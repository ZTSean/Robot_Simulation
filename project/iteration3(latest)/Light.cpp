/**
 * @file Light.cpp
 * @author Group Meryl_Streep
 * @date 8 April 2015
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
	//default value for action range is 20. 
	//Action range should be less than 100. 
	if (newRange < 0)
	{
		cout << "The new value of actionRange should not be negative and it is set to default value 20.0." << endl;
		actionRange = 1.25 *getWidth();
	}else if(newRange > 1.25 *getWidth()){
		cout << "The new value of actionRange is too large. It should be less than 100." << endl;
		cout << "It is set to default value: 20.0." << endl;
		actionRange = 1.25 *getWidth();				// the actionrange is 1.25 of radius
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
