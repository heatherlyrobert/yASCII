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
   uchar       b_x, b_y, b_w, b_t;
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
yascii_box__clear       (void)
{
   int         i           =    0;
   for (i = 0; i < LEN_HUND; ++i) {
      S_boxes [i].b_heavy = S_boxes [i].b_arrange = '-';
      strcpy (S_boxes [i].b_title, "");
      S_boxes [i].b_x = S_boxes [i].b_y = S_boxes [i].b_w = S_boxes [i].b_t = 0;
      strcpy (S_boxes [i].b_note , "");
      S_boxes [i].b_block = '-';
      S_boxes [i].b_npred = S_boxes [i].b_nsucc = 0;
   }
   S_nbox = 0;
   S_cbox = 0;
   return 0;
}

char
yascii_box_find         (char a_title [LEN_TITLE])
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
      strcpy (unit_answer, "seq  ---title---------------------  H  A  --x --y --w --t  note  B  pr sc  Ï");
      DEBUG_YDLST   yLOG_sexit   (__FUNCTION__);
      return unit_answer;
   }
   /*---(defaults)-----------------------*/
   strcpy (unit_answer, "··-  ´····························  -  -  ··- ··- ··- ··-  ´···  -  ·- ·-  Ï");
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
      sprintf (unit_answer, "%3d  %-29.29s  %c  %c  %3d %3d %3d %3d  %-4.4s  %c  %2d %2d  Ï", x_curr,
            x_title, S_boxes [x_curr].b_heavy, S_boxes [x_curr].b_arrange,
            S_boxes [x_curr].b_x, S_boxes [x_curr].b_y, S_boxes [x_curr].b_w, S_boxes [x_curr].b_t,
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
yascii__outline         (char a_heavy, short x, short y, short w, short t, char a_mode)
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
   /*---(header)-------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   DEBUG_YASCII   yLOG_complex ("a_args"    , "%c, %3dx, %3dy, %3dw, %3dt, %c", a_heavy, x, y, w, t, a_mode);
   /*---(defense)------------------------*/
   --rce;  if (a_mode != YASCII_CLEAR && a_mode != YASCII_MERGE) {
      DEBUG_YASCII   yLOG_note    ("illegal mode (CLEAR or MERGE only)");
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(lines)--------------------------*/
   rc = yascii_heaviness (a_heavy, &x_left, &x_topp, &x_righ, &x_bott);
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
   /*---(top)----------------------------*/
   yASCII_draw_merge (x        , y, 'ƒ');
   for (x_cnt = 0, i = x + 1; i < x + w - 1; ++i) {
      yASCII_draw_double (x_cnt++, i, y, x_topp, x_talt);
      c = yASCII_draw_get (i, y);
      if (a_mode == YASCII_CLEAR && c == 'Š') yASCII_print  (i, y, "ˆ", YASCII_CLEAR);
   }
   yASCII_draw_merge (x + w - 1, y, '‚');
   /*---(middle)-------------------------*/
   sprintf (x_line, "%*.*s", w - 2, w - 2, YSTR_EMPTY);
   for (i = 1; i < t - 1; ++i) {
      /*---(left)-----------*/
      yASCII_draw_merge (x, y + i, x_left);
      c = yASCII_draw_get (x, y + i);
      if (a_mode == YASCII_CLEAR && c == 'Š') yASCII_print  (x, y + i, "†", YASCII_CLEAR);
      /*---(center)---------*/
      if (a_mode == YASCII_CLEAR)             yASCII_print  (x + 1, y + i, x_line, YASCII_CLEAR);
      /*---(right)----------*/
      yASCII_draw_merge (x + w - 1, y + i, x_righ);
      c = yASCII_draw_get (x + w - 1, y + i);
      if (a_mode == YASCII_CLEAR && c == 'Š') yASCII_print  (x + w - 1, y + i, "‡", YASCII_CLEAR);
      /*---(done)-----------*/
   }
   /*---(bottom)-------------------------*/
   yASCII_draw_merge (x        , y + t - 1, '„');
   for (x_cnt = 0, i = x + 1; i < x + w - 1; ++i) {
      yASCII_draw_double (x_cnt++, i, y + t - 1, x_bott, x_balt);
      c = yASCII_draw_get (i, y + t - 1);
      if (a_mode == YASCII_CLEAR && c == 'Š') yASCII_print  (i, y + t - 1, "‰", YASCII_CLEAR);
   }
   yASCII_draw_merge (x + w - 1, y + t - 1, '…');
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yASCII_box_full         (char a_heavy, char a_arrange, short x, short y, short w, short t, char a_title [LEN_TITLE], char a_note [LEN_SHORT], char a_block, char a_npred, char a_nsucc)
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
   DEBUG_YASCII   yLOG_complex ("a_args"    , "%c, %c, %3dx, %3dy, %3dw, %3dt", ychrvisible (a_heavy), ychrvisible (a_arrange), x, y, w, t);
   DEBUG_YASCII   yLOG_complex ("config"    , "%cb, %ct, %cb", ychrvisible (myASCII.d_box), ychrvisible (myASCII.d_tie), ychrvisible (myASCII.d_bound));
   /*---(defenses)-----------------------*/
   if (a_arrange == 0 || strchr ("-sbt", a_arrange) == NULL) {
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
   n = yascii_box_find (x_title);
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
   /*---(lines)--------------------------*/
   rc = yascii__outline (a_heavy, x, y, w, t, YASCII_CLEAR);
   DEBUG_YASCII   yLOG_value   ("outline"   , rc);
   /*---(title)--------------------------*/
   if (a_arrange != YASCII_BASE) {
      if (myASCII.d_titles == 'y' && x_title [0] != '·') {
         ystrlcpy (x_line, x_title, w - 1);
         l = strlen (x_line);
         switch (a_arrange) {
         case YASCII_BIG  : case YASCII_TECH :
            yASCII_print (x + (w - l) / 2, y    , x_line, YASCII_CLEAR);
            break;
         case YASCII_STD  : default          :
            yASCII_print (x + 1          , y + 1, x_line, YASCII_CLEAR);
            break;
         }
      }
   }
   /*---(note)---------------------------*/
   if (a_arrange != YASCII_BASE) {
      if (myASCII.d_notes == 'y' && myASCII.d_size != 'u') {
         if (strcmp (a_note, "")  != 0) {
            sprintf (x_line, "(%.5s)", a_note);
            l = strlen (x_line);
            yASCII_print (x + w - l - 1, y + t - 1, x_line, YASCII_CLEAR);
         }
      }
   }
   /*---(block)--------------------------*/
   if (a_arrange != YASCII_BASE) {
      if (myASCII.d_blocks == 'y') {
         if (a_block != '-') {
            sprintf (x_line, "<%c>", a_block);
            yASCII_print (x + 1, y + t - 1, x_line, YASCII_CLEAR);
         }
      }
   }
   /*---(stats)--------------------------*/
   if (a_arrange != YASCII_BASE) {
      if (myASCII.d_counts == 'y' && myASCII.d_size != 'u') {
         if (a_arrange == YASCII_TECH) {
            switch (a_npred) {
            case 0  : strcpy (x_line, "" );  break;
            case 1  : strcpy (x_line, "Á");  break;
            case 2  : strcpy (x_line, "Â");  break;
            case 3  : strcpy (x_line, "Ã");  break;
            case 4  : strcpy (x_line, "Ä");  break;
            default : strcpy (x_line, "Å");  break;
            }
            yASCII_print (x + 1, y + t - 2, x_line, YASCII_CLEAR);
            switch (a_nsucc) {
            case 0  : strcpy (x_line, "" );  break;
            case 1  : strcpy (x_line, "Á");  break;
            case 2  : strcpy (x_line, "Â");  break;
            case 3  : strcpy (x_line, "Ã");  break;
            case 4  : strcpy (x_line, "Ä");  break;
            default : strcpy (x_line, "Å");  break;
            }
            yASCII_print (x + w - 2, y + t - 2, x_line, YASCII_CLEAR);
         } else {
            if (a_npred > 0) {
               if (a_npred == 1)  strcpy  (x_line, " ");
               else               sprintf (x_line, "%-3d", a_npred);
               yASCII_print (x + 1, y + t, x_line, YASCII_CLEAR);
            }
            if (a_nsucc > 0) {
               if (a_nsucc == 1)  strcpy  (x_line, "   ");
               else               sprintf (x_line, "%3d" , a_nsucc);
               yASCII_print (x + w - 4, y + t, x_line, YASCII_CLEAR);
            }
         }
      }
   }
   /*---(add box)------------------------*/
   S_boxes [S_nbox].b_heavy   = a_heavy;
   S_boxes [S_nbox].b_arrange = a_arrange;
   strncpy (S_boxes [S_nbox].b_title, x_title, LEN_TITLE);
   S_boxes [S_nbox].b_x = x;
   S_boxes [S_nbox].b_y = y;
   S_boxes [S_nbox].b_w = w;
   S_boxes [S_nbox].b_t = t;
   strncpy (S_boxes [S_nbox].b_note , a_note , LEN_SHORT);
   S_boxes [S_nbox].b_block   = a_block;
   S_boxes [S_nbox].b_npred   = a_npred;
   S_boxes [S_nbox].b_nsucc   = a_nsucc;
   ++S_nbox;
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yASCII_box_grid         (char a_col, char a_row, char a_title [LEN_TITLE], char a_note [LEN_SHORT], char a_block, char a_npred, char a_nsucc)
{
   /*---(locals)-----------+-----+-----+-*/
   short       x, y;
   /*---(prepare)------------------------*/
   x = myASCII.x_left + (a_col * myASCII.x_wide);
   y = myASCII.y_topp + (a_row * myASCII.y_tall);
   /*---(complete)-----------------------*/
   return yASCII_box_full (myASCII.d_box, YASCII_STD, x, y, myASCII.x_side, myASCII.y_side, a_title, a_note, a_block, a_npred, a_nsucc);
}

char yASCII_box_simple  (char a_col, char a_row, char a_title [LEN_TITLE]) { return yASCII_box_grid (a_col, a_row, a_title, "", '-', 0, 0); }

char
yASCII_node             (short x, short y, char a)
{
   /*---(locals)-----------+-----+-----+-*/
   char        s           [LEN_SHORT] = "";
   /*---(header)-------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(outside)------------------------*/
   yASCII_print (x, y    , "ƒ€€€‚", YASCII_CLEAR);
   yASCII_print (x, y + 1, "   ", YASCII_CLEAR);
   yASCII_print (x, y + 2, "„€€€…", YASCII_CLEAR);
   /*---(label)--------------------------*/
   if (myASCII.d_titles == 'y') {
      sprintf (s, "%c", ychrvisible (a));
      yASCII_print (x + 2, y + 1, s, YASCII_CLEAR);
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yASCII_node_grid         (char a_col, char a_row, char a)
{
   /*---(locals)-----------+-----+-----+-*/
   short       x, y;
   /*---(prepare)------------------------*/
   if (a_col < 0)  x = myASCII.x_left - 8;
   else            x = myASCII.x_left + (a_col * myASCII.x_wide);
   y = myASCII.y_topp + (a_row * myASCII.y_tall);
   /*---(complete)-----------------------*/
   return yASCII_node (x, y, a);
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
   yASCII_print (xb, yt, s, YASCII_CLEAR);
   /*---(middle)----------------------*/
   sprintf (s, "%*.*s", l, l, YSTR_EMPTY);
   for (i = yt + 1; i <= ye - 1; ++i)  yASCII_print (xb, i, s, YASCII_MERGE);
   /*---(bottom)----------------------*/
   sprintf (s, "„%*.*s…", l, l, YSTR_HORZ);
   yASCII_print (xb, ye - 1, s, YASCII_CLEAR);
   /*---(header line)-----------------*/
   sprintf (s, "‡%*.*s†", l, l, YSTR_EDOTS);
   yASCII_print (xb, yh, s, YASCII_CLEAR);
   /*---(column numbers)--------------*/
   for (i = a_bcol; i <= a_ecol; ++i) {
      sprintf (s, "%02d", i);
      yASCII_print (x_left + (myASCII.x_wide * i) + trunc (myASCII.x_side / 2.0) - 1, ye - 1, s, YASCII_CLEAR);
   }
   /*---(title)-----------------------*/
   if (a_title != NULL && strcmp (a_title, "") != 0) {
      l = strlen (a_title);
      sprintf (s, "ƒ%*.*s‚", l + 2, l + 2, YSTR_HORZ);
      yASCII_print (x_left, yb    , s, YASCII_CLEAR);
      sprintf (s, "† %s ‡", a_title);
      yASCII_print (x_left, yb + 1, s, YASCII_CLEAR);
      sprintf (s, "„%*.*s…", l + 2, l + 2, YSTR_HORZ);
      yASCII_print (x_left, yb + 2, s, YASCII_CLEAR);
      /*> yASCII_print (my.x_min + 30, 0, "absolutely everything relies (or should rely) on this block", YASCII_CLEAR);   <*/
   }
   /*---(verticals)-------------------*/
   x = x_left;
   if (a_1head != NULL)  yASCII_print (x, yh, a_1head, YASCII_CLEAR);
   if (a_2col > 0) {
      x = x_left + (a_2col * myASCII.x_wide) + myASCII.x_side - 1;
      yascii_vertical (x, yt, yh, ye - 1);
      x += myASCII.x_gap + 1;
      if (a_2head != NULL)  yASCII_print (x, yh, a_2head, YASCII_CLEAR);
   }
   if (a_3col > 0) {
      x = x_left + (a_3col * myASCII.x_wide) + myASCII.x_side - 1;
      yascii_vertical (x, yt, yh, ye - 1);
      x += myASCII.x_gap + 1;
      if (a_3head != NULL)  yASCII_print (x, yh, a_3head, YASCII_CLEAR);
   }
   if (a_4col > 0) {
      x = x_left + (a_4col * myASCII.x_wide) + myASCII.x_side - 1;
      yascii_vertical (x, yt, yh, ye - 1);
      x += myASCII.x_gap + 1;
      if (a_4head != NULL)  yASCII_print (x, yh, a_4head, YASCII_CLEAR);
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
   rc = yascii_heaviness (a_heavy, &x_left, &x_topp, &x_righ, &x_bott);
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


