/**
 * @file wheel.cpp
 * @author Group Meryl_Streep
 * @date 10 April 2015
 * @brief The details of wheel.
 */
 
#include "Wheel.h"
#include <iostream>
using namespace std; 
 
Wheel::Wheel(double x, double y, double w, double l, double sp, double ori, ShapeType shapet, float c[3], WheelID id): Shape(x, y, w, l, sp, ori, shapet, c)
{
	ID = id;
}


