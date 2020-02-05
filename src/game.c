/**
* Nicolas SANS
* 2020-02-4 23:05
* src/game.c
* game
**/

#include <stdlib.h>
#include "game.h"

game_t *init_game(char const *title, sfVector2f win, int ball_count)
{
    game_t *game = malloc(sizeof(game_t));
    if (!game)
        return (0);
    sfVideoMode mode = {win.x, win.y};
    if (ball_count < 0) {
        game->ball_count = 1;
    } else {
        game->ball_count = ball_count;
    }
    game->info = win;
    game->gravity = 1;
    game->friction = 0.72;
    game->window = sfRenderWindow_create(mode, title, sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    return (game);
}

void dispose_game(game_t *game)
{
    sfRenderWindow_destroy(game->window);
}