/*
 1.读文件数据到动态内存区
 2.分析每行的前导空格和字符串
 3.去掉空格，压缩存储
*/
#include <stdio.h>
#include <windows.h>
typedef signed short int ShortInt;
typedef struct MenuAnalyseStru {
	ShortInt        preBlankCount;
	char *          pmenustr;
	struct MenuAnalyseStru *next;
}MenuAnalyse,*pMenuAnalyse;

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
pMenuAnalyse  readFileLine(FILE * fl, char * *pstr);

FILE * OpenDataFile(char * filename) {
	int j;
	char *p;
	FILE *myfile;
	char szFullPath[MAX_PATH];
	GetModuleFileName(NULL, szFullPath, MAX_PATH);
	j = strlen(szFullPath) - 1;
	while (j > 0 && szFullPath[j] != '\\')
		j--;
	p = &szFullPath[j + 1];
	strcpy(p, filename);
	myfile = fopen(szFullPath, "r"); //打开一个用于读取的文本文件
	return myfile;
}

pMenuAnalyse readFileLine(FILE * fl, char * *pstr) {
	long filelen;
	pMenuAnalyse head,tail,p;
	char *pch,*prepch;

	fseek(fl, 0L, SEEK_END);     // 定位到文件末尾
	filelen = ftell(fl);         // 获取文件长度
	fseek(fl, 0L, SEEK_SET);     // 定位到文件开始
	*pstr = (char *)malloc(filelen + 1); //+1处理最后一行的特殊问题
	fread(*pstr, filelen, 1, fl);
	pch = *pstr;
	head = (pMenuAnalyse)malloc(sizeof(MenuAnalyse));
	tail=head;
	head->next = NULL;
	while (pch < *pstr + filelen) { //从头到位扫描
		prepch = pch;
		while ((pch < *pstr + filelen) && (*pch == ' ')) pch++;
		p=(pMenuAnalyse)malloc(sizeof(MenuAnalyse));	
		p->preBlankCount = pch - prepch;//(pch == prepch ? 0 : pch - prepch + 1);
		p->pmenustr = pch;
		tail->next=p;
		tail=p;
		while ((pch < *pstr + filelen) && (*pch != '\n'))
			pch++;
		*pch = '\0';
		if (pch < *pstr + filelen) {
			pch++;
			if (*pch == '\r')
				pch++;
		}
	}
	tail->next =NULL;
	return head;
}
void visitMenu(pMenuAnalyse head){
	pMenuAnalyse p;
	p=head->next;
    while(p!=NULL){
	 printf("空格数:%d  层:%d 字符串:%s\n", p->preBlankCount ,(p->preBlankCount+2)/4, p->pmenustr);
		p=p->next;
	}
return;
}

int main() {
	FILE * datafile;
	char * pmenustr;
    pMenuAnalyse head;
	datafile = OpenDataFile("turboC.txt");
	if ( datafile == NULL ) {
		fprintf( stdout, "文件名错误!\n" );
		exit(0);
	}
	head=readFileLine(datafile, &pmenustr);
	fclose(datafile);
	visitMenu(head);
	free(pmenustr);
	getchar();
}
