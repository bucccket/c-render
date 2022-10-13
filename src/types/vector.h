#pragma once

#include <stdio.h>
#include <stdlib.h>

#define VECTOR_INIT_CAPACITY 6
#define UNDEFINE  -1
#define SUCCESS 0

typedef struct sVectorList
{
    void **items;
    int capacity;
    int total;
} sVectorList;

typedef struct sVector{
    sVectorList vectorList;
//function pointers
    int (*pfVectorTotal)(struct sVector *);
    int (*pfVectorResize)(struct sVector *, int);
    int (*pfVectorAdd)(struct sVector *, void *);
    int (*pfVectorSet)(struct sVector *, int, void *);
    void *(*pfVectorGet)(struct sVector *, int);
    int (*pfVectorDelete)(struct sVector *, int);
    int (*pfVectorFree)(struct sVector *);
}vector;

extern const struct VectorClass
{
  vector *(*new)(void);
} sVector;
