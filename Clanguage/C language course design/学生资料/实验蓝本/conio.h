#ifndef CONIO_H
#define CONIO_H

#include <windows.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef struct KeyValueStru{
       WORD  VKey;      //Ðé¼ü
       WORD  SCode;     //É¨ÃèÂë
	   CHAR  AscChar;   //Ascii
 }KeyValueStru;

struct text_info {
    unsigned char winleft;
    unsigned char wintop;
    unsigned char winright;
    unsigned char winbottom;
    unsigned char attribute;
    unsigned char normattr;
    unsigned char currmode;
    unsigned char screenheight;
    unsigned char screenwidth;
    unsigned char curx;
    unsigned char cury;
};

enum COLORS {
    /*  dark colors     */
    BLACK,          
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    /*  light colors    */
    DARKGRAY, /* "light black" */
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};

#define BLINK   0x80    /*  blink bit; doesn't work yet  */

#define _NOCURSOR      0
#define _SOLIDCURSOR   1
#define _NORMALCURSOR  2

/* 19 of 31 functions implemented, 62% */

//int _conio_kbhit();
KeyValueStru kbhit();
void _set_screen_lines(int nlines);
void _setcursortype(int type);                                                 /* done */
void blinkvideo();
char *cgets(char *str);                                                        /* how does it work? */
void clreol();                                                                  /* what does it do? */
void clrscr();                                                                  /* done */
#define cprintf printf                                                          /* done */
int  cputs(const char *str);                                                   /* done */
#define cscanf scanf                                                            /* done */
void delline();
#define getch getchar                                                           /* done */
int  getche();                                                                  /* done */
void gettext(int left, int top, int right, int bottom, PCHAR_INFO target);
void gettextinfo(struct text_info *info);                                         /* done */
void gotoxy(int x, int y);                                                      /* done */
void gppconio_init();                                                           /* done; does nothing */
void highvideo();                                                               /* maybe */
void insline();                                                                 /* done */
void intensevideo();
void lowvideo();
int  movetext(int left, int top, int right, int bottom,
             int destleft, int desttop);
void normvideo();
int  putch(int ch);                                                             /* done */
void puttext(int left, int top, int right, int bottom, PCHAR_INFO source);
void textattr(int attr);                                                       /* done */
void textbackground(int color);                                                /* done */
void textcolor(int color);                                                     /* done */
void textmode(int mode);
int  ungetch(int);
int  wherex();                                                                  /* done */
int  wherey();                                                                  /* done */
void window(int left, int top, int right, int bottom);                      /* done */
	
#ifdef __cplusplus
}
#endif

#endif // CONIO_H
