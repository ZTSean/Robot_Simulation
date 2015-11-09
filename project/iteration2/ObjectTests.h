/**
 * @file RobotTests.h
 * @author Group Meryl_Streep
 * @date 12 Mar 2015
 * @brief The Tests for robot within the simulation
 * 
 */
 
#include "Object.h"
#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

class ObjectTests : public CxxTest::TestSuite
{
	public: 
	/**
	 * @brief test whether setShape function works well.
	 */
	void Test_setShape(void)
	{
		float arr[] = {0.4f, 0.7f, 0.8f}; 
		//Object(pos_x, pos_y, size, speed, orientation, shapeType, objType, color, id);
		Object *object2 = new Object(2.0, 4.0, 5.0, 3.0, 6.0, Triangle, Robot, arr , 0);
		object2->setShape(Circle);
		TS_ASSERT_EQUALS(object2->getShapeType(), Circle);
	}
	
	/**
	 * @brief test whether move function works well in calculate deltadistance.
	 */
	void Test_moveDist(void)
	{
		float arr[] = {0.4f, 0.7f, 0.8f}; 
		Object *object2 = new Object(2, 4, 5, 3, 6, Circle, Robot, arr , 0);
		TS_ASSERT_EQUALS(object2->move(10.0).deltaDistance, 30);
	}
	
	/**
	 * @brief test whether move function works well in calculate deltaOri.
	 */
	void Test_moveOri(void)
	{
		float arr[] = {0.4, 0.7, 0.8}; 
		Object *object2 = new Object(2,4,5,3,6, Circle, Robot, arr , 7);
		TS_ASSERT_EQUALS(object2->move(10.0).deltaOri, 6.0);
	}
	
	/**
	 * @brief test whether rotate function works well
	 */
	void Test_rotate(void)
	{
		float arr[] = {0.4, 0.7, 0.8}; 
		Object *object2 = new Object(2, 4, 5, 3, 6.0, Circle, Robot, arr , 7);
		TS_ASSERT_EQUALS(object2->rotate(54.0).deltaOri, 60.0);
	
	}
	
	/**
	 * @brief test whether setColor function works well in setting object's color.
	 */
	void Test_setColor(void)
	{
		float arr[] = {0.4, 0.7, 0.8}; 
		Object *object2 = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		float col[] = {0.3, 0.6, 0.9};
		object2->setColor(col);
		TS_ASSERT_EQUALS(*(object2->getColor()), *col);
	}
	
	/**
	 * @brief test whether setType function works well
	 */
	void Test_setType(void)
	{ 
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object2 = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		object2->setType(Robot);
		TS_ASSERT_EQUALS(object2->getObjectType(), Robot);
	}
	
	/**
	 * @brief test whether setPosition function works well in setting robot's X position.
	 */
	void Test_setXPositionRegular(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		object->setPosition(3,7);
		TS_ASSERT_EQUALS(object->getXPosition(), 3);
		}
		
	/**
	 * @brief test whether setPosition function works well in setting robot's Y position.
	 */
	void Test_setYPositionRegular(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		object->setPosition(3,7);
		TS_ASSERT_EQUALS(object->getYPosition(), 7);
		}
	
	/**
	 * @brief test whether setPosition function works well in setting X position to random value when negative input of X.
	 */
	void Test_setXPositionNegetiveNum(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object2 = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		//Testing negative number
		object2->setPosition(-1, 5);
		TS_ASSERT_LESS_THAN_EQUALS(0,object2->getXPosition());
			
	}
	
	/**
	 * @brief test whether setPosition function works well in setting Y position to random value when negative input of Y.
	 */
	void Test_setYPositionNegetiveNum(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object2 = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		//Testing negative number
		object2->setPosition(5, -1);
		TS_ASSERT_LESS_THAN_EQUALS(0,object2->getYPosition());

			
	}
	
	/**
	 * @brief test whether setPosition function works well in setting X position to random value when beyond bounder input of X.
	 */
	void Test_setXPositionLargerNum1(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		//Testing large extreme, X and Y should greater than or equal 0 and less than or equal 800
		Object *object3 = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		object3->setPosition(900, 900);

		TS_ASSERT_LESS_THAN_EQUALS(object3->getXPosition(), 800);
	}

	/**
	 * @brief test whether setPosition function works well in setting X position to random value when beyond bounder input of X.
	 */
	void Test_setXPositionLargerNum2(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		//Testing large extreme, X and Y should greater than or equal 0 and less than or equal 800
		Object *object3 = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		object3->setPosition(900, 900);

		TS_ASSERT_LESS_THAN_EQUALS(0, object3->getXPosition());
	}
	
	/**
	 * @brief test whether setPosition function works well in setting Y position to random value when beyond bounder input of Y.
	 */
	void Test_setYPositionLargerNum1(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		//Testing large extreme, X and Y should greater than or equal 0 and less than or equal 800
		Object *object3 = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		object3->setPosition(900, 900);

		TS_ASSERT_LESS_THAN_EQUALS(object3->getYPosition(), 800);
	}

	/**
	 * @brief test whether setPosition function works well in setting Y position to random value when beyond bounder input of Y.
	 */
	void Test_setYPositionLargerNum2(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		//Testing large extreme, X and Y should greater than or equal 0 and less than or equal 800
		Object *object3 = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		object3->setPosition(900, 900);

		TS_ASSERT_LESS_THAN_EQUALS(0, object3->getYPosition());
	}
		

	/**
	 * @brief test whether setSize function works well in regular value.
	 */
	void Test_setSizeRegular(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		object->setSize(30);
		TS_ASSERT_EQUALS(object->getSize(), 30);
	}
		
	/**
	 * @brief test whether setSize function works well in beyond bounder value.
	 */
	void Test_setSize_bigger_than_60_1(void)
	{
		// Test when input is bigger than 60
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		object->setSize(70);
		TS_ASSERT_LESS_THAN_EQUALS(20, object->getSize());
	}

	/**
	 * @brief test whether setSize function works well in beyond upper bound value.
	 */
	void Test_setSize_bigger_than_60_2(void)
	{
		// Test when input is bigger than 60
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		object->setSize(70);
		TS_ASSERT_LESS_THAN_EQUALS(object->getSize(), 60);
	}

	/**
	 * @brief test whether setSize function works well in below lower bound value.
	 */
	void Test_setSize_less_than_20_1(void)
	{
		// Test when input is less than 20
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		object->setSize(10);
		TS_ASSERT_LESS_THAN_EQUALS(20, object->getSize());
	}
	
	/**
	 * @brief test whether setSize function works well in below lower bound value.
	 */
	void Test_setSize_less_than_20_2(void)
	{
		// Test when input is less than 20
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		object->setSize(10);
		TS_ASSERT_LESS_THAN_EQUALS(object->getSize(), 40)
	}

	/**
	 * @brief test whether getXPosition function works well.
	 */
	void Test_getXPosition(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		TS_ASSERT_EQUALS(object->getXPosition(), 2);
	} 
		
	/**
	 * @brief test whether getXPosition function works well.
	 */
	void Test_getYPosition(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		TS_ASSERT_EQUALS(object->getYPosition(), 4);
	}
		
	/**
	 * @brief test whether getSize function works well.
	 */
	void Test_getSize(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		TS_ASSERT_EQUALS(object->getSize(), 5);
	}
		
	/**
	 * @brief test whether setOrientation function works well in regular values.
	 */
	void Test_setOrientation_regular(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		object->setOrientation(8);
		TS_ASSERT_EQUALS(object->getOrientation(), 8);
	}

	/**
	 * @brief test whether setOrientation function works well in beyond upper bound values.
	 */
	void Test_setOrientation_bigger_than_360_1(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		object->setOrientation(400);
		TS_ASSERT_LESS_THAN_EQUALS(0,object->getOrientation());
	}

	/**
	 * @brief test whether setOrientation function works well in beyond upper bound values.
	 */
	void Test_setOrientation_bigger_than_360_2(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		object->setOrientation(400);
		TS_ASSERT_LESS_THAN_EQUALS(object->getOrientation(), 360);
	}
	
	/**
	 * @brief test whether setOrientation function works well in negative values.
	 */
	void Test_setOrientation_negative_1(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		object->setOrientation(-1);
		TS_ASSERT_LESS_THAN_EQUALS(0,object->getOrientation());
	}

	/**
	 * @brief test whether setOrientation function works well in negative values.
	 */
	void Test_setOrientation_negative_2(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		object->setOrientation(-1);
		TS_ASSERT_LESS_THAN_EQUALS(object->getOrientation(), 360);
	}
		
	/**
	 * @brief test whether setSpeed function works well in regular values.
	 */
	void Test_setSpeed(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		object->setSpeed(10);
		TS_ASSERT_EQUALS(object->getSpeed(), 10);
	}

	/**
	 * @brief test whether setSpeed function works well in negative values.
	 */
	void Test_setSpeed_Negative(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		object->setSpeed(-1);
		TS_ASSERT_LESS_THAN_EQUALS(0,object->getSpeed());
	}

	/**
	 * @brief test whether getOrientation function works well.
	 */
	void Test_getOrientation(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		TS_ASSERT_EQUALS(object->getOrientation(), 6);
	}
		
	/**
	 * @brief test whether getSpeed function works well.
	 */
	void Test_getSpeed(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		TS_ASSERT_EQUALS(object->getSpeed(), 3);
	}
	
	/**
	 * @brief test whether getColor function works well.
	 */
	void Test_getColor_1(void)
	{
		float arr[] = {0.4f, 0.5f, 0.7f}; 
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		TS_ASSERT_EQUALS((object->getColor()[0]), arr[0]);
	}
	
	/**
	 * @brief test whether getColor function works well.
	 */
	void Test_getColor_2(void)
	{
		float arr[] = {0.4f, 0.5f, 0.7f}; 
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		TS_ASSERT_EQUALS((object->getColor()[1]), arr[1]);
	}
	
	/**
	 * @brief test whether getColor function works well.
	 */
	void Test_getColor_3(void)
	{
		float arr[] = {0.4f, 0.5f, 0.7f}; 
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		TS_ASSERT_EQUALS((object->getColor()[2]), arr[2]);
	}
	
	/**
	 * @brief test whether getObjectType function works well.
	 */
	void Test_getObjectType(void)
	{
		float arr[] = {0.4, 3.5, 2.7}; 
		Object *object1 = new Object();
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		TS_ASSERT_EQUALS(object->getObjectType(), Robot);
	}
	
	/**
	 * @brief test whether getShapeType function works well.
	 */
	void Test_getShapeType(void)
	{
		float arr[] = {0.4, 3.5, 2.7}; 
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);
		TS_ASSERT_EQUALS(object->getShapeType(), Circle);
	}
		
	/**
	 * @brief test whether getID function works well.
	 */
	void Test_getID(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object = new Object(2,4,5,3,6, Circle, Robot, arr, 7);		
		TS_ASSERT_EQUALS(object->getID(), 7);
	}
	
	/**
	 * @brief test whether detectWall function works well in collision with Top wall situation.
	 */
	void Test_detectWallTouch_Top(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object1 = new Object(400, 790, 10, 20, 10, Circle, Robot, arr, 8); // Touch the top wall
		Wall result1 = object1->detectWall(800, 800);
		TS_ASSERT_EQUALS(result1, Top);
	}

	/**
	 * @brief test whether detectWall function works well in collision with Bottom wall situation.
	 */
	void Test_detectWallTouch_Bottom(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object1 = new Object(400, 10, 10, 20, 10, Circle, Robot, arr, 8); // Touch the bottom wall
		Wall result1 = object1->detectWall(800, 800);
		TS_ASSERT_EQUALS(result1, Bottom);
	}

	/**
	 * @brief test whether detectWall function works well in collision with Left wall situation.
	 */
	void Test_detectWallTouch_Left(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object1 = new Object(10, 400, 10, 20, 10, Circle, Robot, arr, 8); // Touch the left wall
		Wall result1 = object1->detectWall(800, 800);
		TS_ASSERT_EQUALS(result1, Left);
	}

	/**
	 * @brief test whether detectWall function works well in collision with Right wall situation.
	 */
	void Test_detectWallTouch_Right(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object1 = new Object(790, 400, 10, 20, 10, Circle, Robot, arr, 8); // Touch the right wall
		Wall result1 = object1->detectWall(800, 800);
		TS_ASSERT_EQUALS(result1, Right);
	}

	/**
	 * @brief test whether detectWall function works well in collision with Top wall situation.
	 */
	void Test_detectWallOut_Top(void)
	{

		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object2 = new Object(400, 790, 15, 30, 20, Circle, Robot, arr, 8); // Out of the top wall
		Wall result2 = object2->detectWall(800, 800);
		TS_ASSERT_EQUALS(result2, Top);
	}

	/**
	 * @brief test whether detectWall function works well in collision with Bottom wall situation.
	 */
	void Test_detectWallOut_Bottom(void)
	{

		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object2 = new Object(400, 10, 15, 30, 20, Circle, Robot, arr, 8); // Out of the bottom wall
		Wall result2 = object2->detectWall(800, 800);
		TS_ASSERT_EQUALS(result2, Bottom);
	}

	/**
	 * @brief test whether detectWall function works well in collision with Left wall situation.
	 */
	void Test_detectWallOut_Left(void)
	{

		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object2 = new Object(10, 500, 15, 30, 20, Circle, Robot, arr, 8); // Out of the left wall
		Wall result2 = object2->detectWall(800, 800);
		TS_ASSERT_EQUALS(result2, Left);
	}

	/**
	 * @brief test whether detectWall function works well in collision with Right wall situation.
	 */
	void Test_detectWallOut_Right(void)
	{

		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object2 = new Object(790, 500, 15, 30, 20, Circle, Robot, arr, 8); // Out of the right wall
		Wall result2 = object2->detectWall(800, 800);
		TS_ASSERT_EQUALS(result2, Right);
	}

	/**
	 * @brief test whether detectWall function works well in collision with Top wall situation.
	 */
	void Test_detectWallWithin_Top(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object3 = new Object(400, 750, 20, 20, 10, Circle, Robot, arr, 8); // within the top wall
		Wall result3 = object3->detectWall(800, 800);
		TS_ASSERT_EQUALS(result3, None);
	}

	/**
	 * @brief test whether detectWall function works well in collision with Bottom wall situation.
	 */
	void Test_detectWallWithin_Bottom(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object3 = new Object(400, 50, 20, 20, 10, Circle, Robot, arr, 8); // within the bottom wall
		Wall result3 = object3->detectWall(800, 800);
		TS_ASSERT_EQUALS(result3, None);
	}

	/**
	 * @brief test whether detectWall function works well in collision with Left wall situation.
	 */
	void Test_detectWallWithin_Left(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object3 = new Object(50, 400, 20, 20, 10, Circle, Robot, arr, 8); // within the left wall
		Wall result3 = object3->detectWall(800, 800);
		TS_ASSERT_EQUALS(result3, None);
	}

	/**
	 * @brief test whether detectWall function works well in collision with Right wall situation.
	 */
	void Test_detectWallWithin_Right(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *object3 = new Object(750, 50, 20, 20, 10, Circle, Robot, arr, 8); // within the right wall
		Wall result3 = object3->detectWall(800, 800);
		TS_ASSERT_EQUALS(result3, None);
	}

	/**
	 * @brief test whether detectObstacle function works well
	 */
	void Test_detectOstacleTouch(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *robot = new Object(400,400,10,20,20, Circle, Robot, arr, 8);	//create a robot
		Object *obs1 = new Object(430,440,40, 20, 20, Circle, Robot, arr, 8);
		bool result1 = robot->detectObstacle(*obs1);
		TS_ASSERT_EQUALS(result1,true);
	}

	/**
	 * @brief test whether detectObstacle function works well in no collision situation.
	 */
	void Test_detectObstacleNoCol(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *robot = new Object(400,400,10,20,20, Circle, Robot, arr, 8);	//create a robot
		Object *obs2 = new Object(600,700,10, 20, 20, Circle, Robot, arr, 8);		
		bool result2 = robot->detectObstacle(*obs2);
		TS_ASSERT_EQUALS(result2,false);
	}
	
	/**
	 * @brief test whether detectObstacle function works well
	 */
	void Test_detectObstacleCol(void)
	{
		float arr[] = {0.4, 3.5, 2,7}; 
		Object *robot = new Object(400,400,10,20,20, Circle, Robot, arr, 8);	//create a robot
		Object *obs3 = new Object(410,410,10, 20, 20, Circle, Robot, arr, 8);  // collision with robot
		bool result3 = robot->detectObstacle(*obs3);
		TS_ASSERT_EQUALS(result3,true);
	}
	

};
