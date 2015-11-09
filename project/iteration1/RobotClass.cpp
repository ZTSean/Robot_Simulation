/**
 * @file RobotClass.cpp
 * @author Group Meryl_Streep
 * @date 15 Feb 2015
 * @brief The representation of robot within the simulation
 * 
 */

#include "RobotClass.h"
#include <iostream>
using namespace std;

// RobotClass constructors
RobotClass::RobotClass()
{
	speed = getrand();
	Vector.orientation = getrand() % 360;
	type = Robot;
	cout << "robot a = " << getXPosition() << endl;
	cout << "robot b = " << getYPosition() << endl;
}

RobotClass::RobotClass(int x,int y,int size,int s,int ori): Shape(x, y, size)
{
	type = Robot;
	speed = s;
	Vector.orientation = ori;
}

RobotClass::~RobotClass()
{
	
}

// special functions for Robot
void RobotClass::setOrientation(int degrees)
{
	if (degrees > 360){
		cout << "orientation is too large, it should be less than 250." << endl;
		orientation = getrand() % 360;
	}else if (degrees < 0){
		cout << "orientation should be greater than 0." << endl;
		orientation = getrand() % 360;
	}else{
		orientation = degrees;
	}
}


void RobotClass::setSpeed(int pps)
{
	if (pps < 0){
		cout << "Speed should greateer than 0." << endl;
		speed = rand();
	}else{
		speed = pps;
	}
    
}


int RobotClass::getOrientation()
{
	return orientation;
}


int RobotClass::getSpeed()
{
	return speed;
}


void RobotClass::pointTo(Target target)
{
}

void RobotClass::rotate(int degrees)
{
}

void RobotClass::translate(int length)
{
}

void RobotClass::updateposition()
{

}


bool RobotClass::detectWall(int width, int height)
{
	if ( ((getXPosition() + getSize()) > width ) || ( getXPosition() < getSize() ) )
	{
		return true;
		//glRotate(180, 0.0f, 0.0f, 1.0f);
	}
	else if ( (getYPosition() + getSize()) > height || (getYPosition() < getSize()))
	{
		return true;
		//glRotate(180, 0.0f, 0.0f, 1.0f);
	}else{
		return false;
	}
}


bool RobotClass::detectObstacle(Obstacle obstacle)
{	
	int xdiff = getXPosition() - obstacle.getXPosition(); 
	int ydiff = getYPosition() - obstacle.getYPosition();
	int distance = getSize() + obstacle.getSize();
	if (xdiff * xdiff + ydiff * ydiff <= distance * distance)
	{
		return true;
	}
	else return false;
}

bool RobotClass::detectTarget(Target target)
{	
	int xdiff = getXPosition() - target.getXPosition(); 
	int ydiff = getYPosition() - target.getYPosition();
	int distance = getSize() + target.getSize();
	if (xdiff * xdiff + ydiff * ydiff <= distance * distance)
	{
		return true;
	}
	else return false;
}
