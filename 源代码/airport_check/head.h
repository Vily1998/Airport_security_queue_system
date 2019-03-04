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
int frame_count;//�����ǵڼ�֡ 
int min_check;//�������С��������1�����max_check 
int max_check;//����������������min_check�����8 
int max_cust_single_line;//���������ȴ��˿���������10�����14 
int max_lines;//������ֱ������������2�����4 
int max_seq_len;//�������ȴ�����(��̨)������2�����6 
int easy_seq_len;//���ɵȴ�����,������ʲôʱ�򿪹ذ����,����2�����6 
int max_cust_check;//ÿ�����������󳤶ȣ�����2�����6 
int max_sec;//һ�ΰ������Ϣ�ʱ��,����5�����20 
int get_off_work;//�°�
int rest[9];//rest[i]Ϊ1��i�Ű��������Ϣ 
int emergency_number=0;//�Ѵ���������� 
int bad_number=0;//�������� 
int active_check;//���ŵĴ�����
int new_people=1;//Ϊ0����û���½��ˣ�����0��Ϊ�¼�����˵ı�ţ�ÿ֡���һ�����ֵ 
int queue_open=1;//��ǰ�м��е����ζ��� 
int mouse_x,mouse_y;
int map[2000]={0};//��¼��û���ظ� 
int oldstategate[9]={1,1,1,1,1,1,1,1,1};//��¼֮ǰ�����״̬ 
int oldstatepeo[9]={0};//��¼֮ǰ����ڶ���״̬  0δ��  1�� 
int oldstatesnake=0;//��¼���ζ���״̬ 0δ�� 1�� 
int important[]={4,8,14,2,4,3,4,8};//��¼���õĲ��� 
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
    int state;//�˵�״̬ 
    //0:before the snake   1:going to the snake   2:in the snake   3:going to the queue
    //4:in the queue   5:tring to change a queue   6:being checked   7:pass the gate
    //8:waiting for the police   9:following the police
    int x,y;//�������� 
    int appear_time;//����˽������ε���ʱ�� 
    int die_time;//����˴���Ļ����ʧ��ʱ�� 
    int cost_time;
    int is_bad;
    int is_emergency;
    int gate_num;//0:δѡ�� i����i������� 
    int kind;//��Ⱦʱ������
}people[MAX_PEOPLE];
int people_head=1,people_tail=1;//��ǰ���ܻᱻ��Ⱦ���˵�ͷ��β��� 

struct Snake
{
    int length;//���� 
    int is_full;
    int number;//���� 
    struct People in_line[MAX_PEOPLE]; 
    int head,tail;// the head and tail for the queue
}snake;

struct Gate
{
    int is_off;//0:�ر� 1������ 
	int state;
    //1:������ 2��������� 3����ͣ���� 4���°� 
    int ready_to_rest;//0:δ�ӵ���Ϣָ�� 1���ӵ���Ϣָ�� 
    int ready_to_off;//0:δ�ӵ��°�ָ�� 1���ӵ��°�ָ�� 
    int x,y;
    int length;//the number of people in the gate
    int member;  
    int check_end_time;//�������ʱ��
	int rest_end_time;//��Ϣ����ʱ�� 
    struct People in_line[MAX_PEOPLE];//a queue for all the people in a gate//??????????????
    int head,tail;//the head and tail for the queue
}gate[9];

struct Anime
{
    int start_time,end_time;
    int x,y;
    int kind;//0:���� 1������ 
}anime[3000];
int anime_head=1,anime_tail=0;

struct Laser
{
    int x1,x2,y1,y2;
    int start_time,end_time;
}laser[3000];
int laser_head=1,laser_tail=0;

#endif

