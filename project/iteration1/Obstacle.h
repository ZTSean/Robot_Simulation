/**
 * @file Obstacle.h
 * @author Group Meryl_Streep
 * @date 15 Feb 2015
 * @brief The representation of Obstacle within the simulation
 * 
 */

#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "Shape.h"


/**
 * @brief Obstacle's position x and y, size
 */
class Obstacle: public Shape{
	public:
		
		/**
		 * @brief The default constructor.
		 */
		Obstacle();
		
		/**
		 * @brief A Constructor.
		 * @param x The x position of Obstacle.
		 * @param y The y position of Obstacle.
		 * @param size The size of Obstacle(radius).
		 */
		Obstacle(int x,int y, int size);
		
		/**
		 * @brief Detect whether obstacle against the wall of window.
		 * @param width The witdth of window(default: 800)
		 * @param height The height of window(default: 800)
		 */
		bool detectWall(int width, int height);
		
		/**
		 * @brief Detect whether obstacle against obstacle.
		 * @param obstacle Obstacle that used to detect whether there is a collision
		 */
		 bool detectObstacle(Obstacle obs);
};



#endif
