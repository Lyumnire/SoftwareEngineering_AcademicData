#include <stdio.h>
#include <math.h>
void main()
{  FILE *fp; double a=1.05; long n=1;
   /****考生在以下空白处写入执行语句******/






   /****考生在以上空白处写入执行语句******/
   printf("%d  %.4f\n",n,a);
   fp=fopen("CD1.dat","wb");
   fwrite(&a,8,1,fp);
   fclose(fp);
}

