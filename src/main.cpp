#include "precompiled.h"

size_t localize_string(const char *OldMsg, char *NewMsg, size_t MaxLen)
{
	size_t remainChars = MaxLen - 1;
	size_t n = 0;

	for (const char *s = OldMsg; *s != '\0' && remainChars; s++)
	{
		if (*s == '#' || *s == '%') {

			if (remainChars < 3) {
				break;
			}

			// http://unicode-table.com/blocks/halfwidth-and-fullwidth-forms/
			NewMsg[n++] = char(0xEF);
			NewMsg[n++] = 0xBC | (((*s - 0x20) & 0x40) >> 6);
			NewMsg[n++] = 0x80 + ((*s - 0x20) & 0x3F);

			remainChars -= 3;
		}
		else
		{
			NewMsg[n++] = *s;
			remainChars--;
		}
	}

	NewMsg[n] = '\0';

	return n;
}

void ClientCommand(edict_t *pEdict)
{
	const char *szArgv = CMD_ARGV(0);

	if (!strcmp(szArgv, "say") || !strcmp(szArgv, "say_team")) {

		auto Buf = CMD_ARGS();

		if (Buf && *Buf) {

			char safeMsg[190];

			auto len = localize_string(Buf, safeMsg, sizeof(safeMsg));

			memcpy(const_cast<char*>(Buf), safeMsg, len + 1);
		}
	}

	RETURN_META(MRES_IGNORED);
}

bool OnMetaAttach()
{
	if (RehldsApi_Init() != RETURN_LOAD) {
		return false;
	}
	return true;
}

