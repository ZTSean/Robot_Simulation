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

enum SensorType{
	RobotSensor,
	LightSensor
};

enum ConnectionType{
	Excitatorydirect,
	Excitatorycrossed,
	Inhibitorydirect,
	Inhibitorycrossed
};

enum WheelID{
	LeftWheel,
	RightWheel
};

class RobotClass;

class Sensor: public Shape{
	private:
		SensorType sensorType;						/**< The type of Sensor*/
		ConnectionType connectionType;				/**< The type of connection with corresponding wheel*/
		WheelID wheelid;							/**< The  corresponding wheel*/
	public: 
		
		/**
		 * @brief The default constructor.
		 */
		Sensor();
		
		/**
		 * @brief A Constructor.
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
		Sensor(double x, double y, double w, double l, double sp, int ori, ShapeType st, float c[3], SensorType sensort, ConnectionType ct);
		
		/**
		 * @brief Default deconstructor.
		 */
		~Sensor();

		//-----------------------------mutator------------------------------
		/**
		 * @brief set Sensor's SensorType through arguement.
		 * @param newSensorType Set Sensor's Sensortype according to arguement newSensorType.
		 */
		void setSensorType(SensorType newSensorType);
		
		/**
		 * @brief set Sensor's ConnectionType through arguement.
		 * @param newconnectionType Set Sensor's connectionType according to arguement newconnectionType.
		 */
		void setConnectionType(ConnectionType newconnectionType);
		
		/**
		 * @brief set Sensor's wheelID through arguement.
		 * @param newWheelID Set Sensor's wheelid according to arguement newWheelID.
		 */
		void setWheelID(WheelID newWheelID);
		
		//-----------------------------accessor------------------------------
		/**
		 * @brief Return sensor type of sensor.
		 */
		SensorType getSensorType();
		
		/**
		 * @brief Return connection type of sensor.
		 */
		ConnectionType getConnectionType();
		
		/**
		 * @brief Return corresponding wheelid of sensor.
		 */
		WheelID getWheelID();
		
		//-----------------------------Functionality------------------------------
		/**
		 * @brief Calculate overall impact of lights on the speed of corresponding wheel.
		 * @param lights The array of all the light in the environment.
		 */
		double lightStimulation(std::vector<Light> lights);
		
		/**
		 * @brief Calculate overall impact of other robots on the speed of corresponding wheel.
		 * @param robots The array of all other robots in the environment.
		 */
		double robotStimulation(std::vector<RobotClass> robots, int id);
};

#endif
