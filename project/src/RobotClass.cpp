/**
 * @file RobotClass.cpp
 * @author Group Meryl_Streep
 * @date 10 April 2015
 * @brief The details of robot within the simulation
 * 
 */

#include "RobotClass.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

// RobotClass constructors


RobotClass::RobotClass(double x, double y, double w, double l, double sp, double ori, ShapeType shapeType, float c[3], ConnectionType ct, int id): Shape(x, y, w, l, sp, ori, shapeType, c)
{
	//-----------------------------------RobotSensor 1----------------------------------------------
	float RobotSensorColor[3] = {1.0f, 0.0f, 1.0f};
	//Sensor(pos_x, pos_y, width, length, speed, orientation, shapeType, color, sensorType, connectionType);
	Sensor RobotSensor1(x + w/2.0 * cos(ori+ M_PI/2.0), y + w/2.0 * sin(ori+ M_PI/2.0), w, l, 0.0, 0, Circle, RobotSensorColor, RobotSensor, ConnectionType(0));
	if (ct == Excitatorydirect || ct == Inhibitorydirect){
		RobotSensor1.setWheelID(LeftWheel);
	}else{
		RobotSensor1.setWheelID(RightWheel);
	}
	sensors.push_back(RobotSensor1);

	//-----------------------------------RobotSensor 2----------------------------------------------
	Sensor RobotSensor2(x + w/2.0 * cos(ori- M_PI/2.0), y + w/2.0 * sin(ori- M_PI/2.0), w, l, 0.0, 0, Circle, RobotSensorColor, RobotSensor, ConnectionType(0));
	if (ct == Excitatorydirect || ct == Inhibitorydirect){
		RobotSensor2.setWheelID(RightWheel);
	}else{
		RobotSensor2.setWheelID(LeftWheel);
	}
	sensors.push_back(RobotSensor2);

	//-----------------------------------LightSensor 1----------------------------------------------
	float LightSensorColor[3] = {0.0f, 1.0f, 1.0f};
	Sensor LightSensor1(x + w/2.0 * cos(ori+ M_PI/2.0), y + w/2.0 * sin(ori+ M_PI/2.0), w, l, 0.0, 0, Circle, LightSensorColor, LightSensor, ct);
	if (ct == Excitatorydirect || ct == Inhibitorydirect){
		LightSensor1.setWheelID(LeftWheel);
	}else{
		LightSensor1.setWheelID(RightWheel);
	}
	sensors.push_back(LightSensor1);
	
	//-----------------------------------LightSensor 2----------------------------------------------
	Sensor LightSensor2(x + w/2.0 * cos(ori- M_PI/2.0), y + w/2.0 * sin(ori- M_PI/2.0), w, l, 0.0, 0, Circle, LightSensorColor, LightSensor, ct);
	if (ct == Excitatorydirect || ct == Inhibitorydirect){
		LightSensor2.setWheelID(RightWheel);
	}else{
		LightSensor2.setWheelID(LeftWheel);
	}
	sensors.push_back(LightSensor2);
	
	//-----------------------------------Left Wheel-------------------------------------------------
	float WheelColor[3] = {1.0f, 1.0f, 0.0f};
	//Wheel(pos_x, pos_y, width, length, speed, orientation, shapeType, color, WheelID);
	Wheel leftWheel(x + w/2.0 * cos(ori+ M_PI/2.0), y + w/2.0 * sin(ori+ M_PI/2.0), w, l, 150.0, ori, Circle, WheelColor, LeftWheel);
	wheels.push_back(leftWheel);
	
	//-----------------------------------Right Wheel------------------------------------------------
	Wheel rightWheel(x + w/2.0 * cos(ori- M_PI/2.0), y + w/2.0 * sin(ori- M_PI/2.0), w, l, 150.0, ori, Circle, WheelColor, RightWheel);
	wheels.push_back(rightWheel);
	
	ID = id;
	connectionType = ct;
	actionRange = w;
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
	wheels[0].setSpeed(sp);
}

void RobotClass::setRightSpeed(double sp)
{
	wheels[1].setSpeed(sp);
}

void RobotClass::setLeftWheelPosition(double x,double y)
{
	wheels[0].setPosition(x,y);
}


void RobotClass::setRightWheelPosition(double x,double y)
{
	wheels[1].setPosition(x,y);
}

void RobotClass::setNewPosition(double x, double y)
{
	//cout << "Orientation: " << getOrientation() << endl;
	//cout << "[Robot new X]: " << x << " [Robot new Y]: "<< y << endl;
	double r = getWidth()/2;
	double d = getOrientation();
	setPosition(x, y);
	wheels[0].setPosition(x + r * cos(wheels[0].regular_Ori(d + M_PI/2.0)), y + r * sin(wheels[0].regular_Ori(d + M_PI/2.0)));
	wheels[1].setPosition(x + r * cos(wheels[1].regular_Ori(d - M_PI/2.0)), y + r * sin(wheels[1].regular_Ori(d - M_PI/2.0)));
	//cout << "[[ l wheel reset ]]: " << wheels[0].getXPosition() << " " << wheels[0].getYPosition() << endl;
	//cout << "[[ r wheel reset ]]: " << wheels[1].getXPosition() << " " << wheels[1].getYPosition() << endl;
	sensors[0].setPosition(x + r * cos(sensors[0].regular_Ori(d + M_PI/2.0)), y + r * sin(sensors[0].regular_Ori(d + M_PI/2.0)));
	sensors[1].setPosition(x + r * cos(sensors[1].regular_Ori(d - M_PI/2.0)), y + r * sin(sensors[1].regular_Ori(d - M_PI/2.0)));
	sensors[2].setPosition(x + r * cos(sensors[2].regular_Ori(d + M_PI/2.0)), y + r * sin(sensors[2].regular_Ori(d + M_PI/2.0)));
	sensors[3].setPosition(x + r * cos(sensors[3].regular_Ori(d - M_PI/2.0)), y + r * sin(sensors[3].regular_Ori(d - M_PI/2.0)));
	
}

void RobotClass::setActionRange(double newRange)
{
	if (newRange < 0)
	{
		cout << "The new value of actionRange should not be negative." << endl;
		actionRange = getWidth();
	}else if(newRange > 5 *getWidth()/2.0){
		cout << "The new value of actionRange is too large." << endl;
		actionRange =  getWidth();				// the actionrange is 2 of radius
	}else{
		actionRange = newRange;
	}
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

double RobotClass::getActionRange(){
	return actionRange;
}

//-----------------------------Functionality------------------------------
/*
void RobotClass::detectWall(double w, double h){ 
	double newXpos = 0.0;
	double newYpos = 0.0;
	double r = getWidth()/2;
	
	if( (getXPosition() - r > w ){  //checks if x goes off from the right
		
		int d = getOrientation();
		newXpos = fmod(getXPosition(), w) - getWidth();
		setPosition( newXpos, getYPosition());
		setLeftWheelPosition(newXpos + r * cos(regular_Ori(d - M_PI/2.0)), getYPosition() + r * sin(regular_Ori(d - M_PI/2.0)));
		setRightWheelPosition(newXpos + r * cos(regular_Ori(d + M_PI/2.0)), getYPosition() + r * sin(regular_Ori(d + M_PI/2.0)));
	} 
	else if ( (getXPosition() + r) < 0) { //checks if x goes off from the left
		newXpos = w;
		setPosition( newXpos, getYPosition());
	} 
	else if ( (getYPosition() + r)  0) { //checks if y goes off from the bottom
		newYpos = h;
		setPosition( getXPosition(), newYpos);
	} 
	else if ( (getYPosition() + r) < h){ //checks if y goes off from the top
		newYpos = fmod(getYPosition(), h);
		setPosition( getXPosition(), newYpos);
	}
}*/
Wall RobotClass::detectWall(double width, double height)
{
	if ( (getXPosition() + getWidth()/2) >= width )
	{
		return Right;
	}else if ( getXPosition() <= getWidth()/2)
	{
		return Left;
	}
	else if ( (getYPosition() + getWidth()/2) >= height)
	{
		return Top;
	}else if (getYPosition() <= getWidth()/2)
	{
		return Bottom;
	}else
	{
		return None;
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
			cout << "Into excite:" << endl;
			for (i = 0; i < sensors.size(); i++){
				if (sensors[i].getSensorType() == RobotSensor){
					if (sensors[i].getWheelID() == LeftWheel){									// robot stimulate left wheel
						robotStimulateLeft += sensors[i].robotStimulation(robots, ID);
					}else{
						robotStimulateRight += sensors[i].robotStimulation(robots, ID);			// robot stimulate right wheel
					}
				}else{
					if (sensors[i].getWheelID() == RightWheel){
						lightStimulateRight += sensors[i].lightStimulation(lights);				// light stimulate right wheel
					}else{
						lightStimulateLeft += sensors[i].lightStimulation(lights);				// light stimulate left wheel
					}
				}
			}
			break;
		case Inhibitorydirect:
		case Inhibitorycrossed:
			cout << "Into inhib:" << endl; 
			for (i = 0; i < sensors.size(); i++){
				if (sensors[i].getSensorType() == RobotSensor){
					if (sensors[i].getWheelID() == LeftWheel){									// robot stimulate left wheel
						robotStimulateLeft -= sensors[i].robotStimulation(robots, ID);
					}else{
						robotStimulateRight -= sensors[i].robotStimulation(robots, ID);			// robot stimulate right wheel
					}
				}else{
					if (sensors[i].getWheelID() == RightWheel){
						lightStimulateRight -= sensors[i].lightStimulation(lights);				// light stimulate right wheel
					}else{
						lightStimulateLeft -= sensors[i].lightStimulation(lights);				// light stimulate left wheel
					}
				}
			}
			break;
	}
	stimulation[0] = lightStimulateLeft + robotStimulateLeft;
	if (getLeftSpeed() + stimulation[0] < 20.0)
	{
		stimulation[0] = getLeftSpeed() - 20.0;
	}
	stimulation[1] = lightStimulateRight + robotStimulateRight;
	if (getRightSpeed() + stimulation[1] < 20.0)
	{
		stimulation[1] = getRightSpeed() - 20.0;
	}
	cout<< "Delta left speed: " << stimulation[0] << endl;
	cout<< "Delta right speed: " << stimulation[1] << endl;
}
