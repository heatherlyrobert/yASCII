/*===[[ START ]]==============================================================*/
#include    "yASCII.h"
#include    "yASCII_priv.h"

/*
 *    I KNOW I AM WASTING SPACE !!!
 *
 *    right now, the artistic look and ability to edit in this file is
 *    a premium for me.  eventually, i will adopt a much more compressed
 *    format for memory savings.  all in good time.
 *
 */

/*
 *    <sp>   means small gap
 *    '      just a word seperator, like <sp>
 *    Œ      means large gap " · "
 *    ÕÔÖ×   glyph orientation signal (prefix)
 *    ¦      new line
 *    ´      period
 *           empty glyph
 *
 */



/* 0llllllllllllllllllllllllllllllllllllllllhxxllllllllllllllllllllllllllllllllllllllllxxllllllllllllllllllllxxllllllllllllllllllllxxllllllllllxxllllllllllxxlllllllllllllllllllli "lD0i"€ýaj  */
/*  ,x··0···40|·2x···80|·2x···100|·2x···120|·2x···130|·2x···140|·2x···A  ¥··160|·d$··A ",¥··0·I   "¥··j··,y  */


static char s_tall        =   6;
static char s_wide        =   9;
static char s_left        =   0;
static char s_topp        =   0;

static char s_start       = '·';

static char s_conjunct    = '·';
static char s_conjtxt     [LEN_SHORT] = "";

static char s_possess     = '·';
static char s_posstxt     [LEN_SHORT] = "";


static short  s_nchar      =    0;
static short  s_nglyph     =    0;
static char   s_request     [LEN_RECD]  = "";
static char   s_words       [LEN_RECD]  = "";
static char   s_diagram     [LEN_RECD]  = "";
static char   s_root        [LEN_RECD]  = "";
static char   s_meaning     [LEN_RECD]  = "";
static char   s_orient      [LEN_RECD]  = "";
static char   s_variant     [LEN_RECD]  = "";

static char   s_formal      [LEN_RECD]  = "";
static char   s_pretty      [LEN_RECD]  = "";
static char   s_glyphish    [LEN_RECD]  = "";

/*  ,x··0···45|·v·9l·y··205|·P··0·j··,y */
/*  ,x··0··220|·v·5l·y··226|·P··0·j··,y */
/*  ,x··0··213|·v·6l·y··220|·P··2h·x··0·j··,y */

/*  ,x··0··220|·v·6l·d··0·j··,y  */


static const char mayanc       [LEN_HUND][400] = {
   /* ---------------------fulls----------- ----------------lefts------------------ -----------------rights---------------- -------tops-------- ------bottoms------ -------verts------- -------horzs------- -----------corners----------- --med-- -thin- thinr -sml- tiny mi */
   "ƒ€ƒ€‰ ‰€‚ ƒ€‰ ‰€‚€‚ ƒ€‰‰‰€’“‚ ƒ’“€‰‰‰€‚ ƒ€‚²ƒ‰²²‚ ƒ‰€‚²ƒ²²‚ ƒ€‚²ƒ‰²²‚ ƒ²²²²‰²²‚ ƒ²²‰€‚²ƒ‚ ƒ²²‰‰€‚²• ƒ²²‰€‚²ƒ‚ ƒ²²‰²²²²‚ ƒ‰€‰‰€–—‚ ƒ’“€‰‰€‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ€‰²‰²²²‚ ƒ²‰€‰²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²‰€‰‚²ƒ‚ ƒ²²²²²‚á   áƒ²²²²²‚ ƒ€‚²ƒ²‚ ƒ€‚ƒ²‚ ƒ€‚ƒ‚ ƒ€‚ƒ‚ ƒ€‚‚ ‰· ",
   " † ž Ÿ   ž Ÿ ‡  ƒ€ˆ€ˆ€€ˆ† ‡ˆ€€ˆ€ˆ€‚  ž Ÿ  Œ ‡ ž Ÿ  Œ  ž Ÿ  Œ ‡€‚²ƒ†  Œ Œ   ž Ÿ Œ  ‡ ž Ÿ Œ   ž Ÿ Œ  ‡€‚²ƒ† ‡ €†„€€€† ‡€€€…‡€ † Œ       Œ Œ       Œ  ž Ÿ   Œ ‡€ƒ †   Œ Œ       Œ Œ       Œ Œ  ž Ÿ Œ     Š²‚ ƒ²Š     Œ  ž Ÿ Œ  žŸ Œ  žŸŒ  žŸŒ ƒ‰žŒ    ",
   "ƒ‰† ž Ÿ   ž Ÿ ‡‰‚ „‚ † ‡ ƒ… ƒ‰ž Ÿ  Œ ‡ƒ‰ž Ÿ  Œ ƒ‰ž Ÿ  Œ  ž Ÿ  Œ Œ  ƒ‰ž Ÿ Œ  ‡ƒ‰ž Ÿ Œ  ƒ‰ž Ÿ Œ   ž Ÿ ‡ƒ… „‚† ‡‰€‰‰€–—† ‡’“€‰‰€‰†  ž Ÿ   Œ ‡ˆž Ÿ   Œ Œ       Œ Œ       Œ Œ ƒ‰ ž Ÿ ‡€‰‚²ƒ† Œ Œ ‡€‰‚²ƒ† ƒ‰ž Ÿ Œ ƒ‰žŸ Œ ƒ‰žŸŒ ƒ‰žŸŒ „€ˆ…    ",
   "‡€† ž Ÿ   ž Ÿ ‡€† ƒœœœœœ… † ‡ „œœœœœ‚ ‡€ž Ÿ  Œ ‡‡€Š€†  Œ ‡€„€…  Œ ƒ‰ž Ÿ  Œ Œ  ‡€ž Ÿ Œ  ‡‡€Š€† Œ  ‡€„€… Œ  ƒ‰ž Ÿ ‡ˆœœœœœœ‚ ƒœœœœœœˆ† ‡ €†„€€€† ‡€€€…‡€ † ƒ‰ž Ÿ   Œ  ž Ÿ   Œ ‡’“ŠŠ‰€‰† ‡‰€ŠŠ€–—† Œ ‡€„„€…  ž Ÿ Œ Œ  ž Ÿ ‡€ž Ÿ Œ ‡€žŸ Œ ‡€žŸŒ „€ˆˆ…         ",
   "  „€…   „€…   ‡€€€€€€€† ‡€€€€€€€†  „€…  Œ ‡‡   †  Œ ‡€…„€†  Œ ‡€„€…  Œ Œ   „€… Œ  ‡‡   † Œ  ‡€…„€† Œ  ‡€„€… Œ       Œ Œ       Œ ‡ƒ… „‚† ‡€„€†   Œ Ž ž Ÿ   Œ „‚† ‡ƒ… „²Š     Œ ƒ‰ ž Ÿ Œ Œ ƒ‰ ž Ÿ „€ˆ€ˆ²… „€ˆˆ²… „€ˆˆ…               ",
   "„€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€€€€€€€… „€€€€€€€… „€ˆ€ˆˆ²²… „ˆ²ˆ²ˆ²²… „€€€€ˆ²²… „€…„€ˆ²²… „²²ˆ€ˆ€ˆ… „²²ˆˆ²ˆ²… „²²ˆ€€€€… „²²ˆ€…„€… „²²²²²²²… „²²²²²²²… „ˆœœœœœœ ‘œœœœœœˆ… „€ˆ€ˆ²²²… „€ˆ²ˆ²²²… „œœœœœœˆ… „ˆœœœœœœ…  á„²²²²²… „€„„€ˆˆ²… „²ˆ€„„€ˆ…                                    ",
   "ƒ‰€€€€€€‚ ƒ€€€€€€‰‚ ƒ‰€€‰€‰€‚ ƒ€‰€‰€€‰‚ ƒ‰€€€‰²²‚ ƒ‰€€€‰²²‚ ƒ²²²²‰²²‚ ƒ²²²²‰²²‚ ƒ²²‰‰€€€‚ ƒ²²‰‰€€€‚ ƒ²²‰²²²²‚ ƒ²²‰²²²²‚ ƒ‰‰€€€€‰‚ ƒ‰‰€€€€‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ‰€€‰²²²‚ ƒ‰€‰²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²‰‰‰€€€‚ ƒ²²²²²‚á    ƒ²²²²²‚ ƒ‰€€€²‚ ƒ€€€²‚ ƒ€€€‚ ƒ€€€‚ ƒ€€‚ ‡· ",
   "‡…ƒŠ€‚ † ‡ ƒ€Š‚„† ‡…€ˆ…  † ‡  „ˆ€„† ‡…ƒŠ  Œ ƒ†Š…  Œ ‡‰€€€†  Œ ‡‰€€€†  Œ Œ  ‡…ƒŠ Œ  ƒ†Š… Œ  ‡‰€€€† Œ  ‡‰€€€† ‡…ƒŠ  ƒ†ƒŠ… Œ       Œ Œ       Œ ‡…ƒŠ   Œ ‡…Œ    Œ Œ       Œ Œ       Œ Œ ‡…ƒŠ Œ     Š²‚ ƒ²Š     Œ ‡…ƒŠ Œ ‡ƒŠ Œ ‡ƒŠŒ ‡ ƒ†Œ ƒ†Œ    ",
   "ƒ†Š… ‡€† ‡€† „Š‡‚  ƒŠ ‡€† ‡€† Š‚  ƒ†Š…  Œ ‡€… €†  Œ ‡…ƒŠ  Œ ƒ†Š…  Œ Œ  ƒ†Š… Œ  ‡€… €† Œ  ‡…ƒŠ Œ  ƒ†Š… ƒ†Š…  ‡€…Š…€‚ ‡‰‰€€€€‰† ‡‰‰€€€€‰† ƒ†Š…   Œ ƒ†Œ    Œ Œ       Œ Œ       Œ Œ ƒ†Š… ‡‰‰€€€† Œ Œ ‡‰‰€€€† ƒ†ŠŠ Œ ƒ†ŠŠ Œ ƒ†ŠŠŒ ƒ†Š†Œ „…€…    ",
   "‡€… €‚     ƒ€ „€†  Š…„€…   „€…„Š  ‡€… €†  Œ ‡€€€‰†  Œ ƒ†Š…  Œ ‡€… €†  Œ Œ  ‡€… €† Œ  ‡€€€‰† Œ  ƒ†Š… Œ  ‡€… €† ‡ˆ€ˆ€€€ˆ† ‡ˆ€€€€€ˆ† ‡…ƒŠ  ƒ†ƒŠ… ‡€… …   Œ ‡€…Œ    Œ ‡‰‰ˆˆ€€‰† ‡‰‰ˆˆ€€‰† Œ ‡ˆ€ˆ€€† ‡…ƒŠŒ Œ Œ ‡…ƒŠŒ ‡€… € Œ ‡€…  Œ ‡€… Œ „€ˆˆ…         ",
   "‡€€€‰…  † ‡  „‰€€€†  „‰€       €‰…  ‡€€€‰†  Œ ‡€ˆ€ˆ†  Œ ‡€… €†  Œ ‡€€€‰†  Œ Œ  ‡€€€‰† Œ  ‡€ˆ€ˆ† Œ  ‡€… €† Œ  ‡€€€‰† Œ       Œ Œ       Œ ƒ†Š…  ‡€…Š…€‚ ‡€€€‚   Œ ‡€€Œ    Œ ‡…ƒŠ  ƒ†ƒŠ… „²Š     Œ ƒ†Š…Œ Œ Œ ƒ†Š…Œ „€ˆ€ˆ²… „€ˆˆ²… „€ˆˆ…               ",
   "„€ˆ€ˆ€€€… „€€€ˆ€ˆ€… „€€ˆ€€ˆ€… „€ˆ€€ˆ€€… „€ˆ€ˆˆ²²… „““““ˆ²²… „€€€€ˆ²²… „€ˆ€ˆˆ²²… „²²ˆ€ˆ€ˆ… „²²ˆ““““… „²²ˆ€€€€… „²²ˆ€ˆ€ˆ… „²²²²²²²… „²²²²²²²… „ˆ€ˆ€€€ˆ… „ˆ€€€€€ˆ… „€ˆ€ˆ²²²… „€ˆˆ²²²²… „ˆˆ…Š… … „ˆ€…Š…€‚…  á„²²²²²… „ˆ€ˆ€€ˆ²… „²ˆˆ€ˆ€€…                                    ",
   "ƒƒ€‰€‰€‚‚ ƒƒ€‰€‰€‚‚ ƒƒ€‰€‰€‚‚ ƒ€‰€‰€‰€‚ ƒ€‰‰€‰²²‚ ƒ€‰‰€‰²²‚ ƒ€‰‰€‰²²‚ ƒ’’——‰²²‚ ƒ²²‰€‰‰€‚ ƒ²²‰€‰‰€‚ ƒ²²‰€‰‰€‚ ƒ²²‰’’——‚ ƒƒ€‰€‰€‚‚ ƒ‰€‰€‰€‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ€‰€‰²²²‚ ƒ’’—‰²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²‰ƒ€€€‚‚ ƒ²²²²²‚á   áƒ²²²²²‚ ƒ€‰€‰²‚ ƒ€‰‰²‚ ƒ€‰‰‚ ƒ€‰‰‚ ƒ€‰‚ ˆ· ",
   "ƒˆ Žˆ‚ ƒ ŽŽ‚ ƒ ŽŽŽ‚ ‡ŽŽŽ † ˆŽˆ  Œ ˆŽˆ  Œ ˆŽˆ  Œ ‡€‰‰€Š  Œ Œ  ˆŽˆ Œ  ˆŽˆ Œ  ˆŽˆ Œ  ‡€‰‰€Š ƒˆ Žˆ‚ ‡€ Ž€† Œ       Œ Œ       Œ ˆŽˆ   Œ ‡€‰‰Š   Œ Œ       Œ Œ       Œ Œ ƒˆ Žˆ‚ Œ     Š²‚ ƒ²Š     Œ ˆŽˆ Œ ˆŽ Œ ˆŽŒ ˆŽŒ ˆŒ    ",
   "‡ˆ€ Ž€ˆ† ‡€ Ž€Ž† ‡ˆ€ Ž€ˆ† ‡ˆ€ Ž€ˆ† ˆ€Ž€ˆ  Œ ˆŽˆ  Œ ‰€Ž€‰  Œ ˆŽˆ  Œ Œ  ˆ€Ž€ˆ Œ  ˆŽˆ Œ  ‰€Ž€‰ Œ  ˆŽˆ ‡ˆ€ Ž€ˆ† ‡€€ Ž€€† ‡ƒ€‰€‰€‚† ‡‰€‰€‰€‰† ˆ€€ˆ   Œ ˆˆ   Œ Œ       Œ Œ       Œ Œ ‡ˆ€ €ˆ† ‡ƒ€ˆ€‚† Œ Œ ‡ƒ€ˆ€‚† ˆ€€ˆ Œ ˆ€€ Œ ˆ€€Œ ‰ŽŒ „€ˆ…    ",
   "‡‰€Ž €‰† ‡Ž€Ž €† ‡‰€Ž €‰† ‡‰€Ž €‰† ‰€Ž€‰  Œ ‰€Ž€‰  Œ ‰Ž‰  Œ ˆ€Ž€ˆ  Œ Œ  ‰€Ž€‰ Œ  ‰€Ž€‰ Œ  ‰Ž‰ Œ  ˆ€Ž€ˆ ‡‰€Ž €‰† ‡€€Ž €€† ƒˆ Žˆ‚ ‡€ Ž€† ‰€Ž€‰   Œ ˆ€Žˆ   Œ ‡ƒ€Šˆ‰€‚† ‡‰€Šˆ‰€‰† Œ ˆ€€Ž€† ƒˆ Žˆ‚ Œ Œ ƒˆ Žˆ‚ ‰Ž‰ Œ ‰Ž Œ ‰ŽŒ „€ˆˆ…         ",
   "„‰Ž ‰… „ŽŽ … „ŽŽŽ …  ŽŽŽ† ‰Ž‰  Œ ‰Ž‰  Œ ‡€…„€†  Œ ‰€Ž€‰  Œ Œ  ‰Ž‰ Œ  ‰Ž‰ Œ  ‡€…„€† Œ  ‰€Ž€‰ Œ       Œ Œ       Œ ‡ˆ€ Ž€ˆ† ‡€€ Ž€€† ‰Ž‰   Œ ‰€Ž‰   Œ ƒˆ Žˆ‚ ‡€ Ž€† „²Š     Œ ‡ˆ€ €ˆ† Œ Œ ‡ˆ€ €ˆ† „€ˆ€ˆ²… „€ˆˆ²… „€ˆˆ…               ",
   "„„€ˆ€ˆ€…… „„€ˆ€ˆ€…… „„€ˆ€ˆ€…… „€ˆ€ˆ€ˆ€… „€ˆˆ€ˆ²²… „€ˆˆ€ˆ²²… „€…„€ˆ²²… „€ˆˆ€ˆ²²… „²²ˆ€ˆˆ€… „²²ˆ€ˆˆ€… „²²ˆ€…„€… „²²ˆ€ˆˆ€… „²²²²²²²… „²²²²²²²… „‰€Ž €‰… „€€Ž €€… „€ˆ€ˆ²²²… „€ˆˆˆ²²²… „ˆ€ Ž€ˆ… „€€ Ž€€…  á„²²²²²… „€€Ž€ˆ²… „²ˆ€€Ž€…                                    ",
   /* ---------------------fulls----------- ----------------lefts------------------ -----------------rights---------------- -------tops-------- ------bottoms------ -------verts------- -------horzs------- ------corners------ --med-- -thin- thinr -sml- tiny mi */
   "ƒ€‰€‰€‰€‚ ƒ‰€€‰€€‰‚ ƒ€€€€€€€‚ ƒ€€€€€€€‚ ƒ‰€€‰‰²²‚ ƒ€€€€‰²²‚ ƒ‰€€‰‰²²‚ ƒ²²²²‰²²‚ ƒ²²‰‰€€‰‚ ƒ²²‰€€€€‚ ƒ²²‰‰€€‰‚ ƒ²²‰²²²²‚ ƒ‰‰€€€‰‰‚ ƒ‰‰‰€‰‰‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ‰€€‰²²²‚ ƒ²²²‰²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²‰‰€€€‰‚ ƒ²²²²²‚á   áƒ²²²²²‚ ƒ‰€€‰²‚ ƒ€€‰²‚ ƒ€€‰‚ ƒ€€‰‚ ƒ€€‚ ƒ· ",
   " ‡…„†  ‡…  „† ‡€‰€‰€‰€† ‡€‰€‰€‰€† ‡…„†  Œ ‡‰€€‰†  Œ ‡…„†  Œ ‡‰€€‰†  Œ Œ  ‡…„† Œ  ‡‰€€‰† Œ  ‡…„† Œ  ‡‰€€‰† ‡… „† ‡‚ ƒ† Œ       Œ Œ       Œ ‡…„†   Œ ‡‰€€†   Œ Œ       Œ Œ       Œ Œ ‡… „† Œ     Š²‚ ƒ²Š     Œ ‡…„† Œ ‡…„† Œ ‡…„†Œ ‡…„†Œ ‡…„Œ    ",
   " ‡…„†  ‡…  „†  … … …   ‡…„†  ‡…„†  Œ ‡…„†  Œ ‡…„†  Œ ‡…„†  Œ Œ  ‡…„† Œ  ‡…„† Œ  ‡…„† Œ  ‡…„† ‡… „† ‡‚ ƒ† ‡‰‰…€„‰‰† ‡‰Š‚€ƒŠ‰† ‡…„†   Œ ‡…„   Œ Œ       Œ Œ       Œ Œ ‡… „† ‡Š…€„Š† Œ Œ ‡‰…€„‰† ‡…„† Œ ‡…„† Œ ‡…„†Œ ‡…„†Œ „ˆˆ…    ",
   " ‡…„†  ‡…  „†  ‚ ‚ ‚   ‡…„†  ‡…„†  Œ ‡…„†  Œ ‡…„†  Œ ‡…„†  Œ Œ  ‡…„† Œ  ‡…„† Œ  ‡…„† Œ  ‡…„† ‡ˆˆ‚€ƒˆˆ† ‡ˆˆ‚€ƒˆˆ† ‡… „† ‡‚ ƒ† ‡…„†   Œ ‡…„   Œ ‡‰Š…€„Š‰† ‡‰‰Šˆ‰‰‰† Œ ‡Š…€„Š† ‡… „† Œ Œ ‡… „† ‡…„† Œ ‡…„† Œ ‡…„†Œ „ˆˆˆ…         ",
   " ‡…„†  ‡…  „† ‡€ˆ€ˆ€ˆ€† ‡€ˆ€ˆ€ˆ€† ‡…„†  Œ ‡ˆ€€ˆ†  Œ ‡ˆ€€ˆ†  Œ ‡…„†  Œ Œ  ‡…„† Œ  ‡ˆ€€ˆ† Œ  ‡ˆ€€ˆ† Œ  ‡…„† Œ       Œ Œ       Œ ‡… „† ‡‚ ƒ† ‡…„†   Œ ‡…„   Œ ‡… „† ‡‚ ƒ† „²Š     Œ ‡… „† Œ Œ ‡… „† „ˆˆˆˆ²… „ˆˆˆ²… „ˆˆˆ…               ",
   "„€ˆ€ˆ€ˆ€… „ˆ€€ˆ€€ˆ… „€€€€€€€… „€€€€€€€… „ˆ€€ˆˆ²²… „€€€€ˆ²²… „–“–“ˆ²²… „ˆ€€ˆˆ²²… „²²ˆˆ€€ˆ… „²²ˆ€€€€… „²²ˆ–“–“… „²²ˆˆ€€ˆ… „²²²²²²²… „²²²²²²²… „ˆˆˆ€ˆˆˆ… „ˆˆ€€€ˆˆ… „ˆ€€ˆ²²²… „ˆ€€ˆ²²²… „ˆˆ… „ˆˆ… „ˆˆ‚ ƒˆˆ…  á„²²²²²… „ˆˆ€ˆˆˆ²… „²ˆˆˆ€ˆˆ…                                    ",
   "ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€€€€€€€‚ ƒ€€€€€€€‚ ƒ€€€€€²²‚ ƒ€€€€€²²‚ ƒ€€€€€²²‚ ƒ€€€€€²²‚ ƒ²²€€€€€‚ ƒ²²€€€€€‚ ƒ²²€€€€€‚ ƒ²²€€€€€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ€€€€²²²‚ ƒ²²²€€€€‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²‰€‰€‰€‚ ƒ²²²²²‚á   áƒ²²²²²‚ ƒ€€€€²‚ ƒ€€€²‚ ƒ€€€‚ ƒ€€€‚ ƒ€€‚ „· ",
   "‡€…       „€† ‡€€€€€€€† ‡€€€€€€€† ‡€€€€€  Œ ‡€€€€€  Œ ‡€€€€€  Œ ‡€€€€€  Œ Œ  €€€€€† Œ  €€€€€† Œ  €€€€€† Œ  €€€€€† ‡€…       „€† Œ       Œ Œ       Œ ‡€€€€   Œ Œ   €€€€† Œ       Œ Œ       Œ Œ ‡€…   Œ     Š²‚ ƒ²Š     Œ ‡€€€€ Œ ‡€€€ Œ ‡€€€Œ ‡€€€Œ ƒ€Œ    ",
   "‡€€€…     „€€€† ‡€€€€€‚   ƒ€€€€€†  ƒ€€€  Œ  ƒ€€€  Œ  ƒ€€€  Œ  ƒ€€€  Œ Œ  €€€‚  Œ  €€€‚  Œ  €€€‚  Œ  €€€‚  ‡€€€…     „€€€† ‡€€€€€‚   ƒ€€€€€†  ƒ€€   Œ Œ   €€‚  Œ       Œ Œ       Œ Œ ‡€€€…  ‡€€€€€‚ Œ Œ ‡€€€€€†  ƒ€€ Œ  ƒ€ Œ  ƒ€Œ  ƒ€Œ „ˆˆ…    ",
   "‡€€€€€…   „€€€€€† ‡€€€‚     ƒ€€€†   ƒ€  Œ   ƒ€  Œ   ƒ€  Œ   ƒ€  Œ Œ  €‚   Œ  €‚   Œ  €‚   Œ  €‚   ‡€€€€€…   „€€€€€† ‡€€€‚     ƒ€€€†   ƒ   Œ Œ   ‚   ‡€€€‚     ƒ€€€† Œ ‡€€€€€† ‡€€€‚  Œ Œ ‡€€€‚    ƒ Œ    Œ   Œ „€ˆ€…         ",
   "‡€€€€€€€† ‡€€€€€€€† ‡€‚       ƒ€†      Œ      Œ      Œ      Œ Œ      Œ      Œ      Œ      Œ       Œ Œ       Œ ‡€‚       ƒ€†      Œ Œ      ‡€‚       ƒ€† „²Š     Œ ‡€‚   Œ Œ ‡€‚   „€ˆ€ˆ²… „€ˆ€²… „€ˆ€…               ",
   "„€€€€€€€… „€€€€€€€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€²²… „€ˆ€ˆ€²²… „€ˆ€ˆ€²²… „€ˆ€ˆ€²²… „²²€ˆ€ˆ€… „²²€ˆ€ˆ€… „²²€ˆ€ˆ€… „²²€ˆ€ˆ€… „²²²²²²²… „²²²²²²²… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€²²… „²²€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€…  á„²²²²²² „€ˆ€ˆ€ˆ²… „²ˆ€ˆ€ˆ€…                                    ",
   "ŽŽŽŽ‚ ƒœœœ‰œ‰ŽŽ ƒŽŽŽŽ ‰œ‰œœœ‚ ŽŽŽ²²‚ ŽŽŽ²²‚ ƒ““––‰²²‚ ƒ  ƒ€‰²²‚ ƒ²²ŽŽŽ ƒ²²ŽŽŽ ƒ²²‰““––‚ ƒ²²‰  ƒ€‚ ƒœœœ‰œ‰ŽŽ ‰œ‰œœœ‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ŽŽ²²²‚ ƒ  ƒ‰²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²‰‰œ‰œœ‚ ƒ²²²²²‚á   áƒ²²²²²‚ ŽŽ²‚ Ž²‚ Ž‚ Ž‚ Ž‚ Œ· ",
   "‡€ƒ€€† Ž  „€† Ž ‡€€‚  €†  ‡€…   ‡  ƒ€†  Œ ‡€‚  †  Œ ‡  ƒ€†  Œ Ÿƒ‚‡„†  Œ Œ  ‡  ƒ€† Œ  ‡€‚  † Œ  ‡  ƒ€† Œ  Ÿƒ‚‡„† Ž  „€† Ž  ‡€…   Œ       Œ Œ       Œ ‡  ƒ†   Œ Ÿƒ‚‡†   Œ Œ       Œ Œ       Œ Œ ‡€…  Œ     Š²‚ ƒ²Š     Œ ‡ƒ‚ƒ  Œ ‡ƒ‚Š Œ ‡ƒ‚ŠŒ ‡ƒ‚ŠŒ ‡‚Œ    ",
   "Ÿƒ‚ ‡…„† Œ   ŽŽŽŽŽ ‡…„† ƒ‚ž     Ÿƒ‚‡„†  Œ ‡…†ƒ‚ž  Œ Ÿƒ‚‡„†  Œ Ÿ„…‡„†  Œ Œ  Ÿƒ‚‡„† Œ  ‡…†ƒ‚ž Œ  Ÿƒ‚‡„† Œ  Ÿ„…‡„† ‡€‰€‰€  Ž Ž€‰€‰€† ‡œœœ‰€‰ŽŽ ‰€‰œœœ† Ÿƒ‚‡†   Œ Ÿ„…‡†   Œ Œ       Œ Œ       Œ Œ Ž€‰€‰€† ‰œ‰œœ† Œ Œ ‰œ‰œœ† Ÿ„…ƒ… Œ Ÿ„…Š Œ Ÿ„…ŠŒ Ÿ„…ŠŒ „ˆˆ…    ",
   "Ÿ„… ‡…„† ‡€‰€‰€ ‡…„† „…ž ŽŽƒ€‰€‰€† Ÿ„…‡„†  Œ ‡…†„…ž  Œ Ÿ„…‡„†  Œ Ÿ ‡„†  Œ Œ  Ÿ„…‡„† Œ  ‡…†„…ž Œ  Ÿ„…‡„† Œ  Ÿ ‡„† ‡€Š€Š€ˆ ŽŽ €Š€Š€† Ž  „€† Ž  ‡€…   Ÿ„…‡†   Œ Ÿ ‡†   Œ ‡œœœŠœ‰ŽŽ ‰œŠœœœ† Œ Ž€…€…€† ‡€…  Œ Œ ‡€…  Ÿ ‡… Œ Ÿ Š Œ Ÿ ŠŒ „€……         ",
   "Ÿ  ‡…„† „ „ „  Œ ‡…„†Ž  ž Ž  … … … Ÿ ‡„†  Œ ‡…†Ž ž  Œ Ÿ ‡„†  Œ ‡€€…„†  Œ Œ  Ÿ ‡„† Œ  ‡…†Ž ž Œ  Ÿ ‡„† Œ  ‡€€…„† Œ       Œ Œ       Œ ‡€‰€‰€  Ž Ž€‰€‰€† Ÿ ‡†   Œ ‡€€…†   Œ Ž  „€† Ž  ‡€…   „²Š     Œ Ž€‰€‰€† Œ Œ Ž€‰€‰€† „€€ˆ…²… „€€…²… „€€……               ",
   "„€€€ˆ…„ˆ… „€ˆ€ˆ€ˆ „ˆ…„…²²²… ŽŽˆ€ˆ€ˆ€… „€€…„ˆ²²… „…„€€ˆ²²… „€€…„ˆ²²… „——’’ˆ²²… „²²ˆ€€…„ˆ „²²„…„€€… „²²ˆ€€…„… „²²ˆ——’’… „²²²²²²²… „²²²²²²²… „€Š€Š€ˆ ŽŽ €Š€Š€… „€€…ˆ²²²… „——’ˆ²²²… ‡€‰€‰€  Ž Ž€‰€‰€…  á„²²²²²… Ž€…€…€ˆ²… „²Ž€…€…€…                                    ",
   /* ---------------------fulls----------- ----------------lefts------------------ -----------------rights---------------- -------tops-------- ------bottoms------ -------verts------- -------horzs------- ------corners------ --med-- -thin- thinr -sml- tiny mi */
   "ƒ‰€€€€€‰‚ ƒ‰€€€€€‰‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ‰€€€‰²²‚ ƒ€‰‰‰‰²²‚ ƒ‰€€€‰²²‚ ƒ²²²²‰²²‚ ƒ²²‰‰€€€‚ ƒ²²‰€‰‰‰‚ ƒ²²‰‰€€€‚ ƒ²²‰²²²²‚ ƒ‰€‰€€€‰‚ ƒ‰€€€‰€‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ€€€‰²²²‚ ƒ²²²‰²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²‰€‰€€€‚ ƒ²²²²²‚á   áƒ²²²²²‚ ƒ‰€€‰²‚ ƒ‰€€²‚ ƒ‰€€‚ ƒ‰€€‚ ƒ‰‰‚ …· ",
   "‡ ƒ‰‰‚ †Ÿ ž‡ ƒ‰‰‚ † ‡ˆ€ˆ€ˆ€Š† ‡Š€ˆ€ˆ€ˆ† ‡ ƒ‰‰†  Œ ‡ ƒ‚  Œ ‡ ƒ‰‰†  Œ ‡‰€€€†  Œ Œ  ‡ ƒ‰‰† Œ  ‡ ƒ‚ Œ  ‡ ƒ‰‰† Œ  ‡‰€€€† ‡  ƒ‰‰† ‡‰‰‚  † Œ       Œ Œ       Œ ‡ƒ‰‰†   Œ ‡‰€€†   Œ Œ       Œ Œ       Œ Œ ‡  ƒ‰‰† Œ     Š²‚ ƒ²Š     Œ ‡ƒ‰‰† Œ ‡ƒ‰‰ Œ ‡ƒ‰‰Œ ‡ƒ‚Œ ƒ‚Œ    ",
   "‡ ƒ‚ Ÿ ž ƒ‚ † ‡€‰‰‰‚ †Ÿ ž ƒ‰‰‰€† ‡ ƒ‚  Œ ‡€ˆŠˆ†  Œ ‡ ƒ‚  Œ ‡ ƒ‰‰†  Œ Œ  ‡ ƒ‚ Œ  ‡€ˆŠˆ† Œ  ‡ ƒ‚ Œ  ‡ ƒ‰‰† ‡  ƒ‚ ƒ‚  † ‡‰€‰€€€‰† ‡‰€€€‰€‰† ‡ƒ‚   Œ ‡ ƒ‰†   Œ Œ       Œ Œ       Œ Œ ‡  ƒ‚ ‡€‰€€€† Œ Œ ‡€‰€€€† ƒ‚ Œ ƒ‚ Œ ƒ‚Œ ‡ˆŠˆŒ „ˆˆ…    ",
   "‡€ˆˆˆ… †Ÿ ž‡ „ˆˆˆ€† ‡ „… Ÿ ž „… † ‡€ˆŠˆ†  Œ ‡‰ˆ‰ˆ†  Œ ‡€ˆŠˆ†  Œ ‡ ƒ‚  Œ Œ  ‡€ˆŠˆ† Œ  ‡‰ˆ‰ˆ† Œ  ‡€ˆŠˆ† Œ  ‡ ƒ‚ ‡ˆ€€ˆŠˆˆ† ‡ˆˆŠˆ€€ˆ† ‡  ƒ‰‰† ‡‰‰‚  † ‡ˆŠˆ†   Œ ‡ ƒ   Œ ‡‰€ŠŠ‰‰‰† ‡‰‰ŠŠ‰€‰† Œ ‡€€ˆŠˆ† ‡  ƒ‰‰† Œ Œ ‡  ƒ‰‰† ‡ˆŠˆ† Œ ‡ˆŠˆ Œ ‡ˆŠˆŒ „ˆ€ˆ…         ",
   "‡‰€‰€‰€Š† ‡Š€‰€‰€‰† ‡ „ˆˆ… †Ÿ ž „ˆˆ… † ‡‰€‰€†  Œ ‡€€€€†  Œ ‡‰ˆ‰ˆ†  Œ ‡€ˆŠˆ†  Œ Œ  ‡‰€‰€† Œ  ‡€€€€† Œ  ‡‰ˆ‰ˆ† Œ  ‡€ˆŠˆ† Œ       Œ Œ       Œ ‡  ƒ‚ ƒ‚  † ‡€‰€†   Œ ‡€ˆŠ†   Œ ‡  ƒ‚† ƒ‚  † „²Š     Œ ‡  ƒ‚ Œ Œ ‡  ƒ‚ „ˆ€ˆˆ²… „ˆ€ˆ²… „ˆ€ˆ…               ",
   "„€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „ˆ€€€€€ˆ… „ˆ€€€€€ˆ… „€ˆ€ˆˆ²²… „²²²²ˆ²²… „––––ˆ²²… „€ˆ€ˆˆ²²… „²²ˆ€ˆ€ˆ… „²²ˆ²²²²… „²²ˆ––––… „²²ˆ€ˆ€ˆ… „²²²²²²²… „²²²²²²²… „ˆ€€ˆŠˆˆ… „ˆˆŠˆ€€ˆ… „ˆ€ˆˆ²²²… „€ˆ€ˆ²²²… „ˆ€€ˆŠˆˆ… „ˆˆŠˆ€€ˆ…  á„²²²²²… „€€ˆŠˆˆ²… „²ˆ€€ˆŠˆ…                                    ",
   "ƒ€€‰€‰€€‚ ƒ€€‰€‰€€‚ ƒ€€‰€‰€€‚ ƒ€€‰€‰€€‚ ƒ€€‰€‰²²‚ ƒ€€‰€‰²²‚ ƒ€€‰€‰²²‚ ƒ€€‰€‰²²‚ ƒ²²‰€‰€€‚ ƒ²²‰€‰€€‚ ƒ²²‰€‰€€‚ ƒ²²‰€‰€€‚ ƒ€€‰€‰€€‚ ƒ€€‰€‰€€‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ€€‰€²²²‚ ƒ€€‰€²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²‰€€‰€‰‚ ƒ²²²²²‚á   áƒ²²²²²‚ ƒ€€‰‰²‚ ƒ€€‰²‚ ƒ€€‰‚ ƒ€€‰‚ ƒ€‰‚ ·· ",
   "‡€‚ ƒ€† ‡€‚ ƒ€† ‡€‚ ƒ€† ‡€‚ ƒ€† ‡€‚   Œ ‡€‚   Œ ‡€‚   Œ ‡€‚   Œ Œ   ƒ€† Œ   ƒ€† Œ   ƒ€† Œ   ƒ€† ‡€‚ ƒ€† ‡€‚ ƒ€† Œ       Œ Œ       Œ ‡€‚    Œ ‡€‚    Œ Œ       Œ Œ       Œ Œ ‡€‚  Œ     Š²‚ ƒ²Š     Œ ‡€‚ Œ ‡€‚ Œ ‡€‚Œ ‡€‚Œ ‡€‚Œ    ",
   "‡€ˆ… „ˆ€† ‡€ˆ… „ˆ€† ‡€ˆ… „ˆ€† ‡€ˆ… „ˆ€† ‡€ˆ… „  Œ ‡€ˆ… „  Œ ‡€ˆ… „  Œ ‡€ˆ… „  Œ Œ  … „ˆ€† Œ  … „ˆ€† Œ  … „ˆ€† Œ  … „ˆ€† ‡€ˆ… „ˆ€† ‡€ˆ… „ˆ€† ‡€ˆ… „ˆ€† ‡€ˆ… „ˆ€† ‡€ˆ…    Œ ‡€ˆ…    Œ Œ       Œ Œ       Œ Œ ‡€ˆ… „ ‡€ˆ… „Œ Œ Œ ‡€ˆ… „† ‡€ˆ… Œ ‡€ˆ… Œ ‡€ˆ…Œ ‡€ˆ…Œ „€ˆ…    ",
   "‡€‰‚ ƒ‰€† ‡€‰‚ ƒ‰€† ‡€‰‚ ƒ‰€† ‡€‰‚ ƒ‰€† ‡€‰‚ ƒ  Œ ‡€‰‚ ƒ  Œ ‡€‰‚ ƒ  Œ ‡€‰‚ ƒ  Œ Œ  ‚ ƒ‰€† Œ  ‚ ƒ‰€† Œ  ‚ ƒ‰€† Œ  ‚ ƒ‰€† ‡€‰‚ ƒ‰€† ‡€‰‚ ƒ‰€† ‡€‰‚ ƒ‰€† ‡€‰‚ ƒ‰€† ‡€‰‚    Œ ‡€‰‚    Œ ‡€‰‚ ƒ‰€† ‡€‰‚ ƒ‰€† Œ ‡€‰‚ ƒ† ‡€‰‚ ƒŒ Œ Œ ‡€‰‚ ƒ† ‡€‰‚ Œ ‡€‰‚ Œ ‡€‰‚Œ „€ˆ€…         ",
   "‡€… „€† ‡€… „€† ‡€… „€† ‡€… „€† ‡€…   Œ ‡€…   Œ ‡€…   Œ ‡€…   Œ Œ   „€† Œ   „€† Œ   „€† Œ   „€† Œ       Œ Œ       Œ ‡€… „€† ‡€… „€† ‡€…    Œ ‡€…    Œ ‡€… „€† ‡€… „€† „²Š     Œ ‡€… Œ Œ Œ ‡€… Œ „€ˆ€ˆ²… „€ˆ€²… „€ˆ€…               ",
   "„€€ˆ€ˆ€€… „€€ˆ€ˆ€€… „€€ˆ€ˆ€€… „€€ˆ€ˆ€€… „€€ˆ€ˆ²²… „€€ˆ€ˆ²²… „€€ˆ€ˆ²²… „€€ˆ€ˆ²²… „²²ˆ€ˆ€€… „²²ˆ€ˆ€€… „²²ˆ€ˆ€€… „²²ˆ€ˆ€€… „²²²²²²²… „²²²²²²²… „€€ˆ€ˆ€€… „€€ˆ€ˆ€€… „€€ˆ€²²²… „€€ˆ€²²²… „€€ˆ€ˆ€€… „€€ˆ€ˆ€€…  á„²²²²²… „€€ˆ€ˆˆ²… „²ˆ€€ˆ€ˆ…                                    ",
   "ƒ€€€‰€€€‚ ƒ€€€‰€€€‚ ƒ€€€‰€€€‚ ƒ€€€‰€€€‚ ƒ€€‰€‰²²‚ ƒ€‰ˆ€‰²²‚ ƒ€€‰€‰²²‚ ƒ²²²²‰²²‚ ƒ²²‰€€‰€‚ ƒ²²‰€‰ˆ€‚ ƒ²²‰€€‰€‚ ƒ²²‰²²²²‚ ƒ‰€€‰€€‰‚ ƒ‰€€‰€€‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ€€‰€²²²‚ ƒ²²²‰²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²‰€€‰€€‚ ƒ²²²²²‚á   áƒ²²²²²‚ ƒ€€‰‰²‚ ƒ€€‰²‚ ƒ€€‰‚ ƒ€€€‚ ƒ€€‚ €· ",
   "  ƒˆ€€‚ ƒ€€ˆ‚     ƒˆ€€‚ ƒ€€ˆ‚    ƒˆ€  Œ ƒ†Š †  Œ  ƒˆ€  Œ ‡€€‰€†  Œ Œ   ƒˆ€ Œ  ƒ†Š † Œ   ƒˆ€ Œ  ‡€€‰€†  ƒˆ€€ €€ˆ‚  Œ       Œ Œ       Œ  ƒˆ€   Œ ‡€€‰†   Œ Œ       Œ Œ       Œ Œ  ƒˆ€€ Œ     Š²‚ ƒ²Š     Œ  ƒˆ Œ  ƒˆ Œ  ƒˆŒ ƒ†ŠŒ †Š Œ    ",
   "ƒ€†Š  ‡† ‡†  Š‡€‚ ƒ€†Š  ‡† ‡†  Š‡€‚ ƒ†Š †  Œ ‡…„€‰  Œ ƒ†Š †  Œ  ƒˆ€  Œ Œ  ƒ†Š † Œ  ‡…„€‰ Œ  ƒ†Š † Œ   ƒˆ€ ƒ†Š  † ‡  Š‡‚ ‡‰€€‰€€‰† ‡‰€€‰€€‰† ƒ†Š    Œ  ƒˆ   Œ Œ       Œ Œ       Œ Œ ƒ†Š  † ‡€€‰€€† Œ Œ ‡€€‰€€† ƒ†Š† Œ ƒ†Š Œ ƒ†ŠŒ ‡…„€Œ „€ˆ…    ",
   "‡… „€‰€† „€‰€… „† ‡… „€‰€† „€‰€… „† ‡…„€‰  Œ ‡† ƒ…  Œ ‡…„€‰  Œ ƒ†Š †  Œ Œ  ‡…„€‰ Œ  ‡† ƒ… Œ  ‡…„€‰ Œ  ƒ†Š † ‡ˆ…„€€€ˆ† ‡ˆ€€€…„ˆ†  ƒˆ€€ €€ˆ‚  ‡…„€‰   Œ ƒ†Š†   Œ ‡‰€‡ˆ€€‰† ‡‰€ˆˆ‚€‰† Œ ‡…„€€€†  ƒˆ€€ Œ Œ  ƒˆ€€ ‡…„€ Œ ‡…„€ Œ ‡…„€Œ „€ˆ€…         ",
   "‡†  ƒ…   ƒ…   ‡† ‡†  ƒ…   ƒ…   ‡† ‡† ƒ…  Œ ‡€€ˆ€†  Œ ‡€€ˆ€†  Œ ‡…„€‰  Œ Œ  ‡† ƒ… Œ  ‡€€ˆ€† Œ  ‡€€ˆ€† Œ  ‡…„€‰ Œ       Œ Œ       Œ ƒ†Š  † ‡  Š‡‚ ‡† ƒ…   Œ ‡…„€   Œ ƒ†Š  † ‡  Š‡‚ „²Š     Œ ƒ†Š  † Œ Œ ƒ†Š  † „€ˆ€ˆ²… „€ˆ€²… „€ˆ€…               ",
   "„€€€ˆ€€ˆ… „€ˆ€€€€€… „€€€ˆ€€ˆ… „€ˆ€€€€€… „€€ˆ€ˆ²²… „€€ˆ€ˆ²²… „––––ˆ²²… „€€ˆ€ˆ²²… „²²ˆ€€ˆ€… „²²ˆ€€ˆ€… „²²ˆ––––… „²²ˆ€€ˆ€… „²²²²²²²… „²²²²²²²… „ˆ…„€€€ˆ… „ˆ€€€…„ˆ… „€€ˆ€²²²… „€€ˆˆ²²²… „ˆ…„€€€ˆ… „ˆ€€€…„ˆ…  á„²²²²²… „…„€€€ˆ²… „²ˆ…„€€€…                                    ",
   /* ---------------------fulls----------- ----------------lefts------------------ -----------------rights---------------- -------tops-------- ------bottoms------ -------verts------- -------horzs------- ------corners------ --med-- -thin- thinr -sml- tiny mi */
   "ƒ€‰€€‰€‰‚ ƒ‰€‰€€‰€‚ ƒ€€€€€€€‚ ƒ€€€€€€€‚ ƒ‰€€‚ƒ²²‚ ƒ€‰‰‚ƒ²²‚ ƒ‰€€‚ƒ²²‚ ƒ²²²²‰²²‚ ƒ²²‰‰€€‚• ƒ²²‰€‰‰‚• ƒ²²‰‰€€‚• ƒ²²‰²²²²‚ ƒ€‚ƒ€‰‰€‚ ƒ€‰‰€‚ƒ€‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ€€‚ƒ²²²‚ ƒ²²²‰²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²‰‰‰€‚ƒ‚ ƒ²²²²²‚á   áƒ²²²²²‚ ƒ‰€€‚²‚ ƒ€€‚²‚ ƒ€€‚‚ ƒ‰‰‚‚ ƒ‰‚‚ Ž· ",
   "‡€…ƒ‚ž Ÿ ž Ÿƒ‚„€† ‡€€‚ ƒ€€† ‡…ƒ‚Ÿ  Œ €Š…Ÿ  Œ ‡…ƒ‚Ÿ  Œ ‡‰€€‚  Œ Œ  ‡…ƒ‚Ÿ Œ  €Š…Ÿ Œ  ‡…ƒ‚Ÿ Œ  ‡‰€€‚  ž „Š€† ‡€Š… Ÿ  Œ       Œ Œ       Œ ‡ƒ‚Ÿ   Œ ‡€€‚   Œ Œ       Œ Œ       Œ Œ ‡Š… Ÿ Œ     Š²‚ ƒ²Š     Œ ‡…ƒ‚ž Œ ‡ƒ‚ž Œ ‡ƒ‚žŒ Š…žŒ „Œ    ",
   " €Š…ž Ÿ ž Ÿ„Š€  ‡œœœœ‚   ƒœœœœ† €Š…Ÿ  Œ „…  Œ €Š…Ÿ  Œ ‡…ƒ‚Ÿ  Œ Œ  €Š…Ÿ Œ  „… Œ  €Š…Ÿ Œ  ‡…ƒ‚Ÿ ‡€†„… „…‡€† ‡€‚ƒ€‰‰€† ‡€‰‰€‚ƒ€† Š…Ÿ   Œ ‡ƒ‚Ÿ   Œ Œ       Œ Œ       Œ Œ „…‡† ‡‰‰€‚ƒ† Œ Œ ‡‰‰€‚ƒ† €Š…ž Œ Š…ž Œ Š…žŒ „…Œ „œœ…    ",
   "‡…   „†  €Š‚ž Ÿ ž ŸƒŠ€  „…  Œ ƒœœœ€†  Œ „…  Œ €Š…Ÿ  Œ Œ  „… Œ  ƒœœœ€† Œ  „… Œ  €Š…Ÿ ‡€ˆ€œœœœ‚ ƒœœœœ€ˆ€†  ž „Š€† ‡€Š… Ÿ  „…   Œ Š…Ÿ   Œ ‡€‚‡ˆ‰‰€† ‡€‰Šˆ‚ƒ€† Œ ƒœœœ€ˆ† ‡Š… Ÿ Œ Œ ‡Š… Ÿ „… Œ „… Œ „…Œ „œœ€…         ",
   "‡œœœœ€€… „€€œœœœ† ‡€‚„…ž Ÿ ž Ÿ„…ƒ€† ƒœœœ€†  Œ ‡€…„€†  Œ ƒœœœ€†  Œ „…  Œ Œ  ƒœœœ€† Œ  ‡€…„€† Œ  ƒœœœ€† Œ  „… Œ       Œ Œ       Œ ‡€†„… „…‡€† ƒœœ€†   Œ „…   Œ  ž „Š€† ‡€Š… Ÿ  „²Š     Œ „…‡† Œ Œ „…‡† „œœœ€²… „œœ€²… „œœ€…               ",
   "„€€€€€€€… „€€€€€€€… „€ˆ€€ˆ€ˆ… „ˆ€ˆ€€ˆ€… „““““ˆ²²… „²²²²ˆ²²… „€…„€ˆ²²… ‘œœœ€ˆ²²… „²²ˆ““““… „²²ˆ²²²²… „²²ˆ€…„€… „²²€œœœ€… „²²²²²²²… „²²²²²²²… „€ˆ€œœœœ ‘œœœœ€ˆ€… „“““ˆ²²²… ‘œœ€ˆ²²²… „€…„… „…„€…  á„²²²²²… „œœœ€ˆˆ²… „²ˆœœœ€ˆ…                                    ",
   "ƒ€€€‰€€€‚ ƒ€€€‰€€€‚ ƒ€€€‰€€€‚ ƒ€€€‰€€€‚ ƒ€‰‰€‰²²‚ ƒˆ‰‰ˆ‰²²‚ ƒ€‰‰€‰²²‚ ƒ²²²²‰²²‚ ƒ²²‰€‰‰€‚ ƒ²²‰ˆ‰‰ˆ‚ ƒ²²‰€‰‰€‚ ƒ²²‰²²²²‚ ƒ‰€‰€‚ ƒ€‰€‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ€‰€‰²²²‚ ƒ²²²‰²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²‰€€‰€€‚ ƒ²²²²²‚á   áƒ²²²²²‚ ƒ€‰€‰²‚ ƒ€‰€²‚ ƒ€‰€‚ ƒ€‰€‚ ƒ€‰‚ ‚· ",
   "                                Œ ‡  †  Œ     Œ ‡€‰‰€†  Œ Œ     Œ  ‡  † Œ     Œ  ‡€‰‰€† ƒœƒ€ˆ       ˆ€‚œ‚ Œ       Œ Œ       Œ      Œ ‡€‰€†   Œ Œ       Œ Œ       Œ Œ      Œ     Š²‚ ƒ²Š     Œ    Œ    Œ   Œ   Œ  Œ    ",
   "‡€‚  ƒ€† ‡€‰€ˆ€‰€† ‡€‰€Š€‰€† ‡€€€ˆ€€€† ‡‚ƒ†  Œ ž„ŠŠ…Ÿ  Œ ‡‚ƒ†  Œ     Œ Œ  ‡‚ƒ† Œ  ž„ŠŠ…Ÿ Œ  ‡‚ƒ† Œ     ‡€Š€€€€€† ‡€€€€€Š€† ‡œƒ€ˆ   † ‡   ˆ€‚œ† ‡‚ƒ†   Œ      Œ Œ       Œ Œ       Œ Œ ‡€‰ˆ‰€† ‡€€‰€€† Œ Œ ‡€€‰€€† ‡‚ƒ† Œ ‡‚ƒ Œ ‡‚ƒŒ ‡‚ƒŒ „„……    ",
   "ž „‚Šƒ… Ÿ ‡€ˆ‚ ƒˆ€†  ž   Ÿ   ƒœœœ‚  ž„ŠŠ…Ÿ  Œ žƒ‚Ÿ  Œ ž„ŠŠ…Ÿ  Œ ‡‚ƒ†  Œ Œ  ž„ŠŠ…Ÿ Œ  žƒ‚Ÿ Œ  ž„ŠŠ…Ÿ Œ  ‡‚ƒ† ‡ˆ€‰   † ‡   ‰€ˆ† ‡€Š€€€€€† €€€€€Š€† ž„Š…Ÿ   Œ ‡‚ƒ†   Œ ‡Š€‰€† ‡€‰ˆŠ† Œ œœ œœ      Œ Œ      ž„Š…Ÿ Œ ž„Š… Œ ž„Š…Œ „„ˆ……         ",
   "ž ƒ…„‚ Ÿ   ž Ÿ   ‡€†   ‡€† ‡€ˆ€Š€ˆ€† žƒ‚Ÿ  Œ ‡„ˆˆ…  Œ ‡„ˆˆ…†  Œ ž„ŠŠ…Ÿ  Œ Œ  žƒ‚Ÿ Œ  ‡„ˆˆ… Œ  ‡„ˆˆ…† Œ  ž„ŠŠ…Ÿ Œ       Œ Œ       Œ ‡„€‰       ‰€…† žƒ‚Ÿ   Œ ž„Š…Ÿ   Œ ƒœƒ€ˆ       ˆ€‚œ‚ „²Š     Œ ‡€‰ˆ‰€† Œ Œ ‡€‰ˆ‰€† „„ˆ…ˆ²… „„ˆ…²… „„ˆ……               ",
   "„€„€ˆ€…€… „€€… „€€… „€ˆ€€€ˆ€… „€€€ˆ€€€… „„ˆˆ…ˆ²²… „²²²²ˆ²²… „€€€€ˆ²²… „„ˆˆ…ˆ²²… „²²ˆ„ˆˆ…… „²²ˆ²²²²… „²²ˆ€€€€… „²²ˆ„ˆˆ…… „²²²²²²²… „²²²²²²²… „œœœˆ€ˆ€… „€ˆ€ˆœœœ… „„ˆ…ˆ²²²… „„ˆ…ˆ²²²… „€ˆ€€€€€… „€€€€€ˆ€…  á„²²²²²… „œœ œœˆ²… „²ˆœœ œœ…                                    ",
   "ƒœœœ‰œœœ‚ ƒœœœ‰œœœ‚ ƒœœœ‰œœœ‚ ƒœœœ‰œœœ‚ ƒœœ‰œ‰²²‚ ƒœœŠœ‰²²‚ ƒœœ‰œ‰²²‚ ƒ²²²²‰²²‚ ƒ²²‰œœ‰œ‚ ƒ²²‰œœŠœ‚ ƒ²²‰œœ‰œ‚ ƒ²²‰²²²²‚ ƒ‰œœ‰œœ‰‚ ƒ‰œœŠœœ‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒœœ‰‰²²²‚ ƒ²²²‰²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²‰œœŠœ‰‚ ƒ²²²²²‚á   áƒ²²²²²‚ ƒœœœ‰²‚ ƒœœ‰²‚ ƒœœ‰‚ ƒœœ‰‚ ƒœ‰‚ †· ",
   "‡’“€Š’“‚ž ‡      ž ‡€€ „€‰€ž Ÿ      ž ‡’“Š’ž  Œ Ÿ „€ž  Œ ‡’“Š’ž  Œ ‡œœ‰œ†  Œ Œ  ‡’“Š’ž Œ  Ÿ „€ž Œ  ‡’“Š’ž Œ  ‡œœ‰œ† ‡’“Š€’ž Ÿ“†„€€ž Œ       Œ Œ       Œ ‡’“Šž   Œ ‡œœ‰†   Œ Œ       Œ Œ       Œ Œ “†„€ž Œ     Š²‚ ƒ²Š     Œ ‡’“’ž Œ ‡“’ž Œ ‡“’žŒ ‡“’žŒ ‡“žŒ    ",
   "Ÿ  „€€… Ÿ  „’“€† Ÿ „€‰€ €† ‡€€€Š€ €† Ÿ „€ž  Œ Ÿ „‰€†  Œ Ÿ „€ž  Œ ‡’“Š’ž  Œ Œ  Ÿ „€ž Œ  Ÿ „‰€† Œ  Ÿ „€ž Œ  ‡’“Š’ž Ÿ „€€ž Ÿ „‰€€† ‡‰œœ‰œœ‰† ‡‰œœŠœœ‰† Ÿ „ž   Œ ‡’“Šž   Œ Œ       Œ Œ       Œ Œ  „‰€† ‡œœŠœ‰† Œ Œ ‡œœŠœ‰† Ÿ €ž Œ Ÿ€ž Œ Ÿ€žŒ Ÿ„€†Œ „ˆ…    ",
   "Ÿ „€‰€‰€† Ÿ „€‰€‰€† Ÿ ‚  ƒ€ž ‡€‚  ƒ€ž Ÿ „‰€†  Œ ‡’“€€ž  Œ Ÿ „‰€†  Œ Ÿ „€ž  Œ Œ  Ÿ „‰€† Œ  ‡’“€€ž Œ  Ÿ „‰€† Œ  Ÿ „€ž ‡ˆ€ˆ‰€€ˆ† ‡ˆ’“€€€ˆ† ‡’“Š€’ž Ÿ“†„€€ž Ÿ „‰†   Œ Ÿ „ž   Œ ‡‰œœŠœœ‰† ‡‰œœŠœœ‰† Œ ‡’“€€ˆ† “†„€ž Œ Œ “†„€ž Ÿ „€† Œ Ÿ„€† Œ Ÿ„€†Œ „ˆ…         ",
   "‡’“€€€† ž Ÿ’“€‡€  ž ‡€…   † Ÿ€…   † ‡’“€€ž  Œ ‡„†  Œ ‡„†  Œ Ÿ „‰€†  Œ Œ  ‡’“€€ž Œ  ‡„† Œ  ‡„† Œ  Ÿ „‰€† Œ       Œ Œ       Œ Ÿ „€€ž Ÿ „‰€€† ‡’“€ž   Œ Ÿ „‰†   Œ Ÿ’“Š€’ž Ÿ“†„€€ž „²Š     Œ  „‰€† Œ Œ  „‰€† „ˆ²… „ˆ²… „ˆ…               ",
   "„„…… „„…… „„…… „„…… „„ˆ²²… „€€€€ˆ²²… „––––ˆ²²… „„ˆ²²… „²²ˆ„… „²²ˆ€€€€… „²²ˆ––––… „²²ˆ„… „²²²²²²²… „²²²²²²²… „ˆ€ˆ‰€€ˆ… „ˆ’“€€€ˆ… „„ˆ²²²… „„ˆ²²²… „ˆ €ˆ€€ˆ… „ˆ „ˆ€€ˆ…  á„²²²²²… „’“€€ˆˆ²… „²ˆ’“€€ˆ…                                    ",
   /* ---------------------fulls----------- ----------------lefts------------------ -----------------rights---------------- -------tops-------- ------bottoms------ -------verts------- -------horzs------- ------corners------ --med-- -thin- thinr -sml- tiny mi */
   "ƒ‰‰‚ ƒ‰‰‚ ƒ‰‰€‰€‰‰‚ ƒ‰‰‚ ƒ‰‰‚ ƒ‰‰€‰€‰‰‚ ƒ‰‚ƒ‰‰²²‚ ƒ‰ˆˆ‰‰²²‚ ƒ‰‚ƒ‰‰²²‚ ƒ²²²²‰²²‚ ƒ²²‰‰‚ƒ‰‚ ƒ²²‰‰ˆˆ‰‚ ƒ²²‰‰‚ƒ‰‚ ƒ²²‰²²²²‚ ƒ‰‰‚ ƒ‰‰‚ ƒ‰‰ˆ€ˆ‰‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ‰‚ƒ‰²²²‚ ƒ²²²‰²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²‰‰ˆ€ˆ‰‚ ƒ²²²²²‚á   áƒ²²²²²‚ ƒ‰€‰‰²‚ ƒ‰‰‰²‚ ƒ‰‰‰‚ ƒ‰‰‰‚ ƒ‰‰‚ Š· ",
   "ƒˆ ˆ‚ „†‡… ƒˆ ˆ‚ „†‡… ƒˆˆ‚  Œ „†‡…  Œ ƒˆˆ‚  Œ ‡‰‚ƒ‰†  Œ Œ  ƒˆˆ‚ Œ  „†‡… Œ  ƒˆˆ‚ Œ  ‡‰‚ƒ‰† ƒˆ ˆ‚ „†‡… Œ       Œ Œ       Œ ƒˆˆ‚   Œ ‡‰‚ƒ†   Œ Œ       Œ Œ       Œ Œ „… Œ     Š²‚ ƒ²Š     Œ ƒˆ‚ Œ ƒˆ‚ Œ ƒˆ‚Œ „†‡Œ †Œ    ",
   "‡†‡† ƒŠ‚ ƒŠ‚ ‡†‡† ƒŠ‚ ƒŠ‚ „†‡…  Œ ƒŠ‚ƒŠ‚  Œ „†‡…  Œ ƒˆˆ‚  Œ Œ  „†‡… Œ  ƒŠ‚ƒŠ‚ Œ  „†‡… Œ  ƒˆˆ‚ „†‡… ƒŠ‚ ƒŠ‚ ‡‰‰‚ ƒ‰‰† ‡‰‰ˆ€ˆ‰‰† „†‡   Œ ƒˆˆ   Œ Œ       Œ Œ       Œ Œ ƒ‚ ƒ‚ ‡‰ˆ€ˆ‰† Œ Œ ‡‰ˆ€ˆ‰† „†‡… Œ „†‡ Œ „†‡Œ ƒŠ‰ŠŒ „€ˆ…    ",
   "ƒˆ‰ˆ‚ „†„‰…‡… ƒˆ‰ˆ‚ „†„‰…‡… ƒŠ‚ƒŠ‚  Œ áŠŠá  Œ ƒŠ‚ƒŠ‚  Œ „†‡…  Œ Œ  ƒŠ‚ƒŠ‚ Œ  áŠŠá Œ  ƒŠ‚ƒŠ‚ Œ  „†‡… ‡€ˆ€€€ˆ€† ‡ˆ€ˆ€ˆ€ˆ† ƒˆ ˆ‚ „†‡… ƒŠ‚ƒŠ   Œ „†…   Œ ‡‰‰† ƒ‰‰† ‡‰‰ˆ€ˆ‰‰† Œ ‡ˆˆ€ˆˆ† „… Œ Œ „… ƒŠ‰Š‚ Œ ƒŠ‰Š Œ ƒŠ‰ŠŒ „€€ˆ…         ",
   "„†  ‡… ƒŠ‚ ƒŠ‚ „†  ‡… ƒŠ‚ ƒŠ‚ áŠŠá  Œ ‡€…„€†  Œ ‡á…„á†  Œ ƒŠ‚ƒŠ‚  Œ Œ  áŠŠá Œ  ‡€…„€† Œ  ‡á…„á† Œ  ƒŠ‚ƒŠ‚ Œ       Œ Œ       Œ „†‡… ƒŠ‚ ƒŠ‚ áŠŠá   Œ ƒŠ‚ƒ‚   Œ ƒˆ ˆ‚ „†‡… „²Š     Œ ƒ‚ ƒ‚ Œ Œ ƒ‚ ƒ‚ „€€€ˆ²… „€€ˆ²… „€€ˆ…               ",
   "„€ˆ€ˆ€ˆ€… „ˆ€ˆ€ˆ€ˆ… „€ˆ€ˆ€ˆ€… „ˆ€ˆ€ˆ€ˆ… „€…„€ˆ²²… „€…„€ˆ²²… „²²²²ˆ²²… „á…„áˆ²²… „²²ˆ€…„€… „²²ˆ€…„€… „²²ˆ²²²²… „²²ˆá…„á… „²²²²²²²… „²²²²²²²… „€ˆ€€€ˆ€… „ˆ€ˆ€ˆ€ˆ… „€…„€²²²… „á…„ˆ²²²… „„…„…… „€Š… „Š€…  á„²²²²²… „ˆˆ€ˆˆˆ²… „²ˆˆˆ€ˆˆ…                                    ",
   "ƒ€–ƒ€‚“€‚ ƒ€–ƒ€‚“€‚ ƒ€–ƒ€‚“€‚ ƒ€–ƒ€‚“€‚ ƒ€–ƒá‰²²‚ ƒá‚“€‰²²‚ ƒ€–ƒá‰²²‚ ƒ²²²²‰²²‚ ƒ²²‰€–ƒá‚ ƒ²²‰á‚“€‚ ƒ²²‰€–ƒá‚ ƒ²²‰²²²²‚ ƒ€–‰‚á‰€‚ ƒ€‰áƒ‰“€‰ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ–ƒá‰²²²‚ ƒ²²²‰²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²‰€–‰‚á‚ ƒ²²²²²‚á   áƒ²²²²²‚ ƒ–ƒá‰²‚ ƒ–ƒ‰²‚ ƒ–ƒ‰‚ ƒ–ƒ‰‚ ƒ†‰‚ · ",
   "‰‚áŽƒ‰ ‰‚áŽƒ‰ ‰‚áŽƒ‰ ‰‚áŽƒ‰ ‡ ‰‚á  Œ Žáƒ‰ †  Œ ‡ ‰‚á  Œ ‡€–ƒá‰  Œ Œ  ‡ ‰‚á Œ  Žáƒ‰ † Œ  ‡ ‰‚á Œ  ‡€–ƒá‰ ‡ Œ„…†† ‡Ž‡Ž„…Œ † Œ       Œ Œ       Œ ‡‰‚á   Œ ‡€–ƒ‰   Œ Œ       Œ Œ       Œ Œ ‡ Œ„…á Œ     Š²‚ ƒ²Š     Œ ‡‰‚á Œ ‡‰‚ Œ ‡‰‚Œ ‡‰‚Œ Š…Œ    ",
   "„…Ž„… „…Ž„… „…Ž„… „…Ž„…  „…Ž  Œ Ž„…   Œ  „…Ž  Œ ‡ ‰‚á  Œ Œ   „…Ž Œ  Ž„…  Œ   „…Ž Œ  ‡ ‰‚á ƒ‚  Ž†† ‡Ž‡  ƒ‚ ‡€–‰‚á‰€† ‡€‰áƒ‰“€† „…Ž   Œ ‡ ‰‚   Œ Œ       Œ Œ       Œ Œ ƒ‚  Ž ‡€–‰‚á‰ Œ Œ ‡€–‰‚á† „…Ž Œ „…Ž Œ „…ŽŒ „…ŽŒ „ˆˆ…    ",
   "Œ ŽŽ Œ Œ ŽŽ Œ Œ ŽŽ Œ Œ ŽŽ Œ  Œ Ž  Œ Ž Œ   Œ ƒ‚ Ž  Œ  „…Ž  Œ Œ   Œ Ž Œ  Ž Œ  Œ  ƒ‚ Ž Œ   „…Ž ‡€ˆ€ˆáˆ€† ‡€€áˆ€ˆ€ ‡ Œ„…†† ‡Ž‡Ž„…Œ † Œ Ž   Œ  „…Ž   Œ ‡€–Š†á‰€† ‡€‰á‡‰“€† Œ ‡€ˆ€ˆŽ ‡ Œ„…á Œ Œ ‡ Œ„…á ‚ Ž Œ ‚  Œ ‚ Œ „ˆ€ˆ…         ",
   "ƒ‚áŽƒ‚ ƒ‚áŽƒ‚ ƒ‚áŽƒ‚ ƒ‚áŽƒ‚ ƒ‚ áŽ  Œ á ƒ‚  Œ ‡€ˆ€ˆŠ  Œ ƒ‚ Ž  Œ Œ  ƒ‚ áŽ Œ  á ƒ‚ Œ  ‡€ˆ€ˆŠ Œ  ƒ‚ Ž Œ       Œ Œ       Œ ƒ‚  Ž†† ‡Ž‡  ƒ‚ ƒ‚áŽ   Œ ƒ‚    Œ ‡ƒ‚„…†† ‡Ž‡Ž„…ƒ‚† „²Š     Œ ƒ‚  Ž Œ Œ ƒ‚  Ž „ˆ€áˆ²… „ˆ€ˆ²… „ˆ€ˆ…               ",
   "„€ˆá€áˆ€… „€ˆá€áˆ€… „€ˆá€áˆ€… „€ˆá€áˆ€… „€ˆ€áˆ²²… „á€ˆ€ˆ²²… „²²²²ˆ²²… „€ˆ€ˆˆ²²… „²²ˆ€ˆ€á… „²²ˆá€ˆ€… „²²ˆ²²²²… „²²ˆ€ˆ€ˆ… „²²²²²²²… „²²²²²²²… „€ˆ€ á€€… „€€ˆá€ˆ€… „€ˆáˆ²²²… „€ˆ€ˆ²²²… „€ˆ€€Ž†† ‡Ž‡€€ˆ€…  á„²²²²²… „²ˆ€ˆáˆ²… „²ˆ²ˆ€ˆá…                                    ",
   "ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²‰²²²²²‚ ƒ²²²²²‚á   áƒ²²²²²‚ ƒ²²²‰²‚ ƒ²²‰²‚ ƒ²²‰‚ ƒ²²‰‚ ƒ²²‚ ·· ",
   "Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ Œ     Œ Œ     Š²‚ ƒ²Š     Œ Œ   Œ Œ Œ  Œ Œ Œ  ŒŒ ‡²‚ŒŒ ‡²‚Œ    ",
   "Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ Œ     Œ Œ     Œ Œ Œ Œ     Œ ‡²‚ Œ Œ ‡²‚Œ Œ ‡²‚ŒŒ Œ ŒŒŒ „²ˆ…    ",
   "Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ Œ     Œ Œ     Œ Œ Œ Œ     Œ Œ Œ Œ Œ Œ ŒŒ Œ Œ ŒŒŒ „²ˆˆ…         ",
   "Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ „²Š     Œ Œ     Œ Œ Œ Œ     Œ „²ˆ²ˆ²… „²ˆˆ²… „²ˆˆ…               ",
   "„²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²…  á„²²²²²… „²²²²²ˆ²… „²ˆ²²²²²…                                    ",
   /* ---------------------fulls----------- ----------------lefts------------------ -----------------rights---------------- -------tops-------- ------bottoms------ -------verts------- -------horzs------- ------corners------ --med-- -thin- thinr -sml- tiny mi */
   "ƒ€€€‰€€‰‚ ƒ€€€‰€€‰‚ ƒ€€€‰€€‰‚ ƒ€€€‰€€‰‚ ƒ€€‰€‰²²‚ ƒ€‰€€‰²²‚ ƒ€€‰€‰²²‚ ƒ²²²²‰²²‚ ƒ²²‰€€‰€‚ ƒ²²‰€‰€€‚ ƒ²²‰€€‰€‚ ƒ²²‰²²²²‚ ƒ€€‰€€‰€‚ ƒ€‰€€‰€€‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ€‰€‰²²²‚ ƒ²²²‰²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²‰€€‰€‰‚ ƒ²²²²²‚á   áƒ²²²²²‚ ƒ€€‰‰²‚ ƒ€€‰²‚ ƒ€€‰‚ ƒ€€‰‚ ƒ€€‚ · ",
   " â „€…†  â „€…†  â „€…†  â „€…†  â †  Œ ‡ â   Œ  â †  Œ ‡€€‰€Š  Œ Œ   â † Œ  ‡ â  Œ   â † Œ  ‡€€‰€Š  â  † † ‡ ‡  â  Œ       Œ Œ       Œ â †   Œ ‡€€‰Š   Œ Œ       Œ Œ       Œ Œ  â † Œ     Š²‚ ƒ²Š     Œ  â† Œ  â Œ  âŒ ‡ƒ€‚Œ ƒ‚Œ    ",
   "‡ ƒ€€‚ † ‡ ƒ€€‚ † ‡ ƒ€€‚ † ‡ ƒ€€‚ † ‡ ƒ€‚†  Œ ‡ƒ€‚ †  Œ ‡ ƒ€‚†  Œ  â †  Œ Œ  ‡ ƒ€‚† Œ  ‡ƒ€‚ † Œ  ‡ ƒ€‚† Œ   â † ‡ ƒ€‚ † † ‡ ‡ ƒ€‚ † ‡€€‰€€‰€† ‡€‰€€‰€€† ‡ƒ€‚†   Œ  â†   Œ Œ       Œ Œ       Œ Œ ‡ ƒ€‚† ‡€€‰€‰† Œ Œ ‡€€‰€‰† ‡ƒ€‚† Œ ‡ƒ€‚ Œ ‡ƒ€‚Œ ‡„…Œ „€……    ",
   "‡ „€… † ‡ „€… † ‡ „€… † ‡ „€… † ‡ „…†  Œ ‡„… †  Œ ‡ „…†  Œ ‡ ƒ€‚†  Œ Œ  ‡ „…† Œ  ‡„… † Œ  ‡ „…† Œ  ‡ ƒ€‚† ‡²„…„€…€† ‡€„€…„…²†  â  † † ‡ ‡  â  ‡„…†   Œ ‡ ƒ€†   Œ ‡€€Šˆ€‰€† ‡€‰ˆˆ‰€€† Œ ‡ „…††  â †Œ Œ Œ  â †Œ ‡„…† Œ ‡„… Œ ‡„…Œ „œœœ…         ",
   "‡ˆ€ˆ€ˆ€Š ‡ˆ€ˆ€ˆ€Š ‡ˆ€ˆ€ˆ€Š ‡ˆ€ˆ€ˆ€Š ‡€ˆ€ˆŠ  Œ ‡ˆ€ˆ€†  Œ ‡€ˆ€ˆŠ  Œ ‡ „…†  Œ Œ  ‡€ˆ€ˆŠ Œ  ‡ˆ€ˆ€† Œ  ‡€ˆ€ˆŠ Œ  ‡ „…† Œ       Œ Œ       Œ ‡ ƒ€‚ † † ‡ ‡ ƒ€‚ † ‡ˆ€ˆŠ   Œ ‡ „…†   Œ ‡âƒ€‚ † † ‡ ‡ ƒ€‚â† „²Š     Œ ‡ ƒ€‚†Œ Œ Œ ‡ ƒ€‚†Œ „œœœˆ²… „œœœ²… „œœœ…               ",
   "„œœœœœœˆ… „œœœœœœˆ… „œœœœœœˆ… „œœœœœœˆ… „œœœœˆ²²… „œœœœˆ²²… „²²²²ˆ²²… „€ˆ€ˆˆ²²… „²²ˆœœœœ… „²²ˆœœœœ… „²²ˆ²²²²… „²²ˆ€ˆ€ˆ… „²²²²²²²… „²²²²²²²… „²„…„€…€… „€„€…„…²… „œœœˆ²²²… „€ˆ€ˆ²²²… „²„…„€…€… „€„€…„…²…  á„²²²²²… „ „…ˆ€ˆ²… „²ˆ „…ˆ€…                                    ",
   "ƒ€€€‰€€€‚ ƒ€€€‰€€€‚ ƒ€€€‰€€€‚ ƒ€€€‰€€€‚ ƒ€€€‰€²²‚ ƒ€€€‰€²²‚ ƒ€€€‰€²²‚ ƒ€€€‰€²²‚ ƒ²²€‰€€€‚ ƒ²²€‰€€€‚ ƒ²²€‰€€€‚ ƒ²²€‰€€€‚ ƒ€€€‰€€€‚ ƒ€€€‰€€€‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ€€€‰²²²‚ ƒ€€€‰²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²‰€€€‰€‚ ƒ²²²²²‚á   áƒ²²²²²‚ ƒ²²²‰²‚ ƒ²²‰²‚ ƒ²²‰‚ ƒ²²‰‚ ƒ²²‚ ·· ",
   "                                  Œ       Œ       Œ       Œ Œ       Œ       Œ       Œ                     Œ       Œ Œ       Œ       Œ       Œ Œ       Œ Œ       Œ Œ      Œ     Š²‚ ƒ²Š     Œ Œ   Œ Œ Œ  Œ Œ Œ  ŒŒ ‡²‚ŒŒ ‡²‚Œ    ",
   "‡€€€Š€€€† ‡€€€Š€€€† ‡€€€Š€€€† ‡€€€Š€€€† ‡€€€Š€  Œ ‡€€€Š€  Œ ‡€€€Š€  Œ ‡€€€Š€  Œ Œ  €Š€€€† Œ  €Š€€€† Œ  €Š€€€† Œ  €Š€€€† ‡€€€Š€€€† ‡€€€Š€€€†               ‡€€€Š   Œ ‡€€€Š   Œ Œ       Œ Œ       Œ Œ      ‡€€€‰€† Œ Œ ‡€€€‰€† ‡²‚ Œ Œ ‡²‚Œ Œ ‡²‚ŒŒ Œ ŒŒŒ „²ˆ…    ",
   "                                  Œ       Œ       Œ       Œ Œ       Œ       Œ       Œ                     ‡€€€Š€€€† ‡€€€Š€€€†       Œ       Œ ‡€€€Š€€€† ‡€€€Š€€€† Œ ‡€€€Š€† Œ    Œ Œ Œ Œ    Œ Œ Œ Œ Œ Œ ŒŒ Œ Œ ŒŒŒ „²ˆˆ…         ",
   "                                  Œ       Œ       Œ       Œ Œ       Œ       Œ       Œ       Œ       Œ Œ       Œ                     Œ       Œ               „²Š     Œ Œ    Œ Œ Œ Œ    Œ „²ˆ²ˆ²… „²ˆˆ²… „²ˆˆ…               ",
   "„€€€ˆ€€€… „€€€ˆ€€€… „€€€ˆ€€€… „€€€ˆ€€€… „€€€ˆ€²²… „€€€ˆ€²²… „€€€ˆ€²²… „€€€ˆ€²²… „²²€ˆ€€€… „²²€ˆ€€€… „²²€ˆ€€€… „²²€ˆ€€€… „²²²²²²²… „²²²²²²²… „€€€ˆ€€€… „€€€ˆ€€€… „€€€ˆ²²²… „€€€ˆ²²²… „€€€ˆ€€€… „€€€ˆ€€€…  á„²²²²²… ‡€€€Š€ˆ²… „²ˆ€€€Š€…                                    ",
   "ƒ‰‰á‰áá‰‚ ƒ‰‰á‰áá‰‚ ƒ‰‰á‰áá‰‚ ƒ‰‰á‰áá‰‚ ƒ‰‰á‰‰²²‚ ƒ‰‰á‰‰²²‚ ƒ‰‰á‰‰²²‚ ƒ²²²²‰²²‚ ƒ²²‰‰‰á‰‚ ƒ²²‰‰‰á‰‚ ƒ²²‰‰‰á‰‚ ƒ²²‰²²²²‚ ƒ‰‰á‰‰á‰‚ ƒ‰‰á‰‰á‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ‰á‰‰²²²‚ ƒ²²²‰²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²‰‰á‰á‰‚ ƒ²²²²²‚á   áƒ²²²²²‚ ƒ‰á‰‰²‚ ƒá‰‰²‚ ƒá‰‰‚ ƒá‰‰‚ ƒ‰‰‚ á· ",
   "áŽáŽŽá ááŽŽŽá ŽŽ€€€Žá áŽŽáŽá áŽŽá  Œ á‰‚á‰  Œ áŽŽá  Œ ‡‰‰á‰†  Œ Œ  áŽŽá Œ  á‰‚‰á Œ  áŽŽá Œ  ‡‰‰á‰† áŽŽŽŽá á‰‚‰á‚á‰ Œ       Œ Œ       Œ áŽŽá   Œ ‡‰‰á†   Œ Œ       Œ Œ       Œ Œ áŽáŽŽá Œ     Š²‚ ƒ²Š     Œ áŽŽá Œ áŽá Œ áŽáŒ áŽáŒ ááŒ    ",
   "ŽáŽŽá ŽŽŽŽáŽá áŽááŽ áŽáŽá áŽŽá  Œ ŽáŽá  Œ ŽááŽ  Œ áŽŽá  Œ Œ  áŽáŽ Œ  ŽáŽá Œ  ŽáŽá Œ  áŽŽá ŽáŽŽá ŽáŽáŽá ‡‰‰á‰‰á‰† ‡‰‰á‰‰á‰† ááŽ   Œ áŽáŽ   Œ Œ       Œ Œ       Œ Œ ááŽ ƒ‰á‰á‰† Œ Œ ‡‰á‰á‰† ááŽ Œ áŽá Œ áŽáŒ áŽáŒ áŽá…    ",
   "áŽŽáŽŽ áŽŽáŽŽá áŽáŽŽá áŽŽŽŽá áŽŽá  Œ áŽŽá  Œ áŽŽá  Œ ŽáŽá  Œ Œ  ŽáŽá Œ  áŽŽá Œ  áŽŽá Œ  ŽáŽá ‡ˆáˆˆˆáˆ† ‡ˆáˆˆˆ„€† áŽŽŽŽá á‰‚‰á‚‰á áŽŽá   Œ Žáá   Œ ‡ŽŽáŽŽ† ‡ŽáŽŽ† Œ ‡ˆáˆˆˆ† áŽáŽŽá Œ Œ áŽáŽŽá ŽáŽá Œ áŽá Œ áŽáŒ „ˆˆˆ…         ",
   "áŽáŽá áŽŽáŽá áŽ€€€€Žá ŽááŽá ŽáŽá  Œ áŽˆ…á  Œ ‡ˆáˆˆ†  Œ áŽŽá  Œ Œ  ŽááŽ Œ  Žáˆ…á Œ  ‡ˆáˆˆ† Œ  áŽŽá Œ       Œ Œ       Œ áŽáŽáŽ áŽŽááŽ áŽá   Œ áŽáŽ   Œ áŽáŽáá áŽáŽáŽá „²Š     Œ ááŽ Œ Œ ááŽ „áˆˆˆ²… „ˆˆˆ²… „ˆˆˆ…               ",
   "„ˆáˆˆˆˆˆ… „ˆáˆˆˆˆˆ… „ˆáˆˆˆˆˆ… „ˆáˆˆˆˆˆ… „ˆáˆˆˆ²²… „ˆáˆˆˆ²²… „€€€€ˆ²²… „ˆáˆˆˆ²²… „²²ˆˆáˆˆ… „²²ˆˆáˆˆ… „²²ˆ€€€€… „²²ˆˆáˆˆ… „²²²²²²²… „²²²²²²²… „ˆáˆˆˆáˆ… „ˆáˆˆˆ„€… „áˆˆˆ²²²… „ˆáˆˆ²²²… „ˆáˆˆˆáˆ… „ˆáˆˆˆ„€…  á„²²²²²… „ˆáˆˆˆ„²… „²ˆˆáˆˆˆ…                                    ",
   /* ---------------------fulls----------- ----------------lefts------------------ -----------------rights---------------- -------tops-------- ------bottoms------ -------verts------- -------horzs------- ------corners------ --med-- -thin- thinr -sml- tiny mi */
   "ƒ€€‰€‰€€‚ ƒ€€‰€‰€€‚ ƒ€€‰€‰€€‚ ƒ€€‰€‰€€‚ ƒ€‰‰€‰²²‚ ƒ€‰‰€‰²²‚ ƒ€‰‰€‰²²‚ ƒ€‰‰€‰²²‚ ƒ²²‰€‰‰€‚ ƒ²²‰€‰‰€‚ ƒ²²‰€‰‰€‚ ƒ²²‰€‰‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ€‰€‰²²²‚ ƒ€‰‰‰²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²‰€€‰€‰‚ ƒ²²²²²‚á   áƒ²²²²²‚ ƒ€‰€‰²‚ ƒ‰€‰²‚ ƒ‰€‰‚ ƒ‰€‰‚ ƒ‰‰‚ á· ",
   "‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽ†  Œ ‡†  Œ ‡ŽŽ†  Œ ‡ŽŽ†  Œ Œ  ‡ŽŽŽŽ† Œ  ‡† Œ  ‡ŽŽ† Œ  ‡ŽŽ† ‡ŽŽŽŽŽŽŽ† ‡† Œ       Œ Œ       Œ ‡ŽŽŽ†   Œ ‡Ž†   Œ Œ       Œ Œ       Œ Œ ‡ŽŽŽŽŽ† Œ     Š²‚ ƒ²Š     Œ ‡ŽŽŽ† Œ ‡ŽŽ† Œ ‡ŽŽ†Œ ‡ŽŽ†Œ ‡ŽŽŒ    ",
   "‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽŽŽ†‡ ‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽ†  Œ ‡†  Œ ‡ŽŽ†  Œ ‡ŽŽ†  Œ Œ  ‡ŽŽŽŽ† Œ  ‡† Œ  ‡ŽŽ† Œ  ‡ŽŽ† ‡ŽŽŽŽŽŽŽ† ‡† ‡€‰€‰€‰€† ‡€‰€‰€‰€† ‡ŽŽŽ†   Œ ‡Ž†   Œ Œ       Œ Œ       Œ Œ ‡ŽŽŽŽŽ† ‡€€‰€‰† Œ Œ ‡€€‰€‰† ‡ŽŽŽ† Œ ‡ŽŽ† Œ ‡ŽŽ†Œ ‡ŽŽ†Œ „ˆˆ…    ",
   "‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽ†  Œ ‡†  Œ ‡ŽŽ†  Œ ‡ŽŽ†  Œ Œ  ‡ŽŽŽŽ† Œ  ‡† Œ  ‡ŽŽ† Œ  ‡ŽŽ† ‡ˆ€ˆ€ˆ€ˆ† ‡ˆ€ˆ€ˆ€ˆ† ‡ŽŽŽŽŽŽŽ† ‡† ‡ŽŽŽ†   Œ ‡Ž†   Œ ‡ŽŽŽŽŽŽŽ† ‡† Œ ‡ˆ€€ˆˆ† ‡ŽŽŽŽŽ† Œ Œ ‡ŽŽŽŽŽ† ‡ŽŽŽ† Œ ‡ŽŽ† Œ ‡ŽŽ†Œ „ˆ€ˆ…         ",
   "‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽ†  Œ ‡†  Œ ‡ŽŽ†  Œ ‡ŽŽ†  Œ Œ  ‡ŽŽŽŽ† Œ  ‡† Œ  ‡ŽŽ† Œ  ‡ŽŽ† Œ       Œ Œ       Œ ‡ŽŽŽŽŽŽŽ† ‡† ‡ŽŽŽ†   Œ ‡Ž†   Œ ‡ŽŽŽŽŽŽŽ† ‡† „²Š     Œ ‡ŽŽŽŽŽ† Œ Œ ‡ŽŽŽŽŽ† „€ˆ€ˆ²… „ˆ€ˆ²… „ˆ€ˆ…               ",
   "„€€ˆ€ˆ€€… „€€ˆ€ˆ€€… „€€ˆ€ˆ€€… „€€ˆ€ˆ€€… „€ˆˆ€ˆ²²… „€ˆˆ€ˆ²²… „€ˆˆ€ˆ²²… „€ˆˆ€ˆ²²… „²²ˆ€ˆˆ€… „²²ˆ€ˆˆ€… „²²ˆ€ˆˆ€… „²²ˆ€ˆˆ€… „²²²²²²²… „²²²²²²²… „ˆ€ˆ€ˆ€ˆ… „ˆ€ˆ€ˆ€ˆ… „€ˆ€ˆ²²²… „€ˆˆˆ²²²… „ˆ€ˆ€ˆ€ˆ… „ˆ€ˆ€ˆ€ˆ…  á„²²²²²… „ˆ€€ˆˆˆ²… „²ˆˆ€€ˆˆ…                                    ",
   /* ---------------fulls----------------- ----------------lefts------------------ -----------------rights---------------- -------tops-------- ------bottoms------ -------verts------- -------horzs------- ------corners------ --med-- -thin  thinr -sml- tiny mi */
};



static const char mayanv       [LEN_HUND][400] = {
   /* -----parts of speech-------  --------right fulls--------- ---------right halves-------- ---------left fulls--------- ---------left halves---------- --------bottom fulls-------- --------bottom halves--------- ----------top fulls--------- ----------top halves---------- -----------------quarters-------------- -----------corners----------- --med-- -thin  thinr -sml- tiny mi */
   "ƒ²²²‰€€€‚ ƒ²²²‰‚ ƒ²²²²²²²‚ ƒ²²²²²‰€‚ ƒ²²²²²‰€‚ ƒ²²²²²‰‚ ƒ²²²²²‰‚ ƒ²²²²²‰‚ ƒ²²²²²‰‚ ƒ€‰²²²²²‚ ƒ€‰²²²²²‚ ƒ‰²²²²²‚ ƒ‰²²²²²‚ ƒ‰²²²²²‚ ƒ‰²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ€‰‰€‚ ƒœœ‰€‰œœ‚ ƒ‰€‰‚ ƒ€‰‚ ƒ‰€‚ ƒœœ‚ ƒœœ‚ ƒ‚ ƒ‚ ƒ²²²²‰‚ ƒ²²²²²²²‚ ƒ‚ƒ‚ ƒ²²²²²²²‚ ƒ€‰²²²²²‚ ƒ‰‚á   áƒ‰‚ ƒ²²²²‚ ƒ²²²‚ ƒ²²²‚ ƒ²²²‚ ƒ²²‚ ·x ",
   "Œ   ž   † Œ   ž²²²Ÿ Œ       Œ Œ     ž † Œ     ‡ ž Œ     ž Ÿ Œ     Ÿ Ÿ Œ     ž ž Œ     ž Ÿ ‡ Ÿ     Œ Ÿ †     Œ ž Ÿ     Œ ž Ÿ     Œ Ÿ Ÿ     Œ ž ž     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ‡œœŠ€Šœœ† ‡ˆ€ˆ€ˆ€ˆ† ‡œœˆ€ˆœœ† ‡œœŠ€Šœœ† ‡ˆ€Š€Š€ˆ† ‡œœŠ€Šœœ† Œ    Ÿ²²Ÿ Œ       Œ ž  Ÿž   Ÿ Œ       Œ ž Œ     Œ ‡œœ‰œœŠ‚ ƒ€Šœœ‰œœ† Œ     Ÿ Œ    Ÿ Œ   ž Œ   ž Œ  ž    ",
   "Œ   ‡ Œ Ÿ Œ   „œœœ† Œ       Œ Œ     Š Ÿ Œ     ž † Œ     Š † Œ     ˆ‰… Œ     ˆ‰… Œ     ˆ‰… ž Š     Œ ‡ Ÿ     Œ ‡ Š     Œ „‰ˆ     Œ „‰ˆ     Œ „‰ˆ     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ    Šœœ… Œ       Œ ‡œœŠŠœœœ† Œ       Œ ‡€Œ     Œ Œ     Œ Ÿ ž Œ     Œ Œ    €† Œ   €† Œ   † Œ   ž „²²…    ",
   "Œ   ‡ Œ Ÿ Œ       Œ Œ   ƒ† Œ     Š Ÿ Œ     ž † Œ     Š † Œ     ‰ˆ‚ Œ     ‰ˆ‚ Œ     ‰ˆ‚ ž Š     Œ ‡ Ÿ     Œ ‡ Š     Œ ƒˆ‰     Œ ƒˆ‰     Œ ƒˆ‰     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ    Š‚ Œ       Œ Œ       Œ Œ       Œ ž Œ     Œ Œ     Œ€† ‡€Œ     Œ Œ     Ÿ Œ    Ÿ Œ   ž „²²²…         ",
   "Œ   ž   † Œ       Œ Œ   ž²²²Ÿ Œ     ž † Œ     ‡ ž Œ     ž Ÿ Œ     ž Ÿ Œ     ž ž Œ     ž Ÿ ‡ Ÿ     Œ Ÿ †     Œ ž Ÿ     Œ ž Ÿ     Œ Ÿ Ÿ     Œ ž ž     Œ ‡Š€Š† ‡‰€‰€‰€‰† ‡‰€‰† ‡Š€Š† ‡Š€Š† ‡œœŠ€Šœœ† Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ    Ÿ²²Ÿ Œ       Œ Œ       Œ Œ       Œ „€Š‰† Œ     Œ Ÿ ž Œ     Œ „²²²²œ… „²²²œ… „²²²…               ",
   "„²²²ˆ²²²… „²²²²²²²… „²²²ˆœœœ… „²²²²²ˆ€… „²²²²²ˆ€… „²²²²²ˆœ… „²²²²²ˆœ… „²²²²²ˆœ… „²²²²²ˆœ… „€ˆ²²²²²… „€ˆ²²²²²… „œˆ²²²²²… „œˆ²²²²²… „œˆ²²²²²… „œˆ²²²²²… „€ˆœœœˆ€… „ˆ€ˆ… „œœˆ€ˆœœ… „œœ… „œœ… „… „… „œœ… „œœ… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²ˆœœ… „²²²²²²²… „²²²²²²²… „²²²²²²²…  á„œœˆœœ… „²²²²²ˆœ… „€ˆ²²²²²…                                    ",
   "ƒ²²²‰€‰€‚ ƒ²²²‰€‰€‚ ƒ²²²²²²²‚ ƒ²²²²²‰€‚ ƒ²²²²²‰€‚ ƒ²²²²²‰€‚ ƒ²²²²²‰€‚ ƒ²²²²²‰€‚ ƒ€‰²²²²²‚ ƒ€‰²²²²²‚ ƒ€‰²²²²²‚ ƒ€‰²²²²²‚ ƒ€‰²²²²²‚ ƒ€‰²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰‚ ƒ‰€‚ ƒ€‰‚ ƒ‰€‚ ƒ€‰‚ ƒ‰€‚ ƒ²²²²²‰²‚ ƒ²²²²‰€€‚ ƒ²²²²²²²‚ ƒ€€‚ƒ€‰€‚ ƒ²²²²²²²‚ ƒ€‰²²²²²‚ ƒ€‰€‰€‚á   áƒ€‰€‰€‚ ƒ²²²²²‚ ƒ²²²€‚ ƒ²²²‰ ƒ²²²‰ ƒ²²‰ ·x ",
   "Œ   ‡€Š€† Œ   ‡€Š€† Œ       Œ Œ     ‡€† Œ     …ƒ† Œ     ‰ƒ† Œ     ‡€† Œ     …ƒ† Œ     ‰ƒ† ‡€†     Œ ‡…ƒ     Œ ‡…ˆ     Œ ‡€†     Œ ‡‚„     Œ ‡‚„     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ‡€Š€Š€Š€† ‡…‡…‡…‡… †…†…†…†…† ‡€ŠŠ€ŠŠ€† „†„€…‡… …†„€…‡„ Œ    ‡€€† Œ       Œ ‡€€†‡€Š€† Œ       Œ ‡€Œ     Œ ‡€ˆ€ˆ€Š€‚ ƒ€Š€ˆ€ˆ€† Œ    €† Œ   €† Œ   ‡ Œ   ‡ Œ  ‡    ",
   "Œ   „€ˆ€… Œ   „€ˆ€† Œ       Œ Œ     Š€† Œ     Š€† Œ     ‰ƒ† Œ     ˆ‰… Œ     ˆ‰… Œ     €‰… ‡€†     Œ ‡€†     Œ ‡…ˆ     Œ „‰ˆ     Œ „‰ˆ     Œ „‰ˆ     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ    Š€€… Œ       Œ ‡€€ŠŠ€ˆ€† Œ       Œ ‡€Œ     Œ Œ     Œ€† ‡€Œ     Œ Œ    €† Œ   €† Œ   ‡ Œ   ‡ „²²ˆ    ",
   "Œ   ƒ€‰€‚ Œ       Œ Œ   ƒ€‰€† Œ     Š€† Œ     …ƒ† Œ     Š€† Œ     ‰ˆ‚ Œ     ‰ˆ‚ Œ     €ˆ‚ ‡€†     Œ ‡…ƒ     Œ ‡€†     Œ ƒˆ‰     Œ ƒˆ‰     Œ ƒˆ‰     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ    Š€‰‚ Œ       Œ Œ       Œ Œ       Œ ‡€Œ     Œ Œ     Œ€† ‡€Œ     Œ Œ    €† Œ   €† Œ   ‡ „²²²ˆ         ",
   "Œ   ‡€Š€† Œ       Œ Œ   ‡€Š€† Œ     ‡€† Œ     …ƒ† Œ     ‰ƒ† Œ     ‡€† Œ     ‚„† Œ     ˆ„† ‡€†     Œ ‡…ƒ     Œ ‡…ˆ     Œ ‡€†     Œ ‡…ƒ     Œ ‡…ƒ     Œ ‡€Š€Š€Š€† ƒ†ƒ†ƒ†ƒ† ‡„‡„‡„‡„ ‡€ŠŠ€ŠŠ€† ƒ†ƒ€‚‡‚ …†ƒ€‚‡„ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ      Œ       Œ Œ       Œ Œ       Œ „€Š€‰€‰€† Œ     Œ€† ‡€Œ     Œ „²²²²€… „²²²€… „²²²ˆ               ",
   "„²²²ˆ€ˆ€… „²²²²²²²… „²²²ˆ€ˆ€… „²²²²²ˆ€… „²²²²²ˆ€… „²²²²²ˆ€… „²²²²²ˆ€… „²²²²²ˆ€… „²²²²²ˆ€… „€ˆ²²²²²… „€ˆ²²²²²… „€ˆ²²²²²… „€ˆ²²²²²… „€ˆ²²²²²… „€ˆ²²²²²… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ… „ˆ€… „€ˆ… „ˆ€… „€ˆ… „ˆ€… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²ˆ€ˆ… „²²²²²²²… „²²²²²²²… „²²²²²²²…  á„€ˆ€ˆ€… „²²²²²ˆ€… „€ˆ²²²²²…                                    ",
   "ƒ²²²‰‰‰‰‚ ƒ²²²‰‰‰‰‚ ƒ²²²²²²²‚ ƒ²²²²²‰‰‚ ƒ²²²²²‰‰‚ ƒ²²²²²²²‚ ƒ²²²²²‰‰‚ ƒ²²²²²‰‰‚ ƒ²²²²²²²‚ ƒ‰‰²²²²²‚ ƒ‰‰²²²²²‚ ƒ²²²²²²²‚ ƒ‰‰²²²²²‚ ƒ‰‰²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ‰‰‰‰‰‰‰‚ ƒ‰‰‰‰‰‰‰‚ ƒ²²²²²²²‚ ƒ‰‰‚ ƒ‰‰‚ ƒ‰‰‚ ƒ‰‰‚ ƒ²²²²²²²‚ ƒ²²²²‰‰‰‚ ƒ²²²²²²²‚ ƒ‰‰‚ƒ‰‰‰‚ ƒ²²²²²²²‚ ƒ‰‰²²²²²‚ ƒ‰‰‰‰‰‚á   áƒ‰‰‰‰‰‚ ƒ²²²²‰‚ ƒ²²²‰‚ ƒ²²²‚ ƒ²²²‚ ƒ²²‚ ·x ",
   "Œ   ‡† Œ   ‡† Œ       Œ Œ     ‡† Œ     ‡Ž† Œ       Œ Œ     ‡† Œ     ‡Ž Œ       Œ ‡†     Œ ‡Ž     Œ Œ       Œ ‡†     Œ ‡Ž     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ‡†‡†‡† ‡ŽŽŽ† Œ       Œ ‡†„€…‡† ‡Ž„€…Ž† Œ       Œ Œ    ‡† Œ       Œ ŒŽŽ†‡ŽŽŽ† Œ       Œ ‡Œ     Œ ‡ŽŽŽŽŽŠ‰‚ ƒ‰ŠŽŽŽŽŽ† Œ    † Œ   † Œ   † Œ   † Œ  †    ",
   "Œ   „ˆˆˆ… Œ   ‡† Œ   ƒ‰‰‰† Œ     Š† Œ     ŠŽ† Œ       Œ Œ     ˆŠ… Œ     ˆŠŽ Œ       Œ ‡†     Œ ‡ŽŽ     Œ Œ       Œ „Šˆ     Œ „ŠŽ     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ    Šˆˆ… Œ       Œ ‡ˆˆŠŠ€ˆˆ† Œ       Œ ‡Œ     Œ Œ     Œ† ‡Œ     Œ Œ    † Œ   † Œ   † Œ   † „²²…    ",
   "Œ   ƒ‰‰‰‚ Œ   „ˆˆˆ† Œ   ‡† Œ     Š† Œ     ŠŽ† Œ       Œ Œ     ‰Š‚ Œ     ‰Š Œ       Œ ‡†     Œ ‡Ž     Œ Œ       Œ ƒŠ‰     Œ ƒŠ     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ    Š‰‰‚ Œ       Œ Œ       Œ Œ       Œ ‡Œ     Œ Œ     Œ† ‡Œ     Œ Œ    † Œ   † Œ   † „²²²…         ",
   "Œ   ‡† Œ       Œ Œ   ‡† Œ     ‡† Œ     ‡Ž† Œ       Œ Œ     ‡Ž† Œ     ‡Ž Œ       Œ ‡†     Œ ‡ŽŽ     Œ Œ       Œ ‡Ž†     Œ ‡Ž     Œ Œ       Œ ‡†‡†‡† ‡ŽŽŽŽ† Œ       Œ ‡†ƒ€‚‡† ‡Žƒ€‚Ž† Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ    ‡ŽŽ† Œ       Œ Œ       Œ Œ       Œ „ˆŠ†‡‡† Œ     Œ† ‡Œ     Œ „²²²²ˆ… „²²²ˆ… „²²²…               ",
   "„²²²ˆˆˆˆ… „²²²²²²²… „²²²ˆˆˆˆ… „²²²²²ˆˆ… „²²²²²ˆˆ… „²²²²²²²… „²²²²²ˆˆ… „²²²²²ˆˆ… „²²²²²²²… „ˆˆ²²²²²… „ˆˆ²²²²²… „²²²²²²²… „ˆˆ²²²²²… „ˆˆ²²²²²… „²²²²²²²… „ˆˆˆˆˆˆˆ… „ˆˆˆˆˆˆˆ… „²²²²²²²… „ˆˆ… „ˆˆ… „ˆˆ… „ˆˆ… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²ˆˆˆ… „²²²²²²²… „²²²²²²²… „²²²²²²²…  á„ˆˆˆˆˆ… „²²²²²ˆˆ… „ˆˆ²²²²²…                                    ",
   /* -----parts of speech-------  --------right fulls--------- ---------right halves-------- ---------left fulls--------- ---------left halves---------- --------bottom fulls-------- --------bottom halves--------- ----------top fulls--------- ----------top halves---------- -----------------quarters-------------- -----------corners----------- --med-- -thin  thinr -sml- tiny mi */
   "ƒ²²²‰á‰‰‚ ƒ²²²‰á‰‰‚ ƒ²²²²²²²‚ ƒ²²²²²á‰‚ ƒ²²²²²á‰‚ ƒ²²²²²²²‚ ƒ²²²²²á‰‚ ƒ²²²²²á‰‚ ƒ²²²²²²²‚ ƒ‰á²²²²²‚ ƒ‰á²²²²²‚ ƒ²²²²²²²‚ ƒ‰á²²²²²‚ ƒ‰á²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ‰‚á‰‚á‰‚ ƒ‰‚á‰‚á‰‚ ƒ²²²²²²²‚ ƒá‚‚ ƒá‰‚ ƒá‚‚ ƒá‰‚ ƒ²²²²²²²‚ ƒ²²²²‰á‰‚ ƒ²²²²²²²‚ Šá‰‚ƒá‰‰‚ ƒ²²²²²²²‚ ƒ‰‰²²²²²‚ ƒ‚á‚á‰‚á   áƒ‚á‚á‰‚ ƒ²²²²‰‚ ƒ²²²‰‚ ƒ²²²‚ ƒ²²²‚ ƒ²²á ·x ",
   "Œ   ááá Œ   ááá Œ       Œ Œ     Žá Œ     á Œ       Œ Œ     Žá Œ     á Œ       Œ áŽ     Œ Žá     Œ Œ       Œ áŽ     Œ áŽŽ     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ‡ŽáŽáŽ† ‡ááŽááŽ† Œ       Œ ‡Žá€áŽ† ‡áá€ááŽ† Œ       Œ Œ    áá Œ       Œ áááŽá Œ       Œ áŒ     Œ ‡áŽáŽŠ‰‚ ƒ‰ŠáŽáŽ† Œ    á Œ   á Œ   á Œ   á Œ  á    ",
   "Œ   áŽŽá Œ   áŽáŽ Œ   ‰á‰‰‚ Œ     á Œ     áŽá Œ       Œ Œ     áŠ… Œ     áŠ… Œ       Œ áŽ     Œ áá     Œ Œ       Œ „Šá     Œ „Šá     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ    Šˆˆ… Œ       Œ ‡áˆ…„ˆáˆ† Œ       Œ áŒ     Œ Œ     Œá áŒ     Œ Œ    á Œ   á Œ   á Œ   á „²²á    ",
   "Œ   áŽá Œ   „ˆáˆ… Œ   Žáá Œ     Žá Œ     á Œ       Œ Œ     áŠ‚ Œ     áŠ‚ Œ       Œ áŽ     Œ Žá     Œ Œ       Œ ƒŠá     Œ ƒŠá     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ    Š‰‰‚ Œ       Œ Œ       Œ Œ       Œ áŒ     Œ Œ     Œá áŒ     Œ Œ    á Œ   á Œ   á „²²²…         ",
   "Œ   ááŽá Œ       Œ Œ   ááŽá Œ     áŽá Œ     ŽŽá Œ       Œ Œ     Žá Œ     ŽŽá Œ       Œ ŽáŽ     Œ áá     Œ Œ       Œ áŽ     Œ á     Œ Œ       Œ ŽáŽáŽá ááŽááŽá Œ       Œ Žá€áŽá áá€ááá Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ    áŽá Œ       Œ Œ       Œ Œ       Œ „ˆŠŽáá† Œ     Œá áŒ     Œ „²²²²ˆ… „²²²ˆ… „²²²…               ",
   "„²²²ˆˆáˆ… „²²²²²²²… „²²²„ˆáˆ… „²²²²²áˆ… „²²²²²áˆ… „²²²²²²²… „²²²²²áˆ… „²²²²²áˆ… „²²²²²²²… „ˆá²²²²²… „ˆá²²²²²… „²²²²²²²… „ˆá²²²²²… „ˆá²²²²²… „²²²²²²²… „ˆ…áˆ…áˆ… „ˆ…áˆ…áˆ… „²²²²²²²… „á…… „áˆ… „á…… „áˆ… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²ˆáˆ… „²²²²²²²… „²²²²²²²… „²²²²²²²…  á„áˆ…áˆ… „²²²²²ˆˆ… „ˆˆ²²²²²…                                    ",
   "ƒ²²²‰€‰€‚ ƒ²²²‰€‰€‚ ƒ²²²²²²²‚ ƒ²²²²²‰€‚ ƒ²²²²²‰€‚ ƒ²²²²²²²‚ ƒ²²²²²‰€‚ ƒ²²²²²‰€‚ ƒ²²²²²²²‚ ƒ€‰²²²²²‚ ƒ€‰²²²²²‚ ƒ²²²²²²²‚ ƒ€‰²²²²²‚ ƒ€‰²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ€‰ƒ€‚‰€‚ ƒ€ƒ€€€‚€‚ ƒ²²²²²²²‚ ƒ€‰‚ ƒ‰€‚ ƒ€‰‚ ƒ‰€‚ ƒ²²²²²²²‚ ƒ²²²²‰‰€‚ ƒ²²²²²²²‚ ƒˆ€‚ƒ€ˆ€‚ ƒ²²²²²²²‚ ƒ€‰²²²²²‚ ƒ€ƒ€‚€‚á   áƒ€ƒ€‚€‚ ƒ²²²²‰‚ ƒ²²²‰‚ ƒ²²²‚ ƒ²²²‚ ƒ²²‚ ·x ",
   "Œ   Š– “Š Œ   Š– “Š Œ       Œ Œ      “Š Œ      —Š Œ       Œ Œ      “Š Œ      —Š Œ       Œ Š–      Œ Š’      Œ Œ       Œ Š–      Œ Š’      Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ‡– “Š– “† ‡’ ƒŠ‚ —† Œ       Œ ‡– “€– “† ‡’ Š€Š —† Œ       Œ Œ     “Š Œ       Œ  —†Š’ —Š Œ       Œ  Œ     Œ ‡– Š “Š‰‚ ƒ€Š– Š “Š Œ      Œ     Œ     Œ     Œ       ",
   "Œ   ‡‰‡‰† Œ   „‰‡‰† Œ       Œ Œ     Š‰† Œ     Šˆ† Œ       Œ Œ     ˆŽ… Œ     ˆ‚… Œ       Œ ‡‰†     Œ ‡ˆ†     Œ Œ       Œ „Ž…     Œ „ƒˆ     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ    Šˆ€… Œ       Œ ‡ˆ€ŠŠ€ˆ€† Œ       Œ ‡ŠŒ     Œ Œ     Œ   Œ     Œ Œ    Š† Œ   Š† Œ   † Œ     „²²…    ",
   "Œ   ‡ˆ‡ˆ† Œ       Œ Œ   ƒˆ‡ˆ† Œ     Šˆ† Œ     Š‰† Œ       Œ Œ     ‰‚ Œ     ‰…‚ Œ       Œ ‡ˆ†     Œ ‡‰†     Œ Œ       Œ ƒ‚     Œ ƒ„‰     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ    Š‰€‚ Œ       Œ Œ       Œ Œ       Œ  Œ     Œ Œ     ŒŠ† ‡ŠŒ     Œ Œ      Œ     Œ     „²²²…         ",
   "Œ   Š’ —Š Œ       Œ Œ   Š’ —Š Œ      —Š Œ      “Š Œ       Œ Œ      —Š Œ      “Š Œ       Œ Š’      Œ Š–      Œ Œ       Œ Š’      Œ Š–      Œ Œ       Œ Š’ —Š’ —Š Š– „Š… “Š Œ       Œ Š’ —€’ —Š Š– Š€Š “Š Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ     —Š Œ       Œ Œ       Œ Œ       Œ „€Š —Š’ Š Œ     Œ   Œ     Œ „²²²²ˆ… „²²²ˆ… „²²²…               ",
   "„²²²ˆ€ˆ€… „²²²²²²²… „²²²ˆ€ˆ€… „²²²²²ˆ€… „²²²²²ˆ€… „²²²²²²²… „²²²²²ˆ€… „²²²²²ˆ€… „²²²²²²²… „€ˆ²²²²²… „€ˆ²²²²²… „²²²²²²²… „€ˆ²²²²²… „€ˆ²²²²²… „²²²²²²²… „€ˆ„€…ˆ€… „€„€€€…€… „²²²²²²²… „€ˆ… „ˆ€… „€ˆ… „ˆ€… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²ˆˆ€… „²²²²²²²… „²²²²²²²… „²²²²²²²…  á„€„€…€… „²²²²²ˆˆ… „€ˆ²²²²²…                                    ",
   "ƒ²²²‰‰‰‰‚ ƒ²²²‰‰‰‰‚ ƒ²²²²²²²‚ ƒ²²²²²‰Ž‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²‰Ž‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒŽ‰²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ‰²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒŽŽ€‚€ŽŽ‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒŽŽ‚ ƒŽŽ‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²‰ŽŽ‚ ƒ²²²²²²²‚ ƒŽŽ‚ƒŽŽŽ‚ ƒ²²²²²²²‚ ƒ€‰²²²²²‚ ƒŽŽŽŽŽ‚á   áƒŽŽŽŽŽ‚ ƒ²²²²€‚ ƒ²²²²‚ ƒ²²²ƒ ƒ²²²‚ ƒ²²‚ ·x ",
   "Œ   ŽŽŽŽŽ Œ    ŽŽŽŽ Œ       Ž Œ     ŽŽŽ Œ       Œ Œ       Œ Œ     ŽŽŽ Œ       Œ Œ       Œ ŽŽŽ     Œ Œ       Œ Œ       Œ      Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ‡Ž†Ž†Ž†Ž† Œ       Œ Œ       Œ ‡Ž†Ž€Ž†Ž† Œ       Œ Œ       Œ Œ    ŽŽŽŽ Œ       Œ ‡ŽŽ†‡ŽŽŽ† Œ       Œ ŽŽŒ     Œ ‡ŽŽŽŽŽŠ€‚ ƒ²ŠŽŽŽŽŽ† Œ    ŽŽ Œ   ŽŽ Œ   Ž Œ   Ž Œ  Ž    ",
   "Œ   ŽŽŽŽŽ Œ     ŽŽŽ Œ      ŽŽ Œ     ŽŽŽ Œ       Œ Œ       Œ Œ     €ŠŽ Œ       Œ Œ       Œ ŽŽŽ     Œ Œ       Œ Œ       Œ Š€     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ    Šˆˆ… Œ       Œ ‡ŽŽŠŠŽŽŽ† Œ       Œ ŽŽŒ     Œ Œ     ŒŽŽ ŽŽŒ     Œ Œ    ŽŽ Œ   ŽŽ Œ   Ž Œ   Ž „²²…    ",
   "Œ   ŽŽŽŽŽ Œ      ŽŽ Œ     ŽŽŽ Œ     ŽŽŽ Œ       Œ Œ       Œ Œ     €Š Œ       Œ Œ       Œ ŽŽŽ     Œ Œ       Œ Œ       Œ ŽŠ€     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ    Š‰‰‚ Œ       Œ Œ       Œ Œ       Œ ŽŽŒ     Œ Œ     ŒŽŽ ŽŽŒ     Œ Œ    ŽŽ Œ   ŽŽ Œ   Ž „²²²…         ",
   "Œ   ŽŽŽŽŽ Œ       Ž Œ    ŽŽŽŽ Œ     ŽŽŽ Œ       Œ Œ       Œ Œ      Œ       Œ Œ       Œ ŽŽŽ     Œ Œ       Œ Œ       Œ ŽŽŽ     Œ Œ       Œ Œ       Œ Ž†Ž†Ž†Ž† Œ       Œ Œ       Œ Ž†Ž€Ž† Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ    ŽŽ Œ       Œ Œ       Œ Œ       Œ „€ŠŽ†Ž†Ž† Œ     ŒŽŽ ŽŽŒ     Œ „²²²²€… „²²²²… „²²²…               ",
   "„²²²ˆˆˆˆ… „² ²²²²²… „²²²ˆˆˆˆ… „²²²²²ˆŽ… „²²²²²²²… „²²²²²²²… „²²²²²ˆ… „²²²²²²²… „²²²²²²²… „Žˆ²²²²²… „²²²²²²²… „²²²²²²²… „Žˆ²²²²²… „²²²²²²²… „²²²²²²²… „Ž………€ŽŽ… „²²²²²²²… „²²²²²²²… „ŽŽ… „… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²…  á„ŽŽ€ŽŽ… „²²²²²ˆ€… „²ˆ²²²²²…                                    ",
   /* -----parts of speech-------  --------right fulls--------- ---------right halves-------- ---------left fulls--------- ---------left halves---------- --------bottom fulls-------- --------bottom halves--------- ----------top fulls--------- ----------top halves---------- -----------------quarters-------------- -----------corners----------- --med-- -thin  thinr -sml- tiny mi */
   "ƒ²²²‰€‰€‚ ƒ²²²‰€‰€‚ ƒ²²²²²²²‚ ƒ²²²²²‰‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²‰€‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ‰‰²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ€‰²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ‰‰‰‰‰‰‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ‰‰‚ ƒ‰‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²‰€‰‚ ƒ²²²²²²²‚ ƒ€‰‚ƒ€‰€‚ ƒ²²²²²²²‚ ƒ‰‰²²²²²‚ ƒ‰‰‰‰‰‚á   áƒ‰‰‰‰‰‚ ƒ²²²²‰‚ ƒ²²²‰‚ ƒ²²²‰ ƒ²²²‰ ƒ²²· ·x ",
   "Œ   ‡   † Œ   ‡   † Œ       Œ Œ     ‡ † Œ       Œ Œ       Œ Œ     ˆ‰† Œ       Œ Œ       Œ ‡ †     Œ Œ       Œ Œ       Œ ‡‰ˆ     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ‡ †‡ †‡ † Œ       Œ Œ       Œ ‡ †‡€†‡ † Œ       Œ Œ       Œ Œ    ‡  † Œ       Œ ‡  †‡ ‡ † Œ       Œ ‡‰Œ     Œ ‡ † ‡ Š‰‚ ƒ‰Š † ‡ † Œ    ‰† Œ   ‰† Œ   ‰ Œ   ‰ Œ  Š    ",
   "Œ   ‡€‰€† Œ   ‡€‰€† Œ   ƒ€‰€† Œ     Š‰† Œ       Œ Œ       Œ Œ     ‰Š… Œ       Œ Œ       Œ ‡‰†     Œ Œ       Œ Œ       Œ „Š‰     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ    Š€ˆ… Œ       Œ ‡€ˆŠŠ€ˆ€† Œ       Œ  Œ     Œ Œ     Œ‰† ‡‰Œ     Œ Œ      Œ     Œ    Œ   ˆ „²²·    ",
   "Œ   ‡€ˆ€† Œ   „€ˆ€† Œ   ‡€ˆ€† Œ     Šˆ† Œ       Œ Œ       Œ Œ     ˆŠ‚ Œ       Œ Œ       Œ ‡ˆ†     Œ Œ       Œ Œ       Œ ƒŠˆ     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ    Š€‰‚ Œ       Œ Œ       Œ Œ       Œ ‡ˆŒ     Œ Œ     Œ   Œ     Œ Œ    ˆ† Œ   ˆ† Œ   ˆ „²²²ˆ         ",
   "Œ   ‡   † Œ       Œ Œ   ‡   † Œ     ‡ † Œ       Œ Œ       Œ Œ     ‰ˆ† Œ       Œ Œ       Œ ‡ †     Œ Œ       Œ Œ       Œ ‡ˆ‰     Œ Œ       Œ Œ       Œ ‡ †‡ †‡ † Œ       Œ Œ       Œ ‡ †‡€†‡ † Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ    ‡  † Œ       Œ Œ       Œ Œ       Œ „ˆŠ † ‡ † Œ     Œˆ† ‡ˆŒ     Œ „²²²²ˆ… „²²²ˆ… „²²²ˆ               ",
   "„²²²ˆ€ˆ€… „²²²²²²²… „²²²ˆ€ˆ€… „²²²²²ˆˆ… „²²²²²²²… „²²²²²²²… „²²²²²ˆ€… „²²²²²²²… „²²²²²²²… „ˆˆ²²²²²… „²²²²²²²… „²²²²²²²… „€ˆ²²²²²… „²²²²²²²… „²²²²²²²… „ˆˆˆˆˆˆˆ… „²²²²²²²… „²²²²²²²… „ˆˆ… „ˆˆ… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²ˆ€ˆ… „²²²²²²²… „²²²²²²²… „²²²²²²²…  á„ˆˆˆˆˆ… „²²²²²ˆˆ… „ˆˆ²²²²²…                                    ",
   "ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²‰²²‚ ƒ²²²²²²²‚ ƒ²²‚ƒ²²²‚ ƒ²²²²²²²‚ ƒ²‰²²²²²‚ ƒ²²²²²‚á   áƒ²²²²²‚ ƒ²²²²²‚ ƒ²²²²‚ ƒ²²²‚ ƒ²²²‚ ƒ²²‚ ·x ",
   "Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ    Œ  Œ Œ       Œ Œ  ŒŒ   Œ Œ       Œ Œ Œ     Œ ‡²²²²²Š²‚ ƒ²Š²²²²²† Œ     Œ Œ    Œ Œ   Œ Œ   Œ Œ  Œ    ",
   "Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ    Š²²… Œ       Œ ‡²²ŠŠ²²²† Œ       Œ Œ Œ     Œ Œ     Œ Œ Œ Œ     Œ Œ     Œ Œ    Œ Œ   Œ Œ   Œ „²²…    ",
   "Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ    Š²²‚ Œ       Œ Œ       Œ Œ       Œ Œ Œ     Œ Œ     Œ Œ Œ Œ     Œ Œ     Œ Œ    Œ Œ   Œ „²²²…         ",
   "Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ    Œ  Œ Œ       Œ Œ       Œ Œ       Œ „²Š²²²²²† Œ     Œ Œ Œ Œ     Œ „²²²²²… „²²²²… „²²²…               ",
   "„²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²ˆ²²… „²²²²²²²… „²²²²²²²… „²²²²²²²…  á„²²²²²… „²²²²²ˆ²… „²ˆ²²²²²…                                    ",
   /* -----parts of speech-------  --------right fulls--------- ---------right halves-------- ---------left fulls--------- ---------left halves---------- --------bottom fulls-------- --------bottom halves--------- ----------top fulls--------- ----------top halves---------- -----------------quarters-------------- ------corners------ --med-- -thin  thinr -sml- tiny mi */
};


static const char mayann       [LEN_TERSE][LEN_FULL] = {
   "ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ",
   "‡ · · · † ‡ · Ž† ‡ · · · † ‡ · Ž† ‡ · · · † ‡ · Ž† ‡ · · · † ‡ · Ž† ‡ŽŽŽŽ · † ‡ŽŽŽŽ† ‡ŽŽŽŽ · † ‡ŽŽŽŽ† ‡ŽŽŽŽ · † ‡ŽŽŽŽ† ‡ŽŽŽŽ · † ‡ŽŽŽŽ† ",
   "‡       † ‡ · „ €ˆ† ‡ ·   · † ‡ · ƒ ‰ˆ† ‡ ·   · † ‡ · ƒ €ˆ† ‡ ·   · † ‡ · ƒ ‰ˆ† ‡ˆ€ … · † ‡ˆ€ € €ˆ† ‡ˆ€ ‚ · † ‡ˆ€ ‰ ‰ˆ† ‡ˆ‰ ‚ · † ‡ˆ‰ ‰ €ˆ† ‡ˆ‰ ‚ · † ‡ˆ€ ‰ €ˆ† ",
   "‡       † ‡ ·   · † ‡ · ƒ ‰€† ‡ · ƒ ‰ˆ† ‡€‰ ‚ · † ‡€‰ ‚ · † ‡€‰ ‰ ‰€† ‡€‰ ‰ ‰ˆ† ‡ ·   · † ‡ ·   · † ‡ · ƒ ‰€† ‡ · ƒ ‰ˆ† ‡ˆ‰ ‚ · † ‡ˆ‰ ‚ · † ‡ˆ‰ ‰ ‰€† ‡ˆ€ ‰ €ˆ† ",
   "‡ · · · † ‡ · · · † ‡ · ŽŽŽŽ† ‡ · ŽŽŽŽ† ‡Ž · † ‡Ž · † ‡ŽŽŽŽ† ‡ŽŽŽŽ† ‡ · · · † ‡ · · · † ‡ · ŽŽŽŽ† ‡ · ŽŽŽŽ† ‡Ž · † ‡Ž · † ‡ŽŽŽŽ† ‡ŽŽŽŽ† ",
   "„€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… ",
};

static const char mayanp       [LEN_PATH][LEN_FULL] = {
   " Ð  ƒ€€€‚  Ñ  ƒ€€€‚  Ò  ƒ€€Ž‚  +  ƒ€€‰‚  !  ƒ€€€‚ ƒ²²²²²²²‚ ƒ²²²²²‰²‚ ƒ‰‰²²‚ ƒ²²²²²‰²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²‰²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²‰²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ",
   "  ƒá‰‰‚€†   ƒá‰‰‚—Š   ƒá‰‰‚ŽŽ   ƒá‰‰‚†   ƒá‰‰‚ ž Œ       Œ Œ    † Œ     Œ Œ     Œ Œ Œ       Œ Œ       Œ Œ Œ     Œ Œ       Œ Œ       Œ Œ Œ     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "  ááá€†   áááˆ†   áááŽŽ   ááá†   ááá ž Œ       Œ Œ   † Œ ‡œœœ…  Œ Œ     „‰… Œ       Œ Œ       Œ Œ Œ     Œ Œ       Œ Œ       Œ „‰…     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "  áŽáŽ€†   áŽáŽ‰†   áŽáŽŽŽ   áŽáŽ†   áŽáŽ ž Œ       Œ Œ  † Œ Œ      Œ Œ     ƒˆ‚ Œ       Œ Œ       Œ Œ Œ     Œ Œ       Œ Œ       Œ ƒˆ‚     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "  „ˆáˆ…€†   „ˆáˆ…“Š   „ˆáˆ…ŽŽ   „ˆáˆ…†   „ˆáˆ… ž Œ       Œ Œ † Œ Œ      Œ Œ     Œ Œ Œ       Œ Œ       Œ Œ Œ     Œ Œ       Œ Œ       Œ Œ Œ     Œ Œ       Œ Œ       Œ ‡²²²²²²²† Œ       Œ Œ       Œ ",
   "    „€€€…     „€€€…     „€€Ž…     „€€ˆ…     „€€€… „²²²²²²²… „ˆˆˆˆˆˆ²… „²²²²ˆ²²… „²²²²²ˆ²… „²²²²²²²… „²²²²²²²… „²ˆ²²²²²… „²²²²²²²… „²²²²²²²… „²ˆ²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… ",
   "     ƒ²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²‚     ƒ²²²²²²‚ ƒ²²‰€‰²²‚ ƒ²²²‰€‰€‚ ƒ€‰€‰²²‚    ƒ²²²‰€‚ ƒ€‰²²²²²‚ ƒ²²²²²‰€‚ ƒ€‰²²‚    ƒ²²‰€‰²²‚ ƒ²²²‚       ƒ²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ",
   "   ƒ²…ƒ€† ‡€‚     Œ Œ   ƒ€‚ Œ Œ ƒ€‚„²‚  ƒ…      Œ Œ  ‡€†  Œ Œ   ‡€Š€… „€Š€†  Œ    Œ ƒ€Š€… „€Š€‚   Œ Œ   ƒ€Š€… „€Š€‚„²²‚ Œ  „€…  Œ Œ ƒ€†     ƒ²…   ƒ€† Œ       Œ Œ       Œ Œ       Œ ",
   "ƒ²²…ƒ€Š€† ‡€Š€‚   Œ „‚  „€Š€† ‡€Š€…  Œ  Œ ƒ€‰€‚ Œ Œ  „€…  Œ Œ   ‡€†     ‡€†  „‚   Œ ‡€†     ‡€† ƒ²… Œ ƒ€Š€…     „€Š€‚ Œ Œ  ƒ€‚ƒ€† Œ „€Š€‚   Œ   ƒ€Š€… Œ       Œ Œ       Œ Œ       Œ ",
   "Œ   „€Š€† ‡€Š€…ƒ²²…  Œ  ƒ€Š€† ‡€Š€‚  „‚ Œ „€ˆ€… Œ „²²‚    Œ „‚  ‡€†     ‡€†   Œ ƒ²… ‡€†     ‡€† Œ   Œ „€Š€‚     ƒ€Š€… Œ Œ  „€…„€† Œ   „€Š€‚ Œ ƒ€Š€…   Œ       Œ Œ       Œ Œ       Œ ",
   "Œ     „€† ‡€…ƒ²…     „‚ „€… Œ Œ „€…   Œ Œ  ƒ²²²²…    Œ    Œ  Œ  ‡€Š€‚ ƒ€Š€†   Œ Œ   „€Š€‚ ƒ€Š€… Œ   „²²‚„€Š€‚ ƒ€Š€…   Œ Œ  ƒ€‚  Œ „²‚   „€† Œ „€†     ‡²²‰€‰²²† Œ       Œ Œ       Œ ",
   "„²²²²²²²… „²²…        „²²²²²… „²²²²²²²… „²²…         „²²²²…  „²²ˆ€ˆ€… „²ˆ²ˆ²²²… „²²²²²ˆ€… „€ˆ²²²…      „²²ˆ€… „€ˆ²²²²²… „²²ˆ€ˆ²²…   „²²²²²… „²²²…     „²²… „²²… „²²²²²²²… „²²²²²²²… ",
};




/*====================------------------------------------====================*/
/*===----                      gathering data                          ----===*/
/*====================------------------------------------====================*/
static void      o___DATA_______________o (void) {;}

char
yascii_mayan__cdata     (char a_size, char a_char, char a_orient, char a_variant, short *r_left, short *r_topp, char *r_wide, char *r_tall)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char       *x_valid     = YSTR_MAYANC;
   char       *p           = NULL;
   char        n           =    0;
   short       x_pos       =    0;
   short       y_pos       =    0;
   char        oc, w, t;
   /*---(begin)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   DEBUG_YASCII   yLOG_complex ("args"      , "%c, %c %c %c", a_size, a_char, a_orient, a_variant);
   /*---(default)------------------------*/
   if (r_left != NULL)  *r_left = 0;
   if (r_topp != NULL)  *r_topp = 0;
   if (r_wide != NULL)  *r_wide = 0;
   if (r_tall != NULL)  *r_tall = 0;
   /*---(defense)------------------------*/
   DEBUG_YASCII   yLOG_value   ("a_char"    , a_char);
   --rce;  if (a_char == 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_char    ("a_char"    , a_char);
   p = strchr (x_valid, a_char);
   DEBUG_YASCII   yLOG_point   ("p"         , p);
   --rce;  if (p == NULL) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(prepare)------------------------*/
   n = p - x_valid;
   /*---(orient)-------------------------*/
   DEBUG_YASCII   yLOG_char    ("a_orient"  , a_orient);
   switch (a_orient) {
   case '´' : oc =  0;  w =  9;  t = 6;  break;
   case 'Ö' : oc =  4;  w =  9;  t = 6;  break;
   case '×' : oc =  8;  w =  9;  t = 6;  break;
   case 'Õ' : oc = 12;  w =  9;  t = 6;  break;
   case 'Ô' : oc = 14;  w =  9;  t = 6;  break;
   case '' : oc = 16;  w =  9;  t = 6;  break;
   case '€' : oc = 18;  w =  9;  t = 6;  break;
   case '„' : oc = 20;  w =  9;  t = 6;  break;
   default  : oc =  4;  w =  9;  t = 6;  break;
   }
   /*---(variant)------------------------*/
   DEBUG_YASCII   yLOG_char    ("a_variant" , a_variant);
   switch (a_variant) {
   case '0' :                            break;
   case '1' : oc += 1;                   break;
   case '2' : if (strchr ("ÕÔ€" , a_orient) == NULL)  oc += 2;                   break;
   case '3' : if (strchr ("ÕÔ€„", a_orient) == NULL)  oc += 3; else oc += 1;     break;
   default  :                            break;
   }
   /*---(coordinates)--------------------*/
   y_pos = (n * 6);
   x_pos = (oc * 10);
   /*---(size)---------------------------*/
   switch (a_size) {
   case 'm' : x_pos = 230;  w = 7;  t = 5;  break;
   case 'h' : x_pos = 238;  w = 6;  t = 5;  break;
   case 'r' : x_pos = 245;  w = 5;  t = 5;  break;
   case 's' : x_pos = 251;  w = 5;  t = 4;  break;
   case 't' : x_pos = 257;  w = 4;  t = 3;  break;
   case 'u' : x_pos = 262;  w = 2;  t = 1;  break;
   }
   DEBUG_YASCII   yLOG_complex ("coords"    , "%3dx, %3dy (%2dn, %2doc) %2dw, %2dh", x_pos, y_pos, n, oc, w, t);
   /*---(save-back)----------------------*/
   if (r_left != NULL)  *r_left = x_pos;
   if (r_topp != NULL)  *r_topp = y_pos;
   if (r_wide != NULL)  *r_wide = w;
   if (r_tall != NULL)  *r_tall = t;
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit   (__FUNCTION__);
   return 0;
}


char
yascii_mayan__vdata     (char a_size, char a_char, char a_part, char a_orient, char a_variant, short *r_left, short *r_topp, char *r_wide, char *r_tall, char *r_xoff, char *r_yoff)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char       *x_valid     = YSTR_MAYANV;
   char       *p           = NULL;
   char        n           =    0;
   short       x_pos       =    0;
   short       y_pos       =    0;
   char        o, w, t;
   char        xo          =    0;
   char        yo          =    0;
   /*---(begin)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   DEBUG_YASCII   yLOG_complex ("args"      , "%c, %c %c %c", a_size, a_char, a_orient, a_variant);
   /*---(default)------------------------*/
   if (r_left != NULL)  *r_left = 0;
   if (r_topp != NULL)  *r_topp = 0;
   if (r_wide != NULL)  *r_wide = 0;
   if (r_tall != NULL)  *r_tall = 0;
   if (r_xoff != NULL)  *r_xoff = 0;
   if (r_yoff != NULL)  *r_yoff = 0;
   /*---(defense)------------------------*/
   DEBUG_YASCII   yLOG_value   ("a_char"    , a_char);
   --rce;  if (a_char == 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_char    ("a_char"    , a_char);
   p = strchr (x_valid, a_char);
   DEBUG_YASCII   yLOG_point   ("p"         , p);
   --rce;  if (p == NULL) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(prepare)------------------------*/
   n = p - x_valid;
   /*---(orient)-------------------------*/
   DEBUG_YASCII   yLOG_char    ("a_orient"  , a_orient);
   switch (a_orient) {
   case '´' :
      o =  0;  w =  9;  t = 6;
      break;
   case 'Ö' :
      o =  3;  w =  3;  t = 6;  xo = 6;
      if (a_part == 'a')  { o += 3;  t = 3;          }
      if (a_part == 'b')  { o += 3;  t = 3;  yo = 3; }
      break;
   case '×' :
      o =  9;  w =  3;  t = 6;
      if (a_part == 'a')  { o += 3;  t = 3;          }
      if (a_part == 'b')  { o += 3;  t = 3;  yo = 3; }
      break;
   case 'Õ' :
      o = 15;  w =  9;  t = 2;  yo = 4;
      if (a_part == 'a')  { o += 3;  w = 5;          }
      if (a_part == 'b')  { o += 3;  w = 4;  xo = 5; }
      break;
   case 'Ô' :
      o = 21;  w =  9;  t = 2;
      if (a_part == 'a')  { o += 3;  w = 5;          }
      if (a_part == 'b')  { o += 3;  w = 4;  xo = 5; }
      break;
   case '' :
      o = 27;  w =  4;  t = 3;  xo = 5;
      if (a_part == 'b')  { yo = 3; }
      break;
   case '€' :
      o = 29;  t = 3;
      if (a_part == 'a')  { w = 4;   }
      if (a_part == 'b')  { w = 5;  xo = 4; }
      break;
   case '„' :
      switch (a_variant) {
      case '1'  : o = 32; if (a_part == 'a')  { w = 7;  t = 2;         }  if (a_part == 'b')  { w = 2;  t = 5;  xo = 7;  yo = 1; }  break;
      case '2'  : o = 33; if (a_part == 'a')  { w = 7;  t = 2; xo = 2; }  if (a_part == 'b')  { w = 2;  t = 5;  yo = 1;          }  break;
      default   : o = 31; if (a_part == 'a')  { w = 2;  t = 5;         }  if (a_part == 'b')  { w = 7;  t = 2;  yo = 4;  xo = 2; }  break;
      }
      break;
   default  :
      o =  3;  w =  3;  t = 6;  xo = 6;
      break;
   }
   /*---(variant)------------------------*/
   DEBUG_YASCII   yLOG_char    ("a_variant" , a_variant);
   if        (strchr ("„", a_orient) != NULL) {
      ;  /* already dealt with */
   } else if (strchr ("€", a_orient) != NULL && a_variant > 1) {
      a_variant = '0';
   } else {
      switch (a_variant) {
      case '0' : break;
      case '1' : if (strchr ("uf"   , a_char) == NULL)  o += 1;   break;
      case '2' : if (strchr ("eovuf", a_char) == NULL)  o += 2;   break;
      default  : break;
      }
   }
   DEBUG_YASCII   yLOG_char    ("a_variant" , a_variant);
   /*---(coordinates)--------------------*/
   y_pos = (n * 6)  + yo;
   x_pos = (o * 10) + xo;
   /*---(size)---------------------------*/
   switch (a_size) {
   case 'm' : x_pos = 335;  w = 2;  t = 5;  xo = 5;  yo = 0;  break;
   case 'h' : x_pos = 342;  w = 2;  t = 5;  xo = 5;  yo = 0;  break;
   case 'r' : x_pos = 349;  w = 1;  t = 5;  xo = 4;  yo = 0;  break;
   case 's' : x_pos = 355;  w = 1;  t = 4;  xo = 4;  yo = 0;  break;
   case 't' : x_pos = 360;  w = 1;  t = 3;  xo = 3;  yo = 0;  break;
   case 'u' : x_pos = 363;  w = 1;  t = 1;  xo = 1;  yo = 0;  break;
   }
   DEBUG_YASCII   yLOG_complex ("coords"    , "%3dx, %3dy (%2dn, %2doc) %2dw, %2dh", x_pos, y_pos, n, o, w, t);
   /*---(save-back)----------------------*/
   if (r_left != NULL)  *r_left = x_pos;
   if (r_topp != NULL)  *r_topp = y_pos;
   if (r_wide != NULL)  *r_wide = w;
   if (r_tall != NULL)  *r_tall = t;
   if (r_xoff != NULL)  *r_xoff = xo;
   if (r_yoff != NULL)  *r_yoff = yo;
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit   (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                       display driver                         ----===*/
/*====================------------------------------------====================*/
static void      o___DISPLAY____________o (void) {;}

char
yascii_mayan__display   (short x, short y, char a_type, short a_left, short a_topp, char a_wide, char a_tall, char a_mode)
{
   /*---(locals)-----------+-----+-----+-*/
   char        i           =    0;
   char        t           [LEN_LABEL] = "";
   /*---(clear working)------------------*/
   for (i = 0; i < MAX_HEIGHT; ++i)   strcpy (g_working [i], "");
   /*---(display)------------------------*/
   for (i = 0; i < a_tall; ++i) {
      switch (a_type) {
      case 'c' : sprintf (t, "%*.*s", a_wide, a_wide, mayanc [a_topp + i] + a_left);  break;
      case 'v' : sprintf (t, "%*.*s", a_wide, a_wide, mayanv [a_topp + i] + a_left);  break;
      case '#' : sprintf (t, "%*.*s", a_wide, a_wide, mayann [a_topp + i] + a_left);  break;
      case 'p' : sprintf (t, "%*.*s", a_wide, a_wide, mayanp [a_topp + i] + a_left);  break;
      }
      ystrlcpy (g_working [i], t, LEN_DESC);
      if (e_displayer != NULL)  e_displayer (x, y + i, t, a_mode);
   }
   return 0;
}



/*====================------------------------------------====================*/
/*===----                       display driver                         ----===*/
/*====================------------------------------------====================*/
static void      o___GLYPHS_____________o (void) {;}

char
yascii_mayan__normal    (char a_orient, char a_cons, char a_cvariant, char a_vowel, char a_vvariant, int x, int y, char a_mode)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char       *x_valid     = "Ö×ÕÔ";
   short       x_left, x_topp;
   char        x_wide, x_tall;
   char        x_xoff, x_yoff;
   /*---(begin)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   DEBUG_YASCII   yLOG_complex ("args"      , "%c, %c %c, %c %c, %3d %3d, %c", a_orient, a_cons, a_cvariant, a_vowel, a_vvariant, x, y, a_mode);
   /*---(defense)------------------------*/
   if (a_orient == '·')  a_orient = 'Ö';
   if (a_orient == ' ')  a_orient = 'Ö';
   DEBUG_YASCII   yLOG_char    ("a_orient"  , a_orient);
   DEBUG_YASCII   yLOG_info    ("x_valid"   , x_valid);
   --rce;  if (strchr (x_valid, a_orient) == NULL) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_char    ("a_cons"    , a_cons);
   --rce;  if (a_cons == 'x') {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(consonant)----------------------*/
   rc = yascii_mayan__cdata   ('-', a_cons, a_orient, a_cvariant, &x_left, &x_topp, &x_wide, &x_tall);
   DEBUG_YASCII   yLOG_value   ("cdata"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   yascii_mayan__display (x + s_left, y + s_topp, 'c', x_left, x_topp, x_wide, x_tall, a_mode);
   /*---(vowel)--------------------------*/
   rc = yascii_mayan__vdata   ('-', a_vowel, '-', a_orient, a_vvariant, &x_left, &x_topp, &x_wide, &x_tall, &x_xoff, &x_yoff);
   DEBUG_YASCII   yLOG_value   ("vdata"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   yascii_mayan__display (x + s_left + x_xoff, y + s_topp + x_yoff, 'v', x_left, x_topp, x_wide, x_tall, a_mode);
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yascii_mayan__number    (char a_one, char a_two, int x, int y, char a_mode)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char       *x_hex       = "0123456789ABCDEF";
   char       *p           = NULL;
   char        n           =    0;
   char        v           =    0;
   uchar       x_dec       =    0;
   char        t           [LEN_TERSE] = "";
   /*---(begin)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   DEBUG_YASCII   yLOG_complex ("args"      , "%c %c, %3d %3d, %c", a_one, a_two, x, y, a_mode);
   /*---(from number)--------------------*/
   if (a_one == '·') {
      x_dec = a_two;
      ystrl4hex (x_dec, t, 1, 'q', LEN_TERSE);
      a_one = t [0];
      a_two = t [1];
   }
   /*---(lesser)-------------------------*/
   p = strchr (x_hex, toupper (a_two));
   DEBUG_YASCII   yLOG_point   ("two"       , p);
   --rce;  if (p == NULL) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   n = p - x_hex;
   DEBUG_YASCII   yLOG_value   ("n"         , n);
   yascii_mayan__display (x + s_left, y + s_topp, '#', n * 10,  0,  9,  6, a_mode);
   /*---(greater)------------------------*/
   p = strchr (x_hex, toupper (a_one));
   DEBUG_YASCII   yLOG_point   ("one"       , p);
   --rce;  if (p == NULL) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   v = n = p - x_hex;
   DEBUG_YASCII   yLOG_value   ("v"         , v);
   if (v >= 8) {
      e_displayer (x + s_left + 3, y + s_topp + 2, "Ï", a_mode);
      v -= 8;
   }
   DEBUG_YASCII   yLOG_value   ("v"         , v);
   if (v >= 4) {
      e_displayer (x + s_left + 3, y + s_topp + 3, "Ï", a_mode);
      v -= 4;
   }
   DEBUG_YASCII   yLOG_value   ("v"         , v);
   if (v >= 2) {
      e_displayer (x + s_left + 5, y + s_topp + 3, "Ï", a_mode);
      v -= 2;
   }
   DEBUG_YASCII   yLOG_value   ("v"         , v);
   if (v >= 1) {
      e_displayer (x + s_left + 5, y + s_topp + 2, "Ï", a_mode);
      v -= 1;
   }
   DEBUG_YASCII   yLOG_value   ("v"         , v);
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yascii_mayan__conjuct   (int a_len, char a_vowel, int x, int y, char a_mode)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char       *x_valid     = "ivuea";
   char        x_off       =    0;
   /*---(begin)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   DEBUG_YASCII   yLOG_note    ("handling conjunction");
   /*---(defense)------------------------*/
   DEBUG_YASCII   yLOG_value   ("a_len"     , a_len);
   --rce;  if (a_len != 2) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_char    ("a_vowel"   , a_vowel);
   DEBUG_YASCII   yLOG_info    ("x_valid"   , x_valid);
   --rce;  if (a_vowel == 0 || strchr (x_valid, a_vowel) == NULL) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(conjunction)--------------------*/
   switch (a_vowel) {
   case 'i' :  x_off =  0;   break;
   case 'v' :  x_off = 10;   break;
   case 'u' :  x_off = 20;   break;
   case 'e' :  x_off = 30;   break;
   case 'a' :  x_off = 40;   break;
   }
   yascii_mayan__display (x + s_left, y + s_topp, 'p', x_off, 0, 9, 6, a_mode);
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yascii_mayan__prefix    (char a_orient, char a_prefix, char a_pvariant, char a_cons, char a_cvariant, char a_vowel, char a_vvariant, int x, int y, char a_mode)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char       *x_valid     = "€„";
   short       x_left, x_topp;
   char        x_wide, x_tall;
   char        x_xoff, x_yoff;
   /*---(begin)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   DEBUG_YASCII   yLOG_complex ("args"      , "%c, %c %c, %c %c, %c %c, %3d %3d, %c", a_orient, a_prefix, a_pvariant, a_cons, a_cvariant, a_vowel, a_vvariant, x, y, a_mode);
   /*---(defense)------------------------*/
   if (strchr ("· ", a_orient) != NULL)  a_orient = '„';
   DEBUG_YASCII   yLOG_char    ("a_orient"  , a_orient);
   DEBUG_YASCII   yLOG_info    ("x_valid"   , x_valid);
   --rce;  if (strchr (x_valid, a_orient) == NULL) {
      a_orient = '„';
   }
   DEBUG_YASCII   yLOG_char    ("a_cons"    , a_cons);
   --rce;  if (a_cons == 'x') {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   if (a_orient == '„')  a_cvariant = a_vvariant = a_pvariant;
   /*---(consonant)----------------------*/
   rc = yascii_mayan__cdata   ('-', a_cons  , a_orient, a_cvariant, &x_left, &x_topp, &x_wide, &x_tall);
   DEBUG_YASCII   yLOG_value   ("cdata"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   yascii_mayan__display (x + s_left, y + s_topp, 'c', x_left, x_topp, x_wide, x_tall, a_mode);
   /*---(prefix)-------------------------*/
   rc = yascii_mayan__vdata   ('-', a_prefix, 'a', a_orient, a_pvariant, &x_left, &x_topp, &x_wide, &x_tall, &x_xoff, &x_yoff);
   DEBUG_YASCII   yLOG_value   ("vdata (p)" , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   yascii_mayan__display (x + s_left + x_xoff, y + s_topp + x_yoff, 'v', x_left, x_topp, x_wide, x_tall, a_mode);
   /*---(vowel)--------------------------*/
   rc = yascii_mayan__vdata   ('-', a_vowel , 'b', a_orient, a_vvariant, &x_left, &x_topp, &x_wide, &x_tall, &x_xoff, &x_yoff);
   DEBUG_YASCII   yLOG_value   ("vdata (s)" , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   yascii_mayan__display (x + s_left + x_xoff, y + s_topp + x_yoff, 'v', x_left, x_topp, x_wide, x_tall, a_mode);
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yascii_mayan__suffix    (char a_orient, char a_cons, char a_cvariant, char a_vowel, char a_vvariant, char a_suffix, char a_svariant, int x, int y, char a_mode)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char       *x_valid     = "Ö×ÕÔƒ";
   short       x_left, x_topp;
   char        x_wide, x_tall;
   char        x_xoff, x_yoff;
   /*---(begin)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   DEBUG_YASCII   yLOG_complex ("args"      , "%c, %c %c, %c %c, %c %c, %3d %3d, %c", a_orient, a_cons, a_cvariant, a_vowel, a_vvariant, a_suffix, a_svariant, x, y, a_mode);
   /*---(defense)------------------------*/
   if (a_orient == '·')  a_orient = 'Ö';
   if (a_orient == ' ')  a_orient = 'Ö';
   DEBUG_YASCII   yLOG_char    ("a_orient"  , a_orient);
   DEBUG_YASCII   yLOG_info    ("x_valid"   , x_valid);
   --rce;  if (strchr (x_valid, a_orient) == NULL) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_char    ("a_cons"    , a_cons);
   --rce;  if (a_cons == 'x') {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(consonant)----------------------*/
   rc = yascii_mayan__cdata   ('-', a_cons  , a_orient, a_cvariant, &x_left, &x_topp, &x_wide, &x_tall);
   DEBUG_YASCII   yLOG_value   ("cdata"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   yascii_mayan__display (x + s_left, y + s_topp, 'c', x_left, x_topp, x_wide, x_tall, a_mode);
   /*---(vowel)--------------------------*/
   rc = yascii_mayan__vdata   ('-', a_vowel , 'a', a_orient, a_vvariant, &x_left, &x_topp, &x_wide, &x_tall, &x_xoff, &x_yoff);
   DEBUG_YASCII   yLOG_value   ("vdata (s)" , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   yascii_mayan__display (x + s_left + x_xoff, y + s_topp + x_yoff, 'v', x_left, x_topp, x_wide, x_tall, a_mode);
   /*---(suffix)-------------------------*/
   rc = yascii_mayan__vdata   ('-', a_suffix, 'b', a_orient, a_svariant, &x_left, &x_topp, &x_wide, &x_tall, &x_xoff, &x_yoff);
   DEBUG_YASCII   yLOG_value   ("vdata (p)" , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   yascii_mayan__display (x + s_left + x_xoff, y + s_topp + x_yoff, 'v', x_left, x_topp, x_wide, x_tall, a_mode);
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yascii_mayan__pretty    (char a_part, char a_formal [LEN_TERSE], char a_pretty [LEN_TERSE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        x_len       =    0;
   /*---(get length)---------------------*/
   x_len = strlen (s_formal);
   /*---(add spaces)---------------------*/
   if (a_part != 2 && x_len > 0) {
      ystrlcat (s_formal  , " ", LEN_RECD);
      ystrlcat (s_pretty  , " ", LEN_RECD);
      ystrlcat (s_glyphish, " ", LEN_RECD);
   }
   /*---(concatinate)--------------------*/
   ystrlcat (s_formal  , a_formal  , LEN_RECD);
   ystrlcat (s_pretty  , a_pretty  , LEN_RECD);
   /*---(glythish)-----------------------*/
   if (a_part == 2)   ystrlcat (s_glyphish, "·", LEN_RECD);
   ystrlcat (s_glyphish, a_formal  , LEN_RECD);
   /*---(complete)-----------------------*/
   return 0;
}

char
yascii_mayan__glyph_orn (char a_part, char a_full [LEN_TERSE], char a_leads, char a_pre, char a_suf, int x, int y, char a_ornament, char a_mode)
{
   /*---(locals)-----------+-----+-----+-*/
   char        t           [LEN_LABEL] = "";
   char        x_full      [LEN_TERSE] = "";
   char        x_pretty    [LEN_TERSE] = "";
   char        x_formal    [LEN_TERSE] = "";
   char       *a           = NULL;
   char        u           [LEN_LABEL] = "";
   char        v           [LEN_LABEL] = "";
   char        l          =    0;
   int         i           =    0;
   /*---(begin)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(sentence begin)-----------------*/
   if (s_start == 'y' && a_ornament != YASCII_BASE) {
      if (e_displayer != NULL)  { for (i = 0; i < s_tall; ++i) e_displayer (x, y + i, "°", a_mode); }
   }
   s_start = '·';
   /*---(lead s)-------------------------*/
   if (strchr (YASCII_SHOW_HINT, a_ornament) != NULL && a_leads == 'y') {
      if (e_displayer != NULL)  e_displayer (x, y + s_topp + 4, "¤", a_mode);
   }
   /*---(condensed conjunction)----------*/
   if (strchr (YASCII_SHOW_HINT, a_ornament) != NULL && a_ornament != YASCII_FULL && s_conjunct != '·') {
      if (s_conjunct != '·') {
         DEBUG_YASCII   yLOG_note   ("writing condensed conjunction");
         DEBUG_YASCII   yLOG_complex ("using"     , "%c  %s", s_conjunct, s_conjtxt);
         sprintf (t, "%c", s_conjunct);
         if (e_displayer != NULL)  e_displayer (x, y + s_topp, t, a_mode);
      }
      if (s_possess != '·') {
         if (e_displayer != NULL)  e_displayer (x, y + s_topp, "à", a_mode);
      }
   }
   /*---(tsae build)---------------------*/
   l = strlen (a_full);
   ystrlcpy (x_full, a_full, LEN_TERSE);
   strcpy (t, "");
   a = x_full;
   if (a_pre == 'y')  {
      sprintf (t, "%c'", x_full [0]);
      a = x_full + 1;
      if (x_full [1] == ')')  a = x_full + 2;
   }
   if (a_suf == 'y') {
      a_suf = x_full [l - 1];
      x_full [l - 1] = '\0';
   }
   ystrlcat (t, a, LEN_LABEL);
   l = strlen (t);
   if (a_suf != '·')  sprintf (u, "%s'%c", t, a_suf);
   else               ystrlcpy (u, t, LEN_LABEL);
   ystrlcpy (x_pretty, u, LEN_LABEL);
   ystrlcpy (x_formal, u, LEN_LABEL);
   if (a_pre == 'y')  x_formal [1] = ')';
   /*---(tsae display)-------------------*/
   if (strchr (YASCII_SHOW_TSAE, a_ornament) != NULL) {
      switch (a_part) {
      case  1  :  ystrlpad (u, v, '.', '>',  9);  v [0] = '„';  strcat (v, "·");  break;
      case  2  :  ystrlpad (u, v, '.', '<',  9);  v [8] = '…';                    break;
      case  0  :  ystrlpad (u, v, '.', '|',  9);  v [0] = '„';  v [8] = '…';      break;
      }
      if (a_ornament != YASCII_FULL && s_conjunct != '·') {
         DEBUG_YASCII   yLOG_note   ("writing condensed conjunction");
         DEBUG_YASCII   yLOG_complex ("using"     , "%c  %s", s_conjunct, s_conjtxt);
         /*> sprintf (t, "%c", s_conjunct);                                           <*/
         /*> if (e_displayer != NULL)  e_displayer (x, y + s_topp, t, a_mode);        <*/
         for (i = 1; i < 4; ++i) { if (e_displayer != NULL)  e_displayer (x, y + s_topp + i, "´", a_mode); }
         if (a_part == 1) {
            v [2] = 'o';
            v [3] = s_conjtxt [1];
            if (s_conjtxt [2] != '\0')  v [4] = s_conjtxt [2];
         }
         yascii_mayan__pretty (0, s_conjtxt, s_conjtxt);
         /*> s_conjunct = '·';                                                        <* 
          *> strcpy (s_conjtxt, "");                                                  <*/
      }
      if (a_ornament != YASCII_FULL && s_possess != '·') {
         for (i = 0; i < 4; ++i)  {
            if (e_displayer != NULL)  e_displayer (x, y + s_topp + i, "à", a_mode);
         }
         if (a_part == 1) {
            v [2] = 'h';
            v [3] = 'n';
            v [4] = 'a';
         }
         /*> s_possess  = '·';                                                        <* 
          *> strcpy (s_posstxt, "");                                                  <*/
      }
      if (e_displayer != NULL)  e_displayer (x + s_left, y + s_topp + 6, v, a_mode);
   }
   yascii_mayan__pretty (a_part, x_formal, x_pretty);
   /*> if (strchr (YASCII_SHOW_HINT, a_ornament) != NULL && a_ornament != YASCII_FULL && s_conjunct != '·') {   <* 
    *>    s_conjunct = '·';                                                                                     <* 
    *>    strcpy (s_conjtxt, "");                                                                               <* 
    *> }                                                                                                        <*/
   /*---(reset)--------------------------*/
   s_possess  = '·';
   strcpy (s_posstxt, "");
   s_conjunct = '·';
   strcpy (s_conjtxt, "");
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yascii_mayan__glyph     (char a_part, char a_full [LEN_TERSE], char a_text [LEN_TERSE], char a_diagram [LEN_TERSE], char a_orient [LEN_TERSE], char a_variant [LEN_TERSE], int x, int y, char a_ornament, char a_mode)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         x_len       =    0;
   int         x_type      =  '·';
   char        x_head      =  '·';
   char        x_next      =  '·';
   char        x_tail      =  '·';
   char        s           =  '·';
   char        x_full      [LEN_LABEL] = "";
   char        t           [LEN_LABEL] = "";
   char        u           [LEN_LABEL] = "";
   char        v           [LEN_LABEL] = "";
   int         i           =    0;
   char        x_pre       =  '·';
   char        x_suf       =  '·';
   int         l           =    0;
   /*---(begin)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   DEBUG_YASCII   yLOG_complex ("args"      , "%d, å%sæ, å%-6.6sæ å%-6.6sæ å%-6.6sæ å%-6.6sæ, %3d %3d %c %c", a_part, a_full, a_text, a_diagram, a_orient, a_variant, x, y, a_ornament, a_mode);
   /*---(defense)------------------------*/
   DEBUG_YASCII   yLOG_point   ("a_text"    , a_text);
   --rce;  if (a_text == NULL) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_info    ("a_text"    , a_text);
   /*---(prepare)------------------------*/
   x_len = strlen (a_text);
   DEBUG_YASCII   yLOG_value   ("x_len"     , x_len);
   --rce;  if (x_len <= 0 || x_len > 3) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   x_head = a_text [0];
   if (x_len > 1)  x_next = a_text [1];
   if (x_len > 2)  x_tail = a_text [2];
   /*---(conjuction)---------------------*/
   if (x_head == 'o') {
      if (a_ornament == YASCII_FULL) {
         rc = yascii_mayan__conjuct (x_len, x_next, x, y, a_mode);
      } else {
         if      (strcmp (a_text + 1, "i" ) == 0) { s_conjunct = 'Ð';  strcpy (s_conjtxt, "oi" ); }
         else if (strcmp (a_text + 1, "v" ) == 0) { s_conjunct = 'Ñ';  strcpy (s_conjtxt, "ov" ); }
         else if (strcmp (a_text + 1, "u" ) == 0) { s_conjunct = 'Ò';  strcpy (s_conjtxt, "ou" ); }
         else if (strcmp (a_text + 1, "e" ) == 0) { s_conjunct = '+';  strcpy (s_conjtxt, "oe" ); }
         else if (strcmp (a_text + 1, "a" ) == 0) { s_conjunct = '!';  strcpy (s_conjtxt, "oa" ); }
         else if (strcmp (a_text + 1, "ai") == 0) { s_conjunct = 'Ô';  strcpy (s_conjtxt, "oai"); }
         else if (strcmp (a_text + 1, "av") == 0) { s_conjunct = 'Õ';  strcpy (s_conjtxt, "oav"); }
         else if (strcmp (a_text + 1, "au") == 0) { s_conjunct = 'Ó';  strcpy (s_conjtxt, "oau"); }
         else                                     { s_conjunct = '·';  strcpy (s_conjtxt, ""   ); }
         DEBUG_YASCII   yLOG_complex ("saving"    , "%c  %s", s_conjunct, s_conjtxt);
         DEBUG_YASCII   yLOG_exitr  (__FUNCTION__, rc);
         return 0;
      }
   }
   /*---(prefixed)-----------------------*/
   else if (strchr (YSTR_MAYANV, x_head) != NULL) {
      if (strchr (YASCII_SHOW_ENGL, a_ornament) != NULL && e_displayer != NULL) {
         if (strchr ("va", x_head) != NULL)  { for (i = 0; i < 3; ++i)  e_displayer (x, y + s_topp + i, "³", a_mode); }
         else                                  e_displayer (x, y + s_topp, "³", a_mode);
      }
      if (a_ornament == YASCII_TSAE  && e_displayer != NULL)  e_displayer (x, y, "Ï", a_mode);
      if (a_diagram [1] == 'S')  s = 'y';
      yascii_mayan__prefix (a_orient [0], x_head, a_variant [0], x_next, a_variant [1], x_tail, a_variant [2], x, y, a_mode);
      x_pre = 'y';
   }
   /*---(suffixed)-----------------------*/
   else if (x_len == 3 && x_next != '\0' && strchr ("· ", x_next) == NULL) {
      if (a_diagram [0] == 'S')  s = 'y';
      yascii_mayan__suffix (a_orient [0], x_head, a_variant [0], x_next, a_variant [1], x_tail, a_variant [2], x, y, a_mode);
      x_suf = 'y';
   }
   /*---(normal)-------------------------*/
   else {
      if (a_diagram [0] == 'S')  s = 'y';
      yascii_mayan__normal (a_orient [0], x_head, a_variant [0], x_next, a_variant [1], x, y, a_mode);
   }
   /*---(ornament)-----------------------*/
   rc = yascii_mayan__glyph_orn (a_part, a_full, s, x_pre, x_suf, x, y, a_ornament, a_mode);
   DEBUG_YASCII   yLOG_value  ("ornament"  , rc);
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit   (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                        word parser                           ----===*/
/*====================------------------------------------====================*/
static void      o___WORDS______________o (void) {;}

char
yascii_mayan__diagram   (char b_text [LEN_TERSE], char r_diagram [LEN_TERSE], char b_orient [LEN_TERSE], char b_variant [LEN_TERSE], char *r_break)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         l           =    0;
   char        x_text      [LEN_TERSE] = "";
   char        x_orient    [LEN_TERSE] = "";
   char        x_variant   [LEN_TERSE] = "";
   int         i           =    0;
   int         j           =    0;
   char        x_break     =    0;
   /*---(begin)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_diagram != NULL)  strcpy (r_diagram, "");
   if (r_break   != NULL)  *r_break = 0;
   /*---(defense)------------------------*/
   DEBUG_YASCII   yLOG_point   ("b_text"    , b_text);
   --rce;  if (b_text == NULL) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_info    ("b_text"    , b_text);
   l = strlen (b_text);
   DEBUG_YASCII   yLOG_value   ("l"         , l);
   --rce;  if (l <= 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_point   ("r_diagram" , r_diagram);
   --rce;  if (r_diagram == NULL) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(diagram)------------------------*/
   for (i = 0; i < l; ++i) {
      DEBUG_YASCII   yLOG_complex ("work"      , "%2di, %-20.20s, %c -- %2dj, %-20.20s, %c, %-20.20s, %c", i, b_text, b_text [i], j, r_diagram, (j > 0) ? r_diagram [j - 1] : '·', x_text, (j > 0) ? x_text [j - 1] : '·');
      /*---(delimiters)------------------*/
      if (strchr (")>·(<'", b_text [i]) != NULL)  continue;
      /*---(vowels)----------------------*/
      if      (strchr (YSTR_MAYANV, b_text [i]) != NULL) {
         DEBUG_YASCII   yLOG_note    ("vowel");
         if      (i == 0)      r_diagram [j] = 'p';
         else if (j > 0 && b_text [i - 1] ==  'q' && b_text [i] == 'u') continue;
         else                  r_diagram [j] = 'v';
      }
      /*---(consonants)------------------*/
      else if (strchr (YSTR_MAYANC, b_text [i]) != NULL) {
         DEBUG_YASCII   yLOG_note    ("consonant");
         /*---(check for syllable break--*/
         if (j > 1 && r_diagram [j - 1] == 'v')  x_break = i;
         /*---(handle consonants)--------*/
         if (j > 0 && r_diagram [j - 1] == 'C' && x_text [j - 1] ==  's') {
            r_diagram [j - 1] = 'S';
            x_text    [j - 1] = b_text [i];
            continue;
         }
         else if (j > 0 && b_text [i - 1] ==  'h' && b_text [i] == 'y') { x_text    [j - 1] = 'y'; continue; }
         else if (j > 0 && b_text [i - 1] ==  'h' && b_text [i] == 'l') { x_text    [j - 1] = 'l'; continue; }
         else if (j > 0 && b_text [i - 1] ==  't' && b_text [i] == 's') { x_text    [j - 1] = 'z'; continue; }
         else if (j > 0 && b_text [i - 1] ==  't' && b_text [i] == 'l') { x_text    [j - 1] = 'c'; continue; }
         else r_diagram [j] = 'C';
      }
      /*---(unknown)---------------------*/
      else  r_diagram [j] = '´';
      /*---(next)------------------------*/
      x_text    [j] = b_text    [i];
      if (b_orient  != NULL)  x_orient  [j] = b_orient  [i];
      if (b_variant != NULL)  x_variant [j] = b_variant [i];
      ++j;
      /*---(done)------------------------*/
   }
   /*---(clean-up)-----------------------*/
   x_text    [j] = '\0';
   if (b_orient  != NULL)  x_orient  [j] = '\0';
   if (b_variant != NULL)  x_variant [j] = '\0';
   r_diagram [j] = '\0';
   /*---(answer key)---------------------*/
   DEBUG_YASCII   yLOG_info    ("x_text"    , x_text);
   DEBUG_YASCII   yLOG_info    ("r_diagram" , r_diagram);
   --rce;  if (strcmp (r_diagram, "Cv")      == 0) rc =  0;
   else if    (strcmp (r_diagram, "Sv")      == 0) rc =  0;
   else if    (strcmp (r_diagram, "pCv")     == 0) rc =  0;
   else if    (strcmp (r_diagram, "pSv")     == 0) rc =  0;
   else if    (strcmp (r_diagram, "Cvv")     == 0) rc =  0;
   else if    (strcmp (r_diagram, "Svv")     == 0) rc =  0;
   else if    (strcmp (r_diagram, "CvCv")    == 0) rc =  2;
   else if    (strcmp (r_diagram, "SvCv")    == 0) rc =  2;
   else if    (strcmp (r_diagram, "CvSv")    == 0) rc =  2;
   else if    (strcmp (r_diagram, "pCvCv")   == 0) rc =  3;
   else if    (strcmp (r_diagram, "pSvCv")   == 0) rc =  3;
   else if    (strcmp (r_diagram, "pCvSv")   == 0) rc =  3;
   else if    (strcmp (r_diagram, "CvCvv")   == 0) rc =  2;
   else if    (strcmp (r_diagram, "SvCvv")   == 0) rc =  2;
   else if    (strcmp (r_diagram, "CvSvv")   == 0) rc =  2;
   else if    (strcmp (r_diagram, "pCvCvv")  == 0) rc =  3;
   else if    (strcmp (r_diagram, "pSvCvv")  == 0) rc =  3;
   else if    (strcmp (r_diagram, "pCvSvv")  == 0) rc =  3;
   else if    (strcmp (r_diagram, "pv")      == 0 && b_text [0] == 'o') rc = 0;
   else if    (strcmp (r_diagram, "pvv")     == 0 && b_text [0] == 'o') rc = 0;
   else {
      DEBUG_YASCII   yLOG_note    ("does not match valid structure");
      if (r_diagram != NULL)  strcpy (r_diagram, "");
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_value   ("rc"        , rc);
   /*---(save-back)----------------------*/
   strlcpy (b_text   , x_text   , LEN_TERSE);
   if (b_orient  != NULL)  strlcpy (b_orient , x_orient , LEN_TERSE);
   if (b_variant != NULL)  strlcpy (b_variant, x_variant, LEN_TERSE);
   if (r_break != NULL)  *r_break = x_break;
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit   (__FUNCTION__);
   return rc;
}

char
yascii_mayan__append    (char a_nglyph, char a_request [LEN_TERSE], char a_word [LEN_TERSE], char a_diagram [LEN_TERSE], char a_root [LEN_LABEL], char a_meaning [LEN_LABEL], char a_orient [LEN_TERSE], char a_variant [LEN_TERSE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        x_len       =    0;
   char        l           =    0;
   char        t           [LEN_LABEL] = "";
   /*---(longest addition)---------------*/
   l = strlen (a_request);
   if (l > x_len)  x_len = l;
   l = strlen (a_word);
   if (l > x_len)  x_len = l;
   l = strlen (a_diagram);
   if (l > x_len)  x_len = l;
   l = strlen (a_root);
   if (l > x_len)  x_len = l;
   l = strlen (a_meaning);
   if (l > x_len)  x_len = l;
   l = strlen (a_orient);
   if (l > x_len)  x_len = l;
   l = strlen (a_variant);
   if (l > x_len)  x_len = l;
   x_len += 1;
   /*---(append)-------------------------*/
   s_nchar  += x_len;
   s_nglyph += a_nglyph;
   sprintf (t, "%-*.*s", x_len, x_len, a_request);
   ystrlcat (s_request, t        , LEN_RECD);
   sprintf (t, "%-*.*s", x_len, x_len, a_word);
   ystrlcat (s_words  , t        , LEN_RECD);
   sprintf (t, "%-*.*s", x_len, x_len, a_diagram);
   ystrlcat (s_diagram, t        , LEN_RECD);
   sprintf (t, "%-*.*s", x_len, x_len, a_meaning);
   ystrlcat (s_meaning, t        , LEN_RECD);
   sprintf (t, "%-*.*s", x_len, x_len, a_root);
   ystrlcat (s_root   , t        , LEN_RECD);
   sprintf (t, "%-*.*s", x_len, x_len, a_orient);
   ystrlcat (s_orient , t        , LEN_RECD);
   sprintf (t, "%-*.*s", x_len, x_len, a_variant);
   ystrlcat (s_variant, t        , LEN_RECD);
   /*---(complete)-----------------------*/
   return 0;
}

char
yascii_mayan__word      (char a_word [LEN_TERSE], char a_meaning [LEN_LABEL], char a_orient [LEN_TERSE], char a_variant [LEN_TERSE], int *x, int *y, char a_ornament, char a_mode)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_word      [LEN_TERSE] = "";
   char        x_orient    [LEN_TERSE] = "";
   char        x_variant   [LEN_TERSE] = "";
   char        x_full      [LEN_TERSE] = "";
   char        x_diagram   [LEN_TERSE] = "";
   char        x_eng       [LEN_TERSE] = "";
   char        x_txt       [LEN_TERSE] = "";
   char        x_ori       [LEN_TERSE] = "";
   char        x_var       [LEN_TERSE] = "";
   char        x_dia       [LEN_TERSE] = "";
   char        x_root      [LEN_LABEL] = "";
   char        x_meaning   [LEN_LABEL] = "";
   char        t           [LEN_LABEL] = "";
   char        x_mean      [LEN_DESC]  = "";
   char        x_break     =    0;
   int         x_beg       =   *x;
   char       *p           = NULL;
   int         l           =    0;
   char        x_suf       =  '·';
   char        x_nglyph    =    0;
   /*---(begin)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   DEBUG_YASCII   yLOG_complex ("args"      , "%-15.15s, å%-10.10sæ å%-10.10sæ å%-10.10sæ, %3d %3d %c %c", a_meaning, a_word, a_orient, a_variant, *x, *y, a_ornament, a_mode);
   /*---(defense)------------------------*/
   DEBUG_YASCII   yLOG_point   ("a_word"    , a_word);
   --rce;  if (a_word == NULL) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   ystrlcpy (x_word   , a_word   , LEN_TERSE);
   ystrlcpy (x_full   , a_word   , LEN_TERSE);
   ystrlcpy (x_orient , a_orient , LEN_TERSE);
   ystrlcpy (x_variant, a_variant, LEN_TERSE);
   DEBUG_YASCII   yLOG_info    ("x_word"    , x_word);
   /*---(diagram)------------------------*/
   rc = yascii_mayan__diagram (x_word, x_diagram, x_orient, x_variant, &x_break);
   DEBUG_YASCII   yLOG_value   ("diagram"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(word suffix hint)---------------*/
   l = strlen (x_diagram);
   if (strcmp (x_diagram + l - 2, "vv") == 0)  x_suf = x_word [l - 1];
   /*---(prefixed)-----------------------*/
   if (rc == 0) {
      DEBUG_YASCII   yLOG_complex ("pos"        , "%4d, %4d", *x, *y);
      ystrlcpy (x_eng, x_full   , LEN_TERSE);
      ystrlcpy (x_txt, x_word   , LEN_TERSE);
      ystrlcpy (x_ori, x_orient , LEN_TERSE);
      ystrlcpy (x_var, x_variant, LEN_TERSE);
      ystrlcpy (x_dia, x_diagram, LEN_TERSE);
      yascii_mayan__glyph (0, x_eng, x_txt, x_dia, x_ori, x_var, *x, *y, a_ornament, a_mode);
      x_nglyph = 1;
   } else {
      DEBUG_YASCII   yLOG_complex ("pos"        , "%4d, %4d", *x, *y);
      sprintf (x_eng, "%*.*s", x_break, x_break, x_full);
      sprintf (x_txt, "%*.*s", rc, rc, x_word   );
      sprintf (x_ori, "%*.*s", rc, rc, x_orient );
      sprintf (x_var, "%*.*s", rc, rc, x_variant);
      sprintf (x_dia, "%*.*s", rc, rc, x_diagram);
      yascii_mayan__glyph (1, x_eng, x_txt, x_dia, x_ori, x_var, *x, *y, a_ornament, a_mode);
      *x += s_wide;
      if (e_displayer != NULL)  e_displayer (*x, *y + s_topp + 0, "€", a_mode);
      if (e_displayer != NULL)  e_displayer (*x, *y + s_topp + 5, "€", a_mode);
      DEBUG_YASCII   yLOG_complex ("pos"        , "%4d, %4d", *x, *y);
      sprintf (x_eng, "%s", x_full    + x_break);
      sprintf (x_txt, "%s", x_word    + rc);
      sprintf (x_ori, "%s", x_orient  + rc);
      sprintf (x_var, "%s", x_variant + rc);
      sprintf (x_dia, "%s", x_diagram + rc);
      yascii_mayan__glyph (2, x_eng, x_txt, x_dia, x_ori, x_var, *x, *y, a_ornament, a_mode);
      x_nglyph = 2;
   }
   /*---(meaning)------------------------*/
   if (strchr (YASCII_SHOW_ENGL, a_ornament) != NULL && a_meaning != NULL) {
      ystrlcpy (x_meaning, a_meaning, LEN_LABEL);
      p = strchr (x_meaning, '/');
      if (p != NULL) {
         p [0] = '\0';
         ++p;
         ystrlcpy (x_root, p, LEN_LABEL);
         ystrlpad (p, t, '.', '<', 15);
         ystrlupper (t, LEN_LABEL);
         sprintf (x_mean, "ƒ·%-15.15s·‚", t);
      } else {
         ystrlcpy (x_root, "·", LEN_LABEL);
         strcpy (x_mean, "· · · · · · · · · ·");
      }
      if (strchr (YASCII_SHOW_ROOT, a_ornament) != NULL) {
         if (e_displayer != NULL)  e_displayer (x_beg + s_left, *y, x_mean, a_mode);
      }
      l = strlen (x_meaning);
      ystrlpad (x_meaning, t, '.', '<', 15);
      sprintf (x_mean, "ƒ·%-15.15s·‚", t);
      if (l <= 12)  x_mean [16] = x_suf;
      if (strchr (YASCII_SHOW_ROOT, a_ornament) != NULL) {
         if (e_displayer != NULL)  e_displayer (x_beg + s_left, *y + 1, x_mean, a_mode);
      } else {
         if (e_displayer != NULL)  e_displayer (x_beg + s_left, *y    , x_mean, a_mode);
      }
   }
   /*---(update)-------------------------*/
   yascii_mayan__append (x_nglyph, x_full, x_word, x_diagram, x_root, x_meaning, x_orient, x_variant);
   *x += s_wide;
   if (a_ornament != YASCII_FULL && x_full [0] == 'o')  *x -= s_wide;
   DEBUG_YASCII   yLOG_complex ("final"      , "%4d, %4d", *x, *y);
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit   (__FUNCTION__);
   return 0;
}

char
yASCII_mayan_word       (char a_word [LEN_TERSE], int x, int y, char a_ornament)
{
   return yascii_mayan__word (a_word, "", "", "", &x, &y, a_ornament, YASCII_CLEAR);
}



/*====================------------------------------------====================*/
/*===----                       full driver                            ----===*/
/*====================------------------------------------====================*/
static void      o___COMPOUND___________o (void) {;}

char
yascii_mayan__compound  (char a_word [LEN_LABEL], char a_meaning [LEN_DESC], char a_orient [LEN_LABEL], char a_variant [LEN_LABEL], int *x, int *y, char a_ornament, char a_mode)
{
   char        rce         =  -10;
   char        rc          =    0;
   char        x_word      [LEN_LABEL] = "";
   char        x_meaning   [LEN_DESC]  = "";
   char        x_orient    [LEN_LABEL] = "";
   char        x_variant   [LEN_LABEL] = "";
   char        t           [LEN_TITLE] = "";
   char        x_full      [LEN_DESC]  = "";
   char       *p           = NULL;
   char       *m           = NULL;
   char       *r           = NULL;
   char        n           =    0;
   int         x_beg       =   *x;
   int         i           =    0;
   /*---(begin)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(prepare)------------------------*/
   ystrlcpy (x_word   , a_word   , LEN_LABEL);
   ystrlcpy (x_meaning, a_meaning, LEN_DESC);
   ystrlcpy (x_orient , a_orient , LEN_LABEL);
   ystrlcpy (x_variant, a_variant, LEN_LABEL);
   /*---(find word marker)---------------*/
   p = strchr (x_word, '›');
   DEBUG_YASCII   yLOG_point   ("p"          , p);
   if (p == NULL) {
      DEBUG_YASCII   yLOG_note   ("handle as normal word");
      rc = yascii_mayan__word     (x_word, x_meaning, x_orient, x_variant, x, y, a_ornament, a_mode);
      DEBUG_YASCII   yLOG_exit   (__FUNCTION__);
      return 0;
   }
   /*---(cut word strings)---------------*/
   n = p - x_word;
   x_word    [n] = '\0';
   x_orient  [n] = '\0';
   x_variant [n] = '\0';
   ++p;
   ++n;
   DEBUG_YASCII   yLOG_complex ("x_word"     , "%-10.10s, %-10.10s", x_word   , x_word    + n);
   DEBUG_YASCII   yLOG_complex ("x_orient"   , "%-10.10s, %-10.10s", x_orient , x_orient  + n);
   DEBUG_YASCII   yLOG_complex ("x_variant"  , "%-10.10s, %-10.10s", x_variant, x_variant + n);
   /*---(find meaning marker)------------*/
   m = strchr (x_meaning, '›');
   DEBUG_YASCII   yLOG_point   ("m"          , m);
   if (m != NULL) {
      m [0] = '\0';
      ++m;
   } else {
      m = x_meaning;
   }
   /*---(find root marker)---------------*/
   r = strchr (m, '/');
   DEBUG_YASCII   yLOG_point   ("r"          , r);
   if (r != NULL) {
      r [0] = '\0';
      ++r;
      DEBUG_YASCII   yLOG_complex ("root"       , "%s", r);
   }
   DEBUG_YASCII   yLOG_complex ("x_meaning"  , "%-10.10s, %-10.10s", x_meaning, m);
   /*---(handle first word)--------------*/
   rc = yascii_mayan__word     (x_word, x_meaning, x_orient, x_variant, x, y, a_ornament, a_mode);
   DEBUG_YASCII   yLOG_value   ("first"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(compound marker)----------------*/
   for (i = 0; i < 6; ++i)  e_displayer (*x, *y + s_topp + i, "›", a_mode);
   if (strchr (YASCII_SHOW_TSAE, a_ornament) != NULL)  e_displayer (*x, *y + s_topp + 6, "›", a_mode);
   if (strchr (YASCII_SHOW_ENGL, a_ornament) != NULL)  e_displayer (*x, *y + s_topp - 1, "›", a_mode);
   /*---(handle second word)-------------*/
   rc = yascii_mayan__word     (x_word + n, m, x_orient + n, x_variant + n, x, y, a_ornament, a_mode);
   DEBUG_YASCII   yLOG_value   ("first"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_YASCII   yLOG_exitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(meaning)------------------------*/
   if (r != NULL) {
      ystrlpad (r, t, '.', '<', LEN_TITLE);
      ystrlupper (t, LEN_TITLE);
      sprintf (x_full, "ƒ·%-29.29s·······‚", t);
      if (strchr (YASCII_SHOW_ROOT, a_ornament) != NULL) {
         if (e_displayer != NULL)  e_displayer (x_beg + s_left, *y, x_full, a_mode);
      }
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit   (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                       full driver                            ----===*/
/*====================------------------------------------====================*/
static void      o___DRIVER_____________o (void) {;}

char
yascii_mayan__sizer     (char a_size, char a_gapping, char a_ornament, char *r_wide, char *r_tall, char *r_left, char *r_topp)
{
   /*---(begin)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   DEBUG_YASCII   yLOG_complex ("args"      , "%c %c %c", a_size, a_gapping, a_ornament);
   /*---(defaults)-----------------------*/
   s_wide = s_tall = s_left = s_topp = 0;
   /*---(integration)--------------------*/
   if (a_ornament != YASCII_BASE  && a_gapping == YASCII_NOGAP) {
      DEBUG_YASCII   yLOG_note    ("gapping upgraded to NORMGAP due to ornamentation");
      a_gapping = YASCII_NORMGAP;
   }
   /*---(general sizing)-----------------*/
   switch (a_size) {
   case YASCII_MEDIUM  :  s_wide =  7;  s_tall =  5;  break;
   case YASCII_THIN    :  s_wide =  6;  s_tall =  5;  break;
   case YASCII_THINNER :  s_wide =  5;  s_tall =  5;  break;
   case YASCII_SMALL   :  s_wide =  5;  s_tall =  4;  break;
   case YASCII_TINY    :  s_wide =  4;  s_tall =  3;  break;
   case YASCII_MICRO   :  s_wide =  2;  s_tall =  1;  break;
   case YASCII_LARGE   :
   default             :  s_wide =  9;  s_tall =  6;  break;   /* large size  */
   }
   DEBUG_YASCII   yLOG_complex ("sizing"    , "%c  %2dw %2dt %2dl %2dt", a_size, s_wide, s_tall, s_left, s_topp);
   /*---(gapping)------------------------*/
   switch (a_gapping) {
   case YASCII_EVENGAP :  s_wide += 1;  s_tall += 1;  break;
   case YASCII_NOGAP   :  break;
   case YASCII_NORMGAP :
   default             :  s_wide += 1;                break;
   }
   DEBUG_YASCII   yLOG_complex ("gapping"   , "%c  %2dw %2dt %2dl %2dt", a_gapping, s_wide, s_tall, s_left, s_topp);
   /*---(ornamentation)------------------*/
   switch (a_ornament) {
   case YASCII_HINTS   :                s_left =  1;   break;
   case YASCII_TSAE    :  s_tall += 1;  s_left =  1;   break;
   case YASCII_FULL    :  s_tall += 1;  s_left =  1;   break;
   case YASCII_ENGLISH :  s_tall += 2;  s_left =  1;   s_topp =  1;  break;
   case YASCII_ICING   :  s_tall += 3;  s_left =  1;   s_topp =  2;  break;
   case YASCII_DIAGRAM :  s_tall += 3;  s_left =  1;   s_topp =  2;  break;
   default             :  break;
   }
   DEBUG_YASCII   yLOG_complex ("ornament"  , "%c  %2dw %2dt %2dl %2dt", a_ornament, s_wide, s_tall, s_left, s_topp);
   /*---(save-back)----------------------*/
   if (r_wide != NULL)  *r_wide = s_wide;
   if (r_tall != NULL)  *r_tall = s_tall;
   if (r_left != NULL)  *r_left = s_left;
   if (r_topp != NULL)  *r_topp = s_topp;
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit   (__FUNCTION__);
   return 0;
}

/*> char                                                                                                                                                                                                                                                  <* 
 *> yascii_mayan__looper    (char a_size, char b_words [LEN_RECD], char b_meaning [LEN_RECD], char b_orient [LEN_RECD], char b_variant [LEN_RECD], int x, int y, char a_layout, char a_gapping, int *a_wide, int *a_tall, char a_ornament, char a_mode)   <* 
 *> {                                                                                                                                                                                                                                                     <* 
 *>    /+---(locals)-----------+-----+-----+-+/                                                                                                                                                                                                           <* 
 *>    char        rce         =  -10;                                                                                                                                                                                                                    <* 
 *>    char        rc          =    0;                                                                                                                                                                                                                    <* 
 *>    int         x_len       =    0;                                                                                                                                                                                                                    <* 
 *>    char        x_words     [LEN_RECD]  = "";                                                                                                                                                                                                          <* 
 *>    char        x_meaning   [LEN_RECD]  = "";                                                                                                                                                                                                          <* 
 *>    char        x_orient    [LEN_RECD]  = "";                                                                                                                                                                                                          <* 
 *>    char        x_variant   [LEN_RECD]  = "";                                                                                                                                                                                                          <* 
 *>    char        x_txt       [LEN_TERSE] = "";                                                                                                                                                                                                          <* 
 *>    char        x_mean      [LEN_LABEL] = "";                                                                                                                                                                                                          <* 
 *>    char        x_ori       [LEN_TERSE] = "";                                                                                                                                                                                                          <* 
 *>    char        x_var       [LEN_TERSE] = "";                                                                                                                                                                                                          <* 
 *>    char       *p           = NULL;                                                                                                                                                                                                                    <* 
 *>    char       *q           = " ";                                                                                                                                                                                                                     <* 
 *>    char       *r           = NULL;                                                                                                                                                                                                                    <* 
 *>    char       *m           = NULL;                                                                                                                                                                                                                    <* 
 *>    char       *n           = NULL;                                                                                                                                                                                                                    <* 
 *>    int         l           =    0;                                                                                                                                                                                                                    <* 
 *>    int         x_loc       =    0;                                                                                                                                                                                                                    <* 
 *>    int         x_pos, y_pos;                                                                                                                                                                                                                          <* 
 *>    char       *x_hex       = "0123456789ABCDEF";                                                                                                                                                                                                      <* 
 *>    char       *h           = NULL;                                                                                                                                                                                                                    <* 
 *>    /+---(walk through text)--------------+/                                                                                                                                                                                                           <* 
 *>    p = strtok_r (x_words  , q, &r);                                                                                                                                                                                                                   <* 
 *>    m = strtok_r (x_meaning, q, &n);                                                                                                                                                                                                                   <* 
 *>    x_pos = x;                                                                                                                                                                                                                                         <* 
 *>    y_pos = y;                                                                                                                                                                                                                                         <* 
 *>    DEBUG_YASCII   yLOG_point   ("p"          , p);                                                                                                                                                                                                    <* 
 *>    while (p != NULL) {                                                                                                                                                                                                                                <* 
 *>       /+---(prepare)---------------------+/                                                                                                                                                                                                           <* 
 *>       DEBUG_YASCII   yLOG_complex ("POS"        , "%4d, %4d", x_pos, y_pos);                                                                                                                                                                          <* 
 *>       x_loc = p - x_words;                                                                                                                                                                                                                            <* 
 *>       DEBUG_YASCII   yLOG_value   ("x_loc"      , x_loc);                                                                                                                                                                                             <* 
 *>       l = strlen (p);                                                                                                                                                                                                                                 <* 
 *>       sprintf (x_txt, "%s", p);                                                                                                                                                                                                                       <* 
 *>       sprintf (x_ori, "%*.*s", l, l, x_orient  + x_loc);                                                                                                                                                                                              <* 
 *>       sprintf (x_var, "%*.*s", l, l, x_variant + x_loc);                                                                                                                                                                                              <* 
 *>       if (m != NULL)  ystrlcpy (x_mean, m , LEN_LABEL);                                                                                                                                                                                               <* 
 *>       else            ystrlcpy (x_mean, "", LEN_LABEL);                                                                                                                                                                                               <* 
 *>       DEBUG_YASCII   yLOG_info    ("x_txt"      , x_txt);                                                                                                                                                                                             <* 
 *>       DEBUG_YASCII   yLOG_info    ("x_ori"      , x_ori);                                                                                                                                                                                             <* 
 *>       DEBUG_YASCII   yLOG_info    ("x_var"      , x_var);                                                                                                                                                                                             <* 
 *>       DEBUG_YASCII   yLOG_info    ("x_mean"     , x_mean);                                                                                                                                                                                            <* 
 *>       /+---(handle glyph)----------------+/                                                                                                                                                                                                           <* 
 *>       if (strcmp (x_txt, "¨") == 0) {                                                                                                                                                                                                                 <* 
 *>          x_pos  = x;                                                                                                                                                                                                                                  <* 
 *>          y_pos += s_tall;                                                                                                                                                                                                                             <* 
 *>       } else if (x_txt [0] == '#' && l > 1) {                                                                                                                                                                                                         <* 
 *>          if      (l == 2)  yascii_mayan__number ('0'      , x_txt [1], x_pos, y_pos, a_mode);                                                                                                                                                         <* 
 *>          else if (l == 3)  yascii_mayan__number (x_txt [1], x_txt [2], x_pos, y_pos, a_mode);                                                                                                                                                         <* 
 *>          else    break;                                                                                                                                                                                                                               <* 
 *>          x_pos += s_wide;                                                                                                                                                                                                                             <* 
 *>       } else if (strcmp (x_txt, "Ï") == 0) {                                                                                                                                                                                                          <* 
 *>          yascii_mayan__display (x_pos + s_left, y_pos + s_topp, 'p', 50,  0,  9,  6, a_mode);                                                                                                                                                         <* 
 *>          x_pos += s_wide;                                                                                                                                                                                                                             <* 
 *>       } else if (strcmp (x_txt, "ÏÏ") == 0) {                                                                                                                                                                                                         <* 
 *>          yascii_mayan__display (x_pos + s_left, y_pos + s_topp, 'p', 50,  0,  9,  6, a_mode);                                                                                                                                                         <* 
 *>          x_pos += s_wide;                                                                                                                                                                                                                             <* 
 *>          yascii_mayan__display (x_pos + s_left, y_pos + s_topp, 'p', 50,  0,  9,  6, a_mode);                                                                                                                                                         <* 
 *>          x_pos += s_wide;                                                                                                                                                                                                                             <* 
 *>       } else if (strcmp (x_txt, "hna") == 0) {                                                                                                                                                                                                        <* 
 *>          s_possess = 'y';                                                                                                                                                                                                                             <* 
 *>          strcpy (s_posstxt, "of");                                                                                                                                                                                                                    <* 
 *>       } else {                                                                                                                                                                                                                                        <* 
 *>          rc = yascii_mayan__word (x_txt, x_mean, x_ori, x_var, &x_pos, &y_pos, a_ornament, a_mode);                                                                                                                                                   <* 
 *>       }                                                                                                                                                                                                                                               <* 
 *>       /+---(next)------------------------+/                                                                                                                                                                                                           <* 
 *>       p = strtok_r (NULL, q, &r);                                                                                                                                                                                                                     <* 
*>       m = strtok_r (NULL, q, &n);                                                                                                                                                                                                                     <* 
*>       DEBUG_YASCII   yLOG_point   ("p"          , p);                                                                                                                                                                                                 <* 
*>    }                                                                                                                                                                                                                                                  <* 
*> }                                                                                                                                                                                                                                                     <*/

/*> char                                                                                <* 
 *> yascii_mayan__prepare   (void)                                                      <* 
 *> {                                                                                   <* 
 *>    /+---(begin)--------------------------+/                                         <* 
 *>    DEBUG_YASCII   yLOG_enter   (__FUNCTION__);                                      <* 
 *>    /+---(defense)------------------------+/                                         <* 
 *>    DEBUG_YASCII   yLOG_point   ("b_words"    , b_words);                            <* 
 *>    --rce;  if (b_words == NULL) {                                                   <* 
 *>       DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);                              <* 
 *>       return rce;                                                                   <* 
 *>    }                                                                                <* 
 *>    DEBUG_YASCII   yLOG_info    ("b_words"    , b_words);                            <* 
 *>    ystrlcpy (x_words, b_words, LEN_RECD);                                           <* 
 *>    x_len = strlen (x_words);                                                        <* 
 *>    DEBUG_YASCII   yLOG_value   ("x_len"     , x_len);                               <* 
 *>    --rce;  if (x_len <= 0) {                                                        <* 
 *>       DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);                              <* 
 *>       return rce;                                                                   <* 
 *>    }                                                                                <* 
 *>    /+---(prepare sizing)-----------------+/                                         <* 
 *>    yascii_mayan__sizer  (a_size, a_gapping, a_ornament, NULL, NULL, NULL, NULL);    <* 
 *>    s_conjunct    = '·';                                                             <* 
 *>    strcpy (s_conjtxt, "");                                                          <* 
 *>    s_possess     = '·';                                                             <* 
 *>    strcpy (s_posstxt, "");                                                          <* 
 *>    /+---(prepare meanings)---------------+/                                         <* 
 *>    DEBUG_YASCII   yLOG_point   ("b_meaning" , b_meaning);                           <* 
 *>    if (b_meaning != NULL)  ystrlpad (b_meaning, x_meaning , '?', '<', x_len + 1);   <* 
 *>    else                    ystrlpad (""      , x_meaning , '?', '<', x_len + 1);    <* 
 *>    DEBUG_YASCII   yLOG_info    ("x_meaning"  , x_meaning);                          <* 
 *>    /+---(prepare orientations)-----------+/                                         <* 
 *>    DEBUG_YASCII   yLOG_point   ("b_orient"  , b_orient);                            <* 
 *>    if (b_orient  != NULL)  ystrlpad (b_orient, x_orient , '?', '<', x_len + 1);     <* 
 *>    else                    ystrlpad (""      , x_orient , '?', '<', x_len + 1);     <* 
 *>    DEBUG_YASCII   yLOG_info    ("x_orient"  , x_orient);                            <* 
 *>    /+---(prepare options)----------------+/                                         <* 
 *>    DEBUG_YASCII   yLOG_point   ("b_variant"  , b_variant);                          <* 
 *>    if (b_variant != NULL)  ystrlpad (b_variant, x_variant, '?', '<', x_len + 1);    <* 
 *>    else                    ystrlpad (""       , x_variant, '?', '<', x_len + 1);    <* 
 *>    DEBUG_YASCII   yLOG_info    ("x_variant"  , x_variant);                          <* 
 *>    /+---(complete)-----------------------+/                                         <* 
 *>    DEBUG_YASCII   yLOG_exit   (__FUNCTION__);                                       <* 
 *>    return 0;                                                                        <* 
 *> }                                                                                   <*/


char
yascii_mayan_driver     (char a_size, char b_words [LEN_RECD], char b_meaning [LEN_RECD], char b_orient [LEN_RECD], char b_variant [LEN_RECD], int x, int y, char a_layout, char a_gapping, int *a_wide, int *a_tall, char a_ornament, char a_mode)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         x_len       =    0;
   char        x_words     [LEN_RECD]  = "";
   char        x_meaning   [LEN_RECD]  = "";
   char        x_orient    [LEN_RECD]  = "";
   char        x_variant   [LEN_RECD]  = "";
   char        x_txt       [LEN_LABEL] = "";
   char        x_mean      [LEN_DESC]  = "";
   char        x_ori       [LEN_LABEL] = "";
   char        x_var       [LEN_LABEL] = "";
   char       *p           = NULL;
   char       *q           = " ";
   char       *r           = NULL;
   char       *m           = NULL;
   char       *n           = NULL;
   int         l           =    0;
   int         x_loc       =    0;
   int         x_pos, y_pos;
   char       *x_hex       = "0123456789ABCDEF";
   char       *h           = NULL;
   uchar       v           =    0;
   /*---(begin)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YASCII   yLOG_point   ("b_words"    , b_words);
   --rce;  if (b_words == NULL) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_info    ("b_words"    , b_words);
   x_len = strlen (b_words);
   DEBUG_YASCII   yLOG_value   ("x_len"     , x_len);
   --rce;  if (x_len <= 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(prepare sizing)-----------------*/
   yascii_mayan__sizer  (a_size, a_gapping, a_ornament, NULL, NULL, NULL, NULL);
   s_start       = '·';
   s_conjunct    = '·';
   strcpy (s_conjtxt, "");
   s_possess     = '·';
   strcpy (s_posstxt, "");
   s_nchar       =    0;
   s_nglyph      =    0;
   strcpy (s_request , "");
   strcpy (s_words   , "");
   strcpy (s_diagram , "");
   strcpy (s_root    , "");
   strcpy (s_meaning , "");
   strcpy (s_orient  , "");
   strcpy (s_variant , "");
   strcpy (s_formal  , "");
   strcpy (s_pretty  , "");
   strcpy (s_glyphish, "");
   /*---(prepare words)------------------*/
   if (b_meaning != NULL) {
      l = strlen (b_meaning);
      if (l > x_len)  x_len = l;
   }
   ystrlpad (b_words  , x_words   , '?', '<', x_len + 1);
   ystrlddel (x_words, '\'', LEN_RECD);
   /*---(prepare meanings)---------------*/
   DEBUG_YASCII   yLOG_point   ("b_meaning" , b_meaning);
   if (b_meaning != NULL)  ystrlpad (b_meaning, x_meaning , '?', '<', x_len + 1);
   else                    ystrlpad (""      , x_meaning , '?', '<', x_len + 1);
   DEBUG_YASCII   yLOG_info    ("x_meaning"  , x_meaning);
   /*---(prepare orientations)-----------*/
   DEBUG_YASCII   yLOG_point   ("b_orient"  , b_orient);
   if (b_orient  != NULL)  ystrlpad (b_orient, x_orient , '?', '<', x_len + 1);
   else                    ystrlpad (""      , x_orient , '?', '<', x_len + 1);
   DEBUG_YASCII   yLOG_info    ("x_orient"  , x_orient);
   /*---(prepare options)----------------*/
   DEBUG_YASCII   yLOG_point   ("b_variant"  , b_variant);
   if (b_variant != NULL)  ystrlpad (b_variant, x_variant, '?', '<', x_len + 1);
   else                    ystrlpad (""       , x_variant, '?', '<', x_len + 1);
   DEBUG_YASCII   yLOG_info    ("x_variant"  , x_variant);
   /*---(walk through text)--------------*/
   p = strtok_r (x_words  , q, &r);
   m = strtok_r (x_meaning, q, &n);
   x_pos = x;
   y_pos = y;
   DEBUG_YASCII   yLOG_point   ("p"          , p);
   while (p != NULL) {
      /*---(prepare)---------------------*/
      DEBUG_YASCII   yLOG_complex ("POS"        , "%4d, %4d", x_pos, y_pos);
      x_loc = p - x_words;
      DEBUG_YASCII   yLOG_value   ("x_loc"      , x_loc);
      l = strlen (p);
      sprintf (x_txt, "%s", p);
      sprintf (x_ori, "%*.*s", l, l, x_orient  + x_loc);
      sprintf (x_var, "%*.*s", l, l, x_variant + x_loc);
      if (m != NULL)  ystrlcpy (x_mean, m , LEN_DESC);
      else            ystrlcpy (x_mean, "", LEN_DESC);
      DEBUG_YASCII   yLOG_info    ("x_txt"      , x_txt);
      DEBUG_YASCII   yLOG_info    ("x_ori"      , x_ori);
      DEBUG_YASCII   yLOG_info    ("x_var"      , x_var);
      DEBUG_YASCII   yLOG_info    ("x_mean"     , x_mean);
      /*---(handle glyph)----------------*/
      if (strcmp (x_txt, "¨") == 0) {
         x_pos  = x;
         y_pos += s_tall;
         yascii_mayan__append (1, x_txt, x_txt, "·", "·", x_txt, "·", "·");
      } else if (x_txt [0] == 'õ' && l > 1) {
         if      (l == 2)  yascii_mayan__number ('0'      , x_txt [1], x_pos, y_pos, a_mode);
         else if (l == 3)  yascii_mayan__number (x_txt [1], x_txt [2], x_pos, y_pos, a_mode);
         else    break;
         x_pos += s_wide;
         yascii_mayan__append (1, x_txt, x_txt, "·", "·", "·", "·", "·");
         yascii_mayan__pretty (0, x_txt, x_txt);
      } else if (x_txt [0] == '#' && l > 1) {
         v = atoi (x_txt + 1);
         yascii_mayan__number ('·' , v, x_pos, y_pos, a_mode);
         x_pos += s_wide;
         yascii_mayan__append (1, x_txt, x_txt, "·", "·", "·", "·", "·");
         yascii_mayan__pretty (0, x_txt, x_txt);
      } else if (strcmp (x_txt, "´") == 0) {
         s_start = 'y';
         yascii_mayan__append (1, x_txt, x_txt, "·", "·", x_txt, "·", "·");
         yascii_mayan__pretty (0, x_txt, x_txt);
      } else if (strcmp (x_txt, "Ï") == 0) {
         yascii_mayan__display (x_pos + s_left, y_pos + s_topp, 'p', 50,  0,  9,  6, a_mode);
         x_pos += s_wide;
         yascii_mayan__append (1, x_txt, x_txt, "·", "·", x_txt, "·", "·");
         yascii_mayan__pretty (0, x_txt, x_txt);
      } else if (strcmp (x_txt, "ÏÏ") == 0) {
         yascii_mayan__display (x_pos + s_left, y_pos + s_topp, 'p', 50,  0,  9,  6, a_mode);
         x_pos += s_wide;
         yascii_mayan__display (x_pos + s_left, y_pos + s_topp, 'p', 50,  0,  9,  6, a_mode);
         x_pos += s_wide;
         yascii_mayan__append (1, x_txt, x_txt, "·", "·", x_txt, "·", "·");
         yascii_mayan__pretty (0, x_txt, x_txt);
      } else if (strcmp (x_txt, "hna") == 0) {
         s_possess = 'y';
         strcpy (s_posstxt, "of");
         yascii_mayan__append (1, x_txt, x_txt, "·", "·", s_posstxt, "·", "·");
         yascii_mayan__pretty (0, x_txt, x_txt);
      } else {
         if (x_txt [0] == 'i')  s_start = 'y';
         if (strchr (x_txt, '›') != NULL)  {
            rc = yascii_mayan__compound (x_txt, x_mean, x_ori, x_var, &x_pos, &y_pos, a_ornament, a_mode);
         } else {
            rc = yascii_mayan__word     (x_txt, x_mean, x_ori, x_var, &x_pos, &y_pos, a_ornament, a_mode);
         }
      }
      /*---(next)------------------------*/
      p = strtok_r (NULL, q, &r);
      m = strtok_r (NULL, q, &n);
      DEBUG_YASCII   yLOG_point   ("p"          , p);
   }
   /*---(save-back)----------------------*/
   /*> if (b_orient  != NULL)  strlcpy (b_orient , x_orient , LEN_RECD);              <* 
    *> if (b_variant != NULL)  strlcpy (b_variant, x_variant, LEN_RECD);              <*/
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit   (__FUNCTION__);
   return 0;
}

char
yASCII_mayan_full       (char a_size, char a_words [LEN_RECD], char a_meaning [LEN_RECD], char a_orient [LEN_RECD], char a_variant [LEN_RECD], int x, int y, char a_layout, char a_gapping, int *a_wide, int *a_tall, char a_ornament, char a_mode)
{
   return yascii_mayan_driver (a_size, a_words, a_meaning, a_orient, a_variant, x, y, a_layout, a_gapping, a_wide, a_tall, a_ornament, a_mode);
}

char
yASCII_updated          (short *r_nchar, short *r_nglyph, char r_request [LEN_RECD], char r_words [LEN_RECD], char r_diagram [LEN_RECD], char r_root [LEN_RECD], char r_meaning [LEN_RECD], char r_orient [LEN_RECD], char r_variant [LEN_RECD])
{
   if (r_nchar    != NULL)  *r_nchar   = s_nchar;
   if (r_nglyph   != NULL)  *r_nglyph  = s_nglyph;
   if (r_request  != NULL)  ystrlcpy (r_request , s_request , LEN_RECD);
   if (r_words    != NULL)  ystrlcpy (r_words   , s_words   , LEN_RECD);
   if (r_diagram  != NULL)  ystrlcpy (r_diagram , s_diagram , LEN_RECD);
   if (r_root     != NULL)  ystrlcpy (r_root    , s_root    , LEN_RECD);
   if (r_meaning  != NULL)  ystrlcpy (r_meaning , s_meaning , LEN_RECD);
   if (r_orient   != NULL)  ystrlcpy (r_orient  , s_orient  , LEN_RECD);
   if (r_variant  != NULL)  ystrlcpy (r_variant , s_variant , LEN_RECD);
   return 0;
}

char
yASCII_pretty           (char r_formal [LEN_RECD], char r_pretty [LEN_RECD], char r_glyphish [LEN_RECD])
{
   if (r_formal   != NULL)  ystrlcpy (r_formal  , s_formal  , LEN_RECD);
   if (r_pretty   != NULL)  ystrlcpy (r_pretty  , s_pretty  , LEN_RECD);
   if (r_glyphish != NULL)  ystrlcpy (r_glyphish, s_glyphish, LEN_RECD);
   return 0;
}


