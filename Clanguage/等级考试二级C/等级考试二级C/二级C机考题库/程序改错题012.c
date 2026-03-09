 #include <stdio.h>
 void main()
{ /******** 1 *******/
  int i;
  int a[6]={1,3,5,7,9,11};
  int b[7]={2,5,7,9,12,16,3};
  /******* 2 *******/
  for(i=0;i<=6;i++) {
	for(j=0;j<7;j++)
	  /******** 3 *******/
	  if(a[i]=b[j]) break;
	/******* 4 ********/
	if(j>=7) 
	  printf("%d  ",a[i]);
  }
  printf("\n");
}