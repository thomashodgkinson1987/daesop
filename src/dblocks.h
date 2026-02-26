#ifndef DBLOCKS_H
#define DBLOCKS_H

#include <stdio.h>

#include "resstr.h"

int read_directory_blocks(FILE *aResFile, DIRPOINTER *loDirectoryPointers);
int getNumberOfDirectoryBlocks(DIRPOINTER *aDirectoryPointers);
FILE *open_aesop_resource_and_set_to_first_directory_block(char *aResName,
												   const char *aMode, struct RESGlobalHeader *aHeaderPointer);

#endif
