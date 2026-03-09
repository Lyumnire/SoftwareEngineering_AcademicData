 #include <stdio.h>
 void main()
{  FILE *fp; double y=2,f1=1,f2=2,f; int i;
   /****考生在以下空白处写入执行语句 ******/
   




   /****考生在以上空白处写入执行语句 ******/
   printf("%f\n",y);
   fp=fopen("CD1.dat","wb");
   fwrite(&y,8,1,fp);
   fclose(fp);
}