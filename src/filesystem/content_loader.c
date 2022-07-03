#include "content_loader.h"

int loadSprite(sprite *spriteInst)
{

  char *spriteFileName = prepend("./sprites/", spriteInst->spriteName);
  if (access(spriteFileName, F_OK) != 0)
  {
    fprintf(stderr, "[ERROR] Couldnt access file %s\n", spriteFileName);
    free(spriteFileName);
    return FS_FILE_ERROR;
  }
  else
  {
    FILE *file = fopen(spriteFileName, "rb");
    if (file < 0)
    {
      fprintf(stderr, "[ERROR] Couldnt find file %s\n", spriteFileName);
      free(spriteFileName);
      fclose(file);
      return FS_FILE_ERROR;
    }
    free(spriteFileName);

    printf("Loading %s\n", spriteInst->spriteName);

    buffer *spriteFile = buffer_.new(file);
    if (!spriteFile->data)
    {
      fprintf(stderr, "[ERROR] Couldnt load file %s\n", spriteInst->spriteName);
      spriteFile->freeBuffer(spriteFile);
      return FS_FILE_ERROR;
    }
    //hexdump(spriteFile->data, spriteFile->size);    

    printf("buffer offs at 0x%08X\n",spriteFile->offset);

    spriteInst->formatVersion = spriteFile->readUint16(spriteFile);
    char *name = spriteFile->readString(spriteFile);
    free(spriteInst->spriteName);
    spriteInst->spriteName = name;
    spriteInst->frameCount = spriteFile->readUint16(spriteFile);
    spriteInst->graphics = calloc(spriteInst->frameCount, sizeof(graphic *));
    spriteInst->x = spriteFile->readUint16(spriteFile);
    spriteInst->y = spriteFile->readUint16(spriteFile);

    for (int n = 0; n < spriteInst->frameCount; n++)
    {
      graphic *g = graphic_.new();
      spriteInst->graphics[n] = g; // shove the pointer in right away. Doesn't matter what happens we need to clean it
      int parseErr = parseGraphic(g, spriteFile);
      if (parseErr != FS_OK)
      {
        spriteFile->freeBuffer(spriteFile);
        return parseErr;
      }
    }
    spriteFile->freeBuffer(spriteFile);
  }
  spriteInst->loaded = 1;
  return FS_OK;
}

int parseGraphic(graphic *g, buffer *spriteFile)
{
  g->sectionSize = spriteFile->readUint32(spriteFile);
  g->name = spriteFile->readString(spriteFile);
  g->x = spriteFile->readUint16(spriteFile);
  g->y = spriteFile->readUint16(spriteFile);
  g->width = spriteFile->readUint16(spriteFile);
  g->height = spriteFile->readUint16(spriteFile);

  if(g->width <= 0 || g->height <= 0){
    fprintf(stderr, "[ERROR] invalid width and height w%d h%d\n", spriteFile->offset, g->width, g->height);
    return FS_PARSE_ERROR;
  }

  printf("ofs 0x%08X w %d h %d\n", spriteFile->offset, g->width, g->height);
  char *data = spriteFile->readString(spriteFile);
  if (g->width * g->height < strlen(data))
  {
    fprintf(stderr, "[ERROR] graphic data oob! check width and height\noffs %8x w%d h%d\n", spriteFile->offset, g->width, g->height);
    free(data);
    return FS_PARSE_ERROR;
  }
  int bounds = (g->width * g->height) + g->height;

  g->data = (char **)calloc(bounds, sizeof(char *));
  if (g->data)
  {
    for (int i = 0; i <= g->height; i++)
    {
      g->data[i] = (char *)calloc(g->width + 1, sizeof(char));
    }
  }
  for (int i = 0; i < g->height; i++)
  {
    memcpy(g->data[i], data + i * g->width + 1, g->width);
  }

  char *mask = spriteFile->readString(spriteFile);
  if (g->width * g->height < strlen(data))
  {
    fprintf(stderr, "[ERROR] graphic mask oob! check width and height\n");
    free(data);
    free(mask);
    return FS_PARSE_ERROR;
  }

  g->mask = (char **)calloc(bounds, sizeof(char *));
  if (g->mask)
  {
    for (int i = 0; i <= g->height; i++) // memory needs 1 elemsiz extra ?
    {
      g->mask[i] = (char *)calloc(g->width + 1, sizeof(char));
    }
  }
  for (int i = 0; i < g->height; i++)
  {
    memcpy(g->mask[i], mask + i * g->width, g->width);
  }

  printf("data ptr %p gdata %p gdata[0] %p\n", data, g->data, g->data[0]);
  printf("mask ptr %p gmask %p gmask[0] %p\n", mask, g->mask, g->mask[0]);

  free(mask);
  free(data);
  return 0;
}
