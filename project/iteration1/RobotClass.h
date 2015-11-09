/**
 * @file RobotClass.h
 * @author Group Meryl_Streep
 * @date 15 Feb 2015
 * @brief The representation of robot within the simulation
 * 
 */

#ifndef ROBOTCLASS_H
#define ROBOTCLASS_H
#include <cstdlib>
#include "Shape.h"
#include "Target.h"
#include "Obstacle.h"

/**
 * @brief A robot class contains attributes and hehaviors.
 * 
 * Inherit from Shape class, add speed and orientation attributes.
 */
 
struct vector{					/**< Vector including distance and orientation information that robot need to locate target*/
	int deltaDistance;
	int deltaOri;
}; 
 
class RobotClass: public Shape{
	public: 
		
		/**
		 * @brief The default constructor.
		 */
		RobotClass();
		
		/**
		 * @brief A Constructor.
		 * @param x The x position of robot.
		 * @param y The y position of robot.
		 * @param s The speed of robot.
		 * @param ori The orientation of robot.
		 * @param size The size of robot(radius).
		 */
		RobotClass(int x, int y, int size, int s, int ori);
		
		/**
		 * @brief Default deconstructor.
		 */
		~RobotClass();

		/**
		 * @brief Set robot's orientation through arguement. 
		 * @param degrees Set robot's orientation according to arguement integer degrees.
		 */ 
		void setOrientation(int degrees); // orientation in degrees
		
		/**
		 * @brief set Robot's speed through arguement.
		 * @param pps Set robot's speed according to arguement integer pps.
		 */
		void setSpeed(int pps); // speed in pixels per second

		/**
		 * @brief Return current orientation of robot.
		 */
		int getOrientation();
		
		/**
		 * @brief Return current speed of robot.
		 */
		int getSpeed();
		
		/**
		 * @brief Orient robot towards target
		 * @param target the target that robot will go
		 */
		void pointTo(Target target); // orientate towards target

		/**
		 * @brief Rotate robot by specified input degrees
		 * @param degrees the degree that robot will rotate
		 */
		void rotate(int degrees);
		
		/**
		 * @brief Translate robot (move forward) by specified input pixels
		 * @param length Distance that robot will translate
		 */
		void translate(int length);
		
		/**
		 * @brief Updating position of robot based on time between frames and speed
		 */
		void updateposition();

		/**
		 * @brief Detect whether robot against the wall of window.
		 * @param width The witdth of window(default: 800)
		 * @param height The height of window(default: 800)
		 */
		bool detectWall(int witdth, int height);
		
		/**
		 * @brief Detect whether robot against obstacle.
		 * @param obs Obstacle that used to detect whether there is a collision
		 */
		bool detectObstacle(Obstacle obs);
		
		/**
		 * @brief Detect whether robot against Target.
		 * @param target Target that used to detect whether there is a collision
		 */
		bool detectTarget(Target target);

		
	private:
		int speed;						/**< speed of robot*/
		int orientation; 				/**< orientation of robot*/
};

#endif
