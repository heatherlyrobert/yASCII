/*===[[ START ]]==============================================================*/
#include    "yASCII.h"
#include    "yASCII_priv.h"



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



struct {
   char        abbr;                   /* identifier    */
   char        x_wide, x_side, x_gap;  /* horz/x values */
   char        y_tall, y_side, y_gap;  /* vert/y values */
   char        frame;                  /* can frame ?   */
   char        x_left, x_righ;         /* horz/x frame  */
   char        y_topp, y_bott;         /* vert/y frame  */
} static const zASCII_bound [LEN_TERSE] = {
   {  YASCII_DEFAULT  , 15, 12,  3,  5,  3,  2, 'y', -2,  2, -6,  3 },
   {  YASCII_MICRO    ,  7,  4,  3,  3,  3,  0, '-',  0,  0,  0,  0 },
   {  YASCII_LARGE    , 22, 17,  5,  6,  4,  2, 'y', -3,  3,  6,  3 },
   {  YASCII_HUGE     , 29, 22,  7,  8,  5,  3, 'y', -4,  4, -6,  3 },
   {  '\0'            ,  0,  0,  0,  0,  0,  0,  0 ,  0,  0,  0,  0 },
};


struct {
   char        b_heavy, b_arrange;
   char        b_title     [LEN_TITLE];
   char        b_col, b_row;
   short       b_x, b_y;
   char        b_wide, b_tall;
   char        b_note      [LEN_SHORT];
   char        b_block, b_npred, b_nsucc;
} static S_boxes [LEN_HUND];
static char S_nbox   = 0;
static char S_cbox   = 0;

/*  ··-  ´·····························  -  -  ··- ··- ··- ··-  ´····  -  ·- ·-  Ï */



/*====================------------------------------------====================*/
/*===----                       box data keeping                       ----===*/
/*====================------------------------------------====================*/
static void  o___DATA____________o () { return; }

char
yascii_box_clear        (void)
{
   int         i           =    0;
   for (i = 0; i < LEN_HUND; ++i) {
      S_boxes [i].b_heavy = S_boxes [i].b_arrange = '-';
      strcpy (S_boxes [i].b_title, "");
      S_boxes [i].b_x = S_boxes [i].b_y = S_boxes [i].b_wide = S_boxes [i].b_tall = 0;
      strcpy (S_boxes [i].b_note , "");
      S_boxes [i].b_block = '-';
      S_boxes [i].b_npred = S_boxes [i].b_nsucc = 0;
   }
   S_nbox = 0;
   S_cbox = 0;
   return 0;
}

char
yascii_box__add         (char a_heavy, char a_arrange, char a_col, char a_row, short a_bx, short a_by, char a_wide, char a_tall, char a_title [LEN_TITLE], char a_note [LEN_SHORT], char a_block, char a_npred, char a_nsucc)
{  /*---(design notes)-------------------*/
   /*
    *    does not check quality/legality of data, only its existance
    */
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*---(defense)------------------------*/
   --rce;  if (S_nbox >= LEN_HUND)                       return rce;
   --rce;  if (a_title == NULL || a_title [0] == '\0')   return rce;
   --rce;  if (a_note  == NULL)                          return rce;
   /*---(correction)---------------------*/
   if (S_nbox < 0)  S_nbox = 0;
   /*---(config)-------------------------*/
   S_boxes [S_nbox].b_heavy   = a_heavy;
   S_boxes [S_nbox].b_arrange = a_arrange;
   /*---(grid)---------------------------*/
   S_boxes [S_nbox].b_col     = a_col;
   S_boxes [S_nbox].b_row     = a_row;
   /*---(placement)----------------------*/
   S_boxes [S_nbox].b_x       = a_bx;
   S_boxes [S_nbox].b_y       = a_by;
   /*---(size)---------------------------*/
   S_boxes [S_nbox].b_wide    = a_wide;
   S_boxes [S_nbox].b_tall    = a_tall;
   /*---(labeling)-----------------------*/
   strncpy (S_boxes [S_nbox].b_title, a_title, LEN_TITLE);
   strncpy (S_boxes [S_nbox].b_note , a_note , LEN_SHORT);
   S_boxes [S_nbox].b_block   = a_block;
   /*---(statistics)---------------------*/
   S_boxes [S_nbox].b_npred   = a_npred;
   S_boxes [S_nbox].b_nsucc   = a_nsucc;
   /*---(increment count)----------------*/
   ++S_nbox;
   /*---(complete)-----------------------*/
   return 1;
}

char yascii_box_count        (void) { return S_nbox; }

char
yascii_box_by_name      (char a_title [LEN_TITLE])
{
   char        rce         =  -10;
   int         i           =    0;
   --rce;  if (a_title == NULL || a_title [0] == '\0')  return rce;
   for (i = 0; i < LEN_HUND; ++i) {
      if (i >= S_nbox)  break;
      if (strcmp (S_boxes [i].b_title, a_title) != 0)  continue;
      return i;
   }
   return --rce;
}

char
yascii_box_by_pos       (short a_bx, short a_by)
{
   char        rce         =  -10;
   int         i           =    0;
   for (i = 0; i < LEN_HUND; ++i) {
      if (i >= S_nbox)  break;
      if (a_bx != S_boxes [i].b_x)  continue;
      if (a_by != S_boxes [i].b_y)  continue;
      return i;
   }
   return --rce;
}

char
yascii_box_by_grid      (char a_col, char a_row)
{
   char        rce         =  -10;
   int         i           =    0;
   for (i = 0; i < LEN_HUND; ++i) {
      if (i >= S_nbox)  break;
      if (a_col != S_boxes [i].b_col)  continue;
      if (a_row != S_boxes [i].b_row)  continue;
      return i;
   }
   return --rce;
}

char
yascii_box_data         (char n, char r_title [LEN_TITLE], char *r_heavy, char *r_arrange, char *r_col, char *r_row, short *r_bx, short *r_by, char *r_wide, char *r_tall, short *r_ex, short *r_ey, char r_note [LEN_SHORT], char *r_block, char *r_npred, char *r_nsucc)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*---(default)------------------------*/
   if (r_title   != NULL)  strcpy (r_title, "");
   if (r_heavy   != NULL)  *r_heavy   = '?';
   if (r_arrange != NULL)  *r_arrange = '?';
   if (r_col     != NULL)  *r_col     = -1;
   if (r_row     != NULL)  *r_row     = -1;
   if (r_bx      != NULL)  *r_bx      = -1;
   if (r_by      != NULL)  *r_by      = -1;
   if (r_wide    != NULL)  *r_wide    = -1;
   if (r_tall    != NULL)  *r_tall    = -1;
   if (r_ex      != NULL)  *r_ex      = -1;
   if (r_ey      != NULL)  *r_ey      = -1;
   if (r_note    != NULL)  strcpy (r_note, "");
   if (r_block   != NULL)  *r_block   = '?';
   if (r_npred   != NULL)  *r_npred   = -1;
   if (r_nsucc   != NULL)  *r_nsucc   = -1;
   /*---(defense)------------------------*/
   --rce;  if (n < 0)         return rce;
   --rce;  if (n >= S_nbox)   return rce;
   /*---(save-back)----------------------*/
   if (r_title   != NULL)  strlcpy (r_title, S_boxes [n].b_title, LEN_TITLE);
   if (r_heavy   != NULL)  *r_heavy   = S_boxes [n].b_heavy;
   if (r_arrange != NULL)  *r_arrange = S_boxes [n].b_arrange;
   if (r_bx      != NULL)  *r_bx      = S_boxes [n].b_x;
   if (r_by      != NULL)  *r_by      = S_boxes [n].b_y;
   if (r_wide    != NULL)  *r_wide    = S_boxes [n].b_wide;
   if (r_tall    != NULL)  *r_tall    = S_boxes [n].b_tall;
   if (r_ex      != NULL)  *r_ex      = S_boxes [n].b_x + S_boxes [n].b_wide - 1;
   if (r_ey      != NULL)  *r_ey      = S_boxes [n].b_y + S_boxes [n].b_tall - 1;
   if (r_note    != NULL)  strlcpy (r_note, S_boxes [n].b_note, LEN_SHORT);
   if (r_block   != NULL)  *r_block   = S_boxes [n].b_block;
   if (r_npred   != NULL)  *r_npred   = S_boxes [n].b_npred;
   if (r_nsucc   != NULL)  *r_nsucc   = S_boxes [n].b_nsucc;
   /*---(complete)-----------------------*/
   return 1;
}

char*
yascii_box_entry        (char a_dir)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    1;
   char        x_curr      =    0;
   char        x_title     [LEN_TITLE] = "";
   char        x_note      [LEN_SHORT] = "";
   /*---(header)-------------------------*/
   DEBUG_YDLST  yLOG_senter  (__FUNCTION__);
   /*---(quick-out)----------------------*/
   if (a_dir == 'T') {
      strcpy (unit_answer, "seq  ---title---------------------  H  A  col row  --x --y --w --t  note  B  pr sc  Ï");
      DEBUG_YDLST   yLOG_sexit   (__FUNCTION__);
      return unit_answer;
   }
   /*---(defaults)-----------------------*/
   strcpy (unit_answer, "··-  ´····························  -  -  ··- ··-  ··- ··- ··- ··-  ´···  -  ·- ·-  Ï");
   x_curr = S_cbox;
   /*---(switch)-------------------------*/
   DEBUG_YDLST  yLOG_schar   (a_dir);
   --rce;  switch (a_dir) {
   case YDLST_HEAD : case YDLST_DHEAD :
      x_curr = 0;
      break;
   case YDLST_PREV : case YDLST_DPREV :
      --x_curr;
      break;
   case YDLST_CURR : case YDLST_DCURR :
      x_curr = x_curr;
      break;
   case YDLST_NEXT : case YDLST_DNEXT :
      ++x_curr;
      break;
   case YDLST_TAIL : case YDLST_DTAIL :
      x_curr = S_nbox - 1;
      break;
   default         :
      DEBUG_YDLST  yLOG_sexitr  (__FUNCTION__, rce);
      return unit_answer;
   }
   DEBUG_YDLST  yLOG_sint    (x_curr);
   /*---(check end)----------------------*/
   --rce;  if (x_curr < 0 || x_curr >= S_nbox) {
      DEBUG_YDLST   yLOG_sexitr  (__FUNCTION__, rce);
      return unit_answer;
   }
   /*---(output)-------------------------*/
   if (x_curr >= 0 && x_curr < S_nbox) {
      snprintf (x_title, LEN_TITLE, "%s······························", S_boxes [x_curr].b_title);
      if (strcmp (S_boxes [x_curr].b_note, "") == 0)  strlcpy  (x_note, "´····", LEN_SHORT);
      else                                            snprintf (x_note, LEN_SHORT, "%s····", S_boxes [x_curr].b_note);
      sprintf (unit_answer, "%3d  %-29.29s  %c  %c  %3d %3d  %3d %3d %3d %3d  %-4.4s  %c  %2d %2d  Ï", x_curr,
            x_title, S_boxes [x_curr].b_heavy, S_boxes [x_curr].b_arrange,
            S_boxes [x_curr].b_col, S_boxes [x_curr].b_row,
            S_boxes [x_curr].b_x, S_boxes [x_curr].b_y,
            S_boxes [x_curr].b_wide, S_boxes [x_curr].b_tall,
            x_note, S_boxes [x_curr].b_block, S_boxes [x_curr].b_npred, S_boxes [x_curr].b_nsucc);
   }
   /*---(save-back)----------------------*/
   S_cbox = x_curr;
   /*---(complete)-----------------------*/
   DEBUG_YDLST  yLOG_sexit   (__FUNCTION__);
   return unit_answer;
}



/*====================------------------------------------====================*/
/*===----                        content boxes                         ----===*/
/*====================------------------------------------====================*/
static void      o___CREATE_____________o (void) {;}

char
yascii_box__erase       (short a_bx, short a_by, char a_wide, char a_tall)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        x_line      [LEN_HUND]  = "";
   short       i           =    0;
   /*---(defense)------------------------*/
   --rce;  if (a_wide < 1)  return rce;
   --rce;  if (a_tall < 1)  return rce;
   /*---(prepare)------------------------*/
   sprintf (x_line, "%*.*s", a_wide - 2, a_wide - 2, YSTR_EMPTY);
   /*---(clear space)--------------------*/
   for (i = 1; i < a_tall - 1; ++i) {
      yASCII_print (a_bx + 1, a_by + i, x_line);
   }
   /*---(complete)-----------------------*/
   return 1;
}

char
yascii_box__outline     (char a_heavy, short a_bx, short a_by, char a_wide, char a_tall, char a_mode)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   short       i           =    0;
   char        c           =  ' ';
   char        x_line      [LEN_HUND]  = "";
   char        x_left, x_topp, x_righ, x_bott;
   char        x_talt, x_balt;
   int         x_cnt       =    0;
   short       x_ex, x_ey;
   /*---(header)-------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   DEBUG_YASCII   yLOG_complex ("a_args"    , "%c, %3dx, %3dy, %3dw, %3dt, %c", a_heavy, a_bx, a_by, a_wide, a_tall, a_mode);
   /*---(defense)------------------------*/
   --rce;  if (a_mode != YASCII_CLEAR && a_mode != YASCII_MERGE) {
      DEBUG_YASCII   yLOG_note    ("illegal mode (CLEAR or MERGE only)");
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(lines)--------------------------*/
   rc = yascii_draw_heaviness (a_heavy, &x_left, &x_topp, &x_righ, &x_bott);
   DEBUG_YASCII   yLOG_value   ("heavy"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   if (x_topp == '')  x_talt = '€';
   else                x_talt = x_topp;
   if (x_bott == '')  x_balt = '€';
   else                x_balt = x_bott;
   DEBUG_YASCII   yLOG_complex ("lines"     , "%c  %c  %c  %c  %c  %c", x_left, x_topp, x_righ, x_bott, x_talt, x_balt);
   /*---(clear inside)-------------------*/
   rc = yascii_box__erase (a_bx, a_by, a_wide, a_tall);
   DEBUG_YASCII   yLOG_value   ("erase"     , rc);
   /*---(prepare)------------------------*/
   x_ex = a_bx + a_wide - 1;
   x_ey = a_by + a_tall - 1;
   DEBUG_YASCII   yLOG_complex ("ends"      , "ex = %3d, ey = %3d", x_ex, x_ey);
   /*---(top)----------------------------*/
   rc = yASCII_segment ('E', 'ƒ', a_bx, a_by, x_topp, x_ex, a_by, '‚');
   DEBUG_YASCII   yLOG_value   ("top"       , rc);
   rc = yASCII_segment ('S', '‚', x_ex, a_by, x_righ, x_ex, x_ey, '…');
   DEBUG_YASCII   yLOG_value   ("right"     , rc);
   rc = yASCII_segment ('W', '…', x_ex, x_ey, x_bott, a_bx, x_ey, '„');
   DEBUG_YASCII   yLOG_value   ("bottom"    , rc);
   rc = yASCII_segment ('N', '„', a_bx, x_ey, x_left, a_bx, a_by, 'ƒ');
   DEBUG_YASCII   yLOG_value   ("right"     , rc);
   /*> yASCII_draw_merge (a_bx        , a_by, 'ƒ');                                                <* 
    *> for (x_cnt = 0, i = a_bx + 1; i < a_bx + a_wide - 1; ++i) {                                      <* 
    *>    yASCII_draw_double (x_cnt++, i, a_by, x_topp, x_talt);                                <* 
    *>    c = yASCII_draw_get (i, a_by);                                                        <* 
    *>    if (a_mode == YASCII_CLEAR && c == 'Š') yASCII_print  (i, a_by, "ˆ");   <* 
    *> }                                                                                     <* 
    *> yASCII_draw_merge (a_bx + a_wide - 1, a_by, '‚');                                                <*/
   /*---(middle)-------------------------*/
   /*> sprintf (x_line, "%*.*s", a_wide - 2, a_wide - 2, YSTR_EMPTY);                                              <* 
    *> for (i = 1; i < a_tall - 1; ++i) {                                                                     <* 
    *>    /+---(left)-----------+/                                                                       <* 
    *>    yASCII_draw_merge (a_bx, a_by + i, x_left);                                                          <* 
    *>    c = yASCII_draw_get (a_bx, a_by + i);                                                                <* 
    *>    if (a_mode == YASCII_CLEAR && c == 'Š') yASCII_print  (a_bx, a_by + i, "†");           <* 
    *>    /+---(center)---------+/                                                                       <* 
    *>    if (a_mode == YASCII_CLEAR)             yASCII_print  (a_bx + 1, a_by + i, x_line);    <* 
    *>    /+---(right)----------+/                                                                       <* 
    *>    yASCII_draw_merge (a_bx + a_wide - 1, a_by + i, x_righ);                                                  <* 
    *>    c = yASCII_draw_get (a_bx + a_wide - 1, a_by + i);                                                        <* 
    *>    if (a_mode == YASCII_CLEAR && c == 'Š') yASCII_print  (a_bx + a_wide - 1, a_by + i, "‡");   <* 
    *>    /+---(done)-----------+/                                                                       <* 
    *> }                                                                                                 <*/
   /*---(bottom)-------------------------*/
   /*> yASCII_draw_merge (a_bx        , a_by + a_tall - 1, '„');                                                <* 
    *> for (x_cnt = 0, i = a_bx + 1; i < a_bx + a_wide - 1; ++i) {                                              <* 
    *>    yASCII_draw_double (x_cnt++, i, a_by + a_tall - 1, x_bott, x_balt);                                <* 
    *>    c = yASCII_draw_get (i, a_by + a_tall - 1);                                                        <* 
    *>    if (a_mode == YASCII_CLEAR && c == 'Š') yASCII_print  (i, a_by + a_tall - 1, "‰");   <* 
    *> }                                                                                             <* 
    *> yASCII_draw_merge (a_bx + a_wide - 1, a_by + a_tall - 1, '…');                                                <*/
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yascii_box__title       (char a_arrange, short a_bx, short a_by, char a_wide, char a_tall, char a_title [LEN_TITLE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_title     [LEN_HUND]  = "";
   short       lb, la;
   /*---(header)-------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(quick-out)----------------------*/
   DEBUG_YASCII   yLOG_char    ("a_arrange" , a_arrange);
   if (a_arrange == YASCII_BASE) {
      DEBUG_YASCII   yLOG_note    ("not applicable to YASCII_BASE");
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   DEBUG_YASCII   yLOG_char    ("d_titles"  , myASCII.d_titles);
   if (myASCII.d_titles != 'y') {
      DEBUG_YASCII   yLOG_note    ("titles are globally turned-off");
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(defenses)-----------------------*/
   DEBUG_YASCII   yLOG_point   ("a_title"   , a_title);
   --rce;  if (a_title == NULL || a_title [0] == '\0') {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_info    ("a_title"   , a_title);
   /*---(hidden title)-------------------*/
   if (a_title [0] == '·') {
      DEBUG_YASCII   yLOG_note    ("leading space (·) means hidden title");
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   lb = strlen (a_title);
   /*---(print)--------------------------*/
   switch (a_arrange) {
   case YASCII_BIG  : case YASCII_TECH :
      snprintf (x_title, a_wide - 3, " %.*s ", a_wide - 5, a_title);
      la = strlen (x_title);
      if (la < lb - 2)  x_title [la - 2] = '>';
      DEBUG_YASCII   yLOG_info    ("x_title"   , x_title);
      rc = yASCII_print (a_bx + ((a_wide - la) / 2.0), a_by, x_title);
      break;
   case YASCII_NODE :
      strlcpy (x_title, a_title, LEN_HUND);
      la = strlen (x_title);
      DEBUG_YASCII   yLOG_info    ("x_title"   , x_title);
      rc = yASCII_print (a_bx + ((a_wide - la) / 2.0), a_by + (a_tall / 2.0), x_title);
      break;
   case YASCII_STD  : default          :
      strlcpy (x_title, a_title, a_wide - 1);
      la = strlen (x_title);
      if (la < lb)  x_title [la - 1] = '>';
      DEBUG_YASCII   yLOG_info    ("x_title"   , x_title);
      rc = yASCII_print (a_bx + 1          , a_by + 1, x_title);
      break;
   }
   DEBUG_YASCII   yLOG_value   ("print"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 1;
}

char
yascii_box__note        (char a_arrange, short a_bx, short a_by, char a_wide, char a_tall, char a_note [LEN_SHORT])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_note      [LEN_TERSE] = "";
   short       lb, la;
   /*---(header)-------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(quick-out)----------------------*/
   DEBUG_YASCII   yLOG_char    ("a_arrange" , a_arrange);
   if (a_arrange == YASCII_BASE || a_arrange == YASCII_NODE) {
      DEBUG_YASCII   yLOG_note    ("not applicable to YASCII_BASE/YASCII_NODE");
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   DEBUG_YASCII   yLOG_char    ("d_notes"   , myASCII.d_notes);
   if (myASCII.d_notes != 'y') {
      DEBUG_YASCII   yLOG_note    ("notes are globally turned-off");
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   DEBUG_YASCII   yLOG_char    ("d_size"    , myASCII.d_size);
   if (myASCII.d_size   == 'u') {
      DEBUG_YASCII   yLOG_note    ("notes skipped for micro boxes");
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(defenses)-----------------------*/
   DEBUG_YASCII   yLOG_point   ("a_note"    , a_note);
   --rce;  if (a_note  == NULL) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_info    ("a_note"    , a_note);
   /*---(hidden title)-------------------*/
   if (a_note [0] == '\0') {
      DEBUG_YASCII   yLOG_note    ("empty note, nothing to do");
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(prepare)------------------------*/
   lb = strlen (a_note);
   if (lb > 4)  sprintf (x_note, "€%.4s>", a_note);
   else         sprintf (x_note, "€%.4s€", a_note);
   la = strlen (x_note);
   DEBUG_YASCII   yLOG_info    ("x_note"    , x_note);
   /*---(print)--------------------------*/
   rc = yASCII_print (a_bx + a_wide - la - 1, a_by + a_tall - 1, x_note);
   DEBUG_YASCII   yLOG_value   ("print"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 1;
}

char
yascii_box__block       (char a_arrange, short a_bx, short a_by, char a_wide, char a_tall, char a_block)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_block     [LEN_TERSE] = "";
   /*---(header)-------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(quick-out)----------------------*/
   DEBUG_YASCII   yLOG_char    ("a_arrange" , a_arrange);
   if (a_arrange == YASCII_BASE || a_arrange == YASCII_NODE) {
      DEBUG_YASCII   yLOG_note    ("not applicable to YASCII_BASE/YASCII_NODE");
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   DEBUG_YASCII   yLOG_char    ("d_blocks"  , myASCII.d_blocks);
   if (myASCII.d_blocks != 'y') {
      DEBUG_YASCII   yLOG_note    ("blocks are globally turned-off");
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   DEBUG_YASCII   yLOG_char    ("d_size"    , myASCII.d_size);
   if (myASCII.d_size   == 'u') {
      DEBUG_YASCII   yLOG_note    ("blocks skipped for micro boxes");
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(defenses)-----------------------*/
   DEBUG_YASCII   yLOG_char    ("a_block"   , a_block);
   --rce;  if ((unsigned) a_block <= 32) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(no block)-----------------------*/
   if (a_block == '-') {
      DEBUG_YASCII   yLOG_note    ("block is unassigned");
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(prepare)------------------------*/
   sprintf (x_block, "€%c€", a_block);
   DEBUG_YASCII   yLOG_info    ("x_block"   , x_block);
   /*---(print)--------------------------*/
   rc = yASCII_print (a_bx + 1, a_by + a_tall - 1, x_block);
   DEBUG_YASCII   yLOG_value   ("print"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 1;
}

char
yascii_box__counts      (char a_arrange, short a_bx, short a_by, char a_wide, char a_tall, char a_npred, char a_nsucc)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_count     [LEN_TERSE] = "";
   /*---(header)-------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(quick-out)----------------------*/
   DEBUG_YASCII   yLOG_char    ("a_arrange" , a_arrange);
   if (a_arrange == YASCII_BASE) {
      DEBUG_YASCII   yLOG_note    ("not applicable to YASCII_BASE");
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   DEBUG_YASCII   yLOG_char    ("d_counts"  , myASCII.d_counts);
   if (myASCII.d_counts != 'y') {
      DEBUG_YASCII   yLOG_note    ("counts are globally turned-off");
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   DEBUG_YASCII   yLOG_char    ("d_size"    , myASCII.d_size);
   if (myASCII.d_size   == 'u') {
      DEBUG_YASCII   yLOG_note    ("counts skipped for micro boxes");
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   if (a_npred <= 0 && a_nsucc <= 0) {
      DEBUG_YASCII   yLOG_note    ("counts are both empty, nothing to do");
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(predeccessors)------------------*/
   DEBUG_YASCII   yLOG_char    ("a_npred"   , a_npred);
   if (a_npred >= 0) {
      if (a_arrange == YASCII_TECH) {
         switch (a_npred) {
         case 0  : strcpy (x_count, " ");  break;
         case 1  : strcpy (x_count, "Á");  break;
         case 2  : strcpy (x_count, "Â");  break;
         case 3  : strcpy (x_count, "Ã");  break;
         case 4  : strcpy (x_count, "Ä");  break;
         default : strcpy (x_count, "Å");  break;
         }
         DEBUG_YASCII   yLOG_info    ("x_count"   , x_count);
         rc = yASCII_print (a_bx + 1, a_by + a_tall - 2, x_count);
      } else {
         if      (a_npred == 0)   strcpy  (x_count, "  ");
         else if (a_npred >  99)  strcpy  (x_count, "**");
         else                     sprintf (x_count, "%-2d", a_npred);
         DEBUG_YASCII   yLOG_info    ("x_count"   , x_count);
         rc = yASCII_print (a_bx + 1, a_by + a_tall, x_count);
      }
   }
   /*---(successors)---------------------*/
   DEBUG_YASCII   yLOG_char    ("a_nsucc"   , a_nsucc);
   if (a_nsucc >= 0) {
      if (a_arrange == YASCII_TECH) {
         switch (a_nsucc) {
         case 0  : strcpy (x_count, " ");  break;
         case 1  : strcpy (x_count, "Á");  break;
         case 2  : strcpy (x_count, "Â");  break;
         case 3  : strcpy (x_count, "Ã");  break;
         case 4  : strcpy (x_count, "Ä");  break;
         default : strcpy (x_count, "Å");  break;
         }
         DEBUG_YASCII   yLOG_info    ("x_count"   , x_count);
         rc = yASCII_print (a_bx + a_wide - 2, a_by + a_tall - 2, x_count);
      } else {
         if      (a_nsucc == 0)   strcpy  (x_count, "  ");
         else if (a_nsucc >  99)  strcpy  (x_count, "**");
         else                     sprintf (x_count, "%2d", a_nsucc);
         DEBUG_YASCII   yLOG_info    ("x_count"   , x_count);
         rc = yASCII_print (a_bx + a_wide - 3, a_by + a_tall, x_count);
      }
   }
   /*---(trouble)------------------------*/
   DEBUG_YASCII   yLOG_value   ("print"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 1;
}

char
yASCII_box_full         (char a_heavy, char a_arrange, char a_col, char a_row, short a_bx, short a_by, char a_wide, char a_tall, char a_title [LEN_TITLE], char a_note [LEN_SHORT], char a_block, char a_npred, char a_nsucc)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_title     [LEN_TITLE] = "";
   short       n           =    0;
   char        x_line      [LEN_HUND]  = "";
   short       l           =    0;
   /*---(header)-------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   DEBUG_YASCII   yLOG_complex ("a_args"    , "%c, %c, %3dx, %3dy, %3dw, %3dt", ychrvisible (a_heavy), ychrvisible (a_arrange), a_bx, a_by, a_wide, a_tall);
   DEBUG_YASCII   yLOG_complex ("config"    , "%cb, %ct, %cb", ychrvisible (myASCII.d_box), ychrvisible (myASCII.d_tie), ychrvisible (myASCII.d_bound));
   /*---(defenses)-----------------------*/
   if (a_arrange == 0 || strchr (YASCII_ARRANGE, a_arrange) == NULL) {
      a_arrange = YASCII_BASE;
      DEBUG_YASCII   yLOG_char    ("a_arrange" , a_arrange);
   }
   DEBUG_YASCII   yLOG_value   ("S_nbox"    , S_nbox);
   --rce;  if (S_nbox >= LEN_HUND) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_point   ("a_title"   , a_title);
   --rce;  if (a_title == NULL) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   if (strcmp (a_title, "") == 0)  sprintf (x_title, "·%2d", S_nbox);
   else                            strlcpy (x_title, a_title, LEN_TITLE);
   DEBUG_YASCII   yLOG_info    ("x_title"   , x_title);
   n = yascii_box_by_name (x_title);
   DEBUG_YASCII   yLOG_value   ("dup?"      , n);
   --rce;  if (n >= 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_point   ("a_note"    , a_note);
   --rce;  if (a_note  == NULL) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_info    ("a_note"    , a_note);
   /*---(check grid)---------------------*/
   if (a_col >= 0)   a_bx = myASCII.x_left + (a_col * myASCII.x_wide);
   if (a_row >= 0)   a_by = myASCII.y_topp + (a_row * myASCII.y_tall);
   /*---(outline)------------------------*/
   rc = yascii_box__outline (a_heavy, a_bx, a_by, a_wide, a_tall, YASCII_MERGE);
   DEBUG_YASCII   yLOG_value   ("outline"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(title)--------------------------*/
   rc = yascii_box__title   (a_arrange, a_bx, a_by, a_wide, a_tall, x_title);
   DEBUG_YASCII   yLOG_value   ("title"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(note)---------------------------*/
   rc = yascii_box__note    (a_arrange, a_bx, a_by, a_wide, a_tall, a_note);
   DEBUG_YASCII   yLOG_value   ("note"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(block)--------------------------*/
   rc = yascii_box__block   (a_arrange, a_bx, a_by, a_wide, a_tall, a_block);
   DEBUG_YASCII   yLOG_value   ("block"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(stats)--------------------------*/
   rc = yascii_box__counts  (a_arrange, a_bx, a_by, a_wide, a_tall, a_npred, a_nsucc);
   DEBUG_YASCII   yLOG_value   ("block"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(add box)------------------------*/
   rc = yascii_box__add  (a_heavy, a_arrange, a_col, a_row, a_bx, a_by, a_wide, a_tall, x_title, a_note, a_block, a_npred, a_nsucc);
   DEBUG_YASCII   yLOG_value   ("add"       , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                        specialty stuff                       ----===*/
/*====================------------------------------------====================*/
static void  o___SPECIALTY_______o () { return; }

char
yascii_vertical         (short x, short yt, short yh, short yb)
{
   int         i           =    0;
   yASCII_draw_merge (x, yt, '‰');
   for (i = yt + 1; i <= yb - 1; ++i) yASCII_draw_merge (x,  i, '');
   yASCII_draw_merge (x, yh, 'Š');
   yASCII_draw_merge (x, yb, 'ˆ');
   return 0;
}

char
yASCII_frame_full       (char a_bcol, char a_brow, char a_ecol, char a_erow, char a_title [LEN_TITLE], char a_1col, char a_1head [LEN_TITLE], char a_2col, char a_2head [LEN_TITLE], char a_3col, char a_3head [LEN_TITLE], char a_4col, char a_4head [LEN_TITLE])
{
   /*---(locals)-----------+-----+-----+-*/
   int         l           =    0;
   char        s           [LEN_RECD]  = "";
   int         xb, yb, xe, ye, yt, yh;
   int         y_topp, x_left;
   int         i           =    0;
   int         x;
   /*---(prepare)---------------------*/
   xb = myASCII.x_left + (a_bcol * myASCII.x_wide);
   yb = myASCII.y_topp + (a_brow * myASCII.y_tall);
   xe = myASCII.x_left + (a_ecol * myASCII.x_wide) + myASCII.x_side;
   ye = myASCII.y_topp + (a_erow * myASCII.y_tall) + myASCII.y_side;
   y_topp = yb;
   x_left = xb;
   /*---(adjust to style)-------------*/
   switch (myASCII.d_size) {
   case YASCII_MICRO   :
      xb -= 2; xe += 2; yb -= 6; ye += 3; yt = yb + 1; yh = yb + 4;
      break;
   case YASCII_LARGE   :
      xb -= 3; xe += 3; yb -= 6; ye += 3; yt = yb + 1; yh = yb + 4;
      break;
   case YASCII_HUGE    :
      xb -= 4; xe += 4; yb -= 6; ye += 3; yt = yb + 1; yh = yb + 4;
      break;
   case YASCII_DEFAULT : default :
      xb -= 2; xe += 2; yb -= 6; ye += 3; yt = yb + 1; yh = yb + 4;
      break;
   }
   /*---(top)-------------------------*/
   l = xe - xb - 2;
   sprintf (s, "ƒ%*.*s‚", l, l, YSTR_HORZ);
   yASCII_print (xb, yt, s);
   /*---(middle)----------------------*/
   sprintf (s, "%*.*s", l, l, YSTR_EMPTY);
   for (i = yt + 1; i <= ye - 1; ++i)  yASCII_print (xb, i, s);
   /*---(bottom)----------------------*/
   sprintf (s, "„%*.*s…", l, l, YSTR_HORZ);
   yASCII_print (xb, ye - 1, s);
   /*---(header line)-----------------*/
   sprintf (s, "‡%*.*s†", l, l, YSTR_EDOTS);
   yASCII_print (xb, yh, s);
   /*---(column numbers)--------------*/
   for (i = a_bcol; i <= a_ecol; ++i) {
      sprintf (s, "%02d", i);
      yASCII_print (x_left + (myASCII.x_wide * i) + trunc (myASCII.x_side / 2.0) - 1, ye - 1, s);
   }
   /*---(title)-----------------------*/
   if (a_title != NULL && strcmp (a_title, "") != 0) {
      l = strlen (a_title);
      sprintf (s, "ƒ%*.*s‚", l + 2, l + 2, YSTR_HORZ);
      yASCII_print (x_left, yb    , s);
      sprintf (s, "† %s ‡", a_title);
      yASCII_print (x_left, yb + 1, s);
      sprintf (s, "„%*.*s…", l + 2, l + 2, YSTR_HORZ);
      yASCII_print (x_left, yb + 2, s);
      /*> yASCII_print (my.x_min + 30, 0, "absolutely everything relies (or should rely) on this block");   <*/
   }
   /*---(verticals)-------------------*/
   x = x_left;
   if (a_1head != NULL)  yASCII_print (x, yh, a_1head);
   if (a_2col > 0) {
      x = x_left + (a_2col * myASCII.x_wide) + myASCII.x_side - 1;
      yascii_vertical (x, yt, yh, ye - 1);
      x += myASCII.x_gap + 1;
      if (a_2head != NULL)  yASCII_print (x, yh, a_2head);
   }
   if (a_3col > 0) {
      x = x_left + (a_3col * myASCII.x_wide) + myASCII.x_side - 1;
      yascii_vertical (x, yt, yh, ye - 1);
      x += myASCII.x_gap + 1;
      if (a_3head != NULL)  yASCII_print (x, yh, a_3head);
   }
   if (a_4col > 0) {
      x = x_left + (a_4col * myASCII.x_wide) + myASCII.x_side - 1;
      yascii_vertical (x, yt, yh, ye - 1);
      x += myASCII.x_gap + 1;
      if (a_4head != NULL)  yASCII_print (x, yh, a_4head);
   }
   /*---(complete)--------------------*/
   return 0;
}

char yASCII_frame  (char a_bcol, char a_brow, char a_ecol, char a_erow, char a_title [LEN_TITLE]) { return yASCII_frame_full (a_bcol, a_brow, a_ecol, a_erow, a_title, -1, "", -1, "", -1, "", -1, ""); }

char
yASCII_bound            (char a_type, char a_heavy, char a_bcol, char a_brow, char a_ecol, char a_erow)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        s           [LEN_RECD]  = "";
   int         xb, yb, xe, ye;
   int         i           =    0;
   char        x_left      =  ' ';
   char        x_righ      =  ' ';
   char        x_topp      =  ' ';
   char        x_bott      =  ' ';
   /*---(prepare)---------------------*/
   xb = myASCII.x_left + (a_bcol * myASCII.x_wide);
   yb = myASCII.y_topp + (a_brow * myASCII.y_tall);
   xe = myASCII.x_left + (a_ecol * myASCII.x_wide) + myASCII.x_side - 1;
   ye = myASCII.y_topp + (a_erow * myASCII.y_tall) + myASCII.y_side - 1;
   /*---(set border type)-------------*/
   rc = yascii_draw_heaviness (a_heavy, &x_left, &x_topp, &x_righ, &x_bott);
   --rce;  if (rc < 0)  return rce;
   /*---(set margins)-----------------*/
   --rce;  switch (a_type) {
   case YASCII_BOUND   :
      break;
   case YASCII_BBOUND  :
      xb -= 1;  xe += 1;  yb -= 1;  ye -= 1;
      break;
   case YASCII_FRAME   :
      for (i = 0; i < LEN_TERSE; ++i) {
         if (myASCII.d_size == '£')                   break;
         if (myASCII.d_size != zASCII_bound [i].abbr)  continue;
         xb -= zASCII_bound [i].x_righ;
         xe += zASCII_bound [i].x_righ;
         yb -= zASCII_bound [i].x_righ;
         ye += zASCII_bound [i].x_righ;
         break;
      }
      break;
   case YASCII_BFRAME  :
      for (i = 0; i < LEN_TERSE; ++i) {
         if (myASCII.d_size == '£')                   break;
         if (myASCII.d_size != zASCII_bound [i].abbr)  continue;
         xb += zASCII_bound [i].x_left;
         xe += zASCII_bound [i].x_righ;
         yb += zASCII_bound [i].y_topp;
         ye += zASCII_bound [i].y_bott;
         break;
      }
      break;
   default  :
      return rce;
      break;
   }
   /*---(top)-------------------------*/
   yASCII_draw_merge (xb, yb, 'ƒ');
   for (i = xb + 1; i < xe; ++i)  yASCII_draw_merge (i, yb, x_topp);
   yASCII_draw_merge (xe, yb, '‚');
   /*---(middle)----------------------*/
   for (i = yb + 1; i < ye; ++i) {
      yASCII_draw_merge (xb, i, x_left);
      yASCII_draw_merge (xe, i, x_righ);
   }
   /*---(bottom)----------------------*/
   yASCII_draw_merge (xb, ye, '„');
   for (i = xb + 1; i < xe; ++i)  yASCII_draw_merge (i, ye, x_bott);
   yASCII_draw_merge (xe, ye, '…');
   /*---(complete)--------------------*/
   return 0;
}

char
yASCII_node             (short a_bx, short a_by, char a_symbol)
{
   char        x_title     [LEN_SHORT] = "";
   if ((unsigned) a_symbol > 32)  sprintf (x_title, "%c", a_symbol);
   return yASCII_box_full (YASCII_SOLID, YASCII_NODE, -1, -1, a_bx, a_by, 5, 3, x_title, "", '-', 0, 0);
}


