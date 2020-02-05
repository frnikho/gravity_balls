/**
* Nicolas SANS
* 2020-02-5 14:15
* src/ball_collision.c
* ball_collision
**/

#include <math.h>
#include "ball.h"

float get_ball_distance(ball_t *b1, ball_t *b2)
{
    float dx = b2->position.x - b1->position.x;
    float dy = b2->position.y - b1->position.y;
    return hypot(dx, dy);
}

int check_collision(ball_t **balls, int count, ball_t *b1)
{
    for (int i = 0; i < count; i++) {
        if (balls[i] != b1 && get_ball_distance(balls[i], b1) < 40) {
            sfCircleShape_setFillColor(balls[i]->shape, sfWhite);
        }
    }
}