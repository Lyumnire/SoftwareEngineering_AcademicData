#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <windows.h>
#include "conio.h"

int __FOREGROUND = LIGHTGRAY;
int __BACKGROUND = BLACK;

void _setcursortype(int _type) {
  CONSOLE_CURSOR_INFO Info;
  Info.bVisible = TRUE;
  if (_type == _NOCURSOR)
     Info.bVisible = FALSE;
  else if (_type == _SOLIDCURSOR)
     Info.dwSize = 100;
  else if (_type == _NORMALCURSOR)
     Info.dwSize = 1;
  SetConsoleCursorInfo (GetStdHandle (STD_OUTPUT_HANDLE), &Info);
}

void clreol() {

}

void SetConsoleFont(HANDLE hConsole,  const wchar_t* fontName, SHORT fontSize)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 12;//fontSize;    // 字符宽度  //好像不能随意设置大小，固定设置大的
	cfi.dwFontSize.Y = 16;//fontSize*2;  // 字符高度（通常高度是宽度的2倍）
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, LF_FACESIZE, fontName);
	SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
}

void clrscr() {
  COORD coord;
  DWORD written;
  CONSOLE_SCREEN_BUFFER_INFO info;
  char dotFontName[] = "Consolas";//"Fixedsys"; // 经典点阵字体，也可替换为"Lucida Console"、"Courier New"
  DWORD fontSize = 24;            // 点阵尺寸（12/16/24均支持）
  coord.X = 0;
  coord.Y = 0;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
  FillConsoleOutputCharacter (GetStdHandle(STD_OUTPUT_HANDLE), ' ',
    info.dwSize.X * info.dwSize.Y, coord, &written);
  SetConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), L"Terminal", 12);//Consolas，Terminal，Fixedsys
  SetConsoleOutputCP(437); //设置代码页，=437（英文），=936（简体中文）
  SetConsoleCP(437);	
  SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_OUTPUT | ENABLE_WRAP_AT_EOL_OUTPUT);	
  gotoxy (0, 0);
	
}

int cputs(const char * str) {
  printf ("%s\n", str);
  return 0;
}

int getche() {
  int ch;
  ch = getch ();
  printf ("%c\n", ch);
  return ch;
}

bool ReadKeyPush(KeyValueStru &keyvalue)
  {
    INPUT_RECORD _InRec;
    DWORD _NumRead;

//BOOL WINAPI ReadConsoleInput(
//  _In_  HANDLE        hConsoleInput,		   //控制台输入句柄,由GetStdHandle获得
//  _Out_ PINPUT_RECORD lpBuffer,			   //指向INPUT_RECORD(可以为数组)的指针
//  _In_  DWORD         nLength,			   //接收消息的个数
//  _Out_ LPDWORD       lpNumberOfEventsRead   //用于存储成功获取消息个数的指针
//);
//
    if(!ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE),&_InRec,1,&_NumRead))
       return false;
    if(_InRec.EventType!=KEY_EVENT)
       return false;
    if(_InRec.Event.KeyEvent.bKeyDown == 0)
       return false;
     keyvalue.VKey   = _InRec.Event.KeyEvent.wVirtualKeyCode;
     keyvalue.SCode  = _InRec.Event.KeyEvent.wVirtualScanCode;     
     keyvalue.AscChar= _InRec.Event.KeyEvent.uChar.AsciiChar;
     return true;
  }

KeyValueStru kbhit()
{
  KeyValueStru KeyValue;
  while (TRUE)
   {
    if(ReadKeyPush(KeyValue)) 
      return(KeyValue);
   }
}

void gettextinfo(struct text_info *info) {
  CONSOLE_SCREEN_BUFFER_INFO _Info;
  GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &_Info);
  info->winleft = _Info.srWindow.Left;
  info->winright = _Info.srWindow.Right;
  info->wintop = _Info.srWindow.Top;
  info->winbottom = _Info.srWindow.Bottom;
  info->attribute = _Info.wAttributes;
  info->normattr = LIGHTGRAY | BLACK;
/*  info->currmode = ; */ /* What is currmode? */
  info->screenheight = _Info.dwSize.Y;
  info->screenwidth = _Info.dwSize.X;
  info->curx = wherex ();
  info->cury = wherey ();
}

void puttext(int left, int top, int right, int bottom, PCHAR_INFO source)
 {
  COORD Corner,dwBufferSize;
  SMALL_RECT MyRect;
  Corner.X=right-left+1;
  Corner.Y=bottom-top+1;
  dwBufferSize.X=0;
  dwBufferSize.Y=0;
  MyRect.Left=left;MyRect.Top=top;
  MyRect.Right=right;MyRect.Bottom=bottom;
  WriteConsoleOutputA(GetStdHandle(STD_OUTPUT_HANDLE),source,Corner,dwBufferSize,&MyRect);
 }

void gettext(int left, int top, int right, int bottom, PCHAR_INFO target)
 {
  COORD Corner,dwBufferSize;
  SMALL_RECT MyRect;
  Corner.X=right-left+1;
  Corner.Y=bottom-top+1;
  dwBufferSize.X=0;
  dwBufferSize.Y=0;
  MyRect.Left=left;
  MyRect.Top=top;
  MyRect.Right=right;
  MyRect.Bottom=bottom;
  ReadConsoleOutputA(GetStdHandle(STD_OUTPUT_HANDLE),target,Corner,dwBufferSize,&MyRect);
 }

void gotoxy(int x, int y) {
  COORD c;
  c.X = x ;
  c.Y = y ;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void gppconio_init() {
  /* Do nothing */
}

void highvideo() {
  if (__FOREGROUND <= BROWN)
     textcolor (__FOREGROUND + 9);
  if (__BACKGROUND <= BROWN)
     textbackground (__BACKGROUND + 9);
}

void insline() {
  printf ("\n");
}

int putch(int ch) {
  printf ("%c", ch);
  return ch;
}

void textattr(int attr) {
  __BACKGROUND = attr >> 4;
  __FOREGROUND = attr & 0x0f;
  SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), attr);
//  printf ("%d\n", text_info.screenheight);
}

void textbackground(int color) {
  __BACKGROUND = color;
  textattr (__BACKGROUND<<4 | __FOREGROUND );
}

void textcolor(int color) {
  __FOREGROUND = color;
  textattr(color | __BACKGROUND << 4);
}

int wherex() {
  CONSOLE_SCREEN_BUFFER_INFO info;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
  return info.dwCursorPosition.X;
}

int wherey() {
  CONSOLE_SCREEN_BUFFER_INFO info;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
  return info.dwCursorPosition.Y - 2;
}

void window(int left, int top, int right, int bottom) {
  SMALL_RECT R;
  R.Left = left;
  R.Top = top;
  R.Right = right;
  R.Bottom = bottom;
  SetConsoleWindowInfo (GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &R);
  gotoxy (left, top);
}
