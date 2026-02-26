#ifndef RENTRY_H
#define RENTRY_H

#include <stdio.h>

#include "resstr.h"

long get_resource_entry_index(int i, DIRPOINTER *loDirectoryPointers);
struct RESEntryHeader *get_resource_entry_header(int aNumber, FILE *aResFile,
											  DIRPOINTER *aDirectoryPointers);
int getMaxNumberOfResourceEntries(DIRPOINTER *aDirectoryPointers);
unsigned char *readResourceBinary(int aResourceNumber, FILE *aResFile,
								  DIRPOINTER *aDirectoryPointers, int *aResourceLength);

#endif
