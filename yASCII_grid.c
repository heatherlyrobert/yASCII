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



/*====================------------------------------------====================*/
/*===----                         configuration                        ----===*/
/*====================------------------------------------====================*/
static void  o___CONFIG__________o () { return; }

char
yASCII_grid_set_full    (char a_size, char a_decor, short x_left, short y_topp)
{
   /*---(header)-------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(style)--------------------------*/
   myASCII.d_size      = a_size;
   switch (a_decor) {
   case YASCII_NONE   :
      myASCII.d_titles = '-'; myASCII.d_notes  = '-';
      myASCII.d_blocks = '-'; myASCII.d_counts = '-';
      break;
   case YASCII_NAMES  :
      myASCII.d_titles = 'y'; myASCII.d_notes  = '-';
      myASCII.d_blocks = '-'; myASCII.d_counts = '-';
      break;
   case YASCII_NOTES  :
      myASCII.d_titles = 'y'; myASCII.d_notes  = 'y';
      myASCII.d_blocks = '-'; myASCII.d_counts = '-';
      break;
   case YASCII_COUNTS :
      myASCII.d_titles = 'y'; myASCII.d_notes  = 'y';
      myASCII.d_blocks = '-'; myASCII.d_counts = 'y';
      break;
   case YASCII_MAX    :
      myASCII.d_titles = 'y'; myASCII.d_notes  = 'y';
      myASCII.d_blocks = 'y'; myASCII.d_counts = 'y';
      break;
   case YASCII_UNIT   :
      myASCII.d_titles = 'y'; myASCII.d_notes  = '-';
      myASCII.d_blocks = 'y'; myASCII.d_counts = '-';
      break;
   default            :
      myASCII.d_titles = 'y'; myASCII.d_notes  = '-';
      myASCII.d_blocks = '-'; myASCII.d_counts = '-';
      break;
   }
   /*---(upper-left corner)--------------*/
   myASCII.x_left      = x_left;
   myASCII.y_topp      = y_topp;
   /*---(grid sizing)--------------------*/
   switch (a_size) {
   case YASCII_MICRO   :
      myASCII.x_wide =  7; myASCII.x_side =  4; myASCII.x_gap =  3;
      myASCII.y_tall =  3; myASCII.y_side =  3; myASCII.y_gap =  0;
      break;
   case YASCII_LARGE   :
      myASCII.x_wide = 22; myASCII.x_side = 17; myASCII.x_gap =  5;
      myASCII.y_tall =  6; myASCII.y_side =  4; myASCII.y_gap =  2;
      break;
   case YASCII_HUGE    :
      myASCII.x_wide = 29; myASCII.x_side = 22; myASCII.x_gap =  7;
      myASCII.y_tall =  8; myASCII.y_side =  5; myASCII.y_gap =  3;
      break;
   case YASCII_DEFAULT : default   :
      myASCII.x_wide = 15; myASCII.x_side = 12; myASCII.x_gap =  3;
      myASCII.y_tall =  5; myASCII.y_side =  3; myASCII.y_gap =  2;
      break;
   }
   DEBUG_YASCII   yLOG_complex ("horz"      , "%3dl, %2dw, %2ds, %2dg", myASCII.x_left, myASCII.x_wide, myASCII.x_side, myASCII.x_gap);
   DEBUG_YASCII   yLOG_complex ("vert"      , "%3dt, %2dt, %2ds, %2dg", myASCII.y_topp, myASCII.y_tall, myASCII.y_side, myASCII.y_gap);
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yASCII_grid_set         (char a_size, char a_decor, char a_col, char a_row)
{
   /*---(locals)-----------+-----+-----+-*/
   short       x, y;
   /*---(new topp-left)------------------*/
   x = myASCII.x_wide * a_col;
   y = myASCII.y_tall * a_row;
   /*---(update grid)--------------------*/
   return yASCII_grid_set_full (a_size, a_decor, x, y);
}

char yASCII_grid_style (char a_size, char a_decor) { return yASCII_grid_set_full (a_size, a_decor, 0, 0); }



/*====================------------------------------------====================*/
/*===----                           creation                           ----===*/
/*====================------------------------------------====================*/
static void  o___CREATE__________o () { return; }

char
yASCII_grid_new_custom  (char a_size, char a_decor, char a_col, char a_row, char a_left, char a_righ, char a_topp, char a_bott, int a_wide, int a_tall)
{
   yASCII_grid_set_full (a_size, a_decor, 0, 0);
   myASCII.x_max = myASCII.x_wide * a_col - myASCII.x_gap + a_left + a_righ;
   myASCII.y_max = myASCII.y_tall * a_row - myASCII.y_gap + a_topp + a_bott;
   yASCII_new  (a_wide, a_tall);
   return yASCII_grid_set_full (a_size, a_decor, a_left, a_topp);
}

char
yASCII_grid_new_full    (char a_size, char a_decor, char a_col, char a_row, char a_left, char a_righ, char a_topp, char a_bott)
{
   yASCII_grid_set_full (a_size, a_decor, 0, 0);
   myASCII.x_max = myASCII.x_wide * a_col - myASCII.x_gap + a_left + a_righ;
   myASCII.y_max = myASCII.y_tall * a_row - myASCII.y_gap + a_topp + a_bott;
   yASCII_new  (myASCII.x_max, myASCII.y_max);
   return yASCII_grid_set_full (a_size, a_decor, a_left, a_topp);
}

char
yASCII_grid_new         (char a_size, char a_decor, char a_col, char a_row)
{
   yASCII_grid_set_full (a_size, a_decor, 0, 0);
   myASCII.x_max = myASCII.x_wide * a_col - myASCII.x_gap;
   myASCII.y_max = myASCII.y_tall * a_row - myASCII.y_gap;
   yASCII_new  (myASCII.x_max, myASCII.y_max);
   return yASCII_grid_set_full (a_size, a_decor, 0, 0);
}



/*====================------------------------------------====================*/
/*===----                              boxes                           ----===*/
/*====================------------------------------------====================*/
static void  o___BOXES___________o () { return; }

char
yASCII_grid_box         (char a_col, char a_row, char a_title [LEN_TITLE], char a_note [LEN_SHORT], char a_block, char a_npred, char a_nsucc)
{
   return yASCII_box_full (myASCII.d_box, YASCII_STD, a_col, a_row, -1, -1, myASCII.x_side, myASCII.y_side, a_title, a_note, a_block, a_npred, a_nsucc);
}

char
yASCII_grid_box_simple  (char a_col, char a_row, char a_title [LEN_TITLE])
{
   return yASCII_grid_box (a_col, a_row, a_title, "", '-', 0, 0);
}

char
yASCII_grid_node         (char a_col, char a_row, char a)
{
   char        x_title     [LEN_SHORT] = "";
   if ((unsigned) a > 32)  sprintf (x_title, "%c", a);
   return yASCII_box_full (myASCII.d_box, YASCII_NODE, a_col, a_row, -1, -1, 5, 3, x_title, "", '-', 0, 0);
}



/*====================------------------------------------====================*/
/*===----                         unit testing                         ----===*/
/*====================------------------------------------====================*/
static void  o___CONNECT_________o () { return; }

/*
 *    ƒ²²²†   ‡²²²‚        ƒ²²‰€€€‰²²‚
 *    Œƒ²²†   ‡²²‚Œ        Œƒ²†   ‡²‚Œ
 *  ‡²…Œƒ²†   ‡²‚Œ„²†   €€‰…Œƒˆ€€€ˆ‚Œ„‰€€
 *  ‡²²…Œ       Œ„²²†     ‡²…Œ     Œ„²†
 *  ‡²²²…       „²²²†   €€ˆ²²…     „²²ˆ€€   
 *
 *  ‡²²²‚       ƒ²²²†   €€‰²²‚     ƒ²²‰€€
 *  ‡²²‚Œ       Œƒ²²†     ‡²‚Œ     Œƒ²†
 *  ‡²‚Œ„²†   ‡²…Œƒ²†   €€ˆ‚Œ„‰€€€‰…Œƒˆ€€
 *    Œ„²²†   ‡²²…Œ        Œ„²†   ‡²…Œ 
 *    „²²²†   ‡²²²…        „²²ˆ€€€ˆ²²…
 */

/*
 *     ‡‰‰‰†
 *
 *     ‡²‰‰‰²†
 *
 *     ‡²‰²‰²‰²†
 *
 */


char yASCII_tie_heavy        (char a_heavy) { myASCII.d_tie = a_heavy;  return 0; }

char
yASCII_tie_full         (char a_heavy, short bx, short by, short ex, short ey, char a_tall, char a_blane, char a_vlane, char a_elane)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_dir       =    0;
   int         i           =    0;
   int         x_beg, x_vrt, x_end;
   int         y_bot, y_top;
   char        x_vert, x_horz, x_halt;
   char        x_cnt       =    0;
   /*---(enter)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   DEBUG_YASCII   yLOG_complex ("a_args"    , "%c  %3dbx, %3dby, %3dex, %3dey, %1dbl, %1dvl, %1del", a_heavy, bx, by, ex, ey, a_tall, a_blane, a_vlane, a_elane);
   /*---(lines)--------------------------*/
   rc = yascii_draw_heaviness (a_heavy, &x_vert, &x_horz, NULL, NULL);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   if (x_horz == '')  x_halt = '€';
   else                x_halt = x_horz;
   DEBUG_YASCII   yLOG_complex ("lines"     , "%c  %c  %c", x_vert, x_horz, x_halt);
   /*---(interpret lanes)----------------*/
   switch (a_blane) {
   case YASCII_VTOP :  a_blane = 0;                                   break;
   case YASCII_VMID :  a_blane = trunc ((myASCII.y_side - 1) / 2.0);  break;
   case YASCII_VBOT :  a_blane = myASCII.y_side - 1;                  break;
   }
   DEBUG_YASCII   yLOG_value   ("a_blane"   , a_blane);
   switch (a_vlane) {
   case YASCII_HLEF :  if (myASCII.x_gap == 3)  a_vlane = 1;  else a_vlane = 2; break;
   case YASCII_HCEN :  a_vlane = trunc ((myASCII.x_gap  - 1) / 2.0) + 1;  break;
   case YASCII_HRIG :  if (myASCII.x_gap == 3)  a_vlane = 3;  else a_vlane = myASCII.x_gap - 1; break;
   }
   DEBUG_YASCII   yLOG_value   ("a_vlane"   , a_vlane);
   switch (a_elane) {
   case YASCII_VTOP :  a_elane = 0;                                   break;
   case YASCII_VMID :  a_elane = trunc ((myASCII.y_side - 1) / 2.0);  break;
   case YASCII_VBOT :  a_elane = myASCII.y_side - 1;                  break;
   }
   DEBUG_YASCII   yLOG_value   ("a_elane"   , a_elane);
   /*---(direction)----------------------*/
   if      (by + a_blane == ey + a_elane)   x_dir = 'Ö';
   else if (by + a_blane <  ey + a_elane)   x_dir = 'Õ';
   else                                     x_dir = 'Ô';
   DEBUG_YASCII   yLOG_char    ("x_dir"     , x_dir);
   /*---(start)--------------------------*/
   if      (a_blane == 0)            yASCII_print (bx, by             , "‰"); 
   else if (a_blane == a_tall - 1)   yASCII_print (bx, by + a_tall - 1, "ˆ"); 
   else                              yASCII_print (bx, by + a_blane   , "‡"); 
   /*---(finish)-------------------------*/
   if      (a_elane == 0)            yASCII_print (ex, ey             , "‰"); 
   else if (a_elane == a_tall - 1)   yASCII_print (ex, ey + a_tall - 1, "ˆ"); 
   else                              yASCII_print (ex, ey + a_elane   , "†"); 
   /*---(connect)------------------------*/
   switch (x_dir) {
   case 'Ö' : 
      DEBUG_YASCII   yLOG_note    ("horizontal");
      for (x_cnt = 0, i = bx + 1; i <= ex - 1; ++i)    yASCII_draw_double (x_cnt++, i, by + a_blane, x_horz, x_halt);
      break;
   case 'Ô' : 
      DEBUG_YASCII   yLOG_note    ("ascending/upward line");
      x_beg  = bx + 1;
      x_vrt  = ex - (myASCII.x_gap + 1) + a_vlane;
      x_end  = ex - 1;
      y_bot  = by + a_blane;
      y_top  = ey + a_elane;
      DEBUG_YASCII   yLOG_complex ("pos"       , "H %3db, %3dv, %3de  V %3db, %3dt", x_beg, x_vrt, x_end, y_bot, y_top);
      for (x_cnt = 0, i = x_beg; i < x_vrt; ++i)              yASCII_draw_double (x_cnt++, i, y_bot, x_horz, x_halt);
      yASCII_draw_merge (x_vrt, y_bot, '…');
      for (i = y_bot - 1; i >= y_top + 1; --i)                yASCII_draw_merge (x_vrt, i, x_vert);
      yASCII_draw_merge (x_vrt, y_top, 'ƒ');
      for (x_cnt = 0, i = x_vrt + 1; i <= x_end; ++i)         yASCII_draw_double (x_cnt++, i, y_top, x_horz, x_halt);
      break;
   case 'Õ' :
      DEBUG_YASCII   yLOG_note    ("descending/downward line");
      for (x_cnt = 0, i = bx + 1; i < bx + a_vlane; ++i)      yASCII_draw_double (x_cnt++, i, by + a_blane, x_horz, x_halt);
      yASCII_draw_merge (bx + a_vlane, by + a_blane, '‚');
      for (i = by + a_blane + 1; i <= ey + a_elane - 1; ++i)  yASCII_draw_merge (bx + a_vlane, i, x_vert);
      yASCII_draw_merge (bx + a_vlane, ey + a_elane, '„');
      for (x_cnt = 0, i = bx + a_vlane + 1; i <= ex - 1; ++i) yASCII_draw_double (x_cnt++, i, ey + a_elane, x_horz, x_halt);
      break;
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yASCII_tie_grid_heavy   (char a_heavy, char a_bcol, char a_brow, char a_ecol, char a_erow)
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
   return yASCII_tie_full (a_heavy, bx, by, ex, ey, myASCII.y_tall - myASCII.y_gap, YASCII_VMID, YASCII_HCEN, YASCII_VMID);
}

char yASCII_tie_grid         (char a_bcol, char a_brow, char a_ecol, char a_erow) { return yASCII_tie_grid_heavy (myASCII.d_tie, a_bcol, a_brow, a_ecol, a_erow); }

char
yASCII_tie_exact_heavy  (char a_heavy, char a_bcol, char a_brow, char a_ecol, char a_erow, char a_blane, char a_vlane, char a_elane)
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
   return yASCII_tie_full (a_heavy, bx, by, ex, ey, myASCII.y_tall - myASCII.y_gap, a_blane, a_vlane, a_elane);
}

char yASCII_tie_exact        (char a_bcol, char a_brow, char a_ecol, char a_erow, char a_blane, char a_vlane, char a_elane) { return yASCII_tie_exact_heavy (myASCII.d_tie, a_bcol, a_brow, a_ecol, a_erow, a_blane, a_vlane, a_elane); }


