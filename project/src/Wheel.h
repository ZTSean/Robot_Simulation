/**
 * @file wheel.h
 * @author Group Meryl_Streep
 * @date 8 April 2015
 * @brief The representation of wheel.
 * 
 */


#ifndef WHEEL_H
#define WHEEL_H

#include <stdlib.h>
#include "Shape.h"
#include "Sensor.h"

class Wheel: public Shape
{
	private:
		WheelID ID;
		
	public:
		/**
		 * @brief A Constructor.
		 * @author Zixiao Wang
		 * @param x The x position of Shape.
		 * @param y The y position of Shape.
		 * @param w The width of Shape.
		 * @param l The length of Shape.
		 * @param sp The speed of Shape.
		 * @param ori The orientation of Shape.
		 * @param st The ShapeType of Shape.
		 * @param c The color of Shape.
		 * @param id The ID of the wheel.
		 */
		Wheel(double x, double y, double w, double l, double sp, double ori, ShapeType st, float c[3], WheelID id);
		
		
	
};

#endif
