/*===[[ START ]]==============================================================*/
#include    "yASCII.h"
#include    "yASCII_priv.h"



static   char  *s_image = NULL;



static char const zASCII_join [LEN_TITLE][LEN_DESC] = {
   /*            ------------- old ------------ */
   /*            123456789-123456789-123456789-123456789-123456789- */
   /*                                          h h v v h v h v h v  */
   /* new */  { "  ≤ å Ä Å É Ö Ñ Ç Ü á â à ä ∑ ù ú û ü ç é - | = ®" },
   /*  ≤  */  { "≤ ≤ ä Ä ä â à à â ä ä â à ä ≤ ù ú ä ä ç ä ≤ ä ≤ ä" },
   /*  å  */  { "å ä å ä Å á Ü á Ü Ü á ä ä ä å ä ä û ü ä é ä | ä ®" },
   /*  Ä  */  { "Ä Ä ä Ä ä â à à â ä ä â à ä Ä ù ú ä ä ç ä Ä ä Ä ä" },
   /*  Å  */  { "Å ä Å ä Å á Ü á Ü Ü á ä ä ä Å ä ä û ü ä é ä Å ä Å" },
   /*  É  */  { "É â á â á É ä á ä Ü á â ä ä É â â á á â á â á â á" },
   /*  Ö  */  { "Ö à Ü à Ü ä Ö ä Ü Ü ä ä à ä Ö à à Ü Ü à Ü à Ü à Ü" },
   /*  Ñ  */  { "Ñ à á à á á ä Ñ ä ä á ä à ä Ñ à à Ñ Ñ à á à Ñ à Ñ" },
   /*  Ç  */  { "Ç â Ü â Ü ä Ü ä Ç Ü ä â ä ä Ç â â Ü Ü â Ü â Ü â Ü" },
   /*  Ü  */  { "Ü ä Ü ä Ü ä Ü ä Ü Ü ä ä ä ä Ü Ü Ü Ü Ü ä Ü Ü Ü Ü Ü" },
   /*  á  */  { "á ä á ä á á ä á ä ä á ä ä ä á á á á á ä á á á á á" },
   /*  â  */  { "â â ä â ä â ä ä â ä ä â ä ä â â â â â â ä â â â â" },
   /*  à  */  { "à à ä à ä ä à à ä ä ä ä à ä à à à à à à ä à à à à" },
   /*  ä  */  { "ä ä ä ä ä ä ä ä ä ä ä ä ä ä ä ä ä ä ä ä ä ä ä ä ä" },
   /*  ∑  */  { "∑ ≤ å Ä Å É Ö Ñ Ç Ü á â à ä ∑ ù ú û ü ç é - | = ®" },
   /*h ù  */  { "ù ù ä ù ä â à à â ä ä â à ä ù ù ù ä ä ç ä ù ä ù ä" },
   /*h ú  */  { "ú ú ä ú ä â à à â ä ä â à ä ú ú_ú ä ä ç ä ú ä ú ä" },
   /*v û  */  { "û ä û ä û á Ü á Ü Ü á ä ä ä û ä ä û û ä û ä û ä û" },
   /*v ü  */  { "ü ä ü ä ü á Ü á Ü Ü á ä ä ä ü ä ä ü ü ä ü ä ü ä ü" },
   /*h ç  */  { "ç ç ä ç ä â à à â ä ä â à ä é é é ä ä ç ä ç ä ç ä" },
   /*v é  */  { "é ä é ä é á Ü á Ü Ü á ä ä ä é ä ä é é ä é ä é ä é" },
   /*h -  */  { "- - ä - ä â à à â ä ä â à ä - - - ä ä - ä - ä - ä" },
   /*v |  */  { "| ä | ä | á Ü á Ü Ü á ä ä ä | ä ä | | ä | ä | ä |" },
   /*h =  */  { "= = ä = ä â à à â ä ä â à ä = = = ä ä = ä = ä = ä" },
   /*v ®  */  { "® ä ® ä ® á Ü á Ü Ü á ä ä ä ® ä ä ® ® ä ® ä ® ä ®" },
};

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
   yASCII_grid_set_full  ('-', YASCII_NAMES, 0, 0);
   myASCII.d_box   = YASCII_SOLID;
   myASCII.d_tie   = YASCII_DOTTED;
   myASCII.d_bound = YASCII_SOLID;
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
yascii__heaviness       (char a_heavy, char *r_left, char *r_topp, char *r_righ, char *r_bott)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        x_left, x_topp, x_righ, x_bott;
   /*---(enter)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   DEBUG_YASCII   yLOG_complex ("a_args"    , "%c, %p, %p, %p, %p", a_heavy, r_left, r_topp, r_righ, r_bott);
   /*---(default)------------------------*/
   if (r_left != NULL)  *r_left = ' ';
   if (r_topp != NULL)  *r_topp = ' ';
   if (r_righ != NULL)  *r_righ = ' ';
   if (r_bott != NULL)  *r_bott = ' ';
   /*---(select)-------------------------*/
   switch (a_heavy) {
   case YASCII_SOLID   :  x_left = 'Å';  x_righ = 'Å';  x_topp = 'Ä';  x_bott = 'Ä';  break;
   case YASCII_DOTTED  :  x_left = 'å';  x_righ = 'å';  x_topp = '≤';  x_bott = '≤';  break;
   case YASCII_LIGHT   :  x_left = '∑';  x_righ = '∑';  x_topp = '∑';  x_bott = '∑';  break;
   case YASCII_WAVY    :  x_left = 'é';  x_righ = 'é';  x_topp = 'ç';  x_bott = 'ç';  break;
   case YASCII_INSIDE  :  x_left = 'û';  x_righ = 'ü';  x_topp = 'ù';  x_bott = 'ú';  break;
   case YASCII_OUTSIDE :  x_left = 'ü';  x_righ = 'û';  x_topp = 'ú';  x_bott = 'ù';  break;
   case YASCII_ANCIENT :  x_left = '|';  x_righ = '|';  x_topp = '-';  x_bott = '-';  break;
   case YASCII_DOUBLE  :  x_left = '®';  x_righ = '®';  x_topp = '=';  x_bott = '=';  break;
   default             :
                          DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
                          return rce;
   }
   DEBUG_YASCII   yLOG_complex ("lines"     , "%c  %c  %c  %c", x_left, x_topp, x_righ, x_bott);
   /*---(save-back)----------------------*/
   if (r_left != NULL)  *r_left = x_left;
   if (r_topp != NULL)  *r_topp = x_topp;
   if (r_righ != NULL)  *r_righ = x_righ;
   if (r_bott != NULL)  *r_bott = x_bott;
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yASCII_grid_set_full    (char a_size, char a_decor, short x_left, short y_topp)
{
   /*---(header)-------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(style)--------------------------*/
   myASCII.d_size      = a_size;
   switch (a_decor) {
   case YASCII_NONE   :
      myASCII.d_names  = '-'; myASCII.d_notes  = '-';
      myASCII.d_blocks = '-'; myASCII.d_counts = '-';
      break;
   case YASCII_NAMES  :
      myASCII.d_names  = 'y'; myASCII.d_notes  = '-';
      myASCII.d_blocks = '-'; myASCII.d_counts = '-';
      break;
   case YASCII_NOTES  :
      myASCII.d_names  = 'y'; myASCII.d_notes  = 'y';
      myASCII.d_blocks = '-'; myASCII.d_counts = '-';
      break;
   case YASCII_COUNTS :
      myASCII.d_names  = 'y'; myASCII.d_notes  = 'y';
      myASCII.d_blocks = '-'; myASCII.d_counts = 'y';
      break;
   case YASCII_MAX    :
      myASCII.d_names  = 'y'; myASCII.d_notes  = 'y';
      myASCII.d_blocks = 'y'; myASCII.d_counts = 'y';
      break;
   case YASCII_UNIT   :
      myASCII.d_names  = 'y'; myASCII.d_notes  = '-';
      myASCII.d_blocks = 'y'; myASCII.d_counts = '-';
      break;
   default            :
      myASCII.d_names  = 'y'; myASCII.d_notes  = '-';
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
yASCII_grid_new_full    (char a_size, char a_decor, char a_col, char a_row, char a_left, char a_righ, char a_topp, char a_bott)
{
   yASCII_grid_set_full (a_size, a_decor, 0, 0);
   myASCII.x_max = myASCII.x_wide * a_col - myASCII.x_gap + a_left + a_righ;
   myASCII.y_max = myASCII.y_tall * a_row - myASCII.y_gap + a_topp + a_bott;
   yASCII_new  (myASCII.x_max, myASCII.y_max);
   yASCII_grid_set_full (a_size, a_decor, a_left, a_topp);
}

char
yASCII_grid_new         (char a_size, char a_decor, char a_col, char a_row)
{
   yASCII_grid_set_full (a_size, a_decor, 0, 0);
   myASCII.x_max = myASCII.x_wide * a_col - myASCII.x_gap;
   myASCII.y_max = myASCII.y_tall * a_row - myASCII.y_gap;
   yASCII_new  (myASCII.x_max, myASCII.y_max);
   yASCII_grid_set_full (a_size, a_decor, 0, 0);
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
   if (x <  0)        return '∞';
   if (x >= myASCII.x_max)   return '∞';
   if (y <  0)        return '∞';
   if (y >= myASCII.y_max)   return '∞';
   o = (y * myASCII.x_max) + x;
   return s_image [o];
}

char
yASCII_single           (int x, int y, char a_new)
{
   /*---(locals)-----------+-----+-----+-*/
   char        c           =  '-';
   char       *p           = NULL;
   char        x_valid     [LEN_DESC] = "";
   char        x_old       =   -1;
   char        x_new       =   -1;
   char        t           [LEN_SHORT] = "";
   /*---(enter)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(quick-out)----------------------*/
   if (x < 0 || x >= myASCII.x_max) {
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   if (y < 0 || y >= myASCII.y_max) {
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(get old)------------------------*/
   c = yASCII_get (x, y);
   DEBUG_YASCII   yLOG_complex ("c"         , "%3d/%c", c, ychrvisible (c));
   ystrlcpy (x_valid, zASCII_join [0], LEN_DESC);
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
   DEBUG_YASCII   yLOG_complex ("a_new"     , "%3d/%c", a_new, ychrvisible (a_new));
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
   ystrlcpy (x_valid, zASCII_join [x_new], LEN_DESC);
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
yASCII_single_dos       (int c, int x, int y, char a_new, char a_alt)
{
   if (c % 2 == 0)  yASCII_single (x, y, a_new);
   else             yASCII_single (x, y, a_alt);
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
   c = ystrldcnt (x_str, '®', LEN_RECD);
   DEBUG_YASCII   yLOG_value   ("c"         , c);
   /*---(walk text)----------------------*/
   --rce;  for (i = 0; i < l; i++) {
      DEBUG_YASCII  yLOG_complex ("char"      , "%4d, %3d, %3d, %c", l, i, x_str [i], x_str [i]);
      /*---(watch for breaks)------------*/
      if (strchr("∑ ≤ - /", x_str[i]) != NULL) {
         DEBUG_YASCII  yLOG_note    ("found a delimiter/space");
         x_break = i;
      }
      /*---(watch for newlines)----------*/
      if (x_str [i] == '®') {
         DEBUG_YASCII  yLOG_note    ("found new line");
         x_break = i;
      } else {
         ++x_width;
      }
      DEBUG_YASCII  yLOG_complex ("width"     , "%4db, %3dw", x_break, x_width);
      if (x_width > a_wide || x_str [i] == '®') {
         DEBUG_YASCII  yLOG_note    ("passed width or newline, display");
         x_str [x_break] = '\0';
         if (a_mode != YASCII_FILL) {
            ystrlcpy  (x_str + x_head, x_out, LEN_RECD);
         } else {
            ystrlpad  (x_str + x_head, x_out, '.', '<', a_wide);
            ystrldchg (x_out, ' ', '∑', a_wide);
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
         ystrldchg (x_out, ' ', '∑', a_wide);
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
   char        x_2nd       =  '∑';
   char        x_horz      [LEN_SHORT] =  "Ä";
   char        x_vert      [LEN_SHORT] =  "Å";
   char        x_end       =  '∑';
   char        t           [LEN_SHORT] =  "∑";
   /*---(enter)--------------------------*/
   DEBUG_YASCII   yLOG_senter  (__FUNCTION__);
   /*---(lines)--------------------------*/
   DEBUG_YASCII   yLOG_schar   (a_heavy);
   if (a_heavy == '≤') {
      strcpy (x_horz, "≤");
      strcpy (x_vert, "å");
   } else if (a_heavy == '∑') {
      strcpy (x_horz, "∑");
      strcpy (x_vert, "∑");
   }
   DEBUG_YASCII   yLOG_schar   (x_horz);
   DEBUG_YASCII   yLOG_schar   (x_vert);
   /*---(direction)----------------------*/
   if (bx > ex) {
      if      (by >  ey)  {  x_dir = 1;  if (a_dir == '◊') { x_2nd = '‘'; x_end = 'â'; }  else { a_dir = '‘'; x_2nd = '◊'; x_end = 'á'; } }
      else if (by == ey)  {  x_dir = 4;  a_dir = '◊';  x_2nd = '¥';  x_end = 'á'; }
      else                {  x_dir = 7;  if (a_dir == '◊') { x_2nd = '’'; x_end = 'à'; }  else { a_dir = '’'; x_2nd = '◊'; x_end = 'á'; } }
   } else if (bx == ex) {
      if      (by >  ey)  {  x_dir = 2;  a_dir = '‘';  x_2nd = '¥';  x_end = 'â'; }
      else if (by == ey)  {  x_dir = 5;  a_dir = '¥';  x_2nd = '¥'; }
      else                {  x_dir = 8;  a_dir = '’';  x_2nd = '¥';  x_end = 'à'; }
   } else {
      if      (by >  ey)  {  x_dir = 3;  if (a_dir == '÷') { x_2nd = '‘'; x_end = 'â'; }  else { a_dir = '‘'; x_2nd = '÷'; x_end = 'Ü'; } }
      else if (by == ey)  {  x_dir = 6;  a_dir = '÷';  x_2nd = '¥';  x_end = 'Ü'; }
      else                {  x_dir = 9;  if (a_dir == '÷') { x_2nd = '’'; x_end = 'à'; }  else { a_dir = '’'; x_2nd = '÷'; x_end = 'Ü'; } }
   }
   DEBUG_YASCII   yLOG_sint    (x_dir);
   DEBUG_YASCII   yLOG_schar   (a_dir);
   DEBUG_YASCII   yLOG_schar   (x_2nd);
   /*---(origination)--------------------*/
   yASCII_print (bx, by, "œ", YASCII_CLEAR); 
   /*---(first segment)------------------*/
   switch (a_dir) {
   case '÷' :  for (i = bx + 1; i < ex; ++i)   yASCII_print ( i, by, x_horz, YASCII_CLEAR);    break;
   case '◊' :  for (i = bx - 1; i > ex; --i)   yASCII_print ( i, by, x_horz, YASCII_CLEAR);    break;
   case '’' :  for (i = by + 1; i < ey; ++i)   yASCII_print (bx,  i, x_vert, YASCII_CLEAR);    break;
   case '‘' :  for (i = by - 1; i > ey; --i)   yASCII_print (bx,  i, x_vert, YASCII_CLEAR);    break;
   }
   /*---(corner)-------------------------*/
   switch (a_dir) { case '÷' :  if (x_dir == 3)  yASCII_print (ex, by, "Ö", YASCII_CLEAR);  else if (x_dir == 9)  yASCII_print (ex, by, "Ç", YASCII_CLEAR);  break;
   case '◊' :  if (x_dir == 1)  yASCII_print (ex, by, "Ñ", YASCII_CLEAR);  else if (x_dir == 7)  yASCII_print (ex, by, "É", YASCII_CLEAR);  break;
   case '’' :  if (x_dir == 7)  yASCII_print (bx, ey, "Ö", YASCII_CLEAR);  else if (x_dir == 9)  yASCII_print (bx, ey, "Ñ", YASCII_CLEAR);  break;
   case '‘' :  if (x_dir == 1)  yASCII_print (bx, ey, "Ç", YASCII_CLEAR);  else if (x_dir == 3)  yASCII_print (bx, ey, "É", YASCII_CLEAR);  break;
   }
   /*---(second segment)-----------------*/
   switch (x_2nd) {
   case '÷' :  for (i = bx + 1; i < ex; ++i)   yASCII_print ( i, ey, x_horz, YASCII_CLEAR);    break;
   case '◊' :  for (i = bx - 1; i > ex; --i)   yASCII_print ( i, ey, x_horz, YASCII_CLEAR);    break;
   case '’' :  for (i = by + 1; i < ey; ++i)   yASCII_print (ex,  i, x_vert, YASCII_CLEAR);    break;
   case '‘' :  for (i = by - 1; i > ey; --i)   yASCII_print (ex,  i, x_vert, YASCII_CLEAR);    break;
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

char yASCII_uconnect  (short bx, short by, char a_dir, short ex, short ey) { return yASCII_connector (bx, by, a_dir, ex, ey, '≤', NULL, 0, 0); }




/*====================------------------------------------====================*/
/*===----                        content boxes                         ----===*/
/*====================------------------------------------====================*/
static void      o___BOXES______________o (void) {;}

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
   rc = yascii__heaviness (a_heavy, &x_left, &x_topp, &x_righ, &x_bott);
   DEBUG_YASCII   yLOG_value   ("heavy"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   if (x_topp == 'ç')  x_talt = 'Ä';
   else                x_talt = x_topp;
   if (x_bott == 'ç')  x_balt = 'Ä';
   else                x_balt = x_bott;
   DEBUG_YASCII   yLOG_complex ("lines"     , "%c  %c  %c  %c  %c  %c", x_left, x_topp, x_righ, x_bott, x_talt, x_balt);
   /*---(top)----------------------------*/
   yASCII_single (x        , y, 'É');
   for (x_cnt = 0, i = x + 1; i < x + w - 1; ++i) {
      yASCII_single_dos (x_cnt++, i, y, x_topp, x_talt);
      c = yASCII_get (i, y);
      if (a_mode == YASCII_CLEAR && c == 'ä') yASCII_print  (i, y, "à", YASCII_CLEAR);
   }
   yASCII_single (x + w - 1, y, 'Ç');
   /*---(middle)-------------------------*/
   sprintf (x_line, "%*.*s", w - 2, w - 2, YSTR_EMPTY);
   for (i = 1; i < t - 1; ++i) {
      /*---(left)-----------*/
      yASCII_single (x, y + i, x_left);
      c = yASCII_get (x, y + i);
      if (a_mode == YASCII_CLEAR && c == 'ä') yASCII_print  (x, y + i, "Ü", YASCII_CLEAR);
      /*---(center)---------*/
      if (a_mode == YASCII_CLEAR)             yASCII_print  (x + 1, y + i, x_line, YASCII_CLEAR);
      /*---(right)----------*/
      yASCII_single (x + w - 1, y + i, x_righ);
      c = yASCII_get (x + w - 1, y + i);
      if (a_mode == YASCII_CLEAR && c == 'ä') yASCII_print  (x + w - 1, y + i, "á", YASCII_CLEAR);
      /*---(done)-----------*/
   }
   /*---(bottom)-------------------------*/
   yASCII_single (x        , y + t - 1, 'Ñ');
   for (x_cnt = 0, i = x + 1; i < x + w - 1; ++i) {
      yASCII_single_dos (x_cnt++, i, y + t - 1, x_bott, x_balt);
      c = yASCII_get (i, y + t - 1);
      if (a_mode == YASCII_CLEAR && c == 'ä') yASCII_print  (i, y + t - 1, "â", YASCII_CLEAR);
   }
   yASCII_single (x + w - 1, y + t - 1, 'Ö');
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yASCII_box_full         (char a_heavy, short x, short y, short w, short t, char a_name [LEN_TITLE], char a_note [LEN_SHORT], char a_block, char a_npred, char a_nsucc)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   short       i           =    0;
   char        x_line      [LEN_HUND]  = "";
   short       l           =    0;
   char        x_left, x_topp, x_righ, x_bott;
   /*---(header)-------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   DEBUG_YASCII   yLOG_complex ("a_args"    , "%3dx, %3dy, %3dw, %3dt", x, y, w, t);
   /*---(lines)--------------------------*/
   rc = yascii__outline (a_heavy, x, y, w, t, YASCII_CLEAR);
   DEBUG_YASCII   yLOG_value   ("outline"   , rc);
   /*---(title)--------------------------*/
   if (myASCII.d_names == 'y') {
      ystrlcpy (x_line, a_name, w - 1);
      l = strlen (x_line);
      yASCII_print (x + 1, y + 1, x_line, YASCII_CLEAR);
   }
   /*---(note)---------------------------*/
   if (myASCII.d_notes == 'y' && myASCII.d_size != 'u') {
      if (strcmp (a_note, "")  != 0) {
         l = strlen (a_note);
         yASCII_print (x + w - l - 1, y + t - 1, a_note, YASCII_CLEAR);
      }
   }
   /*---(block)--------------------------*/
   if (myASCII.d_blocks == 'y') {
      if (a_block != '-') {
         sprintf (x_line, "%c", a_block);
         yASCII_print (x + 1, y, x_line, YASCII_CLEAR);
      }
   }
   /*---(stats)--------------------------*/
   if (myASCII.d_counts == 'y' && myASCII.d_size != 'u') {
      if (a_npred > 0) {
         if (a_npred == 1)  strcpy  (x_line, "†");
         else               sprintf (x_line, "%-3d", a_npred);
         yASCII_print (x + 1, y + t, x_line, YASCII_CLEAR);
      }
      if (a_nsucc > 0) {
         if (a_nsucc == 1)  strcpy  (x_line, "  †");
         else               sprintf (x_line, "%3d" , a_nsucc);
         yASCII_print (x + w - 4, y + t, x_line, YASCII_CLEAR);
      }
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yASCII_box_grid         (char a_col, char a_row, char a_name [LEN_TITLE], char a_note [LEN_SHORT], char a_block, char a_npred, char a_nsucc)
{
   /*---(locals)-----------+-----+-----+-*/
   short       x, y;
   /*---(prepare)------------------------*/
   x = myASCII.x_left + (a_col * myASCII.x_wide);
   y = myASCII.y_topp + (a_row * myASCII.y_tall);
   /*---(complete)-----------------------*/
   return yASCII_box_full (myASCII.d_box, x, y, myASCII.x_side, myASCII.y_side, a_name, a_note, a_block, a_npred, a_nsucc);
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
   yASCII_print (x, y    , "ÉÄÄÄÇ", YASCII_CLEAR);
   yASCII_print (x, y + 1, "Å   Å", YASCII_CLEAR);
   yASCII_print (x, y + 2, "ÑÄÄÄÖ", YASCII_CLEAR);
   /*---(label)--------------------------*/
   if (myASCII.d_names == 'y') {
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
/*===----                         unit testing                         ----===*/
/*====================------------------------------------====================*/
static void  o___CONNECT_________o () { return; }

/*
 *    É≤≤≤Ü   á≤≤≤Ç        É≤≤âÄÄÄâ≤≤Ç
 *    åÉ≤≤Ü   á≤≤Çå        åÉ≤Ü   á≤Çå
 *  á≤ÖåÉ≤Ü   á≤ÇåÑ≤Ü   ÄÄâÖåÉàÄÄÄàÇåÑâÄÄ
 *  á≤≤Öå       åÑ≤≤Ü     á≤Öå     åÑ≤Ü
 *  á≤≤≤Ö       Ñ≤≤≤Ü   ÄÄà≤≤Ö     Ñ≤≤àÄÄ   
 *
 *  á≤≤≤Ç       É≤≤≤Ü   ÄÄâ≤≤Ç     É≤≤âÄÄ
 *  á≤≤Çå       åÉ≤≤Ü     á≤Çå     åÉ≤Ü
 *  á≤ÇåÑ≤Ü   á≤ÖåÉ≤Ü   ÄÄàÇåÑâÄÄÄâÖåÉàÄÄ
 *    åÑ≤≤Ü   á≤≤Öå        åÑ≤Ü   á≤Öå 
 *    Ñ≤≤≤Ü   á≤≤≤Ö        Ñ≤≤àÄÄÄà≤≤Ö
 */

/*
 *     áâââÜ
 *
 *     á≤âââ≤Ü
 *
 *     á≤â≤â≤â≤Ü
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
   rc = yascii__heaviness (a_heavy, &x_vert, &x_horz, NULL, NULL);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   if (x_horz == 'ç')  x_halt = 'Ä';
   else                x_halt = x_horz;
   DEBUG_YASCII   yLOG_complex ("lines"     , "%c  %c  %c", x_vert, x_horz, x_halt);
   /*---(interpret lanes)----------------*/
   switch (a_blane) {
   case 't' :  a_blane = 0;                                   break;
   case 'm' :  a_blane = trunc ((myASCII.y_side - 1) / 2.0);  break;
   case 'b' :  a_blane = myASCII.y_side - 1;                  break;
   }
   DEBUG_YASCII   yLOG_value   ("a_blane"   , a_blane);
   switch (a_vlane) {
   case 'l' :  if (myASCII.x_gap == 3)  a_vlane = 1;  else a_vlane = 2; break;
   case 'c' :  a_vlane = trunc ((myASCII.x_gap  - 1) / 2.0) + 1;  break;
   case 'r' :  if (myASCII.x_gap == 3)  a_vlane = 3;  else a_vlane = myASCII.x_gap - 1; break;
   }
   DEBUG_YASCII   yLOG_value   ("a_vlane"   , a_vlane);
   switch (a_elane) {
   case 't' :  a_elane = 0;                                   break;
   case 'm' :  a_elane = trunc ((myASCII.y_side - 1) / 2.0);  break;
   case 'b' :  a_elane = myASCII.y_side - 1;                  break;
   }
   DEBUG_YASCII   yLOG_value   ("a_elane"   , a_elane);
   /*---(direction)----------------------*/
   if      (by + a_blane == ey + a_elane)   x_dir = '÷';
   else if (by + a_blane <  ey + a_elane)   x_dir = '’';
   else                                     x_dir = '‘';
   DEBUG_YASCII   yLOG_char    ("x_dir"     , x_dir);
   /*---(start)--------------------------*/
   if      (a_blane == 0)            yASCII_print (bx, by             , "â", YASCII_CLEAR); 
   else if (a_blane == a_tall - 1)   yASCII_print (bx, by + a_tall - 1, "à", YASCII_CLEAR); 
   else                              yASCII_print (bx, by + a_blane   , "á", YASCII_CLEAR); 
   /*---(finish)-------------------------*/
   if      (a_elane == 0)            yASCII_print (ex, ey             , "â", YASCII_CLEAR); 
   else if (a_elane == a_tall - 1)   yASCII_print (ex, ey + a_tall - 1, "à", YASCII_CLEAR); 
   else                              yASCII_print (ex, ey + a_elane   , "Ü", YASCII_CLEAR); 
   /*---(connect)------------------------*/
   switch (x_dir) {
   case '÷' : 
      DEBUG_YASCII   yLOG_note    ("horizontal");
      for (x_cnt = 0, i = bx + 1; i <= ex - 1; ++i)    yASCII_single_dos (x_cnt++, i, by + a_blane, x_horz, x_halt);
      break;
   case '‘' : 
      DEBUG_YASCII   yLOG_note    ("ascending/upward line");
      x_beg  = bx + 1;
      x_vrt  = ex - (myASCII.x_gap + 1) + a_vlane;
      x_end  = ex - 1;
      y_bot  = by + a_blane;
      y_top  = ey + a_elane;
      DEBUG_YASCII   yLOG_complex ("pos"       , "H %3db, %3dv, %3de  V %3db, %3dt", x_beg, x_vrt, x_end, y_bot, y_top);
      for (x_cnt = 0, i = x_beg; i < x_vrt; ++i)              yASCII_single_dos (x_cnt++, i, y_bot, x_horz, x_halt);
      yASCII_single (x_vrt, y_bot, 'Ö');
      for (i = y_bot - 1; i >= y_top + 1; --i)                yASCII_single (x_vrt, i, x_vert);
      yASCII_single (x_vrt, y_top, 'É');
      for (x_cnt = 0, i = x_vrt + 1; i <= x_end; ++i)         yASCII_single_dos (x_cnt++, i, y_top, x_horz, x_halt);
      break;
   case '’' :
      DEBUG_YASCII   yLOG_note    ("descending/downward line");
      for (x_cnt = 0, i = bx + 1; i < bx + a_vlane; ++i)      yASCII_single_dos (x_cnt++, i, by + a_blane, x_horz, x_halt);
      yASCII_single (bx + a_vlane, by + a_blane, 'Ç');
      for (i = by + a_blane + 1; i <= ey + a_elane - 1; ++i)  yASCII_single (bx + a_vlane, i, x_vert);
      yASCII_single (bx + a_vlane, ey + a_elane, 'Ñ');
      for (x_cnt = 0, i = bx + a_vlane + 1; i <= ex - 1; ++i) yASCII_single_dos (x_cnt++, i, ey + a_elane, x_horz, x_halt);
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
   return yASCII_tie_full (a_heavy, bx, by, ex, ey, myASCII.y_tall - myASCII.y_gap, 'm', 'c', 'm');
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



/*====================------------------------------------====================*/
/*===----                        specialty stuff                       ----===*/
/*====================------------------------------------====================*/
static void  o___SPECIALTY_______o () { return; }

char
yascii_vertical         (short x, short yt, short yh, short yb)
{
   int         i           =    0;
   yASCII_single (x, yt, 'â');
   for (i = yt + 1; i <= yb - 1; ++i) yASCII_single (x,  i, 'Å');
   yASCII_single (x, yh, 'ä');
   yASCII_single (x, yb, 'à');
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
   sprintf (s, "É%*.*sÇ", l, l, YSTR_HORZ);
   yASCII_print (xb, yt, s, YASCII_CLEAR);
   /*---(middle)----------------------*/
   sprintf (s, "Å%*.*sÅ", l, l, YSTR_EMPTY);
   for (i = yt + 1; i <= ye - 1; ++i)  yASCII_print (xb, i, s, YASCII_MERGE);
   /*---(bottom)----------------------*/
   sprintf (s, "Ñ%*.*sÖ", l, l, YSTR_HORZ);
   yASCII_print (xb, ye - 1, s, YASCII_CLEAR);
   /*---(header line)-----------------*/
   sprintf (s, "á%*.*sÜ", l, l, YSTR_EDOTS);
   yASCII_print (xb, yh, s, YASCII_CLEAR);
   /*---(column numbers)--------------*/
   for (i = a_bcol; i <= a_ecol; ++i) {
      sprintf (s, "%02d", i);
      yASCII_print (x_left + (myASCII.x_wide * i) + trunc (myASCII.x_side / 2.0) - 1, ye - 1, s, YASCII_CLEAR);
   }
   /*---(title)-----------------------*/
   if (a_title != NULL && strcmp (a_title, "") != 0) {
      l = strlen (a_title);
      sprintf (s, "É%*.*sÇ", l + 2, l + 2, YSTR_HORZ);
      yASCII_print (x_left, yb    , s, YASCII_CLEAR);
      sprintf (s, "Ü %s á", a_title);
      yASCII_print (x_left, yb + 1, s, YASCII_CLEAR);
      sprintf (s, "Ñ%*.*sÖ", l + 2, l + 2, YSTR_HORZ);
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
   rc = yascii__heaviness (a_heavy, &x_left, &x_topp, &x_righ, &x_bott);
   --rce;  if (rc < 0)  return rce;
   /*---(set margins)-----------------*/
   --rce;  switch (a_type) {
   case 'r' :
      break;
   case 'b' :
      xb -= 1;  xe += 1;  yb -= 1;  ye -= 1;
      break;
   case 'f' :
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
   case 'F' :
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
   yASCII_single (xb, yb, 'É');
   for (i = xb + 1; i < xe; ++i)  yASCII_single (i, yb, x_topp);
   yASCII_single (xe, yb, 'Ç');
   /*---(middle)----------------------*/
   for (i = yb + 1; i < ye; ++i) {
      yASCII_single (xb, i, x_left);
      yASCII_single (xe, i, x_righ);
   }
   /*---(bottom)----------------------*/
   yASCII_single (xb, ye, 'Ñ');
   for (i = xb + 1; i < xe; ++i)  yASCII_single (i, ye, x_bott);
   yASCII_single (xe, ye, 'Ö');
   /*---(complete)--------------------*/
   return 0;
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
            myASCII.d_size,
            myASCII.x_left, myASCII.x_max, myASCII.x_wide, myASCII.x_side, myASCII.x_gap,
            myASCII.y_topp, myASCII.y_max, myASCII.y_tall, myASCII.y_side, myASCII.y_gap);
   }
   /*---(complete)-----------------------*/
   return unit_answer;
}
