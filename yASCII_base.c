/*===[[ START ]]==============================================================*/
#include    "yASCII.h"
#include    "yASCII_priv.h"


tASCII   myASCII;

char  (*e_displayer)  (int x, int y, char *a_text, char a_mode) = NULL;
char  g_working  [MAX_HEIGHT][LEN_DESC];

char   unit_answer [LEN_RECD];


char yASCII_displayer   (void *a_displayer) { e_displayer = a_displayer; return 0; }

char         /*-> display a single line to screen --------[ whorl  [ 4----3 ]-*/
yascii_oneline          (char *a_text, int x, int y, char a_mode)
{
   if (e_displayer != NULL)  e_displayer (x, y, a_text, a_mode);
}

char
yascii__unit_quiet      (void)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         x_argc      =    1;
   char       *x_argv [1]  = { "yASCII" };
   /*---(header)-------------------------*/
   DEBUG_YASCII  yLOG_enter   (__FUNCTION__);
   /*---(set mute)-----------------------*/
   yURG_all_mute ();
   /*---(start logger)-------------------*/
   rc = yURG_logger  (x_argc, x_argv);
   DEBUG_YASCII   yLOG_value    ("logger"    , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr    (__FUNCTION__, rce);
      return rce;
   }
   /*---(process urgents)----------------*/
   rc = yURG_urgs    (x_argc, x_argv);
   DEBUG_YASCII   yLOG_value    ("logger"    , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr    (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII  yLOG_exit  (__FUNCTION__);
   return 0;
}

char         /*-> set up programgents/debugging ------[ light  [uz.320.011.05]*/ /*-[00.0000.00#.!]-*/ /*-[--.---.---.--]-*/
yascii__unit_loud      (void)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         x_argc      =    3;
   char       *x_argv [3]  = { "yASCII_unit" , "@@kitchen", "@@yascii"};
   /*---(header)-------------------------*/
   DEBUG_YASCII  yLOG_enter   (__FUNCTION__);
   /*---(set mute)-----------------------*/
   yURG_all_mute ();
   /*---(start logger)-------------------*/
   rc = yURG_logger  (x_argc, x_argv);
   DEBUG_YASCII   yLOG_value    ("logger"    , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr    (__FUNCTION__, rce);
      return rce;
   }
   /*---(process urgents)----------------*/
   rc = yURG_urgs    (x_argc, x_argv);
   DEBUG_YASCII   yLOG_value    ("urgs"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr    (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII  yLOG_exit  (__FUNCTION__);
   return 0;
}

char         /*-> set up program urgents/debugging ---[ light  [uz.210.001.01]*/ /*-[00.0000.00#.!]-*/ /*-[--.---.---.--]-*/
yascii__unit_end       (void)
{
   /*---(header)-------------------------*/
   DEBUG_YASCII  yLOG_enter   (__FUNCTION__);
   /*---(complete)-----------------------*/
   DEBUG_YASCII  yLOG_exit  (__FUNCTION__);
   DEBUG_YASCII  yLOGS_end     ();
   return 0;
}
