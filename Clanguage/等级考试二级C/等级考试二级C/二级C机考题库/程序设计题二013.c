 #include <stdio.h>
 #include <math.h>
 void main()
{  FILE *fp; int i; double d,v,y;
   double x[10]={1.2,-1.4,-4.0,1.1,2.1,-1.1,3.0,-5.3,6.5,-0.9};
   /*****考生在以下空白处写入执行语句 ******/

   
   
   
   
   
   
   
   
   /****考生在以上空白处写入执行语句  ******/
   printf("%f   %f\n",v,y);
   fp=fopen("CD2.dat","wb");
   fwrite(&y,8,1,fp);
   fclose(fp);
}