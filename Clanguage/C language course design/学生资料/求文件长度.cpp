#include <stdio.h>
#include <windows.h>
/*
参数：filename文件名，相对路径（相对于执行文件所在目录）表示，即把数据文件与执行文件放在同一目录即可
返回：打开文件失败返回NULL,否则非NULL
*/
FILE * OpenDataFile(char * filename) ;
/*
参数：fl         文件指针
pMainMenu  菜单实例（多叉树）的根结点指针
sysMenuStr 文件数据的首地址
返回：打开文件失败返回NULL,否则非NULL
*/

FILE * OpenDataFile(char * filename) 
{
	int j;
	char *p;
	FILE *myfile;
	char szFullPath[MAX_PATH];
	GetModuleFileName(NULL,szFullPath,MAX_PATH);
	j=strlen(szFullPath)-1;
	while(j>0 && szFullPath[j]!='\\')
		j--;
	p=&szFullPath[j+1];
	strcpy(p,filename);
	myfile=fopen(szFullPath,"r"); //打开一个用于读取的文本文件
	return myfile;
}

int main(){
	FILE * datafile;
	long filelen;
	datafile=OpenDataFile("turboC.txt");//跟执行文件放一块
	if( datafile == NULL )
	{fprintf( stdout, "文件名错误!\n" );
		exit(0);
	}
	fseek(datafile,0L,SEEK_END);       // 定位到文件末尾
	filelen=ftell(datafile);           // 获取文件长度 
	fseek(datafile,0L,SEEK_SET);       // 定位到文件开始 
	fclose(datafile);
	printf("\n文件长度：%ld",filelen);
	getchar();
}
