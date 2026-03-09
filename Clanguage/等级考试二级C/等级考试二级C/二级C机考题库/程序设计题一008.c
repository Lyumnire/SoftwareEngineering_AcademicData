 #include <stdio.h>
 #include <math.h>
 void main()
{  FILE *fp; double sum,x; int i;
   /****考生在以下空白处写入执行语句******/

 
 
 
 
 
 
   /****考生在以上空白处写入执行语句******/
   printf("%f\n",sum);
   fp=fopen("CD1.dat","wb");
   fwrite(&sum,8,1,fp);
   fclose(fp);
 }