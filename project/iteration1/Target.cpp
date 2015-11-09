/**
 * @file Target.cpp
 * @author Group Meryl_Streep
 * @date 15 Feb 2015
 * @brief The Details of Target
 * 
 */
 
#include "Target.h"
#include <iostream>
using namespace std;

Target::Target():Shape(){
	type = Target;
	cout << "target a = " << getXPosition() << "in cons"<< endl;
	cout << "target b = " << getYPosition() << endl;
}

Target::Target(int x,int y, int size):Shape(x, y, size)
{
	type = Target;
}

bool Target::detectObstacle(Obstacle obstacle)
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

bool Target::detectWall(int width, int height)
{
	if ( ((getXPosition() + getSize()) > width ) || ( getXPosition() < getSize() ) )
	{
		return true;
	}
	else if ( (getYPosition() + getSize()) > height || (getYPosition() < getSize()))
	{
		return true;
	}else{
		return false;
	}
}


