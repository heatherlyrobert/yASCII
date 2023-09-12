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



/* 0llllllllllllllllllllllllllllllllllllllllhxxllllllllllllllllllllllllllllllllllllllllxxllllllllllllllllllllxxllllllllllllllllllllxxllllllllllxxllllllllllxxlllllllllllllllllllli "lD0i"€ýaj  */
/*  ,x··0···40|·2x···80|·2x···100|·2x···120|·2x···130|·2x···140|·2x···A  ¥··160|·d$··A ",¥··0·I   "¥··j··,y  */

#define   YASCII_JAGU       0
#define   YASCII_DRAG       1
#define   YASCII_LION       2
#define   YASCII_OCTO       3
#define   YASCII_BIRD       4
#define   YASCII_MOTH       5
#define   YASCII_CLOU       6
#define   YASCII_ENEM       7
#define   YASCII_SQUI       8
#define   YASCII_RIVE       9
#define   YASCII_CAVE       10
#define   YASCII_SNAK       11
#define   YASCII_FALL       12
#define   YASCII_WIER       13
#define   YASCII_ELEP       14
#define   YASCII_LLAM       15
#define   YASCII_FISH       16

/*> base consonants                                                                      <* 
 *> ƒ€‚²ƒ‰ ƒ‰€€€‰ ƒ€‰‰€‰                   alligator is (d) for dragon                   <* 
 *>  ž Ÿ ‡…ƒŠ ˆŽˆ                   jaguar is (g) because pronounced similar      <* 
 *> ƒ‰ž Ÿ ƒ†Š… ˆ€Ž€ˆ                   jungle is (n) contains the 'n'                <* 
 *> ‡€ž Ÿ ‡€… €‚ ‰€Ž€‰                                                                 <* 
 *>  „€… ‡€€€‰† ‰Ž‰                                                                 <* 
 *> „€ˆ€ˆˆ „€ˆ€ˆˆ „€ˆˆ€ˆ                                                                 <* 
 *>    d      g      n                                                                   <* 
 *>                                                                                      <* 
 *> ƒ‰€€‰‰ ƒ€‰‰€‰ ƒ‰‰á‰‰ ƒ‰€€€‰            cloud is (l) contains the 'l'                 <* 
 *> ‡…„†    áƒ‚á ‡ ƒ‰‰†            butterfly is (s)                              <* 
 *> ‡…„† ‡‚ƒ† áƒ’„‚á ‡ ƒ‚            waterfall is (w)                              <* 
 *> ‡…„† ž„ŠŠ…Ÿ á„‚“…á ‡€ˆŠˆ†            bird is (y) for yellow                        <* 
 *> ‡…„† žƒ‚Ÿ áŽ„…Žá ‡‰€‰€†                                                          <* 
 *> „ˆ€€ˆˆ „„ˆˆ…ˆ „ˆáˆˆˆ „€ˆ€ˆˆ                                                          <* 
 *>    l      s      w      y                                                            <* 
 *>                                                                                      <* 
 *>                                                                                      <* 
 *> ƒ‰€€‰‰ ŽŽŽ ƒ‰‚ƒ‰‰ ƒœœ‰œ‰ ƒ‰€€‚ƒ     enemy is (q)                                  <* 
 *>  ƒˆ€ ‡  ƒ€† ƒˆˆ‚ ‡’“Š’ž ‡…ƒ‚žŸ     fish/serpent is (t)                           <* 
 *> ƒ†Š † ƒ‚‡„† „†‡… Ÿ „€ž €Š…žŸ     rodent/squirrel is (k)                        <* 
 *> ‡…„€‰ „…‡„† ƒŠ‚ƒŠ‚ Ÿ „‰€† „…Ÿ     maze/cave (h)                                 <* 
 *> ‡† ƒ…  ‡„† áŠŠá ‡’“€€ž ƒœœœœ†     octopus is (z)                                <* 
 *> „€€ˆ€ˆ „€€…„ˆ „€…„€ˆ „„ˆ „““““ˆ                                                   <* 
 *>    q      t      k      h      z                                                     <* 
 *>                                                                                      <* 
 *>                                                                                      <* 
 *> ƒ€–ƒá‰ ƒ€€‰€‰ ƒ²²²²‰ ƒ€‰‰€‰            llama/deer is (m)                             <* 
 *> ‡ ‰‚á  › † Œ    Œ ‡ŽŽŽŽ†            snake is (c)                                  <* 
 *>  „…Ž ‡ ƒ€‚† Œ    Œ ‡ŽŽŽŽ†            blank is (x)                                  <* 
 *>  Œ Ž ‡ „…† ‡²²²²† ‡ŽŽŽŽ†            river is (r) for pn for in pna (possession)   <* 
 *> ƒ‚ áŽ ‡€ˆ€ˆŠ Œ    Œ ‡ŽŽŽŽ†                                                          <* 
 *> „€ˆ€áˆ „œœœœˆ „²²²²ˆ „€ˆˆ€ˆ                                                          <* 
 *>    m      c      x      r                                                            <*/

/*
 *   full  4 = 5  med
 *   full  6 = 10 thiner
 *   full  6 = 10 small
 *   full  6 = 12 tiny
 *
 */

/*  ,x··0···45|·v·9l·y··205|·P··0·j··,y */
/*  ,x··0··220|·v·5l·y··226|·P··0·j··,y */
/*  ,x··0··213|·v·6l·y··220|·P··2h·x··0·j··,y */

/*  ,x··0··220|·v·6l·d··0·j··,y  */

static const char mayanc       [LEN_HUND][LEN_PATH] = {
   /* ---[[ TIER 1 ]]------fulls----------- ----------------lefts------------------ -----------------rights---------------- -------tops-------- ------bottoms------ -------verts------- -------horzs------- --med-- -thin- thinr -sml- tiny u */
   "ƒ€ƒ€‰ ‰€‚ ƒ€‰ ‰€‚€‚ ƒ€‰‰‰€’“‚ ƒ’“€‰‰‰€‚ ƒ€‚²ƒ‰²²‚ ƒ‰€‚²ƒ²²‚ ƒ€‚²ƒ‰²²‚ ƒ²²²²‰²²‚ ƒ²²‰€‚²ƒ‚ ƒ²²‰‰€‚²• ƒ²²‰€‚²ƒ‚ ƒ²²‰²²²²‚ ƒ‰€‰‰€–—‚ ƒ’“€‰‰€‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²‰²‰²²‚ ƒ€‰‰²²²²‚ ƒ’“€‰‰€‰‚ ƒ‰€‰‰€–—‚ ƒ€‚²ƒ²‚ ƒ€‚ƒ²‚ ƒ€‚ƒ‚ ƒ€‚ƒ‚ ƒ€‚‚ ‰ ",
   " † ž Ÿ   ž Ÿ ‡  ƒ€ˆ€ˆ€€ˆ† ‡ˆ€€ˆ€ˆ€‚  ž Ÿ  Œ ‡ ž Ÿ  Œ  ž Ÿ  Œ ‡€‚²ƒ†  Œ Œ   ž Ÿ Œ  ‡ ž Ÿ Œ   ž Ÿ Œ  ‡€‚²ƒ† ‡ €†„€€€† ‡€€€…‡€ † Œ       Œ Œ       Œ Œ   ž  Œ  žŒ    Œ „‚† ‡ƒ…  ž Ÿ Œ  žŸ Œ  žŸŒ  žŸŒ ƒ‰žŒ   ",
   "ƒ‰† ž Ÿ   ž Ÿ ‡‰‚ „‚ † ‡ ƒ… ƒ‰ž Ÿ  Œ ‡ƒ‰ž Ÿ  Œ ƒ‰ž Ÿ  Œ  ž Ÿ  Œ Œ  ƒ‰ž Ÿ Œ  ‡ƒ‰ž Ÿ Œ  ƒ‰ž Ÿ Œ   ž Ÿ ‡ƒ… „‚† ‡‰€‰‰€–—† ‡’“€‰‰€‰† Œ  ƒ‰ž  Œ ƒ‰žŒ    Œ ƒ²²²²²²²† ‡²²²²²²²‚ ƒ‰ž Ÿ Œ ƒ‰žŸ Œ ƒ‰žŸŒ ƒ‰žŸŒ „€ˆ…   ",
   "‡€† ž Ÿ   ž Ÿ ‡€† ƒœœœœœ… † ‡ „œœœœœ‚ ‡€ž Ÿ  Œ ‡‡€Š€†  Œ ‡€„€…  Œ ƒ‰ž Ÿ  Œ Œ  ‡€ž Ÿ Œ  ‡‡€Š€† Œ  ‡€„€… Œ  ƒ‰ž Ÿ ‡ˆœœœœœœ‚ ƒœœœœœœˆ† ‡ €†„€€€† ‡€€€…‡€ † Œ  ‡€ž  Œ ‡€žŒ    Œ Œ       Œ Œ       Œ ‡€ž Ÿ Œ ‡€žŸ Œ ‡€žŸŒ „€ˆˆ…        ",
   "  „€…   „€…   ‡€€€€€€€† ‡€€€€€€€†  „€…  Œ ‡‡   †  Œ ‡€…„€†  Œ ‡€„€…  Œ Œ   „€… Œ  ‡‡   † Œ  ‡€…„€† Œ  ‡€„€… Œ       Œ Œ       Œ ‡ƒ… „‚† Œ   „  Œ  „Œ    Œ Œ       Œ Œ       Œ „€ˆ€ˆ²… „€ˆˆ²… „€ˆˆ…              ",
   "„€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€€€€€€€… „€€€€€€€… „€ˆ€ˆˆ²²… „ˆ²ˆ²ˆ²²… „€€€€ˆ²²… „€…„€ˆ²²… „²²ˆ€ˆ€ˆ… „²²ˆˆ²ˆ²… „²²ˆ€€€€… „²²ˆ€…„€… „²²²²²²²… „²²²²²²²… „ˆœœœœœœ ‘œœœœœœˆ… „²²ˆ€ˆ²²… „€ˆˆ²²²²… „²²²²²²²… „²²²²²²²…                                   ",
   "ƒ‰€€€€€€‚ ƒ€€€€€€‰‚ ƒ‰€€‰€‰€‚ ƒ€‰€‰€€‰‚ ƒ‰€€€‰²²‚ ƒ‰€€€‰²²‚ ƒ²²²²‰²²‚ ƒ²²²²‰²²‚ ƒ²²‰‰€€€‚ ƒ²²‰‰€€€‚ ƒ²²‰²²²²‚ ƒ²²‰²²²²‚ ƒ‰‰€€€€‰‚ ƒ‰‰€€€€‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²‰²‰²²‚ ƒ‰€‰²²²²‚ ƒ‰€€‰€Š‰‚ ƒ‰Š€‰€€‰‚ ƒ‰€€€²‚ ƒ€€€²‚ ƒ€€€‚ ƒ€€€‚ ƒ€€‚ ‡ ",
   "‡…ƒŠ€‚ † ‡ ƒ€Š‚„† ‡…€ˆ…  † ‡  „ˆ€„† ‡…ƒŠ  Œ ƒ†Š…  Œ ‡‰€€€†  Œ ‡‰€€€†  Œ Œ  ‡…ƒŠ Œ  ƒ†Š… Œ  ‡‰€€€† Œ  ‡‰€€€† ‡…ƒŠ  ƒ†ƒŠ… Œ       Œ Œ       Œ Œ  ‡…  Œ ‡…Œ    Œ ƒ† Š€… „€Š ‡‚ ‡…ƒŠ Œ ‡ƒŠ Œ ‡ƒŠŒ ‡ ƒ†Œ ƒ†Œ   ",
   "ƒ†Š… ‡€† ‡€† „Š‡‚  ƒŠ ‡€† ‡€† Š‚  ƒ†Š…  Œ ‡€… €†  Œ ‡…ƒŠ  Œ ƒ†Š…  Œ Œ  ƒ†Š… Œ  ‡€… €† Œ  ‡…ƒŠ Œ  ƒ†Š… ƒ†Š…  ‡€…Š…€‚ ‡‰‰€€€€‰† ‡‰‰€€€€‰† Œ  ƒ†  Œ ƒ†Œ    Œ ‡²²²²²²²† ‡²²²²²²²† ƒ†ŠŠ Œ ƒ†ŠŠ Œ ƒ†ŠŠŒ ƒ†Š†Œ „…€…   ",
   "‡€… €‚     ƒ€ „€†  Š…„€…   „€…„Š  ‡€… €†  Œ ‡€€€‰†  Œ ƒ†Š…  Œ ‡€… €†  Œ Œ  ‡€… €† Œ  ‡€€€‰† Œ  ƒ†Š… Œ  ‡€… €† ‡ˆ€ˆ€€€ˆ† ‡ˆ€€€€€ˆ† ‡…ƒŠ  ƒ†ƒŠ… Œ  ‡€…  Œ ‡€…Œ    Œ Œ       Œ Œ       Œ ‡€… € Œ ‡€…  Œ ‡€… Œ „€ˆˆ…        ",
   "‡€€€‰…  † ‡  „‰€€€†  „‰€       €‰…  ‡€€€‰†  Œ ‡€ˆ€ˆ†  Œ ‡€… €†  Œ ‡€€€‰†  Œ Œ  ‡€€€‰† Œ  ‡€ˆ€ˆ† Œ  ‡€… €† Œ  ‡€€€‰† Œ       Œ Œ       Œ ƒ†Š…  ‡€…Š…€‚ Œ  ‡€€  Œ ‡€€Œ    Œ Œ       Œ Œ       Œ „€ˆ€ˆ²… „€ˆˆ²… „€ˆˆ…              ",
   "„€ˆ€ˆ€€€… „€€€ˆ€ˆ€… „€€ˆ€€ˆ€… „€ˆ€€ˆ€€… „€ˆ€ˆˆ²²… „““““ˆ²²… „€€€€ˆ²²… „€ˆ€ˆˆ²²… „²²ˆ€ˆ€ˆ… „²²ˆ““““… „²²ˆ€€€€… „²²ˆ€ˆ€ˆ… „²²²²²²²… „²²²²²²²… „ˆ€ˆ€€€ˆ… „ˆ€€€€€ˆ… „²²ˆ€ˆ²²… „€ˆˆ²²²²… „²²²²²²²… „²²²²²²²…                                   ",
   "ƒƒ€‰€‰€‚‚ ƒƒ€‰€‰€‚‚ ƒƒ€‰€‰€‚‚ ƒ€‰€‰€‰€‚ ƒ€‰‰€‰²²‚ ƒ€‰‰€‰²²‚ ƒ€‰‰€‰²²‚ ƒ’’——‰²²‚ ƒ²²‰€‰‰€‚ ƒ²²‰€‰‰€‚ ƒ²²‰€‰‰€‚ ƒ²²‰’’——‚ ƒƒ€‰€‰€‚‚ ƒ‰€‰€‰€‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²‰²‰²²‚ ƒ€‰‰²²²²‚ ƒƒ€‰€‰€‚‚ ƒ‰€‰€‰€‰‚ ƒ€‰€‰²‚ ƒ€‰‰²‚ ƒ€‰‰‚ ƒ€‰‰‚ ƒ€‰‚ ˆ ",
   "ƒˆ Žˆ‚ ƒ ŽŽ‚ ƒ ŽŽŽ‚ ‡ŽŽŽ † ˆŽˆ  Œ ˆŽˆ  Œ ˆŽˆ  Œ ‡€‰‰€Š  Œ Œ  ˆŽˆ Œ  ˆŽˆ Œ  ˆŽˆ Œ  ‡€‰‰€Š ƒˆ Žˆ‚ ‡€ Ž€† Œ       Œ Œ       Œ Œ  ˆ  Œ ˆŒ    Œ ƒˆ Žˆ‚ ‡€ Ž€† ˆŽˆ Œ ˆŽ Œ ˆŽŒ ˆŽŒ ˆŒ   ",
   "‡ˆ€ Ž€ˆ† ‡€ Ž€Ž† ‡ˆ€ Ž€ˆ† ‡ˆ€ Ž€ˆ† ˆ€Ž€ˆ  Œ ˆŽˆ  Œ ‰€Ž€‰  Œ ˆŽˆ  Œ Œ  ˆ€Ž€ˆ Œ  ˆŽˆ Œ  ‰€Ž€‰ Œ  ˆŽˆ ‡ˆ€ Ž€ˆ† ‡€€ Ž€€† ‡ƒ€‰€‰€‚† ‡‰€‰€‰€‰† Œ  ˆ€  Œ ˆ€Œ    Œ ‡²²²²²²²† ‡²²²²²²²† ˆ€€ˆ Œ ˆ€€ Œ ˆ€€Œ ‰ŽŒ „€ˆ…   ",
   "‡‰€Ž €‰† ‡Ž€Ž €† ‡‰€Ž €‰† ‡‰€Ž €‰† ‰€Ž€‰  Œ ‰€Ž€‰  Œ ‰Ž‰  Œ ˆ€Ž€ˆ  Œ Œ  ‰€Ž€‰ Œ  ‰€Ž€‰ Œ  ‰Ž‰ Œ  ˆ€Ž€ˆ ‡‰€Ž €‰† ‡€€Ž €€† ƒˆ Žˆ‚ ‡€ Ž€† Œ  ‰€Ž  Œ ‰€ŽŒ    Œ Œ       Œ Œ       Œ ‰Ž‰ Œ ‰Ž Œ ‰ŽŒ „€ˆˆ…        ",
   "„‰Ž ‰… „ŽŽ … „ŽŽŽ …  ŽŽŽ† ‰Ž‰  Œ ‰Ž‰  Œ ‡€…„€†  Œ ‰€Ž€‰  Œ Œ  ‰Ž‰ Œ  ‰Ž‰ Œ  ‡€…„€† Œ  ‰€Ž€‰ Œ       Œ Œ       Œ ‡ˆ€ Ž€ˆ† ‡€€ Ž€€† Œ  ‰Ž  Œ ‰ŽŒ    Œ Œ       Œ Œ       Œ „€ˆ€ˆ²… „€ˆˆ²… „€ˆˆ…              ",
   "„„€ˆ€ˆ€…… „„€ˆ€ˆ€…… „„€ˆ€ˆ€…… „€ˆ€ˆ€ˆ€… „€ˆˆ€ˆ²²… „€ˆˆ€ˆ²²… „€…„€ˆ²²… „€ˆˆ€ˆ²²… „²²ˆ€ˆˆ€… „²²ˆ€ˆˆ€… „²²ˆ€…„€… „²²ˆ€ˆˆ€… „²²²²²²²… „²²²²²²²… „‰€Ž €‰… „€€Ž €€… „²²ˆ€ˆ²²… „€ˆˆ²²²²… „²²²²²²²… „²²²²²²²…                                   ",
   /* ---[[ TIER 2 ]]------fulls----------- -----------------lefts----------------- -----------------rights---------------- -------tops-------- ------bottoms------ -------verts------  -------horzs------- --med-- -thin  thinr -sml- tiny u */
   "ƒ€‰€‰€‰€‚ ƒ‰€€‰€€‰‚ ƒ€€€€€€€‚ ƒ€€€€€€€‚ ƒ‰€€‰‰²²‚ ƒ€€€€‰²²‚ ƒ‰€€‰‰²²‚ ƒ²²²²‰²²‚ ƒ²²‰‰€€‰‚ ƒ²²‰€€€€‚ ƒ²²‰‰€€‰‚ ƒ²²‰²²²²‚ ƒ‰‰€€€‰‰‚ ƒ‰‰‰€‰‰‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²‰²‰²²‚ ƒ‰€‰²²²²‚ ƒ‰‰€€€‰‰‚ ƒ‰‰‰€‰‰‰‚ ƒ‰€€‰²‚ ƒ€€‰²‚ ƒ€€‰‚ ƒ€€‰‚ ƒ€€‚ ƒ ",
   " ‡…„†  ‡…  „† ‡€‰€‰€‰€† ‡€‰€‰€‰€† ‡…„†  Œ ‡‰€€‰†  Œ ‡…„†  Œ ‡‰€€‰†  Œ Œ  ‡…„† Œ  ‡‰€€‰† Œ  ‡…„† Œ  ‡‰€€‰† ‡… „† ‡‚ ƒ† Œ       Œ Œ       Œ Œ  ‡…  Œ ‡…Œ    Œ ‡… „† ‡‚ ƒ† ‡…„† Œ ‡…„† Œ ‡…„†Œ ‡…„†Œ ‡…„Œ   ",
   " ‡…„†  ‡…  „†  … … …   ‡…„†  ‡…„†  Œ ‡…„†  Œ ‡…„†  Œ ‡…„†  Œ Œ  ‡…„† Œ  ‡…„† Œ  ‡…„† Œ  ‡…„† ‡… „† ‡‚ ƒ† ‡‰‰€€€‰‰† ‡‰‰‰€‰‰‰† Œ  ‡…  Œ ‡…Œ    Œ ‡²²²²²²²† ‡²²²²²²²† ‡…„† Œ ‡…„† Œ ‡…„†Œ ‡…„†Œ „ˆˆ…   ",
   " ‡…„†  ‡…  „†  ‚ ‚ ‚   ‡…„†  ‡…„†  Œ ‡…„†  Œ ‡…„†  Œ ‡…„†  Œ Œ  ‡…„† Œ  ‡…„† Œ  ‡…„† Œ  ‡…„† ‡ˆˆˆ€ˆˆˆ† ‡ˆˆ€€€ˆˆ† ‡… „† ‡‚ ƒ† Œ  ‡…  Œ ‡…Œ    Œ Œ       Œ Œ       Œ ‡…„† Œ ‡…„† Œ ‡…„†Œ „ˆˆˆ…        ",
   " ‡…„†  ‡…  „† ‡€ˆ€ˆ€ˆ€† ‡€ˆ€ˆ€ˆ€† ‡…„†  Œ ‡ˆ€€ˆ†  Œ ‡ˆ€€ˆ†  Œ ‡…„†  Œ Œ  ‡…„† Œ  ‡ˆ€€ˆ† Œ  ‡ˆ€€ˆ† Œ  ‡…„† Œ       Œ Œ       Œ ‡… „† ‡‚ ƒ† Œ  ‡…  Œ ‡…Œ    Œ Œ       Œ Œ       Œ „ˆˆˆˆ²… „ˆˆˆ²… „ˆˆˆ…              ",
   "„€ˆ€ˆ€ˆ€… „ˆ€€ˆ€€ˆ… „€€€€€€€… „€€€€€€€… „ˆ€€ˆˆ²²… „€€€€ˆ²²… „–“–“ˆ²²… „ˆ€€ˆˆ²²… „²²ˆˆ€€ˆ… „²²ˆ€€€€… „²²ˆ–“–“… „²²ˆˆ€€ˆ… „²²²²²²²… „²²²²²²²… „ˆˆˆ€ˆˆˆ… „ˆˆ€€€ˆˆ… „²²ˆˆˆ²²… „ˆ€ˆ²²²²… „²²²²²²²… „²²²²²²²…                                   ",
   "ƒ€€€‰€€€‚ ƒ€€€‰€€€‚ ƒ€€€‰€€€‚ ƒ€€€‰€€€‚ ƒ€‰‰€‰²²‚ ƒˆ‰‰ˆ‰²²‚ ƒ€‰‰€‰²²‚ ƒ²²²²‰²²‚ ƒ²²‰€‰‰€‚ ƒ²²‰ˆ‰‰ˆ‚ ƒ²²‰€‰‰€‚ ƒ²²‰²²²²‚ ƒ‰€‰€‚ ƒ€‰€‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²‰²‰²²‚ ƒ€‰‰²²²²‚ ƒ‰€€€‚ ƒ€€€‰‚ ƒ€‰€‰²‚ ƒ€‰€²‚ ƒ€‰€‚ ƒ€‰€‚ ƒ€‰‚ ‚ ",
   "                                Œ ‡  †  Œ     Œ ‡€‰‰€†  Œ Œ     Œ  ‡  † Œ     Œ  ‡€‰‰€† ƒœƒ€ˆ       ˆ€‚œ‚ Œ       Œ Œ       Œ Œ     Œ  Œ    Œ ƒœƒ€…       „€‚œ‚    Œ    Œ   Œ   Œ  Œ   ",
   "‡€‚  ƒ€† ‡€‰€ˆ€‰€† ‡€‰€Š€‰€† ‡€€€ˆ€€€† ‡‚ƒ†  Œ ž„ŠŠ…Ÿ  Œ ‡‚ƒ†  Œ     Œ Œ  ‡‚ƒ† Œ  ž„ŠŠ…Ÿ Œ  ‡‚ƒ† Œ     ‡€Š€€€€€† ‡€€€€€Š€† ‡œƒ€ˆ   † ‡   ˆ€‚œ† Œ  ‡‚  Œ ‡‚Œ    Œ ‡²²²²²²²† ‡²²²²²²²† ‡‚ƒ† Œ ‡‚ƒ Œ ‡‚ƒŒ ‡‚ƒŒ „„……   ",
   "ž „‚Šƒ… Ÿ ‡€ˆ‚ ƒˆ€†  ž   Ÿ   ƒœœœ‚  ž„ŠŠ…Ÿ  Œ žƒ‚Ÿ  Œ ž„ŠŠ…Ÿ  Œ ‡‚ƒ†  Œ Œ  ž„ŠŠ…Ÿ Œ  žƒ‚Ÿ Œ  ž„ŠŠ…Ÿ Œ  ‡‚ƒ† ‡ˆ€‰   † ‡   ‰€ˆ† ‡€Š€€€€€† €€€€€Š€† Œ  ž„Š  Œ ž„ŠŒ    Œ Œ       Œ Œ       Œ ž„Š…Ÿ Œ ž„Š… Œ ž„Š…Œ „„ˆ……        ",
   "ž ƒ…„‚ Ÿ   ž Ÿ   ‡€†   ‡€† ‡€ˆ€Š€ˆ€† žƒ‚Ÿ  Œ ‡„ˆˆ…  Œ ‡„ˆˆ…†  Œ ž„ŠŠ…Ÿ  Œ Œ  žƒ‚Ÿ Œ  ‡„ˆˆ… Œ  ‡„ˆˆ…† Œ  ž„ŠŠ…Ÿ Œ       Œ Œ       Œ ‡„€‰       ‰€…† Œ  žƒ  Œ žƒŒ    Œ Œ       Œ Œ       Œ „„ˆ…ˆ²… „„ˆ…²… „„ˆ……              ",
   "„€„€ˆ€…€… „€€… „€€… „€ˆ€€€ˆ€… „€€€ˆ€€€… „„ˆˆ…ˆ²²… „²²²²ˆ²²… „€€€€ˆ²²… „„ˆˆ…ˆ²²… „²²ˆ„ˆˆ…… „²²ˆ²²²²… „²²ˆ€€€€… „²²ˆ„ˆˆ…… „²²²²²²²… „²²²²²²²… „œœœˆ€ˆ€… „€ˆ€ˆœœœ… „²²ˆ„ˆ²²… „„ˆˆ²²²²… „²²²²²²²… „²²²²²²²…                                   ",
   "ƒ‰‰á‰áá‰‚ ƒ‰‰á‰áá‰‚ ƒ‰‰á‰áá‰‚ ƒ‰‰á‰áá‰‚ ƒ‰‰á‰‰²²‚ ƒ‰‰á‰‰²²‚ ƒ‰‰á‰‰²²‚ ƒ²²²²‰²²‚ ƒ²²‰‰‰á‰‚ ƒ²²‰‰‰á‰‚ ƒ²²‰‰‰á‰‚ ƒ²²‰²²²²‚ ƒ‰‰á‰‰á‰‚ ƒ‰‰á‰‰á‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²‰²‰²²‚ ƒ‰‰‰²²²²‚ ƒ‰‰á‰‰á‰‚ ƒ€‰‰á‰‰€‚ ƒ‰á‰‰²‚ ƒá‰‰²‚ ƒá‰‰‚ ƒá‰‰‚ ƒ‰‰‚ „ ",
   "áŽáŽŽá ááŽŽŽá áŽ€€€Žá áŽŽáŽá áŽŽá  Œ á‰‚‰á  Œ áŽŽá  Œ ‡‰‰á‰†  Œ Œ  áŽŽá Œ  á‰‚‰á Œ  áŽŽá Œ  ‡‰‰á‰† áŽŽŽŽá á‰‚‰á‚‰á Œ       Œ Œ       Œ Œ  áŽ  Œ áŽŒ    Œ áŽŽŽŽá ŽáƒŽ‚á áŽŽá Œ áŽá Œ áŽáŒ áŽáŒ ááŒ   ",
   "áŽŽŽá áŽŽŽáŽá áŽáŽá áŽáŽá áŽŽá  Œ áŽŽá  Œ áŽŽá  Œ áŽŽá  Œ Œ  áŽŽá Œ  áŽŽá Œ  áŽŽá Œ  áŽŽá áŽŽŽá áŽŽáŽá ‡‰‰á‰‰á‰† ‡‰‰á‰‰á‰† Œ  áŽ  Œ áŽŒ    Œ ‡²²²²²²²† ‡²²²²²²²† áŽá Œ áŽá Œ áŽáŒ áŽáŒ áŽá…   ",
   "áŽŽáŽá áŽŽáŽŽá áŽáŽŽá áŽŽŽŽá áŽŽá  Œ áŽŽá  Œ áŽŽá  Œ áŽŽá  Œ Œ  áŽŽá Œ  áŽŽá Œ  áŽŽá Œ  áŽŽá ‡ˆáˆˆˆáˆ† ‡ˆáˆˆˆ„€† áŽŽŽŽá á‰‚‰á‚‰á Œ  áŽ  Œ áŽŒ    Œ Œ       Œ Œ       Œ áŽŽá Œ áŽá Œ áŽáŒ „ˆˆˆ…        ",
   "áŽáŽá áŽŽáŽá áŽ€€€€Žá áŽáŽá áŽŽá  Œ áŽˆ…á  Œ ‡ˆáˆˆ†  Œ áŽŽá  Œ Œ  áŽŽá Œ  áŽˆ…á Œ  ‡ˆáˆˆ† Œ  áŽŽá Œ       Œ Œ       Œ áŽŽŽá áŽŽáŽá Œ  áŽ  Œ áŽŒ    Œ Œ       Œ Œ       Œ „áˆˆˆ²… „ˆˆˆ²… „ˆˆˆ…              ",
   "„ˆáˆˆˆˆˆ… „ˆáˆˆˆˆˆ… „ˆáˆˆˆˆˆ… „ˆáˆˆˆˆˆ… „ˆáˆˆˆ²²… „ˆáˆˆˆ²²… „€€€€ˆ²²… „ˆáˆˆˆ²²… „²²ˆˆáˆˆ… „²²ˆˆáˆˆ… „²²ˆ€€€€… „²²ˆˆáˆˆ… „²²²²²²²… „²²²²²²²… „ˆáˆˆˆáˆ… „ˆáˆˆˆ„€… „²²ˆˆá²²… „ˆáˆ²²²²… „²²²²²²²… „²²²²²²²…                                   ",
   "ƒ‰€€€€€‰‚ ƒ‰€€€€€‰‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ‰€€€‰²²‚ ƒ€‰‰‰‰²²‚ ƒ‰€€€‰²²‚ ƒ²²²²‰²²‚ ƒ²²‰‰€€€‚ ƒ²²‰€‰‰‰‚ ƒ²²‰‰€€€‚ ƒ²²‰²²²²‚ ƒ‰€‰€€€‰‚ ƒ‰€€€‰€‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²‰²‰²²‚ ƒ€‰‰²²²²‚ ƒ‰€€‰‰‰‰‚ ƒ‰‰‰‰€€‰‚ ƒ‰€€‰²‚ ƒ‰€€²‚ ƒ‰€€‚ ƒ‰€€‚ ƒ‰‰‚ … ",
   "‡ ƒ‰‰‚ †Ÿ ž‡ ƒ‰‰‚ † ‡ˆ€ˆ€ˆ€Š† ‡Š€ˆ€ˆ€ˆ† ‡ ƒ‰‰†  Œ ‡ ƒ‚  Œ ‡ ƒ‰‰†  Œ ‡‰€€€†  Œ Œ  ‡ ƒ‰‰† Œ  ‡ ƒ‚ Œ  ‡ ƒ‰‰† Œ  ‡‰€€€† ‡  ƒ‰‰† ‡‰‰‚  † Œ       Œ Œ       Œ Œ  ‡‰†  Œ ‡‰†Œ    Œ ‡  ƒ‚ ƒ‚  † ‡ƒ‰‰† Œ ‡ƒ‰‰ Œ ‡ƒ‰‰Œ ‡ƒ‚Œ ƒ‚Œ   ",
   "‡ ƒ‚ Ÿ ž ƒ‚ † ‡€‰‰‰‚ †Ÿ ž ƒ‰‰‰€† ‡ ƒ‚  Œ ‡€ˆŠˆ†  Œ ‡ ƒ‚  Œ ‡ ƒ‰‰†  Œ Œ  ‡ ƒ‚ Œ  ‡€ˆŠˆ† Œ  ‡ ƒ‚ Œ  ‡ ƒ‰‰† ‡  ƒ‚ ƒ‚  † ‡‰€‰€€€‰† ‡‰€€€‰€‰† Œ  ‡‚  Œ ‡‚Œ    Œ ‡²²²²²²²† ‡²²²²²²²† ƒ‚ Œ ƒ‚ Œ ƒ‚Œ ‡ˆŠˆŒ „ˆˆ…   ",
   "‡€ˆˆˆ… †Ÿ ž‡ „ˆˆˆ€† ‡ „… Ÿ ž „… † ‡€ˆŠˆ†  Œ ‡‰ˆ‰ˆ†  Œ ‡€ˆŠˆ†  Œ ‡ ƒ‚  Œ Œ  ‡€ˆŠˆ† Œ  ‡‰ˆ‰ˆ† Œ  ‡€ˆŠˆ† Œ  ‡ ƒ‚ ‡ˆ€€ˆŠˆˆ† ‡ˆˆŠˆ€€ˆ† ‡  ƒ‰‰† ‡‰‰‚  † Œ  Šˆ†  Œ Šˆ†Œ    Œ Œ       Œ Œ       Œ ‡ˆŠˆ† Œ ‡ˆŠˆ Œ ‡ˆŠˆŒ „ˆ€ˆ…        ",
   "‡‰€‰€‰€Š† ‡Š€‰€‰€‰† ‡ „ˆˆ… †Ÿ ž „ˆˆ… † ‡‰€‰€†  Œ ‡€€€€†  Œ ‡‰ˆ‰ˆ†  Œ ‡€ˆŠˆ†  Œ Œ  ‡‰€‰€† Œ  ‡€€€€† Œ  ‡‰ˆ‰ˆ† Œ  ‡€ˆŠˆ† Œ       Œ Œ       Œ ‡  ƒ‚ ƒ‚  † Œ  ‡€†  Œ ‡€†Œ    Œ Œ       Œ Œ       Œ „ˆ€ˆˆ²… „ˆ€ˆ²… „ˆ€ˆ…              ",
   "„€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „ˆ€€€€€ˆ… „ˆ€€€€€ˆ… „€ˆ€ˆˆ²²… „²²²²ˆ²²… „––––ˆ²²… „€ˆ€ˆˆ²²… „²²ˆ€ˆ€ˆ… „²²ˆ²²²²… „²²ˆ––––… „²²ˆ€ˆ€ˆ… „²²²²²²²… „²²²²²²²… „ˆ€€ˆŠˆˆ… „ˆˆŠˆ€€ˆ… „²²ˆˆˆ²²… „ˆˆˆ²²²²… „²²²²²²²… „²²²²²²²…                                   ",
   /* ---[[ TIER 3 ]]------fulls----------- -----------------lefts----------------- -----------------rights---------------- -------tops-------- ------bottoms------ -------verts------- -------horzs------- --med-- -thin  thinr -sml- tiny u */
   "ƒ€€€‰€€€‚ ƒ€€€‰€€€‚ ƒ€€€‰€€€‚ ƒ€€€‰€€€‚ ƒ€€‰€‰²²‚ ƒ€‰ˆ€‰²²‚ ƒ€€‰€‰²²‚ ƒ²²²²‰²²‚ ƒ²²‰€€‰€‚ ƒ²²‰€‰ˆ€‚ ƒ²²‰€€‰€‚ ƒ²²‰²²²²‚ ƒ‰€€‰€€‰‚ ƒ‰€€‰€€‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²‰²‰²²‚ ƒ€€‰²²²²‚ ƒ‰€€€‰€‰‚ ƒ‰€‰€€€‰‚ ƒ€€‰‰²‚ ƒ€€‰²‚ ƒ€€‰‚ ƒ€€€‚ ƒ€€‚ € ",
   "  ƒˆ€€‚ ƒ€€ˆ‚     ƒˆ€€‚ ƒ€€ˆ‚    ƒˆ€  Œ ƒ†Š †  Œ  ƒˆ€  Œ ‡€€‰€†  Œ Œ   ƒˆ€ Œ  ƒ†Š † Œ   ƒˆ€ Œ  ‡€€‰€†  ƒˆ€€ €€ˆ‚  Œ       Œ Œ       Œ Œ   ƒ  Œ  ƒŒ    Œ Š ƒˆ€ €ˆ‚ Š  ƒˆ Œ  ƒˆ Œ  ƒˆŒ ƒ†ŠŒ †Š Œ   ",
   "ƒ€†Š  ‡† ‡†  Š‡€‚ ƒ€†Š  ‡† ‡†  Š‡€‚ ƒ†Š †  Œ ‡…„€‰  Œ ƒ†Š †  Œ  ƒˆ€  Œ Œ  ƒ†Š † Œ  ‡…„€‰ Œ  ƒ†Š † Œ   ƒˆ€ ƒ†Š  † ‡  Š‡‚ ‡‰€€‰€€‰† ‡‰€€‰€€‰† Œ  ƒ†  Œ ƒ†Œ    Œ ‡²²²²²²²† ‡²²²²²²²† ƒ†Š† Œ ƒ†Š Œ ƒ†ŠŒ ‡…„€Œ „€ˆ…   ",
   "‡… „€‰€† „€‰€… „† ‡… „€‰€† „€‰€… „† ‡…„€‰  Œ ‡† ƒ…  Œ ‡…„€‰  Œ ƒ†Š †  Œ Œ  ‡…„€‰ Œ  ‡† ƒ… Œ  ‡…„€‰ Œ  ƒ†Š † ‡ˆ…„€€€ˆ† ‡ˆ€€€…„ˆ†  ƒˆ€€ €€ˆ‚  Œ  ‡…„  Œ ‡…„Œ    Œ Œ       Œ Œ       Œ ‡…„€ Œ ‡…„€ Œ ‡…„€Œ „€ˆ€…        ",
   "‡†  ƒ…   ƒ…   ‡† ‡†  ƒ…   ƒ…   ‡† ‡† ƒ…  Œ ‡€€ˆ€†  Œ ‡€€ˆ€†  Œ ‡…„€‰  Œ Œ  ‡† ƒ… Œ  ‡€€ˆ€† Œ  ‡€€ˆ€† Œ  ‡…„€‰ Œ       Œ Œ       Œ ƒ†Š  † ‡  Š‡‚ Œ  ‡†   Œ ‡† Œ    Œ Œ       Œ Œ       Œ „€ˆ€ˆ²… „€ˆ€²… „€ˆ€…              ",
   "„€€€ˆ€€ˆ… „€ˆ€€€€€… „€€€ˆ€€ˆ… „€ˆ€€€€€… „€€ˆ€ˆ²²… „€€ˆ€ˆ²²… „––––ˆ²²… „€€ˆ€ˆ²²… „²²ˆ€€ˆ€… „²²ˆ€€ˆ€… „²²ˆ––––… „²²ˆ€€ˆ€… „²²²²²²²… „²²²²²²²… „ˆ…„€€€ˆ… „ˆ€€€…„ˆ… „²²ˆ€ˆ²²… „€€ˆ²²²²… „²²²²²²²… „²²²²²²²…                                   ",
   "ŽŽŽŽ‚ ƒœœœ‰œ‰ŽŽ ƒŽŽŽŽ ‰œ‰œœœ‚ ŽŽŽ²²‚ ŽŽŽ²²‚ ƒ““––‰²²‚ ƒ  ƒ€‰²²‚ ƒ²²ŽŽŽ ƒ²²ŽŽŽ ƒ²²‰““––‚ ƒ²²‰  ƒ€‚ ƒœœœ‰œ‰ŽŽ ‰œ‰œœœ‰ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²‰²‰²²‚ ƒ€€ƒ²²²²‚ ƒœœœ‰€‰ŽŽ ‰€‰œœœ‚ ŽŽ²‚ Ž²‚ Ž‚ Ž‚ Ž‚ Œ ",
   "‡€ƒ€€† Ž  „€† Ž ‡€€‚  €†  ‡€…   ‡  ƒ€†  Œ ‡€‚  †  Œ ‡  ƒ€†  Œ Ÿƒ‚‡„†  Œ Œ  ‡  ƒ€† Œ  ‡€‚  † Œ  ‡  ƒ€† Œ  Ÿƒ‚‡„† Ž  „€† Ž  ‡€…   Œ       Œ Œ       Œ Œ  Ÿ Ž  Œ Ÿ ŽŒ    Œ Ž  „€† Ž  ‡€…   ‡ƒ‚ƒ  Œ ‡ƒ‚Š Œ ‡ƒ‚ŠŒ ‡ƒ‚ŠŒ ‡‚Œ   ",
   "Ÿƒ‚ ‡…„† Œ   ŽŽŽŽŽ ‡…„† ƒ‚ž     Ÿƒ‚‡„†  Œ ‡…†ƒ‚ž  Œ Ÿƒ‚‡„†  Œ Ÿ„…‡„†  Œ Œ  Ÿƒ‚‡„† Œ  ‡…†ƒ‚ž Œ  Ÿƒ‚‡„† Œ  Ÿ„…‡„† ‡€‰€‰€  Ž Ž€‰€‰€† ‡œœœ‰€‰ŽŽ ‰€‰œœœ† Œ  Ÿƒ‚  Œ Ÿƒ‚Œ    Œ ‡²²²²²²²† ‡²²²²²²²† Ÿ„…ƒ… Œ Ÿ„…Š Œ Ÿ„…ŠŒ Ÿ„…ŠŒ „ˆˆ…   ",
   "Ÿ„… ‡…„† ‡€‰€‰€ ‡…„† „…ž ŽŽƒ€‰€‰€† Ÿ„…‡„†  Œ ‡…†„…ž  Œ Ÿ„…‡„†  Œ Ÿ ‡„†  Œ Œ  Ÿ„…‡„† Œ  ‡…†„…ž Œ  Ÿ„…‡„† Œ  Ÿ ‡„† ‡€á€á€ˆ ŽŽ €á€á€† Ž  „€† Ž  ‡€…   Œ  Ÿ„…  Œ Ÿ„…Œ    Œ Œ       Œ Œ       Œ Ÿ ‡… Œ Ÿ Š Œ Ÿ ŠŒ „€……        ",
   "Ÿ  ‡…„† „ „ „  Œ ‡…„†Ž  ž Ž  … … … Ÿ ‡„†  Œ ‡…†Ž ž  Œ Ÿ ‡„†  Œ ‡€€…„†  Œ Œ  Ÿ ‡„† Œ  ‡…†Ž ž Œ  Ÿ ‡„† Œ  ‡€€…„† Œ       Œ Œ       Œ ‡€‰€‰€  Ž Ž€‰€‰€† Œ  ‡    Œ ‡  Œ    Œ Œ       Œ Œ       Œ „€€ˆ…²… „€€…²… „€€……              ",
   "„€€€ˆ…„ˆ… „€ˆ€ˆ€ˆ „ˆ…„…²²²… ŽŽˆ€ˆ€ˆ€… „€€…„ˆ²²… „…„€€ˆ²²… „€€…„ˆ²²… „——’’ˆ²²… „²²ˆ€€…„ˆ „²²„…„€€… „²²ˆ€€…„… „²²ˆ——’’… „²²²²²²²… „²²²²²²²… „€á€á€ˆ ŽŽ €á€á€… „²²ˆŽŽ²²… ŽŽŽˆ²²²²… „²²²²²²²… „²²²²²²²…                                   ",
   "ƒ‰‰‚ ƒ‰‰‚ ƒ‰‰€‰€‰‰‚ ƒ‰‰‚ ƒ‰‰‚ ƒ‰‰€‰€‰‰‚ ƒ‰‚ƒ‰‰²²‚ ƒ‰ˆˆ‰‰²²‚ ƒ‰‚ƒ‰‰²²‚ ƒ²²²²‰²²‚ ƒ²²‰‰‚ƒ‰‚ ƒ²²‰‰ˆˆ‰‚ ƒ²²‰‰‚ƒ‰‚ ƒ²²‰²²²²‚ ƒ‰‰‚ ƒ‰‰‚ ƒ‰‰ˆ€ˆ‰‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²‰²‰²²‚ ƒ‰‰‰²²²²‚ ƒ‰‰‰‰‚ ƒ‰‰ˆ€ˆ‰‰‚ ƒ‰€‰‰²‚ ƒ‰‰‰²‚ ƒ‰‰‰‚ ƒ‰‰‰‚ ƒ‰‰‚ Š ",
   "ƒˆ ˆ‚ „†‡… ƒˆ ˆ‚ „†‡… ƒˆˆ‚  Œ „†‡…  Œ ƒˆˆ‚  Œ ‡‰‚ƒ‰†  Œ Œ  ƒˆˆ‚ Œ  „†‡… Œ  ƒˆˆ‚ Œ  ‡‰‚ƒ‰† ƒˆ ˆ‚ „†‡… Œ       Œ Œ       Œ Œ  ƒˆ  Œ ƒˆŒ    Œ ƒˆ ˆ‚ „†‡… ƒˆ‚ Œ ƒˆ‚ Œ ƒˆ‚Œ „†‡Œ †Œ   ",
   "‡†‡† ƒŠ‚ ƒŠ‚ ‡†‡† ƒŠ‚ ƒŠ‚ „†‡…  Œ ƒŠ‚ƒŠ‚  Œ „†‡…  Œ ƒˆˆ‚  Œ Œ  „†‡… Œ  ƒŠ‚ƒŠ‚ Œ  „†‡… Œ  ƒˆˆ‚ „†‡… ƒŠ‚ ƒŠ‚ ‡‰‰‚ ƒ‰‰† ‡‰‰ˆ€ˆ‰‰† Œ  „†  Œ „†Œ    Œ ‡²²²²²²²† ‡²²²²²²²† „†‡… Œ „†‡ Œ „†‡Œ ƒŠ‰ŠŒ „€ˆ…   ",
   "ƒˆ‰ˆ‚ „†„‰…‡… ƒˆ‰ˆ‚ „†„‰…‡… ƒŠ‚ƒŠ‚  Œ áŠŠá  Œ ƒŠ‚ƒŠ‚  Œ „†‡…  Œ Œ  ƒŠ‚ƒŠ‚ Œ  áŠŠá Œ  ƒŠ‚ƒŠ‚ Œ  „†‡… ‡€ˆ€€€ˆ€† ‡ˆ€ˆ€ˆ€ˆ† ƒˆ ˆ‚ „†‡… Œ  ƒŠ‚  Œ ƒŠ‚Œ    Œ Œ       Œ Œ       Œ ƒŠ‰Š‚ Œ ƒŠ‰Š Œ ƒŠ‰ŠŒ „€€ˆ…        ",
   "„†  ‡… ƒŠ‚ ƒŠ‚ „†  ‡… ƒŠ‚ ƒŠ‚ áŠŠá  Œ ‡€…„€†  Œ ‡á…„á†  Œ ƒŠ‚ƒŠ‚  Œ Œ  áŠŠá Œ  ‡€…„€† Œ  ‡á…„á† Œ  ƒŠ‚ƒŠ‚ Œ       Œ Œ       Œ „†‡… ƒŠ‚ ƒŠ‚ Œ  áŠ  Œ áŠŒ    Œ Œ       Œ Œ       Œ „€€€ˆ²… „€€ˆ²… „€€ˆ…              ",
   "„€ˆ€ˆ€ˆ€… „ˆ€ˆ€ˆ€ˆ… „€ˆ€ˆ€ˆ€… „ˆ€ˆ€ˆ€ˆ… „€…„€ˆ²²… „€…„€ˆ²²… „²²²²ˆ²²… „á…„áˆ²²… „²²ˆ€…„€… „²²ˆ€…„€… „²²ˆ²²²²… „²²ˆá…„á… „²²²²²²²… „²²²²²²²… „€ˆ€€€ˆ€… „ˆ€ˆ€ˆ€ˆ… „²²ˆ€ˆ²²… „€ˆˆ²²²²… „²²²²²²²… „²²²²²²²…                                   ",
   "ƒœœœ‰œœœ‚ ƒœœœ‰œœœ‚ ƒœœœ‰œœœ‚ ƒœœœ‰œœœ‚ ƒœœ‰œ‰²²‚ ƒœœŠœ‰²²‚ ƒœœ‰œ‰²²‚ ƒ²²²²‰²²‚ ƒ²²‰œœ‰œ‚ ƒ²²‰œœŠœ‚ ƒ²²‰œœ‰œ‚ ƒ²²‰²²²²‚ ƒ‰œœ‰œœ‰‚ ƒ‰œœŠœœ‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²‰²‰²²‚ ƒœœ‰²²²²‚ ƒ‰œœ‰œœ‰‚ ƒ‰œœŠœœ‰‚ ƒœœœ‰²‚ ƒœœ‰²‚ ƒœœ‰‚ ƒœœ‰‚ ƒœ‰‚ † ",
   "‡’“€Š’“‚ž ‡      ž ‡€€ „€‰€ž Ÿ      ž ‡’“Š’ž  Œ Ÿ „€ž  Œ ‡’“Š’ž  Œ ‡œœ‰œ†  Œ Œ  ‡’“Š’ž Œ  Ÿ „€ž Œ  ‡’“Š’ž Œ  ‡œœ‰œ† ‡’“Š€’ž Ÿ“†„€€ž Œ       Œ Œ       Œ Œ  ‡’“  Œ ‡’“Œ    Œ ‡’“Š€’ž Ÿ“†„€€ž ‡’“’ž Œ ‡“’ž Œ ‡“’žŒ ‡“’žŒ ‡“žŒ   ",
   "Ÿ  „€€… Ÿ  „’“€† Ÿ „€‰€ €† ‡€€€Š€ €† Ÿ „€ž  Œ Ÿ „‰€†  Œ Ÿ „€ž  Œ ‡’“Š’ž  Œ Œ  Ÿ „€ž Œ  Ÿ „‰€† Œ  Ÿ „€ž Œ  ‡’“Š’ž Ÿ „€€ž Ÿ „‰€€† ‡‰œœ‰œœ‰† ‡‰œœŠœœ‰† Œ  Ÿ   Œ Ÿ Œ    Œ ‡²²²²²²²† ‡²²²²²²²† Ÿ €ž Œ Ÿ€ž Œ Ÿ€žŒ Ÿ„€†Œ „ˆ…   ",
   "Ÿ „€‰€‰€† Ÿ „€‰€‰€† Ÿ ‚  ƒ€ž ‡€‚  ƒ€ž Ÿ „‰€†  Œ ‡’“€€ž  Œ Ÿ „‰€†  Œ Ÿ „€ž  Œ Œ  Ÿ „‰€† Œ  ‡’“€€ž Œ  Ÿ „‰€† Œ  Ÿ „€ž ‡ˆ€ˆ‰€€ˆ† ‡ˆ’“€€€ˆ† ‡’“Š€’ž Ÿ“†„€€ž Œ  Ÿ „  Œ Ÿ „Œ    Œ Œ       Œ Œ       Œ Ÿ „€† Œ Ÿ„€† Œ Ÿ„€†Œ „ˆ…        ",
   "‡’“€€€† ž Ÿ’“€‡€  ž ‡€…   † Ÿ€…   † ‡’“€€ž  Œ ‡„†  Œ ‡„†  Œ Ÿ „‰€†  Œ Œ  ‡’“€€ž Œ  ‡„† Œ  ‡„† Œ  Ÿ „‰€† Œ       Œ Œ       Œ Ÿ „€€ž Ÿ „‰€€† Œ  ‡’“  Œ ‡’“Œ    Œ Œ       Œ Œ       Œ „ˆ²… „ˆ²… „ˆ…              ",
   "„„…… „„…… „„…… „„…… „„ˆ²²… „€€€€ˆ²²… „––––ˆ²²… „„ˆ²²… „²²ˆ„… „²²ˆ€€€€… „²²ˆ––––… „²²ˆ„… „²²²²²²²… „²²²²²²²… „ˆ€ˆ‰€€ˆ… „ˆ’“€€€ˆ… „²²ˆˆ²²… „ˆ²²²²… „²²²²²²²… „²²²²²²²…                                   ",
   "ƒ€‰€€‰€‰‚ ƒ‰€‰€€‰€‚ ƒ€€€€€€€‚ ƒ€€€€€€€‚ ƒ‰€€‚ƒ²²‚ ƒ€‰‰‚ƒ²²‚ ƒ‰€€‚ƒ²²‚ ƒ²²²²‰²²‚ ƒ²²‰‰€€‚• ƒ²²‰€‰‰‚• ƒ²²‰‰€€‚• ƒ²²‰²²²²‚ ƒ€‚ƒ€‰‰€‚ ƒ€‰‰€‚ƒ€‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²‰²‰²²‚ ƒ‰€‰²²²²‚ ƒ€‚ƒ€‰‰€‚ ƒ€‰‰€‚ƒ€‚ ƒ‰€€‚²‚ ƒ€€‚²‚ ƒ€€‚‚ ƒ‰‰‚‚ ƒ‰‚‚ Ž ",
   "‡€…ƒ‚ž Ÿ ž Ÿƒ‚„€† ‡‚ ƒ† ‡…ƒ‚žŸ  Œ €Š…žŸ  Œ ‡…ƒ‚žŸ  Œ ‡‰€€‚  Œ Œ  ‡…ƒ‚žŸ Œ  €Š…žŸ Œ  ‡…ƒ‚žŸ Œ  ‡‰€€‚  žŸ „Š€† ‡€Š… žŸ  Œ       Œ Œ       Œ Œ  ‡…ƒ  Œ ‡…ƒŒ    Œ  žŸ „Š€† ‡€Š… žŸ  ‡…ƒ‚ž Œ ‡ƒ‚ž Œ ‡ƒ‚žŒ Š…žŒ „Œ   ",
   " €Š…ž Ÿ ž Ÿ„Š€  ‡œœœœ™ Ÿ ž šœœœœ† €Š…žŸ  Œ „…Ÿ  Œ €Š…žŸ  Œ ‡…ƒ‚žŸ  Œ Œ  €Š…žŸ Œ  „…Ÿ Œ  €Š…žŸ Œ  ‡…ƒ‚žŸ ‡€ž„… „…Ÿ€† ‡€‚ƒ€‰‰€† ‡€‰‰€‚ƒ€† Œ  €Š  Œ €ŠŒ    Œ ‡²²²²²²²† ‡²²²²²²²† €Š…ž Œ Š…ž Œ Š…žŒ „…Œ „œœ…   ",
   "‡˜ Ÿ ž ›†  €Š‚ž Ÿ ž ŸƒŠ€  „…Ÿ  Œ ƒœœœœ†  Œ „…Ÿ  Œ €Š…žŸ  Œ Œ  „…Ÿ Œ  ƒœœœœ† Œ  „…Ÿ Œ  €Š…žŸ ‡€ˆœœœœœ‚ ƒœœœœœˆ€†  žŸ „Š€† ‡€Š… žŸ  Œ  „  Œ „Œ    Œ Œ       Œ Œ       Œ „… Œ „… Œ „…Œ „œœœ…        ",
   "‡œœœœœœ… „œœœœœœ† ‡€‚„…ž Ÿ ž Ÿ„…ƒ€† ƒœœœœ†  Œ ‡€…„€†  Œ ƒœœœœ†  Œ „…Ÿ  Œ Œ  ƒœœœœ† Œ  ‡€…„€† Œ  ƒœœœœ† Œ  „…Ÿ Œ       Œ Œ       Œ ‡€ž„… „…Ÿ€† Œ  ƒœœ  Œ ƒœœŒ    Œ Œ       Œ Œ       Œ „œœœœ²… „œœœ²… „œœœ…              ",
   "„€€€€€€€… „€€€€€€€… „€ˆ€€ˆ€ˆ… „ˆ€ˆ€€ˆ€… „““““ˆ²²… „²²²²ˆ²²… „€…„€ˆ²²… ‘œœœœˆ²²… „²²ˆ““““… „²²ˆ²²²²… „²²ˆ€…„€… „²²€œœœœ… „²²²²²²²… „²²²²²²²… „€ˆœœœœœ ‘œœœœœˆ€… „²²ˆ““²²… „““ˆ²²²²… „²²²²²²²… „²²²²²²²…                                   ",
   /* ---[[ TIER 4 ]]------fulls----------- -----------------lefts----------------- -----------------rights---------------- -------tops-------- ------bottoms------ -------verts------- -------horzs------- --med-- -thin  thinr -sml- tiny u */
   "ƒ€–ƒá‰²²‚ ƒ€–ƒá‰²²‚ ƒ²²‰€–ƒá‚ ƒ²²‰á‚“€‚ ƒ€–ƒá‰²²‚ ƒá‚“€‰²²‚ ƒ€–ƒá‰²²‚ ƒ²²²²‰²²‚ ƒ²²‰€–ƒá‚ ƒ²²‰á‚“€‚ ƒ²²‰€–ƒá‚ ƒ²²‰²²²²‚ ƒ€–ƒá‚‰€‚ ƒ€‰ƒá‚“€‰ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²‰²‰²²‚ ƒ€–ƒ²²²²‚ ƒ€€€€€€‰‚ ƒ‰€€€€€€‚ ƒ–ƒá‰²‚ ƒ–ƒ‰²‚ ƒ–ƒ‰‚ ƒ–ƒ‰‚ ƒ†‰‚  ",
   "‡ ‰‚á  Œ ‡ ‰‚á  Œ Œ  ‡ ‰‚á Œ  Žáƒ‰ † ‡ ‰‚á  Œ Žáƒ‰ †  Œ ‡ ‰‚á  Œ ‡€–ƒá‰  Œ Œ  ‡ ‰‚á Œ  Žáƒ‰ † Œ  ‡ ‰‚á Œ  ‡€–ƒá‰ ‡ ‰‚á†† ‡Ž‡Žáƒ‰ † Œ       Œ Œ       Œ Œ  ‡ ‰  Œ ‡ ‰Œ    Œ ‡€…€€ƒ€† Ž‡€‚€€„€† ‡‰‚á Œ ‡‰‚ Œ ‡‰‚Œ ‡‰‚Œ Š…Œ   ",
   " „…Ž  Œ  „…Ž  Œ Œ   „…Ž Œ  Ž„…   „…Ž  Œ Ž„…   Œ  „…Ž  Œ ‡ ‰‚á  Œ Œ   „…Ž Œ  Ž„…  Œ   „…Ž Œ  ‡ ‰‚á  „…Ž†† ‡Ž‡Ž„…  ‡€–ƒá‚‰€† ‡€‰ƒá‚“€† Œ   „  Œ  „Œ    Œ ‡²²²²²²²† ‡²²²²²²²† „…Ž Œ „…Ž Œ „…ŽŒ „…ŽŒ „ˆˆ…   ",
   " Œ Ž  Œ ƒ‚ Ž  Œ Œ   Œ Ž Œ  Ž Œ   Œ Ž  Œ Ž Œ   Œ ƒ‚ Ž  Œ  „…Ž  Œ Œ   Œ Ž Œ  Ž Œ  Œ  ƒ‚ Ž Œ   „…Ž ‡€ˆ€áˆ€€† ‡€€ˆá€ˆ€ ‡ ‰‚á†† ‡Ž‡Žáƒ‰ † Œ   Œ  Œ  ŒŒ    Œ Œ       Œ Œ       Œ ‚ Ž Œ ‚  Œ ‚ Œ „ˆ€ˆ…        ",
   "ƒ‚ áŽ  Œ ‡€ˆ€ˆŠ  Œ Œ  ƒ‚ áŽ Œ  á ƒ‚ ƒ‚ áŽ  Œ á ƒ‚  Œ ‡€ˆ€ˆŠ  Œ ƒ‚ Ž  Œ Œ  ƒ‚ áŽ Œ  á ƒ‚ Œ  ‡€ˆ€ˆŠ Œ  ƒ‚ Ž Œ       Œ Œ       Œ  „…Ž†† ‡Ž‡Ž„…  Œ  ƒ‚  Œ ƒ‚Œ    Œ Œ       Œ Œ       Œ „ˆ€áˆ²… „ˆ€ˆ²… „ˆ€ˆ…              ",
   "„€ˆ€áˆ²²… „²²²²ˆ²²… „²²ˆ€ˆ€á… „²²ˆá€ˆ€… „€ˆ€áˆ²²… „á€ˆ€ˆ²²… „²²²²ˆ²²… „€ˆ€ˆˆ²²… „²²ˆ€ˆ€á… „²²ˆá€ˆ€… „²²ˆ²²²²… „²²ˆ€ˆ€ˆ… „²²²²²²²… „²²²²²²²… „€ˆ€áˆ€€… „€€ˆá€ˆ€… „²²ˆ€ˆ²²… „€ˆˆ²²²²… „²²²²²²²… „²²²²²²²…                                   ",
   "ƒ€€‰€‰²²‚ ƒ²²²²‰²²‚ ƒ²²‰²²²²‚ ƒ²²‰€‰€€‚ ƒ€€‰€‰²²‚ ƒ€‰€€‰²²‚ ƒ€€‰€‰²²‚ ƒ²²²²‰²²‚ ƒ²²‰€€‰€‚ ƒ²²‰€‰€€‚ ƒ²²‰€€‰€‚ ƒ²²‰²²²²‚ ƒ€€‰€€‰€‚ ƒ€‰€€‰€€‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²‰²‰²²‚ ƒ€€‰²²²²‚ ƒ€€‰€€‰€‚ ƒ€‰€€‰€€‚ ƒ€€‰‰²‚ ƒ€€‰²‚ ƒ€€‰‚ ƒ€€‰‚ ƒ€€‚  ",
   "   †  Œ ‡€€‰€Š  Œ Œ  ‡€€‰€Š Œ  ‡       †  Œ ‡     Œ    †  Œ ‡€€‰€Š  Œ Œ     † Œ  ‡    Œ     † Œ  ‡€€‰€Š     † † ‡ ‡     Œ       Œ Œ       Œ Œ      Œ   Œ    Œ     † † ‡ ‡       † Œ    Œ   Œ ‡ƒ€‚Œ ƒ‚Œ   ",
   "‡ ƒ€‚†  Œ    †  Œ Œ     † Œ  ‡ƒ€‚ † ‡ ƒ€‚†  Œ ‡ƒ€‚ †  Œ ‡ ƒ€‚†  Œ    †  Œ Œ  ‡ ƒ€‚† Œ  ‡ƒ€‚ † Œ  ‡ ƒ€‚† Œ     † ‡ ƒ€‚ † † ‡ ‡ ƒ€‚ † ‡€€‰€€‰€† ‡€‰€€‰€€† Œ  ‡ ƒ  Œ ‡ ƒŒ    Œ ‡²²²²²²²† ‡²²²²²²²† ‡ƒ€‚† Œ ‡ƒ€‚ Œ ‡ƒ€‚Œ ‡„…Œ „€……   ",
   "‡ „…†  Œ ‡ ƒ€‚†  Œ Œ  ‡ ƒ€‚† Œ  ‡„… † ‡ „…†  Œ ‡„… †  Œ ‡ „…†  Œ ‡ ƒ€‚†  Œ Œ  ‡ „…† Œ  ‡„… † Œ  ‡ „…† Œ  ‡ ƒ€‚† ‡²„…„€…€† ‡€„€…„…²†     † † ‡ ‡     Œ  ‡ „  Œ ‡ „Œ    Œ Œ       Œ Œ       Œ ‡„…† Œ ‡„… Œ ‡„…Œ „œœœ…        ",
   "‡€ˆ€ˆŠ  Œ ‡ „…†  Œ Œ  ‡ „…† Œ  ‡ˆ€ˆ€† ‡€ˆ€ˆŠ  Œ ‡ˆ€ˆ€†  Œ ‡€ˆ€ˆŠ  Œ ‡ „…†  Œ Œ  ‡€ˆ€ˆŠ Œ  ‡ˆ€ˆ€† Œ  ‡€ˆ€ˆŠ Œ  ‡ „…† Œ       Œ Œ       Œ ‡ ƒ€‚ † † ‡ ‡ ƒ€‚ † Œ  ‡€ˆ  Œ ‡€ˆŒ    Œ Œ       Œ Œ       Œ „œœœˆ²… „œœœ²… „œœœ…              ",
   "„œœœœˆ²²… „€ˆ€ˆˆ²²… „²²ˆ€ˆ€ˆ… „²²ˆœœœœ… „œœœœˆ²²… „œœœœˆ²²… „²²²²ˆ²²… „€ˆ€ˆˆ²²… „²²ˆœœœœ… „²²ˆœœœœ… „²²ˆ²²²²… „²²ˆ€ˆ€ˆ… „²²²²²²²… „²²²²²²²… „²„…„€…€… „€„€…„…²… „²²ˆœˆ²²… „œœˆ²²²²… „²²²²²²²… „²²²²²²²…                                   ",
   "ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²‰²²²²‚ ƒ²²²²²²²‚ ƒ²²‰²²²²‚ ƒ²²²²²²²‚ ƒ²²²²‰²²‚ ƒ²²²²²²²‚ ƒ²²²²‰²²‚ ƒ²²²²²²²‚ ƒ²²²²‰²²‚ ƒ²²‰²²²²‚ ƒ²²²²‰²²‚ ƒ²²‰²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²‰²‚ ƒ²²‰²‚ ƒ²²‰‚ ƒ²²‰‚ ƒ²²‚ · ",
   "Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ  Œ    Œ Œ       Œ Œ  Œ    Œ Œ       Œ Œ    Œ  Œ Œ       Œ Œ    Œ  Œ Œ       Œ Œ    Œ  Œ Œ  Œ    Œ Œ    Œ  Œ Œ  Œ    Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ   Œ Œ Œ  Œ Œ Œ  ŒŒ ‡²‚ŒŒ ‡²‚Œ   ",
   "Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ  Œ    Œ Œ       Œ ‡²²…    Œ Œ       Œ Œ    Œ  Œ Œ       Œ Œ    „²²† Œ       Œ Œ    Œ  Œ Œ  Œ    Œ Œ    Œ  Œ Œ  Œ    Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ‡²‚ Œ Œ ‡²‚Œ Œ ‡²‚ŒŒ Œ ŒŒŒ „²ˆ…   ",
   "Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ  Œ    Œ ‡²²²²²²²† Œ       Œ ‡²²‚    Œ Œ    Œ  Œ ‡²²²²²²²† Œ       Œ Œ    ƒ²²† Œ    Œ  Œ Œ  Œ    Œ Œ    Œ  Œ Œ  Œ    Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ Œ Œ Œ Œ ŒŒ Œ Œ ŒŒŒ „²ˆˆ…        ",
   "Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ  Œ    Œ Œ       Œ Œ       Œ Œ  Œ    Œ Œ    Œ  Œ Œ       Œ Œ       Œ Œ    Œ  Œ Œ    Œ  Œ Œ  Œ    Œ Œ    Œ  Œ Œ  Œ    Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ „²ˆ²ˆ²… „²ˆˆ²… „²ˆˆ…              ",
   "„²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²ˆ²²²²… „²²²²²²²… „²²²²²²²… „²²ˆ²²²²… „²²²²ˆ²²… „²²²²²²²… „²²²²²²²… „²²²²ˆ²²… „²²²²ˆ²²… „²²ˆ²²²²… „²²²²ˆ²²… „²²ˆ²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²…                                   ",
   "ƒ€€‰€‰€€‚ ƒ€€‰€‰€€‚ ƒ€€‰€‰€€‚ ƒ€€‰€‰€€‚ ƒ€‰‰€‰²²‚ ƒ€‰‰€‰²²‚ ƒ€‰‰€‰²²‚ ƒ€‰‰€‰²²‚ ƒ²²‰€‰‰€‚ ƒ²²‰€‰‰€‚ ƒ²²‰€‰‰€‚ ƒ²²‰€‰‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²‰²‰²²‚ ƒ€‰‰²²²²‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰²‚ ƒ‰€‰²‚ ƒ‰€‰‚ ƒ‰€‰‚ ƒ‰‰‚ á ",
   "‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽ†  Œ ‡†  Œ ‡ŽŽ†  Œ ‡ŽŽ†  Œ Œ  ‡ŽŽŽŽ† Œ  ‡† Œ  ‡ŽŽ† Œ  ‡ŽŽ† ‡ŽŽŽŽŽŽŽ† ‡† Œ       Œ Œ       Œ Œ  ‡ŽŽ  Œ ‡ŽŽŒ    Œ ‡ŽŽŽŽŽŽŽ† ‡† ‡ŽŽŽ† Œ ‡ŽŽ† Œ ‡ŽŽ†Œ ‡ŽŽ†Œ ‡ŽŽŒ   ",
   "‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽŽŽ†‡ ‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽ†  Œ ‡†  Œ ‡ŽŽ†  Œ ‡ŽŽ†  Œ Œ  ‡ŽŽŽŽ† Œ  ‡† Œ  ‡ŽŽ† Œ  ‡ŽŽ† ‡ŽŽŽŽŽŽŽ† ‡† ‡€‰€‰€‰€† ‡€‰€‰€‰€† Œ  ‡ŽŽ  Œ ‡ŽŽŒ    Œ ‡²²²²²²²† ‡²²²²²²²† ‡ŽŽŽ† Œ ‡ŽŽ† Œ ‡ŽŽ†Œ ‡ŽŽ†Œ „ˆˆ…   ",
   "‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽ†  Œ ‡†  Œ ‡ŽŽ†  Œ ‡ŽŽ†  Œ Œ  ‡ŽŽŽŽ† Œ  ‡† Œ  ‡ŽŽ† Œ  ‡ŽŽ† ‡ˆ€ˆ€ˆ€ˆ† ‡ˆ€ˆ€ˆ€ˆ† ‡ŽŽŽŽŽŽŽ† ‡† Œ  ‡ŽŽ  Œ ‡ŽŽŒ    Œ Œ       Œ Œ       Œ ‡ŽŽŽ† Œ ‡ŽŽ† Œ ‡ŽŽ†Œ „ˆ€ˆ…        ",
   "‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽŽŽŽ† ‡ŽŽŽŽ†  Œ ‡†  Œ ‡ŽŽ†  Œ ‡ŽŽ†  Œ Œ  ‡ŽŽŽŽ† Œ  ‡† Œ  ‡ŽŽ† Œ  ‡ŽŽ† Œ       Œ Œ       Œ ‡ŽŽŽŽŽŽŽ† ‡† Œ  ‡ŽŽ  Œ ‡ŽŽŒ    Œ Œ       Œ Œ       Œ „€ˆ€ˆ²… „ˆ€ˆ²… „ˆ€ˆ…              ",
   "„€€ˆ€ˆ€€… „€€ˆ€ˆ€€… „€€ˆ€ˆ€€… „€€ˆ€ˆ€€… „€ˆˆ€ˆ²²… „€ˆˆ€ˆ²²… „€ˆˆ€ˆ²²… „€ˆˆ€ˆ²²… „²²ˆ€ˆˆ€… „²²ˆ€ˆˆ€… „²²ˆ€ˆˆ€… „²²ˆ€ˆˆ€… „²²²²²²²… „²²²²²²²… „ˆ€ˆ€ˆ€ˆ… „ˆ€ˆ€ˆ€ˆ… „²²ˆ€ˆ²²… „€ˆˆ²²²²… „²²²²²²²… „²²²²²²²…                                   ",
   /* ---------------fulls----------------- ----------------lefts------------------ -----------------rights---------------- -------tops-------- ------bottoms------ -------verts------- -------horzs------- --med-- -thin  thinr -sml- tiny u */
};


/*> static const char mayans       [LEN_MAYANT][LEN_MAYANC] = {                       <* 
 *>    " ƒ€‰€‰€‚  ƒ€€‰€‰€€‚ ƒ€€‰€‰€€‚ ƒ€€‰€‰€€‚ ",                                    <* 
 *>    "ƒ…   „‚ ‡€‚ ƒ€† ‡€‰† ‡‰€†  ‰† ‡‰  ",                                    <* 
 *>    "‡ˆ€… „€ˆ† ‡€ˆ… „ˆ€† ‡€ˆ… „ˆ€† ‡€ˆ… „ˆ€† ",                                    <* 
 *>    "‡‰€‚ ƒ€‰† ‡€‰‚ ƒ‰€† ‡€‰‚ ƒ‰€† ‡€‰‚ ƒ‰€† ",                                    <* 
 *>    "„‚   ƒ… ‡€… „€† ‡€„† ‡„€†  ˆ† ‡ˆ  ",                                    <* 
 *>    " „€ˆ€ˆ€…  „€€ˆ€ˆ€€… „€€ˆ€ˆ€€… „€€ˆ€ˆ€€… ",                                    <* 
 *>    "ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€€€€€€€‚ ƒ€€€€€€€‚ ",                                    <* 
 *>    "‡€…       „€† ‡€€€€€€€† ‡€€€€€€€† ",                                    <* 
 *>    "‡€€€…     „€€€† ‡€€€€€‚   ƒ€€€€€† ",                                    <* 
 *>    "‡€€€€€…   „€€€€€† ‡€€€‚     ƒ€€€† ",                                    <* 
 *>    "‡€€€€€€€† ‡€€€€€€€† ‡€‚       ƒ€† ",                                    <* 
 *>    "„€€€€€€€… „€€€€€€€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… ",                                    <* 
 *>    "ƒ€€€‰€€€‚ ƒ€€‰€€€€‚ ƒ€€€€‰€€‚ ƒ€€‰€€€€‚ ",                                    <* 
 *>    "  ƒˆ€‚  ƒ€ˆ‚       ƒ…     „€‚   ",                                    <* 
 *>    " ƒ†  ‡€† ‡†  ‡€€€†  ƒ€ˆ‚     ƒ€ˆ‚  ",                                    <* 
 *>    "‡€…„€‰…  „€‰…    ƒ†  ‡€€† ƒ€†  ‡€† ",                                    <* 
 *>    "   ƒ…     „‚    ‡…„€‰…   ‡… „€‰…  ",                                    <* 
 *>    "„€€€ˆ€€€… „€€€ˆ€€€… „€€€ˆ€€€… „€€€€ˆ€€… ",                                    <* 
 *>    "ƒ€‰€‰€‰€‚ ƒ€‰€€€‰€‚ ƒ€‰€‰€‰€‚ ƒ€€€‰€€€‚ ",                                    <* 
 *>    "‡€Š€Š€Š€† ‡€Š‰€‰Š€† ‡‰ˆ‰ˆ‰ˆ‰†  ƒ€‰€‚  ",                                    <* 
 *>    "‡€Š€Š€Š€† ‡€Šˆ‰ˆŠ€† ‡ˆ‰ˆ‰ˆ‰ˆ† ‡€‡€Š€†€† ",                                    <* 
 *>    "‡€Š€Š€Š€† ‡€Šƒˆ‰Š€† ‡‰ˆ‰ˆ‰ˆ‰† ‡€‡€Š€†€† ",                                    <* 
 *>    "‡€Š€Š€Š€† ‡€Šˆ€ˆŠ€† ‡ˆ‰ˆ‰ˆ‰ˆ†  „€ˆ€…  ",                                    <* 
 *>    "„€ˆ€ˆ€ˆ€… „€ˆ€€€ˆ€… „€ˆ€ˆ€ˆ€… „€€€ˆ€€€… ",                                    <* 
 *> };                                                                                <*/

static const char mayanv       [LEN_HUND][LEN_PATH] = {
   /* --------right fulls-------- ---------right halves-------- ---------left fulls--------- ---------left halves---------- --------bottom fulls-------- --------bottom halves--------- ----------top fulls--------- ----------top halves---------- */
   "ƒ²²²²²‰€‚ ƒ²²²²²‰€‚ ƒ²²²²²‰‚ ƒ²²²²²‰‚ ƒ²²²²²‰‚ ƒ²²²²²‰‚ ƒ€‰²²²²²‚ ƒ€‰²²²²²‚ ƒ‰²²²²²‚ ƒ‰²²²²²‚ ƒ‰²²²²²‚ ƒ‰²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ€‰‰€‚ ƒœœ‰€‰œœ‚ ƒ‰€‰‚ ƒ€‰‚ ƒ‰€‚ ƒœœ‚ ƒœœ‚ ƒ‚ ƒ‚ ",
   "Œ     ž † Œ     ‡ ž Œ     ž Ÿ Œ     ž † Œ     † ž Œ     ž Ÿ ‡ Ÿ     Œ Ÿ †     Œ ž Ÿ     Œ ‡ Ÿ     Œ Ÿ Ÿ     Œ ž Ÿ     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ‡œœŠ€Šœœ† ‡ˆ€ˆ€ˆ€ˆ† ‡œœˆ€ˆœœ† ‡œœŠ€Šœœ† ‡ˆ€Š€Š€ˆ† ‡œœŠ€Šœœ† ",
   "Œ     Š Ÿ Œ     ž † Œ     Š † Œ     ˆ‰… Œ     ˆ‰… Œ     ˆ‰… ž Š     Œ ‡ Ÿ     Œ ‡ Š     Œ „‰ˆ     Œ „‰ˆ     Œ „‰ˆ     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "Œ     Š Ÿ Œ     ž † Œ     Š † Œ     ‰ˆ‚ Œ     ‰ˆ‚ Œ     ‰ˆ‚ ž Š     Œ ‡ Ÿ     Œ ‡ Š     Œ ƒˆ‰     Œ ƒˆ‰     Œ ƒˆ‰     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "Œ     ž † Œ     ‡ ž Œ     ž Ÿ Œ     ž † Œ     † ž Œ     ž Ÿ ‡ Ÿ     Œ Ÿ †     Œ ž Ÿ     Œ ‡ Ÿ     Œ Ÿ Ÿ     Œ ž Ÿ     Œ ‡Š€Š† ‡‰€‰€‰€‰† ‡‰€‰† ‡Š€Š† ‡‰€Š€Š€‰† ‡Š€Š† Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "„²²²²²ˆ€… „²²²²²ˆ€… „²²²²²ˆœ… „²²²²²ˆœ… „²²²²²ˆœ… „²²²²²ˆœ… „€ˆ²²²²²… „€ˆ²²²²²… „œˆ²²²²²… „œˆ²²²²²… „œˆ²²²²²… „œˆ²²²²²… „€ˆœœœˆ€… „ˆ€ˆ… „œœˆ€ˆœœ… „€ˆ… „ˆ€… „… „… „œœ… „œœ… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… ",
   "ƒ²²²²²‰€‚ ƒ²²²²²‰€‚ ƒ²²²²²‰€‚ ƒ²²²²²‰€‚ ƒ²²²²²‰€‚ ƒ²²²²²‰€‚ ƒ€‰²²²²²‚ ƒ€‰²²²²²‚ ƒ€‰²²²²²‚ ƒ€‰²²²²²‚ ƒ€‰²²²²²‚ ƒ€‰²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰‚ ƒ‰€‚ ƒ€‰‚ ƒ‰€‚ ƒ€‰‚ ƒ‰€‚ ",
   "Œ     ‡€† Œ     …ƒ† Œ     ‰ƒ† Œ     ‡€† Œ     …ƒ† Œ     ‰ƒ† ‡€†     Œ ‡…ƒ     Œ ‡…ˆ     Œ ‡€†     Œ ‡‚„     Œ ‡‚„     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ‡€Š€Š€Š€† ‡…‡…‡…‡… †…†…†…†…† ‡€ŠŠ€ŠŠ€† „†„€…‡… …†„€…‡„ ",
   "Œ     ‡€† Œ     ‡€† Œ     ‰ƒ† Œ     „‰… Œ     ˆ‰… Œ     €‰… ‡€†     Œ ‡€†     Œ ‡…ˆ     Œ „‰…     Œ „‰ˆ     Œ „‰ˆ     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "Œ     ‡€† Œ     …ƒ† Œ     ‡€† Œ     ƒˆ‚ Œ     ‰ˆ‚ Œ     €ˆ‚ ‡€†     Œ ‡…ƒ     Œ ‡€†     Œ ƒˆ‚     Œ ƒˆ‰     Œ ƒˆ‰     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "Œ     ‡€† Œ     …ƒ† Œ     ‰ƒ† Œ     ‡€† Œ     ‚„† Œ     ˆ„† ‡€†     Œ ‡…ƒ     Œ ‡…ˆ     Œ ‡€†     Œ ‡…ƒ     Œ ‡…ƒ     Œ ‡€Š€Š€Š€† ƒ†ƒ†ƒ†ƒ† ‡„‡„‡„‡„ ‡€ŠŠ€ŠŠ€† ƒ†ƒ€‚‡‚ …†ƒ€‚‡„ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "„²²²²²ˆ€… „²²²²²ˆ€… „²²²²²ˆ€… „²²²²²ˆ€… „²²²²²ˆ€… „²²²²²ˆ€… „€ˆ²²²²²… „€ˆ²²²²²… „€ˆ²²²²²… „€ˆ²²²²²… „€ˆ²²²²²… „€ˆ²²²²²… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ… „ˆ€… „€ˆ… „ˆ€… „€ˆ… „ˆ€… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… ",
   /* --------right fulls-------- ---------right halves-------- ---------left fulls--------- ---------left halves---------- --------bottom fulls-------- --------bottom halves--------- ----------top fulls--------- ----------top halves---------- */
   "ƒ²²²²²‰‰‚ ƒ²²²²²‰‰‚ ƒ²²²²²²²‚ ƒ²²²²²‰‰‚ ƒ²²²²²‰‰‚ ƒ²²²²²²²‚ ƒ‰‰²²²²²‚ ƒ‰‰²²²²²‚ ƒ²²²²²²²‚ ƒ‰‰²²²²²‚ ƒ‰‰²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ‰‰‰‰‰‰‰‚ ƒ‰‰‰‰‰‰‰‚ ƒ²²²²²²²‚ ƒ‰‰‚ ƒ‰‰‚ ƒ‰‰‚ ƒ‰‰‚ ƒ²²²²²²²‚ ",
   "Œ     ‡† Œ     ‡Ž† Œ       Œ Œ     ‡† Œ     ‡Ž Œ       Œ ‡†     Œ ‡Ž     Œ Œ       Œ ‡†     Œ ‡Ž     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ‡†‡†‡† ‡ŽŽŽ† Œ       Œ ‡†„€…‡† ‡Ž„€…Ž† Œ       Œ ",
   "Œ     ‡† Œ     ‡Ž† Œ       Œ Œ     „Š… Œ     „ŠŽ Œ       Œ ‡†     Œ ‡ŽŽ     Œ Œ       Œ „Š…     Œ „ŠŽ     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "Œ     ‡† Œ     ‡Ž† Œ       Œ Œ     ƒŠ‚ Œ     ƒŠ Œ       Œ ‡†     Œ ‡Ž     Œ Œ       Œ ƒŠ‚     Œ ƒŠ     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "Œ     ‡† Œ     ‡Ž† Œ       Œ Œ     ‡Ž† Œ     ‡Ž Œ       Œ ‡†     Œ ‡ŽŽ     Œ Œ       Œ ‡Ž†     Œ ‡Ž     Œ Œ       Œ ‡†‡†‡† ‡ŽŽŽŽ† ‡†ƒ€‚‡† ‡Žƒ€‚Ž† Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "„²²²²²ˆˆ… „²²²²²ˆˆ… „²²²²²²²… „²²²²²ˆˆ… „²²²²²ˆˆ… „²²²²²²²… „ˆˆ²²²²²… „ˆˆ²²²²²… „²²²²²²²… „ˆˆ²²²²²… „ˆˆ²²²²²… „²²²²²²²… „ˆˆˆˆˆˆˆ… „ˆˆˆˆˆˆˆ… „ˆˆ… „ˆˆ… „ˆˆ… „ˆˆ… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… ",
   "ƒ²²²²²á‰‚ ƒ²²²²²á‰‚ ƒ²²²²²²²‚ ƒ²²²²²á‰‚ ƒ²²²²²á‰‚ ƒ²²²²²²²‚ ƒ‰á²²²²²‚ ƒ‰á²²²²²‚ ƒ²²²²²²²‚ ƒ‰á²²²²²‚ ƒ‰á²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ‰‚á‰‚á‰‚ ƒ‰‚á‰‚á‰‚ ƒ²²²²²²²‚ ƒá‚‚ ƒá‰‚ ƒá‚‚ ƒá‰‚ ƒ²²²²²²²‚ ",
   "Œ     Žá Œ     á Œ       Œ Œ     Žá Œ     á Œ       Œ áŽ     Œ áŽ     Œ Œ       Œ áŽ     Œ áŽŽ     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ‡ŽáŽáŽ† ‡ááŽááŽ† Œ       Œ ‡Žá€áŽ† ‡áá€ááŽ† Œ       Œ ",
   "Œ     Žá Œ     áŽá Œ       Œ Œ     áŠ… Œ     áŠ… Œ       Œ áŽ     Œ áá     Œ Œ       Œ „Šá     Œ „Šá     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "Œ     Žá Œ     á Œ       Œ Œ     áŠ‚ Œ     áŠ‚ Œ       Œ áŽ     Œ áŽ     Œ Œ       Œ ƒŠá     Œ ƒŠá     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "Œ     Žá Œ     áŽá Œ       Œ Œ     Žá Œ     ŽŽá Œ       Œ áŽ     Œ áá     Œ Œ       Œ áŽ     Œ á     Œ Œ       Œ ŽáŽáŽá ááŽááŽá Œ       Œ Žá€áŽá áá€ááá Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "„²²²²²áˆ… „²²²²²áˆ… „²²²²²²²… „²²²²²áˆ… „²²²²²áˆ… „²²²²²²²… „ˆá²²²²²… „ˆá²²²²²… „²²²²²²²… „ˆá²²²²²… „ˆá²²²²²… „²²²²²²²… „ˆ…áˆ…áˆ… „ˆ…áˆ…áˆ… „²²²²²²²… „á…… „áˆ… „á…… „áˆ… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… ",
   "ƒ²²²²²‰€‚ ƒ²²²²²‰€‚ ƒ²²²²²²²‚ ƒ²²²²²‰€‚ ƒ²²²²²‰€‚ ƒ²²²²²²²‚ ƒ€‰²²²²²‚ ƒ€‰²²²²²‚ ƒ²²²²²²²‚ ƒ€‰²²²²²‚ ƒ€‰²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ€‰ƒ€‚‰€‚ ƒ€ƒ€€€‚€‚ ƒ²²²²²²²‚ ƒ€‰‚ ƒ‰€‚ ƒ€‰‚ ƒ‰€‚ ƒ²²²²²²²‚ ",
   "Œ      “Š Œ      —Š Œ       Œ Œ      “Š Œ      —Š Œ       Œ Š–      Œ Š’      Œ Œ       Œ Š–      Œ Š’      Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ‡– “Š– “† ‡’ ƒŠ‚ —† Œ       Œ ‡– “€– “† ‡’ Š€Š —† Œ       Œ ",
   "Œ     ‡‰† Œ     ‡ˆ† Œ       Œ Œ     „Ž… Œ     ˆ‚… Œ       Œ ‡‰†     Œ ‡ˆ†     Œ Œ       Œ „Ž…     Œ „ƒˆ     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "Œ     ‡ˆ† Œ     ‡‰† Œ       Œ Œ     ƒ‚ Œ     ‰…‚ Œ       Œ ‡ˆ†     Œ ‡‰†     Œ Œ       Œ ƒ‚     Œ ƒ„‰     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "Œ      —Š Œ      “Š Œ       Œ Œ      —Š Œ      “Š Œ       Œ Š’      Œ Š–      Œ Œ       Œ Š’      Œ Š–      Œ Œ       Œ Š’ —Š’ —Š Š– „Š… “Š Œ       Œ Š’ —€’ —Š Š– Š€Š “Š Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "„²²²²²ˆ€… „²²²²²ˆ€… „²²²²²²²… „²²²²²ˆ€… „²²²²²ˆ€… „²²²²²²²… „€ˆ²²²²²… „€ˆ²²²²²… „²²²²²²²… „€ˆ²²²²²… „€ˆ²²²²²… „²²²²²²²… „€ˆ„€…ˆ€… „€„€€€…€… „²²²²²²²… „€ˆ… „ˆ€… „€ˆ… „ˆ€… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… ",
   /* --------right fulls-------- ---------right halves-------- ---------left fulls--------- ---------left halves---------- --------bottom fulls-------- --------bottom halves--------- ----------top fulls--------- ----------top halves---------- */
   "ƒ²²²²²‰‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²‰‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ‰‰²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ‰‰²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒŽŽ€‚€ŽŽ‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒŽŽ‚ ƒŽŽ‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ",
   "Œ     ŽŽŽ Œ       Œ Œ       Œ Œ     ŽŽŽ Œ       Œ Œ       Œ ŽŽŽ     Œ Œ       Œ Œ       Œ      Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ‡Ž†Ž†Ž†Ž† Œ       Œ Œ       Œ ‡Ž†Ž€Ž†Ž† Œ       Œ Œ       Œ ",
   "Œ     ŽŽŽ Œ       Œ Œ       Œ Œ     €ŠŽ Œ       Œ Œ       Œ ŽŽŽ     Œ Œ       Œ Œ       Œ Š€     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "Œ     ŽŽŽ Œ       Œ Œ       Œ Œ     €Š Œ       Œ Œ       Œ ŽŽŽ     Œ Œ       Œ Œ       Œ ŽŠ€     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "Œ     ŽŽŽ Œ       Œ Œ       Œ Œ      Œ       Œ Œ       Œ ŽŽŽ     Œ Œ       Œ Œ       Œ ŽŽŽ     Œ Œ       Œ Œ       Œ Ž†Ž†Ž†Ž† Œ       Œ Œ       Œ Ž†Ž€Ž† Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "„²²²²²ˆˆ… „²²²²²²²… „²²²²²²²… „²²²²²ˆˆ… „²²²²²²²… „²²²²²²²… „ˆˆ²²²²²… „²²²²²²²… „²²²²²²²… „ˆˆ²²²²²… „²²²²²²²… „²²²²²²²… „Ž………€ŽŽ… „²²²²²²²… „²²²²²²²… „ŽŽ… „… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… ",
   "ƒ²²²²²‰‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²‰€‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ‰‰²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ€‰²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ‰‰‰‰‰‰‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ‰‰‚ ƒ‰‰‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ",
   "Œ     ‡ † Œ       Œ Œ       Œ Œ     ˆ‰† Œ       Œ Œ       Œ ‡ †     Œ Œ       Œ Œ       Œ ‡‰ˆ     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ‡ †‡ †‡ † Œ       Œ Œ       Œ ‡ †‡€†‡ † Œ       Œ Œ       Œ ",
   "Œ     ‡‰† Œ       Œ Œ       Œ Œ     ‰Š… Œ       Œ Œ       Œ ‡‰†     Œ Œ       Œ Œ       Œ „Š‰     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "Œ     ‡ˆ† Œ       Œ Œ       Œ Œ     ˆŠ‚ Œ       Œ Œ       Œ ‡ˆ†     Œ Œ       Œ Œ       Œ ƒŠˆ     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "Œ     ‡ † Œ       Œ Œ       Œ Œ     ‰ˆ† Œ       Œ Œ       Œ ‡ †     Œ Œ       Œ Œ       Œ ‡ˆ‰     Œ Œ       Œ Œ       Œ ‡ †‡ †‡ † Œ       Œ Œ       Œ ‡ †‡€†‡ † Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "„²²²²²ˆˆ… „²²²²²²²… „²²²²²²²… „²²²²²ˆ€… „²²²²²²²… „²²²²²²²… „ˆˆ²²²²²… „²²²²²²²… „²²²²²²²… „€ˆ²²²²²… „²²²²²²²… „²²²²²²²… „ˆˆˆˆˆˆˆ… „²²²²²²²… „²²²²²²²… „ˆˆ… „ˆˆ… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… ",
   "ƒ²²²²²‰²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²‰²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²‰²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²‰²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ƒ²²‰€‰²²‚ ƒ²²²²²²²‚ ƒ²²²²²²²‚ ",
   "Œ     Œ Œ Œ       Œ Œ       Œ Œ     Œ Œ Œ       Œ Œ       Œ Œ Œ     Œ Œ       Œ Œ       Œ Œ Œ     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ‡²²²²²²²† Œ       Œ Œ       Œ ‡²²… „²²† Œ       Œ Œ       Œ ",
   "Œ     Œ Œ Œ       Œ Œ       Œ Œ     „‰… Œ       Œ Œ       Œ Œ Œ     Œ Œ       Œ Œ       Œ „‰…     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "Œ     Œ Œ Œ       Œ Œ       Œ Œ     ƒˆ‚ Œ       Œ Œ       Œ Œ Œ     Œ Œ       Œ Œ       Œ ƒˆ‚     Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "Œ     Œ Œ Œ       Œ Œ       Œ Œ     Œ Œ Œ       Œ Œ       Œ Œ Œ     Œ Œ       Œ Œ       Œ Œ Œ     Œ Œ       Œ Œ       Œ ‡²²²²²²²† Œ       Œ Œ       Œ ‡²²‰€‰²²† Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ Œ       Œ ",
   "„²²²²²ˆ²… „²²²²²²²… „²²²²²²²… „²²²²²ˆ²… „²²²²²²²… „²²²²²²²… „²ˆ²²²²²… „²²²²²²²… „²²²²²²²… „²ˆ²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²… „²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… „²²²²²²²… ",
   /* --------right fulls-------- ---------right halves-------- ---------left fulls--------- ---------left halves---------- --------bottom fulls-------- --------bottom halves--------- ----------top fulls--------- ----------top halves---------- */
};


static const char mayann       [LEN_PATH][LEN_HUND] = {
   "ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ",
   "‡ · · · † ‡ · Ž† ‡ · · · † ‡ · Ž† ‡ · · · † ‡ · Ž† ‡ · · · † ‡ · Ž† ‡ŽŽŽŽ · † ‡ŽŽŽŽ† ‡ŽŽŽŽ · † ‡ŽŽŽŽ† ‡ŽŽŽŽ · † ‡ŽŽŽŽ† ‡ŽŽŽŽ · † ‡ŽŽŽŽ† ",
   "‡       † ‡ · „ €ˆ† ‡ ·   · † ‡ · ƒ ‰ˆ† ‡ ·   · † ‡ · ƒ €ˆ† ‡ ·   · † ‡ · ƒ ‰ˆ† ‡ˆ€ … · † ‡ˆ€ € €ˆ† ‡ˆ€ ‚ · † ‡ˆ€ ‰ ‰ˆ† ‡ˆ‰ ‚ · † ‡ˆ‰ ‰ €ˆ† ‡ˆ‰ ‚ · † ‡ˆ ˆ‰ˆ ˆ† ",
   "‡       † ‡ ·   · † ‡ · ƒ ‰€† ‡ · ƒ ‰ˆ† ‡€‰ ‚ · † ‡€‰ ‚ · † ‡€‰ ‰ ‰€† ‡€‰ ‰ ‰ˆ† ‡ ·   · † ‡ ·   · † ‡ · ƒ ‰€† ‡ · ƒ ‰ˆ† ‡ˆ‰ ‚ · † ‡ˆ‰ ‚ · † ‡ˆ‰ ‰ ‰€† ‡ˆ ˆ‰ˆ ˆ† ",
   "‡ · · · † ‡ · · · † ‡ · ŽŽŽŽ† ‡ · ŽŽŽŽ† ‡Ž · † ‡Ž · † ‡ŽŽŽŽ† ‡ŽŽŽŽ† ‡ · · · † ‡ · · · † ‡ · ŽŽŽŽ† ‡ · ŽŽŽŽ† ‡Ž · † ‡Ž · † ‡ŽŽŽŽ† ‡ŽŽŽŽ† ",
   "„€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… ",
};

/*>                                                                                                                                                                   <* 
 *> counting system is hex - one block is 0 - 15.                                                                                                                     <*
 *>                                                                                                                                                                   <*
 *> ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚ ƒ€‰€‰€‰€‚   <* 
 *> ‡ · · · † ‡ · Ž† ‡ · · · † ‡ · Ž† ‡ · · · † ‡ · Ž† ‡ · · · † ‡ · Ž† ‡ŽŽŽŽ · † ‡ŽŽŽŽ† ‡ŽŽŽŽ · † ‡ŽŽŽŽ† ‡ŽŽŽŽ · † ‡ŽŽŽŽ† ‡ŽŽŽŽ · † ‡ŽŽŽŽ†   <* 
 *> ‡       † ‡ · „ €ˆ† ‡ ·   · † ‡ · ƒ ‰ˆ† ‡ ·   · † ‡ · ƒ €ˆ† ‡ ·   · † ‡ · ƒ ‰ˆ† ‡ˆ€ … · † ‡ˆ€ € €ˆ† ‡ˆ€ ‚ · † ‡ˆ€ ‰ ‰ˆ† ‡ˆ‰ ‚ · † ‡ˆ‰ ‰ €ˆ† ‡ˆ‰ ‚ · † ‡ˆ ˆ‰ˆ ˆ†   <* 
 *> ‡       † ‡ ·   · † ‡ · ƒ ‰€† ‡ · ƒ ‰ˆ† ‡€‰ ‚ · † ‡€‰ ‚ · † ‡€‰ ‰ ‰€† ‡€‰ ‰ ‰ˆ† ‡ ·   · † ‡ ·   · † ‡ · ƒ ‰€† ‡ · ƒ ‰ˆ† ‡ˆ‰ ‚ · † ‡ˆ‰ ‚ · † ‡ˆ‰ ‰ ‰€† ‡ˆ ˆ‰ˆ ˆ†   <* 
 *> ‡ · · · † ‡ · · · † ‡ · ŽŽŽŽ† ‡ · ŽŽŽŽ† ‡Ž · † ‡Ž · † ‡ŽŽŽŽ† ‡ŽŽŽŽ† ‡ · · · † ‡ · · · † ‡ · ŽŽŽŽ† ‡ · ŽŽŽŽ† ‡Ž · † ‡Ž · † ‡ŽŽŽŽ† ‡ŽŽŽŽ†   <* 
 *> „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€… „€ˆ€ˆ€ˆ€…   <* 
 *>                                                                                                                                                                   <*
 *> changing each of the four   to Ï is the greater hex digit which leads to a full byte 0 - 255.                                                                     <*
 *>                                                                                                                                                                   <*/


char
yascii_mayan__cons      (char x_orient, char n, char a_opt, int x, int y, char a_mode)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   short       x_row       =    0;
   short       x_col       =    0;
   char        w           =    0;
   char        h           =    0;
   char        i           =    0;
   char        t           [LEN_LABEL] = "";
   /*---(begin)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   DEBUG_YASCII   yLOG_complex ("args"      , "%c, %2d, %2d, %3dx, %3dy, %c", x_orient, n, a_opt, x, y, a_mode);
   /*---(defense)------------------------*/
   DEBUG_YASCII   yLOG_value   ("n"         , n);
   --rce;  if (n < 0 || n > 16) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_value   ("a_opt"     , a_opt);
   --rce;  if (a_opt < 0 || a_opt > 18) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(prepare)------------------------*/
   x_row = n * 6;
   DEBUG_YASCII   yLOG_value   ("x_row"     , x_row);
   x_col = a_opt * 10;
   DEBUG_YASCII   yLOG_value   ("x_col"     , x_col);
   w = 10;
   h =  6;
   /*---(display)------------------------*/
   if (e_displayer != NULL) {
      DEBUG_YASCII   yLOG_value   ("y"         , y);
      DEBUG_YASCII   yLOG_value   ("x"         , x);
      for (i = 0; i < h; ++i) {
         sprintf (t, "%*.*s", w, w, mayanc [x_row + i] + x_col);
         e_displayer (x, y + i, t, a_mode);
      }
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit   (__FUNCTION__);
   return 0;
}

char
yascii_mayan__vowel     (char x_orient, char n, char a_opt, int x, int y, char a_mode)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   short       x_row       =    0;
   short       x_col       =    0;
   char        w           =    0;
   char        h           =    0;
   char        i           =    0;
   char        t           [LEN_LABEL] = "";
   char        xo          =    0;
   char        yo          =    0;
   /*---(begin)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   DEBUG_YASCII   yLOG_complex ("args"      , "%c, %2d, %2d, %3dx, %3dy, %c", x_orient, n, a_opt, x, y, a_mode);
   /*---(defense)------------------------*/
   DEBUG_YASCII   yLOG_value   ("n"         , n);
   --rce;  if (n < 0 || n > 16) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_value   ("a_opt"     , a_opt);
   --rce;  if (a_opt < 0 || a_opt > 18) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(prepare)------------------------*/
   switch (x_orient) {
   case 'Ö' : w =  3;  h = 6;  x += xo = 6;  break;
   case '×' : w =  3;  h = 6;                break;
   case 'Õ' : w = 10;  h = 2;  y += yo = 4;  break;
   case 'Ô' : w = 10;  h = 2;                break;
   }
   DEBUG_YASCII   yLOG_complex ("coords"    , "%3dx, %3dy, %1dxo, %1dyo, %2dw, %2dh", x, y, xo, yo, w, h);
   x_row = (n * 6) + yo;
   DEBUG_YASCII   yLOG_value   ("x_row"     , x_row);
   x_col = (a_opt * 10) + xo;
   DEBUG_YASCII   yLOG_value   ("x_col"     , x_col);
   /*---(display)------------------------*/
   if (e_displayer != NULL) {
      DEBUG_YASCII   yLOG_value   ("y"         , y);
      DEBUG_YASCII   yLOG_value   ("x"         , x);
      for (i = 0; i < h; ++i) {
         sprintf (t, "%*.*s", w, w, mayanv [x_row + i] + x_col);
         e_displayer (x, y + i, t, a_mode);
      }
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit   (__FUNCTION__);
   return 0;
}

/*
 *
 * Ö = 4
 * × = 8
 * Ô = 12
 * Õ = 14
 *
 *
 * Ösiyo wina
 *
 * siÀyoÁ
 *
 *
 */

char
yascii_mayan__ncons     (char a_ch)
{
   char        rce         =  -10;
   char       *v           = YSTR_MAYANC;
   char       *p           = NULL;
   --rce;  if (a_ch == 0)  return rce;
   p = strchr (v, a_ch);
   --rce;  if (p == NULL)  return rce;
   return p - v;
}

char
yascii_mayan__nvowel    (char a_ch)
{
   char        rce         =  -10;
   char       *v           = YSTR_MAYANV;
   char       *p           = NULL;
   --rce;  if (a_ch == 0)  return rce;
   p = strchr (v, a_ch);
   --rce;  if (p == NULL)  return rce;
   return p - v;
}

char
yASCII_mayan            (char a_size, char *a_text, char a_gap, int x, int y, int *a_wide, int *a_tall, char a_mode)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         x_len       =    0;
   char        x_work      [LEN_RECD];
   char       *p           = NULL;
   char       *q           = " '";
   char       *r           = NULL;
   int         l           =    0;
   char        x_orient    =  'Ö';
   char        oc, ov, c, v;
   char        i           =    0;
   /*---(begin)--------------------------*/
   DEBUG_YASCII   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YASCII   yLOG_point   ("a_text"    , a_text);
   --rce;  if (a_text == NULL) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YASCII   yLOG_info    ("a_text"    , a_text);
   strcpy (x_work, a_text);
   x_len = strlen (x_work);
   DEBUG_YASCII   yLOG_value   ("x_len"     , x_len);
   --rce;  if (x_len <= 0) {
      DEBUG_YASCII   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(walk through text)--------------*/
   p = strtok_r (x_work, q, &r);
   while (p != NULL) {
      i = 0;
      l = strlen (p);
      /*---(orientation)-----------------*/
      x_orient = p [0];
      switch (x_orient) {
      case 'Ö' : oc =  4;  ov =  0;  i++;  break;
      case '×' : oc =  8;  ov =  6;  i++;  break;
      case 'Õ' : oc = 12;  ov = 12;  i++;  break;
      case 'Ô' : oc = 14;  ov = 18;  i++;  break;
      default  : oc =  4;  ov =  0;  x_orient = 'Ö';  break;
      }
      l = strlen (p + i);
      if (l >= 2) {
         /*---(get first image)-------------*/
         c = yascii_mayan__ncons  (p [i++]);
         v = yascii_mayan__nvowel (p [i++]);
         /*---(display)---------------------*/
         yascii_mayan__cons  (x_orient, c, oc, x, y, a_mode);
         yascii_mayan__vowel (x_orient, v, ov, x, y, a_mode);
         l = strlen (p + i);
         if (l >= 2) {
            x += 10;
            /*---(get first image)-------------*/
            c = yascii_mayan__ncons  (p [i++]);
            v = yascii_mayan__nvowel (p [i++]);
            /*---(display)---------------------*/
            yascii_mayan__cons  (x_orient, c, oc, x, y, a_mode);
            yascii_mayan__vowel (x_orient, v, ov, x, y, a_mode);
         }
      }
      /*---(next)------------------------*/
      p = strtok_r (NULL, q, &r);
   }
   /*---(complete)-----------------------*/
   DEBUG_YASCII   yLOG_exit   (__FUNCTION__);
   return 0;
}

