#include"head.h"
#include"link.h" 

int main()
{	
    initgraph(1200,720);
    randomize();
    setrendermode(RENDER_MANUAL);
    input();
    showmouse(0);
    get_resource();
    init();
    setcaption("机场安检排队系统");
    for(frame_count=1;is_run();delay_fps(60),frame_count++)
   	{	
      	check_mouse();
      	put_people();
      	gate_action();
      	snake_action();
     	if(frame_count%60==0)
			output();
      	render_action();
      	if(auto_exit())
        {
            break;
        } 
    }
   	closegraph();
    return 0;
} 
