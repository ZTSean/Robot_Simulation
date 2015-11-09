/**
 * @file Light.cpp
 * @author Group Meryl_Streep
 * @date 15 Mar 2015
 * @brief The representation of robot within the simulation
 * 
 */

#include "Light.h"
#include <iostream>
using namespace std;

// Light constructors

Light::Light(double x, double y, double w, double l, double sp, int ori, ShapeType shapeType, float c[3], double aR): Shape(x, y, w, l, sp, ori, shapeType, c)
{
	actionRange = aR;
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
		actionRange = 20.0;
	}else if(newRange > 100.0){
		cout << "The new value of actionRange is too large. It should be less than 100." << endl;
		cout << "It is set to default value: 20.0." << endl;
		actionRange = 20.0;
	}else{
		actionRange = newRange;
	}
}

//-----------------------------accessor------------------------------
double Light::getActionRange(){
	return actionRange;
}
