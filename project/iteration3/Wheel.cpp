/**
 * @file wheel.cpp
 * @author Group Meryl_Streep
 * @date 9 March 2015
 * @brief 
 */
 
#include "Wheel.h"
#include <iostream>
using namespace std; 
 
Wheel::Wheel(double x, double y, double w, double l, double sp, int ori, ShapeType shapet, float c[3], WheelID id): Shape(x, y, w, l, sp, ori, shapet, c)
{
	ID = id;
}

void move(int signal, double elaspedTime){

}

