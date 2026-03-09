 #include <stdio.h>
 void main()
{ /******** 1 *******/
  char a[7]='a2汉字';
  int i,j,k;
  /******** 2 *******/
  for(i=0;i<strlen(a);i++) {
	printf("a[%d]的机内码为：",i);
    for(j=1;j<=8;j++) {
      k=a[i]&0x80;
	  if(k!=0) putchar('1');
	  /****** 3 *****/
	  else putchar(0);
      /****** 4 *****/
	  a[i]=a[i]>>1;
	}
	printf("\n");
  }
}