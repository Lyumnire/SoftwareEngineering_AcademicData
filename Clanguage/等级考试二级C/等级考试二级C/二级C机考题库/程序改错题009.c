 #include <stdio.h>
 #define N 10
 void main()
{  int i,j,min,temp;
   int a[N]={5,4,3,2,1,9,8,7,6,0};
   printf("≈≈–Ú«∞:");
   /******** 1 *********/
   for(i=0;i<n;i++)
	 printf("%4d",a[i]);
   putchar('\n');
   for(i=0;i<N-1;i++) {
	 /***** 2 ******/
     min=0;
     for(j=i+1;j<N;j++)
       /****** 3 ******/
       if(a[j]>a[min]) min=j;
     temp=a[min];a[min]=a[i];a[i]=temp;
   }
   printf("≈≈–Ú∫Û:");
   for(i=0;i<N;i++)printf("%4d",a[i]);
   /****** 4 ********/
   putchar("\n");
}