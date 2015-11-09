/**
 * \author CSci3081 Guru
 *
 * \file  Simulation.h
 * \brief Main application class for the robot simulation
 *
 */


#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <cstdlib>
#include "BaseGfxApp.h"
//#include "RobotClass.h"
//#include "Target.h"
//#include "Obstacle.h"
#include "EnvironmentClass.h"
#include "Object.h"

/** The Simulation class.  This sets up the GUI and the drawing environment. */  
class Simulation : public BaseGfxApp {
public: 
	/**
	 * @brief the type of UI Control input.
	 */
	enum UIControlType {
		UI_QUIT = 0,
		UI_RESUME = 1,
		UI_PAUSE = 2,
		UI_START = 3,
	};
	
	/**
	 * @brief arguements from user's command input and other window information. 
	 * @param argc The number of command arguement.
	 * @param argv The command input array.
	 * @param width The width of window.
	 * @param height The height of window.
	 */
	Simulation(int argc, char* argv[], int width, int height);
	virtual ~Simulation();

	/**
	 * @brief display all the items.
	 */
	void display();    
	
	/**
	 * @brief 
	 */
	void gluiControl(int controlID);
	
	/**
	 * @brief draw objects and send them to the window.  
	 * @param obj pass in the object which is to be sent. 
	 */
	void renderObject(Object obj);
	
	/**
	 * @brief The action will be taken when left mouse is clicked.
	 * @param x the x position of mouse click position.
	 * @param y the y position of mouse click position.
	 */
	void leftMouseDown(int x, int y);
	
	/**
	 * @brief The action will be taken when right mouse is clicked.
	 * @param x the x position of mouse click position.
	 * @param y the y position of mouse click position.
	 */
	void leftMouseUp(int x, int y);
	


	/**
	 * @brief detect whether there is any overlap between robot, two obstacles and target.
	 */
	void detectcollision();
	


private:
	
	bool controlflag;					/**< The flag for panel input*/
	int numRobot;						/**< The number of robot*/
	int numObstacle;					/**< The number of obstacle*/
	int numTarget;						/**< The number of target*/
	double oldTimeSinceStart;		         	/**< The time since the start*/
	vector<Object> physicalObjects;		                /**< A vector of objects created*/
	EnvironmentClass* env;				        /**< A environment created*/

};


#endif
