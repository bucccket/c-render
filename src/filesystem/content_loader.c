#include "content_loader.h"

char* readFile(FILE* f);

int loadSprite(sprite* spriteInst){

  const char* spriteFile = prepend("./sprites/",spriteInst->spriteName);
  if(access(spriteFile, F_OK) == 0){
    FILE *file = fopen(spriteFile,"rb");
    if(file<0){
      printf("[ERROR] Couldnt find file %s\n", spriteFile);
      return FS_FILE_ERROR;
    }

    printf("Loading %s ",spriteInst->spriteName);

    buffer spriteFile = buffer_.new(readFile(file));
    hexdump (spriteFile.data, spriteFile.size);
    spriteFile.readUint8(&spriteFile);

  }else{
    printf("[ERROR] Couldnt access file %s\n", spriteFile);
    return FS_FILE_ERROR;
  }
  printf("- success\n");

  return FS_OK;
}

char* readFile(FILE* f){

  //getting file size by iterating file.
   if(fseeko(f,0,SEEK_END)!=0){
      printf("reading error SEEK_END\n");
      return NULL;
   }
   off_t size = ftello(f);
   if(fseeko(f,0,SEEK_SET) != 0){
      printf("reading error SEEK_SET\n");
      return NULL;
   }

   //rewind  file offset
   rewind(f);
   char* data = (char*)malloc(size*sizeof(char));
   if(!data){
      printf("malloc error.\n");
      return NULL;
   }
   fread(data,size,1,f);
   fclose(f);
   return data;
}
