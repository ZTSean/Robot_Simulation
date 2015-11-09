/**
 * @file Target.h
 * @author Group Meryl_Streep
 * @date 15 Feb 2015
 * @brief The representation of robot within the simulation
 * 
 */
 
#ifndef TARGETS_H
#define TARGETS_H
#include <cstdlib>
#include "Shape.h"
#include "Obstacle.h"

/**
 * @brief Obstacle's position x and y, size
 */
class Target: public Shape{
	
	public:
		/**
		 * @brief The default constructor.
		 */
		Target();
		
		/**
		 * @brief A Constructor.
		 * @param x The x position of Target.
		 * @param y The y position of Target.
		 * @param size The size of Target.
		 */
		Target(int x,int y, int size);
		
		/**
		 * @brief Detect whether target against obstacle.
		 * @param obs Obstacle that used to detect whether there is a collision
		 */
		bool detectObstacle(Obstacle obs);
		
		/**
		 * @brief Detect whether obstacle against the wall of window.
		 * @param width The witdth of window(default: 800)
		 * @param height The height of window(default: 800)
		 */
		bool detectWall(int width, int height);
		
		// bool detectObjects(Shape shape);			unify all kinds of objects collision
};




#endif
