/**
 * \author CSci5107 Guru
 *
 * \file  main.cpp
 * \brief Main function.
 *
 */


#include "Simulation.h"

int main(int argc, char* argv[])
{
    Simulation *app = new Simulation(argc, argv,800,800);
    app->runMainLoop();
	exit(0);
}

