#include"head.h"

void check_mouse()
{
	mouse_msg msg={0};
	while(mousemsg())
	{
		msg=getmouse();
		if(msg.is_down())
		{
			int x=msg.x,y=msg.y;
			//为了避免出现错误读入，下面这么写更安全
			if(!get_off_work&&point_distance(x,y,1022,605)<=2500)//加人 
			{
				if(snake.number<=max_cust_single_line*max_lines&&0==new_people&&people[people_tail].appear_time+500<=clock())
				{
					people_tail++;
        			people[people_tail].appear_time=clock();
        			if(people[people_tail].is_emergency==0)
        			{
        				new_people=people_tail;
					}
					else 
					{
						emergency_number++;
					}
				}
			}
			else if(point_distance(x,y,1035,74)<=1024)//下班 
			{
				get_off_work=1;
			}
			else if(point_distance(x,y,1017,168)<=256)//1号申请休息 
			{
				rest[1]=1;
			}
			else if(point_distance(x,y,1017,216)<=256)//2号申请休息 
			{
				rest[2]=1;
			}
			else if(point_distance(x,y,1017,264)<=256)//3号申请休息 
			{
				rest[3]=1;
			}
			else if(point_distance(x,y,1017,312)<=256)//4号申请休息 
			{
				rest[4]=1;
			}
			else if(point_distance(x,y,1017,360)<=256)//5号申请休息 
			{
				rest[5]=1;
			}
			else if(point_distance(x,y,1017,408)<=256)//6号申请休息 
			{
				rest[6]=1;
			}
			else if(point_distance(x,y,1017,456)<=256)//7号申请休息 
			{
				rest[7]=1;
			}
			else if(point_distance(x,y,1017,504)<=256)//8号申请休息 
			{
				rest[8]=1;
			}
		}
	} 
    mousepos(&mouse_x,&mouse_y);
}
