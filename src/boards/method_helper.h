#ifndef PANEL_METHOD_HELPER
#define PANEL_METHOD_HELPER

#include "../Settings.h"

#if PANEL_Y > 32
#define PANEL_ADVANCE_ROW PANEL_ROW_VAR = (PANEL_ROW_VAR + 1) & (uint8_t)31;
#else
#if PANEL_Y > 16
#define PANEL_ADVANCE_ROW PANEL_ROW_VAR = (PANEL_ROW_VAR + 1) & (uint8_t)15;
#else
#if PANEL_Y > 8
#define PANEL_ADVANCE_ROW PANEL_ROW_VAR = (PANEL_ROW_VAR + 1) & (uint8_t)7;
#else
#if PANEL_Y > 4
#define PANEL_ADVANCE_ROW PANEL_ROW_VAR = (PANEL_ROW_VAR + 1) & (uint8_t)3;
#endif
#endif
#endif
#endif

#endif // PANEL_METHOD_HELPER