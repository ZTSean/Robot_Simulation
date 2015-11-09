/**
 * @file Shape.h
 * @author Group Meryl_Streep
 * @date 15 Feb 2015
 * @brief The Super Class
 * 
 */
 
#ifndef SHAPE_H
#define SHAPE_H

enum ShapeType{						/**< Shape type of Object*/
	Circle,
	Triangle,
	Quad
};
	
enum Wall{							/**< Different walls*/
	None,
	Top,
	Bottom,
	Left,
	Right
};

/**
 * @brief Super Class of RobotClass, Target and Obstacle, contains position x, y and size
 */
class Shape    // get from lab02 shapes.h
{
	private:
		ShapeType shapeType;
		int ID;
		double width;					/**< size of shape*/
		double length;					
		double pos_x;					/**< x position of shape*/
		double pos_y;					/**< y position of shape*/
		float color[3];				/**< color of shape*/
		
	public:
	
		/**
		 * @brief The default constructor.
		 */
		Shape();
		
		/**
		 * @brief A Constructor.
		 * @param x The x position of Shape.
		 * @param y The y position of Shape.
		 * @param size The size of Shape.
		 */
		Shape(int x, int y, int size);
		
		/**
		 * @brief The default deconstructor.
		 */
		~Shape();

		// modifiers
		/**
		 * @brief Set Shape's Position through arguements. 
		 * @param x Set Shape's position according to arguement integer x.
		 * @param y Set Shape's position according to arguement integer y.
		 */ 
		void setPosition(int x, int y);
		
		/**
		 * @brief set Shape's size through arguement.
		 * @param size Set Shape's size according to arguement integer s.
		 */
		void setSize(int s);
		
		/**
		 * @brief return random integer value.
		 */
		int getrand();
		
		// methods
		/**
		 * @brief Return current x position of Shape.
		 */
		int getXPosition();
		
		/**
		 * @brief Return current y position of Shape.
		 */
		int getYPosition();
		
		/**
		 * @brief Return current size  of Shape.
		 */
		int getSize();
		
		void moveBehavior();
};


#endif
