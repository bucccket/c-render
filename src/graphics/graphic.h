#pragma once

typedef struct graphic_{
  int sectionSize; //size itself is NOT part of size measurement :]
  const char* name;
  //TODO: animation based fags like : has matrix, has move, has offset?
  short x,y;
  short width, height;
  const char *data;
}graphic;

extern const struct GraphicClass {
	graphic (*new)(const char* graphicName);
} graphic_;