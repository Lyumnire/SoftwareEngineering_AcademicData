#include<stdio.h>
#include "conio.h"
#include <stdlib.h>
#include <time.h>

int main()
{
    int x=10,y=10;
    KeyValueStru key;//读键返回类型，看conio.h文件的定义 
    srand(time(0)); // 以当前时间为随机数生成器的种子

    clrscr();//清屏（含设置控制台为英文，实验需用英文制表符号，系统默认为中文）
    do {
    	gotoxy(x,y);
        key=kbhit();//不带回显的读键，可读特殊键：功能键F1...F12,组合键Alx+x等 
        x=rand() %80;
        y=rand() % 25;
    } while(key.AscChar!=27);//Esc键退出循环 
 	getchar();
}
