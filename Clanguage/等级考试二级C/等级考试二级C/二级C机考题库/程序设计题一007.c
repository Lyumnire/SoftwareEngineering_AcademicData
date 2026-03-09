 #include <stdio.h>
 long f(long x)
{  int i,j,y=1;
   for(i=2;i<=x/2;i++)
     if(x%i==0) y=y+i;
   return y;
 }
 void main()
{  FILE *fp; long a,b,c,k=0; 
   /****考生在以下空白处写入执行语句******/

 
 
 
 
 
 
   /****考生在以上空白处写入执行语句******/
   printf("%d\n",k);
   fp=fopen("CD1.dat","wb");
   fwrite(&k,4,1,fp);
   fclose(fp);
 }