#include<stdio.h>
#include "conio.h"
#include<string.h>

int main()
{
    KeyValueStru key;//读键返回类型，看conio.h文件的定义 
    clrscr();//清屏（含设置控制台为英文，实验需用英文制表符号，系统默认为中文）
    do {
        key=kbhit();//不带回显的读键，可读特殊键：功能键F1...F12,组合键Alx+x等 
        printf("Esc(Exit Loop) AsciiChar=%2x VirtualKey=%2x\n",key.AscChar,key.VKey);	
    } while(key.AscChar!=27);//Esc键退出循环 
    key=kbhit();//停顿 
    textattr(0x40);//设置颜色 4是背景表红色，0是前景表黑色，具体看conio.h中的枚举定义 
    gotoxy(2,4);//定位光标 
	printf("djkdsjfkjsdkfj\nasdfsaasafsdfsaf\ndfssssssssssssssssssss\nsdfffffffffffffffffff\nsdffffffffffff\n");
	textcolor(BLUE); //只设置前景
	gotoxy(2,10);//定位光标 
	printf("djkdsjfkjsdkfj\nasdfsaasafsdfsaf\ndfssssssssssssssssssss\nsdfffffffffffffffffff\nsdffffffffffff\n");	
	textbackground(YELLOW); //只设置背景
	gotoxy(2,16);//定位光标 
	printf("djkdsjfkjsdkfj\nasdfsaasafsdfsaf\ndfssssssssssssssssssss\nsdfffffffffffffffffff\nsdffffffffffff\n");	
	getchar();
}
