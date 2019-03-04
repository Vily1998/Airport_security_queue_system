#include"head.h"

void setconfiguration(void)
{
	FILE *fptr;
	fptr=fopen("configuration.dat","rb+");
	int data_count=0;//用于计数 
	if(fptr==NULL)
		printf("The file can't be open!\n");
	else
	{	//printf("The file can be opened successfully!\n");
		while(data_count<=7)
		{
			fseek(fptr,data_count*sizeof(int),SEEK_SET);
			fwrite(&important[data_count],sizeof(int),1,fptr);
			rewind(fptr);
			data_count++;	
		}
	}	
	fclose(fptr);
}

void getconfiguration(void)
{
	FILE *fptr2;
	fptr2=fopen("configuration.dat","rb");
	if(fptr2==NULL)
		printf("The file can't be open!\n");
	else
	{
		//printf("The file can be opened successfully!\n");
		fread(&min_check,sizeof(int),1,fptr2);important[0]=min_check;
		fread(&max_check,sizeof(int),1,fptr2);important[1]=max_check;
		fread(&max_cust_single_line,sizeof(int),1,fptr2);important[2]=max_cust_single_line;
		fread(&max_lines,sizeof(int),1,fptr2);important[3]=max_lines;
		fread(&max_seq_len,sizeof(int),1,fptr2);important[4]=max_seq_len;
		fread(&easy_seq_len,sizeof(int),1,fptr2);important[5]=easy_seq_len;
		fread(&max_cust_check,sizeof(int),1,fptr2);important[6]=max_cust_check;
		fread(&max_sec,sizeof(int),1,fptr2);important[7]=max_sec;
	}
	fclose(fptr2);
}

void configure(void)
{
	setconfiguration();
	getconfiguration();
}
