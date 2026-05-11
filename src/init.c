/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** game initialization
*/
#include "my_hunter.h"

static int init_window(game_t *game)
{
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};

    game->window = sfRenderWindow_create(mode, "My Hunter - Space Shooter",
        sfResize | sfClose, NULL);
    if (!game->window)
        return 84;
    sfRenderWindow_setFramerateLimit(game->window, 60);
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    return 0;
}

int init_game(game_t *game)
{
    if (init_window(game) == 84)
        return 84;
    if (init_textures(game) == 84)
        return 84;
    if (init_sprites(game) == 84)
        return 84;
    if (init_text(game) == 84)
        return 84;
    game->clock = sfClock_create();
    game->spawn_clock = sfClock_create();
    game->transition_clock = sfClock_create();
    init_sounds(game);
    init_music(game);
    init_game_state(game);
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    load_highscores(game);
    update_highscore_text(game);
    return 0;
}
