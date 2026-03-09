 #include <stdio.h>
 /********** 1 *********/
 int DtoH(int n)
{  int k=n & 0xf;
   if(n>>4!=0) DtoH(n>>4);
   /********** 2 *********/
   if(k<=10)  
     putchar(k+'0');
   else
   /********** 3 *********/
	 putchar(k-10+a);
 }
 void main()
{  int a[4]={28,31,255,378},i;
   for(i=0;i<4;i++) {
	 printf("%d-->",a[i]);
	 /******** 4 ********/
	 printf("%s",DtoH(a[i]));
	 putchar('\n');
   }
 }