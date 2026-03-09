 #include <stdio.h>
 void main()
{  FILE *fp; long i,a[40]={1,1},s=2;
   /****考生在以下空白处写入执行语句 ******/

 
 
 

   /****考生在以上空白处写入执行语句 ******/
   printf("%d\n",s);
   fp=fopen("CD1.dat","wb");
   fwrite(&s,4,1,fp);
   fclose(fp);
}