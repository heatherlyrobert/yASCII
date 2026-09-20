/*============================----beg-of-source---============================*/
#ifndef yASCII
#define yASCII yes



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



#include   <ySTR_solo.h>

typedef  unsigned char        uchar;

#define     YASCII_FULL      'f'       /* [a-z][0-9] */
#define     YASCII_ALPHA     'a'       /* [a-z]      */
#define     YASCII_NUMS      'n'       /* [0-9]      */
#define     YASCII_BINARY    'b'       /* [0-1]      */
#define     YASCII_MAYANC    'm'       /* [0-1]      */

#define     YASCII_NORMAL    'b'
#define     YASCII_COLOR     'c'

#define     YASCII_USERNAME  'u'
#define     YASCII_TOKEN     't'
#define     YASCII_PASSWORD  'p'

#define     YASCII_INVALID   'I'
#define     YASCII_LOCKED    'L'
#define     YASCII_QUESTIONS '?'
#define     YASCII_RECOVER   '@'
#define     YASCII_DENIED    'D'
#define     YASCII_PASSED    'P'
#define     YASCII_FAILURE   'F'
#define     YASCII_TIMEOUT   'T'
#define     YASCII_REFRESH   'R'
#define     YASCII_CANCEL    'C'
#define     YASCII_DATE      ':'

#define     YASCII_GAPS      'y'
#define     YASCII_NOGAPS    '-'

#define     YASCII_CLEAR     'c'
#define     YASCII_MERGE     'm'
#define     YASCII_FILL      'f'


/*---(size settings)--------*/
#define     YASCII_MICRO     'u'
#define     YASCII_DEFAULT   '-'
#define     YASCII_LARGE     'l'
#define     YASCII_HUGE      'H'


/*---(decor settings)-------*/
#define     YASCII_NONE      '-'
#define     YASCII_NAMES     't'
#define     YASCII_NOTES     'n'
#define     YASCII_COUNTS    'c'
#define     YASCII_MAX       'A'
#define     YASCII_UNIT      'u'


/*---(line weights)---------*/
#define     YASCII_SOLID     '-'
#define     YASCII_DOTTED    'd'
#define     YASCII_LIGHT     'l'
#define     YASCII_WAVY      'w'
#define     YASCII_INSIDE    'i'
#define     YASCII_OUTSIDE   'o'
#define     YASCII_ANCIENT   'a'
#define     YASCII_DOUBLE    '2'


/*---(line arrangement)-----*/
#define     YASCII_BASE      '-'
#define     YASCII_STD       's'
#define     YASCII_BIG       'b'
#define     YASCII_TECH      't'


#define     YASCII_VTOP   't'
#define     YASCII_VUPR   'k'
#define     YASCII_VMID   'm'
#define     YASCII_VLOW   'j'
#define     YASCII_VBOT   'b'

#define     YASCII_HSTR   's'
#define     YASCII_HLEF   'h'
#define     YASCII_HCEN   'c'
#define     YASCII_HRIG   'l'
#define     YASCII_HEND   'e'

#define     YASCII_BOUND  'r'
#define     YASCII_BBOUND 'b'
#define     YASCII_FRAME  'f'
#define     YASCII_BFRAME 'F'


/*··········>·······················>·········································*/
char*       yASCII_version          (void);
char        yASCII_displayer        (void *a_displayer);

/*··········>·······················>·········································*/
char        yASCII_font             (char a_font [LEN_LABEL], int *r_wide, int *r_tall);
char        yASCII_display          (char a_font [LEN_LABEL], char *a_text, char a_gap, int x, int y, int *a_wide, int *a_tall, char a_mode);
char        yASCII_wrapping         (char *a_text, int x, int y, int *a_wide, int *a_tall, char a_mode);

/*··········>·······················>·········································*/
char        yASCII_language         (char a_iso [LEN_SHORT], char r_name [LEN_LABEL]);
char        yASCII_host             (char n, char r_title [LEN_LABEL], char r_host [LEN_LABEL]);
char        yASCII_cluster          (char n, char r_title [LEN_LABEL], char r_cluster [LEN_LABEL]);
char        yASCII_prompt           (char a_style, char a_cluster, char a_host, char r_prompt [LEN_HUND], char r_key [LEN_SHORT]);
char        yASCII_word             (char a_which, char a_word [LEN_DESC]);
char        yASCII_prompt_box       (char a_cluster, char a_host, char a_date [LEN_LABEL], int x, int y);



/*===[[ yASCII_draw.c ]]======================================================*/
/*········· ´······················ ´·········································*/
/*---(exist)----------------*/
char        yASCII_new              (int a_horz, int a_vert);
char        yASCII_clear            (void);
char        yASCII_free             (void);
/*---(config)---------------*/
char        yASCII_grid_new_custom  (char a_size, char a_decor, char a_col, char a_row, char a_left, char a_righ, char a_topp, char a_bott, int a_wide, int a_tall);
char        yASCII_grid_set_full    (char a_size, char a_decor, short x_off, short y_off);
char        yASCII_grid_set         (char a_size, char a_decor, char a_col, char a_row);
char        yASCII_style            (char a_size, char a_decor);
char        yASCII_grid_new_full    (char a_size, char a_decor, char a_col, char a_row, char a_left, char a_righ, char a_topp, char a_bott);
char        yASCII_grid_new         (char a_size, char a_decor, char a_col, char a_row);
/*---(exim)-----------------*/
char        yASCII_write            (char a_name [LEN_PATH]);
/*---(chars)----------------*/
char        yASCII_get              (int x, int y);
char        yASCII_single           (int x, int y, char a_new);
char        yASCII_print            (int x, int y, char a_text [LEN_RECD], char a_mode);
char        yASCII_printw           (int x, int y, int a_wide, int a_tall, char a_text [LEN_RECD], char a_mode);
/*---(boxes)----------------*/
char        yASCII_box_full         (char a_heavy, char a_arrange, short x, short y, short w, short t, char a_title [LEN_TITLE], char a_note [LEN_SHORT], char a_block, char a_npred, char a_nsucc);
char        yASCII_box_grid         (char a_col, char a_row, char a_title [LEN_TITLE], char a_note [LEN_SHORT], char a_block, char a_npred, char a_nsucc);
char        yASCII_box_simple       (char a_col, char a_row, char a_title [LEN_TITLE]);
char        yASCII_node             (short x, short y, char a);
char        yASCII_node_grid        (char a_col, char a_row, char a);
/*---(reporting)------------*/
char        yascii_box_find         (char a_title [LEN_TITLE]);
char*       yascii_box_entry        (char a_dir);
/*---(connect)--------------*/
char        yASCII_tie_heavy        (char a_heavy);
char        yASCII_tie_full         (char a_heavy, short bx, short by, short ex, short ey, char a_tall, char a_blane, char a_vlane, char a_elane);
char        yASCII_tie_grid         (char a_bcol, char a_brow, char a_ecol, char a_erow);
char        yASCII_tie_grid_heavy   (char a_heavy, char a_bcol, char a_brow, char a_ecol, char a_erow);
char        yASCII_tie_exact        (char a_bcol, char a_brow, char a_ecol, char a_erow, char a_blane, char a_vlane, char a_elane);
char        yASCII_tie_exact_heavy  (char a_heavy, char a_bcol, char a_brow, char a_ecol, char a_erow, char a_blane, char a_vlane, char a_elane);
/*---(specialty)------------*/
char        yASCII_frame_full       (char a_bcol, char a_brow, char a_ecol, char a_erow, char a_title [LEN_TITLE], char a_1col, char a_1head [LEN_TITLE], char a_2col, char a_2head [LEN_TITLE], char a_3col, char a_3head [LEN_TITLE], char a_4col, char a_4head [LEN_TITLE]);
char        yASCII_frame            (char a_bcol, char a_brow, char a_ecol, char a_erow, char a_title [LEN_TITLE]);
char        yASCII_bound            (char a_type, char a_heavy, char a_bcol, char a_brow, char a_ecol, char a_erow);
/*---(unittest)-------------*/
char*       DRAW__unit              (char *a_question, int n);
/*---(done)-----------------*/



#endif
/*============================----end-of-source---============================*/
