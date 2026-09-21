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
   char        l_beg;
   char        l_1st;
   char        l_2nd;
   char        l_end;
} const S_lines [LEN_DESC] = {
   /*---(up/north)------------------*/
   { "NW"  , " à Ç á ¥ " },
   { "NWN" , " à Ç Ñ â " },
   { "N"   , " à â ¥ ¥ " },
   { "NEN" , " à É Ö â " },
   { "NE"  , " à É Ü ¥ " },
   { "NES" , " à É Ç à " },
   { "NWS" , " à Ç É à " },
   /*---(right/east)----------------*/
   { "EN"  , " á Ö â ¥ " },
   { "ENE" , " á Ö É Ü " },
   { "E"   , " á Ü ¥ ¥ " },
   { "ESE" , " á Ç Ñ Ü " },
   { "ES"  , " á Ç à ¥ " },
   { "ESW" , " á Ç Ö á " },
   { "ENW" , " á Ö Ç á " },
   /*---(down/south)----------------*/
   { "SE"  , " â Ñ Ü ¥ " },
   { "SES" , " â Ñ Ç à " },
   { "S"   , " â à ¥ ¥ " },
   { "SWS" , " â Ö É à " },
   { "SW"  , " â Ö á ¥ " },
   { "SEN" , " â Ñ Ö â " },
   { "SWN" , " â Ö Ñ â " },
   /*---(left/west)-----------------*/
   { "WS"  , " Ü É à ¥ " },
   { "WSW" , " Ü É Ö á " },
   { "W"   , " Ü á ¥ ¥ " },
   { "WNW" , " Ü Ñ Ç á " },
   { "WN"  , " Ü Ñ â ¥ " },
   { "WSE" , " Ü É Ñ Ü " },
   { "WNE" , " Ü Ñ É Ü " },
   /*---(DONE)----------------------*/
   { "end" , " x x x x " },
};



/*
 *        YASCII_BASE      YASCII_STD       YASCII_BIG      YASCII_TECH    
 *
 *       ÉÄÄÄÄÄÄÄÄÄÄÄÄÇ   ÉÄÄÄÄÄÄÄÄÄÄÄÄÇ   ÉÄÄtestingÄÄÄÇ   ÉÄÄtestingÄÄÄÇ
 *       Å            Å   Ütesting     á   Ü            á   Ü√          ¬á
 *       ÑÄÄÄÄÄÄÄÄÄÄÄÄÖ   Ñ<k>ÄÄÄÄÄ(uv)Ö   Ñ<k>ÄÄÄÄÄ(uv)Ö   Ñ<k>ÄÄÄÄÄ(uv)Ö
 *                         3          2     3          2                 
 */


/*
 *           
 *             TS TL   TC   TR TE
 *            MS áÄMLÄÄMCÄÄMRÄÜ ME
 *             BS BL   BC   BR BE
 *
 *
 */

/*                   NWS      NWN  N  NEN      NES
 *        WNE   ÉÄÄÄÄÄÄÄÄÄÄÄÇ â    â    â ÉÄÄÄÄÄÄÄÄÄÄÄÇ   ENW
 *       ÉÄÄÄÜ  Å           Å Å    Å    Å Å           Å  áÄÄÄÇ
 *       Å      à  áÄÄÄÄÄÄÇ Å Å    Å    Å Å ÉÄÄÄÄÄÄÜ  à      Å
 *       Å      â   NW    Å Å ÑÄÄÇ Å ÉÄÄÖ Å Å    NE   â      Å
 *       Å   WN Å         Å Å    Å Å Å    Å Å         Å EN   Å
 *       Å      Å         Å Å    Å Å Å    Å Å         Å      Å
 *       Å      Å     ÉÄÄÄàÄàÄÄÄÄàÄàÄàÄÄÄÄàÄàÄÄÄÇ     Å      Å
 *       Å      ÑÄÄÄÄÄÜœ  œ œ    œ œ œ    œ œ  œáÄÄÄÄÄÖ      Å
 *       ÑÄÄÄÄÄÄÄÄÄÄÄÄÜœ                       œáÄÄÄÄÄÄÄÄÄÄÄÄÖ 
 *          áÄÄÄÄÇ    Å                         Å    ÉÄÄÄÄÜ 
 *       WNW     Å    Å                         Å    Å     ENE
 *               ÑÄÄÄÄÜœ     twenty-eight      œáÄÄÄÄÖ
 *        W áÄÄÄÄÄÄÄÄÄÜœ                       œáÄÄÄÄÄÄÄÄÄÜ E
 *               ÉÄÄÄÄÜœ      connectors       œáÄÄÄÄÇ
 *       WSW     Å    Å                         Å    Å     ESE
 *          áÄÄÄÄÖ    Å                         Å    ÑÄÄÄÄÜ 
 *       ÉÄÄÄÄÄÄÄÄÄÄÄÄÜœ                        áÄÄÄÄÄÄÄÄÄÄÄÄÇ
 *       Å      ÉÄÄÄÄÄÜœ  œ œ    œ œ œ    œ œ  œáÄÄÄÄÄÇ      Å
 *       Å      Å     ÑÄÄÄâÄâÄÄÄÄâÄâÄâÄÄÄÄâÄâÄÄÄÖ     Å      Å
 *       Å      Å         Å Å    Å Å Å    Å Å         Å      Å
 *       Å   SE Å         Å Å    Å Å Å    Å Å         Å ES   Å
 *       Å      à   SW    Å Å ÉÄÄÖ Å ÑÄÄÇ Å Å    SE   à      Å
 *       Å      â  áÄÄÄÄÄÄÖ Å Å    Å    Å Å ÑÄÄÄÄÄÄÜ  â      Å
 *       ÑÄÄÄÜ  Å           Å Å    Å    Å Å           Å  áÄÄÄÖ
 *        WSE   ÑÄÄÄÄÄÄÄÄÄÄÄÖ à    à    à ÑÄÄÄÄÄÄÄÄÄÄÄÖ   ESW
 *                   SWN      SWS  S  SES      SEN
 */

/*                        NNW   NN-   NNE
 *                          œ    œ    œ 
 *              NW-         Å    Å    Å         NE-
 *                 œÄÄÄÄÄÄÇ Å    Å    Å ÉÄÄÄÄÄÄœ
 *          WN- œ         Å ÑÄÄÇ Å ÉÄÄÖ Å         œ EN-
 *              Å         Å    Å Å Å    Å         Å
 *              Å         Å    Å Å Å    Å         Å
 *              Å     ÉÄÄÄàÄÄÄÄàÄàÄàÄÄÄÄàÄÄÄÇ     Å
 *              ÑÄÄÄÄÄÜ                     áÄÄÄÄÄÖ
 *      WNW œÄÄÄÄÇ    Å                     Å    ÉÄÄÄÄœ EEN
 *               Å    Å                     Å    Å
 *               ÑÄÄÄÄÜ       twenty        áÄÄÄÄÖ
 *      WW- œÄÄÄÄÄÄÄÄÄÜ                     áÄÄÄÄÄÄÄÄÄœ EE-
 *               ÉÄÄÄÄÜ     connectors      áÄÄÄÄÇ
 *               Å    Å                     Å    Å
 *      WSW œÄÄÄÄÖ    Å                     Å    ÑÄÄÄÄœ EES
 *              ÉÄÄÄÄÄÜ                     áÄÄÄÄÄÇ
 *              Å     ÑÄÄÄâÄÄÄÄâÄâÄâÄÄÄÄâÄÄÄÖ     Å
 *              Å         Å    Å Å Å    Å         Å
 *              Å         Å    Å Å Å    Å         Å
 *          ES- œ         Å ÉÄÄÖ Å ÑÄÄÇ Å         œ ES-
 *                 œÄÄÄÄÄÄÖ Å    Å    Å ÑÄÄÄÄÄÄœ
 *              SW-         Å    Å    Å         SE-
 *                          œ    œ    œ 
 *                        SSW   SS-   SSE
 */
/*
 *    ¥         É≤≤≤≤≤≤≤≤Ç NES                         
 *              å        å                             
 *         ÉÄÄÄÄàÄÇ    ÉÄàÄÄÄÄÇ    ÉÄÄÄÄÄÄÇ    ÉÄÄÄÄÄÄÇ
 *         Å      Å    Å      Å    Å      Å    Å      Å     
 *         Å      Å    Å      Å    Å      Å    Å      Å
 *         ÑÄÄÄÄÄÄÖ    ÑÄÄÄÄÄÄÖ    ÑÄÄÄÄâÄÖ    ÑÄâÄÄÄÄÖ
 *                                      å        å
 *                                  SEN Ñ≤≤≤≤≤≤≤≤Ö
 *
 *
 *    ¥    ÉÄÄÄÄÄÄÇ          ÉÄÄÄÄÄÄÇ   
 *         Å      Å ESW      Å      Å   
 *         Å      á≤≤Ç    É≤≤Ü      Å
 *         ÑÄÄÄÄÄÄÖ  å    å  ÑÄÄÄÄÄÄÖ
 *                   å    å          
 *         ÉÄÄÄÄÄÄÇ  å    å  ÉÄÄÄÄÄÄÇ
 *         Å      á≤≤Ö    Ñ≤≤Ü      Å
 *         Å      Å     WSE  Å      Å   
 *         ÑÄÄÄÄÄÄÖ          ÑÄÄÄÄÄÄÖ   
 *
 *
 */

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

/*  ∑∑-  ¥∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑  -  -  ∑∑- ∑∑- ∑∑- ∑∑-  ¥∑∑∑∑  -  ∑- ∑-  œ */

struct {
   char        b_heavy, b_arrange;
   char        b_title     [LEN_TITLE];
   uchar       b_x, b_y, b_w, b_t;
   char        b_note      [LEN_SHORT];
   char        b_block, b_npred, b_nsucc;
} static S_boxes [LEN_HUND];
static char S_nbox   = 0;
static char S_cbox   = 0;



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
   DEBUG_YASCII   yLOG_complex ("config"    , "%cb, %ct, %cb", ychrvisible (myASCII.d_box), ychrvisible (myASCII.d_tie), ychrvisible (myASCII.d_bound));
   /*---(clear boxes)--------------------*/
   yascii_box__clear ();
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
/*===----                    drawing coonecting lines                  ----===*/
/*====================------------------------------------====================*/
static void      o___LINES______________o (void) {;}

char
yascii__line_ends       (char a_path [LEN_SHORT], char r_ends [LEN_TERSE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         l           =    0;
   int         i           =    0;
   char        n           =   -1;
   /*---(defense)------------------------*/
   if (r_ends != NULL)   strcpy (r_ends, " - - - - ");
   /*---(defense)------------------------*/
   --rce;  if (a_path == NULL || a_path [0] == '\0')  return rce;
   --rce;  if (r_ends == NULL)                        return rce;
   /*---(prepare)------------------------*/
   l = strlen (a_path);
   /*---(walk entries)-------------------*/
   for (i = 0; i < LEN_DESC; ++i) {
      if (strcmp (S_lines [i].l_name, "end")  == 0)  break;
      if (strcmp (S_lines [i].l_name, a_path) != 0)  continue;
      strlcpy (r_ends, S_lines [i].l_ends, LEN_TERSE);
      return 1;
   }
   /*---(save-back)----------------------*/
   return --rce;
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
yascii__label           (short a_bx, short a_by, short a_ex, short a_ey, char a_align [LEN_SHORT], char a_label [LEN_LABEL])
{
   /*---(design notes)-------------------*/
   /* 
    *                                           TL C TR
    *                                              â
    *                                           UL U UR
    *                                              C  
    *             US UL   UC   UR UE               Å
    *            MS áÄMLÄÄMCÄÄMRÄÜ ME           ML M MR
    *             DS DL   DC   DR DE               Å
    *                                              M
    *                                           DL C DR
    *                                              à
    *                                           BL B BR
    */
   /*> short       x_min, x_max, x_len, x_off;                                        <* 
    *> short       y_min, y_max, y_len, y_off;                                        <*/
}

char
yASCII_line             (char a_path [LEN_SHORT], char a_heavy, char a_bef, short a_bx, short a_by, short a_vx, short a_vy, short a_ex, short a_ey, char a_aft, char a_seg, char a_align [LEN_SHORT], char a_label [LEN_LABEL])
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
   --rce;  if (a_bef  == 0 || strchr ("+-œ¥≥†∑ "      , a_bef) == NULL) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_char    ("a_aft"     , a_bef);
   --rce;  if (a_aft  == 0 || strchr ("+-œ¥≥†∑ "      , a_bef) == NULL) {
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
   if (a_bef != ' ') {
      switch (x_dir) {
      case 'E' :  yASCII_single (a_bx - 1, a_by    , a_bef);    break;
      case 'W' :  yASCII_single (a_bx + 1, a_by    , a_bef);    break;
      case 'S' :  yASCII_single (a_bx    , a_by - 1, a_bef);    break;
      case 'N' :  yASCII_single (a_bx    , a_by + 1, a_bef);    break;
      }
   }
   /*---(draw lines)---------------------*/
   --rce;  for (i = 0; i < l; ++i) {
      /*---(prepare)---------------------*/
      x_dir  = a_path [i];
      x_beg  = x_ends [(i * 2) + 1];
      x_end  = x_ends [(i * 2) + 3];
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
   }
   /*---(after)--------------------------*/
   if (a_aft != ' ') {
      switch (x_dir) {
      case 'E' :  yASCII_single (a_bx + 1, a_by    , a_aft);    break;
      case 'W' :  yASCII_single (a_bx - 1, a_by    , a_aft);    break;
      case 'S' :  yASCII_single (a_bx    , a_by + 1, a_aft);    break;
      case 'N' :  yASCII_single (a_bx    , a_by - 1, a_aft);    break;
      }
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 1;
}



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
   if (strcmp (a_title, "") == 0)  sprintf (x_title, "∑%2d", S_nbox);
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
      if (myASCII.d_titles == 'y' && x_title [0] != '∑') {
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
            case 1  : strcpy (x_line, "¡");  break;
            case 2  : strcpy (x_line, "¬");  break;
            case 3  : strcpy (x_line, "√");  break;
            case 4  : strcpy (x_line, "ƒ");  break;
            default : strcpy (x_line, "≈");  break;
            }
            yASCII_print (x + 1, y + t - 2, x_line, YASCII_CLEAR);
            switch (a_nsucc) {
            case 0  : strcpy (x_line, "" );  break;
            case 1  : strcpy (x_line, "¡");  break;
            case 2  : strcpy (x_line, "¬");  break;
            case 3  : strcpy (x_line, "√");  break;
            case 4  : strcpy (x_line, "ƒ");  break;
            default : strcpy (x_line, "≈");  break;
            }
            yASCII_print (x + w - 2, y + t - 2, x_line, YASCII_CLEAR);
         } else {
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
   yASCII_print (x, y    , "ÉÄÄÄÇ", YASCII_CLEAR);
   yASCII_print (x, y + 1, "Å   Å", YASCII_CLEAR);
   yASCII_print (x, y + 2, "ÑÄÄÄÖ", YASCII_CLEAR);
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
      strcpy (unit_answer, "seq  ---title---------------------  H  A  --x --y --w --t  note  B  pr sc  œ");
      DEBUG_YDLST   yLOG_sexit   (__FUNCTION__);
      return unit_answer;
   }
   /*---(defaults)-----------------------*/
   strcpy (unit_answer, "∑∑-  ¥∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑  -  -  ∑∑- ∑∑- ∑∑- ∑∑-  ¥∑∑∑  -  ∑- ∑-  œ");
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
      snprintf (x_title, LEN_TITLE, "%s∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑", S_boxes [x_curr].b_title);
      if (strcmp (S_boxes [x_curr].b_note, "") == 0)  strlcpy  (x_note, "¥∑∑∑∑", LEN_SHORT);
      else                                            snprintf (x_note, LEN_SHORT, "%s∑∑∑∑", S_boxes [x_curr].b_note);
      sprintf (unit_answer, "%3d  %-29.29s  %c  %c  %3d %3d %3d %3d  %-4.4s  %c  %2d %2d  œ", x_curr,
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
 *>    rc = yascii__heaviness (a_heavy, &x_vert, &x_horz, NULL, NULL);                                                                                                  <* 
 *>    --rce;  if (rc < 0) {                                                                                                                                            <* 
 *>       DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);                                                                                                              <* 
 *>       return rce;                                                                                                                                                   <* 
 *>    }                                                                                                                                                                <* 
 *>    if (x_horz == 'ç')  x_halt = 'Ä';                                                                                                                                <* 
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
 *>    if      (by + a_blane == ey + a_elane)   x_dir = '÷';                                                                                                            <* 
 *>    else if (by + a_blane <  ey + a_elane)   x_dir = '’';                                                                                                            <* 
 *>    else                                     x_dir = '‘';                                                                                                            <* 
 *>    DEBUG_YASCII   yLOG_char    ("x_dir"     , x_dir);                                                                                                               <* 
 *>    /+---(start)--------------------------+/                                                                                                                         <* 
 *>    if      (a_blane == 0)            yASCII_print (bx, by             , "â", YASCII_CLEAR);                                                                         <* 
 *>    else if (a_blane == a_tall - 1)   yASCII_print (bx, by + a_tall - 1, "à", YASCII_CLEAR);                                                                         <* 
 *>    else                              yASCII_print (bx, by + a_blane   , "á", YASCII_CLEAR);                                                                         <* 
 *>    /+---(finish)-------------------------+/                                                                                                                         <* 
 *>    if      (a_elane == 0)            yASCII_print (ex, ey             , "â", YASCII_CLEAR);                                                                         <* 
 *>    else if (a_elane == a_tall - 1)   yASCII_print (ex, ey + a_tall - 1, "à", YASCII_CLEAR);                                                                         <* 
 *>    else                              yASCII_print (ex, ey + a_elane   , "Ü", YASCII_CLEAR);                                                                         <* 
 *>    /+---(connect)------------------------+/                                                                                                                         <* 
 *>    switch (x_dir) {                                                                                                                                                 <* 
 *>    case '÷' :                                                                                                                                                       <* 
 *>       DEBUG_YASCII   yLOG_note    ("horizontal");                                                                                                                   <* 
 *>       for (x_cnt = 0, i = bx + 1; i <= ex - 1; ++i)    yASCII_single_dos (x_cnt++, i, by + a_blane, x_horz, x_halt);                                                <* 
 *>       break;                                                                                                                                                        <* 
 *>    case '‘' :                                                                                                                                                       <* 
 *>       DEBUG_YASCII   yLOG_note    ("ascending/upward line");                                                                                                        <* 
 *>       x_beg  = bx + 1;                                                                                                                                              <* 
 *>       x_vrt  = ex - (myASCII.x_gap + 1) + a_vlane;                                                                                                                  <* 
 *>       x_end  = ex - 1;                                                                                                                                              <* 
 *>       y_bot  = by + a_blane;                                                                                                                                        <* 
 *>       y_top  = ey + a_elane;                                                                                                                                        <* 
 *>       DEBUG_YASCII   yLOG_complex ("pos"       , "H %3db, %3dv, %3de  V %3db, %3dt", x_beg, x_vrt, x_end, y_bot, y_top);                                            <* 
 *>       for (x_cnt = 0, i = x_beg; i < x_vrt; ++i)              yASCII_single_dos (x_cnt++, i, y_bot, x_horz, x_halt);                                                <* 
*>       yASCII_single (x_vrt, y_bot, 'Ö');                                                                                                                            <* 
*>       for (i = y_bot - 1; i >= y_top + 1; --i)                yASCII_single (x_vrt, i, x_vert);                                                                     <* 
*>       yASCII_single (x_vrt, y_top, 'É');                                                                                                                            <* 
*>       for (x_cnt = 0, i = x_vrt + 1; i <= x_end; ++i)         yASCII_single_dos (x_cnt++, i, y_top, x_horz, x_halt);                                                <* 
*>       break;                                                                                                                                                        <* 
*>    case '’' :                                                                                                                                                       <* 
*>       DEBUG_YASCII   yLOG_note    ("descending/downward line");                                                                                                     <* 
*>       for (x_cnt = 0, i = bx + 1; i < bx + a_vlane; ++i)      yASCII_single_dos (x_cnt++, i, by + a_blane, x_horz, x_halt);                                         <* 
*>       yASCII_single (bx + a_vlane, by + a_blane, 'Ç');                                                                                                              <* 
*>       for (i = by + a_blane + 1; i <= ey + a_elane - 1; ++i)  yASCII_single (bx + a_vlane, i, x_vert);                                                              <* 
*>       yASCII_single (bx + a_vlane, ey + a_elane, 'Ñ');                                                                                                              <* 
*>       for (x_cnt = 0, i = bx + a_vlane + 1; i <= ex - 1; ++i) yASCII_single_dos (x_cnt++, i, ey + a_elane, x_horz, x_halt);                                         <* 
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
   --rce;  if (a_bbase == 0 || strchr ("ÇÅÖ", a_bbase) == NULL) {
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
   --rce;  if (a_ebase == 0 || strchr ("ÉÅÑ", a_ebase) == NULL) {
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
   if (r_base != NULL)  *r_base = 'œ';
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
      case 'b'  : if (n == 0)  *r_base = 'â';  else if (n == x_max)  *r_base = 'à';  else *r_base = 'á';  break;
      case 'e'  : if (n == 0)  *r_base = 'â';  else if (n == x_max)  *r_base = 'à';  else *r_base = 'Ü';  break;
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
   rc = yascii__heaviness (a_heavy, &x_vert, &x_horz, NULL, NULL);
   DEBUG_YASCII   yLOG_value   ("heavy"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   if (x_horz == 'ç')  x_halt = 'Ä';
   else                x_halt = x_horz;
   DEBUG_YASCII   yLOG_complex ("lines"     , "%c  %c  %c", x_vert, x_horz, x_halt);
   /*---(direction)----------------------*/
   if      (a_by == a_ey)   x_dir = '÷';
   else if (a_by <  a_ey)   x_dir = '’';
   else                     x_dir = '‘';
   DEBUG_YASCII   yLOG_char    ("x_dir"     , x_dir);
   /*---(display endpionts)--------------*/
   yASCII_print (a_bx, a_by, a_bbase, YASCII_CLEAR); 
   yASCII_print (a_ex, a_ey, a_ebase, YASCII_CLEAR); 
   /*---(horizontal)---------------------*/
   if (x_dir == '÷') {
      DEBUG_YASCII   yLOG_note    ("horizontal");
      for (x_cnt = 0, i = a_bx + 1; i < a_ex; ++i)   yASCII_single_dos (x_cnt++, i, a_by, x_horz, x_halt);
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 1;
   }
   /*---(ascending/upward)---------------*/
   if (x_dir == '‘') {
      DEBUG_YASCII   yLOG_note    ("ascending/upward line");
      for (x_cnt = 0, i = a_bx + 1; i < a_vx; ++i)   yASCII_single_dos (x_cnt++, i, a_by, x_horz, x_halt);
      yASCII_single (a_vx, a_by, 'Ö');
      for (i = a_by - 1; i >= a_ey + 1; --i)         yASCII_single (a_vx, i, a_vx);
      yASCII_single (a_vx, a_ey, 'É');
      for (x_cnt = 0, i = a_vx + 1; i < a_ex; ++i)   yASCII_single_dos (x_cnt++, i, a_ey, x_horz, x_halt);
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 2;
   }
   /*---(decending/downward)-------------*/
   if (x_dir == '’') {
      DEBUG_YASCII   yLOG_note    ("descending/downward line");
      for (x_cnt = 0, i = a_bx + 1; i < a_vx; ++i)   yASCII_single_dos (x_cnt++, i, a_by, x_horz, x_halt);
      yASCII_single (a_vx, a_by, 'Ç');
      for (i = a_by + 1; i <= a_ey - 1; ++i)         yASCII_single (a_bx, i, a_vx);
      yASCII_single (a_vx, a_ey, 'Ñ');
      for (x_cnt = 0, i = a_vx + 1; i < a_ex; ++i)   yASCII_single_dos (x_cnt++, i, a_ey, x_horz, x_halt);
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
   short       bx, ex;
   short       by, ey;
   short       bt, et;
   short       bo, vo, eo;
   char        x_bbase     [LEN_SHORT] = "?";
   char        x_ebase     [LEN_SHORT] = "?";
   /*---(enter)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   x_pred = yascii_box_find (a_pred);
   DEBUG_YASCII   yLOG_value   ("x_pred"    , x_pred);
   --rce;  if (x_pred < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   x_succ = yascii_box_find (a_succ);
   DEBUG_YASCII   yLOG_value   ("x_succ"    , x_succ);
   --rce;  if (x_succ < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_complex ("a_args"    , "%-20.20s to %-20.20s, %c, %1dbl, %1dvl, %1del", a_pred, a_succ, a_heavy, a_blane, a_vlane, a_elane);
   /*---(specifics)----------------------*/
   bx = S_boxes [x_pred].b_x + S_boxes [x_pred].b_w - 1;
   ex = S_boxes [x_succ].b_x;
   by = S_boxes [x_pred].b_y;
   ey = S_boxes [x_succ].b_y;
   bt = S_boxes [x_pred].b_t;
   et = S_boxes [x_succ].b_t;
   DEBUG_YASCII   yLOG_complex ("refs"      , "beg %3dx, %3dy, %3dt to end %3dx, %3dy, %3dt", bx, by, bt, ex, ey, et);
   /*---(offsets)------------------------*/
   bo  = yascii_link__ranges ('b', a_blane, bt    , x_bbase);
   DEBUG_YASCII   yLOG_value   ("bo"        , bo);
   --rce;  if (bo < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   bo += by;
   vo  = yascii_link__ranges ('-', a_vlane, a_hgap, NULL);
   DEBUG_YASCII   yLOG_value   ("vo"        , vo);
   --rce;  if (vo < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   vo += bx + 1;
   eo  = yascii_link__ranges ('e', a_elane, et    , x_ebase);
   DEBUG_YASCII   yLOG_value   ("eo"        , eo);
   --rce;  if (eo < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   eo += ey;
   DEBUG_YASCII   yLOG_complex ("offs"      , "beg (%c) %3d  vert (%c) %3d/%3d  end (%c) %3d", a_blane, bo, a_vlane, vo, a_hgap, a_elane, eo);
   /*---(draw)---------------------------*/
   rc = yascii_link__detail (a_heavy, bx, bo, x_bbase, vo, ex, eo, x_ebase);
   DEBUG_YASCII   yLOG_value   ("draw"      , rc);
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
