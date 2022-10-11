#include "ui_utils.h"

bool checkFlagAt(unsigned int flag, unsigned int bitindex)
{
    return (flag & (1 << bitindex)) != 0;
}