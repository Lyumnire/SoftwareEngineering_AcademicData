 #include <stdio.h>
 #include <string.h>
 void main()
{  char str[81]; int i,flag;
   /******* 1 ******/
   get(str);
   for(i=0;str[i]!='\0';) {
     flag=tolower(str[i])>='a' && tolower(str[i])<='z';
	 /********* 2 *********/
	 flag=not flag;
	 if(flag) {
	   /******* 3 ********/
	   strcpy(str+i+1,str+i);
	   /******* 4 ********/
	   break;
	 }
	 i++;
   }
   printf("%s\n",str);
}