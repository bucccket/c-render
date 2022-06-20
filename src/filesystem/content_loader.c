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

    printf("header %08X\n",spriteFile.readUint32(&spriteFile));
    printf("version %04X\n",spriteFile.readUint16(&spriteFile));
    printf("sprite name \"%s\"\n",spriteFile.readString(&spriteFile));
    printf("frames %04X\n",spriteFile.readUint16(&spriteFile));
    printf("X Pos %04X\n",spriteFile.readUint16(&spriteFile));
    printf("Y Pos %04X\n",spriteFile.readUint16(&spriteFile));
  }else{
    printf("[ERROR] Couldnt access file %s\n", spriteFile);
    return FS_FILE_ERROR;
  }
  printf("- success\n");

  return FS_OK;
}
