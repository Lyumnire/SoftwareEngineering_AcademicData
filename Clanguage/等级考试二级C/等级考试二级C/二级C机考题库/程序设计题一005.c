 #include <stdio.h>
 #include <math.h>
 void main()
{  FILE *fp; double s,x[5]={-1.5,2.1,6.3,3.2,-0.7};
   double y[5]={7,5.1,3.2,4.5,7.6}; int i,j;
   /****考生在以下空白处写入执行语句******/
   





   /****考生在以上空白处写入执行语句******/
   printf("%f\n",s);
   fp=fopen("CD1.dat","wb");
   fwrite(&s,8,1,fp);
   fclose(fp);
}