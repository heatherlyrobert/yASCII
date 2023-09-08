/*===[[ START ]]==============================================================*/
#include    "yASCII.h"
#include    "yASCII_priv.h"



/*> static const char mayanc       [LEN_MAYANT][LEN_MAYANC] = {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  <* 
 *>    " ƒ€‰€‰€‚ ƒ€€‰€‰€€‚ƒ€€‰€‰€€‚ƒ€€‰€‰€€‚ƒ€€€‰€€€‚ƒ€€€‰€€€‚ƒ€€€‰€€€‚ƒ€€€‰€€€‚ƒ€‰€‰€‰€‚ƒ€‰€‰€‰€‚ƒ€‰€‰€‰€‚ƒ€‰€‰€‰€‚ƒ€‰€‰€‰€‚ƒ€‰€‰€‰€‚ƒ€€€€€€€‚ƒ€€€€€€€‚ƒ€€€‰€€€‚ƒ€€‰€€€€‚ƒ€€€€‰€€‚ƒ€€‰€€€€‚ƒ€‰‚‰ƒ‰€‚ƒ‰‰‚‰ƒ‰‰‚ƒ€€‚‰ƒ€€‚ƒ‰‰‚‰ƒ‰‰‚ƒ€€€‰€€€‚ƒ€‰€‰€‰€‚ƒ€‰€‰€‰€‚ƒ€‰€‰€‰€‚ƒ€ƒ€‰ ‰€‚ƒ€‰ ‰€‚€‚ƒ€‰‰‰€’“‚ƒ’“€‰‰‰€‚ƒ‰€€€€€‰‚ƒ‰€‰€‰€‰‚ƒ‰€€€€€‰‚ƒ‰€€€€€‰‚ƒ‰€€€€€€‚ƒ€€€€€€‰‚ƒ‰€€‰€‰€‚ƒ€‰€‰€€‰‚ƒ€‰€€‰€‰‚ƒ‰€‰€€‰€‚ƒ€€€€€€€‚ƒ€€€€€€€‚ƒ‰€€€€€‰‚ƒ‰€€€€€‰‚ƒ€‰€‰€‰€‚ƒ€‰€‰€‰€‚šœœœ‰œœœ™šœœœ‰œœœ™šœœœ‰œœœ™šœœœ‰œœœ™ƒ‰€€‰€€€‚ƒ€€€‰€€‰‚ƒ‰€€‰€€€‚ƒ€€€‰€€‰‚ƒ€ˆ€á‡€‰ƒ€á‘€€€‰á €€€€‰€‰‰€€€áƒ€‰ƒ€‰€‰€‰€‚ƒ€‰€‰€‰€‚ƒ€‰€‰€‰€‚ƒ€‰€‰€‰€‚ƒ€€€‰€€€‚ƒ€‰€€€‰€‚ƒ‰‰‰‰‰‰‰‚ƒ€€€‰€€€‚",   <* 
 *>    "ƒ…   „‚‡€‚ ƒ€†‡€‰† ‡‰€† ‰† ‡‰  á  á  á  á  á  á  á  á  ‡…„†  ‡€€†  ‡‰ˆ‰†  ž Š Ÿ ‡€…      „€†‡€€€€€€€†‡€€€€€€€†  ƒˆ€‚ ƒ€ˆ‚      ƒ…    „€‚  ‡€… „€†‡ˆ… „ˆ†ƒ€† ‡€‚‡ ‡ŽŽ† ƒŠ‚ ‡ ƒŠ‚ †‡€ƒŠ‚€†‡ŽƒŠ‚Ž† † ž Ÿ  ž Ÿ ‡ ƒ€ˆ€ˆ€€ˆ†‡ˆ€€ˆ€ˆ€‚‡Š€‰€‰€Š†‡†ƒ… „‚‡†‡Š€‰€‰€Š†‡Š€€€‰€Š†‡…ƒŠ€‚ †‡ ƒ€Š‚„†‡…€ˆ…  †‡  „ˆ€„†‡€…ƒ‚ž Ÿž Ÿƒ‚„€†‡‚ƒ†‡ ƒ‰‰‚ †Ÿž‡ ƒ‰‰‚ †‡ˆ€ˆ€ˆ€Š†‡Š€ˆ€ˆ€ˆ†‡’“€Š’“‚ž‡      ž‡€€ „€‰€žŸ      ž ƒ€€€‚ †‡ ƒ€€€‚  ƒ‰€€‚ †‡ ƒ€€‰‚  • •  ‡ ‘€‚ ‘€†ƒ€‚ ƒ „€† ƒ€‚ ” ‡€Š€Š€Š€†‡ŽŽŽŽŽŽŽ†‡‰ˆ‰ˆ‰ˆ‰†‡ŽŽŽ† ƒ€‰€‚ ‡€ˆ€‚ƒˆ€†‡†‡€‚ Š ƒ€†",   <* 
 *>    "‡ˆ€… „€ˆ†‡€ˆ… „ˆ€†‡€ˆ… „ˆ€†‡€ˆ… „ˆ€†‡€‚  ƒ€†‡€‰€ˆ€‰€†‡€‰€Š€‰€†‡€€€ˆ€€€† ‡…„†  ‡€€†  ‡ˆ‰ˆ†  ž Š Ÿ ‡€€€…    „€€€†‡€€€€€‚  ƒ€€€€€† ƒ†[]‡€†‡†[]‡€€€† ƒ€ˆ‚    ƒ€ˆ‚ „€€…‰„€€…„€€…‰„€€…„ˆ€…‰„€ˆ…„ˆˆ…‰„ˆˆ… ž  Ÿ ‡ ž  Ÿ †‡€ž  Ÿ€†‡Žž  ŸŽ†ƒ‰† ž Ÿ  ž Ÿ ‡‰‚„‚ †‡ ƒ…‡† „‰… ‡†‡Š… Š „Š†‡Š€ˆ‰ˆ€Š†‡†  ƒ… ‡†ƒ†Š… ‡€†‡€† „Š‡‚ ƒŠ ‡€†‡€† Š‚  €Š…ž Ÿž Ÿ„Š€ ‡œœœœ™ Ÿž šœœœœ†‡ ƒ‚ Ÿž ƒ‚ †‡€‰‰‰‚ †Ÿž ƒ‰‰‰€†Ÿ  „€€…Ÿ  „’“€†Ÿ „€‰€ €†‡€€€Š€ €†‡ ‡ • †  ‡ • † †‡  ƒ  ‘‚  †‡€† „€… ‡€€€† ƒ  ” „€€€†   ‡€€€Š‡€Š€Š€Š€†‡ŽŽŽŽŽŽŽ†‡ˆ‰ˆ‰ˆ‰ˆ†‡ŽŽŽŽ†‡€‡€Š€†€†‡‰ †‡ˆˆŠˆŠˆˆ†ž    Ÿ",   <* 
 *>    "‡‰€‚ ƒ€‰†‡€‰‚ ƒ‰€†‡€‰‚ ƒ‰€†‡€‰‚ ƒ‰€†ž „‚Šƒ… Ÿ‡€ˆ™ šˆ€† ž   Ÿ  ƒœœœ‚  ‡…„†  ‡€€†  ‡‰ˆ‰†  ž Š Ÿ ‡€€€€€…  „€€€€€†‡€€€‚    ƒ€€€†‡€…„€‰… „€‰…   ƒ†[]‡€€†ƒ€†[]‡€†ƒ€€‚ˆƒ€€‚ƒ€€‚ˆƒ€€‚ƒ‰€‚ˆƒ€‰‚ƒ‰‰‚ˆƒ‰‰‚ ž  Ÿ ‡ ž  Ÿ †‡€ž  Ÿ€†‡Žž  ŸŽ†‡€† ž Ÿ  ž Ÿ ‡€†ƒœœœœœ… †‡ „œœœœœ‚‡† ƒˆ‚ ‡†‡Š‚ Š ƒŠ†‡Š€ƒˆ‰€Š†‡† ƒ…  ‡†‡€… €‚    ƒ€ „€† Š…„€…  „€…„Š ‡˜ Ÿž ›† €Š‚ž Ÿž ŸƒŠ€ ‡€ˆˆˆ… †Ÿž‡ „ˆˆˆ€†‡ „… Ÿž „… †Ÿ „€‰€‰€†Ÿ „€‰€‰€†Ÿ ‚  ƒ€ž‡€‚  ƒ€ž „€…  †‡  „€…  ‡  † †‡ ‡  †  „€‰€‚ †‡€ „€† ‡€‰€‰€€ ‡€… ” ƒ€…‡€Š€Š€Š€†‡ŽŽŽŽŽŽŽ†‡‰ˆ‰ˆ‰ˆ‰†‡ŽŽŽ†‡€‡€Š€†€†      ‡ †  † ‡  ž    Ÿ",   <* 
 *>    "„‚   ƒ…‡€… „€†‡€„† ‡„€† ˆ† ‡ˆ ž ƒ…„‚ Ÿ  ž Ÿ  ‡€†   ‡€†‡€ˆ€Š€ˆ€† ‡…„†  ‡€€†  ‡ˆ‰ˆ†  ž Š Ÿ ‡€€€€€€€†‡€€€€€€€†‡€‚      ƒ€†   ƒ…    „‚   ‡…„€‰…  ‡… „€‰… ƒ‚ ƒ‚„€‚ ƒ€…„€ ‡€…‡ŽŽ ‡† „œŠœ… ‡ „œŠœ… †‡€„œŠœ…€†‡Ž„œŠœ…Ž†  „€…  „€…  ‡€€€€€€€†‡€€€€€€€†‡Š€ˆ€ˆ€Š†‡†„‚ ƒ…‡†‡Š€ˆ€ˆ€Š†‡Š€ˆ€€€Š†‡€€€‰…  †‡  „‰€€€† „‰€      €‰… ‡œœœœœœ…„œœœœœœ†‡€‚„…ž Ÿž Ÿ„…ƒ€†‡‰€‰€‰€Š†‡Š€‰€‰€‰†‡ „ˆˆ… †Ÿž „ˆˆ… †‡’“€€€† žŸ’“€‡€  ž‡€…   †Ÿ€…   †‡ˆ€€ˆ€…  „€ˆ€€ˆ†‡  „€…  „€…  †‡€ ” ” ‡€€€   ”    • … ƒ€‰€† •‡€Š€Š€Š€†‡ŽŽŽŽŽŽŽ†‡ˆ‰ˆ‰ˆ‰ˆ†‡ŽŽŽŽ† „€ˆ€… ‡œœœœœˆ †  † ‡  ‡€… Š „€†",   <* 
 *>    " „€ˆ€ˆ€… „€€ˆ€ˆ€€…„€€ˆ€ˆ€€…„€€ˆ€ˆ€€…„€„€ˆ€…€…„€€˜ ›€€…„€ˆ€€€ˆ€…„€€€ˆ€€€…„€ˆ€ˆ€ˆ€…„€ˆ€ˆ€ˆ€…„€ˆ€ˆ€ˆ€…„€ˆ€ˆ€ˆ€…„€€€€€€€…„€€€€€€€…„€ˆ€ˆ€ˆ€…„€ˆ€ˆ€ˆ€…„€€€ˆ€€€…„€€€ˆ€€€…„€€€ˆ€€€…„€€€€ˆ€€…„…„…ˆ„…„…„ „…ˆ„… …„€€…ˆ„€€…„ˆˆ…ˆ„ˆˆ…„€€€ˆ€€€…„€ˆ€ˆ€ˆ€…„€ˆ€ˆ€ˆ€…„€ˆ€ˆ€ˆ€…„€ˆ€ˆ€ˆ€…„€ˆ€ˆ€ˆ€…„€€€€€€€…„€€€€€€€…„ˆ€€€€€ˆ…„ˆ€ˆ€ˆ€ˆ…„ˆ€€€€€ˆ…„ˆ€€€€€ˆ…„€ˆ€ˆ€€€…„€€€ˆ€ˆ€…„€€ˆ€€ˆ€…„€ˆ€€ˆ€€…„€€€€€€€…„€€€€€€€…„€ˆ€€ˆ€ˆ…„ˆ€ˆ€€ˆ€…„€ˆ€ˆ€ˆ€…„€ˆ€ˆ€ˆ€…„ˆ€€€€€ˆ…„ˆ€€€€€ˆ…›„…˜›„…˜›„…˜›„…˜„€€ˆ€€ˆ€…„€ˆ€€ˆ€€…„€ˆ€€€ˆ€…„€ˆ€€€ˆ€…”´ƒ€‰€€€…‡€‰€‚´„€…‘€…´„€ˆ€…´ … ” „€…„€ˆ€ˆ€ˆ€…„€ˆ€ˆ€ˆ€…„€ˆ€ˆ€ˆ€…„€ˆ€ˆ€ˆ€…„€€€ˆ€€€…„€ˆ€€€ˆ€…„€€ˆ€ˆ€€…„€€€ˆ€€€…",   <* 
 *> };                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           <*/

/*> static const char mayanv       [LEN_MAYANT][LEN_MAYANV] = {                       <* 
 *>    "š€™  ƒ‚ ƒ€‚ ƒ€‚ ƒ€‚ ƒ‰‚ ƒ‰‚ ‘€‚ ƒ€‚ ƒ‰‚ ƒ‚  ƒ€‚ ƒ€‚ ƒ‰‚",                    <* 
 *>    "Ÿ ž  ž Ÿ ƒ… ‡€† „‰… ‡† ‡Š† ‘Š† „‚ ” „Š‚ ‡    ‡ˆ†",                    <* 
 *>    "Ÿ ž  ž Ÿ ƒ… ‡€† ƒˆ‚ ‡† ‡Š† ‘€† ƒ… • ƒŠ… ‡    ‡‰†",                    <* 
 *>    "Ÿ ž  ž Ÿ ƒ… ‡€† „‰… ‡† ‡Š† ‘€† „‚ ” „Š‚ ‡    ‡ˆ†",                    <* 
 *>    "Ÿ ž  ž Ÿ ƒ… ‡€† ƒˆ‚ ‡† ‡Š† ‘Š† ƒ… • ƒŠ… ‡    ‡‰†",                    <* 
 *>    "›€˜  „œ… „€… „€… „€… „ˆ… „ˆ… ‘€… „€… „ˆ… „…  „€… „€… „ˆ…",                    <* 
 *> };                                                                                <*/
