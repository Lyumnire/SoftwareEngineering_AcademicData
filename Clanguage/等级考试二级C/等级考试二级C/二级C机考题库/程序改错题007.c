#include <stdio.h>
float f(float x,int n)
{ /******* 1 ******/
  if(n==1) 
	return 1;
  else
	/****** 2 ******/
	return f(x,n-1);
}
void main()
{  float y,z; int m;
   while(1) {
     scanf("%f%d",&y,&m);
	 /****** 3 *******/
	 if(m>=0) break;
	 /******* 4 ********/
	 z=f(m,y);
	 printf("%f\n",z);
   }
}