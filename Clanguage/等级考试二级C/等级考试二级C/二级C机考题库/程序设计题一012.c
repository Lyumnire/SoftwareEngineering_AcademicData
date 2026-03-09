 #include <stdio.h>
 #include <math.h>
 void main()
{  FILE *fp; int i;
   /****考生在以下空白处写入语句 ******/


 
   /****考生在以上空白处写入语句 ******/
   printf("%.10f\n",y);
   fp=fopen("CD1.dat","wb");
   fwrite(&y,8,1,fp);
   fclose(fp);
}