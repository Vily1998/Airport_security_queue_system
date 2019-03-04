#include"head.h"

void init()
{
    for(int i=1;i<MAX_PEOPLE;i++)//µÚi¸öÈË 
    {
    	people[i].id=i;
        people[i].state=0;
        people[i].cost_time=ran(4000,max_sec*1000);//???
        people[i].is_bad=i>5&&ran(1,10000)<500?1:0;
        people[i].is_emergency=i>5&&ran(1,10000)<100?1:0;
        
        if(people[i].is_emergency)
        {
            people[i].is_bad=0;
            if(people[i-1].is_emergency)
            {
                people[i].is_emergency=0;
            }
        }
        
        people[i].kind=ran(1,155);
        
        if(people[i].is_bad==1)
        {
        	if(people[i].kind>153)people[i].kind=153;
        	people[i].kind=156+people[i].kind/11;
		}
		
        people[i].gate_num=0;
        people[i].die_time=2147483647;
        people[i].x=2147483647;
        people[i].y=2147483647;
    }
    
    snake.is_full=0;
    snake.number=0;
    
    for(int i=1;i<=max_cust_single_line*max_lines;i++)
	{
    	snake.in_line[i].id=0;
		snake.in_line[i].state=-1;
    	snake.in_line[i].x=0;
		snake.in_line[i].y=0;
    	snake.in_line[i].appear_time=0;
    	snake.in_line[i].cost_time=0;
    	snake.in_line[i].is_bad=-1;
    	snake.in_line[i].is_emergency=-1;
    	snake.in_line[i].gate_num=0;
    }
    
    snake.head=1;
	snake.tail=1;
	
	for(int i=1;i<=max_check;i++)
    {
		if(i<=min_check) gate[i].is_off=1;
		else gate[i].is_off=0;
		gate[i].state=2;
    	gate[i].member=0;  
    	gate[i].check_end_time=0;
    	gate[i].rest_end_time=0;
    	gate[i].ready_to_rest=0;
		gate[i].ready_to_off=0 ; 
    	for(int j=1;j<=max_seq_len;j++)
		{
    		gate[i].in_line[j].id=0;
			gate[i].in_line[j].state=-1;
    		gate[i].in_line[j].x=0;
			gate[i].in_line[j].y=0;
    		gate[i].in_line[j].appear_time=0;
    		gate[i].in_line[j].cost_time=0;
    		gate[i].in_line[j].is_bad=-1;
    		gate[i].in_line[j].is_emergency=-1;
    		gate[i].in_line[j].gate_num=0;
    	}
    	gate[i].head=1;
		gate[i].tail=1;
	}
	
	for(int i=1;i<=8;i++)
	{
		gate[i].x=72+i*96;
		gate[i].y=38;
	}
	
	for(int i=0;i<9;i++)
	{
		rest[i]=0;
	}
}

