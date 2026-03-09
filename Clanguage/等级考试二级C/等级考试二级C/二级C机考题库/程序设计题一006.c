 #include <stdio.h>
 #include <math.h>
 void main()
{  FILE *fp; double y,t=1;int i=1;
   /****考生在以下空白处写入执行语句******/

 
 
 
 
  
   /****考生在以上空白处写入执行语句******/
   printf("%f\n",y);
   fp=fopen("CD1.dat","wb");
   fwrite(&y,8,1,fp);
   fclose(fp);
 }