/**
 * @file EnvironmentClass.cpp
 * @author Group Meryl_Streep
 * @date 10 April 2015
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
	if (elaspedTime > 0.05)
	{
		elaspedTime = 0.02;
	}
	double spd[(*robots).size()][2];
	unsigned int i = 0;
	double newLX, newLY, newRX, newRY, newSp_L, newSp_R;
	
	//-----------------get all deltaspeed---------------------------------------------------
	for(i = 0; i < (*robots).size(); i++){
		cout << "--------------------------Robot "<<i<<"-------------------------------------" << endl;
		(*robots)[i].detectStimulation((*robots), (*lights), spd[i]);			// get delta speed 
		
		// get new speed of two wheels
		newSp_L = (*robots)[i].getLeftSpeed() + spd[i][0];
		newSp_R = (*robots)[i].getRightSpeed() + spd[i][1];
		double leftwheelX = (*robots)[i].getLeftWheelX();
		double leftwheelY = (*robots)[i].getLeftWheelY();
		double rightwheelX = (*robots)[i].getRightWheelX();
		double rightwheelY = (*robots)[i].getRightWheelY();
		double leftRadius = 0.0, rightRadius = 0.0;
		double d = (*robots)[i].getOrientation();
		
		double dis = (*robots)[i].getWidth();
		double ini_angle;					// define lately
		
		/*
		// print information about 
		cout << endl << endl <<"[newSp_L]: " << newSp_L<<"  " << "[newSp_R]:" << newSp_R << endl;
		cout << "[connectionType]: " << (*robots)[i].getConnectionType() << endl;
		cout << "[Width of robot(diameter)]: " << (*robots)[i].getWidth() << endl;
		cout << "[Ori]: " << d << endl;
		cout << "[leftwheel]: " << leftwheelX << "  " << leftwheelY << "  [rightwheel]: " << rightwheelX << " " << rightwheelY << endl; 
		*/

		//-----------------turn left------------------------------------------------------------
			if(newSp_L < newSp_R){								// rotation counterclockwise
				if((leftwheelY <= rightwheelY))				    // initiate ini_angle, value between 0-360			
				{
					ini_angle = acos((rightwheelX-leftwheelX)/dis); 
				}else 							
				{
					ini_angle = 2*M_PI - acos((rightwheelX-leftwheelX)/dis);		
				}
				
				//cout << "[ini_angle]: " << ini_angle << endl << endl;

				leftRadius = ((*robots)[i].getWidth()/(newSp_R-newSp_L)*newSp_L);  // always positive 
				//cout << "leftradius: " << leftRadius << endl;
				
				rightRadius = ((*robots)[i].getWidth()/(newSp_R-newSp_L)*newSp_R);
				//cout << "rightradius: " << rightRadius << endl;
				
				double delta_angle = newSp_L*elaspedTime/leftRadius;
				//cout << "delta_angle: " << delta_angle << endl;
				
				double new_angle = ini_angle + delta_angle;
				//cout << "new_angle: " << new_angle << endl << "======================" << endl;
				
				//set new wheel position
				newLX = leftRadius * cos(new_angle);
				newLY = leftRadius * sin(new_angle);
				newRX = rightRadius * cos(new_angle);
				newRY = rightRadius * sin(new_angle);
				/*
				cout << "#### Before translate: ####" << endl;
				cout << "newLX: " << newLX << "  newLY: " << newLY << endl;
				cout << "newRX: " << newRX << "  newRY: " << newRY << endl << endl;
			
				cout << "#### After translate: ####" << endl;*/
				// translate robot to the right position
				newLX += leftwheelX - leftRadius*cos(ini_angle); // minus the X position of center of rotation, leftwheelX/abs(leftwheelX) is a sign whether it is negative 
				newLY += leftwheelY - leftRadius*sin(ini_angle);
				newRX += leftwheelX - leftRadius*cos(ini_angle);
				newRY += leftwheelY - leftRadius*sin(ini_angle);
				//cout << "newLX: " << newLX << "  newLY: " << newLY << "  translate: " << leftwheelX - leftRadius*cos(ini_angle) << " " << leftwheelY - leftRadius*sin(ini_angle) << endl;
				//cout << "newRX: " << newRX << "  newRY: " << newRY << endl;
				
				// set new orientation for the robot
				//cout << "[NewOri]: " << delta_angle + d << endl;
				(*robots)[i].setOrientation((*robots)[i].regular_Ori(delta_angle + d));
			}
			//----------------------------turn right----------------------------------------------
			else if(newSp_L > newSp_R){											// rotation clockwise
				if((leftwheelY < rightwheelY))									// initiate ini_angle, value between 0-360
				{
					ini_angle = 2*M_PI - acos((leftwheelX-rightwheelX)/dis);
				}else 
				{
					ini_angle = acos((leftwheelX-rightwheelX)/dis);
				}
				
				//cout << "ini_angle: " << ini_angle << endl << endl;
				
				leftRadius=((*robots)[i].getWidth()/(newSp_L-newSp_R)*newSp_L);
				//cout << "leftradius:"<<leftRadius<<endl;
				
				rightRadius = ((*robots)[i].getWidth()/(newSp_L-newSp_R)*newSp_R);
				//cout << "rightradius:" << rightRadius << endl;
				
				double delta_angle = newSp_R * elaspedTime/rightRadius;
				//cout << "delta_angle:" << newSp_R * elaspedTime/rightRadius << endl;
				
				double new_angle = ini_angle - delta_angle;
				//cout << "new_angle: " << new_angle << endl << endl;

				//set new wheel position
				newLX = leftRadius * cos(new_angle);
				newLY = leftRadius * sin(new_angle);
				newRX = rightRadius * cos(new_angle);
				newRY = rightRadius * sin(new_angle);
				
				//cout << "#### Before translate: ####" << endl;
				//cout << "newLX: " << newLX << "  newLY: " << newLY << endl;
				//cout << "newRX: " << newRX << "  newRY: " << newRY << endl << endl;
			
				//cout << "#### After translate: ####" << endl;
				// translate robot to the right position
				newLX += rightwheelX - rightRadius*cos(ini_angle);
				newLY += rightwheelY - rightRadius*sin(ini_angle);
				newRX += rightwheelX - rightRadius*cos(ini_angle);
				newRY += rightwheelY - rightRadius*sin(ini_angle);
				//cout << "newLX: " << newLX << "  newLY: " << newLY << "  translate: " << rightwheelX - rightRadius*cos(ini_angle) << " " << rightwheelY - rightRadius*sin(ini_angle) << endl;
				//cout << "newRX: " << newRX << "  newRY: " << newRY << endl;
				
				// set new orientation for the robot
				//cout << "[NewOri]: " << d - delta_angle << endl;
				(*robots)[i].setOrientation((*robots)[i].regular_Ori(d - delta_angle));
			}else  				// go straight
			{
				//cout << "d: " << d << endl;
				leftRadius = elaspedTime* newSp_L;			// used for moving back
				rightRadius = elaspedTime* newSp_R;
				
				newLX = leftwheelX + elaspedTime * cos(d) * newSp_L;
				newLY = leftwheelY + elaspedTime * sin(d) * newSp_L;
				newRX = rightwheelX + elaspedTime * cos(d) * newSp_R;
				newRY = rightwheelY + elaspedTime * sin(d) * newSp_R;
			}
			// set robot attributes
			//(*robots)[i].setLeftWheelPosition(newLX,newLY);
			//(*robots)[i].setRightWheelPosition(newRX,newRY);
			(*robots)[i].setNewPosition((newLX+newRX)/2, (newLY+newRY)/2);
			
			//==========================================output information===============================================================
			//cout << endl <<"Second Time" << endl;
			//cout << "Ori: " << (*robots)[i].getOrientation() << endl;
			//cout << "[before] leftwheel: " << leftwheelX << "  " << leftwheelY << "  " << "rightwheel: "<<rightwheelX<<" "<<rightwheelY<<endl;
			//cout << "[after]  leftwheel: " << newLX << " " << newLY << "  rightwheel: " << newRX << " " << newRY << endl << endl;
			
			/*
			int j = 0;
			for (j = 0; j < (*lights).size(); j++)
			{
				cout << "[Light radius]: " << (*lights)[i].getWidth()/2.0;
				cout << "[Light Action Range]: " << (*lights)[i].getActionRange() << endl;
			}*/
			//==============================================================================================================================
			
			if((*robots)[i].detectWall(boundary[0], boundary[1]) == Top ){
				double ori = (*robots)[i].getOrientation();
				double movebackX = 1/2 * (leftRadius*cos((*robots)[i].getOrientation()) + rightRadius*cos((*robots)[i].getOrientation()));
				double movebackY = 1/2 * (leftRadius*sin((*robots)[i].getOrientation()) + rightRadius*sin((*robots)[i].getOrientation()));
				(*robots)[i].setNewPosition((*robots)[i].getXPosition(), (*robots)[i].getYPosition()- 0.5);
				cout << "[movebackX]: " << movebackX << endl;
				cout << "[movebackY]: " << movebackY << endl;
				
				if (ori != M_PI/2.0 && ori != 1.5*M_PI){				// collision with top wall
					(*robots)[i].setOrientation(2*M_PI - ori);
				}else{
					(*robots)[i].setOrientation(ori + M_PI);
				}
				(*robots)[i].setNewPosition((*robots)[i].getXPosition(), (*robots)[i].getYPosition());
				
			}else if((*robots)[i].detectWall(boundary[0], boundary[1]) == Bottom ){
				double ori = (*robots)[i].getOrientation();
				double movebackX = 1/2 * (leftRadius*cos((*robots)[i].getOrientation()) + rightRadius*cos((*robots)[i].getOrientation()));
				double movebackY = 1/2 * (leftRadius*sin((*robots)[i].getOrientation()) + rightRadius*sin((*robots)[i].getOrientation()));
				(*robots)[i].setNewPosition((*robots)[i].getXPosition(), (*robots)[i].getYPosition() + 0.5);
				cout << "[movebackX]: " << movebackX << endl;
				cout << "[movebackY]: " << movebackY << endl;
				
				if (ori != M_PI/2.0 && ori != 1.5*M_PI){				// collision with bottom wall
					(*robots)[i].setOrientation(2*M_PI - ori);
				}else{
					(*robots)[i].setOrientation(ori + M_PI);
				}
				(*robots)[i].setNewPosition((*robots)[i].getXPosition(), (*robots)[i].getYPosition());
			}else if((*robots)[i].detectWall(boundary[0], boundary[1]) == Right){
				double ori = (*robots)[i].getOrientation();
				double movebackX = 1/2 * (leftRadius*cos((*robots)[i].getOrientation()) + rightRadius*cos((*robots)[i].getOrientation()));
				double movebackY = 1/2 * (leftRadius*sin((*robots)[i].getOrientation()) + rightRadius*sin((*robots)[i].getOrientation()));
				(*robots)[i].setNewPosition((*robots)[i].getXPosition() - 0.5, (*robots)[i].getYPosition());

				//go back for a little
				
				if (ori != M_PI && ori != 0.0){				// collision with right wall 
					(*robots)[i].setOrientation((*robots)[i].regular_Ori(3*M_PI - ori));
				}else{
					(*robots)[i].setOrientation((*robots)[i].regular_Ori(ori + M_PI));
				}
				(*robots)[i].setNewPosition((*robots)[i].getXPosition(), (*robots)[i].getYPosition());
			}else if((*robots)[i].detectWall(boundary[0], boundary[1]) == Left){
				double ori = (*robots)[i].getOrientation();
				double movebackX = 1/2 * (leftRadius*cos((*robots)[i].getOrientation()) + rightRadius*cos((*robots)[i].getOrientation()));
				double movebackY = 1/2 * (leftRadius*sin((*robots)[i].getOrientation()) + rightRadius*sin((*robots)[i].getOrientation()));
				(*robots)[i].setNewPosition((*robots)[i].getXPosition() + 0.5, (*robots)[i].getYPosition());

				//go back for a little
				
				if (ori != M_PI && ori != 0.0){				// collision with left wall 
					(*robots)[i].setOrientation((*robots)[i].regular_Ori(3*M_PI - ori));
				}else{
					(*robots)[i].setOrientation((*robots)[i].regular_Ori(ori + M_PI));
				}
				(*robots)[i].setNewPosition((*robots)[i].getXPosition(), (*robots)[i].getYPosition());
			}
			//cout << "---------------------------------------------------------------" << endl;

			
	}

	//cout << "~~~~~~deltaTime: " << elaspedTime << "~~~~~~~~" << endl;
}
 
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


