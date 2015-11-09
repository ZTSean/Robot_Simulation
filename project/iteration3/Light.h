/**
 * @file Light.h
 * @author Group Meryl_Streep
 * @date 15 Mar 2015
 * @brief The representation of light within the simulation
 * 
 */

#ifndef LIGHT_H
#define LIGHT_H
#include <cstdlib>
#include "Shape.h"

/**
 * @brief A light class contains attributes and behaviors.
 * 
 * Inherit from Shape class, add speed and orientation attributes.
 */

 
class Light: public Shape{
	private:
		double actionRange;					/**< The action range of light*/
	public: 
		
		/**
		 * @brief A Constructor.
		 * @param x The x position of Shape.
		 * @param y The y position of Shape.
		 * @param w The width of Shape.
		 * @param l The length of Shape.
		 * @param sp The speed of Shape.
		 * @param ori The orientation of Shape.
		 * @param st The ShapeType of Shape.
		 * @param c The color of Shape.
		 * @param aR The action range of the light.
		 */
		Light(double x, double y, double w, double l, double sp, int ori, ShapeType st, float c[3], double aR);
		
		/**
		 * @brief Default deconstructor.
		 */
		~Light();

		//-----------------------------mutator------------------------------
		/**
		 * @brief set light's action range through arguement.
		 * @param newSensorType Set Light's action range according to arguement newRange.
		 */
		void setActionRange(double newRange);
		
		//-----------------------------accessor------------------------------
		/**
		 * @brief Return action range of the light.
		 */
		double getActionRange();
};

#endif
