/*============================----beg-of-source---============================*/
#ifndef yASCII_priv
#define yASCII_priv yes


/*===[[ HEADER BEG ]]=========================================================*/
/*                      ´·········1·········2·········3·········4·········5·········6·········7*/
/*--------- 12345678901 ´123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/
/*········· ··········· ´·····························´········································*/
#define     P_NAME      "yASCII"
/*········· ··········· ´·····························´········································*/
#define     P_FOCUS     "RS (run-time support)"
#define     P_NICHE     "us (user control)"
#define     P_SUBJECT   "ascii font and art creation"
#define     P_PURPOSE   "provide clear, simple ascii font and art usage across programs"
/*········· ··········· ´·····························´········································*/
#define     P_NAMESAKE  "angelia-minyma (message)"
#define     P_PRONOUNCE ""
#define     P_TERSE     "embodiment of the gods communications"
#define     P_HERITAGE  "daimona, message personified, daughter of the god hermes"
#define     P_BRIEFLY   ""
#define     P_IMAGERY   "beautiful young woman with graceful wings and feathers in her hair"
#define     P_REASON    "this library is about editing source/messages"
/*········· ··········· ´·····························´········································*/
#define     P_ONELINE   P_NAMESAKE " " P_SUBJECT
/*········· ··········· ´·····························´········································*/
#define     P_HOMEDIR   "/home/system/yASCII.ascii_fonts_and_art"
#define     P_BASENAME  "yASCII"
#define     P_FULLNAME  "/usr/local/lib64/libyASCII"
#define     P_SUFFIX    "···"
#define     P_CONTENT   "···"
/*········· ··········· ´·····························´········································*/
#define     P_SYSTEM    "gnu/linux   (powerful, ubiquitous, technical, and hackable)"
#define     P_LANGUAGE  "ansi-c      (wicked, limitless, universal, and everlasting)"
#define     P_COMPILER  "gcc 11.3.0"
#define     P_CODESIZE  "large       (appoximately 10,000 slocl)"
/*········· ··········· ´·····························´········································*/
#define     P_DEPSTDC   "stdio,stdlib,string"
#define     P_DEPGRAPH  "···"
#define     P_DEPCORE   "yURG,yLOG,ySTR"
#define     P_DEPVIKEYS ""
#define     P_DEPOTHER  "···"
#define     P_DEPSOLO   "···"
/*········· ··········· ´·····························´········································*/
#define     P_AUTHOR    "heatherlyrobert"
#define     P_CREATED   ""
/*········· ··········· ´·····························´········································*/
#define     P_VERMAJOR  "3.--, extracted from ySTR to simplify and target"
#define     P_VERMINOR  "3.0-, get up and working"
#define     P_VERNUM    "3.0f"
#define     P_VERTXT    "mayan added a small, configurable line connector"
/*········· ··········· ´·····························´········································*/
#define     P_PRIORITY  "direct, simple, brief, vigorous, and lucid (h.w. fowler)"
#define     P_PRINCIPAL "[grow a set] and build your wings on the way down (r. bradbury)"
#define     P_REMINDER  "there are many better options, but i *own* every byte of this one"
/*········· ··········· ´·····························´········································*/
/*--------- 12345678901 ´123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/
/*                      ´·········1·········2·········3·········4·········5·········6·········7*/
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


/*===[[ yASCII_base.c ]]======================================================*/
/*··········>·······················>·········································*/
char        yascii__unit_quiet      (void);
char        yascii__unit_loud       (void);
char        yascii__unit_end        (void);


/*===[[ yASCII_font.c ]]======================================================*/
/*··········>·······················>·········································*/
char        yASCII_font             (char a_font [LEN_LABEL], int *r_wide, int *r_tall);
char        yascii_font__index      (char a_range, int a_letter);
int         yascii_font__addltr     (char a_ltr);
int         yascii_font__addrow     (char *a_text, char a_gap, int x, int y, char a_mode);
char        yASCII_display          (char a_font [LEN_LABEL], char *a_text, char a_gap, int x, int y, int *a_wide, int *a_tall, char a_mode);
char        yascii_oneline          (char *a_text, int x, int y, char a_mode);
char        yASCII_wrapping         (char *a_text, int x, int y, int *a_wide, int *a_tall, char a_mode);
char*       yascii__font_unit       (char *a_question, int a_num);


/*===[[ yASCII_font.c ]]======================================================*/
/*··········>·······················>·········································*/
char        yascii__getlang         (char a_iso [LEN_SHORT], char r_name [LEN_LABEL]);



/*===[[ yASCII_mayan.c ]]=====================================================*/
/*··········>·······················>·········································*/
/*---(data)---------------------------*/
/*> char        yascii_mayan__cdata     (char a_size, char a_char, char a_orient, char a_variant, short *r_left, short *r_topp, char *r_wide, char *r_tall);                                            <* 
 *> char        yascii_mayan__vdata     (char a_size, char a_char, char a_part, char a_orient, char a_variant, short *r_left, short *r_topp, char *r_wide, char *r_tall, char *r_xoff, char *r_yoff);   <*/
/*---(glyphs)-------------------------*/
/*> char        yascii_mayan__display   (short x, short y, char a_type, short a_left, short a_topp, char a_wide, char a_tall, char a_mode);                                                                                               <* 
 *> char        yascii_mayan__normal    (char a_orient, char a_cons, char a_cvariant, char a_vowel, char a_vvariant, int x, int y, char a_mode);                                                                                          <* 
 *> char        yascii_mayan__prefix    (char a_orient, char a_prefix, char a_pvariant, char a_cons, char a_cvariant, char a_vowel, char a_vvariant, int x, int y, char a_mode);                                                          <* 
 *> char        yascii_mayan__suffix    (char a_orient, char a_cons, char a_cvariant, char a_vowel, char a_vvariant, char a_suffix, char a_svariant, int x, int y, char a_mode);                                                          <* 
 *> char        yascii_mayan__conjuct   (int a_len, char a_vowel, int x, int y, char a_mode);                                                                                                                                             <* 
 *> char        yascii_mayan__glyph     (char a_part, char a_full [LEN_TERSE], char a_text [LEN_TERSE], char a_diagram [LEN_TERSE], char a_orient [LEN_TERSE], char a_variant [LEN_TERSE], int x, int y, char a_ornament, char a_mode);   <*/
/*---(words)--------------------------*/
/*> char        yascii_mayan__diagram   (char b_text [LEN_TERSE], char r_diagram [LEN_TERSE], char b_orient [LEN_TERSE], char b_variant [LEN_TERSE], char *r_break);                                  <* 
 *> char        yascii_mayan__word      (char a_word [LEN_TERSE], char a_meaning [LEN_LABEL], char a_orient [LEN_TERSE], char a_variant [LEN_TERSE], int *x, int *y, char a_ornament, char a_mode);   <*/
/*---(drivers)------------------------*/
/*> char        yascii_mayan__sizer     (char a_size, char a_gapping, char a_ornament, char *r_wide, char *r_tall, char *r_left, char *r_topp);                                                                                                                        <* 
 *> char        yascii_mayan_driver     (char a_size, char b_words [LEN_RECD], char b_meaning [LEN_RECD], char b_orient [LEN_RECD], char b_variant [LEN_RECD], int x, int y, char a_layout, char a_gapping, int *a_wide, int *a_tall, char a_ornament, char a_mode);   <*/
/*---(done)---------------------------*/


#endif

