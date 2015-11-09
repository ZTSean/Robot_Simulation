/**
 * @file EnvironmentClass.h
 * @author Group Meryl_Streep
 * @date 9 March 2015
 * @brief Main application class for the Environment Class
 * 
 */
//#include "BaseGfxApp.h"
#include "Object.h"
#include <vector>
#include <iostream>

class EnvironmentClass
{
	public:
		
		/**
		 * @brief The default constructor.
		 */
		EnvironmentClass();
		
		/**
		 * @brief A Constructor.
		 * @param area The size of environment.
		 * @param width The width of environment.
		 * @param height The height of environment.
		 * @param objs The vector array of objects.
		 */
		EnvironmentClass(int area, int width, int height, std::vector<Object> *objs);
		
		/**
		 * @brief Update the orientation and positions of each object.
		 * @param elapsedTime the time inteval between each updates
		 */
		void update(double elaspedTime);
		
		
		/**
		 * @brief This function returns the number of objects in the environment. 
		 */
		int getCount();
		
		/**
		 * @brief Objects register with the environment, which adds them to the environment data structure(s).
		 * @param obj the object need to be registered to the environment.
		 */
		void registerObject(Object obj);
		
		/**
		 * @brief This function returns the information about distance and angles between each pair of robot and target. The infomation is returned in form of distance-direction vector.
		 * @param obj the value for robot.touch sensor. 
		 */

		int touchSensorReading(Object obj);
		
		
		/**
		 * @brief This function adjusts the orientation of a robot and make sure that the robots always move towards target. 
		 * @param obj pass in the object that we want to know information(distance and orientation) towards its target.
		 */
		Navigate homingSensorReading(Object obj);
		
	private:
		
		std::vector<Object> *objects;		/**< The object array*/
		int TimesCount;				/**< The number used for count how many times that update function been called*/
		int count;				/**< the number of objects*/
		int size;				/**< size of environment*/
		int boundary[2];			/**< boundary of environment*/
		
		
};
