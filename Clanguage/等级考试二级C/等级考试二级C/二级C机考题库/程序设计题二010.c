 #include <stdio.h>
 #include <math.h>
 /****考生在以下空白处编写函数f******/







 /****考生在以上空白处写入语句 ******/
 void main()
{  FILE *fp; double y;
   double b[10]={1.1,3.2,-2.5,5.67,3.42,-4.5,2.54,5.6,0.97,4.65};
   y=f(b,1.5,10);
   printf("%f\n",y);
   fp=fopen("CD2.dat","wb");
   fwrite(&y,8,1,fp);
   fclose(fp);
}