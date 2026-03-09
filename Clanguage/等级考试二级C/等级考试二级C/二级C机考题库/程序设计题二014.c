 #include <stdio.h>
 /*****考生在以下空白处编写函数f ******/






 /*****考生在以上空白处编写函数f ******/
 #include <math.h>
 void main()
{  FILE *fp; int i; long k=0;
   for(i=11;i<1000;i++)
	 if(f(i)) { printf("%5d",i);k++; if(k%10==0) putchar('\n');}
   putchar('\n');
   printf("%d\n",k);
   fp=fopen("CD2.dat","wb");
   fwrite(&k,4,1,fp);
   fclose(fp);
}