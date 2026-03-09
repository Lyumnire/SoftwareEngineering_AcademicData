 #include <stdio.h>
 void main()
{  int a[9][9]={{0}},i,j,n;
   /*********** 1 **************/
   while(scanf("%d",n),n<1||n>9);
   for(i=0;i<n;i++) {
	 /****** 2 ********/
     for(j=0;j<i;j++)
	   /******* 3 *********/
	   a[i][j]=i-j;
   }
   for(i=0;i<n;i++) {
	 for(j=0;j<n;j++) 
	   /******** 4 *********/
	   printf("%3d",&a[i][j]);
	 putchar('\n');
   }
 }