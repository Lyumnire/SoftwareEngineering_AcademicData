#include <stdio.h>
#include <string.h>
void main()
{  FILE *fp; int i,j,k,n;
   char s[]="Windows Office",c;
   n=strlen(s);
   /****考生在以下空白处写入执行语句******/

   
   
   
   
   
   
   /****考生在以上空白处写入执行语句******/
   puts(s);
   fp=fopen("CD2.dat","wb");
   fwrite(s,1,n,fp);
   fclose(fp);
}