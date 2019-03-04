#ifndef _LINK_H_
#define _LINK_H_

#include"configure.cpp"
#include"start.cpp"
#include"mathematics.cpp"
#include"init.cpp"
#include"gateaction.cpp"
#include"render.cpp"
#include"snakeaction.cpp"
#include"mouse.cpp"
#include"output.cpp"


void setblank(int x1,int y1,int x2,int y2);
void home(void);
void conpage(void);
int mainoption(void);
int conoption(void);
void input(void);
void setconfiguration(void);
void getconfiguration(void);
void configure(void);
void init(void);
void snake_action(void);
void put_people(void);
int choose_gate(void);
void Dynamic_opening_off(void);
void check_rest(int n);
void check_open(void);
void off_duty(void);
void gate_action(void);
int auto_exit(void);
int ran(int lowbound,int upbound);
int normal_distribution(void);
int point_distance(int pos_x1,int pos_y1,int pos_x2,int pos_y2);
int nextx(int x,int y);
int nexty(int x,int y);
void check_mouse(void);
void get_resource(void);
void add_anime(int x1,int y1,int x2,int y2);
void render_action(void);
void outputpart1(void);
void outputpart2(void);
void output(void);

#endif
