#include <stdio.h>
#include <math.h> 
void main()
{ double a[10],v=0,x,d; int i;
  printf("Input 10 numbers:  ");
  for(i=0;i<10;i++) {
	scanf("___1___", &a[i]);
	v=v+___2____;
  }
  d=_____3_____; x=a[0];
  for(i=1;i<10;i++)
	if(fabs(a[i]-v)<d) d=fabs(a[i]-v),___4____;
  printf("%.4f   %.4f\n",v,x);
}