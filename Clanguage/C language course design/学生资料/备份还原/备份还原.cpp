#include<stdio.h>
#include<string.h>
#include "conio.h"

int main()
{
	CHAR_INFO FirstSave[300];
    clrscr();
	printf("djkdsjfkjsdkfj\nasdfsaasafsdfsaf\ndfssssssssssssssssssss\nsdfffffffffffffffffff\nsdffffffffffff\n");
	printf("djkdsjfkjsdkfj\nasdfsaasafsdfsaf\ndfssssssssssssssssssss\nsdfffffffffffffffffff\nsdffffffffffff\n");
	gettext(1,1,8,5,FirstSave);

	getchar();
	puttext(1,15,8,19,FirstSave);
	getchar();
}
