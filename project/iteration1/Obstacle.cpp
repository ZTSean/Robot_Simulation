/**
 * @file Obstacle.cpp
 * @author Group Meryl_Streep
 * @date 15 Feb 2015
 * @brief Details of Obstacle.
 * 
 */
#include "Obstacle.h"
#include <iostream>
using namespace std;

Obstacle::Obstacle():Shape()
{
	type = Obstacle;
	cout << "obs a = " << getXPosition() << "in cons"<< endl;
	cout << "obs b = " << getYPosition() << endl;
}

Obstacle::Obstacle(int x,int y, int size):Shape(x, y, size)
{
	type = Obstacle;
}


bool Obstacle::detectWall(int width, int height)
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

bool Obstacle::detectObstacle(Obstacle obstacle)
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
