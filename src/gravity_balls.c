/**
* Nicolas SANS
* 2020-02-4 22:44
* src/gravity_balls.c
* gravity_balls
**/

#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "game.h"

int init(game_t *g)
{
    time_t t;
    srand((unsigned) time(&t));
    g->balls = malloc(sizeof(ball_t) * g->ball_count);
    for (int i = 0; i < g->ball_count; i++) {
        float x = (rand() % 1600);
        float y = (rand() % 800 - 50) + 50;
        float dy = (rand() % 1) + 2;
        float dx = (rand() % 6) - 3;
        sfVector2f p = {x, y - 200};
        sfVector2f d_pos = {dx, dy};
        g->balls[i] = init_ball(p, g->gravity, g->friction, get_random_color());
        set_delta_ball_position(g->balls[i], d_pos);
    }
}

int input(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
}

void render(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    for (int i = 0; i < game->ball_count; i++) {
        check_collision(game->balls, game->ball_count, game->balls[i]);
        draw_ball(game->balls[i], game->window);
    }
    sfRenderWindow_display(game->window);
}

int loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        input(game);
        render(game);
    }
}

int main(int argc, char **argv)
{
    srand(0);
    sfVector2f window = {1600, 800};
    game_t *game = init_game("Gravity Balls", window, 1);
    if (argc > 1)
        game->ball_count = atof(argv[1]);
    if (argc > 2)
        game->gravity = atof(argv[2]);
    if (argc > 3)
        game->friction = atof(argv[3]);
    init(game);
    loop(game);
    dispose_game(game);
    return (0);
}