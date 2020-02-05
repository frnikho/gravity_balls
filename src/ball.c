/**
* Nicolas SANS
* 2020-02-4 23:29
* src/ball.c
* ball
**/

#include <stdlib.h>
#include "ball.h"

ball_t *init_ball(sfVector2f pos, float gravity, float friction, sfColor color)
{
    ball_t *ball = malloc(sizeof(ball_t));
    sfVector2f d_pos = {0, 5};
    ball->position = pos;
    ball->d_pos = d_pos;
    ball->gravity = gravity;
    ball->friction = friction;
    ball->shape = sfCircleShape_create();
    sfCircleShape_setPosition(ball->shape, pos);
    sfCircleShape_setRadius(ball->shape, 20);
    sfCircleShape_setFillColor(ball->shape, color);
    return (ball);
}

void add_ball_position(ball_t *ball, sfVector2f pos)
{
    sfVector2f current_pos = sfCircleShape_getPosition(ball->shape);
    sfVector2f new_pos = {pos.x + current_pos.x, pos.y + current_pos.y};
    ball->position = new_pos;
    sfCircleShape_setPosition(ball->shape, new_pos);
}

static void update(ball_t *ball)
{
    float radius = sfCircleShape_getRadius(ball->shape);
    float x = ball->position.x;
    float y = ball->position.y;
    float dy = ball->d_pos.y;

    if (y + radius + dy > 800) {
        ball->d_pos.y = -dy * ball->friction;
    } else {
        ball->d_pos.y += ball->gravity;
    }
    add_ball_position(ball, ball->d_pos);
}

void draw_ball(ball_t *ball, sfRenderWindow *window)
{
    update(ball);
    sfRenderWindow_drawCircleShape(window, ball->shape, 0);
}