/**
 * @file Light.cpp
 * @author Group Meryl_Streep
 * @date 10 April 2015
 * @brief The details of light.
 */

#include "Light.h"
#include <iostream>
using namespace std;

// Light constructors

Light::Light(double x, double y, double w, double l, double sp, double ori, ShapeType shapeType, float c[3]): Shape(x, y, w, l, sp, ori, shapeType, c)
{
	actionRange = 1.25 * w;
}

Light::~Light()
{
	
}

//-----------------------------mutator------------------------------
void Light::setActionRange(double newRange)
{
	if (newRange < 0)
	{
		cout << "The new value of actionRange should not be negative." << endl;
		actionRange = 2 *getWidth()/2.0;
	}else if(newRange > 5 *getWidth()/2.0){
		cout << "The new value of actionRange is too large." << endl;
		actionRange = 2.5 *getWidth()/2.0;				// the actionrange is 2.5 of radius
	}else{
		actionRange = newRange;
	}
}

//-----------------------------accessor------------------------------
double Light::getActionRange(){
	return actionRange;
}

//-----------------------------functionality-------------------------
Wall Light::detectWall(double width, double height)
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
