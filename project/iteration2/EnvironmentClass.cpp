/**
 * @file RobotClass.h
 * @author Group Meryl_Streep
 * @date 9 March 2015
 * @brief The physicial environment.
 * 
 */

#include "EnvironmentClass.h"
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>

using namespace std;

EnvironmentClass::EnvironmentClass(){
	count = 0;
	TimesCount = 0;

}

//EnvironmentClass::EnvironmentClass(int area, int width, int height, vector<RobotClass> *r, vector<Obstacle> *obs, vector<Target> *t){
EnvironmentClass::EnvironmentClass(int area, int width, int height, std::vector<Object> *objs){
	count = 0;
	TimesCount = 0;
	size = area;
	boundary[0] = width;
	boundary[1] = height;
	objects = objs;
}

void EnvironmentClass::update(double elaspedTime){
	int i = 0;
	for (i = 0; i < count; i++){
		if ((*objects)[i].getObjectType() == Robot || (*objects)[i].getObjectType() == Target)
		{
			
			Navigate moveVector = (*objects)[i].move(elaspedTime);
			double PI = atan(1)*4;
			double newDegree = moveVector.deltaOri;
			(*objects)[i].setOrientation(newDegree);
			//cout << "deltaDis: " << moveVector.deltaDistance <<endl;
			//cout << "deltaX: " << moveVector.deltaDistance * cos(newDegree) <<endl;
			//cout << "deltaY: " << moveVector.deltaDistance * sin(newDegree) << endl;
			double newX = (*objects)[i].getXPosition() + moveVector.deltaDistance * cos(newDegree*PI/180);
			double newY = (*objects)[i].getYPosition() + moveVector.deltaDistance * sin(newDegree*PI/180);
			(*objects)[i].setPosition(newX, newY);
			
			
			//cout << "touchsensorReading: " << touchSensorReading((*objects)[i]) <<endl;
			//-----------------------------------------detect collision-------------------------------------
			if (touchSensorReading((*objects)[i]) == 3)
			{
				if ((*objects)[i].getObjectType() == Robot){
					
					int k = rand() % 1000;
					int m = rand() % 1000;
					int n = rand() % 1000;
					float c[3] = {k/1000.0f, m/1000.0f, n/1000.0f}; 
					(*objects)[i].setColor(c);
				}
				// ------------------------------------find collision wall--------------------------------
				if((*objects)[i].detectWall(boundary[0], boundary[1]) == Top){
					if ((*objects)[i].getOrientation() > 90){										// collision with top wall
						(*objects)[i].setOrientation((*objects)[i].getOrientation() + 90);
					}else{
						(*objects)[i].setOrientation(((*objects)[i].getOrientation() + 270));
					}
				}else if((*objects)[i].detectWall(boundary[0], boundary[1]) == Bottom){
					if ((*objects)[i].getOrientation() > 270){									// collision with bottom wall
						(*objects)[i].setOrientation((double)(((int)((*objects)[i].getOrientation() + 90))%360));
					}else{
						(*objects)[i].setOrientation(((*objects)[i].getOrientation() - 90));
					}
				}else if((*objects)[i].detectWall(boundary[0], boundary[1]) == Left){
					if ((*objects)[i].getOrientation() > 180){									// collision with left wall 
						(*objects)[i].setOrientation((*objects)[i].getOrientation() + 90);
					}else{
						(*objects)[i].setOrientation(((*objects)[i].getOrientation() - 90));
					}
				}else if((*objects)[i].detectWall(boundary[0], boundary[1]) == Right){
					if ((*objects)[i].getOrientation() < 90){										// collision with right wall
						(*objects)[i].setOrientation((*objects)[i].getOrientation() + 90);
					}else{
						
						(*objects)[i].setOrientation(((*objects)[i].getOrientation() - 90));
						
					}
				}
				
				
				double newX2 = (*objects)[i].getXPosition() - 2* moveVector.deltaDistance * cos(newDegree*PI/180);
				double newY2 = (*objects)[i].getYPosition() - 2* moveVector.deltaDistance * sin(newDegree*PI/180);
				(*objects)[i].setPosition(newX2, newY2);
				
				
			}else if(touchSensorReading((*objects)[i]) == 2)
			{
				// ------------------------------collision with other objects--------------------------------
				int j = 0;
				if ((*objects)[i].getObjectType() == Robot){
					int k = rand() % 1000;
					int m = rand() % 1000;
					int n = rand() % 1000;
					float c[3] = {k/1000.0f, m/1000.0f, n/1000.0f}; 
					(*objects)[i].setColor(c);
				}
				for (j = 0; j < count; j++ ){
					if (!((*objects)[i].getObjectType() == (*objects)[j].getObjectType() && (*objects)[i].getID() == (*objects)[j].getID()))
					{
						if((*objects)[i].detectObstacle((*objects)[j])){
							int d = (*objects)[i].getOrientation();
							int x0 = (*objects)[i].getXPosition();
							int x1 = (*objects)[j].getXPosition();
							int y0 = (*objects)[i].getYPosition();
							int y1 = (*objects)[j].getYPosition();
							if ( (d >= 0.0 && d < 90.0) || (d >270.0 && d < 360.0)  )							// orientation is vertical
							{	
								double k = tan(d);
								if ( (k * (x1 - x0) + y0 - y1) > 0 ){							// the center of obstacle is below the line draw by robot orientation, turn anticlockwise
									double ori = (*objects)[i].getOrientation() + 90;
									cout << "The value of the Orientatioin +90 1:"<< ori<< endl;
									(*objects)[i].setOrientation((double)((int)(((*objects)[i].getOrientation()) + 90)%360));
								}else if ((k * (x1 - x0) + y0 - y1) < 0) {						// the center of obstacle is above the line draw by robot orientation, turn clockwise
									double ori = (*objects)[i].getOrientation() - 90;
									cout << "The value of the Orientatioin - 90 1: "<< ori<< endl;
									(*objects)[i].setOrientation((double)((int)(((*objects)[i].getOrientation()) + 270)%360));
								}else{															// turn back, 
									double ori = (*objects)[i].getOrientation() - 180;
									cout << "The value of the Orientatioin -180 1:"<< ori<< endl;
									(*objects)[i].setOrientation((double)((int)(((*objects)[i].getOrientation()) + 180)%360));
								}
							}else if (d > 90.0 && d < 270.0){
								double k = tan(d);
								if ( (k * (x1 - x0) + y0 - y1) > 0 ){							// the center of obstacle is below the line draw by robot orientation, turn anticlockwise
									double ori = (*objects)[i].getOrientation() - 90;
									cout << "The value of the Orientatioin - 90 2:"<< ori<< endl;
									(*objects)[i].setOrientation((double)((int)(((*objects)[i].getOrientation()) + 270)%360));
								}else if ((k * (x1 - x0) + y0 - y1) < 0) {						// the center of obstacle is above the line draw by robot orientation, turn clockwise
									double ori = (*objects)[i].getOrientation() + 90;
									cout << "The value of the Orientatioin +90 2:"<< ori<< endl;
									(*objects)[i].setOrientation((double)((int)(((*objects)[i].getOrientation()) +90)%360));
								}else{															// turn back, 
									double ori = (*objects)[i].getOrientation() - 180;
									cout << "The value of the Orientatioin 180 2:"<< ori<< endl;
									(*objects)[i].setOrientation((double)((int)(((*objects)[i].getOrientation()) + 180)%360));
								}
							}else if (d == 270.0){
								if (x0 < x1){
									(*objects)[i].setOrientation((double)((int)(((*objects)[i].getOrientation()) + 270)%360));
								}else if( x0 > x1){
									(*objects)[i].setOrientation((double)((int)(((*objects)[i].getOrientation()) + 90)%360));
								}else{
									(*objects)[i].setOrientation((double)((int)(((*objects)[i].getOrientation()) + 180)%360));
								}
							}else{
								if (x0 < x1){
									(*objects)[i].setOrientation((double)((int)(((*objects)[i].getOrientation()) + 90)%360));
								}else if( x0 > x1){
									(*objects)[i].setOrientation((double)((int)(((*objects)[i].getOrientation()) + 270)%360));
								}else{
									(*objects)[i].setOrientation((double)((int)(((*objects)[i].getOrientation()) + 180)%360));
								}
							}
						}
					}
				}
			
				double newX2 = (*objects)[i].getXPosition() - 2* moveVector.deltaDistance * cos(newDegree*PI/180);
				double newY2 = (*objects)[i].getYPosition() - 2* moveVector.deltaDistance * sin(newDegree*PI/180);
				(*objects)[i].setPosition(newX2, newY2);
			
			}else if(touchSensorReading((*objects)[i]) == 1)
			{
				// ------------------------------------find target--------------------------------
				int k = 0;
				for (k = 0; k < count; k++)
				{
					if ((*objects)[i].getObjectType() != Target&&(*objects)[k].getObjectType() == Target && (*objects)[i].getID() == (*objects)[k].getID() && (*objects)[i].detectObstacle((*objects)[k]))
					{
						if (i > k){
							(*objects).erase((*objects).begin()+i);
							(*objects).erase((*objects).begin()+k);
						}else{
							(*objects).erase((*objects).begin()+k);
							(*objects).erase((*objects).begin()+i);
						}
						count -= 2;
						break;
					}
				}
			}else{
				// --------------------------------no collision, reset orientation to target---------------------------
			}
		}
	}
	
	if (TimesCount == 20000){
		int i = 0;
		for (i = 0; i < count; i++){
			if ((*objects)[i].getObjectType() == Robot){
				Navigate resetOri= homingSensorReading((*objects)[i]);
				(*objects)[i].setOrientation(resetOri.deltaOri);
			}
		}
		TimesCount = 0;
	}
	//cout << "TimesCount:" << TimesCount << endl;
	TimesCount++;
	
}

/*
int Environment::registerObject(Vector<RobotClass> *r, Vector<Target> *t, Vector<Obstacle> *obs){
	obstacles = obs;
	targets = t;
	robots = r;
}
*/

int EnvironmentClass::getCount(){
	return count;
}


void EnvironmentClass::registerObject(Object obj){
	objects->push_back(obj);
	count++;
}

int EnvironmentClass::touchSensorReading(Object obj){
	int i = 0;
	int status = 0;
	if (obj.detectWall(boundary[0], boundary[1]) != None)
	{
		status = 3;
	}else{
		for (i = 0; i < count; i++){
			if ((*objects)[i].getObjectType() == Target && obj.getID() == (*objects)[i].getID() && (*objects)[i].detectObstacle(obj)){
				// find target
				status = 1;
			}else if((*objects)[i].getObjectType() == Robot && obj.getID() == (*objects)[i].getID() )
			{
				//find self, do nothing
			}else{
				// find other objects
				if(obj.detectObstacle((*objects)[i])) {
					status = 2;
					break; // I was writing the test of Object However Robot implement couple of methods of it and we already have test cases for those methods those getters a
				}
			}
		}
	}
	return status;
}


Navigate EnvironmentClass::homingSensorReading(Object obj){
	// sends back distnace and direction that robot should take
	int i = 0;
	Navigate aim;
	for (i = 0; i < count; i++)
	{
		if ((*objects)[i].getID() == obj.getID() && (*objects)[i].getObjectType() == Target)
		{
			int xDist=(*objects)[i].getXPosition() - obj.getXPosition();
			int yDist=(*objects)[i].getYPosition() - obj.getYPosition();
			if (xDist != 0){
					aim.deltaDistance = sqrt(pow(xDist,2)+pow(yDist,2));
				if (yDist > 0){
					aim.deltaOri = int(acos(xDist/aim.deltaDistance)*180/(atan(1)*4));
				}else{
					aim.deltaOri = 360 - (int(acos(xDist/aim.deltaDistance)*180/(atan(1)*4)));
				}
			}else{
				if (yDist > 0){					// target is above robot
					aim.deltaOri = 90;
				}else {
					aim.deltaOri = 270;			// target is under robot
				}
			}
			break;
		}
	}
	return aim;
}


