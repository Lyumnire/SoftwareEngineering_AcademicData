 #include <stdio.h>
 /****考生在以下空白处声明函数f ******/




 /****考生在以上空白处声明函数f ******/
 void main()
{  FILE *fp; double min; int i,j,x1,y1;
   /****考生在以下空白处写入执行语句******/







   /****考生在以上空白处写入执行语句******/
   printf("%f  %d  %d\n",min,x1,y1);
   fp=fopen("CD2.dat","wb");
   fwrite(&min,8,1,fp);
   fclose(fp);
}