#include <stdio.h>
#include <____1_____>
void main()
{  char s[81]; int i;
   _____2_____;
   for(i=0;____3_____;i++) {
	 if(isupper(s[i]))
	   s[i]=s[i]+32;
	 else
       if(islower(s[i]))
	     s[i]=s[i]-32;
	 if(____4____) s[i]='_';
   }
   puts(s);
}