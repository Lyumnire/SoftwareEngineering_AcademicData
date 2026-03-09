#include <stdio.h>
void main()
{  FILE *fp; long x,y,z,k=0;
   /****考生在以下空白处写入执行语句******/





   /****考生在以上空白处写入执行语句******/
   printf("%ld\n",k);
   fp=fopen("CD1.dat","wb");
   fwrite(&k,4,1,fp);
   fclose(fp);
}