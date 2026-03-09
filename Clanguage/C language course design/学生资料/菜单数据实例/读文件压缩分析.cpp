/*
 1.读文件数据到动态内存区
 2.分析每行的前导空格和字符串
 3.去掉空格，压缩存储
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;
typedef signed short int ShortInt;
typedef struct MenuAnalyseStru {
	ShortInt        preBlankCount;
	char *          pmenustr;
};

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
void   readFileLine(FILE * fl, char * &pstr,vector <MenuAnalyseStru> &menus);
void   printMenuString(vector <MenuAnalyseStru> &menus);

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

void readFileLine(FILE * fl, char * &pstr,vector <MenuAnalyseStru> &menus) {
	long filelen;
	MenuAnalyseStru menuitem;
	char *pscan;   //当前扫描指针
	char *prescan; //pascan前地址
	char *strstart;//有效串开始地址
	char *pcollect;//收集指针

	fseek(fl, 0L, SEEK_END);     // 定位到文件末尾
	filelen = ftell(fl)+1;         // 获取文件长度
	fseek(fl, 0L, SEEK_SET);     // 定位到文件开始
	pstr = (char *)malloc(filelen); //+1处理最后一行的特殊问题
	fread(pstr, filelen, 1, fl);
	*(pstr+filelen-1)='\n';//文件尾强制放结束，以防不存在
	pscan = pstr;
	pcollect =pstr;
	while (pscan < pstr + filelen) { //从头到位扫描
		prescan = pscan;
		while ((pscan < pstr + filelen) && (*pscan == ' ')) pscan++;
		menuitem.preBlankCount = pscan - prescan;
		menuitem.pmenustr = pcollect;//串存放位置
		strstart=pscan;//菜单串开始地址
		while ((pscan < pstr + filelen) && (*pscan != '\n'))
			pscan++;
		*pscan = '\0';//菜单串尾
		for(int i=0;i<=pscan-strstart;i++,pcollect++){//搬移字符串
			*pcollect=strstart[i];
		}
		
		if (pscan < pstr + filelen) {
			pscan++;
			if (*pscan == '\r')
				pscan++;
		}
		menus.push_back(menuitem);  //加入向量中保存
	}
	filelen=pcollect-pstr+1;
    realloc(pstr,filelen);//调整大小，释放多余空间：有异常
}
void   printMenuString(vector <MenuAnalyseStru> &menus){
	for (int i = 0; i < menus.size(); i++) //遍历向量中数据
		cout <<"空格数:"<< menus[i].preBlankCount <<"  层："<<(menus[i].preBlankCount+2)/4<< " 字符串:" << menus[i].pmenustr << endl;	
}

int main() {
	FILE * datafile;
	char * pmenustr;
	vector <MenuAnalyseStru> menus;
	datafile = OpenDataFile("TurboC.txt");
	if ( datafile == NULL ) {
		fprintf( stdout, "文件名错误!\n" );
		exit(0);
	}
	readFileLine(datafile, pmenustr,menus);
	fclose(datafile);
	printMenuString(menus);	
	menus.clear();		
	free(pmenustr);	//有异常
	getchar();
}
