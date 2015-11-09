/**
 * @file EnvironmentClass.cpp
 * @author Group Meryl_Streep
 * @date 19 March 2015
 * @brief The physicial environment.
 * 
 */

#include "EnvironmentClass.h"
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>

using namespace std;

//-------------------helper function----------------------------
double sign(double d)
{
	if (d >= 0.0)
	{
		return 1.0;
	}else
	{
	 return -1.0;
	}
}





EnvironmentClass::EnvironmentClass(){
	count = 0;
}

EnvironmentClass::EnvironmentClass(int area, int width, int height, std::vector<RobotClass> *rs, std::vector<Light> *ls){
	count = 0;
	size = area;
	boundary[0] = width;
	boundary[1] = height;
	robots = rs;
	lights = ls;
}

/**
 * Updates position of the robot
 */
 
void EnvironmentClass::update(double elaspedTime){
	double spd[(*robots).size()][2];
	int i = 0;
	double newLX, newLY, newRX, newRY, newSp_L, newSp_R, newOri;
	
	//-----------------get all deltaspeed---------------------------------------------------
	for(i = 0; i < (*robots).size(); i++){
		cout << "--------------------------robot "<<i<<"-------------------------------------" << endl;
		(*robots)[i].detectStimulation((*robots), (*lights), spd[i]);			// get delta speed 
		
		// get new speed of two wheels
		newSp_L = (*robots)[i].getLeftSpeed() + spd[i][0];
		newSp_R = (*robots)[i].getRightSpeed() + spd[i][1];
		double leftwheelX = (*robots)[i].getLeftWheelX();
		double leftwheelY = (*robots)[i].getLeftWheelY();
		double rightwheelX = (*robots)[i].getRightWheelX();
		double rightwheelY = (*robots)[i].getRightWheelY();
		double PI = atan(1)*4;
		
		double dis = (*robots)[i].getWidth();
		double ini_angle;					// define lately
		
		// print information about 
		cout << "newSp_L: " << newSp_L<<"  " << "newSp_R:" << newSp_R << endl;
		cout << "Width of robot(diameter): " << (*robots)[i].getWidth() << endl;
		cout << "Dis: " << dis << endl;
		cout << "leftwheel: " << leftwheelX << "  " << leftwheelY << "  rightwheel: " << rightwheelX << " " << rightwheelY << endl; 


		//-----------------turn left------------------------------------------------------------
			if(newSp_L <= newSp_R){								// rotation counterclockwise
				if((leftwheelY <= rightwheelY))				                // initiate ini_angle, value between 0-360			
				{
					ini_angle = acos((rightwheelX-leftwheelX)/dis); 
				}else 							
				{
					ini_angle = 2*PI - acos((rightwheelX-leftwheelX)/dis);		
				}
				
				cout << "ini_angle: " << ini_angle << endl << endl;

				double leftRadius = ((*robots)[i].getWidth()/(newSp_R-newSp_L)*newSp_L);  // always positive 
				cout << "leftradius: " << leftRadius << endl;
				
				double rightRadius = ((*robots)[i].getWidth()/(newSp_R-newSp_L)*newSp_R);
				cout << "rightradius: " << rightRadius << endl;
				
				double delta_angle = newSp_L*elaspedTime/leftRadius;
				cout << "delta_angle: " << delta_angle << endl;
				
				double new_angle = ini_angle + delta_angle;
				cout << "new_angle: " << new_angle << endl << endl;
				
				//set new wheel position
				newLX = leftRadius * cos(new_angle);
				newLY = leftRadius * sin(new_angle);
				newRX = rightRadius * cos(new_angle);
				newRY = rightRadius * sin(new_angle);
				
				cout << "#### Before translate: ####" << endl;
				cout << "newLX: " << newLX << "  newLY: " << newLY << endl;
				cout << "newRX: " << newRX << "  newRY: " << newRY << endl << endl;
			
				cout << "#### After translate: ####" << endl;
				// translate robot to the right position
				newLX += leftwheelX - leftRadius*cos(ini_angle); // minus the X position of center of rotation, leftwheelX/abs(leftwheelX) is a sign whether it is negative 
				newLY += leftwheelY - leftRadius*sin(ini_angle);
				newRX += leftwheelX - leftRadius*cos(ini_angle);
				newRY += leftwheelY - leftRadius*sin(ini_angle);
				cout << "newLX: " << newLX << "  newLY: " << newLY << "  translate: " << leftwheelX - sign(leftwheelX) * leftRadius*cos(ini_angle) << " " << leftwheelY - sign(leftwheelY) * leftRadius*sin(ini_angle) << endl;
				cout << "newRX: " << newRX << "  newRY: " << newRY << endl;
				//(*robots)[i].setOrientation(int((new_angle)/PI*180));
			}
			//----------------------------turn right----------------------------------------------
			else{													// rotation clockwise
				if((leftwheelY < rightwheelY))									// initiate ini_angle, value between 0-360
				{
					ini_angle = 2*PI - acos((rightwheelX-leftwheelX)/dis);
				}else 
				{
					ini_angle = acos((rightwheelX-leftwheelX)/dis);
				}
				
				double leftRadius=((*robots)[i].getWidth()/(newSp_L-newSp_R)*newSp_L);
				cout << "leftradius:"<<leftRadius<<endl;
				
				double rightRadius = ((*robots)[i].getWidth()/(newSp_L-newSp_R)*newSp_R);
				cout << "rightradius:" << rightRadius << endl;
				
				double delta_angle = newSp_L * elaspedTime/leftRadius;
				cout << "delta_angle:" << newSp_L * elaspedTime/leftRadius << endl;
				
				double new_angle = ini_angle + delta_angle;

				//set new wheel position
				newLX = leftRadius * cos(new_angle);
				newLY = leftRadius * sin(new_angle);
				newRX = rightRadius * cos(new_angle);
				newRY = rightRadius * sin(new_angle);
				
				// translate robot to the right position
				newLX += rightwheelX - rightRadius*cos(ini_angle);
				newLY += rightwheelY - rightRadius*sin(ini_angle);
				newRX += rightwheelX - rightRadius*cos(ini_angle);
				newRY += rightwheelY - rightRadius*sin(ini_angle);
			}else  				// go straight
			{
				int d = (*robots)[i].getOrientation();
				cout << "d: " << d << endl;
				leftRadius = elaspedTime* newSp_L;			// used for moving back
				rightRadius = elaspedTime* newSp_R;
				
				newLX = leftwheelX + elaspedTime * cos(d/180.0 * PI) * newSp_L;
				newLY = leftwheelY + elaspedTime * sin(d/180.0 * PI) * newSp_L;
				newRX = rightwheelX + elaspedTime * cos(d/180.0 * PI) * newSp_R;
				newRY = rightwheelY + elaspedTime * sin(d/180.0 * PI) * newSp_R;
			}
			// set robot attributes
			(*robots)[i].setLeftSpeed(newSp_L);
			(*robots)[i].setRightSpeed(newSp_R);
			(*robots)[i].setLeftWheelPosition(newLX,newLY);
			(*robots)[i].setRightWheelPosition(newRX,newRY);
			(*robots)[i].setPosition((newLX+newRX)/2, (newLY+newRY)/2);
			cout << endl <<"Second Time" << endl;
			cout << "leftwheel: " << leftwheelX << "  " << leftwheelY << "  " << "rightwheel: "<<rightwheelX<<" "<<rightwheelY<<endl;
			cout << "L: " << newLX << " " << newLY << "  R: " << newRX << " " << newRY << endl;
			cout << "---------------------------------------------------------------" << endl;
		//}

	}

	
}

/**
 * Returns count of robot and lights in the environment
 */
 
int EnvironmentClass::getCount(){
	return count;
}


void EnvironmentClass::registerRobotClass(RobotClass r){
	robots->push_back(r);
	count++;
}

void EnvironmentClass::registerLight(Light l){
	lights->push_back(l);
	count++;
}


