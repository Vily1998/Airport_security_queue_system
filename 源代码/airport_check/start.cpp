#include"head.h"

void setblank(int x1,int y1,int x2,int y2)//设置文本框 
{
	setlinestyle(PS_DASH, NULL, 2);
	line(x1,y1,x2,y1);
	line(x1,y2,x2,y2);
	line(x1,y1,x1,y2);
	line(x2,y1,x2,y2);
}

void home(void)//开始页面 
{ 
	FILE *ptr1;
	ptr1=fopen("outputdetail.txt","w");
	fclose(ptr1);
	FILE *ptr2;
	ptr2=fopen("outputchange.txt","w");
	fclose(ptr2);//清空log日志 
	initgraph(1200, 720);
	PIMAGE graph;
	graph=newimage();
	getimage(graph,"home.jpg");
	putimage(0,0,graph);
	setbkmode(TRANSPARENT);
	setfont(70, 0, "宋体");
	setcolor(EGERGB(0xFF,0xFF,0xF0));
	outtextxy(240,240, "Welcome To The Airport");
	setfont(50, 0, "宋体");
	setcolor(EGERGB(0xFF,0xFF,0xF0));
	xyprintf(950,400,"直接开始");
	xyprintf(950,500,"配置参数");
	xyprintf(950,600,"直接退出");
	setlinestyle(PS_DASH, NULL,2);
	setblank(930,400,1170,450);
	setblank(930,500,1170,550);
	setblank(930,600,1170,650);
	delimage(graph); 
}

void conpage(void)//配置参数页面 
{
	const char *element1[]={
	"<1> min_check",
	"<2> max_check",
	"<3> max_cust_single_line",
	"<4> max_lines",
	"<5> max_seq_len",
	"<6> easy_seq_len",
	"<7> max_cust_check",
	"<8> max_sec"};
	const char *element2[]={
	"安检口最小数",
	"安检口最大数",
	"单队列最大等待乘客数",
	"缓冲区直队数量",
	"最大允许等待长度",
	"轻松等待长度",
	"每条安检队伍最大长度",
	"一次安检或休息最长时长"}; 	
	const char *ch_number[]={"4","8","14","2","4","3","4","8"};
	char tem_ch[30];
	initgraph(1200,720);
	PIMAGE graph2;
	graph2=newimage();
	getimage(graph2,"configure.jpg");//获取背景图片 
	putimage(0,0,graph2);
	setfont(30, 0, "宋体");
	setcolor(EGERGB(0xFF,0xFF,0xF0));
	outtextrect(340, 50, 160, 100, "参数名称");
	outtextrect(680, 50, 120, 100, "推荐数值");
	outtextrect(930, 50, 120, 100, "当前数值");
	setfont(22,0,"宋体");
	setcolor(EGERGB(0xFF,0xFF,0xF0));
	for(int i=0;i<8;i++)
		outtextrect(310,100+70*i,270,100,element1[i]);
	for(int i=0;i<8;i++)
		outtextrect(50,100+i*70,250,100,element2[i]);
	setfont(25,0,"宋体");
	for(int i=0;i<8;i++)
		outtextrect(730,100+70*i,250,100,ch_number[i]);
	PIMAGE p1;
	p1=newimage();
	getimage(p1,"minus.jpg");
	for(int i=0;i<=7;i++)
	{
		putimage(910,90+i*70,p1);
	}
	delimage(p1);
	
	PIMAGE p2;
	p2=newimage();
	getimage(p2,"plus.jpg");
	for(int i=0;i<=7;i++)
	{
		putimage(1025,90+i*70,p2);
	} 
	delimage(p2);
	setfont(30,0,"宋体");
	setcolor(EGERGB(0xFF,0xFF,0xF0));
	outtextrect(1000,660,250,100,"保存并开始");
	setblank(990,650,1160,700);
	PIMAGE p3;
	p3=newimage();
	getimage(p3,"blank.jpg");
	for(int i=0;i<=7;i++)
		{
			putimage(970,90+70*i,p3);
		} 
	delimage(p3);
	setfont(25,0,"宋体");
	setcolor(EGERGB(0xFF,0xFF,0xF0));
	for(int i=0;i<8;i++)
		//outtextrect(980,100+70*i,250,100,ch_number[i]);
		xyprintf(980,100+70*i,"%d",important[i]); 
	//xyprintf(980,590,"%d",important[7]);
	delimage(graph2);	
}

int mainoption(void)//主界面选择 1为直接开始 2为配置参数 0为直接退出 
{
	int mainoption0=0; 
	int mainoption1=1;
	int mainoption2=2; 
	setlinestyle(PS_DASH, NULL,2);
	mouse_msg msg = {0};
	while(is_run())
	{
		msg=getmouse();
		if((int)msg.x>930&&(int)msg.x<1170)
		{
			if((int)msg.y>400&&(int)msg.y<450)
			{
				setcolor(EGERGB(0x80, 0x0, 0xFF));
				setblank(930,400,1170,450);
				xyprintf(950,400,"直接开始");
				setcolor(EGERGB(0xFF,0xFF,0xF0));
				setblank(930,500,1170,550);
				xyprintf(950,500,"配置参数");
				setblank(930,600,1170,650);
				xyprintf(950,600,"直接退出"); 
				if(msg.is_left()&&msg.is_up()) 
					return mainoption1;
			}
			else if((int)msg.y>500&&(int)msg.y<550)
			{
				setcolor(EGERGB(0x80, 0x0, 0xFF));
				setblank(930,500,1170,550);
				//outtextrect(500,300,200,100,"配置参数");
				xyprintf(950,500,"配置参数");
				setcolor(EGERGB(0xFF,0xFF,0xF0));
				setblank(930,400,1170,450);
				xyprintf(950,400,"直接开始");
				setblank(930,600,1170,650); 
				xyprintf(950,600,"直接退出");
				if(msg.is_left()&&msg.is_up())
					return mainoption2;
			}
			else if((int)msg.y>600&&(int)msg.y<650)
			{
				setcolor(EGERGB(0x80, 0x0, 0xFF));
				setblank(930,600,1170,650); 
				xyprintf(950,600,"直接退出");
				setcolor(EGERGB(0xFF,0xFF,0xF0));
				setblank(930,500,1170,550);
				xyprintf(950,500,"配置参数");
				setblank(930,400,1170,450);
				xyprintf(950,400,"直接开始");
				if(msg.is_left()&&msg.is_up())
					return mainoption0;
			}
			else 
			{
			setcolor(EGERGB(0xFF,0xFF,0xF0));
			setblank(930,600,1170,650); 
			xyprintf(950,600,"直接退出");
			setblank(930,500,1170,550);
			xyprintf(950,500,"配置参数");
			setblank(930,400,1170,450);
			xyprintf(950,400,"直接开始");
			}
		}
	} 
}

int conoption(void)//配置参数界面选择 1为保存并退出 
{
	PIMAGE pp;
	pp=newimage();
	getimage(pp,"blank.jpg");
	setbkmode(TRANSPARENT);
	char *tem_ch[8];
	mouse_msg msg = {0};
	while(is_run())
	{
		setfont(25,0,"宋体");
		msg=getmouse();
		if((int)msg.x>910&&(int)msg.x<960&&(int)msg.y>90&&(int)msg.y<140)
			{	
				if(msg.is_left()&&msg.is_up())
				{	
					if(important[0]>1) 
						important[0]--;
					putimage(970,90,pp);
					xyprintf(980,100,"%d",important[0]);
				}
			}
		else if((int)msg.x>1025&&(int)msg.x<1075&&(int)msg.y>90&&(int)msg.y<140)
		{
			if(msg.is_left()&&msg.is_up())
			{
				if(important[0]<important[1])
					important[0]++;
				putimage(970,90,pp);
				xyprintf(980,100,"%d",important[0]);
			}
		}
		
		else if((int)msg.x>910&&(int)msg.x<960&&(int)msg.y>160&&(int)msg.y<210)
			{
				if(msg.is_left()&&msg.is_up())
				{	
					if(important[1]>important[0])
						important[1]--;
					putimage(970,160,pp);
					xyprintf(980,170,"%d",important[1]);
				}
			}
		else if((int)msg.x>1025&&(int)msg.x<1075&&(int)msg.y>160&&(int)msg.y<210)
		{
			if(msg.is_left()&&msg.is_up())
			{	
				if(important[1]<8)
					important[1]++;
				putimage(970,160,pp);
				xyprintf(980,170,"%d",important[1]);
			}
		}
		
		else if((int)msg.x>910&&(int)msg.x<960&&(int)msg.y>230&&(int)msg.y<280)
			{
				if(msg.is_left()&&msg.is_up())
				{ 
					if(important[2]>10)
						important[2]--;
					putimage(970,230,pp);
					xyprintf(980,240,"%d",important[2]);
				}
			} 
		else if((int)msg.x>1025&&(int)msg.x<1075&&(int)msg.y>230&&(int)msg.y<280)
		{
			if(msg.is_left()&&msg.is_up())
			{
				if(important[2]<14)
					important[2]++;
				putimage(970,230,pp);
				xyprintf(980,240,"%d",important[2]);
			}
		}
		else if((int)msg.x>910&&(int)msg.x<960&&(int)msg.y>300&&(int)msg.y<350)
			{
				if(msg.is_left()&&msg.is_up())
				{
					if(important[3]>2)
						important[3]--;
					putimage(970,300,pp);
					xyprintf(980,310,"%d",important[3]);
				}
			}
		else if((int)msg.x>1025&&(int)msg.x<1075&&(int)msg.y>300&&(int)msg.y<350)
		{
			if(msg.is_left()&&msg.is_up())
			{
				if(important[3]<4)
					important[3]++;
				putimage(970,300,pp);
				xyprintf(980,310,"%d",important[3]);
			}
		}
		else if((int)msg.x>910&&(int)msg.x<960&&(int)msg.y>370&&(int)msg.y<420)
			{
				if(msg.is_left()&&msg.is_up())
				{
					if(important[4]>2)
						important[4]--;
					putimage(970,370,pp);
					xyprintf(980,380,"%d",important[4]);
				}
			}
		else if((int)msg.x>1025&&(int)msg.x<1075&&(int)msg.y>370&&(int)msg.y<420)
		{
			if(msg.is_left()&&msg.is_up())
			{
				if(important[4]<6)
					important[4]++;
				putimage(970,370,pp);
				xyprintf(980,380,"%d",important[4]);
			}
		}
		else if((int)msg.x>910&&(int)msg.x<960&&(int)msg.y>440&&(int)msg.y<490)
			{
				if(msg.is_left()&&msg.is_up())
				{
					if(important[5]>2)
						important[5]--;
					putimage(970,440,pp);
					xyprintf(980,450,"%d",important[5]);
				}
			} 
		else if((int)msg.x>1025&&(int)msg.x<1075&&(int)msg.y>440&&(int)msg.y<490)
		{
			if(msg.is_left()&&msg.is_up())
			{
				if(important[5]<6)
					important[5]++;
				putimage(970,440,pp);
				xyprintf(980,450,"%d",important[5]);
			}
		}
		else if((int)msg.x>910&&(int)msg.x<960&&(int)msg.y>510&&(int)msg.y<580)
			{
				if(msg.is_left()&&msg.is_up())
				{
					if(important[6]>2)
						important[6]--;
					putimage(970,510,pp);
					xyprintf(980,520,"%d",important[6]);
				}
			}
		else if((int)msg.x>1025&&(int)msg.x<1075&&(int)msg.y>510&&(int)msg.y<580)
		{
			if(msg.is_left()&&msg.is_up())
			{
				if(important[6]<6)
					important[6]++;
				putimage(970,510,pp);
				xyprintf(980,520,"%d",important[6]);
			}
		}
		else if((int)msg.x>910&&(int)msg.x<960&&(int)msg.y>580&&(int)msg.y<650)
			{
				if(msg.is_left()&&msg.is_up())
				{
					if(important[7]>5)
						important[7]--;
					putimage(970,580,pp);
					xyprintf(980,590,"%d",important[7]);
				}
			}
		else if((int)msg.x>1025&&(int)msg.x<1075&&(int)msg.y>580&&(int)msg.y<650)
		{
			if(msg.is_left()&&msg.is_up())
			{
				if(important[7]<20)
					important[7]++;
				putimage(970,580,pp);
				xyprintf(980,590,"%d",important[7]);
			}
		}
		if((int)msg.x>990&&(int)msg.x<1160&&(int)msg.y>650&&(int)msg.y<700)
		{
			setfont(30,0,"宋体");
			setlinestyle(PS_DASH, NULL, 3);
			setcolor(EGERGB(0x80, 0x0, 0xFF));
			setblank(990,650,1160,700);
			outtextrect(1000,660,250,100,"保存并开始");
			if(msg.is_left()&&msg.is_up())
				return 1;
		}
		else 
		{
		setfont(30,0,"宋体");
		setcolor(EGERGB(0xFF,0xFF,0xF0));
		setlinestyle(PS_DASH, NULL, 3);
		setblank(990,650,1160,700);
		outtextrect(1000,660,250,100,"保存并开始");
		}
	}
	delimage(pp);	 
}

void input(void)
{
    home();
    setcaption("机场安检排队系统");
    int signal=mainoption();
    if(signal==1)
    	getconfiguration();
	else if(signal==2)
	{	
		getconfiguration();
		conpage();
		if(conoption()==1)
			configure();
	}
	else if(signal==0)
		exit(0);
}
