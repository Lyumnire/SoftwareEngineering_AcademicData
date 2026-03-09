#include <stdio.h>
void main()
{  FILE *fp; long i,n=0,x[10][2];
   /****考生在以下空白处写入执行语句******/






   /****考生在以上空白处写入执行语句******/
   for(i=0;i<n;i++)
	 printf("%ld  %ld\n",x[i][0],x[i][1]);
   fp=fopen("CD1.dat","wb");
   fwrite(&x,4,2*n,fp);
   fclose(fp);
}