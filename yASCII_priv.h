/*============================----beg-of-source---============================*/
#ifndef yASCII_priv
#define yASCII_priv yes



/*===[[ GNU GENERAL PUBLIC LICENSE (GPL) ]]===================================*/
/*´´·········1·········2·········3·········4·········5·········6·········7·········8  */

#define  P_COPYRIGHT   \
   "copyright (c) 2020 robert.s.heatherly at balsashrike at gmail dot com"

#define  P_LICENSE     \
   "the only place you could have gotten this code is my github, my website,¦"   \
   "or illegal sharing. given that, you should be aware that this is GPL licensed."

#define  P_COPYLEFT    \
   "the GPL COPYLEFT REQUIREMENT means any modifications or derivative works¦"   \
   "must be released under the same GPL license, i.e, must be free and open."

#define  P_INCLUDE     \
   "the GPL DOCUMENTATION REQUIREMENT means that you must include the original¦" \
   "copyright notice and the full licence text with any resulting anything."

#define  P_AS_IS       \
   "the GPL NO WARRANTY CLAUSE means the software is provided without any¦"      \
   "warranty and the author cannot be held liable for damages."

#define  P_THEFT    \
   "if you knowingly violate the spirit of these ideas, i suspect you might¦"    \
   "find any number of freedom-minded hackers may take it quite personally ;)"

/*´´·········1·········2·········3·········4·········5·········6·········7·········8  */
/*===[[ GNU GENERAL PUBLIC LICENSE (GPL) ]]===================================*/



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
#define     P_VERMINOR  "3.1-, stable for ouroboros"
#define     P_VERNUM    "3.1f"
#define     P_VERTXT    "yascii__line unit_tested"
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
#include    <math.h>              /* clibc  standard math handling            */
/*---(custom core)-----------------------*/
#include    <yURG.h>              /* heatherly urgent processing              */
#include    <yLOG.h>              /* heatherly program logging                */
#include    <ySTR.h>              /* heatherly string processing              */
#include    <yDLST_solo.h>        /* heatherly dlist constants                */
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
   char        d_titles;
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

char        yascii__unit_quiet      (void);
char        yascii__unit_loud       (void);
char        yascii__unit_end        (void);



/*===[[ yASCII_draw.c ]]======================================================*/
/*········´ ´···············exist·´ ´·········································*/
char        yASCII_new              (int a_horz, int a_vert);
char        yASCII_clear            (void);
char        yASCII_free             (void);
/*········´ ´··············config·´ ´·········································*/
char        yascii__heaviness       (char a_heavy, char *r_left, char *r_topp, char *r_righ, char *r_bott);
char        yASCII_grid_set_full    (char a_size, char a_decor, short x_left, short y_topp);
char        yASCII_grid_set         (char a_size, char a_decor, char a_col, char a_row);
char        yASCII_style            (char a_size, char a_decor);
char        yASCII_grid_new_custom  (char a_size, char a_decor, char a_col, char a_row, char a_left, char a_righ, char a_topp, char a_bott, int a_wide, int a_tall);
char        yASCII_grid_new_full    (char a_size, char a_decor, char a_col, char a_row, char a_left, char a_righ, char a_topp, char a_bott);
char        yASCII_grid_new         (char a_size, char a_decor, char a_col, char a_row);
/*········´ ´················exim·´ ´·········································*/
char        yASCII_write            (char a_name [LEN_PATH]);
/*········´ ´···············chars·´ ´·········································*/
char        yASCII_get              (int x, int y);
char        yASCII_single           (int x, int y, char a_new);
char        yASCII_single_dos       (int c, int x, int y, char a_new, char a_alt);
char        yASCII_print            (int x, int y, char a_text [LEN_RECD], char a_mode);
char        yASCII_printw           (int x, int y, int a_wide, int a_tall, char a_text [LEN_RECD], char a_mode);
char        yASCII_connector        (short bx, short by, char a_dir, short ex, short ey, char a_heavy, char a_label [LEN_LABEL], short lx, short ly);
char        yASCII_uconnect         (short bx, short by, char a_dir, short ex, short ey);
char        yascii__line            (char a_dir, char a_beg, short a_bx, short a_by, char a_line, short a_ex, short a_ey, char a_end);
char        yASCII_line             (char a_path [LEN_SHORT], char a_heavy, char a_bef, short a_bx, short a_by, short a_vx, short a_vy, short a_ex, short a_ey, char a_aft, char a_seg, char a_align [LEN_SHORT], char a_label [LEN_LABEL]);
/*········´ ´···············boxes·´ ´·········································*/
char        yascii__outline         (char a_heavy, short x, short y, short w, short t, char a_mode);
char        yASCII_box_full         (char a_heavy, char a_arrange, short x, short y, short w, short t, char a_title [LEN_TITLE], char a_note [LEN_SHORT], char a_block, char a_npred, char a_nsucc);
char        yASCII_box_simple       (char a_col, char a_row, char a_title [LEN_TITLE]);
char        yASCII_node             (short x, short y, char a);
char        yASCII_node_grid         (char a_col, char a_row, char a);
/*········´ ´················data·´ ´·········································*/
char        yascii_box__clear       (void);
char        yascii_box_find         (char a_title [LEN_TITLE]);
char*       yascii_box_entry        (char a_dir);
/*········´ ´·············connect·´ ´·········································*/
char        yASCII_tie_heavy        (char a_heavy);
char        yASCII_tie_full         (char a_heavy, short bx, short by, short ex, short ey, char a_tall, char a_blane, char a_vlane, char a_elane);
char        yASCII_tie_grid_heavy   (char a_heavy, char a_bcol, char a_brow, char a_ecol, char a_erow);
char        yASCII_tie_grid         (char a_bcol, char a_brow, char a_ecol, char a_erow);
char        yASCII_tie_exact_heavy  (char a_heavy, char a_bcol, char a_brow, char a_ecol, char a_erow, char a_blane, char a_vlane, char a_elane);
char        yASCII_tie_exact        (char a_bcol, char a_brow, char a_ecol, char a_erow, char a_blane, char a_vlane, char a_elane);
/*········´ ´················link·´ ´·········································*/
char        yascii_link__defense    (short a_bx, short a_by, char a_btype, short a_vx, short a_ex, short a_ey, char a_etype);
char        yascii_link__detail     (char a_heavy, short a_bx, short a_by, char a_bbase [LEN_SHORT], short a_vx, short a_ex, short a_ey, char a_ebase [LEN_SHORT]);
char        yascii_link__ranges     (char a_end, char a_lane, char a_max, char *r_base);
char        yASCII_link_full        (char a_pred [LEN_TITLE], char a_succ [LEN_TITLE], char a_heavy, char a_hgap, char a_blane, char a_vlane, char a_elane);
/*········´ ´···········specialty·´ ´·········································*/
char        yascii_vertical         (short x, short yt, short yh, short yb);
char        yASCII_frame_full       (char a_bcol, char a_brow, char a_ecol, char a_erow, char a_title [LEN_TITLE], char a_1col, char a_1head [LEN_TITLE], char a_2col, char a_2head [LEN_TITLE], char a_3col, char a_3head [LEN_TITLE], char a_4col, char a_4head [LEN_TITLE]);
char        yASCII_frame            (char a_bcol, char a_brow, char a_ecol, char a_erow, char a_title [LEN_TITLE]);
char        yASCII_bound            (char a_type, char a_heavy, char a_bcol, char a_brow, char a_ecol, char a_erow);
/*········´ ´············unittest·´ ´·········································*/
char*       DRAW__unit              (char *a_question, int n);
/*········´ ´················DONE·´ ´·········································*/



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


char        yascii__heaviness       (char a_heavy, char *r_left, char *r_topp, char *r_righ, char *r_bott);
char        yascii__outline         (char a_heavy, short x, short y, short w, short t, char a_mode);


#endif

