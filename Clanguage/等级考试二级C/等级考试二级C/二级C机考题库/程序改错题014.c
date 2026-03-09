 #include <stdio.h>
 void main()
{  char a[]="a2汉字";
   int mm,i;
   /******** 1 *******/
   printf(“请输入密码:”);
   /******** 2 *******/
   scanf("%d",mm);
   for(i=0;a[i]!='\0';i++) /*各字符与mm作一次按位异或*/
     a[i]=a[i]^mm;
   puts(a);
   /*** 各字符与mm再作一次按位异或 ***/
   /******** 3 *******/ 
   for( ;a[i]!='\0';i++)
	 /****** 4 ******/
     a[i]=a[i]^mm^mm;
   puts(a);
}