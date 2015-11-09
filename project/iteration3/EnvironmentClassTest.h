/**
 * @file EnvironmentClassTest.h
 * @author Group Meryl_Streep
 * @date 12 Mar 2015
 * @brief The Tests for environment functions
 * 
 */
 
#include <cxxtest/TestSuite.h>
#include "EnvironmentClass.h"
#include <math.h>
#include <GL/glut.h>
#include "Object.h"
#include <stdlib.h>

using namespace std;

class EnvironmentClassTest : public CxxTest::TestSuite
{
	public: 
	
	/**
	 * @brief When the target is at the direction of exactly up left, reset the Navigate's direction to 45.
	 * @param void
	 * 
	 * 
	 */
	void Test_HomingSensorReading_upLeftorRight(void)
	{
		vector<Object> *objects = new vector<Object>();;
		float arr[] = {0.4, 0.7, 0.8};
		Object object1(2,4,5,3,6, Circle, Robot, arr, 7);
		Object object2(22,24,5,3,26, Circle, Target, arr, 7);
		EnvironmentClass aEnv(640000,800,800, objects);
		aEnv.registerObject(object2);
		TS_ASSERT_EQUALS(aEnv.homingSensorReading(object1).deltaOri, (double)45);
	}
	
	
	/**
	 * @brief When the target is at the direction of exactly downright, reset the direction of Navigate to 315, which is 360-315
	 * @param void
	 */

	void Test_HomingSensorReading_downLeftorRight(void)
	{
		vector<Object> *objects = new vector<Object>();;
		float arr[] = {0.4, 0.7, 0.8};
		Object object1(2,24,5,3,6, Circle, Robot, arr, 7);
		Object object2(22,4,5,3,280, Circle, Target, arr, 7);
		EnvironmentClass aEnv(640000,800,800, objects);
		aEnv.registerObject(object2);
		TS_ASSERT_EQUALS(aEnv.homingSensorReading(object1).deltaOri, (double)315);
	}
	
	/**
	 * @brief When the target is at the direction of exactly up, reset the direction of Navigate to 90 degrees, which makes the direction to 90. 
	 * @param void
	 */

	void Test_HomingSensorReading_Up(void)
	{
		vector<Object> *objects = new vector<Object>();;
		float arr[] = {0.4, 0.7, 0.8};
		Object object1(22,4,5,3,6, Circle, Robot, arr, 7);
		Object object2(22,24,5,3,280, Circle, Target, arr, 7);
		EnvironmentClass aEnv(640000,800,800, objects);
		aEnv.registerObject(object2);
		TS_ASSERT_EQUALS(aEnv.homingSensorReading(object1).deltaOri, (double)90);
	}
	
	/**
	 * @brief When the target is at the direction of exactly below, reset the direction of Navigate to 270, which makes the robot points down. 
	 * @param void
	 */

	void Test_HomingSensorReading_down(void)
	{
		vector<Object> *objects = new vector<Object>();;
		float arr[] = {0.4, 0.7, 0.8};
		Object object1(22,24,5,3,6, Circle, Robot, arr, 7);
		Object object2(22,4,5,3,280, Circle, Target, arr, 7);
		EnvironmentClass aEnv(640000,800,800, objects);
		aEnv.registerObject(object2);
		TS_ASSERT_EQUALS(aEnv.homingSensorReading(object1).deltaOri, (double)270);
	}
	
	/**
	 * @brief When the center of Obstacle is below the line drawn by the robot, and orientation of robot is between 0 and 90, decrement the orientation of robot by 90 degrees
	 * @param void
	 */
	
	void Test_update_collide_otherObj_Not_Verticle_below(void)
	{
		vector<Object> *objects = new vector<Object>();
		float arr[] = {0.4, 0.7, 0.8};
		Object object1(22,22,5,6,40, Circle, Robot, arr, 7);
		Object object2(32,32,5,0,0, Circle, Obstacle, arr, 7);
		EnvironmentClass aEnv(640000,800,800, objects);
		aEnv.registerObject(object1);
		aEnv.registerObject(object2);
		aEnv.update(1);
		TS_ASSERT_EQUALS((*objects)[0].getOrientation(), (double)310);
	}
	
	/**
	 * @brief When the center of Obstacle is at the same horizon with the line drawn by the robot, increment the orientation of robot by 180 degrees, which means make it move back. 
	 * @param void
	 */

	void Test_update_collide_otherObj_Not_Verticle_hori(void)
	{
		vector<Object> *objects = new vector<Object>();
		float arr[] = {0.4, 0.7, 0.8};
		Object object1(33,33,5,1,0, Circle, Robot, arr, 7);
		Object object2(42,33,5,0,0, Circle, Obstacle, arr, 7);
		EnvironmentClass aEnv(640000,800,800, objects);
		aEnv.registerObject(object1);
		aEnv.registerObject(object2);
		aEnv.update(10);
		TS_ASSERT_EQUALS((*objects)[0].getOrientation(), (double)180);
	}
	
	/**
	 * @brief When the center of Obstacle is above the line drawn by the robot, and orientation is between 0 and 90, decrement the orientation of robot by 90 degrees
	 * @param void
	 */

	void Test_update_collide_otherObj_Not_Verticle_above(void)
	{
		vector<Object> *objects = new vector<Object>();
		float arr[] = {0.4, 0.7, 0.8};
		Object object1(17,17,5,3,60, Circle, Robot, arr, 7);
		Object object2(22,22,5,0,0, Circle, Obstacle, arr, 7);
		EnvironmentClass aEnv(640000,800,800, objects);
		aEnv.registerObject(object1);
		aEnv.registerObject(object2);
		aEnv.update(1);
		TS_ASSERT_EQUALS((*objects)[0].getOrientation(), (double)330);
	}
	
	/**
	 * @brief When the center of Obstacle is to the right of the line drawn by the robot, and the orientaion of robot is 270, which means moving downwards, decrement the orientation by 90 degrees
	 * @param void
	 */

	void Test_update_collide_otherObj_Verticle_right(void)
	{
		vector<Object> *objects = new vector<Object>();
		float arr[] = {0.4, 0.7, 0.8};
		Object object1(18,27,5,1,270, Circle, Robot, arr, 7);
		Object object2(22,22,5,0,0, Circle, Obstacle, arr, 7);
		EnvironmentClass aEnv(640000,800,800, objects);
		aEnv.registerObject(object1);
		aEnv.registerObject(object2);
		aEnv.update(1);
		TS_ASSERT_EQUALS((*objects)[0].getOrientation(), (double)180);
	}

	/**
	 * @brief When the center of Obstacle is to the left of the line drawn by the robot, and orientation is 90, which means moving upwards, decrement the orientation of robot by 90 degrees
	 * @param void
	 */

	void Test_update_collide_otherObj_Verticle_left(void)
	{
		vector<Object> *objects = new vector<Object>();
		float arr[] = {0.4, 0.7, 0.8};
		Object object1(23,20,5,5,(double)90, Circle, Robot, arr, 7);
		Object object2(20,30,5,0,0, Circle, Obstacle, arr, 7);
		EnvironmentClass aEnv(640000,800,800, objects);
		aEnv.registerObject(object1);
		aEnv.registerObject(object2);
		aEnv.update(1);
		TS_ASSERT_EQUALS((*objects)[0].getOrientation(), (double)0);
	}
	
	/**
	 * @brief When the center of Obstacle is on the line drawn by the robot, and the robot is moving vertically, decrement the orientation of robot by 180. 
	 * @param void
	 * */

	void Test_update_collide_otherObj_Verticle_Ver(void)
	{
		vector<Object> *objects = new vector<Object>();
		float arr[] = {0.4, 0.7, 0.8};
		Object object1(22,22,5,5,270, Circle, Robot, arr, 7);
		Object object2(22,9,5,0,0, Circle, Obstacle, arr, 7);
		EnvironmentClass aEnv(640000,800,800, objects);
		aEnv.registerObject(object1);
		aEnv.registerObject(object2);
		aEnv.update(1);
		TS_ASSERT_EQUALS((*objects)[0].getOrientation(), (double)90);
	}
	
	
	/**
	 * @brief The following 8 test cases are to detect collision with Wall. For this function, it tests when the orientatioin is between 0 and 90, and it touched the top wall, it's orientation will decrement by 90.
	 * @param void
	 * */

	void Test_updatecollide_top_turn_right(void)
	{
		vector<Object> *objects = new vector<Object>();;
		float arr[] = {0.4, 0.7, 0.8};
		Object object1(400,780,10,2,45, Circle, Robot, arr, 7);
		//objects->push_back(object1);
		EnvironmentClass aEnv(640000,800,800, objects);
		aEnv.registerObject(object1);
		aEnv.update(10);
		TS_ASSERT_EQUALS((*objects)[0].getOrientation(),(double)315);

	}
	
	/**
	 * @brief For this function, it tests when the orientatioin is between 90 and 180, and it touched the top wall, it's orientation will increment by 90.
	 * @param void
	 * */
	void Test_update_collide_top_turn_left(void)
	{
		vector<Object> *objects = new vector<Object>();
		float arr[] = {0.4, 0.7, 0.8};
		Object object1(400,780,10,2,135, Circle, Robot, arr, 7);
		//objects->push_back(object1);
		EnvironmentClass aEnv(640000,800,800, objects);
		aEnv.registerObject(object1);
		aEnv.update(10);
		TS_ASSERT_EQUALS((*objects)[0].getOrientation(),(double)225);
	}

	/**
	 * @brief For this function, it tests when the orientatioin is between 180 and 270, and it touched the bottom wall, it's orientation will decrement by 90.
	 * @param void
	 * */
	void Test_update_collide_bottom_turn_right(void)
	{
		vector<Object> *objects = new vector<Object>();
		float arr[] = {0.4, 0.7, 0.8};
		Object object1(500,20,10,2,225, Circle, Robot, arr, 7);
		//objects->push_back(object1);
		EnvironmentClass aEnv(640000,800,800, objects);
		aEnv.registerObject(object1);
		aEnv.update(10);
		TS_ASSERT_EQUALS((*objects)[0].getOrientation(),(double)135);
	}
	
	/**
	 * @brief For this function, it tests when the orientatioin is between 180 and 360, and it touched the bottom wall, it's orientation will decrement by 90.
	 * @param void
	 * */
	void Test_update_collide_bottom_turn_left(void)
	{
		vector<Object> *objects = new vector<Object>();;
		float arr[] = {0.4, 0.7, 0.8};
		Object object1(400,20,10,2,315, Circle, Robot, arr, 7);
		//objects->push_back(object1);
		EnvironmentClass aEnv(640000,800,800, objects);
		aEnv.registerObject(object1);
		aEnv.update(10);
		TS_ASSERT_EQUALS((*objects)[0].getOrientation(),(double)45);
	}

	/**
	 * @brief For this function, it tests when the orientatioin is between 90 and 180, and it touched the right wall, it's orientation will decrement by 90.
	 * @param void
	 */
	void Test_update_collide_left_turn_right(void)
	{
		vector<Object> *objects = new vector<Object>();;
		float arr[] = {0.4, 0.7, 0.8};
		Object object1(20,500,10,2,135, Circle, Robot, arr, 7);
		//objects->push_back(object1);
		EnvironmentClass aEnv(640000,800,800, objects);
		aEnv.registerObject(object1);
		aEnv.update(10);
		TS_ASSERT_EQUALS((*objects)[0].getOrientation(),(double)45);
	}
	
	/**
	 * @brief For this function, it tests when the orientatioin is between 180 and 270, and it touched the right wall, it's orientation will increment by 90.
	 * @param void
	 */
	void Test_update_collide_left_turn_left(void)
	{
		vector<Object> *objects = new vector<Object>();;
		float arr[] = {0.4, 0.7, 0.8};
		Object object1(20,500,10,2,225, Circle, Robot, arr, 7);
		//objects->push_back(object1);
		EnvironmentClass aEnv(640000,800,800, objects);
		aEnv.registerObject(object1);
		aEnv.update(10);
		TS_ASSERT_EQUALS((*objects)[0].getOrientation(),(double)315);
	}
	
	/**
	 * @brief For this function, it tests when the orientatioin is between 270 and 360, and it touched the right wall, it's orientation will decrement by 90.
	 * @param void
	 */
	void Test_update_collide_right_turn_right(void)
	{
		vector<Object> *objects = new vector<Object>();;
		float arr[] = {0.4, 0.7, 0.8};
		Object object1(2,5,1,2,315, Circle, Robot, arr, 7);
		//objects->push_back(object1);
		EnvironmentClass aEnv(100,10,10, objects);
		aEnv.registerObject(object1);
		aEnv.update(10);
		TS_ASSERT_EQUALS((*objects)[0].getOrientation(),(double)225);
	}
	
	/**
	 * @brief For this function, it tests when the orientatioin is between 0 and 90, and it touched the right wall, it's orientation will increment by 90.
	 * @param void
	 */
	void Test_update_collide_right_turn_left(void)
	{
		vector<Object> *objects = new vector<Object>();;
		float arr[] = {0.4, 0.7, 0.8};
		Object object1(780,500,10,2,45, Circle, Robot, arr, 7);
		//objects->push_back(object1);
		EnvironmentClass aEnv(640000,800,800, objects);
		aEnv.registerObject(object1);
		aEnv.update(10);
		TS_ASSERT_EQUALS((*objects)[0].getOrientation()
		,(double)135);
	}
	
	/**
	 * @brief When there's one object registered, getCount() function return 1.
	 * @param void
	 */

	void Test_getCount()
	{
		vector<Object> *objects = new vector<Object>();;
		float arr[] = {0.4, 0.7, 0.8};
		Object object1(2,5,1,2,45, Circle, Robot, arr, 7);
		//objects->push_back(object1);
		EnvironmentClass aEnv(640000,800,800, objects);
		aEnv.registerObject(object1);
		TS_ASSERT_EQUALS(aEnv.getCount(),1);		
	}	
	
	/**
	 * @brief To test that when two objects are registered, getCount() function returns two
	 * @param void
	 */
	
	void Test_registerObject(Object obj){
		vector<Object> *objects = new vector<Object>();;
		float arr[] = {0.4, 0.7, 0.8};
		Object object1(2,5,1,2,45, Circle, Robot, arr, 7);
		Object object2(8,8,1,2,45, Circle, Robot, arr, 7);
		//objects->push_back(object1);
		EnvironmentClass aEnv(6400,800,800, objects);
		aEnv.registerObject(object1);	
		aEnv.registerObject(object2);
		TS_ASSERT_EQUALS(aEnv.getCount(),2);
	}
	
	/**
	 * @brief When the target is found, the status marked is 1
	 * @param void
	 */


	void Test_touchSensorReading_find_target(Object obj){
		vector<Object> *objects = new vector<Object>();;
		float arr[] = {0.4, 0.7, 0.8};
		Object object1(6,2,1,2,315, Circle, Robot, arr, 7);
		Object object2(4,2,1,2,315, Circle, Target, arr, 7);
		//objects->push_back(object1);
		EnvironmentClass aEnv(640000,800,800, objects);
		aEnv.registerObject(object2);
		aEnv.update(0);
		TS_ASSERT_EQUALS(aEnv.touchSensorReading(object1),1);		
	}
	
	/**
	 * @brief When there is only one object and it's Robot, the robot would find itself, so the status is marked as 0
	 * @param void
	 */
	void Test_touchsensorReading_find_self(Object obj){
		vector<Object> *objects = new vector<Object>();;
		float arr[] = {0.4, 0.7, 0.8};
		Object object1(5,2,1,2,315, Circle, Robot, arr, 7);
		//objects->push_back(object1);
		EnvironmentClass aEnv(640000,800,800, objects);
		aEnv.registerObject(object1);
		aEnv.update(10);
		TS_ASSERT_EQUALS(aEnv.touchSensorReading(object1),0);
	}
	
	/**
	 * @brief When wall is detected, the status is marked ad 3.
	 * @param void
	 */

	void Test_touchSensorReading_detect_wall(Object obj){
		vector<Object> *objects = new vector<Object>();;
		float arr[] = {0.4, 0.7, 0.8};
		Object object1(9,2,2,2,315, Circle, Robot, arr, 7);
		//objects->push_back(object1);
		EnvironmentClass aEnv(640000,800,800, objects);
		//aEnv->registerObject(object1);
		aEnv.update(0);
		TS_ASSERT_EQUALS(aEnv.touchSensorReading(object1),3);
	}

	/**
	 * @brief When Robot finds other objects, the status is marked as 2. 
	 * @param void
	 */
	void Test_touchSensorReading_find_other_object(Object obj){
		vector<Object> *objects = new vector<Object>();;
		float arr[] = {0.4, 0.7, 0.8};
		Object object1(6,2,1,2,315, Circle, Robot, arr, 7);
		Object object2(4,2,1,2,315, Circle, Obstacle, arr, 6);
		//objects->push_back(object1);
		EnvironmentClass aEnv(640000,800,800, objects);
		aEnv.registerObject(object1);
		aEnv.update(0);
		TS_ASSERT_EQUALS(aEnv.touchSensorReading(object2),2);
	}

	/**
	 * @brief When one is Target, other is not, and collision detected, decrements the objects count by 2
	 * @param void
	 */

	void Test_update_Find_Target(void)
	{
		vector<Object> *objects = new vector<Object>();;
		float arr[] = {0.4, 0.7, 0.8}; 
		Object object1(10,50,5,1,90, Circle, Robot, arr, 7);
		Object object2(10,60,5,1,270, Circle, Target, arr, 7);
		EnvironmentClass aEnv(640000,800,800, objects);
		aEnv.registerObject(object1);
		aEnv.registerObject(object2);
		aEnv.update(1);
		TS_ASSERT_EQUALS(aEnv.getCount(), 0);
	}
	
	/**
	 * @brief This test case is to test when there is no collision, the orientation of robot keeps unchanges.
	 * @param void
	 * */

	void Test_update_No_Collision(void)
	{
		vector<Object> *objects = new vector<Object>();;
		float arr[] = {0.4, 0.7, 0.8}; 
		Object object1(400,400,5,3,45, Circle, Robot, arr, 7);
		EnvironmentClass aEnv(640000, 800, 800, objects);
		aEnv.registerObject(object1);
		aEnv.update(10);
		TS_ASSERT_EQUALS((*objects)[0].getOrientation(), (double)45);
	}





};
