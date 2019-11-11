//
//  Block.hpp
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

#ifndef Block_hpp
#define Block_hpp

#include <stdio.h>
#include <functional>
#include "glm.h"

class Block {
public:
    Block(int size, float scale[3], float color[3]);

    ~Block();       // Destruction to free memory

    void draw();        // to be called from main's display()
    void update();

    float position[3];
    float color[3];
    float strech[3];
    float orientation[4];
    float pivot[4];
    float angle[4];
    float translation[3];
    float delta;
    float counter;
    float size;
	float radius;
	float center[3];
    std::function<void()> update_func;
	GLMmodel* model;
};

#endif /* Block_hpp */
