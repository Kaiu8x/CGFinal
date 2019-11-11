//
//  Robot.cpp
//  Robot
//
//

#include "Robot.hpp"
#include <functional>
#include <iostream>
#include <cmath>

Robot::Robot() {
    //just for init
    float scale[] = {1, 1, 1};
    float cl[] = {1.0f, 1.0f, 1.0f};
    float size = 1.0f;
    for (int i = 0; i < PARTS; i++) {
        parts[i] = new Block(size, scale, cl);
    }
    
    /*parts[HEAD]->model = glmReadOBJ("/Users/kaiu8x/Dropbox/ITC11/7moSem/CompGraphics/Optimus/Optimus/CGFinal/assets/robot/HEAD.obj");
    parts[NECK]->model = glmReadOBJ("/Users/kaiu8x/Dropbox/ITC11/7moSem/CompGraphics/Optimus/Optimus/CGFinal/assets/robot/NECK.obj");
    parts[CHEST]->model = glmReadOBJ("/Users/kaiu8x/Dropbox/ITC11/7moSem/CompGraphics/Optimus/Optimus/CGFinal/assets/robot/CHEST.obj");
    parts[HIPS]->model = glmReadOBJ("/Users/kaiu8x/Dropbox/ITC11/7moSem/CompGraphics/Optimus/Optimus/CGFinal/assets/robot/HIPS.obj");
    parts[WAIST]->model = glmReadOBJ("/Users/kaiu8x/Dropbox/ITC11/7moSem/CompGraphics/Optimus/Optimus/CGFinal/assets/robot/WAIST.obj");
    parts[RSHOULDER]->model = glmReadOBJ("/Users/kaiu8x/Dropbox/ITC11/7moSem/CompGraphics/Optimus/Optimus/CGFinal/assets/robot/RSHOULDER.obj");
    parts[RBICEP]->model = glmReadOBJ("/Users/kaiu8x/Dropbox/ITC11/7moSem/CompGraphics/Optimus/Optimus/CGFinal/assets/robot/RBICEP.obj");
    parts[RARM]->model = glmReadOBJ("/Users/kaiu8x/Dropbox/ITC11/7moSem/CompGraphics/Optimus/Optimus/CGFinal/assets/robot/RARM.obj");
    parts[RHAND]->model = glmReadOBJ("/Users/kaiu8x/Dropbox/ITC11/7moSem/CompGraphics/Optimus/Optimus/CGFinal/assets/robot/RHAND.obj");
    parts[RLEG]->model = glmReadOBJ("/Users/kaiu8x/Dropbox/ITC11/7moSem/CompGraphics/Optimus/Optimus/CGFinal/assets/robot/RLEG.obj");
    parts[RSHIN]->model = glmReadOBJ("/Users/kaiu8x/Dropbox/ITC11/7moSem/CompGraphics/Optimus/Optimus/CGFinal/assets/robot/RSHIN.obj");
    parts[RFOOT]->model = glmReadOBJ("/Users/kaiu8x/Dropbox/ITC11/7moSem/CompGraphics/Optimus/Optimus/CGFinal/assets/robot/RFOOT.obj");
    parts[LSHOULDER]->model = glmReadOBJ("/Users/kaiu8x/Dropbox/ITC11/7moSem/CompGraphics/Optimus/Optimus/CGFinal/assets/robot/LSHOULDER.obj");
    parts[LBICEP]->model = glmReadOBJ("/Users/kaiu8x/Dropbox/ITC11/7moSem/CompGraphics/Optimus/Optimus/CGFinal/assets/robot/LBICEP.obj");
    parts[LARM]->model = glmReadOBJ("/Users/kaiu8x/Dropbox/ITC11/7moSem/CompGraphics/Optimus/Optimus/CGFinal/assets/robot/LARM.obj");
    parts[LHAND]->model = glmReadOBJ("/Users/kaiu8x/Dropbox/ITC11/7moSem/CompGraphics/Optimus/Optimus/CGFinal/assets/robot/LHAND.obj");
    parts[LLEG]->model = glmReadOBJ("/Users/kaiu8x/Dropbox/ITC11/7moSem/CompGraphics/Optimus/Optimus/CGFinal/assets/robot/LLEG.obj");
    parts[LSHIN]->model = glmReadOBJ("/Users/kaiu8x/Dropbox/ITC11/7moSem/CompGraphics/Optimus/Optimus/CGFinal/assets/robot/LSHIN.obj");
    parts[LFOOT]->model = glmReadOBJ("/Users/kaiu8x/Dropbox/ITC11/7moSem/CompGraphics/Optimus/Optimus/CGFinal/assets/robot/LFOOT.obj");*/
    
	parts[HEAD]->model = glmReadOBJ("assets/robot/HEAD.obj");
	parts[NECK]->model = glmReadOBJ("assets/robot/NECK.obj");
	parts[CHEST]->model = glmReadOBJ("assets/robot/CHEST.obj");
	parts[HIPS]->model = glmReadOBJ("assets/robot/HIPS.obj");
	parts[WAIST]->model = glmReadOBJ("assets/robot/WAIST.obj");
	parts[RSHOULDER]->model = glmReadOBJ("assets/robot/RSHOULDER.obj");
	parts[RBICEP]->model = glmReadOBJ("assets/robot/RBICEP.obj");
	parts[RARM]->model = glmReadOBJ("assets/robot/RARM.obj");
	parts[RHAND]->model = glmReadOBJ("assets/robot/RHAND.obj");
	parts[RLEG]->model = glmReadOBJ("assets/robot/RLEG.obj");
	parts[RSHIN]->model = glmReadOBJ("assets/robot/RSHIN.obj");
	parts[RFOOT]->model = glmReadOBJ("assets/robot/RFOOT.obj");
	parts[LSHOULDER]->model = glmReadOBJ("assets/robot/LSHOULDER.obj");
	parts[LBICEP]->model = glmReadOBJ("assets/robot/LBICEP.obj");
	parts[LARM]->model = glmReadOBJ("assets/robot/LARM.obj");
	parts[LHAND]->model = glmReadOBJ("assets/robot/LHAND.obj");
	parts[LLEG]->model = glmReadOBJ("assets/robot/LLEG.obj");
	parts[LSHIN]->model = glmReadOBJ("assets/robot/LSHIN.obj");
	parts[LFOOT]->model = glmReadOBJ("assets/robot/LFOOT.obj");

    parts[HIPS]->position[0] = 0;
    parts[HIPS]->position[1] = 0;
    parts[HIPS]->position[2] = 0;
    parts[HIPS]->strech[0] = 1.7;
    parts[HIPS]->strech[1] = 0.8;
    parts[HIPS]->strech[2] = 1.1;
    parts[HIPS]->color[0] = 1;
    parts[HIPS]->color[1] = 1;
    parts[HIPS]->color[2] = 1;

    parts[HIPS]->angle[0] = 1;
    parts[HIPS]->angle[1] = 0;
    parts[HIPS]->angle[2] = 0;
    parts[HIPS]->angle[3] = 1;
    parts[HIPS]->delta = 0.1;
    parts[HIPS]->counter = -50;

    auto tmp = parts[HIPS];
    parts[HIPS]->update_func = [tmp](void) {
        tmp->counter += tmp->delta;
        tmp->translation[1] = -0.08 * sin(tmp->counter)+0.08;
    };

    parts[LLEG]->position[0] = 0.7;
    parts[LLEG]->position[1] = -1.6;
    parts[LLEG]->position[2] = 0;
    parts[LLEG]->strech[0] = 0.8;
    parts[LLEG]->strech[1] = 1.8;
    parts[LLEG]->strech[2] = 0.9;
    parts[LLEG]->color[0] = 0;
    parts[LLEG]->color[1] = 1;
    parts[LLEG]->color[2] = 0;


    parts[LLEG]->angle[0] = 1;
    parts[LLEG]->angle[1] = 0;
    parts[LLEG]->angle[2] = 0;
    parts[LLEG]->angle[3] = 1;
    parts[LLEG]->delta = 0.1;
    parts[LLEG]->counter = 0;

    tmp = parts[LLEG];
    parts[LLEG]->update_func = [tmp](void) {
        tmp->counter += tmp->delta;
        tmp->angle[3] = -15 * sin(tmp->counter);
    };


    parts[LSHIN]->position[0] = 0.85;
    parts[LSHIN]->position[1] = -3.6;
    parts[LSHIN]->position[2] = -0.1;
    parts[LSHIN]->strech[0] = 0.9;
    parts[LSHIN]->strech[1] = 2.2;
    parts[LSHIN]->strech[2] = 1.1;
    parts[LSHIN]->color[0] = 1;
    parts[LSHIN]->color[1] = 0;
    parts[LSHIN]->color[2] = 0;

    parts[LSHIN]->pivot[0] = parts[LLEG]->position[0] * 2;
    parts[LSHIN]->pivot[1] = parts[LLEG]->position[1] * 2;
    parts[LSHIN]->pivot[2] = parts[LLEG]->position[2] * 2;
    parts[LSHIN]->angle[0] = 1;
    parts[LSHIN]->angle[1] = 0;
    parts[LSHIN]->angle[2] = 0;
    parts[LSHIN]->angle[3] = 1;
    parts[LSHIN]->delta = 0.1;
    parts[LSHIN]->counter = -25;

    tmp = parts[LSHIN];
    parts[LSHIN]->update_func = [tmp](void) {
        tmp->counter += tmp->delta;
        tmp->angle[3] = -25 * sin(tmp->counter)+25/2;
    };


    parts[LFOOT]->position[0] = 0.85;
    parts[LFOOT]->position[1] = -5.1;
    parts[LFOOT]->position[2] = 0;
    parts[LFOOT]->strech[0] = 0.9;
    parts[LFOOT]->strech[1] = 0.7;
    parts[LFOOT]->strech[2] = 1.3;
    parts[LFOOT]->color[0] = 1;
    parts[LFOOT]->color[1] = 0;
    parts[LFOOT]->color[2] = 1;
    parts[LFOOT]->orientation[3] = -2.5;
    parts[LFOOT]->orientation[0] = 0;
    parts[LFOOT]->orientation[1] = 0;
    parts[LFOOT]->orientation[2] = 1;

    parts[LFOOT]->pivot[0] = parts[LSHIN]->position[0] - parts[LSHIN]->strech[0] / 2;//+parts[LFOOT]->strech[0]/2;
    parts[LFOOT]->pivot[1] = parts[LSHIN]->position[1] - parts[LSHIN]->strech[1] / 2;//+parts[LFOOT]->strech[1]/2;
    parts[LFOOT]->pivot[2] = parts[LSHIN]->position[2] - parts[LSHIN]->strech[2] / 2;//+parts[LFOOT]->strech[2]/2;
    parts[LFOOT]->angle[0] = 1;
    parts[LFOOT]->angle[1] = 0;
    parts[LFOOT]->angle[2] = 0;
    parts[LFOOT]->angle[3] = 1;
    parts[LFOOT]->delta = 0.1;
    parts[LFOOT]->counter = -50;

    tmp = parts[LFOOT];
    parts[LFOOT]->update_func = [tmp](void) {
        tmp->counter += tmp->delta;
        tmp->angle[3] = -15 * sin(tmp->counter);
    };

    parts[RLEG]->position[0] = -0.7;
    parts[RLEG]->position[1] = -1.6;
    parts[RLEG]->position[2] = 0;
    parts[RLEG]->strech[0] = 0.8;
    parts[RLEG]->strech[1] = 1.8;
    parts[RLEG]->strech[2] = 0.9;
    parts[RLEG]->color[0] = 0;
    parts[RLEG]->color[1] = 1;
    parts[RLEG]->color[2] = 0;

    parts[RLEG]->angle[0] = 1;
    parts[RLEG]->angle[1] = 0;
    parts[RLEG]->angle[2] = 0;
    parts[RLEG]->angle[3] = 1;
    parts[RLEG]->delta = 0.1;
    parts[RLEG]->counter = 0;

    tmp = parts[RLEG];
    parts[RLEG]->update_func = [tmp](void) {
        tmp->counter += tmp->delta;
        tmp->angle[3] = 15 * sin(tmp->counter);
    };

    parts[RSHIN]->position[0] = -0.7;
    parts[RSHIN]->position[1] = -3.6;
    parts[RSHIN]->position[2] = -0.1;
    parts[RSHIN]->strech[0] = 0.9;
    parts[RSHIN]->strech[1] = 2.2;
    parts[RSHIN]->strech[2] = 1.1;
    parts[RSHIN]->color[0] = 1;
    parts[RSHIN]->color[1] = 0;
    parts[RSHIN]->color[2] = 0;

    parts[RSHIN]->pivot[0] = parts[RLEG]->position[0] * 2;
    parts[RSHIN]->pivot[1] = parts[RLEG]->position[1] * 2;
    parts[RSHIN]->pivot[2] = parts[RLEG]->position[2] * 2;
    parts[RSHIN]->angle[0] = 1;
    parts[RSHIN]->angle[1] = 0;
    parts[RSHIN]->angle[2] = 0;
    parts[RSHIN]->angle[3] = 1;
    parts[RSHIN]->delta = 0.1;
    parts[RSHIN]->counter = -25;

    tmp = parts[RSHIN];
    parts[RSHIN]->update_func = [tmp](void) {
        tmp->counter += tmp->delta;
        tmp->angle[3] = 25 * sin(tmp->counter)+25/2;
    };


    parts[RFOOT]->position[0] = -0.5;
    parts[RFOOT]->position[1] = -5.1;
    parts[RFOOT]->position[2] = 0;
    parts[RFOOT]->strech[0] = 0.9;
    parts[RFOOT]->strech[1] = 0.7;
    parts[RFOOT]->strech[2] = 1.3;
    parts[RFOOT]->color[0] = 1;
    parts[RFOOT]->color[1] = 0;
    parts[RFOOT]->color[2] = 1;
    parts[RFOOT]->orientation[3] = 2.5;
    parts[RFOOT]->orientation[0] = 0;
    parts[RFOOT]->orientation[1] = 0;
    parts[RFOOT]->orientation[2] = 1;


    parts[RFOOT]->pivot[0] = parts[RSHIN]->position[0] - parts[RSHIN]->strech[0] / 2;//+parts[RFOOT]->strech[0]/2;
    parts[RFOOT]->pivot[1] = parts[RSHIN]->position[1] - parts[RSHIN]->strech[1] / 2;//+parts[RFOOT]->strech[1]/2;
    parts[RFOOT]->pivot[2] = parts[RSHIN]->position[2] - parts[RSHIN]->strech[2] / 2;//+parts[RFOOT]->strech[2]/2;
    parts[RFOOT]->angle[0] = 1;
    parts[RFOOT]->angle[1] = 0;
    parts[RFOOT]->angle[2] = 0;
    parts[RFOOT]->angle[3] = 1;
    parts[RFOOT]->delta = 0.1;
    parts[RFOOT]->counter = 50;

    tmp = parts[RFOOT];
    parts[RFOOT]->update_func = [tmp](void) {
        tmp->counter += tmp->delta;
        tmp->angle[3] = 15 * sin(tmp->counter);
    };

    parts[WAIST]->position[0] = 0;
    parts[WAIST]->position[1] = 1.1;
    parts[WAIST]->position[2] = 0;
    parts[WAIST]->strech[0] = 1.5;
    parts[WAIST]->strech[1] = 1.4;
    parts[WAIST]->strech[2] = 1;
    parts[WAIST]->color[0] = 0;
    parts[WAIST]->color[1] = 1;
    parts[WAIST]->color[2] = 0;

    parts[CHEST]->position[0] = 0;
    parts[CHEST]->position[1] = 2.1;
    parts[CHEST]->position[2] = 0;
    parts[CHEST]->strech[0] = 2.3;
    parts[CHEST]->strech[1] = 1.4;
    parts[CHEST]->strech[2] = 1.3;
    parts[CHEST]->color[0] = 1;
    parts[CHEST]->color[1] = 1;
    parts[CHEST]->color[2] = 0;

    parts[CHEST]->angle[0] = 0;
    parts[CHEST]->angle[1] = 1;
    parts[CHEST]->angle[2] = 0;
    parts[CHEST]->angle[3] = 1;
    parts[CHEST]->delta = 0.1;
    parts[CHEST]->counter = 50;

    tmp = parts[CHEST];
    parts[CHEST]->update_func = [tmp](void) {
        tmp->counter += tmp->delta;
        tmp->angle[3] = 10 * sin(tmp->counter);
    };


    parts[HEAD]->position[0] = 0;
    parts[HEAD]->position[1] = 3;
    parts[HEAD]->position[2] = 0.1;
    parts[HEAD]->strech[0] = 1.3;
    parts[HEAD]->strech[1] = 1.3;
    parts[HEAD]->strech[2] = 1.3;
    parts[HEAD]->color[0] = 0;
    parts[HEAD]->color[1] = 1;
    parts[HEAD]->color[2] = 1;

	
    parts[NECK]->position[0] = 0;
    parts[NECK]->position[1] = 2.9;
    parts[NECK]->position[2] = 0;
    parts[NECK]->strech[0] = 0.6;
    parts[NECK]->strech[1] = 0.2;
    parts[NECK]->strech[2] = 0.5;
    parts[NECK]->color[0] = 1;
    parts[NECK]->color[1] = 0;
    parts[NECK]->color[2] = 1;

    parts[RSHOULDER]->position[0] = -1.2;
    parts[RSHOULDER]->position[1] = 2.5;
    parts[RSHOULDER]->position[2] = 0;
    parts[RSHOULDER]->strech[0] = 0.9;
    parts[RSHOULDER]->strech[1] = 0.7;
    parts[RSHOULDER]->strech[2] = 0.9;
    parts[RSHOULDER]->color[0] = 1;
    parts[RSHOULDER]->color[1] = 1;
    parts[RSHOULDER]->color[2] = 1;


    parts[RSHOULDER]->pivot[0] = parts[RSHOULDER]->position[0];//+parts[RFOOT]->strech[0]/2;
    parts[RSHOULDER]->pivot[1] = parts[RSHOULDER]->position[1];//+parts[RFOOT]->strech[1]/2;
    parts[RSHOULDER]->pivot[2] = parts[RSHOULDER]->position[2];//+parts[RFOOT]->strech[2]/2;

    parts[RSHOULDER]->angle[0] = 1;
    parts[RSHOULDER]->angle[1] = 0;
    parts[RSHOULDER]->angle[2] = 0;
    parts[RSHOULDER]->angle[3] = 1;
    parts[RSHOULDER]->delta = 0.1;
    parts[RSHOULDER]->counter = 50;

    tmp = parts[RSHOULDER];
    parts[RSHOULDER]->update_func = [tmp](void) {
        tmp->counter += tmp->delta;
        tmp->angle[3] = -15 * sin(tmp->counter);
    };

    parts[RBICEP]->position[0] = -1.2;
    parts[RBICEP]->position[1] = 2.2;
    parts[RBICEP]->position[2] = 0;
    parts[RBICEP]->strech[0] = 0.6;
    parts[RBICEP]->strech[1] = 0.8;
    parts[RBICEP]->strech[2] = 0.6;
    parts[RBICEP]->color[0] = 1;
    parts[RBICEP]->color[1] = 0;
    parts[RBICEP]->color[2] = 1;



    parts[RARM]->position[0] = -1.2;
    parts[RARM]->position[1] = 0.7;
    parts[RARM]->position[2] = 0;
    parts[RARM]->strech[0] = 0.8;
    parts[RARM]->strech[1] = 1.4;
    parts[RARM]->strech[2] = 0.8;
    parts[RARM]->color[0] = 0;
    parts[RARM]->color[1] = 1;
    parts[RARM]->color[2] = 1;


    parts[RARM]->pivot[0] = parts[RBICEP]->position[0] - parts[RBICEP]->strech[0] / 2;//+parts[RFOOT]->strech[0]/2;
    parts[RARM]->pivot[1] = parts[RBICEP]->position[1] - parts[RBICEP]->strech[1] / 2;//+parts[RFOOT]->strech[1]/2;
    parts[RARM]->pivot[2] = parts[RBICEP]->position[2] - parts[RBICEP]->strech[2] / 2;//+parts[RFOOT]->strech[2]/2;
    parts[RARM]->angle[0] = 1;
    parts[RARM]->angle[1] = 0;
    parts[RARM]->angle[2] = 0;
    parts[RARM]->angle[3] = 1;
    parts[RARM]->delta = 0.1;
    parts[RARM]->counter = 50;

    tmp = parts[RARM];
    parts[RARM]->update_func = [tmp](void) {
        tmp->counter += tmp->delta;
        tmp->angle[3] = -10 * sin(tmp->counter)-15;
    };

    parts[RHAND]->position[0] = -1.2;
    parts[RHAND]->position[1] = -0.3;
    parts[RHAND]->position[2] = 0.5;
    parts[RHAND]->strech[0] = 0.6;
    parts[RHAND]->strech[1] = 0.6;
    parts[RHAND]->strech[2] = 0.6;
    parts[RHAND]->color[0] = 1;
    parts[RHAND]->color[1] = 1;
    parts[RHAND]->color[2] = 1;


    parts[LSHOULDER]->position[0] = 1.2;
    parts[LSHOULDER]->position[1] = 2.5;
    parts[LSHOULDER]->position[2] = 0;
    parts[LSHOULDER]->strech[0] = 0.9;
    parts[LSHOULDER]->strech[1] = 0.7;
    parts[LSHOULDER]->strech[2] = 0.9;
    parts[LSHOULDER]->color[0] = 1;
    parts[LSHOULDER]->color[1] = 1;
    parts[LSHOULDER]->color[2] = 1;

    parts[LSHOULDER]->pivot[0] = parts[LSHOULDER]->position[0];//+parts[RFOOT]->strech[0]/2;
    parts[LSHOULDER]->pivot[1] = parts[LSHOULDER]->position[1];//+parts[RFOOT]->strech[1]/2;
    parts[LSHOULDER]->pivot[2] = parts[LSHOULDER]->position[2];//+parts[RFOOT]->strech[2]/2;

    parts[LSHOULDER]->angle[0] = 1;
    parts[LSHOULDER]->angle[1] = 0;
    parts[LSHOULDER]->angle[2] = 0;
    parts[LSHOULDER]->angle[3] = 1;
    parts[LSHOULDER]->delta = 0.1;
    parts[LSHOULDER]->counter = 50;

    tmp = parts[LSHOULDER];
    parts[LSHOULDER]->update_func = [tmp](void) {
        tmp->counter += tmp->delta;
        tmp->angle[3] = 15 * sin(tmp->counter);
    };

    parts[LBICEP]->position[0] = 1.2;
    parts[LBICEP]->position[1] = 2.2;
    parts[LBICEP]->position[2] = 0;
    parts[LBICEP]->strech[0] = 0.6;
    parts[LBICEP]->strech[1] = 0.8;
    parts[LBICEP]->strech[2] = 0.6;
    parts[LBICEP]->color[0] = 1;
    parts[LBICEP]->color[1] = 0;
    parts[LBICEP]->color[2] = 1;

    parts[LARM]->position[0] = 1.2;
    parts[LARM]->position[1] = 0.7;
    parts[LARM]->position[2] = 0;
    parts[LARM]->strech[0] = 0.8;
    parts[LARM]->strech[1] = 1.4;
    parts[LARM]->strech[2] = 0.8;
    parts[LARM]->color[0] = 0;
    parts[LARM]->color[1] = 1;
    parts[LARM]->color[2] = 1;



    parts[LARM]->pivot[0] = parts[LBICEP]->position[0] - parts[LBICEP]->strech[0] / 2;//+parts[RFOOT]->strech[0]/2;
    parts[LARM]->pivot[1] = parts[LBICEP]->position[1] - parts[LBICEP]->strech[1] / 2;//+parts[RFOOT]->strech[1]/2;
    parts[LARM]->pivot[2] = parts[LBICEP]->position[2] - parts[LBICEP]->strech[2] / 2;//+parts[RFOOT]->strech[2]/2;
    parts[LARM]->angle[0] = 1;
    parts[LARM]->angle[1] = 0;
    parts[LARM]->angle[2] = 0;
    parts[LARM]->angle[3] = 1;
    parts[LARM]->delta = 0.1;
    parts[LARM]->counter = 50;

    tmp = parts[LARM];
    parts[LARM]->update_func = [tmp](void) {
        tmp->counter += tmp->delta;
        tmp->angle[3] = 10 * sin(tmp->counter)-15;
    };

    parts[LHAND]->position[0] = 1.2;
    parts[LHAND]->position[1] = -0.3;
    parts[LHAND]->position[2] = 0.5;
    parts[LHAND]->strech[0] = 0.6;
    parts[LHAND]->strech[1] = 0.6;
    parts[LHAND]->strech[2] = 0.6;
    parts[LHAND]->color[0] = 1;
    parts[LHAND]->color[1] = 1;
    parts[LHAND]->color[2] = 1;

	parts[NECK] -> color[0] = parts[NECK] -> color[1] = parts[NECK] -> color[2] = parts[NECK] -> color[0] = 1;
	parts[NECK] -> strech[0] = parts[NECK] -> strech[1] = parts[NECK] -> strech[2] = 0.3f;

	for (int i = 0; i < PARTS; i++)
	{
		glmUnitize(parts[i]->model);
		glmFacetNormals(parts[i]->model);
		glmDimensions(parts[i]->model, parts[i]->strech);
		parts[i]->center[0] = parts[i]->position[0] + parts[i]->strech[0] / 2.0f;
		parts[i]->center[1] = parts[i]->position[1] + parts[i]->strech[1] / 2.0f;
		parts[i]->center[2] = parts[i]->position[2] + parts[i]->strech[2] / 2.0f;
		parts[i]->radius = sqrtf(parts[i]->center[0] * parts[i]->center[0] +
		parts[i]->center[1] * parts[i]->center[1] +
		parts[i]->center[2] * parts[i]->center[2]);
	}
}

float angle = 0;

void Robot::draw() {
    parts[HIPS]->draw();
    parts[HEAD]->draw();
    parts[NECK]->draw(); 
    glPushMatrix();
    {
        parts[CHEST]->draw();
        glPushMatrix();
        {
            parts[RSHOULDER]->draw();
            parts[RBICEP]->draw();
            parts[RARM]->draw();
            parts[RHAND]->draw();
        }
        glPopMatrix();
        glPushMatrix();
        {
            parts[LSHOULDER]->draw();
            parts[LBICEP]->draw();
            parts[LARM]->draw();
            parts[LHAND]->draw();
        }
        glPopMatrix();
    }
    glPopMatrix();
    parts[WAIST]->draw();
    glPushMatrix();
    {
        glRotatef(2.5, 0, 0, 1);
        parts[LLEG]->draw();
        parts[LSHIN]->draw();
        parts[LFOOT]->draw();
    }
    glPopMatrix();

    glPushMatrix();
    {
        glRotatef(-2.5, 0, 0, 1);
        parts[RLEG]->draw();
        parts[RSHIN]->draw();
        parts[RFOOT]->draw();
    }
    glPopMatrix();
}

void Robot::update() {
    for (int i = 0; i < PARTS; i++) {
        parts[i]->update();
    }
}
