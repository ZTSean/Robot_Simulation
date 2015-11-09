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
#include "Wheel.h"
#include "Sensor.h"
#include <vector>
#include "Light.h"

/**
 * @brief A robot class contains attributes and hehaviors.
 * 
 * Inherit from Shape class, add speed and orientation attributes.
 */


 
class RobotClass: public Shape
{
	private:
		std::vector<Sensor> sensors;							/**< speed of robot*/
		std::vector<Wheel> wheels; 								/**< orientation of robot*/
		int ID;													/**< ID of robot*/							// ################# used for when traverse the vector<robots> array, avoid scan it self
		ConnectionType connectionType;							/**< Connecntion type of robot*/
	public: 
		
		/**
		 * @brief The default constructor.
		 */
		RobotClass();
		
		/**
		 * @brief A Constructor.
		 * @param x The x position of robot.
		 * @param y The y position of robot.
		 * @param w The width of robot.
		 * @param l The length of robot.
		 * @param sp The speed of robot.
		 * @param ori The orientation of robot.
		 * @param shapeType The shape type of robot.
		 * @param c The color of robot.
		 * @param ct The connection type of robot.
		 * @param id The id of robot.
		 */
		RobotClass(double x, double y, double w, double l, double sp, int ori, ShapeType shapeType, float c[3], ConnectionType ct, int id);
		
		/**
		 * @brief Default deconstructor.
		 */
		~RobotClass();


		//-----------------------------mutator------------------------------
		/**
		 * @brief set robot's ID through arguement.
		 * @param newWheelID Set robot's ID according to arguement id.
		 */
		void setID(int id);
		
		/**
		 * @brief set Robot's ConnectionType through arguement.
		 * @param newconnectionType Set Robot's connectionType according to arguement newconnectionType.
		 */
		void setConnectionType(ConnectionType newconnectionType);

		/**
		 * @brief set Robot's left wheel speed.
		 */		
		void setLeftSpeed(double sp);
		/**
		 * @brief set Robot's right wheel speed.
		 */
		void setRightSpeed(double sp);
		/**
		 * @brief set Robot's left wheel  position.
		 */
		void setLeftWheelPosition(double x,double y);

		/**
		 * @brief set Robot's right wheel x position.
		 */
		void setRightWheelPosition(double x,double y);

		
		
		//-----------------------------accessor------------------------------
		/**
		 * @brief Return ID of robot.
		 */
		int getID();

		/**
		 * @brief Return leftspeed of robot.
		 */		
		double getLeftSpeed();

		/**
		 * @brief Return rightspeed of robot.
		 */
		double getRightSpeed();
		
		/**
		 * @brief Return LeftWheelX of robot.
		 */
		double getLeftWheelX();

		/**
		 * @brief Return LeftWheelY of robot.
		 */
		double getLeftWheelY();

		/**
		 * @brief Return RightWheelX of robot.
		 */
		double getRightWheelX();

		/**
		 * @brief Return RightWheelY of robot.
		 */
		double getRightWheelY();
		
		/**
		 * @brief Return connection type of Robot.
		 */
		ConnectionType getConnectionType();
		
		//-----------------------------Functionality------------------------------
		/**
		 * @brief Detect whether robot against the wall of window.
		 * @param width The witdth of window(default: 800)
		 * @param height The height of window(default: 800)
		 */
		void detectWall(double witdth, double height);
		
		/**
		 * @brief Detect whether robot against obstacle.
		 * @param obs Obstacle that used to detect whether there is a collision
		 */
		void detectStimulation(std::vector<RobotClass> robots, std::vector<Light> lights, double stimulation[2]);
		
};

#endif
