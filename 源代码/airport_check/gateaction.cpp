#include"head.h"

int choose_gate() //0:�޿�ѡ����� i��ѡ��i�Ű���� 
{
    int min=1000;
    int ans=0;
	for(int i=1;i<=max_check;i++)
    {
    	//printf("**\n");
		if(gate[i].is_off&&gate[i].state!=3&&gate[i].state!=4&&gate[i].ready_to_rest!=1&&gate[i].member<min&&gate[i].member<max_cust_check)
    	{
    		min=gate[i].member;
    		ans=i;
    		//printf("____\n");
    	}
    }
    return ans;
}

void Dynamic_opening_off() //��̬������������� 
{
	snake.number=snake.tail-snake.head;
	int n=0;//��ǰ���Ű�������� 
	for(int i=1;i<=max_check;i++)
	{
		if(gate[i].is_off) n++;
	}
	if(n<=max_check&&snake.number>n*max_seq_len)//���°���� 
	{
		for(int i=1;i<=max_check;i++)
		{
			if(gate[i].is_off==0)
			{
				gate[i].is_off=1;
				break; 
			}
		}
	}
	else if(n>min_check&&snake.number<n*easy_seq_len)//�رհ���� 
	{
			
		for(int i=max_check;i>0;i--)
		{
			if(gate[i].is_off&&gate[i].state==2)
			{
				gate[i].is_off=0;
				break; 
			}
		}
	}	
}

void check_rest(int n)//n�Ű������Ϣ 
{
	gate[n].ready_to_rest=1;
	printf("%d�Ŵ�����Ϣ\n",n); 
	if(gate[n].member==0) 
	{
		
		gate[n].rest_end_time=clock()+ran(4000,max_sec*1000);
		gate[n].state=3;
		gate[n].ready_to_rest=0;
	}
}

void check_open()//��Ϣ���� 
{
	for(int i=1;i<=max_check;i++)
	{
		if(gate[i].state==3&&gate[i].rest_end_time<=clock())
		{
			gate[i].state=2;
		}
	}
}

void off_duty()
{
	for(int i=1;i<=max_check;i++)
    {
    	gate[i].ready_to_off=1;
    }
}

void gate_action()//����ڰ��� 
{
	Dynamic_opening_off();
	
	clock_t time;
	for(int i=1;i<=max_check;i++)
    {
		time=clock();
		
		if(gate[i].state==2&&gate[i].member!=0)
		{
			
			time=clock();
			
			gate[i].check_end_time=time+gate[i].in_line[gate[i].head].cost_time;
			people[gate[i].in_line[gate[i].head].id].die_time=gate[i].check_end_time+1000;
			if(gate[i].check_end_time+6000>people_clear_time||people_clear_time==2147483647)people_clear_time=gate[i].check_end_time+6000;
			printf("%d�ų˿���%d�Ű���ڰ���\n", gate[i].in_line[gate[i].head].id,i);
			if(gate[i].in_line[gate[i].head].is_bad==1) 
			{
				printf("����Σ������%d\n", gate[i].in_line[gate[i].head].id);
				bad_number++;
			}
			
			gate[i].state=1;
		}
		time=clock();
		
		if(gate[i].state==1&&gate[i].check_end_time<=time)
		{
			gate[i].state=2;
			gate[i].head++;
			gate[i].member--;
			printf("%d�Ű���ڰ������\n",i); 
		}
	}
	
	for(int i=1;i<=max_check;i++)
	{
		if(rest[i]==1)
		{
			
			check_rest(i);
			if(!gate[i].ready_to_rest) rest[i]=0;
		}
	}
	
	check_open();
}

int auto_exit()
{
	if(!get_off_work||clock()<people_clear_time)
	{
		return 0;
	}
	return 1;
	
}
