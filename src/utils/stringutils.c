#include "stringutils.h"

char* prepend(const char* prepended, const char* source){
  char *res = malloc(strlen(prepended)+strlen(source)+1);
  strcpy(res,prepended);
  strcat(res,source);
  return res;
}
