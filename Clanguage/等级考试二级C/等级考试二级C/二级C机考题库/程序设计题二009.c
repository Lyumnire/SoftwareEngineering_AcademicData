 #include <stdio.h>
 #include <math.h>
 #define len(x1,y1,x2,y2) sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))
 void main()
{  FILE *fp; int i,j; double min,d;
   double x[10]={1.1,3.2,-2.5,5.67,3.42,-4.5,2.54,5.6,0.97,4.65};
   double y[10]={-6,4.3,4.5,3.67,2.42,2.54,5.6,-0.97,4.65,-3.33};
   min=len(x[0],y[0],x[1],y[1]);
   /****考生在以下空白处写入执行语句 ******/

   
   
   
   

   
   
   /****考生在以上空白处写入执行语句 ******/
   printf("%f\n",min);
   fp=fopen("CD2.dat","wb");
   fwrite(&min,8,1,fp);
   fclose(fp);
}