/*===[[ START ]]==============================================================*/
#include    "yASCII.h"
#include    "yASCII_priv.h"



/*===[[ GNU GENERAL PUBLIC LICENSE (GPL) ]]===================================*/
/*¥¥∑∑∑∑∑∑∑∑∑1∑∑∑∑∑∑∑∑∑2∑∑∑∑∑∑∑∑∑3∑∑∑∑∑∑∑∑∑4∑∑∑∑∑∑∑∑∑5∑∑∑∑∑∑∑∑∑6∑∑∑∑∑∑∑∑∑7∑∑∑∑∑∑∑∑∑8  */

#define  P_COPYRIGHT   \
   "copyright (c) 2020 robert.s.heatherly at balsashrike at gmail dot com"

#define  P_LICENSE     \
   "the only place you could have gotten this code is my github, my website,¶"   \
   "or illegal sharing. given that, you should be aware that this is GPL licensed."

#define  P_COPYLEFT    \
   "the GPL COPYLEFT REQUIREMENT means any modifications or derivative works¶"   \
   "must be released under the same GPL license, i.e, must be free and open."

#define  P_INCLUDE     \
   "the GPL DOCUMENTATION REQUIREMENT means that you must include the original¶" \
   "copyright notice and the full licence text with any resulting anything."

#define  P_AS_IS       \
   "the GPL NO WARRANTY CLAUSE means the software is provided without any¶"      \
   "warranty and the author cannot be held liable for damages."

#define  P_THEFT    \
   "if you knowingly violate the spirit of these ideas, i suspect you might¶"    \
   "find any number of freedom-minded hackers may take it quite personally ;)"

/*¥¥∑∑∑∑∑∑∑∑∑1∑∑∑∑∑∑∑∑∑2∑∑∑∑∑∑∑∑∑3∑∑∑∑∑∑∑∑∑4∑∑∑∑∑∑∑∑∑5∑∑∑∑∑∑∑∑∑6∑∑∑∑∑∑∑∑∑7∑∑∑∑∑∑∑∑∑8  */
/*===[[ GNU GENERAL PUBLIC LICENSE (GPL) ]]===================================*/

struct {
   char        l_name      [LEN_SHORT];
   char        l_ends      [LEN_TERSE];
   char        l_bx2ex;
   char        l_by2ey;
   char        l_bx2vx;
   char        l_by2vy;
   char        l_vx2ex;
   char        l_vy2ey;
} const S_lines [LEN_DESC] = {
   /*---(up/north)------------------*/
   { "NW"  , " à Ç á ¥ " , '>' , '>' , '¥' , '¥' , '¥' , '¥' },
   { "NWS" , " à Ç É à " , '>' , '>' , '¥' , '>' , '¥' , '<' },
   { "NWN" , " à Ç Ñ â " , '>' , '>' , '¥' , '>' , '¥' , '>' },
   { "N"   , " à â ¥ ¥ " , '=' , '>' , '¥' , '¥' , '¥' , '¥' },
   { "NEN" , " à É Ö â " , '<' , '>' , '¥' , '>' , '¥' , '>' },
   { "NES" , " à É Ç à " , '<' , '>' , '¥' , '>' , '¥' , '<' },
   { "NE"  , " à É Ü ¥ " , '<' , '>' , '¥' , '¥' , '¥' , '¥' },
   /*---(down/south)----------------*/
   { "SE"  , " â Ñ Ü ¥ " , '<' , '<' , '¥' , '¥' , '¥' , '¥' },
   { "SEN" , " â Ñ Ö â " , '<' , '<' , '¥' , '<' , '¥' , '>' },
   { "SES" , " â Ñ Ç à " , '<' , '<' , '¥' , '<' , '¥' , '<' },
   { "S"   , " â à ¥ ¥ " , '=' , '<' , '¥' , '¥' , '¥' , '¥' },
   { "SWS" , " â Ö É à " , '>' , '<' , '¥' , '<' , '¥' , '<' },
   { "SWN" , " â Ö Ñ â " , '>' , '<' , '¥' , '<' , '¥' , '>' },
   { "SW"  , " â Ö á ¥ " , '>' , '<' , '¥' , '¥' , '¥' , '¥' },
   /*---(right/east)----------------*/
   { "EN"  , " á Ö â ¥ " , '<' , '>' , '¥' , '¥' , '¥' , '¥' },
   { "ENW" , " á Ö Ç á " , '<' , '>' , '<' , '¥' , '>' , '¥' },
   { "ENE" , " á Ö É Ü " , '<' , '>' , '<' , '¥' , '<' , '¥' },
   { "E"   , " á Ü ¥ ¥ " , '<' , '=' , '¥' , '¥' , '¥' , '¥' },
   { "ESE" , " á Ç Ñ Ü " , '<' , '<' , '<' , '¥' , '<' , '¥' },
   { "ESW" , " á Ç Ö á " , '<' , '<' , '<' , '¥' , '>' , '¥' },
   { "ES"  , " á Ç à ¥ " , '<' , '<' , '¥' , '¥' , '¥' , '¥' },
   /*---(left/west)-----------------*/
   { "WS"  , " Ü É à ¥ " , '>' , '<' , '¥' , '¥' , '¥' , '¥' },
   { "WSE" , " Ü É Ñ Ü " , '>' , '<' , '>' , '¥' , '<' , '¥' },
   { "WSW" , " Ü É Ö á " , '>' , '<' , '>' , '¥' , '>' , '¥' },
   { "W"   , " Ü á ¥ ¥ " , '>' , '=' , '¥' , '¥' , '¥' , '¥' },
   { "WNW" , " Ü Ñ Ç á " , '>' , '>' , '>' , '¥' , '>' , '¥' },
   { "WNE" , " Ü Ñ É Ü " , '>' , '>' , '>' , '¥' , '<' , '¥' },
   { "WN"  , " Ü Ñ â ¥ " , '>' , '>' , '¥' , '¥' , '¥' , '¥' },
   /*---(DONE)----------------------*/
   { "end" , " x x x x " },
};



/*====================------------------------------------====================*/
/*===----                      finding specific path                   ----===*/
/*====================------------------------------------====================*/
static void      o___SEARCH_____________o (void) {;}

char
yascii__line_find       (char a_path [LEN_SHORT])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         i           =    0;
   /*---(defense)------------------------*/
   --rce;  if (a_path == NULL || a_path [0] == '\0')  return rce;
   /*---(walk entries)-------------------*/
   for (i = 0; i < LEN_DESC; ++i) {
      if (strcmp (S_lines [i].l_name, "end")  == 0)  break;
      if (strcmp (S_lines [i].l_name, a_path) != 0)  continue;
      return i;
   }
   /*---(complete)-----------------------*/
   return --rce;
}



/*====================------------------------------------====================*/
/*===----                    drawing coonecting lines                  ----===*/
/*====================------------------------------------====================*/
static void      o___SUPPORT____________o (void) {;}

char
yascii__line_comp       (char a_comp, short a_one, short a_two)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*---(defense)------------------------*/
   --rce;  if (a_comp == 0)  return rce;
   /*---(overall)------------------------*/
   if (a_comp != '¥' && a_one == -1)  return 0;
   if (a_comp != '¥' && a_two == -1)  return 0;
   /*---(specific tests)-----------------*/
   --rce;  switch (a_comp) {
   case '=' : if (a_one == a_two)               return 1;  break;
   case '<' : if (a_one <  a_two)               return 1;  break;
   case '‹' : if (a_one <= a_two)               return 1;  break;
   case '>' : if (a_one >  a_two)               return 1;  break;
   case '›' : if (a_one >= a_two)               return 1;  break;
   case '¥' : if (a_one == -1 && a_two >  -1)   return 1;
              if (a_one >  -1 && a_two == -1)   return 1;  break;
   default  : return rce;                       break;
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
yascii__line_valid      (char a_path [LEN_SHORT], char n, short a_bx, short a_by, short a_vx, short a_vy, short a_ex, short a_ey)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        x_ends      [LEN_SHORT] = "";
   /*---(defense)------------------------*/
   --rce;  if (a_path == NULL || a_path [0] == '\0')  return rce;
   --rce;  if (n       < -1 || n >= LEN_DESC)         return rce;
   --rce;  if (a_bx    < 0)                           return rce;
   --rce;  if (a_by    < 0)                           return rce;
   --rce;  if (a_vx    <  -1)                         return rce;
   --rce;  if (a_vy    <  -1)                         return rce;
   --rce;  if (a_ex    < 0)                           return rce;
   --rce;  if (a_ey    < 0)                           return rce;
   /*---(check path)---------------------*/
   --rce;  if (n == -1) {
      n = yascii__line_find (a_path);
      if (n < 0)   return rce;
   }
   /*---(check bounds)-------------------*/
   --rce;  if (yascii__line_comp (S_lines [n].l_bx2ex, a_bx, a_ex) != 1)  return rce;
   --rce;  if (yascii__line_comp (S_lines [n].l_by2ey, a_by, a_ey) != 1)  return rce;
   --rce;  if (yascii__line_comp (S_lines [n].l_bx2vx, a_bx, a_vx) != 1)  return rce;
   --rce;  if (yascii__line_comp (S_lines [n].l_by2vy, a_by, a_vy) != 1)  return rce;
   --rce;  if (yascii__line_comp (S_lines [n].l_vx2ex, a_vx, a_ex) != 1)  return rce;
   --rce;  if (yascii__line_comp (S_lines [n].l_vy2ey, a_vy, a_ey) != 1)  return rce;
   /*---(complete)-----------------------*/
   return 1;
}

char
yascii__line_ends       (char a_path [LEN_SHORT], char r_ends [LEN_TERSE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        n           =   -1;
   /*---(default)------------------------*/
   if (r_ends != NULL)   strcpy (r_ends, " - - - - ");
   /*---(find entry)---------------------*/
   n = yascii__line_find (a_path);
   if (n < 0)  return n;
   /*---(save-back)----------------------*/
   if (r_ends != NULL)  strlcpy (r_ends, S_lines [n].l_ends, LEN_TERSE);
   /*---(complete)-----------------------*/
   return n;
}

char
yascii__line_coords     (char a_len, char a_cnt, char a_dir, short a_bx, short a_by, short a_vx, short a_vy, short a_ex, short a_ey, short *r_x1, short *r_y1, short *r_x2, short *r_y2)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   short       x1, y1, x2, y2;
   /*---(defense)------------------------*/
   --rce;  if (a_len <  1  || a_len >  3)                      return rce;
   --rce;  if (a_cnt <  0  || a_cnt >= a_len)                  return rce;
   --rce;  if (a_dir == 0  || strchr ("NSEW", a_dir) == NULL)  return rce;
   --rce;  if (r_x1  == NULL)                                  return rce;
   --rce;  if (r_y1  == NULL)                                  return rce;
   --rce;  if (r_x2  == NULL)                                  return rce;
   --rce;  if (r_y2  == NULL)                                  return rce;
   /*---(initial point)------------------*/
   if (a_cnt == 0) {
      x1 = *r_x1 = a_bx;
      y1 = *r_y1 = a_by;
   } else {
      x1 = *r_x1 = *r_x2;
      y1 = *r_y1 = *r_y2;
   }
   /*---(handle final)----------------*/
   if (a_cnt == a_len - 1) {
      *r_x2 = a_ex;
      *r_y2 = a_ey;
      return a_cnt;
   }
   /*---(default final)------------------*/
   *r_x2 = x1;
   *r_y2 = y1;
   /*---(first waypoint)--------------*/
   if (a_cnt == 0) {
      if (a_len == 2) {
         switch (a_dir) {
         case 'N' :case 'S' : *r_y2 = a_ey;  break;
         case 'E' :case 'W' : *r_x2 = a_ex;  break;
         }
      } else {
         switch (a_dir) {
         case 'N' :case 'S' : *r_y2 = a_vy;  break;
         case 'E' :case 'W' : *r_x2 = a_vx;  break;
         }
      }
      return a_cnt;
   }
   /*---(second waypoint)-------------*/
   switch (a_dir) {
   case 'N' :case 'S' : *r_y2 = a_ey;  break;
   case 'E' :case 'W' : *r_x2 = a_ex;  break;
   }
   /*---(complete)-----------------------*/
   return a_cnt;
}



/*====================------------------------------------====================*/
/*===----                    drawing coonecting lines                  ----===*/
/*====================------------------------------------====================*/
static void      o___DRAWING____________o (void) {;}

char
yascii__line_draw       (char a_dir, char a_beg, short a_bx, short a_by, char a_line, short a_ex, short a_ey, char a_end)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         i           =    0;
   /*---(quick-out)----------------------*/
   if (a_dir == '-')  return 0;
   /*---(defense)------------------------*/
   --rce;  if (a_dir  == 0 || strchr ("EWSN"          , a_dir) == NULL)  return rce;
   --rce;  if (a_beg  == 0 || strchr ("âàáÜÉÇÑÖœ¥≥†∑ ", a_beg) == NULL)  return rce;
   --rce;  if (a_line == 0)                                              return rce;
   --rce;  if (a_end  == 0 || strchr ("âàáÜÉÇÑÖœ¥≥†∑ ", a_end) == NULL)  return rce;
   /*---(begin)--------------------------*/
   if (a_beg != ' ')  yASCII_single (a_bx, a_by, a_beg);
   /*---(line)---------------------------*/
   switch (a_dir) {
   case 'E' :  for (i = a_bx + 1; i < a_ex; ++i)   yASCII_single ( i, a_by, a_line);    break;
   case 'W' :  for (i = a_bx - 1; i > a_ex; --i)   yASCII_single ( i, a_by, a_line);    break;
   case 'S' :  for (i = a_by + 1; i < a_ey; ++i)   yASCII_single (a_bx,  i, a_line);    break;
   case 'N' :  for (i = a_by - 1; i > a_ey; --i)   yASCII_single (a_bx,  i, a_line);    break;
   }
   /*---(end)----------------------------*/
   if (a_end != ' ')  yASCII_single (a_ex, a_ey, a_end);
   /*---(complete)-----------------------*/
   return 1;
}

char
yascii__line_label      (char a_len, char a_cnt, char a_dir, char a_bef, short a_bx, short a_by, short a_ex, short a_ey, char a_aft, char a_align [LEN_SHORT], char a_label [LEN_HUND])
{
   /*---(design notes)-------------------*/
   /* 
    *          top-left is origin                [ [ [  
    *           (same as coordinates)              â    
    *                                            < < <  
    *                                              Å    
    *       -    [ <      |      > ]               Å    
    *       =    [ÉÄ<ÄÄÄÄÄ|ÄÄÄÄÄ>ÄÜ]             | | |
    *       +    [ <      |      > ]               Å
    *                                              Å
    *                                            > > > 
    *                                              à
    *                                            ] ] ]
    *    
    *                                            - = +
    */
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        l, lx, ly;
   char        ox, oy;
   char        x, y;
   /*---(defense)------------------------*/
   --rce;  if (a_dir == 0 || strchr ("NSEW", a_dir) == NULL)   return rce;
   --rce;  if (a_align == NULL || a_align [0] == '\0')         return rce;
   l = strlen (a_align);
   --rce;  if (l     != 2)                                     return rce;
   --rce;  if (strchr ("[<|>]", a_align [0]) == NULL)          return rce;
   --rce;  if (strchr ("+=-"  , a_align [1]) == NULL)          return rce;
   --rce;  if (a_label == NULL || a_label [0] == '\0')         return rce;
   /*---(header)-------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(prepare)------------------------*/
   l  = strlen (a_label);
   if (a_bx <= a_ex)  ox = a_bx;   else ox = a_ex;
   if (a_by <= a_ey)  oy = a_by;   else oy = a_ey;
   lx = abs (a_ex - a_bx);
   ly = abs (a_ey - a_by);
   DEBUG_YASCII   yLOG_complex ("prep"      , "%1d %1d, %c %-3.3s %-10.10s, l=%2d, ox=%3d, oy=%3d, lx=%2d, ly=%2d", a_len, a_cnt, a_dir, a_align, a_label, l, ox, oy, lx, ly);
   /*---(horizontal)---------------------*/
   if (strchr ("EW", a_dir) != NULL) {
      /*---(ypos)------------------------*/
      switch (a_align [1]) {
      case '-' :  y = oy - 1;         break;
      case '=' :  y = oy;             break;
      case '+' :  y = oy + 1;         break;
      }
      DEBUG_YASCII   yLOG_value   ("y"         , y);
      /*---(xpos)------------------------*/
      switch (a_align [0]) {
      case '[' :  x = ox - l;         break;
      case '<' :  x = ox + 1;         break;
      case '|' :  x = ox + ((lx - l) / 2.0) + 1;  break;
      case '>' :  x = ox + lx - l;    break;
      case ']' :  x = ox + lx + 1;    break;
      }
      DEBUG_YASCII   yLOG_value   ("x"         , x);
      /*---(on-line adaptations)---------*/
      if (a_align [1] == '=') {
         switch (a_align [0]) {
         case '<' : ++x;  break;
         case '>' : --x;  break;
         }
         DEBUG_YASCII   yLOG_value   ("x-adapt"   , x);
      }
      /*---(adapt to markers)------------*/
      if ((a_bef != ' ' && a_cnt == 0) ||
            (a_aft != ' ' && a_cnt == a_len - 1)) {
         switch (a_align [0]) {
         case '[' :  --x;  if (a_align [1] == '=')  --x;  break;
         case ']' :  ++x;  if (a_align [1] == '=')  ++x;  break;
         }
         DEBUG_YASCII   yLOG_value   ("x-marker"  , x);
      }
      /*---(done)------------------------*/
   }
   /*---(vertical)-----------------------*/
   else {
      /*---(xpos)------------------------*/
      switch (a_align [1]) {
      case '-' :  x = ox - l + 1;           break;
      case '=' :  x = ox - (l / 2.0) + 1;   break;
      case '+' :  x = ox;                   break;
      }
      DEBUG_YASCII   yLOG_value   ("x"         , x);
      /*---(xadjust)---------------------*/
      if (strchr ("<|>", a_align [0]) != NULL) {
         switch (a_align [1]) {
         case '-' : --x;  break;
         case '+' : ++x;  break;
         }
      }
      /*---(ypos)------------------------*/
      switch (a_align [0]) {
      case '[' :  y = oy - 1;           break;
      case '<' :  y = oy + 1;           break;
      case '|' :  y = oy + (ly / 2.0);  break;
      case '>' :  y = oy + ly - 1;      break;
      case ']' :  y = oy + ly + 1;      break;
      }
      DEBUG_YASCII   yLOG_value   ("y"         , y);
      /*---(adapt to markers)------------*/
      if ((a_bef != ' ' && a_cnt == 0) ||
            (a_aft != ' ' && a_cnt == a_len - 1)) {
         switch (a_align [0]) {
         case '[' :  --y;   break;
         case ']' :  ++y;   break;
         }
      }
      DEBUG_YASCII   yLOG_value   ("y-marker"  , y);
   }
   /*---(on-line adaptations)---------*/
   rc = yASCII_print  (x, y, a_label, YASCII_CLEAR);
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 1;
}

char
yASCII_line_full        (char a_path [LEN_SHORT], char a_heavy, char a_bef, char a_beg, short a_bx, short a_by, short a_vx, short a_vy, short a_ex, short a_ey, char a_end, char a_aft, char a_seg, char a_align [LEN_SHORT], char a_label [LEN_HUND])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_vert, x_horz;
   char        x_ends      [LEN_TERSE] = " ?  ?  ?  ? ";
   char        l           =    0;
   char        x_dir       =  '-';
   char        x_beg, x_end;
   int         i           =    0;
   short       x1, y1, x2, y2;
   /*---(header)-------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YASCII   yLOG_point   ("a_path"    , a_path);
   --rce;  if (a_path == NULL || a_path [0] == '\0') {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_info    ("a_path"    , a_path);
   DEBUG_YASCII   yLOG_char    ("a_bef"     , a_bef);
   --rce;  if (a_bef  == 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_char    ("a_aft"     , a_bef);
   --rce;  if (a_aft  == 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(set line type)------------------*/
   rc = yascii__heaviness  (a_heavy, &x_vert, &x_horz, NULL, NULL);
   DEBUG_YASCII   yLOG_value   ("heavy"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(get ends)-----------------------*/
   rc = yascii__line_ends (a_path, x_ends);
   DEBUG_YASCII   yLOG_value   ("ends"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_info    ("x_ends"    , x_ends);
   /*---(prepare)------------------------*/
   l = strlen (a_path);
   x_dir = a_path [0];
   /*---(before)-------------------------*/
   DEBUG_YASCII   yLOG_char    ("a_bef"     , a_bef);
   if (a_bef != ' ') {
      DEBUG_YASCII   yLOG_note    ("writing before marker");
      switch (x_dir) {
      case 'E' :  yASCII_force (a_bx - 1, a_by    , a_bef);    break;
      case 'W' :  yASCII_force (a_bx + 1, a_by    , a_bef);    break;
      case 'S' :  yASCII_force (a_bx    , a_by - 1, a_bef);    break;
      case 'N' :  yASCII_force (a_bx    , a_by + 1, a_bef);    break;
      }
   }
   /*---(draw lines)---------------------*/
   --rce;  for (i = 0; i < l; ++i) {
      /*---(prepare)---------------------*/
      x_dir  = a_path [i];
      x_beg  = x_ends [(i * 2) + 1];
      if (a_beg != ' ' && i == 0)      x_beg = a_beg;
      x_end  = x_ends [(i * 2) + 3];
      if (a_end != ' ' && i == l - 1)  x_end = a_end;
      /*---(get endpoints)---------------*/
      rc = yascii__line_coords (l, i, x_dir, a_bx, a_by, a_vx, a_vy, a_ex, a_ey, &x1, &y1, &x2, &y2);
      DEBUG_YASCII   yLOG_complex ("LOOP"      , "%2d, %2d, %c, %c, %c, %d", l, i, x_dir, x_beg, x_end, rc);
      if (rc < 0) {
         DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
      /*---(draw)------------------------*/
      switch (x_dir) {
      case 'N' : case 'S' : yascii__line_draw (x_dir, x_beg, x1, y1, x_vert, x2, y2, x_end); break;
      case 'E' : case 'W' : yascii__line_draw (x_dir, x_beg, x1, y1, x_horz, x2, y2, x_end); break;
      }
      /*---(label)-----------------------*/
      if (a_seg == i)                rc = yascii__line_label (l, i, x_dir, a_bef, x1, y1, x2, y2, a_aft, a_align, a_label);
      if (a_seg == 9 && i == l - 1)  rc = yascii__line_label (l, i, x_dir, a_bef, x1, y1, x2, y2, a_aft, a_align, a_label);
      /*---(done)------------------------*/
   }
   /*---(after)--------------------------*/
   if (a_aft != ' ') {
      switch (x_dir) {
      case 'E' :  yASCII_force (a_ex + 1, a_ey    , a_aft);    break;
      case 'W' :  yASCII_force (a_ex - 1, a_ey    , a_aft);    break;
      case 'S' :  yASCII_force (a_ex    , a_ey + 1, a_aft);    break;
      case 'N' :  yASCII_force (a_ex    , a_ey - 1, a_aft);    break;
      }
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 1;
}

char
yASCII_line_label       (char a_path [LEN_SHORT], char a_heavy, short a_bx, short a_by, short a_vx, short a_vy, short a_ex, short a_ey, char a_seg, char a_align [LEN_SHORT], char a_label [LEN_HUND])
{
   return yASCII_line_full (a_path, a_heavy, ' ', ' ', a_bx, a_by, a_vx, a_vy, a_ex, a_ey, ' ', ' ', a_seg, a_align, a_label);
}

char
yASCII_line_mark        (char a_path [LEN_SHORT], char a_heavy, char a_bef, short a_bx, short a_by, short a_vx, short a_vy, short a_ex, short a_ey, char a_aft)
{
   return yASCII_line_full (a_path, a_heavy, a_bef, ' ', a_bx, a_by, a_vx, a_vy, a_ex, a_ey, ' ', a_aft, -1, "", "");
}

char
yASCII_line             (char a_path [LEN_SHORT], char a_heavy, short a_bx, short a_by, short a_vx, short a_vy, short a_ex, short a_ey)
{
   return yASCII_line_full (a_path, a_heavy, ' ', ' ', a_bx, a_by, a_vx, a_vy, a_ex, a_ey, ' ', ' ', -1, "", "");
}
