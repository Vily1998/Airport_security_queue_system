#include"head.h"

int ran(int lowbound,int upbound)//�������һ��low��up֮������� 
{
    if(upbound<lowbound)
    {
        int tmp=lowbound;
        lowbound=upbound;
        upbound=tmp;
    }
    return random(upbound-lowbound+1)+lowbound;
}

int normal_distribution()//��̬�ֲ����ֵ��ÿͣ�1��ʾ�ÿͳ��֣�0��ʾ������ 
{
    double chance,time_now=clock(),average=240000,deviation=90000,option=10000;//??????????��Ҫ֮��������� 
    chance=(double)option/2.506628274631/deviation*pow(2.718281828459045,-((average-time_now)*(average-time_now))/(2*deviation*deviation));
    //�������ֱ�Ϊ������2pi��e
    if(randomf()<chance)return 1;
    return 0;
}

int point_distance(int pos_x1,int pos_y1,int pos_x2,int pos_y2)
{
	double pos_x=pos_x1-pos_x2,pos_y=pos_y1-pos_y2;
	double dist_ans=pos_x*pos_x+pos_y*pos_y;
	int ans=(int)dist_ans;
	return ans;
}

int nextx(int x,int y)
{
	if(y==648||y==552)
	{
		if(x==120+max_cust_single_line*48)//�ǹյ� 
		{
			return x;
		}
		else
		{
			return x+48;
		}
	}
	else
	{
		if(x==168)//�ǹյ�
		{
			return 168;
		}
		else
		{
			return x-48;
		}
	}
}

int nexty(int x,int y)
{
	if(y==648||y==552)
	{
		if(x==120+max_cust_single_line*48)//�ǹյ� 
		{
			return y-48;
		}
		else
		{
			return y;
		}
	}
	else
	{
		if(x==168)//�ǹյ�
		{
			return y-48;
		}
		else
		{
			return y;
		}
	}
}
