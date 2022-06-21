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

    printf("---------\n");
    printf("section size:%d\nGraphic %s\n",spriteFile.readUint32(&spriteFile),spriteFile.readString(&spriteFile));
    printf("x: %d\t\ty: %d\n",spriteFile.readUint16(&spriteFile),spriteFile.readUint16(&spriteFile));
    int width = spriteFile.readUint16(&spriteFile);
    int height = spriteFile.readUint16(&spriteFile);
    printf("width: %d\theight: %d\n",width,height);
    const char* asciiArt = spriteFile.readString(&spriteFile);
    if(width*height<strlen(asciiArt)){
      printf("[FATAL ERROR] graphic data oob! check width and height\n");
      return FS_PARSE_ERROR;
    }
    for(int i=0;i<height;i++){
      printf("%.*s\n",width,asciiArt+(width*i));
    }

  }else{
    printf("[ERROR] Couldnt access file %s\n", spriteFile);
    return FS_FILE_ERROR;
  }
  return FS_OK;
}
