#include "vector.h"

// SOURCE: https://aticleworld.com/implement-vector-in-c/

int vectorTotal(vector *v)
{
    int totalCount = UNDEFINE;
    if (v)
    {
        totalCount = v->vectorList.total;
    }
    return totalCount;
}

int vectorResize(vector *v, int capacity)
{
    int status = UNDEFINE;
    if (v)
    {
        void **items = realloc(v->vectorList.items, sizeof(void *) * capacity);
        if (items)
        {
            v->vectorList.items = items;
            v->vectorList.capacity = capacity;
            status = SUCCESS;
        }
    }
    return status;
}

int vectorPushBack(vector *v, void *item)
{
    int status = UNDEFINE;
    if (v)
    {
        if (v->vectorList.capacity == v->vectorList.total)
        {
            status = vectorResize(v, v->vectorList.capacity * 2);
            if (status != UNDEFINE)
            {
                v->vectorList.items[v->vectorList.total++] = item;
            }
        }
        else
        {
            v->vectorList.items[v->vectorList.total++] = item;
            status = SUCCESS;
        }
    }
    return status;
}

int vectorSet(vector *v, int index, void *item)
{
    int status = UNDEFINE;
    if (v)
    {
        if ((index >= 0) && (index < v->vectorList.total))
        {
            v->vectorList.items[index] = item;
            status = SUCCESS;
        }
    }
    return status;
}

void *vectorGet(vector *v, int index)
{
    void *readData = NULL;
    if (v)
    {
        if ((index >= 0) && (index < v->vectorList.total))
        {
            readData = v->vectorList.items[index];
        }
    }
    return readData;
}

int vectorDelete(vector *v, int index)
{
    int status = UNDEFINE;
    int i = 0;
    if (v)
    {
        if ((index < 0) || (index >= v->vectorList.total))
            return status;
        v->vectorList.items[index] = NULL;
        for (i = index; (i < v->vectorList.total - 1); ++i)
        {
            v->vectorList.items[i] = v->vectorList.items[i + 1];
            v->vectorList.items[i + 1] = NULL;
        }
        v->vectorList.total--;
        if ((v->vectorList.total > 0) && ((v->vectorList.total) == (v->vectorList.capacity / 4)))
        {
            vectorResize(v, v->vectorList.capacity / 2);
        }
        status = SUCCESS;
    }
    return status;
}

int vectorFree(vector *v)
{
    int status = UNDEFINE;
    if (v)
    {
        free(v->vectorList.items);
        v->vectorList.items = NULL;
        status = SUCCESS;
    }
    return status;
}

static vector *new ()
{
    vector *vector_ptr = (vector *)malloc(sizeof(vector));
    *vector_ptr = (vector){.pfVectorTotal = &vectorTotal,
                           .pfVectorResize = &vectorResize,
                           .pfVectorAdd = &vectorPushBack,
                           .pfVectorSet = &vectorSet,
                           .pfVectorGet = &vectorGet,
                           .pfVectorFree = &vectorFree,
                           .pfVectorDelete = &vectorDelete,
                           .vectorList.capacity = VECTOR_INIT_CAPACITY,
                           .vectorList.total = 0,
                           .vectorList.items = malloc(sizeof(void *) * VECTOR_INIT_CAPACITY)};
    return vector_ptr;
}

const struct VectorClass sVector = {.new = &new};
