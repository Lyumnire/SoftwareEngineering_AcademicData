 #include <stdio.h>
 void f(int **a,int m,int n,int *mm,int *nn)
{  int i,j,max=a[0][0];
   /****考生在以下空白处写入语句 ******/

 
 
 
   /****考生在以上空白处写入语句 ******/
 }
 void main()
{  FILE *fp; int ii,jj;
   int b[3][3]={{1,3,4},{2,9,5},{3,7,6}};
   int *c[3]={b[0],b[1],b[2]};
   /****考生在以下空白处写入调用语句 ******/
   


   /****考生在以上空白处写入调用语句 ******/
   printf("最大值为%d，行号%d，列号%d\n",b[ii][jj],ii,jj);
   fp=fopen("CD2.dat","wb");
   fwrite(&ii,4,1,fp); fwrite(&jj,4,1,fp);
   fclose(fp);
}