#include "content_loader.h"

int loadSprite(sprite *spriteInst)
{

  char *spriteFileName = prepend("./sprites/", spriteInst->spriteName);
  if (access(spriteFileName, F_OK) == 0)
  {
    FILE *file = fopen(spriteFileName, "rb");
    if (file < 0)
    {
      printf("[ERROR] Couldnt find file %s\n", spriteFileName);
      return FS_FILE_ERROR;
    }
    free(spriteFileName);

    printf("Loading %s\n", spriteInst->spriteName);

    buffer *spriteFile = buffer_.new(file); // TODO: it is probably sensical to
                                            //  add the buffer to the struct to
                                            //  maintian the allocated memory
                                            //  (optionally it'd be in a global mem pool)
    // hexdump(spriteFile->data, spriteFile->size);

    if (spriteFile->readUint32(spriteFile) != 0xBEEFB055)
    {
      return FS_HEADER_ERROR;
    }
    spriteInst->formatVersion = spriteFile->readUint16(spriteFile);
    spriteInst->spriteName = spriteFile->readString(spriteFile);
    spriteInst->frameCount = spriteFile->readUint16(spriteFile);
    spriteInst->graphics = calloc(spriteInst->frameCount, sizeof(graphic *));
    spriteInst->x = spriteFile->readUint16(spriteFile);
    spriteInst->y = spriteFile->readUint16(spriteFile);

    for (int n = 0; n < spriteInst->frameCount; n++)
    {
      graphic *g = graphic_.new();
      //(graphic *)malloc(sizeof(graphic)); // due to linker issue I need ot manually allocate struct :)
      g->sectionSize = spriteFile->readUint32(spriteFile);
      g->name = spriteFile->readString(spriteFile);
      g->x = spriteFile->readUint16(spriteFile);
      g->y = spriteFile->readUint16(spriteFile);
      g->width = spriteFile->readUint16(spriteFile);
      g->height = spriteFile->readUint16(spriteFile);

      char *data = spriteFile->readString(spriteFile);
      if (g->width * g->height < strlen(data))
      {
        printf("[FATAL ERROR] graphic data oob! check width and height\n");
        return FS_PARSE_ERROR;
      }
      int bounds = (g->width * g->height) + 1;
      g->data = (char **)calloc(bounds, sizeof(char *));
      if (g->data)
      {
        for (int i = 0; i <= g->height; i++)
        {
          g->data[i] = (char *)calloc(g->width, sizeof(char *));
          memset(g->data[i], 0, g->width);
        }
      }
      for (int i = 0; i < g->height; i++)
      {
        memcpy(g->data[i], data + i * g->width, g->width);
      }

      char *mask = spriteFile->readString(spriteFile);
      if (g->width * g->height < strlen(data))
      {
        printf("[FATAL ERROR] graphic mask oob! check width and height\n");
        return FS_PARSE_ERROR;
      }
      g->mask = (char **)calloc(bounds, sizeof(char *));
      if (g->mask)
      {
        for (int i = 0; i <= g->height; i++)//memory needs 1 elemsiz extra ?
        {
          g->mask[i] = (char *)calloc(g->width, sizeof(char *));
          memset(g->mask[i], 0, g->width);
        }
      }
      for (int i = 0; i < g->height; i++)
      {
        memcpy(g->mask[i], mask + i * g->width, g->width);
      }
      spriteInst->graphics[n] = g;

      free(mask);
      free(data);
    }
    spriteFile->freeBuffer(spriteFile);
  }
  else
  {
    printf("[ERROR] Couldnt access file %s\n", spriteFileName);
    return FS_FILE_ERROR;
  }
  return FS_OK;
}
