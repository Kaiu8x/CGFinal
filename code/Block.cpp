//
//  Block.cpp
//  Robot
//
//

#include "Block.hpp"

Block::Block(int n, float sc[3], float cl[3])
        : orientation(),
          angle(),
          pivot(),
          translation()
          {
    position[0] = position[1] = position[2] = 0;
    color[0] = cl[0];
    color[1] = cl[1];
    color[2] = cl[2];
    strech[0] = sc[0];
    strech[1] = sc[1];
    strech[2] = sc[2];
    size = n;
    update_func = [this](void) {
        return;
    };
}

Block::~Block() {

}

void Block::draw() {
    glTranslatef(translation[0], translation[1], translation[2]);
    glTranslatef(pivot[0], pivot[1], pivot[2]);
    glRotatef(angle[3], angle[0], angle[1], angle[2]);
    glTranslatef(-pivot[0], -pivot[1], -pivot[2]);
    glPushMatrix();
    {
        glTranslatef(position[0], position[1], position[2]);
        glRotatef(orientation[3], orientation[0], orientation[1], orientation[2]);
		glmDraw(model, GLM_SMOOTH | GLM_MATERIAL);
    }
    glPopMatrix();
}

void Block::update() {
    update_func();
}
