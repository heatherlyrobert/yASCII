/*============================----beg-of-source---============================*/
#ifndef yASCII
#define yASCII yes

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

char        yASCII_mayan            (char a_size, char *a_text, char a_gap, int x, int y, int *a_wide, int *a_tall, char a_mode);

#endif
/*============================----end-of-source---============================*/
