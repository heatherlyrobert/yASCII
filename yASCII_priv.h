/*============================----beg-of-source---============================*/
#ifndef yASCII_priv
#define yASCII_priv yes


/*===[[ HEADER BEG ]]=========================================================*/
/*                      ┤иииииииии1иииииииии2иииииииии3иииииииии4иииииииии5иииииииии6иииииииии7*/
/*--------- 12345678901 ┤123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/
/*иииииииии иииииииииии ┤иииииииииииииииииииииииииииии┤ииииииииииииииииииииииииииииииииииииииии*/
#define     P_NAME      "yASCII"
/*иииииииии иииииииииии ┤иииииииииииииииииииииииииииии┤ииииииииииииииииииииииииииииииииииииииии*/
#define     P_FOCUS     "RS (run-time support)"
#define     P_NICHE     "us (user control)"
#define     P_SUBJECT   "ascii font and art creation"
#define     P_PURPOSE   "provide clear, simple ascii font and art usage across programs"
/*иииииииии иииииииииии ┤иииииииииииииииииииииииииииии┤ииииииииииииииииииииииииииииииииииииииии*/
#define     P_NAMESAKE  "angelia-minyma (message)"
#define     P_PRONOUNCE ""
#define     P_TERSE     "embodiment of the gods communications"
#define     P_HERITAGE  "daimona, message personified, daughter of the god hermes"
#define     P_BRIEFLY   ""
#define     P_IMAGERY   "beautiful young woman with graceful wings and feathers in her hair"
#define     P_REASON    "this library is about editing source/messages"
/*иииииииии иииииииииии ┤иииииииииииииииииииииииииииии┤ииииииииииииииииииииииииииииииииииииииии*/
#define     P_ONELINE   P_NAMESAKE " " P_SUBJECT
/*иииииииии иииииииииии ┤иииииииииииииииииииииииииииии┤ииииииииииииииииииииииииииииииииииииииии*/
#define     P_HOMEDIR   "/home/system/yASCII.ascii_fonts_and_art"
#define     P_BASENAME  "yASCII"
#define     P_FULLNAME  "/usr/local/lib64/libyASCII"
#define     P_SUFFIX    "иии"
#define     P_CONTENT   "иии"
/*иииииииии иииииииииии ┤иииииииииииииииииииииииииииии┤ииииииииииииииииииииииииииииииииииииииии*/
#define     P_SYSTEM    "gnu/linux   (powerful, ubiquitous, technical, and hackable)"
#define     P_LANGUAGE  "ansi-c      (wicked, limitless, universal, and everlasting)"
#define     P_COMPILER  "gcc 11.3.0"
#define     P_CODESIZE  "large       (appoximately 10,000 slocl)"
/*иииииииии иииииииииии ┤иииииииииииииииииииииииииииии┤ииииииииииииииииииииииииииииииииииииииии*/
#define     P_DEPSTDC   "stdio,stdlib,string"
#define     P_DEPGRAPH  "иии"
#define     P_DEPCORE   "yURG,yLOG,ySTR"
#define     P_DEPVIKEYS ""
#define     P_DEPOTHER  "иии"
#define     P_DEPSOLO   "иии"
/*иииииииии иииииииииии ┤иииииииииииииииииииииииииииии┤ииииииииииииииииииииииииииииииииииииииии*/
#define     P_AUTHOR    "heatherlyrobert"
#define     P_CREATED   ""
/*иииииииии иииииииииии ┤иииииииииииииииииииииииииииии┤ииииииииииииииииииииииииииииииииииииииии*/
#define     P_VERMAJOR  "3.--, extracted from ySTR to simplify and target"
#define     P_VERMINOR  "3.1-, stable for ouroboros"
#define     P_VERNUM    "3.1c"
#define     P_VERTXT    "more debugging in draw"
/*иииииииии иииииииииии ┤иииииииииииииииииииииииииииии┤ииииииииииииииииииииииииииииииииииииииии*/
#define     P_PRIORITY  "direct, simple, brief, vigorous, and lucid (h.w. fowler)"
#define     P_PRINCIPAL "[grow a set] and build your wings on the way down (r. bradbury)"
#define     P_REMINDER  "there are many better options, but i *own* every byte of this one"
/*иииииииии иииииииииии ┤иииииииииииииииииииииииииииии┤ииииииииииииииииииииииииииииииииииииииии*/
/*--------- 12345678901 ┤123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/
/*                      ┤иииииииии1иииииииии2иииииииии3иииииииии4иииииииии5иииииииии6иииииииии7*/
/*===[[ HEADER END ]]=========================================================*/



/*---(ansi-c standard)-------------------*/
#include    <stdio.h>             /* clibc  standard input/output             */
#include    <stdlib.h>            /* clibc  standard general purpose          */
#include    <string.h>            /* clibc  standard string handling          */
/*---(custom core)-----------------------*/
#include    <yURG.h>              /* heatherly urgent processing              */
#include    <yLOG.h>              /* heatherly program logging                */
#include    <ySTR.h>              /* heatherly string processing              */
/*---(done)------------------------------*/

#define    YASCII_SHOW_HINT  "yYFe$>"
#define    YASCII_SHOW_TSAE  "YFe$>"
#define    YASCII_SHOW_ENGL  "e$>"
#define    YASCII_SHOW_ROOT  "$>"

#define     MAX_WIDTH     450
#define     MAX_HEIGHT     10

extern char  (*e_displayer)  (int x, int y, char *a_text, char a_mode);
extern char  g_working  [MAX_HEIGHT][LEN_DESC];


extern char   unit_answer [LEN_RECD];


/*===[[ TEST STRUCTURE ]]=====================================================*/
typedef struct cASCII tASCII;
struct cASCII {
   /*---(overall)-----------*/
   char        d_size;
   char        d_names;
   char        d_notes;
   char        d_blocks;
   char        d_counts;
   /*---(heavy)-------------*/
   char        d_box;
   char        d_tie;
   char        d_bound;
   /*---(horz/x)------------*/
   int         x_left;
   char        x_wide;
   char        x_side;
   char        x_gap;
   int         x_max;
   /*---(vert/y)------------*/
   int         y_topp;
   char        y_tall;
   char        y_side;
   char        y_gap;
   int         y_max;
   /*---(done)--------------*/
};
extern tASCII   myASCII;

/*===[[ yASCII_base.c ]]======================================================*/
/*ииииииииии>иииииииииииииииииииииии>иииииииииииииииииииииииииииииииииииииииии*/
char        yascii__unit_quiet      (void);
char        yascii__unit_loud       (void);
char        yascii__unit_end        (void);


/*===[[ yASCII_font.c ]]======================================================*/
/*ииииииииии>иииииииииииииииииииииии>иииииииииииииииииииииииииииииииииииииииии*/
char        yASCII_font             (char a_font [LEN_LABEL], int *r_wide, int *r_tall);
char        yascii_font__index      (char a_range, int a_letter);
int         yascii_font__addltr     (char a_ltr);
int         yascii_font__addrow     (char *a_text, char a_gap, int x, int y, char a_mode);
char        yASCII_display          (char a_font [LEN_LABEL], char *a_text, char a_gap, int x, int y, int *a_wide, int *a_tall, char a_mode);
char        yascii_oneline          (char *a_text, int x, int y, char a_mode);
char        yASCII_wrapping         (char *a_text, int x, int y, int *a_wide, int *a_tall, char a_mode);
char*       yascii__font_unit       (char *a_question, int a_num);


/*===[[ yASCII_font.c ]]======================================================*/
/*ииииииииии>иииииииииииииииииииииии>иииииииииииииииииииииииииииииииииииииииии*/
char        yascii__getlang         (char a_iso [LEN_SHORT], char r_name [LEN_LABEL]);


char        yascii__heaviness       (char a_heavy, char *r_left, char *r_topp, char *r_righ, char *r_bott);
char        yascii__outline         (char a_heavy, short x, short y, short w, short t, char a_mode);


#endif

