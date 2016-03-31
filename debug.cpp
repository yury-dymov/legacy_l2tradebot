#include "debug.h"

void Debug::write (const string & pck)
{
	FILE *f = fopen ("pck.dbg", "ab");
	for (unsigned int i = 0; i < pck.length (); ++i)
	{
		fprintf (f, "%X%X ", (unsigned char) pck[i] / 0x10, (unsigned char) pck[i] % 0x10);
	}
	fprintf (f, "\n\n");
	fclose (f);
}
