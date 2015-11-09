/**
 * @file Sensor.cpp
 * @author Group Meryl_Streep
 * @date 8 April 2015
 * @brief The representation of Sensor.
 * 
 */

#include "Sensor.h"
#include <iostream>
#include <math.h>
#include "RobotClass.h"
using namespace std;

// Sensor constructors

Sensor::Sensor(double x, double y, double w, double l, double sp, double ori, ShapeType shapet, float c[3], SensorType sensort, ConnectionType ct): Shape(x, y, w, l, sp, ori, shapet, c)
{
	sensorType = sensort;
	connectionType = ct;
}

Sensor::~Sensor()
{
	
}

//-----------------------------mutator------------------------------
void Sensor::setSensorType(SensorType newSensorType)
{
	sensorType = newSensorType;
}

void Sensor::setConnectionType(ConnectionType newconnectionType)
{
	connectionType = newconnectionType;
}

void Sensor::setWheelID(WheelID newWheelID)
{
	wheelid = newWheelID;
}

//-----------------------------accessor------------------------------
SensorType Sensor::getSensorType(){
	return sensorType;
}

ConnectionType Sensor::getConnectionType(){
	return connectionType;
}

WheelID Sensor::getWheelID(){
	return wheelid;
}

//-----------------------------Functionality------------------------------
double Sensor::lightStimulation(vector<Light> lights)
{
	double deltaSpeed = 0;							// Overall impact on corresponding wheel's speed
	int length = lights.size();
	int dis = 0;
	std::vector<Light>::size_type i = 0;
	for (i = 0; i < length; i++){						// taverse all light stimulis
		double xdiff = getXPosition() - lights[i].getXPosition(); 
		double ydiff = getYPosition() - lights[i].getYPosition();
		dis = sqrt(xdiff * xdiff + ydiff * ydiff);
		if ( dis <= lights[i].getActionRange() + getWidth()/2.0){
			double deltaDis = lights[i].getActionRange() + getWidth()/2.0 - dis;
			cout << "deltaDis: " << deltaDis << endl;
			deltaSpeed += 10 * deltaDis;
		}
	}
	return deltaSpeed;
}

double Sensor::robotStimulation(vector<RobotClass> robots, int id)
{
	double deltaSpeed = 0;											// Overall impact on corresponding wheel's speed
	int length = robots.size();
	int dis = 0;
	std::vector<RobotClass>::size_type i = 0;
	for (i = 0; i < length && robots[i].getID() != id; i++){		// taverse all robot stimulis except itself
		double xdiff = getXPosition() - robots[i].getXPosition(); 
		double ydiff = getYPosition() - robots[i].getYPosition();
		dis = sqrt(xdiff * xdiff + ydiff * ydiff);
		if ( dis <= getWidth()/2.0 + robots[i].getWidth()/2.0){
			double deltaDis = getWidth()/2.0 + robots[i].getWidth()/2.0 - dis;
			deltaSpeed += 10 * deltaDis;
		}
	}
	return deltaSpeed;
}

