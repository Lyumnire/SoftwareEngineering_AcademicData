#include <stdio.h>
void main()
{  /****** 1 ******/
   int n,s;
   scanf("%d",&n);
   /****** 2 ******/
   n<0?-n:n;
   /****** 3 ******/
   while(n>=0){
     /***** 4 *****/
     s=s+n/10;
	 n=n/10;
   }
   printf("%d\n",s);
}