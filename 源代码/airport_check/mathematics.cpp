#include"head.h"

int ran(int lowbound,int upbound)//随机返回一个low到up之间的整数 
{
    if(upbound<lowbound)
    {
        int tmp=lowbound;
        lowbound=upbound;
        upbound=tmp;
    }
    return random(upbound-lowbound+1)+lowbound;
}

int normal_distribution()//正态分布出现的旅客，1表示旅客出现，0表示不出现 
{
    double chance,time_now=clock(),average=240000,deviation=90000,option=10000;//??????????需要之后调整参数 
    chance=(double)option/2.506628274631/deviation*pow(2.718281828459045,-((average-time_now)*(average-time_now))/(2*deviation*deviation));
    //两个数分别为根号下2pi和e
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
		if(x==120+max_cust_single_line*48)//是拐点 
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
		if(x==168)//是拐点
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
		if(x==120+max_cust_single_line*48)//是拐点 
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
		if(x==168)//是拐点
		{
			return y-48;
		}
		else
		{
			return y;
		}
	}
}
