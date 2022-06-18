#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* prepend(const char* prepended, const char* source);
void hexdump(char* data, size_t size);
