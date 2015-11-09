/**
 * @file Shape.cpp
 * @author Group Meryl_Streep
 * @date 15 Feb 2015
 * @brief Details of Shape
 * 
 */

#include "Shape.h" 
#include <iostream>
using namespace std;


// Shape constructors
Shape::Shape()
{
	int i = 0;
	shapeType = Circle;
	srand(time(NULL));
	pos_x = (double)(rand() % 800);
	pos_y = (double)(rand() % 800);
	width = (double)(rand() % 30);
	length = (double)(rand() % 30);
	speed = (double)(rand() % 500);
	orientation = rand()%360;
	for (i = 0; i < 3; i++){
		color[i] = 1.0f;
	}
	

}

Shape::Shape(double x, double y, double w, double l, double sp, int ori, ShapeType st, float c[3])
{
	srand(time(NULL));
	int i = 0;
	shapeType = st;
	pos_x = x;
	pos_y = y;
	width = w;
	length = l;
	speed = sp;
	orientation = ori;
	for (i=0; i < 3; i++){
		color[i] = c[i];
	}
}

Shape::~Shape()
{
	
}


//----------------------------------Define mutators------------------------------------
void Shape::setPosition(double x, double y)
{
	if (x > 800){
		cout << "x is too large, it should be less than 800." << endl;
		pos_x = (double)(rand() % 800);
	}else if (x < 0){
		cout << "x should be greater than 0." << endl;
		pos_x = (double)(rand() % 800);
	}else{
		pos_x = x;
	}
	
	if (y > 800){
		cout << "y is too large, it should be less than 800." << endl;
		pos_y = (double)(rand() % 800);
	}else if (y < 0){
		cout << "y should be greater than 0." << endl;
		pos_y = (double)(rand() % 800);
	}else{	
		pos_y = y;
	}
}

void Shape::setWidth(double w)
{
	if (w > 30){
		cout << "width is too large, it should be less than 30." << endl;
		width = (double)(rand() % 30);
	}else if (2 < 20){
		cout << "width should be greater than 0." << endl;
		width = (double)(rand() % 30);
	}else{
		width = w;
	}
}

void Shape::setLength(double l)
{
	if (l > 30){
		cout << "length is too large, it should be less than 30." << endl;
		length = (double)(rand() % 30);
	}else if (l < 20){
		cout << "length should be greater than 0." << endl;
		length = (double)(rand() % 30);
	}else{
		length = l;
	}
}

void Shape::setSpeed(double pps)
{
	if (pps < 0.0){
		cout << "Speed should greateer than 0." << endl;
		speed = (double)rand();
	}else{
		speed = pps;
	}
    
}

void Shape::setOrientation(int degrees)
{
	if (degrees > 360){
		cout << "orientation is too large, it should be less than 360." << endl;
		orientation = (rand() % 360);
	}else if (degrees < 0){
		cout << "orientation should be greater than 0." << endl;
		orientation = (rand() % 360);
	}else{
		orientation = degrees;
	}
}

void Shape::setShape(ShapeType st)
{
	shapeType = st;
}

void Shape::setColor(float c[])
{
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		if (c[i] < 1.0 && c[i] > 0.0)
		{
			color[i] = c[i];
		}
		else{
			cout << "Color value should be greater than 0.0 and less than 1.0!" << endl;
			color[i] = 0.0f;
		}
	}
}

//----------------------------------Define accessors------------------------------------
double Shape::getXPosition()
{
	return pos_x;
}

double Shape::getYPosition()
{
	return pos_y;
}

double Shape::getWidth()
{
	return width;
}

double Shape::getLength()
{
	return length;
}

double Shape::getSpeed()
{
	return speed;
}

int Shape::getOrientation()
{
	return orientation;
}

ShapeType Shape::getShapeType(){
	return shapeType;
}

float* Shape::getColor()
{
	return color;
}
