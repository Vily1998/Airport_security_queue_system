#include"head.h"

void outputpart1(void)//������ڡ�����ڶ��к��Ŷӻ�����״̬�б仯ʱ���м�¼
{
	FILE *fptr;
	char nowtime[500];
	fptr=fopen("outputchange.txt","a+");
	//�����
	for(int wincount=1;wincount<=max_check;wincount++)//��ӡ����ںͶ���״̬ 
	{
		if(gate[wincount].ready_to_off==1&&oldstategate[wincount]!=5)
		{ 
			oldstategate[wincount]=5;
			fprintf(fptr,"T=<%ds> WIN%d:�ӵ��°�ָ��\n",clock()/1000,wincount);	
		}
		else if(gate[wincount].ready_to_rest==1&&oldstategate[wincount]!=6)
		{
			oldstategate[wincount]=6;
			fprintf(fptr,"T=<%ds> WIN%d:�ӵ���Ϣָ��\n",clock()/1000,wincount);
		}
		else if(get_off_work!=1&&gate[wincount].state==3&&oldstategate[wincount]!=3)
		{
			oldstategate[wincount]=3;
			fprintf(fptr,"T=<%ds> WIN%d:��Ϣ\n",clock()/1000,wincount);
		}
		else if(get_off_work==1&&gate[wincount].member==0&&oldstategate[wincount]!=4)
		{
			oldstategate[wincount]=4;
			fprintf(fptr,"T=<%ds> WIN%d:�°�\n",clock()/1000,wincount); 
		}
		else if(gate[wincount].state==1&&gate[wincount].ready_to_rest!=1&&gate[wincount].ready_to_off!=1&&oldstategate[wincount]!=1)
		{
			oldstategate[wincount]=1;
			fprintf(fptr,"T=<%ds> WIN%d:����\n",clock()/1000,wincount);
		}
		if(gate[wincount].member==max_cust_check&&oldstatepeo[wincount]!=1)
		{
			oldstatepeo[wincount]=1;
			fprintf(fptr,"T=<%ds> %d�Ű���ڶ�������\n",clock()/1000,wincount); 
		}
		if(gate[wincount].member<max_cust_check&&oldstatepeo[wincount]!=0)
		{
			oldstatepeo[wincount]=0;
			fprintf(fptr,"T=<%ds> %d�Ű���ڶ���δ��\n",clock()/1000,wincount); 
		}
	}
	if(snake.number==max_cust_single_line*max_lines&&oldstatesnake!=1)
	{
		oldstatesnake=1;
		fprintf(fptr,"T=<%ds> ����������\n",clock()/1000);
	} 
	if(snake.number<max_cust_single_line*max_lines&&oldstatesnake!=0)
	{
		oldstatesnake=0;
		fprintf(fptr,"T=<%ds> ������δ��\n",clock()/1000);
	}
	//��ӡ������״̬ 
	fclose(fptr);
}

void outputpart2(void)//ÿ�������Լ�¼����ڡ�����ڶ��к��Ŷӻ�������״̬
{
	FILE *ptr;
	char nowtime[500];
	ptr=fopen("outputdetail.txt","a+");
	itoa(clock()/1000,nowtime,10);//��¼ʱ�� 
	fputs("T=<",ptr);    
	fputs(nowtime,ptr);
	fputs("s>\n",ptr);//��ӡʱ�� 
	fputs("OFFDUTY=",ptr);
	if(get_off_work==1)	
		fputc('Y',ptr);
	else	
		fputc('N',ptr);
	fputc('\n',ptr);//��ӡ���°�
	
	int wincount=1;//���ڼ�¼�������Ŀ
	for(;wincount<=max_check;wincount++)//��ӡ�������Ϣ 
	{
		fputs("WIN",ptr);
		fprintf(ptr,"%d",wincount);
		fputs(":State=",ptr);
		
		if(gate[wincount].state==1)
			fputs("������",ptr);
		else if(gate[wincount].state==2)
			fputs("�������",ptr);
		else if(gate[wincount].state==3)
			fputs("��ͣ����",ptr);
		else if(gate[wincount].state==4)
			fputs("�°�",ptr);
		else if(gate[wincount].ready_to_off==1&&gate[wincount].member>=1)
			fputs("׼���°�",ptr);
		else if(gate[wincount].ready_to_rest==1&&gate[wincount].member>=1)
			fputs("׼����Ϣ",ptr);		
		if(gate[wincount].state==1)
		//���ڻ������ŶӲ���û���°� �� ����ڴ�����Ϣ״̬�����Ұ���ڻ������Ŷ� 
			{
				fputs(" WinList(�����г˿ͱ���б�)=",ptr);
				for(int jj=gate[wincount].head;jj<=gate[wincount].tail-1;jj++)
					{
						char peomark[30];//�˵ı�� 
						itoa(gate[wincount].in_line[jj].id,peomark,10);
						fputs(peomark,ptr);
						fputc(' ',ptr);
					} //��ӡ�����г˿ͱ���б�
				char peonum[30];
				fputs("WinListCustCount(����ڶ�������)=",ptr);
				itoa(gate[wincount].member,peonum,10);
				fputs(peonum,ptr);
				//��ӡ����ڶ������� 
				fputc('\n',ptr); 
			}
		else if(gate[wincount].state==3||gate[wincount].state==2)//����ڴ�����Ϣ״̬
		{
			//fputs("���ڴ�����Ϣ״̬"); 
			fputs(" WinListCustCount(����ڶ�������)=0",ptr);
			fputc('\n',ptr);
		}
		else if(gate[wincount].state==4)
		{
			//fputs("���ڴ����°�״̬"); 
			fputs(" WinListCustCount(����ڶ�������)=0",ptr);
			fputc('\n',ptr);	
		}
		else if(gate[wincount].ready_to_off==1&gate[wincount].member>=1)//׼����Ϣ���������� 
		{
			fputs(" WinList(�����г˿ͱ���б�)=",ptr);
			for(int peocount=1;peocount<=gate[wincount].length;peocount++)//��¼�Ŷ��� 
			{
				for(int j=gate[wincount].head;j<=gate[wincount].tail-1;j++)
					{
						char peomark[30];//�˵ı�� 
						itoa(gate[wincount].in_line[j].id,peomark,10);
						fputs(peomark,ptr);
						fputc(' ',ptr);
					} //��ӡ�����г˿ͱ���б�
				char peonum[30];
				fputs("WinListCustCount(����ڶ�������)=",ptr);
				itoa(gate[wincount].member,peonum,10);
				fputs(peonum,ptr);
			}
		}
		else if(gate[wincount].ready_to_rest==1&&gate[wincount].member>=1)//׼���°൫�������� 
		{
			fputs(" WinList(�����г˿ͱ���б�)=",ptr);
			for(int peocount=1;peocount<=gate[wincount].length;peocount++)//��¼�Ŷ��� 
			{
				for(int j=gate[wincount].head;j<=gate[wincount].tail-1;j++)
					{
						char peomark[30];//�˵ı�� 
						itoa(gate[wincount].in_line[j].id,peomark,10);
						fputs(peomark,ptr);
						fputc(' ',ptr);
					} //��ӡ�����г˿ͱ���б�
				char peonum[30];
				fputs("WinListCustCount(����ڶ�������)=",ptr);
				itoa(gate[wincount].member,peonum,10);
				fputs(peonum,ptr);
			}
		}
		if(gate[wincount].in_line[gate[wincount].head].is_bad==1)//��ͷΪ����
			fprintf(ptr,"%d�ų˿���Ҫ������������\n",gate[wincount].in_line[gate[wincount].head].id);
		if(gate[wincount].member>0&&map[gate[wincount].in_line[gate[wincount].tail-1].id]!=1)
		{
			map[gate[wincount].in_line[gate[wincount].tail-1].id]=1;
			fprintf(ptr,"%d�ų˿ͽ���%d�Ű����\n",gate[wincount].in_line[gate[wincount].tail-1].id,wincount);
		}
		if(gate[wincount].member>0)
		{
			fprintf(ptr,"%d�ų˿ͽ�Ҫ�뿪%d�Ű����\n",gate[wincount].in_line[gate[wincount].head].id,wincount);
		}
	}
	if(snake.number>=1)
		fprintf(ptr,"%d�ų˿ͽ�Ҫ����%d�Ű����\n",snake.in_line[snake.head].id,snake.in_line[snake.head].gate_num+1);
	fputs("EMERGENCY:Total Number Passed(�����˿�����)=",ptr);
	char emenum[30];
	itoa(emergency_number,emenum,10);
	fputs(emenum,ptr);
	fputc('\n',ptr);//��ӡ��������ͨ��������
	fprintf(ptr,"Υ��ƷЯ��������=%d\n",bad_number);
	fputs("ListCustCount(�Ŷӻ������ܳ˿���)=",ptr);
	char snakenum[30];
	itoa(snake.number,snakenum,10);
	fputs(snakenum,ptr);
	fputc('\n',ptr);//��ӡ�Ŷӻ������ܳ˿��� 	
	fputc('\n',ptr);	
	fclose(ptr); 
}    

void output()
{
	outputpart1();
	outputpart2(); 
}

