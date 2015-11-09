/**
 * @file Sensor.h
 * @author Group Meryl_Streep
 * @date 15 Mar 2015
 * @brief The representation of robot within the simulation
 * 
 */

#ifndef SENSOR_H
#define SENSOR_H
#include <cstdlib>
#include "Shape.h"
#include "Light.h"
#include <vector>

/**
 * @brief A light class contains attributes and hehaviors.
 * 
 * Inherit from Shape class, add speed and orientation attributes.
 */

/**
 * @brief Sensor types for robots
 */
enum SensorType{
	RobotSensor,
	LightSensor
};

/**
 * @brief connection types between sensor and wheel
 */
enum ConnectionType{
	Excitatorydirect,
	Excitatorycrossed,
	Inhibitorydirect,
	Inhibitorycrossed
};

/**
 * @brief id for left and right wheel.
 */
enum WheelID{
	LeftWheel,
	RightWheel
};

// predeclare of Robotclass
/**
 * @brief Pre-declaration of robot.
 */
class RobotClass;

class Sensor: public Shape{
	private:
		SensorType sensorType;						/**< The type of Sensor*/
		ConnectionType connectionType;				/**< The type of connection with corresponding wheel*/
		WheelID wheelid;							/**< The  corresponding wheel*/
	public: 
		
		/**
		 * @brief The default constructor.
		 * @author Zixiao Wang
		 */
		Sensor();
		
		/**
		 * @brief A Constructor.
		 * @author Zixiao Wang
		 * @param x The x position of Sensor.
		 * @param y The y position of Sensor.
		 * @param w The width of Sensor.
		 * @param l The length of Sensor.
		 * @param sp The speed of Sensor.
		 * @param ori The orientation of Sensor.
		 * @param st The ShapeType of Sensor.
		 * @param c The color of Sensor.
		 * @param aR The action range of the Sensor.
		 */
		Sensor(double x, double y, double w, double l, double sp, double ori, ShapeType st, float c[3], SensorType sensort, ConnectionType ct);
		
		/**
		 * @brief Default deconstructor.
		 * @author Zixiao Wang
		 */
		~Sensor();

		//-----------------------------mutator------------------------------
		/**
		 * @brief set Sensor's SensorType through arguement.
		 * @author Zixiao Wang
		 * @param newSensorType Set Sensor's Sensortype according to arguement newSensorType.
		 */
		void setSensorType(SensorType newSensorType);
		
		/**
		 * @brief set Sensor's ConnectionType through arguement.
		 * @param newconnectionType Set Sensor's connectionType according to arguement newconnectionType.
		 * @author Zixiao Wang
		 */
		void setConnectionType(ConnectionType newconnectionType);
		
		/**
		 * @brief set Sensor's wheelID through arguement.
		 * @author Zixiao Wang
		 * @param newWheelID Set Sensor's wheelid according to arguement newWheelID.
		 */
		void setWheelID(WheelID newWheelID);
		
		//-----------------------------accessor------------------------------
		/**
		 * @brief Return sensor type of sensor.
		 * @author Zixiao Wang
		 */
		SensorType getSensorType();
		
		/**
		 * @brief Return connection type of sensor.
		 * @author Zixiao Wang
		 */
		ConnectionType getConnectionType();
		
		/**
		 * @brief Return corresponding wheelid of sensor.
		 * @author Zixiao Wang
		 */
		WheelID getWheelID();
		
		//-----------------------------Functionality------------------------------
		/**
		 * @brief Calculate overall impact of lights on the speed of corresponding wheel.
		 * @author Yangyun Li and Zixiao Wang
		 * @param lights The array of all the light in the environment.
		 */
		double lightStimulation(std::vector<Light> lights);
		
		/**
		 * @brief Calculate overall impact of other robots on the speed of corresponding wheel.
		 * @author Yangyun Li and Zixiao Wang
		 * @param robots The array of all other robots in the environment.
		 */
		double robotStimulation(std::vector<RobotClass> robots, int id);
};

#endif
