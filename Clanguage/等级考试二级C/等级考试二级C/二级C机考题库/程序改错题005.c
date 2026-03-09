#include <stdio.h>
void main()
{  float x,max,min;  int i;
   /******** 1 *******/
   for(i=0;i<=10;i++) {
	 /****** 2 *******/
     scanf("%f",x);
     /******* 3 ********/
     if(i=1)
	   { max=x;min=x;}
     else {
       if(x>max) max=x;
       if(x<min) min=x;
	}
  }
  /******* 4 ********/
  printf("%f,%f\n",Max,Min);
}
