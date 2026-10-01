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
 *       Å      Å         Å Å    Å Å Å    Å Å         E      Å
 *       Å   SE Å         Å Å    Å Å Å    Å Å         S      Å
 *       Å      à   SW    Å Å ÉÄÄÖ Å ÑÄÄÇ Å Å         à      Å
 *       Å      â  áÄÄÄÄÄÄÖ Å Å    Å    Å Å ÑÄÄÄSEÄÜ  â      Å
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


/*>  intersections                                                                       <* 
 *>                                                                                      <* 
 *>                   ÅóÄÄÄÄÄÄÄÄ∞                                                        <* 
 *>            ∞ÄÄÄÄÄñÅ                                                                  <* 
 *>                                                                                      <* 
 *>                                                                                      <* 
 *>                   Å                                                                  <* 
 *>   link     ∞ÄÄÄÄÄÄäÄÄÄÄÄÄÄÄ∞                                                         <* 
 *>                   Å                                                                  <* 
 *>                                                                                      <* 
 *>                   Å                                                                  <* 
 *>            ∞ÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄ∞    easy to miss                                         <* 
 *>                   Å                                                                  <* 
 *>                                                                                      <* 
 *>                   Å                                                                  <* 
 *>            ∞ÄÄÄÄÄÜäáÄÄÄÄÄÄÄ∞    way ambiguous                                        <* 
 *>                   Å                                                                  <* 
 *>                                                                                      <* 
 *>                   Å                                                                  <* 
 *>            ∞ÄÄÄÄÄÄ∞ÄÄÄÄÄÄÄÄ∞    easy to confuse with a pad                           <* 
 *>                   Å                                                                  <* 
 *>                                                                                      <* 
 *>                   Å                                                                  <* 
 *>            ∞ÄÄÄÄÄÄœÄÄÄÄÄÄÄÄ∞    unclear                                              <*
 *>                   Å                                                                  <* 
 *>                                                                                      <* 
 *>                   Å                                                                  <* 
 *>            ∞ÄÄÄÄÄÄ/ÄÄÄÄÄÄÄÄ∞    also more visible                                    <* 
 *>                   Å                                                                  <* 
 *>                                                                                      <* 
 *>                   Å                                                                  <* 
 *>  no-link   ∞ÄÄÄÄÄÄXÄÄÄÄÄÄÄÄ∞    more visible marking, over/under                     <* 
 *>                   Å                                                                  <* 
 *>                                                                                      <* 
 *>                   Å                                                                  <* 
 *>            ∞ÄÄÄÄÄ)Å(ÄÄÄÄÄÄÄ∞    too complicated                                      <* 
 *>                   Å                                                                  <* 
 *>                                                                                      <* 
 *>                   Å                                                                  <* 
 *>            ∞ÄÄÄÄÄÄµÄÄÄÄÄÄÄÄ∞                                                         <* 
 *>                   Å                                                                  <* 
 *>                                                                                      <*/

static char const zASCII_join [LEN_TITLE][LEN_DESC] = {
   /*            ------------- old ------------ */
   /*             123456789-123456789-123456789-123456789-123456789 */
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



/*====================------------------------------------====================*/
/*===----                       configuration                          ----===*/
/*====================------------------------------------====================*/
static void      o___CONFIG_____________o (void) {;}

char
yascii_heaviness        (char a_heavy, char *r_left, char *r_topp, char *r_righ, char *r_bott)
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
   case YASCII_DOTMED  :  x_left = '¥';  x_righ = '¥';  x_topp = '¥';  x_bott = '¥';  break;
   case YASCII_DOTBIG  :  x_left = 'œ';  x_righ = 'œ';  x_topp = 'œ';  x_bott = 'œ';  break;
   case YASCII_DOTSQR  :  x_left = '≥';  x_righ = '≥';  x_topp = '≥';  x_bott = '≥';  break;
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



/*====================------------------------------------====================*/
/*===----                   printing and getting chars                 ----===*/
/*====================------------------------------------====================*/
static void      o___SINGLES____________o (void) {;}

/*
 *
 *
 *           Å  ≥  û
 *           Å  ≥  û
 *   ÉÄÄÄÄÇ  Å  ≥  û
 *   Å  ÉÄäÄÄàÄÄäÄÄàÇ
 *   ÑÄÄäÄÖ     ≥   áÄÄÄÄ
 *      Å   ®   ≥ É≤ä≤≤≤Ç
 *  úúúúÜ   ®     å Å   å
 *      ÑÄâÄäÄâÄâÄäÄÖ   å
 *        é ® å ¥ å     å
 *        é ® å ¥ Ñ≤≤≤≤≤Ö
 *        é ® å ¥            
 */

char
yASCII_draw_get         (short x, short y)
{
   /*---(locals)-----------+-----+-----+-*/
   int         o           =    0;
   /*---(defense)------------------------*/
   if (x <  0)               return '∞';
   if (x >= myASCII.x_max)   return '∞';
   if (y <  0)               return '∞';
   if (y >= myASCII.y_max)   return '∞';
   /*---(calc offset)--------------------*/
   o = (y * myASCII.x_max) + x;
   /*---(complete)-----------------------*/
   return G_image [o];
}

char
yASCII_draw_full        (char c, short x, short y, char a_new, char a_alt, char a_mode)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         x_off       =    0;
   char        x_new       =  '-';
   /*∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑*/
   char       *p           = NULL;
   char        x_valid     [LEN_DESC] = "";
   char        x_row       =   -1;
   char        x_col       =   -1;
   char        x_exist     =   -1;
   char        x_final     =   -1;
   /*---(enter)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(quick-out)----------------------*/
   DEBUG_YASCII   yLOG_value   ("x"         , x);
   DEBUG_YASCII   yLOG_value   ("x_max"     , myASCII.x_max);
   --rce;  if (x < 0 || x >= myASCII.x_max) {
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_YASCII   yLOG_value   ("y"         , y);
   DEBUG_YASCII   yLOG_value   ("y_max"     , myASCII.y_max);
   --rce;  if (y < 0 || y >= myASCII.y_max) {
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_YASCII   yLOG_char    ("a_new"     , a_new);
   --rce;  if ((unsigned) a_new < 32) {
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_YASCII   yLOG_char    ("a_alt"     , a_alt);
   --rce;  if ((unsigned) a_alt < 32) {
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_YASCII   yLOG_char    ("a_mode"    , a_mode);
   --rce;  if (a_mode != YASCII_CLEAR && a_mode != YASCII_MERGE) {
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   /*---(prepare)------------------------*/
   x_off = (y * myASCII.x_max) + x;
   DEBUG_YASCII   yLOG_value   ("x_off"     , x_off);
   DEBUG_YASCII   yLOG_value   ("c"         , c);
   if (c < 0)       c == 0;
   if (c % 2 == 0)  x_new = a_new;
   else             x_new = a_alt;
   DEBUG_YASCII   yLOG_char    ("x_new"     , x_new);
   /*---(replace)------------------------*/
   if (a_mode == YASCII_CLEAR) {
      DEBUG_YASCII   yLOG_note    ("mode in clear, just force it");
      G_image [x_off] = x_new;
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 1;
   }
   DEBUG_YASCII   yLOG_note    ("mode in merge, calculate right char");
   /*---(get valid letters)--------------*/
   ystrlcpy (x_valid, zASCII_join [0], LEN_DESC);
   DEBUG_YASCII   yLOG_info    ("x_valid"   , x_valid);
   /*---(get existing)-------------------*/
   x_exist = yASCII_draw_get (x, y);
   DEBUG_YASCII   yLOG_char    ("x_exist"   , x_exist);
   p = strchr (x_valid, x_exist);
   DEBUG_YASCII   yLOG_point   ("p"         , p);
   if (p == NULL) {
      DEBUG_YASCII   yLOG_note    ("leave alone");
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 3;
   }
   x_col = p - x_valid;
   DEBUG_YASCII   yLOG_value   ("x_col"     , x_col);
   /*---(get new)------------------------*/
   p = strchr (x_valid, x_new);
   DEBUG_YASCII   yLOG_point   ("p"         , p);
   if (p == NULL) {
      if (x_exist == ' ') {
         DEBUG_YASCII   yLOG_note    ("update empty spot");
         G_image [x_off] = x_new;
         DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
         return 5;
      }
      DEBUG_YASCII   yLOG_note    ("leave alone");
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 4;
   }
   x_row = (p - x_valid) / 2;
   DEBUG_YASCII   yLOG_char    ("x_row"     , x_row);
   /*---(identify replacement)-----------*/
   ystrlcpy (x_valid, zASCII_join [x_row], LEN_DESC);
   DEBUG_YASCII   yLOG_info    ("x_valid"   , x_valid);
   x_final = x_valid [x_col];
   DEBUG_YASCII   yLOG_char    ("x_final"   , x_final);
   /*---(replace)------------------------*/
   G_image [x_off] = x_final;
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 2;
}

char yASCII_draw_exact  (short x, short y, char a_new)  { return yASCII_draw_full (0, x, y, a_new, a_new, YASCII_CLEAR); }
char yASCII_draw_merge  (short x, short y, char a_new)  { return yASCII_draw_full (0, x, y, a_new, a_new, YASCII_MERGE); }
char yASCII_draw_double (char c, short x, short y, char a_new, char a_alt)  { return yASCII_draw_full (c, x, y, a_new, a_alt, YASCII_MERGE); }



/*====================------------------------------------====================*/
/*===----                 printing character strings                   ----===*/
/*====================------------------------------------====================*/
static void      o___STRINGS____________o (void) {;}

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
      /*> if (a_mode == YASCII_LAYER)   c = yascii_join (G_image [o], c);             <*/
      G_image [o] = c;
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
   rc = yascii_heaviness (a_heavy, &x_vert, &x_horz, NULL, NULL);
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
      for (x_cnt = 0, i = bx + 1; i <= ex - 1; ++i)    yASCII_draw_double (x_cnt++, i, by + a_blane, x_horz, x_halt);
      break;
   case '‘' : 
      DEBUG_YASCII   yLOG_note    ("ascending/upward line");
      x_beg  = bx + 1;
      x_vrt  = ex - (myASCII.x_gap + 1) + a_vlane;
      x_end  = ex - 1;
      y_bot  = by + a_blane;
      y_top  = ey + a_elane;
      DEBUG_YASCII   yLOG_complex ("pos"       , "H %3db, %3dv, %3de  V %3db, %3dt", x_beg, x_vrt, x_end, y_bot, y_top);
      for (x_cnt = 0, i = x_beg; i < x_vrt; ++i)              yASCII_draw_double (x_cnt++, i, y_bot, x_horz, x_halt);
      yASCII_draw_merge (x_vrt, y_bot, 'Ö');
      for (i = y_bot - 1; i >= y_top + 1; --i)                yASCII_draw_merge (x_vrt, i, x_vert);
      yASCII_draw_merge (x_vrt, y_top, 'É');
      for (x_cnt = 0, i = x_vrt + 1; i <= x_end; ++i)         yASCII_draw_double (x_cnt++, i, y_top, x_horz, x_halt);
      break;
   case '’' :
      DEBUG_YASCII   yLOG_note    ("descending/downward line");
      for (x_cnt = 0, i = bx + 1; i < bx + a_vlane; ++i)      yASCII_draw_double (x_cnt++, i, by + a_blane, x_horz, x_halt);
      yASCII_draw_merge (bx + a_vlane, by + a_blane, 'Ç');
      for (i = by + a_blane + 1; i <= ey + a_elane - 1; ++i)  yASCII_draw_merge (bx + a_vlane, i, x_vert);
      yASCII_draw_merge (bx + a_vlane, ey + a_elane, 'Ñ');
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
 *>    rc = yascii_heaviness (a_heavy, &x_vert, &x_horz, NULL, NULL);                                                                                                  <* 
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
 *>       for (x_cnt = 0, i = bx + 1; i <= ex - 1; ++i)    yASCII_draw_double (x_cnt++, i, by + a_blane, x_horz, x_halt);                                                <* 
 *>       break;                                                                                                                                                        <* 
 *>    case '‘' :                                                                                                                                                       <* 
 *>       DEBUG_YASCII   yLOG_note    ("ascending/upward line");                                                                                                        <* 
 *>       x_beg  = bx + 1;                                                                                                                                              <* 
 *>       x_vrt  = ex - (myASCII.x_gap + 1) + a_vlane;                                                                                                                  <* 
 *>       x_end  = ex - 1;                                                                                                                                              <* 
 *>       y_bot  = by + a_blane;                                                                                                                                        <* 
 *>       y_top  = ey + a_elane;                                                                                                                                        <* 
 *>       DEBUG_YASCII   yLOG_complex ("pos"       , "H %3db, %3dv, %3de  V %3db, %3dt", x_beg, x_vrt, x_end, y_bot, y_top);                                            <* 
 *>       for (x_cnt = 0, i = x_beg; i < x_vrt; ++i)              yASCII_draw_double (x_cnt++, i, y_bot, x_horz, x_halt);                                                <* 
*>       yASCII_draw_merge (x_vrt, y_bot, 'Ö');                                                                                                                            <* 
*>       for (i = y_bot - 1; i >= y_top + 1; --i)                yASCII_draw_merge (x_vrt, i, x_vert);                                                                     <* 
*>       yASCII_draw_merge (x_vrt, y_top, 'É');                                                                                                                            <* 
*>       for (x_cnt = 0, i = x_vrt + 1; i <= x_end; ++i)         yASCII_draw_double (x_cnt++, i, y_top, x_horz, x_halt);                                                <* 
*>       break;                                                                                                                                                        <* 
*>    case '’' :                                                                                                                                                       <* 
*>       DEBUG_YASCII   yLOG_note    ("descending/downward line");                                                                                                     <* 
*>       for (x_cnt = 0, i = bx + 1; i < bx + a_vlane; ++i)      yASCII_draw_double (x_cnt++, i, by + a_blane, x_horz, x_halt);                                         <* 
*>       yASCII_draw_merge (bx + a_vlane, by + a_blane, 'Ç');                                                                                                              <* 
*>       for (i = by + a_blane + 1; i <= ey + a_elane - 1; ++i)  yASCII_draw_merge (bx + a_vlane, i, x_vert);                                                              <* 
*>       yASCII_draw_merge (bx + a_vlane, ey + a_elane, 'Ñ');                                                                                                              <* 
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
   rc = yascii_heaviness (a_heavy, &x_vert, &x_horz, NULL, NULL);
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
      for (x_cnt = 0, i = a_bx + 1; i < a_ex; ++i)   yASCII_draw_double (x_cnt++, i, a_by, x_horz, x_halt);
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 1;
   }
   /*---(ascending/upward)---------------*/
   if (x_dir == '‘') {
      DEBUG_YASCII   yLOG_note    ("ascending/upward line");
      for (x_cnt = 0, i = a_bx + 1; i < a_vx; ++i)   yASCII_draw_double (x_cnt++, i, a_by, x_horz, x_halt);
      yASCII_draw_merge (a_vx, a_by, 'Ö');
      for (i = a_by - 1; i >= a_ey + 1; --i)         yASCII_draw_merge (a_vx, i, a_vx);
      yASCII_draw_merge (a_vx, a_ey, 'É');
      for (x_cnt = 0, i = a_vx + 1; i < a_ex; ++i)   yASCII_draw_double (x_cnt++, i, a_ey, x_horz, x_halt);
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 2;
   }
   /*---(decending/downward)-------------*/
   if (x_dir == '’') {
      DEBUG_YASCII   yLOG_note    ("descending/downward line");
      for (x_cnt = 0, i = a_bx + 1; i < a_vx; ++i)   yASCII_draw_double (x_cnt++, i, a_by, x_horz, x_halt);
      yASCII_draw_merge (a_vx, a_by, 'Ç');
      for (i = a_by + 1; i <= a_ey - 1; ++i)         yASCII_draw_merge (a_bx, i, a_vx);
      yASCII_draw_merge (a_vx, a_ey, 'Ñ');
      for (x_cnt = 0, i = a_vx + 1; i < a_ex; ++i)   yASCII_draw_double (x_cnt++, i, a_ey, x_horz, x_halt);
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 3;
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, --rce);
   return rce;
}

/*> char                                                                                                                                                  <* 
 *> yASCII_link_full        (char a_pred [LEN_TITLE], char a_succ [LEN_TITLE], char a_heavy, char a_hgap, char a_blane, char a_vlane, char a_elane)       <* 
 *> {                                                                                                                                                     <* 
 *>    /+---(locals)-----------+-----+-----+-+/                                                                                                           <* 
 *>    char        rce         =  -10;                                                                                                                    <* 
 *>    char        rc          =    0;                                                                                                                    <* 
 *>    char        x_pred      =    0;                                                                                                                    <* 
 *>    char        x_succ      =    0;                                                                                                                    <* 
 *>    short       bx, ex;                                                                                                                                <* 
 *>    short       by, ey;                                                                                                                                <* 
 *>    short       bt, et;                                                                                                                                <* 
 *>    short       bo, vo, eo;                                                                                                                            <* 
 *>    char        x_bbase     [LEN_SHORT] = "?";                                                                                                         <* 
 *>    char        x_ebase     [LEN_SHORT] = "?";                                                                                                         <* 
 *>    /+---(enter)--------------------------+/                                                                                                           <* 
 *>    DEBUG_YASCII   yLOG_enter   (__FUNCTION__);                                                                                                        <* 
 *>    /+---(defense)------------------------+/                                                                                                           <* 
 *>    x_pred = yascii_box_find (a_pred);                                                                                                                 <* 
 *>    DEBUG_YASCII   yLOG_value   ("x_pred"    , x_pred);                                                                                                <* 
 *>    --rce;  if (x_pred < 0) {                                                                                                                          <* 
 *>       DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);                                                                                                <* 
 *>       return rce;                                                                                                                                     <* 
 *>    }                                                                                                                                                  <* 
 *>    x_succ = yascii_box_find (a_succ);                                                                                                                 <* 
 *>    DEBUG_YASCII   yLOG_value   ("x_succ"    , x_succ);                                                                                                <* 
 *>    --rce;  if (x_succ < 0) {                                                                                                                          <* 
 *>       DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);                                                                                                <* 
 *>       return rce;                                                                                                                                     <* 
 *>    }                                                                                                                                                  <* 
 *>    DEBUG_YASCII   yLOG_complex ("a_args"    , "%-20.20s to %-20.20s, %c, %1dbl, %1dvl, %1del", a_pred, a_succ, a_heavy, a_blane, a_vlane, a_elane);   <* 
 *>    /+---(specifics)----------------------+/                                                                                                           <* 
 *>    bx = S_boxes [x_pred].b_x + S_boxes [x_pred].b_w - 1;                                                                                              <* 
 *>    ex = S_boxes [x_succ].b_x;                                                                                                                         <* 
 *>    by = S_boxes [x_pred].b_y;                                                                                                                         <* 
 *>    ey = S_boxes [x_succ].b_y;                                                                                                                         <* 
 *>    bt = S_boxes [x_pred].b_t;                                                                                                                         <* 
 *>    et = S_boxes [x_succ].b_t;                                                                                                                         <* 
 *>    DEBUG_YASCII   yLOG_complex ("refs"      , "beg %3dx, %3dy, %3dt to end %3dx, %3dy, %3dt", bx, by, bt, ex, ey, et);                                <* 
 *>    /+---(offsets)------------------------+/                                                                                                           <* 
 *>    bo  = yascii_link__ranges ('b', a_blane, bt    , x_bbase);                                                                                         <* 
 *>    DEBUG_YASCII   yLOG_value   ("bo"        , bo);                                                                                                    <* 
 *>    --rce;  if (bo < 0) {                                                                                                                              <* 
 *>       DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);                                                                                                <* 
 *>       return rce;                                                                                                                                     <* 
 *>    }                                                                                                                                                  <* 
 *>    bo += by;                                                                                                                                          <* 
 *>    vo  = yascii_link__ranges ('-', a_vlane, a_hgap, NULL);                                                                                            <* 
 *>    DEBUG_YASCII   yLOG_value   ("vo"        , vo);                                                                                                    <* 
 *>    --rce;  if (vo < 0) {                                                                                                                              <* 
 *>       DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);                                                                                                <* 
 *>       return rce;                                                                                                                                     <* 
 *>    }                                                                                                                                                  <* 
 *>    vo += bx + 1;                                                                                                                                      <* 
 *>    eo  = yascii_link__ranges ('e', a_elane, et    , x_ebase);                                                                                         <* 
 *>    DEBUG_YASCII   yLOG_value   ("eo"        , eo);                                                                                                    <* 
 *>    --rce;  if (eo < 0) {                                                                                                                              <* 
 *>       DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);                                                                                                <* 
 *>       return rce;                                                                                                                                     <* 
 *>    }                                                                                                                                                  <* 
 *>    eo += ey;                                                                                                                                          <* 
 *>    DEBUG_YASCII   yLOG_complex ("offs"      , "beg (%c) %3d  vert (%c) %3d/%3d  end (%c) %3d", a_blane, bo, a_vlane, vo, a_hgap, a_elane, eo);        <* 
 *>    /+---(draw)---------------------------+/                                                                                                           <* 
 *>    rc = yascii_link__detail (a_heavy, bx, bo, x_bbase, vo, ex, eo, x_ebase);                                                                          <* 
 *>    DEBUG_YASCII   yLOG_value   ("draw"      , rc);                                                                                                    <* 
 *>    --rce;  if (rc < 0) {                                                                                                                              <* 
 *>       DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);                                                                                                <* 
 *>       return rce;                                                                                                                                     <* 
 *>    }                                                                                                                                                  <* 
 *>    /+---(complete)-----------------------+/                                                                                                           <* 
 *>    DEBUG_YASCII   yLOG_exit    (__FUNCTION__);                                                                                                        <* 
 *>    return 0;                                                                                                                                          <* 
*> }                                                                                                                                                     <*/



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
