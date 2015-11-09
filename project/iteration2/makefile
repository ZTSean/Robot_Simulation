UNAME = $(shell uname)


CC 		= g++
CFLAGS 	= -Wall
LDFLAGS =

CXXDIR	  = ../bin/cxxtest
CXXTEST	  = $(CXXDIR)/bin/cxxtestgen
CXXFLAGS  = --error-printer --have-eh

##
##
##
# List of cpp files to be compiled
# Note, if you add any cpp files to your project, you must also add them here
##
CPPFILES += main.cpp 
CPPFILES += BaseGfxApp.cpp 
CPPFILES += Simulation.cpp
CPPFILES += Object.cpp
CPPFILES += EnvironmentClass.cpp

##
# Lists all the cpp files in /src
# Note, this means you can make from /src, /lib, or /bin
##
SOURCES=$(addprefix ../src/,  $(CPPFILES))

OBJECTS = $(addprefix ../bin/,  $(CPPFILES:.cpp=.o)) 

GLUI = glui

##
# Linking the GLUI libraries
##
LINK_LIBS += -L../lib/$(GLUI)/lib/ -lglui
INCLUDE = -I../lib/$(GLUI)/include -I../src

##
# Linking GLUT and OpenGl for Mac
##
ifeq ($(UNAME), Darwin)
	LINK_LIBS += -framework glut -framework opengl
	EXECUTABLE = ../bin/gorobot
	TESTRUNNER1 = ../bin/testrobot
	TESTRUNNER2 = ../bin/testenv
##
# Linking GLUT and OpenGl for Linux
##
else
	ifeq ($(UNAME), Linux)
		LINK_LIBS += -lglut -lGL -lGLU
		EXECUTABLE = ../bin/gorobot
		TESTRUNNER1 = ../bin/testrobot
		TESTRUNNER2 = ../bin/testenv
##
# Linking GLUT and OpenGl for Windows
# Note, you must have freeGlut installed; see the Resource page for details
##
	else 
		GLUTINCLUDEPATH = C:\Dev-Cpp\mingw32\freeglut\include\
		GLUTLIBPATH = C:\Dev-Cpp\mingw32\freeglut\lib\
		LINK_LIBS += -L$(GLUTLIBPATH) -lfreeglut -lopengl32 -Wl,--subsystem,windows
		INCLUDE += -I$(GLUTPATH)
		EXECUTABLE = gorobot.exe

	endif
endif

##



##
# Sets up the /bin folder, checks for all cpp files, and compiles the executable
##
all: setup $(SOURCES) gorobot testrobot testenv

setup:
	mkdir -p ../bin

gorobot: $(GLUI) $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) $(LINK_LIBS) -o $(EXECUTABLE)

testrobot.cpp: ObjectTests.h 
	$(CXXTEST) $(CXXFLAGS) ObjectTests.h -o testrobot.cpp 
	
testenv.cpp: EnvironmentClassTest.h
	$(CXXTEST) $(CXXFLAGS) EnvironmentClassTest.h -o testenv.cpp 

testrobot: $(GLUI) testrobot.cpp ../bin/Object.o
	$(CC) -I$(CXXDIR) $(LINK_LIBS) -o $(TESTRUNNER1) ../bin/Object.o ../src/testrobot.cpp

testenv: $(GLUI) ../bin/testenv.o ../bin/EnvironmentClass.o ../bin/Object.o
	$(CC) -I$(CXXDIR) $(LINK_LIBS) -o $(TESTRUNNER2) ../bin/EnvironmentClass.o ../bin/testenv.o ../bin/Object.o




tests: testrobot testenv
	$(TESTRUNNER1); $(TESTRUNNER2)

# This creates the object files in the /bin folder
##
../bin/%.o: ../src/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

../bin/testenv.o: testenv.cpp 
	$(CC) $(CFLAGS) $(INCLUDE) -I$(CXXDIR) -c -o ../bin/testenv.o testenv.cpp


clean:
	\rm -rf testrobot.cpp testenv.cpp $(OBJECTS) $(EXECUTABLE) $(TESTRUNNER1) $(TESTRUNNER2) ../bin/testenv.o
	 $(MAKE)  -C ../lib/$(GLUI) clean

$(GLUI):
	$(MAKE) -C ../lib/$(GLUI) all
