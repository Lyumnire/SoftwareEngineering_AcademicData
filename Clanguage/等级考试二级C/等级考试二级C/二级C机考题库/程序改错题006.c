#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void main()
{  int i,n;
   struct axy { float x,y;};
   /***** 1 *****/
   struct axy a;
   /***** 2 *****/
   scanf("%d",n);
   a=(struct axy*) malloc(n*sizeof(struct axy));
   for(i=0;i<n;i++)
	 scanf("%f%f",&a[i].x,&a[i].y);
   /***** 3 ******/
   for(i=1;i<=n;i++)
	 if(sqrt(pow(a[i].x,2)+pow(a[i].y,2))<=5) {
	   printf("%f,",a[i].x);
	   /*************** 4 **************/
       printf("%f\n",a+i->y);
	 }
}