#include <stdio.h>
void main()
{   int n,i;
    /****** 1 ******/
    scanf("%f",&n);
	printf("%d=",n);
    /****** 2 ******/
    n=2;
	/****** 3 ******/
    while(n>0)
      if(n%i==0) {
        printf("%d*",i);
	    /****** 4 ******/
        n=n*i;
	  }
      else i++;
	printf("\b \n");
}