/**
* Nicolas SANS
* 2020-02-4 23:27
* include/ball.h
* ball.h
**/

#ifndef GRAVITY_BALLS_BALL_H
#define GRAVITY_BALLS_BALL_H

#include <SFML/Graphics.h>

typedef struct ball_s {
    sfVector2f position;
    sfVector2f d_pos;
    float gravity;
    float friction;
    sfCircleShape *shape;
} ball_t;

ball_t *init_ball(sfVector2f pos, float gravity, float friction, sfColor color);
void draw_ball(ball_t *ball, sfRenderWindow *window);

#endif
