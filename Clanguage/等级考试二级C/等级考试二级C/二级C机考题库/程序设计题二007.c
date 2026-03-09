 #include <stdio.h>
 #include <math.h>
 double f(double **x,int m,int n)
{  double max; int i,j;
   for(i=0;i<m;i++) {
     max=x[i][0];
     for(j=1;j<n;j++) 
	   if(fabs(x[i][j])>fabs(max)) max=x[i][j];
     for(j=0;j<n;j++) x[i][j]/=max;
   }
 }
 void main()
{  FILE *fp;
   double a[3][3]={{1.3,2.7,3.6},{2,3,4.7},{3,4,1.27}};
   double *c[3]={a[0],a[1],a[2]}; int i,j;
   /****考生在以下空白处写入执行语句******/





   /****考生在以上空白处写入执行语句******/
   fp=fopen("CD2.dat","wb");
   fwrite(*a+8,8,1,fp);
   fclose(fp);
}