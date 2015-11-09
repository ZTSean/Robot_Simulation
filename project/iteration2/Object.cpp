/**
 * @file Object.cpp
 * @author Group Meryl_Streep
 * @date 9 March 2015
 * @brief The representation of Object within the simulation
 * 
 */

#include "Object.h"
#include <iostream>
using namespace std;

// Object constructors
Object::Object()
{
	shapeType = Circle;
	speed = 10.0d;
	orientation = (double)(rand() % 360);
	cout << "robot a = " << getXPosition() << endl;
	cout << "robot b = " << getYPosition() << endl;
}

Object::Object(double x,double y,double s, double sp,double ori, ShapeType sh, ObjectType objtype, float c[3], int id)
{
	int i = 0;
	shapeType = sh;
	pos_x = x;
	pos_y = y;
	size = s;
	speed = sp;
	orientation = ori;
	objType = objtype;
	for (i=0; i < 3; i++){
		color[i] = c[i];
	}
	ID = id;
}

Object::~Object()
{
	
}

// special functions for Object
void Object::setShape(ShapeType shape)
{
	shapeType = shape;
}

void Object::setColor(float c[])
{
	int i = 0;
	for (i = 0; i < 3;i++)
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

void Object::setType(ObjectType obj)
{
	objType = obj;
}

void Object::setOrientation(double degrees)
{
	if (degrees > (double)360){
		cout << "orientation is too large, it should be less than 360." << endl;
		cout <<"Orientation is: "<< degrees <<endl;
		orientation = (double)(rand() % 360);
	}else if (degrees < (double)0){
		cout << "orientation should be greater than 0." << endl;
		cout <<"Orientation is: "<< degrees <<endl;
		orientation = (double)(rand() % 360);
	}else{
		orientation = degrees;
	}
}

void Object::setSpeed(double pps)
{
	if (pps < 0.0){
		cout << "Speed should greateer than 0." << endl;
		speed = (double)rand();
	}else{
		speed = pps;
	}
    
}
void Object::setPosition(double x, double y)
{
	if (x > 800){
		cout << "x is too large, it should be less than 800." << endl;
		pos_x = (double)(rand() % (int)((800.0-2*size) + size));
	}else if (x < 0){
		cout << "size should be greater than 0." << endl;
		pos_x = (double)(rand() % (int)((800.0-2*size) + size));
	}else{
		pos_x = x;
	}
	
	if (y > 800){
		cout << "y is too large, it should be less than 800." << endl;
		pos_y = (double)(rand() % (int)((800.0-2*size) + size));
	}else if (y < 0){
		cout << "y should be greater than 0." << endl;
		pos_y = (double)(rand() % (int)((800.0-2*size) + size));
	}else{	
		pos_y = y;
	}
}

void Object::setSize(double s)
{
	if (s > 60){
		cout << "size is too large, it should be less than 60." << endl;
		size = (double)(20 + rand() % 40);
	}else if (s < 20){
		cout << "size should be greater than 20." << endl;
		size = (double)(20 + rand() % 40);
	}else{
		size = s;
	}
}

double Object::getXPosition()
{
	return pos_x;
}

double Object::getYPosition()
{
	return pos_y;
}

double Object::getSize()
{
	return size;
}

double Object::getOrientation()
{
	return orientation;
}


double Object::getSpeed()
{
	return speed;
}

float* Object::getColor()
{
	return color;
}

ObjectType Object::getObjectType(){
	return objType;
}

ShapeType Object::getShapeType(){
	return shapeType;
}


int Object::getID(){
	return ID;
}



Navigate Object::move(double elapsedTime)
{
	Navigate m;
	m.deltaDistance = getSpeed() * elapsedTime;
	m.deltaOri = getOrientation();
	return m;
}

Navigate Object::rotate(double d){
	Navigate m;
	m.deltaDistance = 0.0;
	int dd = (int(d + getOrientation()))%360; 
	m.deltaOri = (double)dd;
	return m;
}


Wall Object::detectWall(int width, int height)
{
	if ( (getXPosition() + getSize()) >= width )
	{
		return Right;
	}else if ( getXPosition() <= getSize())
	{
		return Left;
	}
	else if ( (getYPosition() + getSize()) >= height)
	{
		return Top;
	}else if (getYPosition() <= getSize())
	{
		return Bottom;
	}else
	{
		return None;
	}
}


bool Object::detectObstacle(Object obj)
{	
	double xdiff = getXPosition() - obj.getXPosition(); 
	double ydiff = getYPosition() - obj.getYPosition();
	double distance = getSize() + obj.getSize();
	if (xdiff * xdiff + ydiff * ydiff <= distance * distance)
	{
		return true;
	}
	else return false;
}
