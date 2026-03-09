#include <stdio.h>
void main()
{  char s1[80],s2[40]; int j;
   /***** 1 *****/
   int i;
   printf("Input the first string:");
   gets(s1);
   printf("Input the second string:");
   gets(s2);
   /********** 2********/
   while(s1[i]!=0)
	 i++;
   for(j=0;s2[j]!='\0';j++) 
	 /****** 3 ******/
	 s1[j]=s2[j];
   /******* 4 *******/
   s1[i+j]=\0;
   puts(s1);
}