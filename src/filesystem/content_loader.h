#pragma once

#include "../graphics/sprite.h"
#include "../graphics/graphic.h"
#include "../utils/stringutils.h"
#include "buffered_reader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define FS_OK 0
#define FS_FILE_ERROR 1
#define FS_HEADER_ERROR 2
#define FS_PARSE_ERROR 3

int loadSprite(sprite *spriteInst);
int parseGraphic(graphic *g, buffer* spriteFile);
