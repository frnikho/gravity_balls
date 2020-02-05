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

int init(game_t *game)
{
    time_t t;
    srand((unsigned) time(&t));
    game->balls = malloc(sizeof(ball_t) * game->ball_count);
    for (int i = 0; i < game->ball_count; i++) {
        float x = (rand() % 1600);
        float y = (rand() % 800 - 50) + 50;
        sfVector2f pos = {x, y - 200};
        game->balls[i] = init_ball(pos, game->gravity, game->friction, get_random_color());
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
    int ball_count;
    if (argc > 1)
        ball_count = atoi(argv[1]);
    srand(0);
    sfVector2f window = {1600, 800};
    game_t *game = init_game("Gravity Balls", window, ball_count);
    if (argc > 2)
        game->gravity = atof(argv[2]);
    init(game);
    loop(game);
    dispose_game(game);
    return (0);
}