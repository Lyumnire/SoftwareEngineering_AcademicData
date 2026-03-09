 #include <stdio.h>
 void main()
{  FILE *fp; long i=1;
   /****考生在以下空白处写入执行语句 ******/


 
 
 
   /****考生在以上空白处写入执行语句 ******/
   printf("%d\n",i);
   fp=fopen("CD1.dat","wb");
   fwrite(&i,4,1,fp);
   fclose(fp);
}