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

char yASCII_style (char a_size, char a_decor) { return yASCII_grid_set_full (a_size, a_decor, 0, 0); }

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
