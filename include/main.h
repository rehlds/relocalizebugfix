#ifndef _MAIN_H_
#define _MAIN_H_

#include "precompiled.h"

extern DLL_FUNCTIONS *g_pFunctionTable;

extern int localize_string(char *buf);
extern bool OnMetaAttach();
extern void ClientCommand(edict_t *pEdict);

#endif // _MAIN_H_
