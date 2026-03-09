#include <stdio.h>
void main()
{  FILE *fp; long i,y=1,jc=1;
   /****考生在以下空白处写入执行语句******/





   /****考生在以上空白处写入执行语句******/
   printf("%ld\n",y);
   fp=fopen("CD1.dat","wb");
   fwrite(&y,4,1,fp);
   fclose(fp);
}