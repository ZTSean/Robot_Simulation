/**
 * @file RobotClass.cpp
 * @author Group Meryl_Streep
 * @date 15 Feb 2015
 * @brief The representation of robot within the simulation
 * 
 */

#include "RobotClass.h"
#include <iostream>
#include <math.h>
using namespace std;

// RobotClass constructors

RobotClass::RobotClass(double x, double y, double w, double l, double sp, int ori, ShapeType shapeType, float c[3], ConnectionType ct, int id): Shape(x, y, w, l, sp, ori, shapeType, c)
{
	//-----------------------------------RobotSensor 1----------------------------------------------
	float RobotSensorColor[3] = {1.0f, 0.0f, 1.0f};
	//Sensor(pos_x, pos_y, width, length, speed, orientation, shapeType, color, sensorType, connectionType);
	Sensor RobotSensor1(x+w/2, y+l/2, 0.0, 0.0, 0.0, 0, Circle, RobotSensorColor, RobotSensor, ct);
	if (ct == Excitatorydirect || ct == Inhibitorydirect){
		RobotSensor1.setWheelID(LeftWheel);
	}else{
		RobotSensor1.setWheelID(RightWheel);
	}
	sensors.push_back(RobotSensor1);
	
	//-----------------------------------RobotSensor 2----------------------------------------------
	Sensor RobotSensor2(x-w/2, y+l/2, 0.0, 0.0, 0.0, 0, Circle, RobotSensorColor, RobotSensor, ct);
	if (ct == Excitatorydirect || ct == Inhibitorydirect){
		RobotSensor2.setWheelID(RightWheel);
	}else{
		RobotSensor2.setWheelID(LeftWheel);
	}
	sensors.push_back(RobotSensor2);

	//-----------------------------------LightSensor 1----------------------------------------------
	float LightSensorColor[3] = {0.0f, 1.0f, 1.0f};
	Sensor LightSensor1(x+w/2, y+l/2, 0.0, 0.0, 0.0, 0, Circle, LightSensorColor, LightSensor, ct);
	if (ct == Excitatorydirect || ct == Inhibitorydirect){
		LightSensor1.setWheelID(LeftWheel);
	}else{
		LightSensor1.setWheelID(RightWheel);
	}
	sensors.push_back(LightSensor1);
	
	//-----------------------------------LightSensor 2----------------------------------------------
	Sensor LightSensor2(x+w/2, y+l/2, 0.0, 0.0, 0.0, 0, Circle, LightSensorColor, LightSensor, ct);
	if (ct == Excitatorydirect || ct == Inhibitorydirect){
		LightSensor2.setWheelID(RightWheel);
	}else{
		LightSensor2.setWheelID(LeftWheel);
	}
	sensors.push_back(LightSensor2);
	
	//-----------------------------------Left Wheel-------------------------------------------------
	float WheelColor[3] = {1.0f, 1.0f, 0.0f};
	//Wheel(pos_x, pos_y, width, length, speed, orientation, shapeType, color, WheelID);
	Wheel leftWheel(x-w/2, y, 0.0, 0.0, 30.0, 0, Circle, WheelColor, LeftWheel);
	wheels.push_back(leftWheel);
	
	//-----------------------------------Right Wheel------------------------------------------------
	Wheel rightWheel(x+w/2, y-3, 0.0, 0.0, 45.0, 0, Circle, WheelColor, RightWheel);
	wheels.push_back(rightWheel);
	
	
	ID = id;
	connectionType = ct;
}


RobotClass::~RobotClass()
{
	
}


//-----------------------------mutator------------------------------
void RobotClass::setID(int id)
{
	ID = id;
}

void RobotClass::setConnectionType(ConnectionType newconnectionType)
{
	connectionType = newconnectionType;
}

void RobotClass::setLeftSpeed(double sp)
{
	std::vector<Wheel>::size_type i = 0;
	wheels[i].setSpeed(sp);
}

void RobotClass::setRightSpeed(double sp)
{
	std::vector<Wheel>::size_type i = 1;
	wheels[i].setSpeed(sp);
}

void RobotClass::setLeftWheelPosition(double x,double y)
{
	std::vector<Wheel>::size_type i = 0;
	wheels[i].setPosition(x,y);
}


void RobotClass::setRightWheelPosition(double x,double y)
{
	std::vector<Wheel>::size_type i = 1;
	wheels[i].setPosition(x,y);
}


//-----------------------------accessor------------------------------
int RobotClass::getID()
{
	return ID;
}

double RobotClass::getLeftSpeed()
{
	std::vector<Wheel>::size_type i = 0;
	return wheels[i].getSpeed();
}

double RobotClass::getRightSpeed()
{
	std::vector<Wheel>::size_type i = 1;
	//cout<<i<<endl;
	return wheels[i].getSpeed();
}

double RobotClass::getLeftWheelX()
{
	std::vector<Wheel>::size_type i = 0;
	return wheels[i].getXPosition();
}

double RobotClass::getLeftWheelY()
{
	std::vector<Wheel>::size_type i = 0;
	return wheels[i].getYPosition();
}

double RobotClass::getRightWheelX()
{
	std::vector<Wheel>::size_type i = 1;
	return wheels[i].getXPosition();
}

double RobotClass::getRightWheelY()
{
	std::vector<Wheel>::size_type i = 1;
	return wheels[i].getYPosition();
}

ConnectionType RobotClass::getConnectionType(){
	return connectionType;
}
//-----------------------------Functionality------------------------------

void RobotClass::detectWall(double w, double h){ 
	double newXpos;
	double newYpos;
	
	if( ((getXPosition()+ (getWidth()/2)) < w) ){  //checks if x goes off from the right
		newXpos = fmod(getXPosition(), w);
		setPosition( newXpos, getYPosition());
	} else if ( (getXPosition() + (getWidth()/2)) > 0) { //checks if x goes off from the left
		newXpos = w;
		setPosition( newXpos, getYPosition());
	} else if ( (getYPosition() + (getWidth()/2)) > 0) { //checks if y goes off from the bottom
		newYpos = h;
		setPosition( getXPosition(), newYpos);
	} else if ( (getYPosition() + (getWidth()/2)) < h){ //checks if y goes off from the top
		newYpos = fmod(getYPosition(), h);
		setPosition( getXPosition(), newYpos);
	}
}

void RobotClass::detectStimulation(vector<RobotClass> robots, vector<Light> lights, double stimulation[2])
{	
	double lightStimulateLeft = 0.0;				// lights Stimulation for left wheel
	double robotStimulateLeft = 0.0; 				// robots Stimulation for left wheel
	double lightStimulateRight = 0.0;				// lights Stimulation for Right wheel
	double robotStimulateRight = 0.0; 				// robots Stimulation for RIght wheel
	
	std::vector<Sensor>::size_type i = 0;
	switch(connectionType)
	{
		case Excitatorydirect:
		case Excitatorycrossed:
			for (i = 0; i < sensors.size(); i++){
				if (sensors[i].getSensorType() == RobotSensor){
					if (sensors[i].getWheelID() == LeftWheel){									// robot stimulate left wheel
						robotStimulateLeft += sensors[i].robotStimulation(robots, ID);
					}else{
						robotStimulateRight += sensors[i].robotStimulation(robots, ID);			// robot stimulate right wheel
					}
				}else{
					if (sensors[i].getWheelID() == RightWheel){
						lightStimulateLeft += sensors[i].lightStimulation(lights);				// light stimulate left wheel
					}else{
						lightStimulateRight += sensors[i].lightStimulation(lights);				// light stimulate right wheel
					}
				}
			}
			break;
		case Inhibitorydirect:
		case Inhibitorycrossed:
			for (i = 0; i < sensors.size(); i++){
				if (sensors[i].getSensorType() == RobotSensor){
					if (sensors[i].getWheelID() == LeftWheel){									// robot stimulate left wheel
						robotStimulateLeft -= sensors[i].robotStimulation(robots, ID);
					}else{
						robotStimulateRight -= sensors[i].robotStimulation(robots, ID);			// robot stimulate right wheel
					}
				}else{
					if (sensors[i].getWheelID() == RightWheel){
						lightStimulateLeft -= sensors[i].lightStimulation(lights);				// light stimulate left wheel
					}else{
						lightStimulateRight -= sensors[i].lightStimulation(lights);				// light stimulate right wheel
					}
				}
			}
			break;
	}
	stimulation[0] = lightStimulateLeft + robotStimulateLeft;
	stimulation[1] = lightStimulateRight + robotStimulateRight;
	cout<< "Delta left speed: " << stimulation[0] << endl;
	cout<< "Delta right speed: " << stimulation[1] << endl;
}
