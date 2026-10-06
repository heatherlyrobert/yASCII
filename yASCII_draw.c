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
 *       ÉÄÄÄÄÄÄÄÄÄÄÄÄÇ   ÉÄÄÄÄÄÄÄÄÄÄÄÄÇ   ÉÄ testing ÄÄÇ   ÉÄ testing ÄÄÇ
 *       Å            Å   Ütesting     á   Ü            á   Ü√          ¬á
 *       ÑÄÄÄÄÄÄÄÄÄÄÄÄÖ   ÑÄkÄÄÄÄÄÄÄuvÄÖ   ÑÄkÄÄÄÄÄÄÄuvÄÖ   ÑÄkÄÄÄÄÄÄÄuvÄÖ
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

static char const zASCII_join [LEN_HUND][LEN_HUND] = {
   /*            ------------- old ------------ */
   /*             123456789-123456789-123456789-123456789-123456789 */
   /*                                          h h v v h v h v h v  */
   /* new */  { "  ≤ å Ä Å É Ö Ñ Ç Ü á â à ä ∑ ù ú û ü ç é - | = ®" },
   /*  ≤  */  { "≤ ≤ ä Ä ä â à à â ä ä â à ä ≤ ù ú ä ä ç ä - ä = ä" },
   /*  å  */  { "å ä å ä Å á Ü á Ü Ü á ä ä ä å ä ä û ü ä é ä | ä ®" },
   /*  Ä  */  { "Ä Ä ä Ä ä â à à â ä ä â à ä Ä ù ú ä ä ç ä - ä = ä" },
   /*  Å  */  { "Å ä Å ä Å á Ü á Ü Ü á ä ä ä Å ä ä û ü ä é ä | ä ®" },
   /*  É  */  { "É â á â á É ä á ä Ü á â ä ä É â â á á â á â á â á" },
   /*  Ö  */  { "Ö à Ü à Ü ä Ö ä Ü Ü ä ä à ä Ö à à Ü Ü à Ü à Ü à Ü" },
   /*  Ñ  */  { "Ñ à á à á á ä Ñ ä ä á ä à ä Ñ à à á á à á à á à á" },
   /*  Ç  */  { "Ç â Ü â Ü ä Ü ä Ç Ü ä â ä ä Ç â â Ü Ü â Ü â Ü â Ü" },
   /*  Ü  */  { "Ü ä Ü ä Ü ä Ü ä Ü Ü ä ä ä ä Ü ä ä Ü Ü ä Ü ä Ü ä Ü" },
   /*  á  */  { "á ä á ä á á ä á ä ä á ä ä ä á ä ä á á ä á ä á ä á" },
   /*  â  */  { "â â ä â ä â ä ä â ä ä â ä ä â â â ä ä â ä â ä â ä" },
   /*  à  */  { "à à ä à ä ä à à ä ä ä ä à ä à à à ä ä à ä à ä à ä" },
   /*  ä  */  { "ä ä ä ä ä ä ä ä ä ä ä ä ä ä ä ä ä ä ä ä ä ä ä ä ä" },
   /*  ∑  */  { "∑ ≤ å Ä Å É Ö Ñ Ç Ü á â à ä ∑ ù ú û ü ç é - | = ®" },
   /*h ù  */  { "ù ù ä ù ä â à à â ä ä â à ä ù ù ù ä ä ç ä ù ä ù ä" },
   /*h ú  */  { "ú ú ä ú ä â à à â ä ä â à ä ú ú_ú ä ä ç ä ú ä ú ä" },
   /*v û  */  { "û ä û ä û á Ü á Ü Ü á ä ä ä û ä ä û û ä û ä û ä û" },
   /*v ü  */  { "ü ä ü ä ü á Ü á Ü Ü á ä ä ä ü ä ä ü ü ä ü ä ü ä ü" },
   /*h ç  */  { "ç ç ä ç ä â à à â ä ä â à ä ç é é ä ä ç ä ç ä ç ä" },
   /*v é  */  { "é ä é ä é á Ü á Ü Ü á ä ä ä é ä ä é é ä é ä é ä é" },
   /*h -  */  { "- - ä - ä â à à â ä ä â à ä - - - ä ä - ä - ä - ä" },
   /*v |  */  { "| ä | ä | á Ü á Ü Ü á ä ä ä | ä ä | | ä | ä | ä |" },
   /*h =  */  { "= = ä = ä â à à â ä ä â à ä = = = ä ä = ä = ä = ä" },
   /*v ®  */  { "® ä ® ä ® á Ü á Ü Ü á ä ä ä ® ä ä ® ® ä ® ä ® ä ®" },
};

/*
 *
 *    testing <¥¥¥¥¥¥¥Ç
 *                    Ñ¥¥¥¥¥¥¥> result
 *
 *
 *    testing < ¥ ¥ ¥ Ç
 *                    Ñ ¥ ¥ ¥ > result
 *
 *
 *    testing <≥≥≥≥≥≥≥Ç
 *                    Ñ≥≥≥≥≥≥≥> result
 *
 *
 *    testing < ≥ ≥ ≥ Ç
 *                    Ñ ≥ ≥ ≥ > result
 *
 *
 *    testing <œœœœœœœÇ
 *                    Ñœœœœœœœ>  result
 *
 *
 *    testing < œ œ œ Ç
 *                    Ñ œ œ œ >  result
 *
 */

/*====================------------------------------------====================*/
/*===----                       configuration                          ----===*/
/*====================------------------------------------====================*/
static void      o___CONFIG_____________o (void) {;}

char
yascii_draw_heaviness   (char a_heavy, char *r_left, char *r_topp, char *r_righ, char *r_bott)
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
   case YASCII_WAVY    :  x_left = 'é';  x_righ = 'é';  x_topp = 'ç';  x_bott = 'ç';  break;
   case YASCII_INSIDE  :  x_left = 'û';  x_righ = 'ü';  x_topp = 'ù';  x_bott = 'ú';  break;
   case YASCII_OUTSIDE :  x_left = 'ü';  x_righ = 'û';  x_topp = 'ú';  x_bott = 'ù';  break;
   case YASCII_ANCIENT :  x_left = '|';  x_righ = '|';  x_topp = '-';  x_bott = '-';  break;
   case YASCII_DOUBLE  :  x_left = '®';  x_righ = '®';  x_topp = '=';  x_bott = '=';  break;
   case YASCII_LIGHT   :  x_left = '∑';  x_righ = '∑';  x_topp = '∑';  x_bott = '∑';  break;
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

char
yascii_draw_joiner      (char a_old, char a_new, char *r_rc)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑*/
   char       *p           = NULL;
   char        x_valid     [LEN_HUND] = "";
   char        x_row       =   -1;
   char        x_col       =   -1;
   char        x_final     =   -1;
   char        n           =    0;
   /*---(enter)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YASCII   yLOG_char    ("a_old"     , a_old);
   --rce;  if ((unsigned) a_old < 32 || (unsigned) a_old == 127)  {
      if (r_rc    != NULL)  *r_rc    = rce;
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return '∞';
   }
   DEBUG_YASCII   yLOG_char    ("a_new"     , a_new);
   --rce;  if ((unsigned) a_new < 32 || (unsigned) a_new == 127) {
      if (r_rc    != NULL)  *r_rc    = rce;
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return '∞';
   }
   /*---(load options)-------------------*/
   strlcpy (x_valid, zASCII_join [0], LEN_HUND);
   DEBUG_YASCII   yLOG_info    ("x_valid"   , x_valid);
   /*---(find existing)------------------*/
   p = strchr (x_valid, a_old);
   DEBUG_YASCII   yLOG_point   ("p"         , p);
   if (p == NULL) {
      DEBUG_YASCII   yLOG_note    ("leave alone");
      if (r_rc    != NULL)  *r_rc    = 3;
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return a_old;
   }
   DEBUG_YASCII   yLOG_char    ("p [0]"     , p [0]);
   x_col = p - x_valid;
   DEBUG_YASCII   yLOG_value   ("x_col"     , x_col);
   /*---(get new)------------------------*/
   p = strchr (x_valid, a_new);
   DEBUG_YASCII   yLOG_point   ("p"         , p);
   if (p == NULL) {
      if (a_old == ' ') {
         DEBUG_YASCII   yLOG_note    ("update empty spot");
         if (r_rc    != NULL)  *r_rc    = 5;
         DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
         return a_new;
      }
      DEBUG_YASCII   yLOG_note    ("leave alone");
      if (r_rc    != NULL)  *r_rc    = 4;
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return a_old;
   }
   DEBUG_YASCII   yLOG_char    ("p [0]"     , p [0]);
   n = p - x_valid;
   DEBUG_YASCII   yLOG_value   ("n"         , n);
   x_row = n / 2.0;
   DEBUG_YASCII   yLOG_value   ("x_row"     , x_row);
   /*---(identify replacement)-----------*/
   strlcpy (x_valid, zASCII_join [x_row], LEN_HUND);
   DEBUG_YASCII   yLOG_info    ("x_valid"   , x_valid);
   x_final = x_valid [x_col];
   DEBUG_YASCII   yLOG_char    ("x_final"   , x_final);
   /*---(save-back)----------------------*/
   if (r_rc    != NULL)  *r_rc    = 2;
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return x_final;
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
   char        rc          =    0;
   int         x_off       =    0;
   char        x_new       =  '-';
   char        x_exist     =   -1;
   char        x_final     =   -1;
   /*---(enter)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(quick-out)----------------------*/
   DEBUG_YASCII   yLOG_value   ("x"         , x);
   DEBUG_YASCII   yLOG_value   ("x_max"     , myASCII.x_max);
   if (x < 0 || x >= myASCII.x_max) {
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   DEBUG_YASCII   yLOG_value   ("y"         , y);
   DEBUG_YASCII   yLOG_value   ("y_max"     , myASCII.y_max);
   if (y < 0 || y >= myASCII.y_max) {
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(defense)------------------------*/
   DEBUG_YASCII   yLOG_char    ("a_new"     , a_new);
   --rce;  if ((unsigned) a_new < 32 || (unsigned) a_new == 127) {
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_YASCII   yLOG_char    ("a_alt"     , a_alt);
   --rce;  if ((unsigned) a_alt < 32 || (unsigned) a_alt == 127) {
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_YASCII   yLOG_char    ("a_mode"    , a_mode);
   --rce;  if (a_mode != YASCII_CLEAR && a_mode != YASCII_MERGE) {
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   /*---(prepare offset)-----------------*/
   x_off = (y * myASCII.x_max) + x;
   DEBUG_YASCII   yLOG_value   ("x_off"     , x_off);
   /*---(choose character)---------------*/
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
   /*---(call joiiner)-------------------*/
   x_exist = yASCII_draw_get (x, y);
   DEBUG_YASCII   yLOG_char    ("x_exist"   , x_exist);
   x_final = yascii_draw_joiner (x_exist, x_new, &rc);
   DEBUG_YASCII   yLOG_char    ("joiner"    , rc);
   DEBUG_YASCII   yLOG_char    ("x_final"   , x_final);
   /*---(save-back)----------------------*/
   G_image [x_off] = x_final;
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return rc;
}

char yASCII_draw_exact  (short x, short y, char a_new)  { return yASCII_draw_full (0, x, y, a_new, a_new, YASCII_CLEAR); }
char yASCII_draw_merge  (short x, short y, char a_new)  { return yASCII_draw_full (0, x, y, a_new, a_new, YASCII_MERGE); }
char yASCII_draw_double (char c, short x, short y, char a_new, char a_alt)  { return yASCII_draw_full (c, x, y, a_new, a_alt, YASCII_MERGE); }



/*====================------------------------------------====================*/
/*===----                 printing character strings                   ----===*/
/*====================------------------------------------====================*/
static void      o___STRINGS____________o (void) {;}

char
yASCII_print            (int x, int y, char a_text [LEN_RECD])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         x_len       =    0;
   int         i           =    0;
   char        c           =  '-';
   int         n           =    0;
   char        x_fails     =    0;
   char        x_lines     =    1;
   short       x_curr      =    0;
   /*---(enter)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YASCII   yLOG_point   ("a_text"    , a_text);
   --rce;  if (a_text == NULL) {
      DEBUG_YASCII   yLOG_note    ("text is null");
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_info    ("a_text"    , a_text);
   /*---(filter)-------------------------*/
   DEBUG_YASCII   yLOG_value   ("x"         , x);
   DEBUG_YASCII   yLOG_value   ("y"         , y);
   if (y <  0) {
      DEBUG_YASCII   yLOG_note    ("y too low, nothing to display");
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   if (y >= myASCII.y_max) {
      DEBUG_YASCII   yLOG_note    ("y too high, nothing to display");
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   x_len = strlen (a_text);
   DEBUG_YASCII   yLOG_value   ("x_len"     , x_len);
   if (x_len <= 0) {
      DEBUG_YASCII   yLOG_note    ("text is empty, nothing to do");
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(place characters)---------------*/
   for (i = 0; i < x_len; ++i) {
      /*---(prepare)---------------------*/
      c  = a_text [i];
      ++x_curr;
      /*---(new lines)-------------------*/
      if (c == '|') {
         ++n;
         ++x_lines;
         ++y;
         x -= x_curr;
         x_curr = 0;
         continue;
      }
      /*---(display)---------------------*/
      rc = yASCII_draw_full (-1, x + i, y, c, c, YASCII_CLEAR);
      if (rc == 1) ++n;
      if (rc <  0) ++x_fails;
      /*---(done)------------------------*/
   }
   DEBUG_YASCII   yLOG_value   ("n"         , n);
   DEBUG_YASCII   yLOG_value   ("x_lines"   , x_lines);
   /*---(check for troubles)-------------*/
   DEBUG_YASCII   yLOG_value   ("x_fails"   , x_fails);
   --rce;  if (x_fails > 0) {
      DEBUG_YASCII   yLOG_note    ("some characters where illegal");
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(some not printed)---------------*/
   if (n == 0) {
      DEBUG_YASCII   yLOG_note    ("no text was visible");
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   if (n < x_len) {
      DEBUG_YASCII   yLOG_note    ("some text was out of bounds");
      DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
      return 1;
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 2;
}

char
yASCII_printw           (int x, int y, int a_wide, int a_tall, char a_text [LEN_RECD])
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
   strlcpy (x_str, a_text, LEN_RECD);
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
         /*> if (a_mode != YASCII_FILL) {                                             <* 
          *>    strlcpy  (x_str + x_head, x_out, LEN_RECD);                           <* 
          *> } else {                                                                 <* 
          *>    ystrlpad  (x_str + x_head, x_out, '.', '<', a_wide);                  <* 
          *>    ystrldchg (x_out, ' ', '∑', a_wide);                                  <* 
          *> }                                                                        <*/
         yASCII_print (x, y + x_lines, x_out);
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
      /*> if (a_mode != YASCII_FILL) {                                                <* 
       *>    strlcpy  (x_str + x_head, x_out, LEN_RECD);                              <* 
       *> } else {                                                                    <* 
       *>    ystrlpad  (x_str + x_head, x_out, '.', '<', a_wide);                     <* 
       *>    ystrldchg (x_out, ' ', '∑', a_wide);                                     <* 
       *> }                                                                           <*/
      yASCII_print (x, y + x_lines, x_out);
      x_lines ++;
   } else {
      DEBUG_YASCII  yLOG_note    ("nothing left at end to print");
   }
   for (i = x_lines; i < a_tall; ++i) {
      ystrlpad  ("", x_out, '.', '<', a_wide);
      yASCII_print (x, y + i, x_out);
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
   yASCII_print (bx, by, "œ"); 
   /*---(first segment)------------------*/
   switch (a_dir) {
   case '÷' :  for (i = bx + 1; i < ex; ++i)   yASCII_print ( i, by, x_horz);    break;
   case '◊' :  for (i = bx - 1; i > ex; --i)   yASCII_print ( i, by, x_horz);    break;
   case '’' :  for (i = by + 1; i < ey; ++i)   yASCII_print (bx,  i, x_vert);    break;
   case '‘' :  for (i = by - 1; i > ey; --i)   yASCII_print (bx,  i, x_vert);    break;
   }
   /*---(corner)-------------------------*/
   switch (a_dir) { case '÷' :  if (x_dir == 3)  yASCII_print (ex, by, "Ö");  else if (x_dir == 9)  yASCII_print (ex, by, "Ç");  break;
   case '◊' :  if (x_dir == 1)  yASCII_print (ex, by, "Ñ");  else if (x_dir == 7)  yASCII_print (ex, by, "É");  break;
   case '’' :  if (x_dir == 7)  yASCII_print (bx, ey, "Ö");  else if (x_dir == 9)  yASCII_print (bx, ey, "Ñ");  break;
   case '‘' :  if (x_dir == 1)  yASCII_print (bx, ey, "Ç");  else if (x_dir == 3)  yASCII_print (bx, ey, "É");  break;
   }
   /*---(second segment)-----------------*/
   switch (x_2nd) {
   case '÷' :  for (i = bx + 1; i < ex; ++i)   yASCII_print ( i, ey, x_horz);    break;
   case '◊' :  for (i = bx - 1; i > ex; --i)   yASCII_print ( i, ey, x_horz);    break;
   case '’' :  for (i = by + 1; i < ey; ++i)   yASCII_print (ex,  i, x_vert);    break;
   case '‘' :  for (i = by - 1; i > ey; --i)   yASCII_print (ex,  i, x_vert);    break;
   }
   /*---(termination)--------------------*/
   sprintf (t, "%c", x_end);
   yASCII_print (ex, ey, t); 
   /*---(label)--------------------------*/
   if (a_label != NULL)  yASCII_print (lx, ly, a_label);
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char yASCII_uconnect  (short bx, short by, char a_dir, short ex, short ey) { return yASCII_connector (bx, by, a_dir, ex, ey, '≤', NULL, 0, 0); }

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
   strlcpy  (unit_answer, "DRAW             : question not understood", LEN_RECD);
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
