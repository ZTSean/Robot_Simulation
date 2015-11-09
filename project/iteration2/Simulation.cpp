/**
 * @file RobotClass.h
 * @author Group Meryl_Streep
 * @date 9 March 2015
 * @brief The simulation of robot
 * 
 */

#include "Simulation.h"
#include <math.h>
#include <time.h>

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
	env = new EnvironmentClass((glutGet(GLUT_WINDOW_WIDTH)*glutGet(GLUT_WINDOW_HEIGHT)), glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), &physicalObjects);
	oldTimeSinceStart = 0;
	
	// environment construct
	//env.EnvironmentClass((glutGet(GLUT_WINDOW_WIDTH)*glutGet(GLUT_WINDOW_HEIGHT)), glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), &physicalObjects);
	
	// initial setting : 2 robots, 6 obstacles, 2 targets
	srand(time(NULL));
	int i = 0, j = 0;
	numRobot = 2;
	numObstacle = 6; 
	numTarget = 2;
	for (i = 0; i < numRobot; i++)
	{
		float c[3] = {1.0f, 0.0f, 0.0f};
		Object object(rand() % 760 +20, rand() % 760 + 20, 20 + rand() % 40, 200, rand() % 360, Circle, Robot, c, i);
		env->registerObject(object);
		cout << "Robot "<< i << endl;
	}
	
	for (i = 0; i < numObstacle; i++)
	{
		float c[3] = {0.0f, 0.0f, 1.0f};
		Object object(rand() % 760 + 20, rand() % 760 + 20, 20 + rand() % 40, 0, rand() % 360, Circle, Obstacle, c, i);
		env->registerObject(object);
		cout << "Obstacle "<< i << endl;
	}
	
	for (i = 0; i < numTarget; i++)
	{
		float c[3] = {0.0f, 1.0f, 0.0f};
		Object object(rand() % 760 + 20, rand() % 760 + 20, 20 + rand() % 40, 40, rand() % 360, Circle, Target, c, i);
		env->registerObject(object);
		cout << "Target "<< i << endl;

	}
	
	cout << "avoid initial overlap start:"<<endl;
	// avoid initial overlap
	int num = numRobot + numTarget + numObstacle;
	cout << "the number of objects: " << num <<endl; 
	
	for (i = 0; i < num; i++){
		for ( j = i; j < num; j++){
			if( (j != i) && (physicalObjects[i].detectObstacle(physicalObjects[j]) || physicalObjects[i].detectWall(glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT))))
			{
				//cout << "overlapped!!" <<endl;
				int r = physicalObjects[i].getSize();
				physicalObjects[i].setPosition(rand() % (800-2*r) + r, rand() % (800-2*r)+r);	// if overlap reset a new position until no overlap
				j = 0;
			}
		}
	}
	for (i = 0; i < num; i++){
		
		cout << "ObjectType: " << physicalObjects[i].getObjectType();
		cout << "Position: " << physicalObjects[i].getXPosition() << "," << physicalObjects[i].getYPosition() << endl;
	}

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
	
	int i = 0, j = 0;

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
	
	//render all objects
	for (i = 0; i < env->getCount(); i++){ 
		renderObject(physicalObjects[i]);
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

/*void Simulation::initialRender(){
	srand(time(NULL));
	bool flag = true;
	while (flag){
		for 
		if ( robot.detectWall(glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT)) || robot.detectObstacle(obs1) || robot.detectObstacle(obs2) || robot.detectTarget(target)){
			int a = rand() % 800;
			int b = rand() % 800;
			cout << "robot a = " << a << endl;
			cout << "robot b = " << b << endl;
			cout << "robot " <<endl;
			robot.setPosition(a, b);
		}else if (obs2.detectWall(glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT)))
		{
			int a = rand() % 800;
			int b = rand() % 800;
			cout << "obs2 a = " << a << endl;
			cout << "obs2 b = " << b << endl;
			cout << "obs2" <<endl;
			obs2.setPosition(a, b);
		}else if (target.detectObstacle(obs1) || target.detectObstacle(obs2) || target.detectWall(glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT)))
		{
			int a = rand() % 800;
			int b = rand() % 800;
			cout << "tar a = " << a << endl;
			cout << "tar b = " << b << endl;
			cout <<"tar" <<endl;
			
			target.setPosition(a, b);
		}else if (obs1.detectWall(glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT)) || obs1.detectObstacle(obs2))
		{
			int a = rand() % 800;
			int b = rand() % 800;
			cout << "obs1 a = " << a << endl;
			cout << "obs1 b = " << b << endl;
			cout << "osb1" <<endl;
			obs1.setPosition(a, b);
		}
		else \
		{
			flag = false;
			cout << "false" <<endl;
		}
	}
}
*/

void Simulation::renderObject(Object obj){
	int i = 0;
	glPushMatrix();
	glTranslatef(obj.getXPosition(), obj.getYPosition(), 0.0f);
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
	glColor3f(obj.getColor()[0], obj.getColor()[1], obj.getColor()[2]);
	glBegin(GL_TRIANGLE_FAN);
	//glVertex2f(rand()% 800, rand()% 800);
	for (i = 0; i <= 50; i++){
		glVertex2f(
			(obj.getSize() *cos (i * 2.0 * M_PI/50)),
			(obj.getSize() *sin (i * 2.0 * M_PI/50))
		);
	}
	glEnd();
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
