/*===[[ START ]]==============================================================*/
#include    "yASCII.h"
#include    "yASCII_priv.h"



static   char  *s_image = NULL;
static   int    s_horz  =   -1;
static   int    s_vert  =   -1;


char
yASCII_print            (int x, int y, char *a_text, char a_mode)
{
   /*---(locals)-----------+-----+-----+-*/
   int         x_len       =    0;
   int         i           =    0;
   char        c           =  '-';
   int         o           =    0;
   int         n           =    0;
   DEBUG_YASCII   yLOG_senter  (__FUNCTION__);
   DEBUG_YASCII   yLOG_sint    (x);
   DEBUG_YASCII   yLOG_sint    (y);
   DEBUG_YASCII   yLOG_snote   (a_text);
   x_len = strlen (a_text);
   DEBUG_YASCII   yLOG_sint    (x_len);
   for (i = 0; i < x_len; ++i) {
      c = a_text [i];
      if (a_mode == YASCII_MERGE && c == ' ')  continue;
      if (x >= s_horz)  continue;
      if (y >= s_vert)  continue;
      o = (y * s_horz) + (x + i);
      DEBUG_YASCII   yLOG_sint    (o);
      s_image [o] = c;
      ++n;
   }
   DEBUG_YASCII   yLOG_sint    (n);
   DEBUG_YASCII   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char
yASCII_connector        (short bx, short by, char a_dir, short ex, short ey, char a_heavy, char a_label [LEN_LABEL], short lx, short ly)
{
   /*---(locals)-----------+-----+-----+-*/
   char        x_dir       =    0;
   int         i           =    0;
   char        x_2nd       =  '·';
   char        x_horz      [LEN_SHORT] =  "€";
   char        x_vert      [LEN_SHORT] =  "";
   char        x_end       =  '·';
   char        t           [LEN_SHORT] =  "·";
   /*---(enter)--------------------------*/
   DEBUG_YASCII   yLOG_senter  (__FUNCTION__);
   /*---(lines)--------------------------*/
   DEBUG_YASCII   yLOG_schar   (a_heavy);
   if (a_heavy == '²') {
      strcpy (x_horz, "²");
      strcpy (x_vert, "Œ");
   } else if (a_heavy == '·') {
      strcpy (x_horz, "·");
      strcpy (x_vert, "·");
   }
   DEBUG_YASCII   yLOG_schar   (x_horz);
   DEBUG_YASCII   yLOG_schar   (x_vert);
   /*---(direction)----------------------*/
   if (bx > ex) {
      if      (by >  ey)  {  x_dir = 1;  if (a_dir == '×') { x_2nd = 'Ô'; x_end = '‰'; }  else { a_dir = 'Ô'; x_2nd = '×'; x_end = '‡'; } }
      else if (by == ey)  {  x_dir = 4;  a_dir = '×';  x_2nd = '´';  x_end = '‡'; }
      else                {  x_dir = 7;  if (a_dir == '×') { x_2nd = 'Õ'; x_end = 'ˆ'; }  else { a_dir = 'Õ'; x_2nd = '×'; x_end = '‡'; } }
   } else if (bx == ex) {
      if      (by >  ey)  {  x_dir = 2;  a_dir = 'Ô';  x_2nd = '´';  x_end = '‰'; }
      else if (by == ey)  {  x_dir = 5;  a_dir = '´';  x_2nd = '´'; }
      else                {  x_dir = 8;  a_dir = 'Õ';  x_2nd = '´';  x_end = 'ˆ'; }
   } else {
      if      (by >  ey)  {  x_dir = 3;  if (a_dir == 'Ö') { x_2nd = 'Ô'; x_end = '‰'; }  else { a_dir = 'Ô'; x_2nd = 'Ö'; x_end = '†'; } }
      else if (by == ey)  {  x_dir = 6;  a_dir = 'Ö';  x_2nd = '´';  x_end = '†'; }
      else                {  x_dir = 9;  if (a_dir == 'Ö') { x_2nd = 'Õ'; x_end = 'ˆ'; }  else { a_dir = 'Õ'; x_2nd = 'Ö'; x_end = '†'; } }
   }
   DEBUG_YASCII   yLOG_sint    (x_dir);
   DEBUG_YASCII   yLOG_schar   (a_dir);
   DEBUG_YASCII   yLOG_schar   (x_2nd);
   /*---(origination)--------------------*/
   yASCII_print (bx, by, "Ï", YASCII_CLEAR); 
   /*---(first segment)------------------*/
   switch (a_dir) {
   case 'Ö' :  for (i = bx + 1; i < ex; ++i)   yASCII_print ( i, by, x_horz, YASCII_CLEAR);    break;
   case '×' :  for (i = bx - 1; i > ex; --i)   yASCII_print ( i, by, x_horz, YASCII_CLEAR);    break;
   case 'Õ' :  for (i = by + 1; i < ey; ++i)   yASCII_print (bx,  i, x_vert, YASCII_CLEAR);    break;
   case 'Ô' :  for (i = by - 1; i > ey; --i)   yASCII_print (bx,  i, x_vert, YASCII_CLEAR);    break;
   }
   /*---(corner)-------------------------*/
   switch (a_dir) {
   case 'Ö' :  if (x_dir == 3)  yASCII_print (ex, by, "…", YASCII_CLEAR);  else if (x_dir == 9)  yASCII_print (ex, by, "‚", YASCII_CLEAR);  break;
   case '×' :  if (x_dir == 1)  yASCII_print (ex, by, "„", YASCII_CLEAR);  else if (x_dir == 7)  yASCII_print (ex, by, "ƒ", YASCII_CLEAR);  break;
   case 'Õ' :  if (x_dir == 7)  yASCII_print (bx, ey, "…", YASCII_CLEAR);  else if (x_dir == 9)  yASCII_print (bx, ey, "„", YASCII_CLEAR);  break;
   case 'Ô' :  if (x_dir == 1)  yASCII_print (bx, ey, "‚", YASCII_CLEAR);  else if (x_dir == 3)  yASCII_print (bx, ey, "ƒ", YASCII_CLEAR);  break;
   }
   /*---(second segment)-----------------*/
   switch (x_2nd) {
   case 'Ö' :  for (i = bx + 1; i < ex; ++i)   yASCII_print ( i, ey, x_horz, YASCII_CLEAR);    break;
   case '×' :  for (i = bx - 1; i > ex; --i)   yASCII_print ( i, ey, x_horz, YASCII_CLEAR);    break;
   case 'Õ' :  for (i = by + 1; i < ey; ++i)   yASCII_print (ex,  i, x_vert, YASCII_CLEAR);    break;
   case 'Ô' :  for (i = by - 1; i > ey; --i)   yASCII_print (ex,  i, x_vert, YASCII_CLEAR);    break;
   }
   /*---(termination)--------------------*/
   sprintf (t, "%c", x_end);
   yASCII_print (ex, ey, t, YASCII_CLEAR); 
   /*---(label)--------------------------*/
   if (a_label != NULL)  yASCII_print (lx, ly, a_label, YASCII_CLEAR);
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char
yASCII_new              (int a_horz, int a_vert)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   int         x_tries     =    0;
   char       *x_new       = NULL;
   /*---(header)-------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YASCII   yLOG_point   ("s_image"   , s_image);
   --rce;  if (s_image != NULL) {
      DEBUG_YASCII   yLOG_note    ("drawing space already created");
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(limits)-------------------------*/
   DEBUG_YASCII   yLOG_complex ("requested" , "%3dx by %3dy", a_horz, a_vert);
   if (a_horz > LEN_RECD)  a_horz = LEN_RECD;
   if (a_vert > LEN_RECD)  a_vert = LEN_RECD;
   DEBUG_YASCII   yLOG_complex ("using"     , "%3dx by %3dy", a_horz, a_vert);
   /*---(malloc)-------------------------*/
   while (x_new == NULL) {
      ++x_tries;
      x_new = (char *) malloc (sizeof (char) * a_vert * a_horz);
      if (x_tries > 10)   break;
   }
   DEBUG_YASCII   yLOG_value   ("x_tries"   , x_tries);
   DEBUG_YASCII   yLOG_point   ("x_new"     , x_new);
   --rce;  if (x_new == NULL) {
      DEBUG_YASCII   yLOG_note    ("drawing space could not be created");
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   DEBUG_YASCII   yLOG_note    ("saving pointer and sizes");
   s_image = x_new;
   s_horz  = a_horz;
   s_vert  = a_vert;
   /*---(clear)--------------------------*/
   yASCII_clear ();
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yASCII_clear            (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   int         x           =    0;
   int         y           =    0;
   int         o           =    0;
   /*---(header)-------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YASCII   yLOG_point   ("s_image"   , s_image);
   --rce;  if (s_image == NULL) {
      DEBUG_YASCII   yLOG_note    ("image space does not exist");
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(clear)--------------------------*/
   for (y = 0; y < s_vert; ++y) {
      DEBUG_YASCII   yLOG_value   ("y"         , y);
      for (x = 0; x < s_horz; ++x) {
         o = y * s_horz + x;
         s_image [o] = ' ';
      }
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yASCII_free             (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   /*---(header)-------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YASCII   yLOG_point   ("s_image"   , s_image);
   --rce;  if (s_image == NULL) {
      DEBUG_YASCII   yLOG_note    ("image space does not exist");
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(malloc)-------------------------*/
   free (s_image);
   /*---(clear)--------------------------*/
   s_image = NULL;
   s_horz  = -1;
   s_vert  = -1;
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yASCII_write            (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   int         y           =    0;
   int         o           =    0;
   FILE       *f           = NULL;
   /*---(header)-------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YASCII   yLOG_point   ("s_image"   , s_image);
   --rce;  if (s_image == NULL) {
      DEBUG_YASCII   yLOG_note    ("image space does not exist");
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(open)---------------------------*/
   f = fopen (YSTR_CLIP, "wt");
   DEBUG_YASCII   yLOG_point   ("f"         , f);
   --rce;  if (f == NULL) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(write)--------------------------*/
   for (y = 0; y < s_vert; ++y) {
      fprintf (f, "%-*.*s\n", s_horz, s_horz, s_image + (y * s_horz));
   }
   /*---(close)--------------------------*/
   fflush (f);
   fclose (f);
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}

