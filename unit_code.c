/*===========================[[ start-of-code ]]==============================*/
#include    "yASCII.h"
#include    "yASCII_priv.h"
#include    "unit_code.h"



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
