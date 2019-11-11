//
//  Robot.hpp
//  Robot
//
//
// Please don't change lines 9-31 (It helps me to grade)
#ifdef __APPLE__
// For XCode only: New C++ terminal project. Build phases->Compile with libraries: add OpenGL and GLUT
// Import this whole code into a new C++ file (main.cpp, for example). Then run.
// Reference: https://en.wikibooks.org/wiki/OpenGL_Programming/Installation/Mac
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif
#ifdef _WIN32
// For VS on Windows only: Download CG_Demo.zip. UNZIP FIRST. Double click on CG_Demo/CG_Demo.sln
// Run
#include "freeglut.h"
#endif
#ifdef __unix__
// For Linux users only: g++ CG_Demo.cpp -lglut -lGL -o CG_Demo
// ./CG_Demo
// Reference: https://www.linuxjournal.com/content/introduction-opengl-programming
#include "GL/freeglut.h"
#include "GL/gl.h"

#endif

#include "Block.hpp"

#ifndef Robot_hpp
#define Robot_hpp

#include <stdio.h>

#define PARTS 19 
const float PI_F = 3.14159265358979f;

class Robot {
public:
    Robot();

    ~Robot();       // Destruction to free memory

    void draw();        // to be called from main's display()
    void update();

    enum ROBOT_PARTS {
        HEAD, NECK, CHEST, HIPS, WAIST,
        RSHOULDER, RBICEP, RARM, RHAND,
        RLEG, RSHIN, RFOOT,
        LSHOULDER, LBICEP, LARM, LHAND,
        LLEG, LSHIN, LFOOT
    };

    Block *parts[PARTS];
    float rotations[3][PARTS];
};


#endif /* Robot_hpp */
