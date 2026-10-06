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

/*
 *
 *   there are three connections types for lines between two boxes...
 *   1) line      direct option, exact interface
 *   2) link      middle option, eastward lines based on box names and lanes
 *   3) tie       easy option, eastward lines based on grid position only, no lanes
 *
 *
 */



/*====================------------------------------------====================*/
/*===----                          box linking                         ----===*/
/*====================------------------------------------====================*/
static void  o___LINK____________o () { return; }

/*> char                                                                                                                                                                <* 
 *> yASCII_link_full        (char a_heavy, short bx, short by, short ex, short ey, char a_tall, char a_blane, char a_vlane, char a_elane)                               <* 
 *> {                                                                                                                                                                   <* 
 *>    /+---(locals)-----------+-----+-----+-+/                                                                                                                         <* 
 *>    char        rce         =  -10;                                                                                                                                  <* 
 *>    char        rc          =    0;                                                                                                                                  <* 
 *>    char        x_dir       =    0;                                                                                                                                  <* 
 *>    int         i           =    0;                                                                                                                                  <* 
 *>    int         x_beg, x_vrt, x_end;                                                                                                                                 <* 
 *>    int         y_bot, y_top;                                                                                                                                        <* 
 *>    char        x_vert, x_horz, x_halt;                                                                                                                              <* 
 *>    char        x_cnt       =    0;                                                                                                                                  <* 
 *>    /+---(enter)--------------------------+/                                                                                                                         <* 
 *>    DEBUG_YASCII   yLOG_enter   (__FUNCTION__);                                                                                                                      <* 
 *>    DEBUG_YASCII   yLOG_complex ("a_args"    , "%c  %3dbx, %3dby, %3dex, %3dey, %1dbl, %1dvl, %1del", a_heavy, bx, by, ex, ey, a_tall, a_blane, a_vlane, a_elane);   <* 
 *>    /+---(lines)--------------------------+/                                                                                                                         <* 
 *>    rc = yascii_draw_heaviness (a_heavy, &x_vert, &x_horz, NULL, NULL);                                                                                                  <* 
 *>    --rce;  if (rc < 0) {                                                                                                                                            <* 
 *>       DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);                                                                                                              <* 
 *>       return rce;                                                                                                                                                   <* 
 *>    }                                                                                                                                                                <* 
 *>    if (x_horz == '')  x_halt = '€';                                                                                                                                <* 
 *>    else                x_halt = x_horz;                                                                                                                             <* 
 *>    DEBUG_YASCII   yLOG_complex ("lines"     , "%c  %c  %c", x_vert, x_horz, x_halt);                                                                                <* 
 *>    /+---(interpret lanes)----------------+/                                                                                                                         <* 
 *>    switch (a_blane) {                                                                                                                                               <* 
 *>    case 't' :  a_blane = 0;                                   break;                                                                                                <* 
 *>    case 'm' :  a_blane = trunc ((myASCII.y_side - 1) / 2.0);  break;                                                                                                <* 
 *>    case 'b' :  a_blane = myASCII.y_side - 1;                  break;                                                                                                <* 
 *>    }                                                                                                                                                                <* 
 *>    DEBUG_YASCII   yLOG_value   ("a_blane"   , a_blane);                                                                                                             <* 
 *>    switch (a_vlane) {                                                                                                                                               <* 
 *>    case 'l' :  if (myASCII.x_gap == 3)  a_vlane = 1;  else a_vlane = 2; break;                                                                                      <* 
 *>    case 'c' :  a_vlane = trunc ((myASCII.x_gap  - 1) / 2.0) + 1;  break;                                                                                            <* 
 *>    case 'r' :  if (myASCII.x_gap == 3)  a_vlane = 3;  else a_vlane = myASCII.x_gap - 1; break;                                                                      <* 
 *>    }                                                                                                                                                                <* 
 *>    DEBUG_YASCII   yLOG_value   ("a_vlane"   , a_vlane);                                                                                                             <* 
 *>    switch (a_elane) {                                                                                                                                               <* 
 *>    case 't' :  a_elane = 0;                                   break;                                                                                                <* 
 *>    case 'm' :  a_elane = trunc ((myASCII.y_side - 1) / 2.0);  break;                                                                                                <* 
 *>    case 'b' :  a_elane = myASCII.y_side - 1;                  break;                                                                                                <* 
 *>    }                                                                                                                                                                <* 
 *>    DEBUG_YASCII   yLOG_value   ("a_elane"   , a_elane);                                                                                                             <* 
 *>    /+---(direction)----------------------+/                                                                                                                         <* 
 *>    if      (by + a_blane == ey + a_elane)   x_dir = 'Ö';                                                                                                            <* 
 *>    else if (by + a_blane <  ey + a_elane)   x_dir = 'Õ';                                                                                                            <* 
 *>    else                                     x_dir = 'Ô';                                                                                                            <* 
 *>    DEBUG_YASCII   yLOG_char    ("x_dir"     , x_dir);                                                                                                               <* 
 *>    /+---(start)--------------------------+/                                                                                                                         <* 
 *>    if      (a_blane == 0)            yASCII_print (bx, by             , "‰");                                                                         <* 
 *>    else if (a_blane == a_tall - 1)   yASCII_print (bx, by + a_tall - 1, "ˆ");                                                                         <* 
 *>    else                              yASCII_print (bx, by + a_blane   , "‡");                                                                         <* 
 *>    /+---(finish)-------------------------+/                                                                                                                         <* 
 *>    if      (a_elane == 0)            yASCII_print (ex, ey             , "‰");                                                                         <* 
 *>    else if (a_elane == a_tall - 1)   yASCII_print (ex, ey + a_tall - 1, "ˆ");                                                                         <* 
 *>    else                              yASCII_print (ex, ey + a_elane   , "†");                                                                         <* 
 *>    /+---(connect)------------------------+/                                                                                                                         <* 
 *>    switch (x_dir) {                                                                                                                                                 <* 
 *>    case 'Ö' :                                                                                                                                                       <* 
 *>       DEBUG_YASCII   yLOG_note    ("horizontal");                                                                                                                   <* 
 *>       for (x_cnt = 0, i = bx + 1; i <= ex - 1; ++i)    yASCII_draw_double (x_cnt++, i, by + a_blane, x_horz, x_halt);                                                <* 
 *>       break;                                                                                                                                                        <* 
 *>    case 'Ô' :                                                                                                                                                       <* 
 *>       DEBUG_YASCII   yLOG_note    ("ascending/upward line");                                                                                                        <* 
 *>       x_beg  = bx + 1;                                                                                                                                              <* 
 *>       x_vrt  = ex - (myASCII.x_gap + 1) + a_vlane;                                                                                                                  <* 
 *>       x_end  = ex - 1;                                                                                                                                              <* 
 *>       y_bot  = by + a_blane;                                                                                                                                        <* 
 *>       y_top  = ey + a_elane;                                                                                                                                        <* 
 *>       DEBUG_YASCII   yLOG_complex ("pos"       , "H %3db, %3dv, %3de  V %3db, %3dt", x_beg, x_vrt, x_end, y_bot, y_top);                                            <* 
 *>       for (x_cnt = 0, i = x_beg; i < x_vrt; ++i)              yASCII_draw_double (x_cnt++, i, y_bot, x_horz, x_halt);                                                <* 
*>       yASCII_draw_merge (x_vrt, y_bot, '…');                                                                                                                            <* 
*>       for (i = y_bot - 1; i >= y_top + 1; --i)                yASCII_draw_merge (x_vrt, i, x_vert);                                                                     <* 
*>       yASCII_draw_merge (x_vrt, y_top, 'ƒ');                                                                                                                            <* 
*>       for (x_cnt = 0, i = x_vrt + 1; i <= x_end; ++i)         yASCII_draw_double (x_cnt++, i, y_top, x_horz, x_halt);                                                <* 
*>       break;                                                                                                                                                        <* 
*>    case 'Õ' :                                                                                                                                                       <* 
*>       DEBUG_YASCII   yLOG_note    ("descending/downward line");                                                                                                     <* 
*>       for (x_cnt = 0, i = bx + 1; i < bx + a_vlane; ++i)      yASCII_draw_double (x_cnt++, i, by + a_blane, x_horz, x_halt);                                         <* 
*>       yASCII_draw_merge (bx + a_vlane, by + a_blane, '‚');                                                                                                              <* 
*>       for (i = by + a_blane + 1; i <= ey + a_elane - 1; ++i)  yASCII_draw_merge (bx + a_vlane, i, x_vert);                                                              <* 
*>       yASCII_draw_merge (bx + a_vlane, ey + a_elane, '„');                                                                                                              <* 
*>       for (x_cnt = 0, i = bx + a_vlane + 1; i <= ex - 1; ++i) yASCII_draw_double (x_cnt++, i, ey + a_elane, x_horz, x_halt);                                         <* 
*>       break;                                                                                                                                                        <* 
*>    }                                                                                                                                                                <* 
*>    /+---(complete)-----------------------+/                                                                                                                         <* 
*>    DEBUG_YASCII   yLOG_exit    (__FUNCTION__);                                                                                                                      <* 
*>    return 0;                                                                                                                                                        <* 
*> }                                                                                                                                                                   <*/

char
yascii_link__defense    (short a_bx, short a_by, char a_bbase, short a_vx, short a_ex, short a_ey, char a_ebase)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*---(enter)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YASCII   yLOG_value   ("a_bx"      , a_bx);
   --rce;  if (a_bx < 0 || a_bx >= 1000) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_value   ("a_by"      , a_by);
   --rce;  if (a_by < 0 || a_by >= 1000) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_char    ("a_bbase"   , a_bbase);
   --rce;  if (a_bbase == 0 || strchr ("‚…", a_bbase) == NULL) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_value   ("a_vx"      , a_vx);
   --rce;  if (a_vx < 0 || a_vx >= 1000) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_value   ("a_ex"      , a_ex);
   --rce;  if (a_ex < 0 || a_ex >= 1000) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_value   ("a_ey"      , a_ey);
   --rce;  if (a_ey < 0 || a_ey >= 1000) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_char    ("a_ebase"   , a_ebase);
   --rce;  if (a_ebase == 0 || strchr ("ƒ„", a_ebase) == NULL) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 1;
}

char
yascii_link__ranges     (char a_end, char a_lane, char a_max, char *r_base)
{
   /*---(design notes)-------------------*/
   /*
    *   lanes are...
    *      numbers 0-20 (absolute top-bottom or left-right positions)
    *      t topmost      s start
    *      k up           h left
    *      m middle       c center
    *      j down         l right
    *      b bottom       e end
    *
    */
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        n, x_max, x_qtr, x_hlf, x_thr;
   /*---(default)------------------------*/
   if (r_base != NULL)  *r_base = 'Ï';
   /*---(defenses)-----------------------*/
   --rce;  if (a_max  <  1)      return rce;
   --rce;  if (a_lane <  0)      return rce;
   /*---(prepare)------------------------*/
   x_max = a_max - 1;
   x_qtr = x_max / 4.0;
   x_hlf = x_max / 2.0;
   x_thr = x_max - x_qtr;
   /*---(absolute)-----------------------*/
   --rce;  if (a_lane < 32) {
      if (a_lane > x_max)   return rce;
      n = a_lane;
   }
   /*---(relatives)----------------------*/
   else {
      --rce;  switch (a_lane) {
      case YASCII_VTOP : case YASCII_HSTR :  n = 0;       break;
      case YASCII_VUPR : case YASCII_HLEF :  n = x_qtr;   break;
      case YASCII_VMID : case YASCII_HCEN :  n = x_hlf;   break;
      case YASCII_VLOW : case YASCII_HRIG :  n = x_thr;   break;
      case YASCII_VBOT : case YASCII_HEND :  n = x_max;   break;
      default  :                             return rce;  break;
      }
   }
   /*---(save-back)----------------------*/
   --rce;  if (r_base != NULL) {
      switch (a_end) {
      case 'b'  : if (n == 0)  *r_base = '‰';  else if (n == x_max)  *r_base = 'ˆ';  else *r_base = '‡';  break;
      case 'e'  : if (n == 0)  *r_base = '‰';  else if (n == x_max)  *r_base = 'ˆ';  else *r_base = '†';  break;
      case '-'  : break;
      default   : return rce;  break;
      }
   }
   /*---(complete)-----------------------*/
   return n;
}

char
yascii_link__detail     (char a_heavy, short a_bx, short a_by, char a_bbase [LEN_SHORT], short a_vx, short a_ex, short a_ey, char a_ebase [LEN_SHORT])
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
   /*---(defense)------------------------*/
   rc = yascii_link__defense (a_bx, a_by, a_bbase [0], a_vx, a_ex, a_ey, a_ebase [0]);
   DEBUG_YASCII   yLOG_value   ("defense"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(lines)--------------------------*/
   rc = yascii_draw_heaviness (a_heavy, &x_vert, &x_horz, NULL, NULL);
   DEBUG_YASCII   yLOG_value   ("heavy"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   if (x_horz == '')  x_halt = '€';
   else                x_halt = x_horz;
   DEBUG_YASCII   yLOG_complex ("lines"     , "%c  %c  %c", x_vert, x_horz, x_halt);
   /*---(direction)----------------------*/
   if      (a_by == a_ey)   x_dir = 'Ö';
   else if (a_by <  a_ey)   x_dir = 'Õ';
   else                     x_dir = 'Ô';
   DEBUG_YASCII   yLOG_char    ("x_dir"     , x_dir);
   /*---(display endpionts)--------------*/
   yASCII_print (a_bx, a_by, a_bbase); 
   yASCII_print (a_ex, a_ey, a_ebase); 
   /*---(horizontal)---------------------*/
   if (x_dir == 'Ö') {
      DEBUG_YASCII   yLOG_note    ("horizontal");
      for (x_cnt = 0, i = a_bx + 1; i < a_ex; ++i)   yASCII_draw_double (x_cnt++, i, a_by, x_horz, x_halt);
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 1;
   }
   /*---(ascending/upward)---------------*/
   if (x_dir == 'Ô') {
      DEBUG_YASCII   yLOG_note    ("ascending/upward line");
      for (x_cnt = 0, i = a_bx + 1; i < a_vx; ++i)   yASCII_draw_double (x_cnt++, i, a_by, x_horz, x_halt);
      yASCII_draw_merge (a_vx, a_by, '…');
      for (i = a_by - 1; i >= a_ey + 1; --i)         yASCII_draw_merge (a_vx, i, a_vx);
      yASCII_draw_merge (a_vx, a_ey, 'ƒ');
      for (x_cnt = 0, i = a_vx + 1; i < a_ex; ++i)   yASCII_draw_double (x_cnt++, i, a_ey, x_horz, x_halt);
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 2;
   }
   /*---(decending/downward)-------------*/
   if (x_dir == 'Õ') {
      DEBUG_YASCII   yLOG_note    ("descending/downward line");
      for (x_cnt = 0, i = a_bx + 1; i < a_vx; ++i)   yASCII_draw_double (x_cnt++, i, a_by, x_horz, x_halt);
      yASCII_draw_merge (a_vx, a_by, '‚');
      for (i = a_by + 1; i <= a_ey - 1; ++i)         yASCII_draw_merge (a_bx, i, a_vx);
      yASCII_draw_merge (a_vx, a_ey, '„');
      for (x_cnt = 0, i = a_vx + 1; i < a_ex; ++i)   yASCII_draw_double (x_cnt++, i, a_ey, x_horz, x_halt);
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 3;
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, --rce);
   return rce;
}

char
yASCII_link_full        (char a_pred [LEN_TITLE], char a_succ [LEN_TITLE], char a_heavy, char a_hgap, char a_blane, char a_vlane, char a_elane)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_pred      =    0;
   char        x_succ      =    0;
   short       x_bx, x_by;
   char        x_bt;
   short       x_ex, x_ey;
   char        x_et;
   char        x_bo, x_vo, x_eo;
   short       x_vx;
   char        x_name      [LEN_SHORT] = "";
   /*---(enter)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   x_pred = yascii_box_by_name (a_pred);
   DEBUG_YASCII   yLOG_value   ("x_pred"    , x_pred);
   --rce;  if (x_pred < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   x_pred = yascii_box_by_name (a_succ);
   DEBUG_YASCII   yLOG_value   ("x_succ"    , x_succ);
   --rce;  if (x_succ < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_complex ("a_args"    , "%-20.20s to %-20.20s, %c, %1dbl, %1dvl, %1del", a_pred, a_succ, a_heavy, a_blane, a_vlane, a_elane);
   /*---(specifics)----------------------*/
   rc = yascii_box_data (x_pred, NULL, NULL, NULL, NULL, NULL, NULL, &x_by, NULL, &x_bt, &x_bx, NULL, NULL, NULL, NULL, NULL);
   /*> bx = s_boxes [x_pred].b_x + s_boxes [x_pred].b_w - 1;                          <*/
   /*> by = s_boxes [x_pred].b_y;                                                     <*/
   /*> x_bt = s_boxes [x_pred].b_t;                                                     <*/
   rc = yascii_box_data (x_succ, NULL, NULL, NULL, NULL, NULL, &x_ex, &x_ey, NULL, &x_et, NULL, NULL, NULL, NULL, NULL, NULL);
   /*> ex = s_boxes [x_succ].b_x;                                                     <*/
   /*> ey = s_boxes [x_succ].b_y;                                                     <*/
   /*> et = s_boxes [x_succ].b_t;                                                     <*/
   DEBUG_YASCII   yLOG_complex ("refs"      , "beg %3dx, %3dy, %3dt to end %3dx, %3dy, %3dt", x_bx, x_by, x_bt, x_ex, x_ey, x_et);
   /*---(beginning ypos adjust)----------*/
   x_bo  = yascii_link__ranges ('b', a_blane, x_bt  , NULL);
   DEBUG_YASCII   yLOG_value   ("x_bo"      , x_bo);
   --rce;  if (x_bo < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   x_by += x_bo;
   /*---(vertical xpos adjust)-----------*/
   x_vo  = yascii_link__ranges ('-', a_vlane, a_hgap, NULL);
   DEBUG_YASCII   yLOG_value   ("x_vo"      , x_vo);
   --rce;  if (x_vo < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   x_vx  = x_vo + x_bx + 1;
   /*---(ending ypos adjust)-------------*/
   x_eo  = yascii_link__ranges ('e', a_elane, x_et  , NULL);
   DEBUG_YASCII   yLOG_value   ("x_eo"      , x_eo);
   --rce;  if (x_eo < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   x_ey += x_eo;
   DEBUG_YASCII   yLOG_complex ("offs"      , "beg (%c) %3d  vert (%c) %3d/%3d  end (%c) %3d", a_blane, x_by, a_vlane, x_vx, a_hgap, a_elane, x_ey);
   /*---(line name)----------------------*/
   if      (x_by == x_ey)   strcpy (x_name, "E");
   else if (x_by <  x_ey)   strcpy (x_name, "ESE");
   else                     strcpy (x_name, "ENE");
   DEBUG_YASCII   yLOG_info    ("x_name"    , x_name);
   /*---(draw)---------------------------*/
   rc = yASCII_line (x_name, a_heavy, x_bx, x_by, x_vx, -1, x_ex, x_ey);
   DEBUG_YASCII   yLOG_value   ("draw"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}


