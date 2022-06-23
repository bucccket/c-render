#include "stringutils.h"

char* prepend(const char* prepended, const char* source){
  char *res = malloc(strlen(prepended)+strlen(source)+1);
  strcpy(res,prepended);
  strcat(res,source);
  return res;
}

void hexdump(bytestream data, size_t size){
  //hex dump
  printf("\n\033[1;36moffset    \033[1;34m00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n00000000\033[0m  ");
  for(int i = 1; i<=size; i++){
    //8 char padding string
    char* padding = (char*)malloc(8);
    memset(padding, '0', 8); //fill all places with character 0
    //allocate 8 bytes to side bar (matches padding)
    char* sideBar = (char*)malloc(8); //max digits -> padding
    sprintf(sideBar,"%x",i); // write line # in bar
    int len = strlen(sideBar); //get num of digits (could do logarithmically)
    memmove(padding+(8-len), sideBar, len); //write sidebar number over padding
    free(sideBar); //premature free of sidebar buffer to keep memory regions clean
    const char* highlight = "\033[1;33m";
    const char* normal = "\033[0m";
    const char* none = "";
    printf("%s%02X%s ",(i<=4?highlight:none),data[i-1],(i<=4?normal:none)); // with 2x per hex write numbers
    if(i%16==0){ //newline on every hexadecimal
      printf("\n\033[1;34m%s\033[0m  ",padding);
    }
    free(padding);
  }
  printf("\n");
}

void print2dString(char **data,int lines){
  for(int i=0;i<lines;i++){
    printf("%s\n",data[i]);
  }
}
