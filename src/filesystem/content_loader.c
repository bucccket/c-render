#include "content_loader.h"

int loadSprite(sprite* spriteInst){

  const char* spriteFile = prepend("./sprites/",spriteInst->spriteName);
  if(access(spriteFile, F_OK) == 0){
    FILE *file = fopen(spriteFile,"rb");
    if(file<0){
      printf("[ERROR] Couldnt find file %s\n", spriteFile);
      return FS_FILE_ERROR;
    }

    printf("Loading %s ",spriteInst->spriteName);

    buffer spriteFile = buffer_.new(file);
    hexdump (spriteFile.data, spriteFile.size);

    int header = spriteFile.readUint32(&spriteFile);
    printf("header %08X check %s\n",header,header==0xBEEFB055?"ok":"failed. exiting");
    if(header!=0xBEEFB055){
      return FS_HEADER_ERROR;
    }
    spriteInst->formatVersion = spriteFile.readUint16(&spriteFile);
    spriteInst->spriteName = spriteFile.readString(&spriteFile);
    spriteInst->frameCount = spriteFile.readUint16(&spriteFile);
    spriteInst->x=spriteFile.readUint16(&spriteFile);
    spriteInst->y=spriteFile.readUint16(&spriteFile);

    for(int n=0;n<spriteInst->frameCount;n++){
      graphic g = (graphic){};
      g.sectionSize = spriteFile.readUint32(&spriteFile);
      g.name = spriteFile.readString(&spriteFile);
      g.x = spriteFile.readUint16(&spriteFile);
      g.y = spriteFile.readUint16(&spriteFile);
      g.width = spriteFile.readUint16(&spriteFile);
      g.height = spriteFile.readUint16(&spriteFile);
      const char* asciiArt = spriteFile.readString(&spriteFile);
      if(g.width*g.height<strlen(asciiArt)){
        printf("[FATAL ERROR] graphic data oob! check width and height\n");
        return FS_PARSE_ERROR;
      }
      g.data = (char**) calloc(g.width*g.height, sizeof(char*));
      if(g.data)
      {
        for(int i = 0; i < g.width*g.height; i++)
        {
            g.data[i] = (char*)calloc(g.width*g.height, sizeof(char));
            memset(g.data[i], 0, sizeof(*g.data[i] * g.width*g.height-1));
        }
      }
      for(int i=0;i<g.height;i++){
        sprintf(g.data[i],"%.*s",g.width,asciiArt+(g.width*i));
      }
      spriteInst->graphics[n] = &g;
    }
    printf("checking graphic name g3: %s\n",spriteInst->graphics[spriteInst->frameCount-1]->name);
  }else{
    printf("[ERROR] Couldnt access file %s\n", spriteFile);
    return FS_FILE_ERROR;
  }
  return FS_OK;
}
