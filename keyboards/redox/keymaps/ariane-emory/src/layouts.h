// -*- c-backslash-column: 80; c-backslash-max-column: 80 ; fill-column: 80; eval: (display-fill-column-indicator-mode 1); -*-

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
#define QT_E     LBRM_4(KC_E)
#define QT_R     LBRM_4(KC_R)
#define QT_T     KC_T
#define QT_Y     KC_Y
#define QT_U     RBRM_4(KC_U)
#define QT_I     RBRM_4(KC_I)
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
#define QB_V     LBRM_1(KC_V)
#define QB_B     KC_B
#define QB_N     KC_N
#define QB_M     RBRM_1(KC_M)
#define QB_COMM  KC_COMM
#define QB_DOT   KC_DOT
#define QB_SLSH  LBRM_4(QB_RC)
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
#define WB_V    LBRM_1(KC_C)
#define WB_B    KC_V
#define WB_N    KC_K
#define WB_M    RBRM_1(KC_L)
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
#define KB_V    LBRM_1(KC_D)
#define KB_B    KC_V
#define KB_N    KC_K
#define KB_M    RBRM_1(KC_N)
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
#define CB_V    LBRM_1(KC_D)
#define CB_B    KC_V
#define CB_N    KC_K
#define CB_M    RBRM_1(KC_H)
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
#define DB_V    LBRM_1(KC_K)
#define DB_B    KC_X
#define DB_N    KC_B
#define DB_M    RBRM_1(KC_M)
#define DB_COMM KC_W
#define DB_DOT  KC_V
#define DB_SLSH RBRM_4(DB_RC)
//==============================================================================


//==============================================================================
// Y: 'Threatish' layout 
//==============================================================================
#define YT_Q    KC_Z
#define YT_W    KC_F
#define YT_E    KC_N
#define YT_R    KC_G
#define YT_T    KC_Q
#define YT_Y    KC_J
#define YT_U    KC_Y
#define YT_I    KC_O
#define YT_O    KC_U
#define YT_P    KC_SLSH
//------------------------------------------------------------------------------
#define YH_A    LHRM_4(KC_C)
#define YH_S    LHRM_3(KC_S)
#define YH_D    LHRM_2(KC_H)
#define YH_F    LHRM_1(KC_T)
#define YH_G    LHRM_0(KC_M)
#define YH_H    RHRM_0(KC_X)
#define YH_J    RHRM_1(KC_R)
#define YH_K    RHRM_2(KC_E)
#define YH_L    RHRM_3(KC_I)
#define YH_QUOT RHRM_4(KC_A)
//------------------------------------------------------------------------------
#define YB_Z    LBRM_4(KC_P)
#define YB_X    KC_B
#define YB_C    KC_L
#define YB_V    LBRM_1(KC_D)
#define YB_B    KC_V
#define YB_N    KC_K
#define YB_M    RBRM_1(KC_W)
#define YB_COMM KC_COMM
#define YB_DOT  KC_DOT
#define YB_SLSH RBRM_4(KC_QUOT)
//==============================================================================


//==============================================================================
// X: Oxeylyzed 
//==============================================================================
#define XT_Q    KC_Z
#define XT_W    KC_L
#define XT_E    KC_N
#define XT_R    KC_K
#define XT_T    KC_Q
#define XT_Y    KC_P
#define XT_U    KC_Y
#define XT_I    KC_O
#define XT_O    KC_U
#define XT_P    KC_SLSH
//------------------------------------------------------------------------------
#define XH_A    LHRM_4(KC_S)
#define XH_S    LHRM_3(KC_R)
#define XH_D    LHRM_2(KC_H)
#define XH_F    LHRM_1(KC_T)
#define XH_G    LHRM_0(KC_M)
#define XH_H    RHRM_0(KC_G)
#define XH_J    RHRM_1(KC_C)
#define XH_K    RHRM_2(KC_E)
#define XH_L    RHRM_3(KC_I)
#define XH_QUOT RHRM_4(KC_A)
//------------------------------------------------------------------------------
#define XB_Z    LBRM_4(KC_J)
#define XB_X           KC_X
#define XB_C           KC_B
#define XB_V    LBRM_1(KC_D)
#define XB_B           KC_V
#define XB_N           KC_F
#define XB_M    RBRM_1(KC_W)
#define XB_COMM        KC_COMM
#define XB_DOT         KC_DOT
#define XB_SLSH RBRM_4(KC_QUOT)
//==============================================================================


//==============================================================================
// N: Canary (mod)
//==============================================================================
#define NT_Q    KC_Q
#define NT_W    KC_Y
#define NT_E    LBRM_4(KC_L)
#define NT_R    LBRM_4(KC_D)
#define NT_T    KC_K
#define NT_Y    KC_X
#define NT_U    RBRM_4(KC_F)
#define NT_I    RBRM_4(KC_O)
#define NT_O    KC_U
#define NT_P    KC_SLSH
//------------------------------------------------------------------------------
#define NH_A    LHRM_4(KC_W)
#define NH_S    LHRM_3(KC_S)
#define NH_D    LHRM_2(KC_R)
#define NH_F    LHRM_1(KC_T)
#define NH_G    LHRM_0(KC_G)
#define NH_H    RHRM_0(KC_M)
#define NH_J    RHRM_1(KC_H) // N)
#define NH_K    RHRM_2(KC_E)
#define NH_L    RHRM_3(KC_I)
#define NH_QUOT RHRM_4(KC_A)
//------------------------------------------------------------------------------
#define NB_Z    LBRM_4(KC_C)
#define NB_X           KC_V
#define NB_C           KC_J
#define NB_V    LBRM_1(KC_P)
#define NB_B           KC_B
#define NB_N           KC_Z
#define NB_M    RBRM_1(KC_N) // H)
#define NB_COMM        KC_COMM
#define NB_DOT         KC_DOT
#define NB_SLSH RBRM_4(KC_QUOT)
//==============================================================================


//==============================================================================
// G: Graphite
//==============================================================================
#define GT_Q    KC_Q
#define GT_W    KC_L
#define GT_E    KC_D
#define GT_R    KC_W
#define GT_T    KC_Z
#define GT_Y    KC_SLSH
#define GT_U    KC_F
#define GT_I    KC_O
#define GT_O    KC_U
#define GT_P    KC_J
//------------------------------------------------------------------------------
#define GH_A    LHRM_4(KC_N)
#define GH_S    LHRM_3(KC_R)
#define GH_D    LHRM_2(KC_T)
#define GH_F    LHRM_1(KC_S)
#define GH_G    LHRM_0(KC_G)
#define GH_H    RHRM_0(KC_Y)
#define GH_J    RHRM_1(KC_H)
#define GH_K    RHRM_2(KC_A)
#define GH_L    RHRM_3(KC_E)
#define GH_QUOT RHRM_4(KC_I)
//------------------------------------------------------------------------------
#define GB_Z    LBRM_4(KC_B)
#define GB_X           KC_X
#define GB_C           KC_M
#define GB_V    LBRM_1(KC_C)
#define GB_B           KC_V
#define GB_N           KC_K
#define GB_M    RBRM_1(KC_P)
#define GB_COMM        KC_COMM
#define GB_DOT         KC_DOT
#define GB_SLSH RBRM_4(KC_QUOT)
//==============================================================================




//==============================================================================
// H: Gallium Q/B V/J
//==============================================================================
#define HT_Q    KC_Q
#define HT_W    KC_L
#define HT_E    KC_D
#define HT_R    KC_C
#define HT_T    KC_V
#define HT_Y    KC_Z
#define HT_U    KC_Y
#define HT_I    KC_O
#define HT_O    KC_U
#define HT_P    KC_SLSH
//------------------------------------------------------------------------------
#define HH_A    LHRM_4(KC_N)
#define HH_S    LHRM_3(KC_R)
#define HH_D    LHRM_2(KC_T)
#define HH_F    LHRM_1(KC_S)
#define HH_G    LHRM_0(KC_G)
#define HH_H    RHRM_0(KC_P)
#define HH_J    RHRM_1(KC_H)
#define HH_K    RHRM_2(KC_A)
#define HH_L    RHRM_3(KC_E)
#define HH_QUOT RHRM_4(KC_I)
//------------------------------------------------------------------------------
#define HB_Z    LBRM_4(KC_B)
#define HB_X           KC_X
#define HB_C           KC_M
#define HB_V    LBRM_1(KC_W)
#define HB_B           KC_J
#define HB_N           KC_K
#define HB_M    RBRM_1(KC_F)
#define HB_COMM        KC_COMM
#define HB_DOT         KC_DOT
#define HB_SLSH RBRM_4(KC_QUOT)
//==============================================================================


//#define ROTATE_OXEY
//==============================================================================
// M: Another Oxey
//==============================================================================
#define MT_Q    KC_Z
#define MT_W    KC_F
#define MT_E    LBRM_4(KC_R)
#define MT_R    LBRM_4(KC_L)
#define MT_T    KC_K
//..............................................................................
#define MT_Y    KC_X 
#define MT_U    RBRM_4(KC_Y)
#define MT_I    RBRM_4(KC_O) // U // O 
#define MT_O    KC_U // O // U 
#define MT_P    KC_SLSH
//------------------------------------------------------------------------------
#define MH_A    LHRM_4(KC_W)
#define MH_S    LHRM_3(KC_S)
#define MH_D    LHRM_2(KC_N)
#define MH_F    LHRM_1(KC_T)
#define MH_G    LHRM_0(KC_M)
//.............................................................................
#define MH_H    RHRM_0(KC_P) 
#define MH_J    RHRM_1(KC_H)
#define MH_K    RHRM_2(KC_E) // E)
#define MH_L    RHRM_3(KC_I) // E) // I)
#ifdef ROTATE_OXEY
#  define MH_QUOT RHRM_4(KC_QUOT) 
#else
#  define MH_QUOT RHRM_4(KC_A)
#endif
//-----------------------------------------------------------------------------
#define MB_Z    LBRM_4(KC_C)
#define MB_X           KC_B
#define MB_C           KC_Q
#define MB_V    LBRM_1(KC_G)
#define MB_B           KC_V
//.............................................................................
#define MB_N           KC_J 
#define MB_M    RBRM_1(KC_D) 
#define MB_COMM        KC_COMM
#define MB_DOT         KC_DOT
#ifdef ROTATE_OXEY
#    define MB_SLSH RBRM_4(KC_A)
#else
#    define MB_SLSH RBRM_4(KC_QUOT)
#endif
//==============================================================================
