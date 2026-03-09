#include <stdio.h>
#include <math.h>
void main()
{ double x,eps,s=1,t=1;
  /******* 1 ********/
  float i=1;
  /******* 2 **********/
  scanf("%f%f",&x,&eps);
  do {
    i++;
	/***** 3 *****/
    t=t*x/i;
    s+=t;
    /***** 4 *****/
  } while(fabs(t)<eps);
  printf("%f\n",s);
}
