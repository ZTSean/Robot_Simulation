/**
 * @file Shape.cpp
 * @author Group Meryl_Streep
 * @date 15 Feb 2015
 * @brief Details of Shape
 * 
 */
 
 
#include "Shape.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

// Shape constructors
Shape::Shape()
{
	srand(time(NULL));
	pos_x = rand() % 800;
	pos_y = rand() % 800;
	size = rand() % 100;
}

Shape::Shape(double x, double y, double w, double l, double s, double sp, ShapeType shapeType, float c[3])
{
	pos_x = x;
	pos_y = y;
	size = s;
	
}

Shape::~Shape()
{
	
}


// original function from Shapes
void Shape::setPosition(int x, int y)
{
	if (x > 800){
		cout << "x is too large, it should be less than 800." << endl;
		pos_x = getrand() % 800;
	}else if (x < 0){
		cout << "size should be greater than 0." << endl;
		pos_x = getrand() % 800;
	}else{
		pos_x = x;
	}
	
	if (y > 800){
		cout << "y is too large, it should be less than 800." << endl;
		pos_y = getrand() % 800;
	}else if (y < 0){
		cout << "y should be greater than 0." << endl;
		pos_y = getrand() % 800;
	}else{	
		pos_y = y;
	}
}

void Shape::setSize(int s)
{
	if (s > 100){
		cout << "size is too large, it should be less than 100." << endl;
		s = getrand() % 100;
	}else if (s < 0){
		cout << "size should be greater than 0." << endl;
		s = getrand() % 100;
	}else{
		size = s;
	}
}

int Shape::getrand(){
	srand(time(NULL));
	return rand();
}

int Shape::getXPosition()
{
	return pos_x;
}

int Shape::getYPosition()
{
	return pos_y;
}

int Shape::getSize()
{
	return size;
}
