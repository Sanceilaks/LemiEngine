#include "Vec2.h"

float Vec2::operator[](int right)
{
    if (right == 0)
        return x;
    else if (right == 1)
        return y;
}
