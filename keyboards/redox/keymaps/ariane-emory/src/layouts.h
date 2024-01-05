//==============================================================================
// Main layouts:
//==============================================================================

//==============================================================================
// Q: Qwerty
//==============================================================================
#ifdef ROTATE_RIGHT_COL
# define QT_RC  KC_P
# define QH_RC  KC_QUOT
# define QB_RC  KC_SLSH
#else
# define QT_RC  KC_P
# define QH_RC  KC_QUOT
# define QB_RC  KC_SLSH
#endif
//------------------------------------------------------------------------------
#define QT_TAB   LT(LN_UTIL,KC_TAB)
#define QT_Q     KC_Q
#define QT_W     KC_W
#define QT_E     KC_E
#define QT_R     KC_R
#define QT_T     KC_T
#define QT_Y     KC_Y
#define QT_U     KC_U
#define QT_I     KC_I
#define QT_O     KC_O
#define QT_P     QT_RC
#define QT_BSLS  LT(LN_UTIL,KC_BSLS)
//------------------------------------------------------------------------------
#define QH_CAPS  LCTL_ESC
#define QH_A     LHRM_4(KC_A)
#define QH_S     LHRM_3(KC_S)
#define QH_D     LHRM_2(KC_D)
#define QH_F     LHRM_1(KC_F)
#define QH_G     LHRM_0(KC_G)
#define QH_H     RHRM_0(KC_H)
#define QH_J     RHRM_1(KC_J)
#define QH_K     RHRM_2(KC_K)
#define QH_L     RHRM_3(KC_L)
#define QH_QUOT  RHRM_4(QH_RC)
#define QH_ENTR  RCTL_DQUO
//------------------------------------------------------------------------------
#define QB_Z     LBRM_4(KC_Z)
#define QB_X     KC_X
#define QB_C     KC_C
#define QB_V     LBRM_4(KC_V)
#define QB_B     KC_B
#define QB_N     KC_N
#define QB_M     LBRM_4(KC_M)
#define QB_COMM  KC_COMM
#define QB_DOT   KC_DOT
#define QB_SLSH  LBRM_4(QB_RC)
//==============================================================================


//==============================================================================
// Y: 'Workmak', my modified Workman layout
//==============================================================================
#ifdef ROTATE_RIGHT_COL
# define YT_RC  KC_SLSH
# define YH_RC  KC_QUOT
# define YB_RC  KC_I
#else
# define YT_RC  KC_SLSH
# define YH_RC  KC_I
# define YB_RC  KC_QUOT
#endif
//------------------------------------------------------------------------------
#define YT_Q    KC_Z
#define YT_W    KC_F
#define YT_E    KC_N
#define YT_R    KC_G
#define YT_T    KC_Q
#define YT_Y    KC_J
#define YT_U    KC_Y
#define YT_I    KC_U
#define YT_O    KC_O
#define YT_P    YT_RC
//------------------------------------------------------------------------------
#define YH_A    LHRM_4(KC_B)
#define YH_S    LHRM_3(KC_S)
#define YH_D    LHRM_2(KC_H)
#define YH_F    LHRM_1(KC_T)
#define YH_G    LHRM_0(KC_M)
#define YH_H    RHRM_0(KC_X)
#define YH_J    RHRM_1(KC_R)
#define YH_K    RHRM_2(KC_E)
#define YH_L    RHRM_3(KC_A)
#define YH_QUOT RHRM_4(YH_RC)
//------------------------------------------------------------------------------
#define YB_Z    LBRM_4(KC_P)
#define YB_X    KC_C
#define YB_C    KC_L
#define YB_V    LBRM_4(KC_D) 
#define YB_B    KC_V
#define YB_N    KC_K
#define YB_M    LBRM_4(KC_W)
#define YB_COMM KC_COMM
#define YB_DOT  KC_DOT
#define YB_SLSH RBRM_4(YB_RC)
//==============================================================================


//==============================================================================
// W: Workman
//==============================================================================
#ifdef ROTATE_RIGHT_COL
# define WT_RC  KC_SLSH
# define WH_RC  KC_QUOT
# define WB_RC  KC_I
#else
# define WT_RC  KC_SLSH
# define WH_RC  KC_I
# define WB_RC  KC_QUOT
#endif
//------------------------------------------------------------------------------
#define WT_Q    KC_Q
#define WT_W    KC_D
#define WT_E    KC_R
#define WT_R    KC_W
#define WT_T    KC_B
#define WT_Y    KC_J
#define WT_U    KC_F
#define WT_I    KC_U
#define WT_O    KC_P
#define WT_P    WT_RC
//------------------------------------------------------------------------------
#define WH_A    LHRM_4(KC_A)
#define WH_S    LHRM_3(KC_S)
#define WH_D    LHRM_2(KC_H)
#define WH_F    LHRM_1(KC_T)
#define WH_G    LHRM_0(KC_G)
#define WH_H    RHRM_0(KC_Y)
#define WH_J    RHRM_1(KC_N)
#define WH_K    RHRM_2(KC_E)
#define WH_L    RHRM_3(KC_O)
#define WH_QUOT RHRM_4(WH_RC)
//------------------------------------------------------------------------------
#define WB_Z    LBRM_4(KC_Z)
#define WB_X    KC_X
#define WB_C    KC_M
#define WB_V    LBRM_4(KC_C)
#define WB_B    KC_V
#define WB_N    KC_K
#define WB_M    LBRM_4(KC_L)
#define WB_COMM KC_COMM
#define WB_DOT  KC_DOT
#define WB_SLSH RBRM_4(WB_RC)
//==============================================================================


//==============================================================================
// K: Colemak-DN
//==============================================================================
#ifdef ROTATE_RIGHT_COL
# define KT_RC  KC_SLSH
# define KH_RC  KC_QUOT
# define KB_RC  KC_O
#else
# define KT_RC  KC_SLSH
# define KH_RC  KC_O
# define KB_RC  KC_QUOT
#endif
//------------------------------------------------------------------------------
#define KT_Q    KC_Q
#define KT_W    KC_W
#define KT_E    KC_F
#define KT_R    KC_P
#define KT_T    KC_B
#define KT_Y    KC_J
#define KT_U    KC_L
#define KT_I    KC_U
#define KT_O    KC_Y
#define KT_P    KT_RC
//------------------------------------------------------------------------------
#define KH_A    LHRM_4(KC_A)
#define KH_S    LHRM_3(KC_R)
#define KH_D    LHRM_2(KC_S)
#define KH_F    LHRM_1(KC_T)
#define KH_G    LHRM_0(KC_G)
#define KH_H    RHRM_0(KC_M)
#define KH_J    RHRM_1(KC_H)
#define KH_K    RHRM_2(KC_E)
#define KH_L    RHRM_3(KC_I)
#define KH_QUOT RHRM_4(KH_RC)
//------------------------------------------------------------------------------
#define KB_Z    LBRM_4(KC_Z)
#define KB_X    KC_X
#define KB_C    KC_C
#define KB_V    LBRM_4(KC_D)
#define KB_B    KC_V
#define KB_N    KC_K
#define KB_M    LBRM_4(KC_N)
#define KB_COMM KC_COMM
#define KB_DOT  KC_DOT
#define KB_SLSH RBRM_4(KB_RC)
//==============================================================================


//==============================================================================
// C: Colemak-DH
//==============================================================================
#ifdef ROTATE_RIGHT_COL
# define CT_RC  KC_SLSH
# define CH_RC  KC_QUOT
# define CB_RC  KC_O
#else
# define CT_RC  KC_SLSH
# define CH_RC  KC_O
# define CB_RC  KC_QUOT
#endif
//------------------------------------------------------------------------------
#define CT_Q    KC_Q
#define CT_W    KC_W
#define CT_E    KC_F
#define CT_R    KC_P
#define CT_T    KC_B
#define CT_Y    KC_J
#define CT_U    KC_L
#define CT_I    KC_U
#define CT_O    KC_Y
#define CT_P    CT_RC
//------------------------------------------------------------------------------
#define CH_A    LHRM_4(KC_A)
#define CH_S    LHRM_3(KC_R)
#define CH_D    LHRM_2(KC_S)
#define CH_F    LHRM_1(KC_T)
#define CH_G    LHRM_0(KC_G)
#define CH_H    RHRM_0(KC_M)
#define CH_J    RHRM_1(KC_N)
#define CH_K    RHRM_2(KC_E)
#define CH_L    RHRM_3(KC_I)
#define CH_QUOT RHRM_4(CH_RC)
//------------------------------------------------------------------------------
#define CB_Z    LBRM_4(KC_Z)
#define CB_X    KC_X
#define CB_C    KC_C
#define CB_V    LBRM_4(KC_D)
#define CB_B    KC_V
#define CB_N    KC_K
#define CB_M    LBRM_4(KC_H)
#define CB_COMM KC_COMM
#define CB_DOT  KC_DOT
#define CB_SLSH RBRM_4(CB_RC)
//==============================================================================


//==============================================================================
// D: Dvorak
//==============================================================================
#ifdef ROTATE_RIGHT_COL
# define DT_RC  KC_Z
# define DH_RC  KC_L
# define DB_RC  KC_S
#else
# define DT_RC  KC_L
# define DH_RC  KC_S
# define DB_RC  KC_Z
#endif
//------------------------------------------------------------------------------
#define DT_Q    KC_SLSH
#define DT_W    KC_COMM
#define DT_E    KC_DOT
#define DT_R    KC_P
#define DT_T    KC_Y
#define DT_Y    KC_F
#define DT_U    KC_G
#define DT_I    KC_C
#define DT_O    KC_R
#define DT_P    DT_RC
//------------------------------------------------------------------------------
#define DH_A    LHRM_4(KC_A)
#define DH_S    LHRM_3(KC_O)
#define DH_D    LHRM_2(KC_E)
#define DH_F    LHRM_1(KC_I)
#define DH_G    LHRM_0(KC_U)
#define DH_H    RHRM_0(KC_D)
#define DH_J    RHRM_1(KC_H)
#define DH_K    RHRM_2(KC_T)
#define DH_L    RHRM_3(KC_N)
#define DH_QUOT RHRM_4(DH_RC)
//------------------------------------------------------------------------------
#define DB_Z    LBRM_4(KC_QUOT)
#define DB_X    KC_Q
#define DB_C    KC_J
#define DB_V    LBRM_4(KC_K)
#define DB_B    KC_X
#define DB_N    KC_B
#define DB_M    LBRM_4(KC_M)
#define DB_COMM KC_W
#define DB_DOT  KC_V
#define DB_SLSH RBRM_4(DB_RC)
//==============================================================================


//==============================================================================
// X: Wreathy-JX-Z/Slsh
//==============================================================================
#ifdef ROTATE_RIGHT_COL
# define XT_RC  KC_Z // SLSH
# define XH_RC  KC_QUOT
# define XB_RC  KC_I
#else
# define XT_RC  KC_Z // SLSH
# define XH_RC  KC_I
# define XB_RC  KC_QUOT
#endif
//------------------------------------------------------------------------------
#define XT_Q    KC_Q
#define XT_W    KC_G
#define XT_E    KC_D
#define XT_R    KC_F
#define XT_T    KC_V
#define XT_Y    KC_SLSH // Z
#define XT_U    KC_L
#define XT_I    KC_U
#define XT_O    KC_O
#define XT_P    XT_RC
//------------------------------------------------------------------------------
#define XH_A    LHRM_4(KC_N)
#define XH_S    LHRM_3(KC_S)
#define XH_D    LHRM_2(KC_T)
#define XH_F    LHRM_1(KC_H)
#define XH_G    LHRM_0(KC_Y)
#define XH_H    RHRM_0(KC_W)
#define XH_J    RHRM_1(KC_R)
#define XH_K    RHRM_2(KC_E)
#define XH_L    RHRM_3(KC_A)
#define XH_QUOT RHRM_4(XH_RC)
//------------------------------------------------------------------------------
#define XB_Z    LBRM_4(KC_B)
#define XB_X    KC_C
#define XB_C    KC_M
#define XB_V    LBRM_4(KC_P)
#define XB_B    KC_K
#define XB_N    KC_J
#define XB_M    RBRM_4(KC_X)
#define XB_COMM KC_COMM
#define XB_DOT  KC_DOT
#define XB_SLSH RBRM_4(XB_RC)
//==============================================================================


