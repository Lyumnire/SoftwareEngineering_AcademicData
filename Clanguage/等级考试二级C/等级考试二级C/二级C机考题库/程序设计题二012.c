 #include <stdio.h>
 void main()
{  FILE *fp; long x;  int i;
   char a[]="Windows Office 2010";
   /****考生在以下空白处写入执行语句******/

   
   
   
   
   
   /****考生在以上空白处写入执行语句******/
   printf("%d\n",x);
   fp=fopen("CD2.dat","wb");
   fwrite(&x,4,1,fp);
   fclose(fp);
}