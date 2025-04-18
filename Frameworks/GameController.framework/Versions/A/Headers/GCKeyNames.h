//
//  GCKeys.h
//  GameController
//
//  Copyright © 2020 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GameController/GCExtern.h>

NS_ASSUME_NONNULL_BEGIN

/**
A set of strings that can be used to access keyboard buttons
 
 @example keyboard.physicalInputProfile.buttons[GCKeySpacebar]
 
@see GCKeyboardInput.h
@see GCPhysicalInputProfile.h
*/

GAMECONTROLLER_EXPORT NSString *const GCKeyA API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* a or A */
GAMECONTROLLER_EXPORT NSString *const GCKeyB API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* b or B */
GAMECONTROLLER_EXPORT NSString *const GCKeyC API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* c or C */
GAMECONTROLLER_EXPORT NSString *const GCKeyD API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* d or D */
GAMECONTROLLER_EXPORT NSString *const GCKeyE API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* e or E */
GAMECONTROLLER_EXPORT NSString *const GCKeyF API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* f or F */
GAMECONTROLLER_EXPORT NSString *const GCKeyG API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* g or G */
GAMECONTROLLER_EXPORT NSString *const GCKeyH API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* h or H */
GAMECONTROLLER_EXPORT NSString *const GCKeyI API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* i or I */
GAMECONTROLLER_EXPORT NSString *const GCKeyJ API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* j or J */
GAMECONTROLLER_EXPORT NSString *const GCKeyK API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* k or K */
GAMECONTROLLER_EXPORT NSString *const GCKeyL API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* l or L */
GAMECONTROLLER_EXPORT NSString *const GCKeyM API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* m or M */
GAMECONTROLLER_EXPORT NSString *const GCKeyN API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* n or N */
GAMECONTROLLER_EXPORT NSString *const GCKeyO API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* o or O */
GAMECONTROLLER_EXPORT NSString *const GCKeyP API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* p or P */
GAMECONTROLLER_EXPORT NSString *const GCKeyQ API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* q or Q */
GAMECONTROLLER_EXPORT NSString *const GCKeyR API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* r or R */
GAMECONTROLLER_EXPORT NSString *const GCKeyS API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* s or S */
GAMECONTROLLER_EXPORT NSString *const GCKeyT API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* t or T */
GAMECONTROLLER_EXPORT NSString *const GCKeyU API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* u or U */
GAMECONTROLLER_EXPORT NSString *const GCKeyV API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* v or V */
GAMECONTROLLER_EXPORT NSString *const GCKeyW API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* w or W */
GAMECONTROLLER_EXPORT NSString *const GCKeyX API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* x or X */
GAMECONTROLLER_EXPORT NSString *const GCKeyY API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* y or Y */
GAMECONTROLLER_EXPORT NSString *const GCKeyZ API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                           /* z or Z */
GAMECONTROLLER_EXPORT NSString *const GCKeyOne API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                         /* 1 or ! */
GAMECONTROLLER_EXPORT NSString *const GCKeyTwo API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                         /* 2 or @ */
GAMECONTROLLER_EXPORT NSString *const GCKeyThree API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                       /* 3 or # */
GAMECONTROLLER_EXPORT NSString *const GCKeyFour API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                        /* 4 or $ */
GAMECONTROLLER_EXPORT NSString *const GCKeyFive API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                        /* 5 or % */
GAMECONTROLLER_EXPORT NSString *const GCKeySix API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                         /* 6 or ^ */
GAMECONTROLLER_EXPORT NSString *const GCKeySeven API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                       /* 7 or & */
GAMECONTROLLER_EXPORT NSString *const GCKeyEight API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                       /* 8 or * */
GAMECONTROLLER_EXPORT NSString *const GCKeyNine API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                        /* 9 or ( */
GAMECONTROLLER_EXPORT NSString *const GCKeyZero API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                        /* 0 or ) */
GAMECONTROLLER_EXPORT NSString *const GCKeyReturnOrEnter API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));               /* Return (Enter) */
GAMECONTROLLER_EXPORT NSString *const GCKeyEscape API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                      /* Escape */
GAMECONTROLLER_EXPORT NSString *const GCKeyDeleteOrBackspace API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));           /* Delete (Backspace) */
GAMECONTROLLER_EXPORT NSString *const GCKeyTab API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                         /* Tab */
GAMECONTROLLER_EXPORT NSString *const GCKeySpacebar API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                    /* Spacebar */
GAMECONTROLLER_EXPORT NSString *const GCKeyHyphen API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                      /* - or _ */
GAMECONTROLLER_EXPORT NSString *const GCKeyEqualSign API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                   /* = or + */
GAMECONTROLLER_EXPORT NSString *const GCKeyOpenBracket API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                 /* [ or { */
GAMECONTROLLER_EXPORT NSString *const GCKeyCloseBracket API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                /* ] or } */
GAMECONTROLLER_EXPORT NSString *const GCKeyBackslash API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                   /* \ or | */
GAMECONTROLLER_EXPORT NSString *const GCKeyNonUSPound API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                  /* Non-US # or _ */
GAMECONTROLLER_EXPORT NSString *const GCKeySemicolon API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                   /* ; or : */
GAMECONTROLLER_EXPORT NSString *const GCKeyQuote API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                       /* ' or " */
GAMECONTROLLER_EXPORT NSString *const GCKeyGraveAccentAndTilde API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));         /* Grave Accent and Tilde */
GAMECONTROLLER_EXPORT NSString *const GCKeyComma API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                       /* , or < */
GAMECONTROLLER_EXPORT NSString *const GCKeyPeriod API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                      /* . or > */
GAMECONTROLLER_EXPORT NSString *const GCKeySlash API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                       /* / or ? */
GAMECONTROLLER_EXPORT NSString *const GCKeyCapsLock API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                    /* Caps Lock */

/* Function keys */
GAMECONTROLLER_EXPORT NSString *const GCKeyF1 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                          /* F1 */
GAMECONTROLLER_EXPORT NSString *const GCKeyF2 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                          /* F2 */
GAMECONTROLLER_EXPORT NSString *const GCKeyF3 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                          /* F3 */
GAMECONTROLLER_EXPORT NSString *const GCKeyF4 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                          /* F4 */
GAMECONTROLLER_EXPORT NSString *const GCKeyF5 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                          /* F5 */
GAMECONTROLLER_EXPORT NSString *const GCKeyF6 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                          /* F6 */
GAMECONTROLLER_EXPORT NSString *const GCKeyF7 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                          /* F7 */
GAMECONTROLLER_EXPORT NSString *const GCKeyF8 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                          /* F8 */
GAMECONTROLLER_EXPORT NSString *const GCKeyF9 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                          /* F9 */
GAMECONTROLLER_EXPORT NSString *const GCKeyF10 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                         /* F10 */
GAMECONTROLLER_EXPORT NSString *const GCKeyF11 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                         /* F11 */
GAMECONTROLLER_EXPORT NSString *const GCKeyF12 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                         /* F12 */
GAMECONTROLLER_EXPORT NSString *const GCKeyF13 API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0));                         /* F13 */
GAMECONTROLLER_EXPORT NSString *const GCKeyF14 API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0));                         /* F14 */
GAMECONTROLLER_EXPORT NSString *const GCKeyF15 API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0));                         /* F15 */
GAMECONTROLLER_EXPORT NSString *const GCKeyF16 API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0));                         /* F16 */
GAMECONTROLLER_EXPORT NSString *const GCKeyF17 API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0));                         /* F17 */
GAMECONTROLLER_EXPORT NSString *const GCKeyF18 API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0));                         /* F18 */
GAMECONTROLLER_EXPORT NSString *const GCKeyF19 API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0));                         /* F19 */
GAMECONTROLLER_EXPORT NSString *const GCKeyF20 API_AVAILABLE(macos(12.0), ios(15.0), tvos(15.0));                         /* F20 */
GAMECONTROLLER_EXPORT NSString *const GCKeyPrintScreen API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                 /* Print Screen */
GAMECONTROLLER_EXPORT NSString *const GCKeyScrollLock API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                  /* Scroll Lock */
GAMECONTROLLER_EXPORT NSString *const GCKeyPause API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                       /* Pause */
GAMECONTROLLER_EXPORT NSString *const GCKeyInsert API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                      /* Insert */
GAMECONTROLLER_EXPORT NSString *const GCKeyHome API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                        /* Home */
GAMECONTROLLER_EXPORT NSString *const GCKeyPageUp API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                      /* Page Up */
GAMECONTROLLER_EXPORT NSString *const GCKeyDeleteForward API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));               /* Delete Forward */
GAMECONTROLLER_EXPORT NSString *const GCKeyEnd API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                         /* End */
GAMECONTROLLER_EXPORT NSString *const GCKeyPageDown API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                    /* Page Down */
GAMECONTROLLER_EXPORT NSString *const GCKeyRightArrow API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                  /* Right Arrow */
GAMECONTROLLER_EXPORT NSString *const GCKeyLeftArrow API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                   /* Left Arrow */
GAMECONTROLLER_EXPORT NSString *const GCKeyDownArrow API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                   /* Down Arrow */
GAMECONTROLLER_EXPORT NSString *const GCKeyUpArrow API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                     /* Up Arrow */

/* Keypad (numpad) keys */
GAMECONTROLLER_EXPORT NSString *const GCKeyKeypadNumLock API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));               /* Keypad NumLock or Clear */
GAMECONTROLLER_EXPORT NSString *const GCKeyKeypadSlash API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                 /* Keypad / */
GAMECONTROLLER_EXPORT NSString *const GCKeyKeypadAsterisk API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));              /* Keypad * */
GAMECONTROLLER_EXPORT NSString *const GCKeyKeypadHyphen API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                /* Keypad - */
GAMECONTROLLER_EXPORT NSString *const GCKeyKeypadPlus API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                  /* Keypad + */
GAMECONTROLLER_EXPORT NSString *const GCKeyKeypadEnter API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                 /* Keypad Enter */
GAMECONTROLLER_EXPORT NSString *const GCKeyKeypad1 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                     /* Keypad 1 or End */
GAMECONTROLLER_EXPORT NSString *const GCKeyKeypad2 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                     /* Keypad 2 or Down Arrow */
GAMECONTROLLER_EXPORT NSString *const GCKeyKeypad3 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                     /* Keypad 3 or Page Down */
GAMECONTROLLER_EXPORT NSString *const GCKeyKeypad4 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                     /* Keypad 4 or Left Arrow */
GAMECONTROLLER_EXPORT NSString *const GCKeyKeypad5 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                     /* Keypad 5 */
GAMECONTROLLER_EXPORT NSString *const GCKeyKeypad6 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                     /* Keypad 6 or Right Arrow */
GAMECONTROLLER_EXPORT NSString *const GCKeyKeypad7 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                     /* Keypad 7 or Home */
GAMECONTROLLER_EXPORT NSString *const GCKeyKeypad8 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                     /* Keypad 8 or Up Arrow */
GAMECONTROLLER_EXPORT NSString *const GCKeyKeypad9 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                     /* Keypad 9 or Page Up */
GAMECONTROLLER_EXPORT NSString *const GCKeyKeypad0 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                     /* Keypad 0 or Insert */
GAMECONTROLLER_EXPORT NSString *const GCKeyKeypadPeriod API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                /* Keypad . or Delete */
GAMECONTROLLER_EXPORT NSString *const GCKeyKeypadEqualSign API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));             /* Keypad = */
GAMECONTROLLER_EXPORT NSString *const GCKeyNonUSBackslash API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));              /* Non-US \ or | */

GAMECONTROLLER_EXPORT NSString *const GCKeyApplication API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                 /* Application */
GAMECONTROLLER_EXPORT NSString *const GCKeyPower API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                       /* Power */

GAMECONTROLLER_EXPORT NSString *const GCKeyInternational1 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));              /* International1 */
GAMECONTROLLER_EXPORT NSString *const GCKeyInternational2 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));              /* International2 */
GAMECONTROLLER_EXPORT NSString *const GCKeyInternational3 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));              /* International3 */
GAMECONTROLLER_EXPORT NSString *const GCKeyInternational4 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));              /* International4 */
GAMECONTROLLER_EXPORT NSString *const GCKeyInternational5 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));              /* International5 */
GAMECONTROLLER_EXPORT NSString *const GCKeyInternational6 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));              /* International6 */
GAMECONTROLLER_EXPORT NSString *const GCKeyInternational7 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));              /* International7 */
GAMECONTROLLER_EXPORT NSString *const GCKeyInternational8 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));              /* International8 */
GAMECONTROLLER_EXPORT NSString *const GCKeyInternational9 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));              /* International9 */

/* LANG1: On Apple keyboard for Japanese, this is the kana switch (かな) key */
/* On Korean keyboards, this is the Hangul/English toggle key. */
GAMECONTROLLER_EXPORT NSString *const GCKeyLANG1 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                       /* LANG1 */

/* LANG2: On Apple keyboards for Japanese, this is the alphanumeric (英数) key */
/* On Korean keyboards, this is the Hanja conversion key. */
GAMECONTROLLER_EXPORT NSString *const GCKeyLANG2 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                       /* LANG2 */

/* LANG3: Defines the Katakana key for Japanese USB word-processing keyboards. */
GAMECONTROLLER_EXPORT NSString *const GCKeyLANG3 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                       /* LANG3 */

/* LANG4: Defines the Hiragana key for Japanese USB word-processing keyboards. */
GAMECONTROLLER_EXPORT NSString *const GCKeyLANG4 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                       /* LANG4 */

/* LANG5: Defines the Zenkaku/Hankaku key for Japanese USB word-processing keyboards. */
GAMECONTROLLER_EXPORT NSString *const GCKeyLANG5 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                       /* LANG5 */

/* LANG6-9: Reserved for language-specific functions, such as Front End Processors and Input Method Editors. */
GAMECONTROLLER_EXPORT NSString *const GCKeyLANG6 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                       /* LANG6 */
GAMECONTROLLER_EXPORT NSString *const GCKeyLANG7 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                       /* LANG7 */
GAMECONTROLLER_EXPORT NSString *const GCKeyLANG8 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                       /* LANG8 */
GAMECONTROLLER_EXPORT NSString *const GCKeyLANG9 API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                       /* LANG9 */

GAMECONTROLLER_EXPORT NSString *const GCKeyLeftControl API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                 /* Left Control */
GAMECONTROLLER_EXPORT NSString *const GCKeyLeftShift API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                   /* Left Shift */
GAMECONTROLLER_EXPORT NSString *const GCKeyLeftAlt API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                     /* Left Alt */
GAMECONTROLLER_EXPORT NSString *const GCKeyLeftGUI API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                     /* Left GUI */
GAMECONTROLLER_EXPORT NSString *const GCKeyRightControl API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                /* Right Control */
GAMECONTROLLER_EXPORT NSString *const GCKeyRightShift API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                  /* Right Shift */
GAMECONTROLLER_EXPORT NSString *const GCKeyRightAlt API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                    /* Right Alt */
GAMECONTROLLER_EXPORT NSString *const GCKeyRightGUI API_AVAILABLE(macos(11.0), ios(14.0), tvos(14.0));                    /* Right GUI */

NS_ASSUME_NONNULL_END
