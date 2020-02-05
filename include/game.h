/**
* Nicolas SANS
* 2020-02-4 23:04
* include/gravity.h
* gravity.h
**/

#ifndef GRAVITY_BALLS_GRAVITY_H
#define GRAVITY_BALLS_GRAVITY_H

#include <SFML/Graphics.h>
#include "ball.h"

typedef struct game_s {
    sfRenderWindow *window;
    sfVector2f info;
    sfEvent event;
    int ball_count;
    float gravity;
    float friction;
    ball_t **balls;
} game_t;

game_t *init_game(char const *title, sfVector2f win, int ball_count);
void dispose_game(game_t *game);
sfColor get_random_color();

#endif
