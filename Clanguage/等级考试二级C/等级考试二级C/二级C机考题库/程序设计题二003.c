#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{  FILE *fp; long i,n,*a;
   char s[]="ABCabc$%^,.+-*/";
   n=strlen(s);
   a=(long*)malloc(n*sizeof(long));
   /****考生在以下空白处写入执行语句******/

   
   
   
   
   
   /****考生在以上空白处写入执行语句******/
   fp=fopen("CD2.dat","wb");
   fwrite(a,4,n,fp);
   fclose(fp);
}