#include"head.h"

void snake_action() //��� ��һ���˳��� ��ά�� 
{
    clock_t time;
	snake.number=snake.tail-snake.head;
	
	if(snake.number>=max_cust_single_line*max_lines)printf("��������\n");
	else if(new_people!=0&&snake.number<max_cust_single_line*max_lines&&get_off_work==0) //���˼���  
	{
		snake.in_line[snake.tail]=people[new_people];
		//printf("**%d\n",people[new_people].id);
		//printf("**%d\n",snake.in_line[snake.tail].id);
		//printf("**%d\n",snake.in_line[snake.head].id);
		printf("%d���뻺����\n", new_people);
		time=clock();
		people[new_people].appear_time=time;
		snake.tail++;
		snake.number++;
		if(queue_open*max_cust_single_line<=snake.number+1)queue_open++;
		if(queue_open>max_lines)queue_open=max_lines;
		new_people=0;
	}
	
	if(snake.head==snake.tail){}// printf("������Ϊ��\n");
	else
	{
		int j=choose_gate();
		printf("choose gate: %d\n",choose_gate());
		
		if(j!=0) //���� 
		{
			//printf("**%d\n",snake.in_line[snake.head].id);
			people[snake.in_line[snake.head].id].gate_num=j;
			printf("%d���뿪��������ǰ��%d�Ű����\n", snake.in_line[snake.head].id,j);
			gate[j].in_line[gate[j].tail]=people[snake.in_line[snake.head].id];
			gate[j].tail++;
			gate[j].member++;
			
			int x1=people[snake.in_line[snake.head].id].x,y1=people[snake.in_line[snake.head].id].y;
			int x2=gate[j].x,y2=24+(gate[j].tail-gate[j].head)*48;
			add_anime(x1,y1,x2,y2);
			snake.head++;
			snake.number--;	
		}
	}
	snake.number=snake.tail-snake.head;
}

void put_people()
{
	printf("snake.number:%d\nmax_cust_single_line:%d\nmax_lines%d\n",snake.number,max_cust_single_line,max_lines);
    if(snake.number<=max_cust_single_line*max_lines&&people[people_tail].appear_time+1000<=clock()&&0==new_people&&!get_off_work&&normal_distribution()==1)
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
