#pragma once

#include "../graphics/sprite.h"
#include "../utils/stringutils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>

#define FS_OK 0
#define FS_FILE_ERROR 1
#define FS_PARSE_ERROR 2

typedef char* bytestream;

int loadSprite(sprite* spriteInst);
