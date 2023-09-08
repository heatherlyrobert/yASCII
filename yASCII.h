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

/*··········>·······················>·········································*/
char*       yASCII_version          (void);
char        yASCII_font             (char a_font [LEN_LABEL], int *r_wide, int *r_tall);
char        yASCII_display          (char a_font [LEN_LABEL], char *a_text, char a_gap, int x, int y, int *a_wide, int *a_tall, char a_mode);
char        yASCII_wrapping         (char *a_text, int x, int y, int *a_wide, int *a_tall, char a_mode);


#endif
/*============================----end-of-source---============================*/
