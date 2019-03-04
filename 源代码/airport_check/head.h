#ifndef _MAIN_H_
#define _MAIN_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<graphics.h>
#include<math.h>
#include<windows.h> 
#define MAX_PEOPLE (3000)   
#define MAX_GATE (8)   
int frame_count;//现在是第几帧 
int min_check;//安检口最小数，最少1，最多max_check 
int max_check;//安检口最大数，最少min_check，最多8 
int max_cust_single_line;//单队列最大等待乘客数，最少10，最大14 
int max_lines;//缓冲区直队数量，最少2，最大4 
int max_seq_len;//最大允许等待长度(柜台)，最少2，最大6 
int easy_seq_len;//轻松等待长度,决定了什么时候开关安检口,最少2，最大6 
int max_cust_check;//每条安检队伍最大长度，最少2，最大6 
int max_sec;//一次安检或休息最长时长,最少5，最多20 
int get_off_work;//下班
int rest[9];//rest[i]为1：i号安检口正休息 
int emergency_number=0;//已处理紧急人数 
int bad_number=0;//坏人人数 
int active_check;//开着的窗口数
int new_people=1;//为0代表没有新进人，大于0则为新加入的人的编号，每帧检查一遍这个值 
int queue_open=1;//当前有几行的蛇形队列 
int mouse_x,mouse_y;
int map[2000]={0};//记录有没有重复 
int oldstategate[9]={1,1,1,1,1,1,1,1,1};//记录之前安检口状态 
int oldstatepeo[9]={0};//记录之前安检口队列状态  0未满  1满 
int oldstatesnake=0;//记录蛇形队列状态 0未满 1满 
int important[]={4,8,14,2,4,3,4,8};//记录配置的参数 
int people_clear_time=2147483647;
PIMAGE peoples;
PIMAGE badman;
PIMAGE vip;
PIMAGE img[170];
PIMAGE gate_open,gate_close;
PIMAGE mouse;
PIMAGE background;
PIMAGE green_button,red_button;
PIMAGE ball_open,ball_close;
PIMAGE ball_dark;


struct People
{
	int id;
    int state;//人的状态 
    //0:before the snake   1:going to the snake   2:in the snake   3:going to the queue
    //4:in the queue   5:tring to change a queue   6:being checked   7:pass the gate
    //8:waiting for the police   9:following the police
    int x,y;//横纵坐标 
    int appear_time;//这个人进入蛇形道的时间 
    int die_time;//这个人从屏幕上消失的时间 
    int cost_time;
    int is_bad;
    int is_emergency;
    int gate_num;//0:未选择 i：第i个安检口 
    int kind;//渲染时的种类
}people[MAX_PEOPLE];
int people_head=1,people_tail=1;//当前可能会被渲染的人的头和尾编号 

struct Snake
{
    int length;//长度 
    int is_full;
    int number;//人数 
    struct People in_line[MAX_PEOPLE]; 
    int head,tail;// the head and tail for the queue
}snake;

struct Gate
{
    int is_off;//0:关闭 1：开启 
	int state;
    //1:办理中 2：办理结束 3：暂停服务 4：下班 
    int ready_to_rest;//0:未接到休息指令 1：接到休息指令 
    int ready_to_off;//0:未接到下班指令 1：接到下班指令 
    int x,y;
    int length;//the number of people in the gate
    int member;  
    int check_end_time;//安检结束时间
	int rest_end_time;//休息结束时间 
    struct People in_line[MAX_PEOPLE];//a queue for all the people in a gate//??????????????
    int head,tail;//the head and tail for the queue
}gate[9];

struct Anime
{
    int start_time,end_time;
    int x,y;
    int kind;//0:到达 1：出发 
}anime[3000];
int anime_head=1,anime_tail=0;

struct Laser
{
    int x1,x2,y1,y2;
    int start_time,end_time;
}laser[3000];
int laser_head=1,laser_tail=0;

#endif

