/**
 * @file Shape.h
 * @author Group Meryl_Streep
 * @date 8 April 2015
 * @brief The Super Class
 * 
 */
 
#ifndef SHAPE_H
#define SHAPE_H

#include <cstdlib>
#include <time.h>
#include <math.h>


enum ShapeType{						/**< Shape type of Object*/
	Circle,
	Triangle,
	Rectangle,
	Quad
};
	
enum Wall{						/**< Different walls*/
	None,
	Top,
	Bottom,
	Left,
	Right
};


/**
 * @brief Super Class of RobotClass, Target and Obstacle, contains position x, y, width and length
 */
class Shape    // get from lab02 shapes.h
{
	private:
		ShapeType shapeType;
		int ID;
		double width;					/**< width of shape*/
		double length;					/**< length of shape*/
		double pos_x;					/**< x position of shape*/
		double pos_y;					/**< y position of shape*/
		double speed;					/**< speed of shape*/
		double orientation;				/**< direction of shape*/
		float color[3];					/**< color of shape*/
		
	public:
	
		/**
		 * @brief The default constructor.
		 * @author: Zixiao Wang
		 */
		Shape();
		
		/**
		 * @brief A Constructor.
		 * @param x The x position of Shape.
		 * @param y The y position of Shape.
		 * @param w The width of Shape.
		 * @param l The length of Shape.
		 * @param sp The speed of Shape.
		 * @param ori The orientation of Shape.
		 * @param st The ShapeType of Shape.
		 * @param c The color of Shape.
		 * @author: Zixiao Wang
		 */
		Shape(double x, double y, double w, double l, double sp, double ori, ShapeType st, float c[3]);
		
		/**
		 * @brief The default deconstructor.
		 * @author: Zixiao Wang
		 */
		~Shape();

		//-----------------------------mutator------------------------------
		/**
		 * @brief Set Shape's Position through arguements. 
		 * @param x Set Shape's position according to arguement double x.
		 * @param y Set Shape's position according to arguement double y.
		 * @author: Zixiao Wang
		 */ 
		virtual void setPosition(double x, double y);
		
		/**
		 * @brief set Shape's width through arguement.
		 * @param w Set Shape's width according to arguement double w.
		 * @author: Zixiao Wang
		 */
		void setWidth(double w);
		
		/**
		 * @brief set Shape's length through arguement.
		 * @param l Set Shape's length according to arguement double l.
		 * @author: Zixiao Wang
		 */
		void setLength(double l);
		
		/**
		 * @brief set object's speed through arguement.
		 * @param pps Set object's speed according to arguement integer pps.
		 * @author: Zixiao Wang
		 */
		virtual void setSpeed(double pps); // speed in pixels per second
		
		/**
		 * @brief Set Shape's orientation through arguement. 
		 * @param degrees Set Shape's orientation according to arguement integer degrees.
		 * @author: Zixiao Wang
		 */ 
		void setOrientation(double degrees); // orientation in degrees
		
		
		/**
		 * @brief Set SHape's shape through arguements. 
		 * @param shape Set Shape's shape according to the shape passed in.
		 * @author: Zixiao Wang
		 */ 
		void setShape(ShapeType shape);
		
		/**
		 * @brief Set Shape's color through arguements. 
		 * @param c[] Set Shape's color according to the array passed in.
		 * @author: Zixiao Wang
		 */ 
		void setColor(float c[]);
		
		
		//-----------------------------accessor------------------------------
		/**
		 * @brief Return current x position of Shape.
		 * @author: Zixiao Wang
		 */
		double getXPosition();
		
		/**
		 * @brief Return current y position of Shape.
		 * @author: Zixiao Wang
		 */
		double getYPosition();
		
		/**
		 * @brief Return current width of Shape.
		 * @author: Zixiao Wang
		 */
		double getWidth();
		
		/**
		 * @brief Return current length of Shape.
		 * @author: Zixiao Wang
		 */
		double getLength();
		
		/**
		 * @brief Return current speed of object.
		 * @author: Zixiao Wang
		 */
		double getSpeed();
		
		/**
		 * @brief Return current orientation of object.
		 * @author: Zixiao Wang
		 */
		double getOrientation();
		
		/**
		 * @brief Return Object's shape through arguements.
		 * @author: Zixiao Wang
		 */ 
		ShapeType getShapeType();
		
		/**
		 * @brief Get Object's color through arguements.
		 * @author: Zixiao Wang
		 */ 
		float * getColor();
		
		//-----------------------helper function-----------------------------
		double regular_Ori(double d);			// regular orientation to range from 0 - 360
		
		
		
};


#endif
