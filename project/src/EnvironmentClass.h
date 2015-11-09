/**
 * @file EnvironmentClass.h
 * @author Group Meryl_Streep
 * @date 10 April 2015
 * @brief Main application class for the Environment Class
 * 
 */
 
 #ifndef ENVIRONMENTCLASS_H
#define ENVIRONMENTCLASS_H
#include "RobotClass.h"
#include "Light.h"
#include <vector>
#include <iostream>

class EnvironmentClass
{
	public:
		
		/**
		 * @brief The default constructor.
		 * @author Zixiao Wang
		 */
		EnvironmentClass();
		
		/**
		 * @brief A Constructor.
		 * @author Zixiao Wang
		 * @param area The size of environment.
		 * @param width The width of environment.
		 * @param height The height of environment.
		 * @param objs The vector array of objects.
		 */
		EnvironmentClass(int area, int width, int height, std::vector<RobotClass> *rs, std::vector<Light> *ls);
		
		/**
		 * @brief Update the orientation and positions of each object.
		 * @param elapsedTime the time inteval between each updates
		 * @author: Yangyun Li and Zixiao Wang
		 */
		void update(double elaspedTime);
		
		
		/**
		 * @brief This function returns the number of objects in the environment. 
		 * @author Zixiao Wang
		 */
		int getCount();
		
		/**
		 * @brief Robots register with the environment, which adds them to the environment data structure(s).
		 * @author Zixiao Wang
		 * @param r The robot need to be registered to the environment.
		 */
		void registerRobotClass(RobotClass r);
		
		/**
		 * @brief Lights register with the environment, which adds them to the environment data structure(s).
		 * @author Zixiao Wang
		 * @param l The light need to be registered to the environment.
		 */
		void registerLight(Light l);
		
	private:
		
		std::vector<RobotClass> *robots;		/**< The robot array*/
		std::vector<Light> *lights;				/**< The light array */
		int count;								/**< the number of objects*/
		int size;								/**< size of environment*/
		int boundary[2];						/**< boundary of environment*/
		
		
};

#endif
