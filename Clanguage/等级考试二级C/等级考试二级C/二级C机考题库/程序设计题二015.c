 #include <stdio.h>
 #include <math.h>
 /****考生在以下空白处写入执行语句 编写函数f判断与形参相应的实参是否素数****/





 /*****考生在以上空白处编写函数f *************/
 #include <math.h>
 void main()
{  FILE *fp; int i; long s=0,k=0;
   /****考生在以下空白处写入执行语句******/

 
 
   /****考生在以上空白处写入执行语句******/
   printf("素数个数%d   素数总和%d\n",k,s);
   fp=fopen("CD2.dat","wb");
   fwrite(&k,4,1,fp);fwrite(&s,4,1,fp);
   fclose(fp);
}
