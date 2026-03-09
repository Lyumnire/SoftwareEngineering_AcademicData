 #include <stdio.h>
 #include <math.h>
 /*****考生在以下空白处编写函数f ******/







 /****考生在以上空白处编写函数f  ******/
 void main()
{  FILE *fp; int i; double y;
   double a[10]={1.2,-1.4,-4.0,1.1,2.1,-1.1,3.0,-5.3,6.5,-0.9};
   y=f(a,2.345,10);
   printf("%f\n",y);
   fp=fopen("CD2.dat","wb");
   fwrite(&y,8,1,fp);
   fclose(fp);
}