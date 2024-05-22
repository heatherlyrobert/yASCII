/*===[[ START ]]==============================================================*/
#include    "yASCII.h"
#include    "yASCII_priv.h"



static   char  *s_image = NULL;


static char s_joining [LEN_LABEL][LEN_TITLE] = {
   /*            ------------- old ------------ */
   /*            123456789-123456789-123456789- */
   /* new */  { "  � � � � � � � � � � � � � � " },
   /*  �  */  { "� � � � � � � � � � � � � � � " },
   /*  �  */  { "� � � � � � � � � � � � � � � " },
   /*  �  */  { "� � � � � � � � � � � � � � � " },
   /*  �  */  { "� � � � � � � � � � � � � � � " },
   /*  �  */  { "� � � � � � � � � � � � � � � " },
   /*  �  */  { "� � � � � � � � � � � � � � � " },
   /*  �  */  { "� � � � � � � � � � � � � � � " },
   /*  �  */  { "� � � � � � � � � � � � � � � " },
   /*  �  */  { "� � � � � � � � � � � � � � � " },
   /*  �  */  { "� � � � � � � � � � � � � � � " },
   /*  �  */  { "� � � � � � � � � � � � � � � " },
   /*  �  */  { "� � � � � � � � � � � � � � � " },
   /*  �  */  { "� � � � � � � � � � � � � � � " },
};


/*====================------------------------------------====================*/
/*===----                   creation and destruction                   ----===*/
/*====================------------------------------------====================*/
static void      o___EXIST______________o (void) {;}

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
   --rce;  if (a_horz <= 0 || a_horz > 1000) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (a_vert <= 0 || a_vert > 1000) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
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
   myASCII.x_max  = a_horz;
   myASCII.y_max  = a_vert;
   /*---(clear)--------------------------*/
   yASCII_clear ();
   /*---(style)--------------------------*/
   yASCII_grid  ('-', 0, 0);
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
   for (y = 0; y < myASCII.y_max; ++y) {
      DEBUG_YASCII   yLOG_value   ("y"         , y);
      for (x = 0; x < myASCII.x_max; ++x) {
         o = y * myASCII.x_max + x;
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
   myASCII.x_max  = -1;
   myASCII.y_max  = -1;
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                       configuration                          ----===*/
/*====================------------------------------------====================*/
static void      o___CONFIG_____________o (void) {;}

char
yASCII_grid             (char a_style, short x_left, short y_topp)
{
   /*---(style)--------------------------*/
   myASCII.d_style    = a_style;
   /*---(upper-left corner)--------------*/
   myASCII.x_left      = x_left;
   myASCII.y_topp      = y_topp;
   /*---(grid sizing)--------------------*/
   switch (a_style) {
   case YASCII_MICRO   :
      myASCII.x_wide =  7; myASCII.x_side =  4; myASCII.x_gap =  3;
      myASCII.y_tall =  3; myASCII.y_side =  3; myASCII.y_gap =  0;
      break;
   case YASCII_LARGE   :
      myASCII.x_wide = 23; myASCII.x_side = 17; myASCII.x_gap =  6;
      myASCII.y_tall =  6; myASCII.y_side =  4; myASCII.y_gap =  2;
      break;
   case YASCII_HUGE    :
      myASCII.x_wide = 30; myASCII.x_side = 18; myASCII.x_gap = 12;
      myASCII.y_tall =  8; myASCII.y_side =  5; myASCII.y_gap =  3;
      break;
   case YASCII_DEFAULT : default   :
      myASCII.x_wide = 15; myASCII.x_side = 12; myASCII.x_gap =  3;
      myASCII.y_tall =  5; myASCII.y_side =  3; myASCII.y_gap =  2;
      break;
   }
   /*---(complete)-----------------------*/
   return 0;
}

char yASCII_style (char a_style) { return yASCII_grid (a_style, 0, 0); }

char
yASCII_grid_new         (char a_style, short a_col, short a_row)
{
   yASCII_grid (a_style, 0, 0);
   myASCII.x_max = myASCII.x_wide * a_col - myASCII.x_gap;
   myASCII.y_max = myASCII.y_tall * a_row - myASCII.y_gap;
   yASCII_new  (myASCII.x_max, myASCII.y_max);
   yASCII_grid (a_style, 0, 0);
}



/*====================------------------------------------====================*/
/*===----                     export and import                        ----===*/
/*====================------------------------------------====================*/
static void      o___EXIM_______________o (void) {;}

char
yASCII_write            (char a_name [LEN_PATH])
{
   /*---(locals)-----------+-----+-----+-*/
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
   DEBUG_YASCII   yLOG_point   ("a_name"    , a_name);
   --rce;  if (a_name == NULL) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_info    ("a_name"    , a_name);
   /*---(open)---------------------------*/
   f = fopen (a_name, "wt");
   DEBUG_YASCII   yLOG_point   ("f"         , f);
   --rce;  if (f == NULL) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(write)--------------------------*/
   for (y = 0; y < myASCII.y_max; ++y) {
      fprintf (f, "%-*.*s\n", myASCII.x_max, myASCII.x_max, s_image + (y * myASCII.x_max));
   }
   /*---(close)--------------------------*/
   fflush (f);
   fclose (f);
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                   printing and getting chars                 ----===*/
/*====================------------------------------------====================*/
static void      o___CHARS______________o (void) {;}

char
yASCII_get              (int x, int y)
{
   int         o           =    0;
   if (x <  0)        return '�';
   if (x >= myASCII.x_max)   return '�';
   if (y <  0)        return '�';
   if (y >= myASCII.y_max)   return '�';
   o = (y * myASCII.x_max) + x;
   return s_image [o];
}

char
yASCII_single           (int x, int y, char a_new)
{
   /*---(locals)-----------+-----+-----+-*/
   char        c           =  '-';
   char       *p           = NULL;
   char        x_valid     [LEN_TITLE] = "";
   char        x_old       =   -1;
   char        x_new       =   -1;
   char        t           [LEN_SHORT] = "";
   /*---(enter)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(get old)------------------------*/
   c = yASCII_get (x, y);
   DEBUG_YASCII   yLOG_complex ("c"         , "%3d/%c", c, ychrvisible (c));
   ystrlcpy (x_valid, s_joining [0], LEN_TITLE);
   DEBUG_YASCII   yLOG_info    ("x_valid"   , x_valid);
   p = strchr (x_valid, c);
   DEBUG_YASCII   yLOG_point   ("p"         , p);
   if (p == NULL) {
      DEBUG_YASCII   yLOG_note    ("leave alone");
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 1;
   }
   x_old = p - x_valid;
   DEBUG_YASCII   yLOG_value   ("x_old"     , x_old);
   /*---(get new)------------------------*/
   p = strchr (x_valid, a_new);
   DEBUG_YASCII   yLOG_point   ("p"         , p);
   if (p == NULL) {
      DEBUG_YASCII   yLOG_note    ("leave alone");
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 2;
   }
   x_new = (p - x_valid) / 2;
   DEBUG_YASCII   yLOG_value   ("x_new"     , x_new);
   /*---(identify replacement)-----------*/
   ystrlcpy (x_valid, s_joining [x_new], LEN_TITLE);
   DEBUG_YASCII   yLOG_info    ("x_valid"   , x_valid);
   c = x_valid [x_old];
   DEBUG_YASCII   yLOG_complex ("c"         , "%3d/%c", c, ychrvisible (c));
   /*---(replace)------------------------*/
   sprintf (t, "%c", c);
   yASCII_print (x, y, t, YASCII_CLEAR);
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yASCII_print            (int x, int y, char a_text [LEN_RECD], char a_mode)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =    0;
   int         x_len       =    0;
   int         i           =    0;
   char        c           =  '-';
   int         o           =    0;
   int         n           =    0;
   /*---(enter)--------------------------*/
   DEBUG_YASCII   yLOG_senter  (__FUNCTION__);
   /*---(defense)------------------------*/
   --rce;  if (a_text == NULL) {
      DEBUG_YASCII   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_snote   (a_text);
   /*---(filter)-------------------------*/
   if (y <  0) {
      DEBUG_YASCII   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   if (y >= myASCII.y_max) {
      DEBUG_YASCII   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   x_len = strlen (a_text);
   DEBUG_YASCII   yLOG_sint    (x_len);
   if (x_len <= 0) {
      DEBUG_YASCII   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   /*---(place characters)---------------*/
   for (i = 0; i < x_len; ++i) {
      c = a_text [i];
      if (a_mode == YASCII_MERGE && c == ' ')  continue;
      if (x + i <  0)       continue;
      if (x + i >= myASCII.x_max)  continue;
      o = (y * myASCII.x_max) + (x + i);
      /*> if (a_mode == YASCII_LAYER)   c = yascii_join (s_image [o], c);             <*/
      s_image [o] = c;
      ++n;
   }
   DEBUG_YASCII   yLOG_sint    (n);
   DEBUG_YASCII   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char
yASCII_printw           (int x, int y, int a_wide, int a_tall, char a_text [LEN_RECD], char a_mode)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         i           =    0;
   int         l           =    0;
   char        x_str       [LEN_RECD]  = "";
   int         x_head      =    0;
   int         x_break     =    0;
   int         x_width     =    0;
   int         x_lines     =    0;
   int         c           =    0;
   char        x_out       [LEN_RECD]  = "";
   /*---(enter)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YASCII   yLOG_point   ("a_text"    , a_text);
   --rce;  if (a_text == NULL) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_info    ("a_text"    , a_text);
   /*---(prepare)------------------------*/
   ystrlcpy (x_str, a_text, LEN_RECD);
   l = strlen (x_str);
   DEBUG_YASCII   yLOG_value   ("l"         , l);
   c = ystrldcnt (x_str, '�', LEN_RECD);
   DEBUG_YASCII   yLOG_value   ("c"         , c);
   /*---(walk text)----------------------*/
   --rce;  for (i = 0; i < l; i++) {
      DEBUG_YASCII  yLOG_complex ("char"      , "%4d, %3d, %3d, %c", l, i, x_str [i], x_str [i]);
      /*---(watch for breaks)------------*/
      if (strchr("� � - /", x_str[i]) != NULL) {
         DEBUG_YASCII  yLOG_note    ("found a delimiter/space");
         x_break = i;
      }
      /*---(watch for newlines)----------*/
      if (x_str [i] == '�') {
         DEBUG_YASCII  yLOG_note    ("found new line");
         x_break = i;
      } else {
         ++x_width;
      }
      DEBUG_YASCII  yLOG_complex ("width"     , "%4db, %3dw", x_break, x_width);
      if (x_width > a_wide || x_str [i] == '�') {
         DEBUG_YASCII  yLOG_note    ("passed width or newline, display");
         x_str [x_break] = '\0';
         if (a_mode != YASCII_FILL) {
            ystrlcpy  (x_str + x_head, x_out, LEN_RECD);
         } else {
            ystrlpad  (x_str + x_head, x_out, '.', '<', a_wide);
            ystrldchg (x_out, ' ', '�', a_wide);
         }
         yASCII_print (x, y + x_lines, x_out, a_mode);
         ++x_lines;
         x_width = 0;
         ++x_break;
         i = x_head = x_break;
         if (x_lines >= a_tall) {
            DEBUG_YASCII  yLOG_note    ("more text after box filled");
            DEBUG_YASCII  yLOG_exitr   (__FUNCTION__, rce);
            return rce;
         }
      } else {
         DEBUG_YASCII  yLOG_note    ("under width limit, get next char");
      }
   }
   /*---(left-over)----------------------*/
   DEBUG_YASCII  yLOG_complex ("leftover"  , "%3d w, %3d s, %3d l", x_width, x_head, l);
   if (x_width > 0) {
      DEBUG_YASCII  yLOG_note    ("print final bits");
      if (a_mode != YASCII_FILL) {
         ystrlcpy  (x_str + x_head, x_out, LEN_RECD);
      } else {
         ystrlpad  (x_str + x_head, x_out, '.', '<', a_wide);
         ystrldchg (x_out, ' ', '�', a_wide);
      }
      yASCII_print (x, y + x_lines, x_out, a_mode);
      x_lines ++;
   } else {
      DEBUG_YASCII  yLOG_note    ("nothing left at end to print");
   }
   for (i = x_lines; i < a_tall; ++i) {
      ystrlpad  ("", x_out, '.', '<', a_wide);
      yASCII_print (x, y + i, x_out, a_mode);
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yASCII_connector        (short bx, short by, char a_dir, short ex, short ey, char a_heavy, char a_label [LEN_LABEL], short lx, short ly)
{
   /*---(locals)-----------+-----+-----+-*/
   char        x_dir       =    0;
   int         i           =    0;
   char        x_2nd       =  '�';
   char        x_horz      [LEN_SHORT] =  "�";
   char        x_vert      [LEN_SHORT] =  "�";
   char        x_end       =  '�';
   char        t           [LEN_SHORT] =  "�";
   /*---(enter)--------------------------*/
   DEBUG_YASCII   yLOG_senter  (__FUNCTION__);
   /*---(lines)--------------------------*/
   DEBUG_YASCII   yLOG_schar   (a_heavy);
   if (a_heavy == '�') {
      strcpy (x_horz, "�");
      strcpy (x_vert, "�");
   } else if (a_heavy == '�') {
      strcpy (x_horz, "�");
      strcpy (x_vert, "�");
   }
   DEBUG_YASCII   yLOG_schar   (x_horz);
   DEBUG_YASCII   yLOG_schar   (x_vert);
   /*---(direction)----------------------*/
   if (bx > ex) {
      if      (by >  ey)  {  x_dir = 1;  if (a_dir == '�') { x_2nd = '�'; x_end = '�'; }  else { a_dir = '�'; x_2nd = '�'; x_end = '�'; } }
      else if (by == ey)  {  x_dir = 4;  a_dir = '�';  x_2nd = '�';  x_end = '�'; }
      else                {  x_dir = 7;  if (a_dir == '�') { x_2nd = '�'; x_end = '�'; }  else { a_dir = '�'; x_2nd = '�'; x_end = '�'; } }
   } else if (bx == ex) {
      if      (by >  ey)  {  x_dir = 2;  a_dir = '�';  x_2nd = '�';  x_end = '�'; }
      else if (by == ey)  {  x_dir = 5;  a_dir = '�';  x_2nd = '�'; }
      else                {  x_dir = 8;  a_dir = '�';  x_2nd = '�';  x_end = '�'; }
   } else {
      if      (by >  ey)  {  x_dir = 3;  if (a_dir == '�') { x_2nd = '�'; x_end = '�'; }  else { a_dir = '�'; x_2nd = '�'; x_end = '�'; } }
      else if (by == ey)  {  x_dir = 6;  a_dir = '�';  x_2nd = '�';  x_end = '�'; }
      else                {  x_dir = 9;  if (a_dir == '�') { x_2nd = '�'; x_end = '�'; }  else { a_dir = '�'; x_2nd = '�'; x_end = '�'; } }
   }
   DEBUG_YASCII   yLOG_sint    (x_dir);
   DEBUG_YASCII   yLOG_schar   (a_dir);
   DEBUG_YASCII   yLOG_schar   (x_2nd);
   /*---(origination)--------------------*/
   yASCII_print (bx, by, "�", YASCII_CLEAR); 
   /*---(first segment)------------------*/
   switch (a_dir) {
   case '�' :  for (i = bx + 1; i < ex; ++i)   yASCII_print ( i, by, x_horz, YASCII_CLEAR);    break;
   case '�' :  for (i = bx - 1; i > ex; --i)   yASCII_print ( i, by, x_horz, YASCII_CLEAR);    break;
   case '�' :  for (i = by + 1; i < ey; ++i)   yASCII_print (bx,  i, x_vert, YASCII_CLEAR);    break;
   case '�' :  for (i = by - 1; i > ey; --i)   yASCII_print (bx,  i, x_vert, YASCII_CLEAR);    break;
   }
   /*---(corner)-------------------------*/
   switch (a_dir) { case '�' :  if (x_dir == 3)  yASCII_print (ex, by, "�", YASCII_CLEAR);  else if (x_dir == 9)  yASCII_print (ex, by, "�", YASCII_CLEAR);  break;
   case '�' :  if (x_dir == 1)  yASCII_print (ex, by, "�", YASCII_CLEAR);  else if (x_dir == 7)  yASCII_print (ex, by, "�", YASCII_CLEAR);  break;
   case '�' :  if (x_dir == 7)  yASCII_print (bx, ey, "�", YASCII_CLEAR);  else if (x_dir == 9)  yASCII_print (bx, ey, "�", YASCII_CLEAR);  break;
   case '�' :  if (x_dir == 1)  yASCII_print (bx, ey, "�", YASCII_CLEAR);  else if (x_dir == 3)  yASCII_print (bx, ey, "�", YASCII_CLEAR);  break;
   }
   /*---(second segment)-----------------*/
   switch (x_2nd) {
   case '�' :  for (i = bx + 1; i < ex; ++i)   yASCII_print ( i, ey, x_horz, YASCII_CLEAR);    break;
   case '�' :  for (i = bx - 1; i > ex; --i)   yASCII_print ( i, ey, x_horz, YASCII_CLEAR);    break;
   case '�' :  for (i = by + 1; i < ey; ++i)   yASCII_print (ex,  i, x_vert, YASCII_CLEAR);    break;
   case '�' :  for (i = by - 1; i > ey; --i)   yASCII_print (ex,  i, x_vert, YASCII_CLEAR);    break;
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

char yASCII_uconnect  (short bx, short by, char a_dir, short ex, short ey) { return yASCII_connector (bx, by, a_dir, ex, ey, '�', NULL, 0, 0); }




/*====================------------------------------------====================*/
/*===----                        content boxes                         ----===*/
/*====================------------------------------------====================*/
static void      o___BOXES______________o (void) {;}

char
yASCII_box_full         (short x, short y, short w, short t, char a_name [LEN_TITLE], char a_note [LEN_SHORT], char a_npred, char a_nsucc)
{
   /*---(locals)-----------+-----+-----+-*/
   short       i           =    0;
   char        x_line      [LEN_HUND]  = "";
   short       l           =    0;
   /*---(header)-------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   DEBUG_YASCII   yLOG_complex ("a_args"    , "%3dx, %3dy, %3dw, %3dt", x, y, w, t);
   /*---(top)----------------------------*/
   sprintf (x_line, "�%*.*s�", w - 2, w - 2, YSTR_HORZ);
   yASCII_print (x, y, x_line, YASCII_CLEAR);
   /*---(middle)-------------------------*/
   sprintf (x_line, "�%*.*s�", w - 2, w - 2, YSTR_EMPTY);
   for (i = 1; i < t - 1; ++i) {
      yASCII_print (x, y + i, x_line, YASCII_CLEAR);
   }
   /*---(bottom)-------------------------*/
   sprintf (x_line, "�%*.*s�", w - 2, w - 2, YSTR_HORZ);
   yASCII_print (x, y + t - 1, x_line, YASCII_CLEAR);
   /*---(title)--------------------------*/
   ystrlcpy (x_line, a_name, w - 1);
   l = strlen (x_line);
   yASCII_print (x + 1, y + 1, x_line, YASCII_CLEAR);
   /*---(note)---------------------------*/
   if (strcmp (a_note, "")  != 0) {
      l = strlen (a_note);
      yASCII_print (x + w - l - 1, y + t - 1, a_note, YASCII_CLEAR);
   }
   /*---(stats)--------------------------*/
   if (a_npred > 0) {
      sprintf (x_line, "%-3d", a_npred);
      yASCII_print (x + 1, y + t, x_line, YASCII_CLEAR);
   }
   if (a_nsucc > 0) {
      sprintf (x_line, "%3d" , a_nsucc);
      yASCII_print (x + w - 4, y + t, x_line, YASCII_CLEAR);
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yASCII_grid_box         (char a_col, char a_row, char a_name [LEN_TITLE], char a_note [LEN_SHORT], char a_npred, char a_nsucc)
{
   /*---(locals)-----------+-----+-----+-*/
   short       x, y;
   /*---(prepare)------------------------*/
   x = myASCII.x_left + (a_col * myASCII.x_wide);
   y = myASCII.y_topp + (a_row * myASCII.y_tall);
   /*---(complete)-----------------------*/
   return yASCII_box_full (x, y, myASCII.x_side, myASCII.y_side, a_name, a_note, a_npred, a_nsucc);
}

char yASCII_grid_simple (char a_col, char a_row, char a_title [LEN_TITLE]) { return yASCII_grid_box (a_col, a_row, a_title, "", 0, 0); }
char yASCII_grid_empty  (char a_col, char a_row) { return yASCII_grid_box (a_col, a_row, "", "", 0, 0); }

char
yASCII_node             (short x, short y, char a)
{
   /*---(locals)-----------+-----+-----+-*/
   char        s           [LEN_SHORT] = "";
   /*---(header)-------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(outside)------------------------*/
   yASCII_print (x, y    , "�����", YASCII_CLEAR);
   yASCII_print (x, y + 1, "�   �", YASCII_CLEAR);
   yASCII_print (x, y + 2, "�����", YASCII_CLEAR);
   /*---(label)--------------------------*/
   sprintf (s, "%c", ychrvisible (a));
   yASCII_print (x + 2, y + 1, s, YASCII_CLEAR);
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                         unit testing                         ----===*/
/*====================------------------------------------====================*/
static void  o___CONNECT_________o () { return; }

char
yASCII_connect_full     (short bx, short by, short ex, short ey, char a_tall, char a_blane, char a_vlane, char a_elane)
{
   /*---(locals)-----------+-----+-----+-*/
   char        x_dir       =    0;
   int         i           =    0;
   /*---(enter)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   DEBUG_YASCII   yLOG_complex ("a_args"    , "%3dbx, %3dby, %3dex, %3dey, %1dbl, %1dvl, %1del", bx, by, ex, ey, a_tall, a_blane, a_vlane, a_elane);
   /*---(direction)----------------------*/
   if      (by + a_blane == ey + a_elane)   x_dir = '�';
   else if (by + a_blane <  ey + a_elane)   x_dir = '�';
   else                                     x_dir = '�';
   DEBUG_YASCII   yLOG_char    ("x_dir"     , x_dir);
   /*---(start)--------------------------*/
   if      (a_blane == 0)        yASCII_print (bx, by          , "�", YASCII_CLEAR); 
   else if (a_blane == a_tall)   yASCII_print (bx, by + a_tall , "�", YASCII_CLEAR); 
   else                          yASCII_print (bx, by + a_blane, "�", YASCII_CLEAR); 
   /*---(finish)-------------------------*/
   if      (a_elane == 0)        yASCII_print (ex, ey          , "�", YASCII_CLEAR); 
   else if (a_elane == a_tall)   yASCII_print (ex, ey + a_tall , "�", YASCII_CLEAR); 
   else                          yASCII_print (ex, ey + a_elane, "�", YASCII_CLEAR); 
   /*---(connect)------------------------*/
   switch (x_dir) {
   case '�' : 
      DEBUG_YASCII   yLOG_note    ("horizontal");
      for (i = bx + 1; i <= ex - 1; ++i)        yASCII_single (i, by + a_blane, '�');
      break;
   case '�' : 
      DEBUG_YASCII   yLOG_note    ("ascending/upward line");
      for (i = bx + 1; i < ex - a_vlane; ++i)  yASCII_single (i, by + a_blane, '�');
      yASCII_single (ex - 2, by + a_blane, '�');
      for (i = by + a_blane - 1; i >= ey + a_elane + 1; --i)  yASCII_single (ex - a_vlane, i, '�');
      yASCII_single (ex - 2, ey + a_elane, '�');
      break;
   case '�' :
      DEBUG_YASCII   yLOG_note    ("descending/downward line");
      yASCII_single (bx + a_vlane, by + a_blane, '�');
      for (i = by + a_blane + 1; i <= ey + a_elane - 1; ++i)  yASCII_single (bx + a_vlane, i, '�');
      yASCII_single (bx + 2, ey + a_elane, '�');
      for (i = bx + a_vlane + 1; i <= ex - 1; ++i)  yASCII_single (i, ey + a_elane, '�');
      break;
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yASCII_grid_connect     (char a_bcol, char a_brow, char a_ecol, char a_erow)
{
   /*---(locals)-----------+-----+-----+-*/
   short       bx, by, ex, ey;
   /*---(beginning)----------------------*/
   if (a_bcol == -1)    bx = myASCII.x_left - 4;
   else                 bx = myASCII.x_left + (a_bcol * myASCII.x_wide) + myASCII.x_wide - myASCII.x_gap - 1;
   by = myASCII.y_topp + (a_brow * myASCII.y_tall);
   /*---(ending)-------------------------*/
   if (a_ecol == 66)    ex = myASCII.x_max + 3;
   else                 ex = myASCII.x_left + (a_ecol * myASCII.x_wide);
   ey = myASCII.y_topp + (a_erow * myASCII.y_tall);
   /*---(complete)-----------------------*/
   return yASCII_connect_full (bx, by, ex, ey, myASCII.y_tall - myASCII.y_gap, 1, 2, 1);
}



/*====================------------------------------------====================*/
/*===----                         unit testing                         ----===*/
/*====================------------------------------------====================*/
static void  o___UNITTEST________o () { return; }

char*
DRAW__unit              (char *a_question, int n)
{ 
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         rc          =    0;
   /*---(prepare)------------------------*/
   ystrlcpy  (unit_answer, "DRAW             : question not understood", LEN_RECD);
   /*---(crontab name)-------------------*/
   if (strcmp (a_question, "grid"          )  == 0) {
      snprintf (unit_answer, LEN_RECD, "DRAW grid        : %c   H %3dn %3dx %3dw %3ds %3dg   V %3dn %3dx %3dt %3ds %3dg",
            myASCII.d_style,
            myASCII.x_left, myASCII.x_max, myASCII.x_wide, myASCII.x_side, myASCII.x_gap,
            myASCII.y_topp, myASCII.y_max, myASCII.y_tall, myASCII.y_side, myASCII.y_gap);
   }
   /*---(complete)-----------------------*/
   return unit_answer;
}
