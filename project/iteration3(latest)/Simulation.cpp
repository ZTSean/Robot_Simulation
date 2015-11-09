/**
 * @file Simulation.cpp
 * @author Group Meryl_Streep
 * @date 8 April 2015
 * @brief The simulation of whole project.
 * 
 */

#include "Simulation.h"
#include <math.h>
#include <time.h>

//-------------------------helper functions--------------------------------------------------------
bool DetectLights_Robot (Light lig, RobotClass r1){      		//used to avoid light/robot overlap
        double xdiff = lig.getXPosition() - r1.getXPosition();
        double ydiff = lig.getYPosition() - r1.getYPosition();
        double distance = lig.getWidth()/2 + r1.getWidth()/2;
        if(xdiff*xdiff + ydiff*ydiff <= distance*distance){
           return true;
        }
        else return false;
}

bool DetectLights_Lights (Light lig, Light lig2){			//used to avoid light/light overlap
        double xdiff = lig.getXPosition() - lig2.getXPosition();
        double ydiff = lig.getYPosition() - lig2.getYPosition();
        double distance = lig.getWidth()/2 + lig.getWidth()/2;
        if(xdiff*xdiff + ydiff*ydiff <= distance*distance){
           return true;
        }
        else return false;
}

bool DetectRobot_Robot (RobotClass r1, RobotClass r2){			//used to avoid robot/robot overlap
        double xdiff = r1.getXPosition() - r2.getXPosition();
        double ydiff = r1.getYPosition() - r2.getYPosition();
        double distance = r1.getWidth()/2 + r2.getWidth()/2;
        if(xdiff*xdiff + ydiff*ydiff <= distance*distance){
           return true;
        }
        else return false;
}



Simulation::Simulation(int argc, char* argv[], int width, int height) : BaseGfxApp(argc, argv, width, height, 50, 50, GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH, true, 851, 50)
{
	setCaption("Robot Simulation");

	//creates a basic UI panel with quit button
	GLUI_Panel *toolPanel = new GLUI_Panel(m_glui, "Control Panel");
	new GLUI_Button(m_glui, "Start", UI_START, (GLUI_Update_CB)s_gluicallback);
	new GLUI_Button(m_glui, "Pause", UI_PAUSE, (GLUI_Update_CB)s_gluicallback);
	new GLUI_Button(m_glui, "Resume", UI_RESUME, (GLUI_Update_CB)s_gluicallback);
	new GLUI_Button(m_glui, "Quit", UI_QUIT, (GLUI_Update_CB)quick_exit);

	// Initialize OpenGL
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
	glEnable(GL_BLEND); 
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
	gluOrtho2D(0, m_width, 0, m_height);
	glViewport(0, 0, m_width, m_height);
	
	controlflag = true;
	// environment constructer
	//env.EnvironmentClass(area, boundary[0], boundary[1], robots, lights);
	env = new EnvironmentClass((glutGet(GLUT_WINDOW_WIDTH)*glutGet(GLUT_WINDOW_HEIGHT)), glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), &robots, &lights);
	oldTimeSinceStart = 0;
	
	count = 0;
	
	// initial setting : 10 robots, 5 lights
	srand(time(NULL));
	int i = 0, j = 0, k = 0, l = 0;
	numRobot = 10;
	numLight = 4;
	for (i = 0; i < numRobot; i++)
	{
		float c[3] = {1.0f, 0.0f, 0.0f};							// red
		//RobotClass(pos_x, , pos_y, width, length, speed, orientation, shapeType, color, ConnectionType, id)
		RobotClass robot(rand()%760+20, rand()%760+20, 20 + rand() % 10, 0.0, 0,  2*M_PI*rand()/RAND_MAX, Circle, c, ConnectionType(rand()%4), i);
		//RobotClass robot(790, 400, 20, 0.0, 0, rand() % 360, Circle, c, ConnectionType(2), i);

		env->registerRobotClass(robot);
		cout << "Robot "<< i << endl;
		cout << "X: " << robots[i].getXPosition() << " Y: " << robots[i].getYPosition() << endl;
		cout << "Ori: " << robots[i].getOrientation() << endl;
		cout << "Radius: " << robots[i].getWidth()/2.0 << endl;
		cout << "l Wheel X:" << robots[i].getLeftWheelX() << "   l Wheel Y: " << robots[i].getLeftWheelY() << endl << endl;
		cout << "r Wheel X:" << robots[i].getRightWheelX() << "   r Wheel Y: " << robots[i].getRightWheelY() << endl << endl;

	}
	
	for (i = 0; i < numLight; i++)
	{
		float c[3] = {1.0f, 0.0f, 1.0f};							// yellow
		//Light(pos_x, , pos_y, width, length, speed, orientation, shapeType, color, actionRange)
		Light light(rand() % 760 +20, rand() % 760 + 20, 20 + rand() % 20, 0.0, 0.0, 0.0, Circle, c);
		env->registerLight(light);
		cout << "Light: "<< i << endl;
	}

	
//#############################################################################################################
	cout << "---------------Avoid initial overlap start:-------------"<<endl;
	// avoid initial overlap
	int num = numRobot + numLight;
	cout << "The number of Lights and Robots: " << num <<endl; 

	//-----------------------------checks if overlap occurs robot/robot ---------------------------------------
	for(j = 0; j < robots.size(); j++){				
		for(k = 0; k < robots.size(); k++){
			if ( ((j != k) && (DetectRobot_Robot (robots[j], robots[k]))) || robots[j].detectWall(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT)) != None){
				double r = robots[j].getWidth()/2.0;
				double x = fmod(rand(),(800.0-2*r)) + r;
				double y = fmod(rand(),(800.0-2*r)) + r;
				robots[j].setNewPosition(x, y);
				k = 0;
			}
		}
	}
	
	
	//-----------------------------checks if overlap occurs light/robot ---------------------------------------
	for(j = 0; j < lights.size(); j++){				
		for(k = 0; k < lights.size(); k++){
			for( l = 0; l < robots.size(); l++){
				double r = lights[j].getWidth()/2.0;
				if ( (j != k) && DetectLights_Lights (lights[j], lights[k])){			// light overlap with other light
					lights[j].setPosition(fmod(rand(),(800.0-2*r)) + r, fmod(rand(),(800.0-2*r))+r);
					k = 0;
					l = 0;
				}else if(lights[j].detectWall(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT)) != None){	//  light overlap with wall
					lights[j].setPosition(fmod(rand(),(800.0-2*r)) + r, fmod(rand(),(800.0-2*r))+r);
					k = 0;
					l = 0;
				}else if(DetectLights_Robot (lights[j], robots[l]))			// light overlap with other light
				{
					lights[j].setPosition(fmod(rand(),(800.0-2*r)) + r, fmod(rand(),(800.0-2*r))+r);
					k = 0;
					l = 0;
				}
			}
		}
	}
	
	//env->update(0.05);
	double a[2] = {};
	robots[0].detectStimulation(robots, lights, a);
}


void Simulation::gluiControl(int n)
{
	if (n == 1 || n == 3){
	controlflag = false;
	}else if (n == 2){
		controlflag = true;
	}
}

void Simulation::display()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	
	unsigned int i = 0;

	double timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	//cout<<"start"<<timeSinceStart;
	if (oldTimeSinceStart == 0.0)
	{
		oldTimeSinceStart = timeSinceStart;
	}
	
	double deltaTime = timeSinceStart - oldTimeSinceStart;
	oldTimeSinceStart = timeSinceStart;
	
	// update all 
	if (!controlflag){
		env->update(deltaTime/1000.0);
	}
	
	//render all Robots
	for (i = 0; i < robots.size(); i++){ 
		renderRobot(robots[i]);
	}
	
	//render all Lights
	for (i = 0; i < lights.size(); i++){ 
		renderLight(lights[i]);
	}
	
	// debugging messages
	int err;
	if ((err = glGetError()) != GL_NO_ERROR) {
		cerr << "GL is in an error state" << endl;
		cerr << "(GL error code " << err << ")\n";
		assert(0);
	}

	// advance
	glutSwapBuffers();
}



Simulation::~Simulation()
{
}

void Simulation::leftMouseDown(int x, int y)
{
	// nothing here for now
}

void Simulation::leftMouseUp(int x, int y)
{
	// nohing here for now
}


void Simulation::renderRobot(RobotClass robot){
	int i = 0;
	glPushMatrix();
	if (robot.getShapeType() == Circle){
		glTranslatef(robot.getXPosition(), robot.getYPosition(), 0.0f);
		glColor3f(robot.getColor()[0], robot.getColor()[1], robot.getColor()[2]);
		glBegin(GL_TRIANGLE_FAN);
		for (i = 0; i <= 50; i++){
			glVertex2f(
				(robot.getWidth()/2.0 *cos (i * 2.0 * M_PI/50)),
				(robot.getWidth()/2.0 *sin (i * 2.0 * M_PI/50))
			);
		}
		glEnd();
	}
	glPopMatrix();

	
}

void Simulation::renderLight(Light light){
	int i = 0;
	glPushMatrix();
	if (light.getShapeType() == Circle){
		glTranslatef(light.getXPosition(), light.getYPosition(), 0.0f);
		glColor3f(light.getColor()[0], light.getColor()[1], light.getColor()[2]);
		glBegin(GL_TRIANGLE_FAN);
		for (i = 0; i <= 50; i++){
			glVertex2f(
				(light.getWidth()/2.0 *cos (i * 2.0 * M_PI/50)),
				(light.getWidth()/2.0 *sin (i * 2.0 * M_PI/50))
			);
		}
		glEnd();
	
	}
	glPopMatrix();

}


/*
void Simulation::start(UIControlType n){
	setControlid(n);
}
void Simulation::resume(UIControlType n){
	setControlid(n);
}

void Simulation::pause(UIControlType n){
	setControlid(n);
}

void Simulation::setControlid(UIControlType n){

}
*/


/*
if (obj.getObjectType() == Robot)
	{
		glColor3f(1.0f, 1.0f, 1.0f); // line will be white
		glBegin(GL_LINES);
		// draw a red line to indicate direction.
		// The line is “radius” length.
		// It starts halfway beween the center and circles’ edge.
		double degree = obj.getOrientation()*3.1415926/180;
		glVertex2f( 0.5*obj.getSize()*cos(degree) ,0.5*obj.getSize()*sin(degree) );
		glVertex2f( 1.5*obj.getSize()*cos(degree) , 1.5*obj.getSize()*sin(degree));
		glEnd();
	} 
*/
