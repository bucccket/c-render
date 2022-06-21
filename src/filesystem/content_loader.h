#pragma once

#include "../graphics/sprite.h"
#include "../utils/stringutils.h"
#include "buffered_reader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>

#define FS_OK 0
#define FS_FILE_ERROR 1
#define FS_PARSE_ERROR 2

#define ARR_WIDTH(x)  (sizeof(x) / sizeof((x)[0]))
#define ARR_HEIGHT(x) sizeof(x[0])/sizeof(x[0][0]);

int loadSprite(sprite *spriteInst);
