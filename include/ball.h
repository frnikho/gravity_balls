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
    float mass;
    sfCircleShape *shape;
} ball_t;

ball_t *init_ball(sfVector2f pos, float gravity, float friction, sfColor color);
void draw_ball(ball_t *ball, sfRenderWindow *window);
void set_delta_ball_position(ball_t *ball, sfVector2f pos);
float get_ball_distance(ball_t *b1, ball_t *b2);
int check_collision(ball_t **balls, int count, ball_t *b1);

#endif
