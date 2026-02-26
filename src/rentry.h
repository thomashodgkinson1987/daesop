#ifndef RENTRY_H
#define RENTRY_H

#include <stdio.h>

#include "resstr.h"

long getResourceEntryIndex(int i, DIRPOINTER * loDirectoryPointers);
struct RESEntryHeader *getResourceEntryHeader(int aNumber, FILE *aResFile,
		DIRPOINTER * aDirectoryPointers);
int getMaxNumberOfResourceEntries(DIRPOINTER *aDirectoryPointers);
unsigned char *readResourceBinary(int aResourceNumber, FILE *aResFile,
		DIRPOINTER *aDirectoryPointers, int *aResourceLength);

#endif

