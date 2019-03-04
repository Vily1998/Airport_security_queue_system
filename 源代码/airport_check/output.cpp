#include"head.h"

void outputpart1(void)//当安检口、安检口队列和排队缓冲区状态有变化时进行记录
{
	FILE *fptr;
	char nowtime[500];
	fptr=fopen("outputchange.txt","a+");
	//安检口
	for(int wincount=1;wincount<=max_check;wincount++)//打印安检口和队列状态 
	{
		if(gate[wincount].ready_to_off==1&&oldstategate[wincount]!=5)
		{ 
			oldstategate[wincount]=5;
			fprintf(fptr,"T=<%ds> WIN%d:接到下班指令\n",clock()/1000,wincount);	
		}
		else if(gate[wincount].ready_to_rest==1&&oldstategate[wincount]!=6)
		{
			oldstategate[wincount]=6;
			fprintf(fptr,"T=<%ds> WIN%d:接到休息指令\n",clock()/1000,wincount);
		}
		else if(get_off_work!=1&&gate[wincount].state==3&&oldstategate[wincount]!=3)
		{
			oldstategate[wincount]=3;
			fprintf(fptr,"T=<%ds> WIN%d:休息\n",clock()/1000,wincount);
		}
		else if(get_off_work==1&&gate[wincount].member==0&&oldstategate[wincount]!=4)
		{
			oldstategate[wincount]=4;
			fprintf(fptr,"T=<%ds> WIN%d:下班\n",clock()/1000,wincount); 
		}
		else if(gate[wincount].state==1&&gate[wincount].ready_to_rest!=1&&gate[wincount].ready_to_off!=1&&oldstategate[wincount]!=1)
		{
			oldstategate[wincount]=1;
			fprintf(fptr,"T=<%ds> WIN%d:工作\n",clock()/1000,wincount);
		}
		if(gate[wincount].member==max_cust_check&&oldstatepeo[wincount]!=1)
		{
			oldstatepeo[wincount]=1;
			fprintf(fptr,"T=<%ds> %d号安检口队列已满\n",clock()/1000,wincount); 
		}
		if(gate[wincount].member<max_cust_check&&oldstatepeo[wincount]!=0)
		{
			oldstatepeo[wincount]=0;
			fprintf(fptr,"T=<%ds> %d号安检口队列未满\n",clock()/1000,wincount); 
		}
	}
	if(snake.number==max_cust_single_line*max_lines&&oldstatesnake!=1)
	{
		oldstatesnake=1;
		fprintf(fptr,"T=<%ds> 缓冲区已满\n",clock()/1000);
	} 
	if(snake.number<max_cust_single_line*max_lines&&oldstatesnake!=0)
	{
		oldstatesnake=0;
		fprintf(fptr,"T=<%ds> 缓冲区未满\n",clock()/1000);
	}
	//打印缓冲区状态 
	fclose(fptr);
}

void outputpart2(void)//每秒周期性记录安检口、安检口队列和排队缓冲区的状态
{
	FILE *ptr;
	char nowtime[500];
	ptr=fopen("outputdetail.txt","a+");
	itoa(clock()/1000,nowtime,10);//记录时间 
	fputs("T=<",ptr);    
	fputs(nowtime,ptr);
	fputs("s>\n",ptr);//打印时间 
	fputs("OFFDUTY=",ptr);
	if(get_off_work==1)	
		fputc('Y',ptr);
	else	
		fputc('N',ptr);
	fputc('\n',ptr);//打印上下班
	
	int wincount=1;//用于记录安检口数目
	for(;wincount<=max_check;wincount++)//打印安检口信息 
	{
		fputs("WIN",ptr);
		fprintf(ptr,"%d",wincount);
		fputs(":State=",ptr);
		
		if(gate[wincount].state==1)
			fputs("办理中",ptr);
		else if(gate[wincount].state==2)
			fputs("办理结束",ptr);
		else if(gate[wincount].state==3)
			fputs("暂停服务",ptr);
		else if(gate[wincount].state==4)
			fputs("下班",ptr);
		else if(gate[wincount].ready_to_off==1&&gate[wincount].member>=1)
			fputs("准备下班",ptr);
		else if(gate[wincount].ready_to_rest==1&&gate[wincount].member>=1)
			fputs("准备休息",ptr);		
		if(gate[wincount].state==1)
		//窗口还有人排队并且没有下班 或 安检口处于休息状态，并且安检口还有人排队 
			{
				fputs(" WinList(队列中乘客编号列表)=",ptr);
				for(int jj=gate[wincount].head;jj<=gate[wincount].tail-1;jj++)
					{
						char peomark[30];//人的编号 
						itoa(gate[wincount].in_line[jj].id,peomark,10);
						fputs(peomark,ptr);
						fputc(' ',ptr);
					} //打印队列中乘客编号列表
				char peonum[30];
				fputs("WinListCustCount(安检口队列人数)=",ptr);
				itoa(gate[wincount].member,peonum,10);
				fputs(peonum,ptr);
				//打印安检口队列人数 
				fputc('\n',ptr); 
			}
		else if(gate[wincount].state==3||gate[wincount].state==2)//安检口处于休息状态
		{
			//fputs("窗口处于休息状态"); 
			fputs(" WinListCustCount(安检口队列人数)=0",ptr);
			fputc('\n',ptr);
		}
		else if(gate[wincount].state==4)
		{
			//fputs("窗口处于下班状态"); 
			fputs(" WinListCustCount(安检口队列人数)=0",ptr);
			fputc('\n',ptr);	
		}
		else if(gate[wincount].ready_to_off==1&gate[wincount].member>=1)//准备休息但窗口有人 
		{
			fputs(" WinList(队列中乘客编号列表)=",ptr);
			for(int peocount=1;peocount<=gate[wincount].length;peocount++)//记录排队人 
			{
				for(int j=gate[wincount].head;j<=gate[wincount].tail-1;j++)
					{
						char peomark[30];//人的编号 
						itoa(gate[wincount].in_line[j].id,peomark,10);
						fputs(peomark,ptr);
						fputc(' ',ptr);
					} //打印队列中乘客编号列表
				char peonum[30];
				fputs("WinListCustCount(安检口队列人数)=",ptr);
				itoa(gate[wincount].member,peonum,10);
				fputs(peonum,ptr);
			}
		}
		else if(gate[wincount].ready_to_rest==1&&gate[wincount].member>=1)//准备下班但窗口有人 
		{
			fputs(" WinList(队列中乘客编号列表)=",ptr);
			for(int peocount=1;peocount<=gate[wincount].length;peocount++)//记录排队人 
			{
				for(int j=gate[wincount].head;j<=gate[wincount].tail-1;j++)
					{
						char peomark[30];//人的编号 
						itoa(gate[wincount].in_line[j].id,peomark,10);
						fputs(peomark,ptr);
						fputc(' ',ptr);
					} //打印队列中乘客编号列表
				char peonum[30];
				fputs("WinListCustCount(安检口队列人数)=",ptr);
				itoa(gate[wincount].member,peonum,10);
				fputs(peonum,ptr);
			}
		}
		if(gate[wincount].in_line[gate[wincount].head].is_bad==1)//对头为坏人
			fprintf(ptr,"%d号乘客正要被带往警务室\n",gate[wincount].in_line[gate[wincount].head].id);
		if(gate[wincount].member>0&&map[gate[wincount].in_line[gate[wincount].tail-1].id]!=1)
		{
			map[gate[wincount].in_line[gate[wincount].tail-1].id]=1;
			fprintf(ptr,"%d号乘客进入%d号安检口\n",gate[wincount].in_line[gate[wincount].tail-1].id,wincount);
		}
		if(gate[wincount].member>0)
		{
			fprintf(ptr,"%d号乘客将要离开%d号安检口\n",gate[wincount].in_line[gate[wincount].head].id,wincount);
		}
	}
	if(snake.number>=1)
		fprintf(ptr,"%d号乘客将要进入%d号安检口\n",snake.in_line[snake.head].id,snake.in_line[snake.head].gate_num+1);
	fputs("EMERGENCY:Total Number Passed(紧急乘客数量)=",ptr);
	char emenum[30];
	itoa(emergency_number,emenum,10);
	fputs(emenum,ptr);
	fputc('\n',ptr);//打印紧急出口通过人数量
	fprintf(ptr,"违禁品携带者数量=%d\n",bad_number);
	fputs("ListCustCount(排队缓冲区总乘客数)=",ptr);
	char snakenum[30];
	itoa(snake.number,snakenum,10);
	fputs(snakenum,ptr);
	fputc('\n',ptr);//打印排队缓冲区总乘客数 	
	fputc('\n',ptr);	
	fclose(ptr); 
}    

void output()
{
	outputpart1();
	outputpart2(); 
}

