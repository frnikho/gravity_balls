/**
* Nicolas SANS
* 2020-02-5 0:51
* src/color.c
* color
**/

#include <stdlib.h>
#include "game.h"

sfColor get_random_color()
{
    sfColor color;
    color.r = (rand() % 255);
    color.g = (rand() % 255);
    color.b = (rand() % 255);
    color.a = 255;
    return (color);
}