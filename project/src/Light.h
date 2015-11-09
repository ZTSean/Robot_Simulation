/**
 * @file Light.h
 * @author Group Meryl_Streep
 * @date 8 April 2015
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
		 * @author Zixiao Wang
		 * @param x The x position of Shape.
		 * @param y The y position of Shape.
		 * @param w The width of Shape.
		 * @param l The length of Shape.
		 * @param sp The speed of Shape.
		 * @param ori The orientation of Shape.
		 * @param st The ShapeType of Shape.
		 * @param c The color of Shape.
		 */
		Light(double x, double y, double w, double l, double sp, double ori, ShapeType st, float c[3]);
		
		/**
		 * @brief Default deconstructor.
		 * @author Zixiao Wang
		 */
		~Light();

		//-----------------------------mutator------------------------------
		/**
		 * @brief set light's action range through arguement.
		 * @author Zixiao Wang
		 * @param newSensorType Set Light's action range according to arguement newRange.
		 */
		void setActionRange(double newRange);
		
		//-----------------------------accessor------------------------------
		/**
		 * @brief Return action range of the light.
		 * @author Zixiao Wang
		 */
		double getActionRange();
		
		//-----------------------------functionality-------------------------
		/**
		 * @brief Detect whether light against the wall of window.
		 * @author Zixiao Wang
		 * @param width The witdth of window(default: 800)
		 * @param height The height of window(default: 800)
		 */
		Wall detectWall(double witdth, double height);
};

#endif
