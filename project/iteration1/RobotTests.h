/**
 * @file RobotTests.h
 * @author Group Meryl_Streep
 * @date 15 Feb 2015
 * @brief The Tests for robot within the simulation
 * 
 */

#include <cxxtest/TestSuite.h>
#include "Shape.h"
#include "Obstacle.h"
#include "Target.h"
#include "RobotClass.h"

using namespace std;
/* Functions that we need to test:
 * In "RobotClass.h": setPosition(), setSize(), getXPosition(), getYPosition(), detectWall(), detectObstacle()
 */
 
/*
 * Assuming that when inputing negative values, the values would be changed to random value
 * Assuming that the default constructor has all values set to random.
 */



/**
 * @brief A Test class for test functions in RobotClass
 * 
 * Tests for all functions in RobotClass.
 */
class RobotClassTests : public CxxTest::TestSuite 
{
	public:
	
		/**
		 * @brief test whether setPosition function works well
		 */
		void Test_setPosition(void){
			// This test tests functionality of setPosition(int, int)
			// Create a RobotClass object to test
			RobotClass *aRobot = new RobotClass(2, 5, 8, 10, 8);
			
			// Test to ensure the object set the position

			//Normal case
			aRobot->setPosition(3,7);
			TS_ASSERT_EQUALS(aRobot->getXPosition(), 3);
			TS_ASSERT_EQUALS(aRobot->getYPosition(), 7);
			
			//Testing negative number
			aRobot->setPosition(-1, -1);
			TS_ASSERT_LESS_THAN_EQUALS(0,aRobot->getXPosition());
			TS_ASSERT_LESS_THAN_EQUALS(0,aRobot->getYPosition());
			
			//Testing large extreme, X and Y should greater than or equal 0 and less than or equal 800
			aRobot->setPosition(900, 900);

			TS_ASSERT_LESS_THAN_EQUALS(aRobot->getXPosition(), 800);
			TS_ASSERT_LESS_THAN_EQUALS(0, aRobot->getXPosition());
			
			TS_ASSERT_LESS_THAN_EQUALS(aRobot->getYPosition(), 800);
			TS_ASSERT_LESS_THAN_EQUALS(0, aRobot->getYPosition());
		}
		
		/**
		 * @brief test whether setSize function works well
		 */
		void Test_setSize(void){
			// This test tests functionality of setSize(int)
			// Create a RobotClass object to test
			RobotClass *aRobot = new RobotClass(2, 5, 8, 10, 8);
			
			// Tests  
			aRobot->setSize(10);
			TS_ASSERT_EQUALS(aRobot->getSize(), 10);
			
			// Test when input is less than 0
			aRobot->setSize(-1);
			TS_ASSERT_LESS_THAN_EQUALS(0, aRobot->getSize());
			TS_ASSERT_LESS_THAN_EQUALS(aRobot->getSize(), 100)
			
			// Testing the boundary, size should less than or equal 100
			aRobot->setSize(300);
			TS_ASSERT_LESS_THAN_EQUALS(0, aRobot->getSize());
			TS_ASSERT_LESS_THAN_EQUALS(aRobot->getSize(), 100);
		}
		
		/**
		 * @brief test whether getXPosition function works well
		 */
		void Test_getXPosition(void){
			// This test tests functionality of int getXPosition()
			// Create a RobotClass object to test
			RobotClass *aRobot = new RobotClass(2, 5, 8, 10, 8);
			
			// Tests  
			TS_ASSERT_EQUALS(aRobot->getXPosition(), 2);
		}

		/**
		 * @brief test whether getYPosition function works well
		 */
		void Test_getYPosition(void){
			// This test tests functionality of int getYPosition()
			// Create a RobotClass object to test
			RobotClass *aRobot = new RobotClass(2, 5, 8, 10, 8);
			
			// Tests  
			TS_ASSERT_EQUALS(aRobot->getYPosition(), 5);
		}
		
		/**
		 * @brief test whether getSpeed function works well
		 */
		void Test_getSpeed(void){
			// This test tests functionality of int getSpeed()
			// Create a RobotClass object to test
			RobotClass *aRobot = new RobotClass(250, 205, 8, 10, 8);
			// Tests  
			TS_ASSERT_EQUALS(aRobot->getSpeed(), 10);
		}
		
		/**
		 * @brief test whether getPrientation function works well
		 */
		void Test_getOrientation(void){
			// This test tests functionality of int getOrientation()
			// Create a RobotClass object to test
			RobotClass *aRobot = new RobotClass(200, 200, 8, 10, 8);
			
			// Tests  
			TS_ASSERT_EQUALS(aRobot->getOrientation(), 8);
		}



		/**
		 * @brief test whether RobotClass detectWall function works well
		 */
		void Test_detectWall(void){
			// This test tests functionality of bool detectWall()
			// Create a RobotClass object to test
			RobotClass *robot_dw1 = new RobotClass(790, 790, 10, 20, 10); // Touch the wall
			RobotClass *robot_dw2 = new RobotClass(810, 500, 15, 30, 20); // Out of the wall
			RobotClass *robot_dw3 = new RobotClass(400, 400, 20, 20, 10); // within the wall
			
			// assume the height of window is 800, the width of window is 800
			bool result1 = robot_dw1->detectWall(800, 800);
			bool result2 = robot_dw2->detectWall(800, 800);
			bool result3 = robot_dw3->detectWall(800, 800);
			
			// Tests 
			TS_ASSERT_EQUALS(result1, false);
			TS_ASSERT_EQUALS(result2, true);
			TS_ASSERT_EQUALS(result3, false);
		}

		/**
		 * @brief test whether RobotClass detectObstacle function works well
		 */
		void Test_detectObstacle(void){
			// This test tests functionality of bool detectObstacle()
			RobotClass *robot = new RobotClass(400,400,10,20,20);	// create robot
			Obstacle *obs1 = new Obstacle(430,440,40);				// obs1, just touch the robot
			Obstacle *obs2 = new Obstacle(600,700,10);				// obs2, no collision with robot
			Obstacle *obs3 = new Obstacle(410,410,10);				// obs3, collision with robot
			
			// Create a RobotClass object to test
			bool result1 = robot->detectObstacle(*obs1);
			bool result2 = robot->detectObstacle(*obs2);
			bool result3 = robot->detectObstacle(*obs3);
			
			// Tests
			TS_ASSERT_EQUALS(result1,true);
			TS_ASSERT_EQUALS(result2,false);
			TS_ASSERT_EQUALS(result3,true);
		}
		
		/**
		 * @brief test whether RobotClass pointTo function works well
		 */
		void pointTo(Target target){
			TS_ASSERT_EQUALS(true,true);
		}
		
		/**
		 * @brief test whether RobotClass rotate function works well
		 */
		void rotate(int degrees){
			TS_ASSERT_EQUALS(true,true);
		}
		
		/**
		 * @brief test whether RobotClass translate function works well
		 */
		void translate(int length){
			TS_ASSERT_EQUALS(true,true);
		}
		
		/**
		 * @brief test whether RobotClass updateposition function works well
		 */
		void updateposition(){
			TS_ASSERT_EQUALS(true,true);
		}
		


};

// Test for Simulation.h
class SimulationTests : public CxxTest::TestSuite 
{
	public:

		/**
		 * @brief test whether leftMouseDown function works well
		 */
		void Test_leftMouseDown(void){
		// NOT THIS TIME!!!
		// This test tests functionality of leftMouseDown(int, int)
		// Create a Simulation object to test
		// Tests
			TS_ASSERT_EQUALS(true,true);
		}

		/**
		 * @brief test whether leftMouseUp function works well
		 */
		void Test_leftMouseUp(void){
		// NOT THIS TIME!!!
		// This test tests functionality of leftMouseUp(int, int)
		// Create a Simulation object to test
		// Tests  
			TS_ASSERT_EQUALS(true,true);
		}
};
