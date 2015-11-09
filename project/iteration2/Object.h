/**
 * @file Object.h
 * @author Group Meryl_Streep
 * @date 9 March 2015
 * @brief The Object Class
 * 
 */
 
#ifndef OBJECT_H
#define OBJECT_H
#include <stdlib.h>

struct Navigate{						/**< Vector including distance and orientation information that robot need to locate target*/
	double deltaDistance;
	double deltaOri;
}; 

enum ObjectType{						/**< Type of Object*/
	Robot,
	Obstacle,
	Target
};

enum ShapeType{							/**< Shape type of Object*/
	Circle,
	Triangle,
	Quad
};
	
enum Wall{								/**< Different walls*/
	None,
	Top,
	Bottom,
	Left,
	Right
};

/**
 * @brief Super Class of RobotClass, Target and Obstacle, contains position x, y and size
 */
class Object    // get from lab02 shapes.h
{
	private:
		ObjectType objType;				/**< type of object*/
		ShapeType shapeType;		        	/**< shape of object*/
		int ID;						/**< ID of object*/
		double size;					/**< size of object*/
		double pos_x;					/**< x position of object*/
		double pos_y;					/**< y position of object*/
		float color[3];					/**< color of object*/
		double speed;					/**< speed of object*/
		double orientation;				/**< orientation of object*/
		
	public:
	
		/**
		 * @brief The default constructor.
		 */
		Object();
		
		/**
		 * @brief A Constructor.
		 * @param x The x position of object.
		 * @param y The y position of object.
		 * @param s The size of object.
		 * @param sp The speed of object.
		 * @param ori The orientation of the object
		 * @param sh The shapeType of the object. Circle/Triangle/ quad
		 * @param objtype The Type og the Object. Robot/ Obstacle/ Target
		 * @param c[3] The color of object indicated by an array of floats. 
		 * @param ID A unique ID number for each object. 
		 */
		Object(double x, double y, double s, double sp,double ori, ShapeType sh, ObjectType objtype, float c[3], int id);
		
		/**
		 * @brief The default constructor.
		 */
		~Object();

		/**
		 * @brief Set Object's shape through arguements. 
		 * @param shape Set Object's shape according to the shape passed in.
		 */ 
		void setShape(ShapeType shape);

		/**
		 * @brief Set Object's color through arguements. 
		 * @param c[] Set Object's color according to the array passed in.
		 */ 
		void setColor(float c[]);

		/**
		 * @brief Set Object's type through arguements. 
		 * @param obj Set Object's type according to the array passed in, the arguement obj could be robot, obstacle or target.
		 */ 
		void setType(ObjectType obj);
		
		/**
		 * @brief Set Object's Position through arguements. 
		 * @param x Set Object's position according to arguement double x.
		 * @param y Set Object's position according to arguement double y.
		 */ 
		void setPosition(double x, double y);
		
		/**
		 * @brief set Object's size through arguement.
		 * @param size Set Object's size according to arguement double s.
		 */
		void setSize(double s);
		
		// methods
		/**
		 * @brief Return current x position of Object.
		 */
		double getXPosition();
		
		/**
		 * @brief Return current y position of Object.
		 */
		double getYPosition();
		
		/**
		 * @brief Return current size of Object.
		 */
		double getSize();
		
		/**
		 * @brief Set Object's orientation through arguement. 
		 * @param degrees Set object's orientation according to arguement double degrees.
		 */ 
		void setOrientation(double degrees); // orientation in degrees
		
		/**
		 * @brief set Object's speed through arguement.
		 * @param pps Set object's speed according to arguement double pps.
		 */
		void setSpeed(double pps); // speed in pixels per second

		/**
		 * @brief Return current orientation of Object.
		 */
		double getOrientation();
		
		/**
		 * @brief Return current speed of Object.
		 */
		double getSpeed();
		
		/**
		 * @brief Return movement vector in elapsed time.
		 * @param elapsedTime delta time since start time
		 */
		Navigate move(double elapsedTime);

		/**
		 * @brief Return movement vector in certain degree.
		 * @param d The degree that object will rotate.
		 */
		Navigate rotate(double d);
		
		
		/**
		 * @brief Set Object's color through arguements. 
		 */ 
		float * getColor();
		
		/**
		 * @brief Return Object's type through arguements. 
		 */ 
		ObjectType getObjectType();
		
		/**
		 * @brief Return Object's shape through arguements. 
		 */ 
		ShapeType getShapeType();
		
		
		/**
		 * @brief Return Object's ID through arguements. 
		 */ 
		int getID();
		
		/**
		 * @brief Return the type of wall that the Object detects.
		 * @param width The width of the wall.
		 * @param height The height of the wall.
		 */ 
		Wall detectWall(int width, int height);
		
		/**
		 * @brief Return if a Object detects an obstacle. 
		 * @param obj The object to be detected whether there is a collision with it.
		 */ 
		bool detectObstacle(Object obj);

};


#endif
