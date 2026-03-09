#include <stdio.h>
void main()
{ int a,n,i; long s=0,t;
  /******* 1 ********/
  scanf("%d%d",a,n);
  /******* 2 **********/
  t=1;
  /******* 3 **********/
  for(i=1;i<n;i++) {
    t=t*10+a;
    /******* 4 ********/
	t=t+s;
  }
  printf("%ld\n",s);
}
