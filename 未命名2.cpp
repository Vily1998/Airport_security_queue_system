//图形边界和填充
#include <graphics.h>

int main()
{
	initgraph(640, 480);

   //设置画图颜色，使用RGB宏，三个参数值的范围均为0 - 255 (0xFF)
	//分别表示红色亮度，绿色亮度，蓝色亮度
	//EGERGB(0xFF, 0x0, 0x0) (纯红色) 等价于0xFF0000
	
	//第一次设置背景色
	setbkcolor(EGERGB(0x0, 0x40, 0x0)); //浅绿色
	
	//设置绘图颜色，一般用于边界
	setcolor(EGERGB(0xFF, 0xFF, 0x0));

	//设置填充颜色，一般为图形内部颜色
	setfillcolor(EGERGB(0xFF, 0x0, 0x80));

	//画一带填充的椭圆
	fillellipse(200, 200, 150, 100);//椭圆圆心坐标<200,200>，150和100分别是半径 

	//画一个空心圆
	circle(500, 300, 100);//圆心坐标<500,300>，半径是100 

	//再次设置填充颜色，用于决定下一函数填充的颜色
	setfillcolor(EGERGB(0x80, 0x0, 0xFF));

	//手工填充
	//x,y是开始填充的坐标，第三个参数是填充的边界颜色，或者说以这个颜色作为边界
	//如果这个边界不封闭，那么会导致整个屏幕都是这个颜色
	floodfill(500, 300, EGERGB(0xFF, 0xFF, 0x0));

	getch();//获取一个键盘字符输入。如果当前没有输入的字符就一直等待 
    
	setbkcolor(EGERGB(0x0, 0x0, 0x40)); //修改背景色为浅蓝色
	
	getch();
	closegraph();//关闭图形环境 
	return 0;
} 
