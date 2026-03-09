 #include <stdio.h>
 #include <math.h>
 /****考生在以下空白处声明函数f ******/





 /****考生在以上空白处声明函数f ******/
 void main()
{  FILE *fp; double x,max;
   /****考生在以下空白处写入执行语句******/

 
 
 
   
   /****考生在以上空白处写入执行语句******/
   printf("%f\n",max);
   fp=fopen("CD2.dat","wb");
   fwrite(&max,8,1,fp);
   fclose(fp);
}