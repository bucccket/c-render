#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../filesystem/buffered_reader.h"

char* prepend(const char* prepended, const char* source);
void hexdump(bytestream data, size_t size);
void print2dString(char **data,int lines);
