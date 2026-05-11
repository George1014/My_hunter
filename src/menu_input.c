/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** menu input handling
*/
#include "my_hunter.h"

static void handle_up_key(game_t *game)
{
    if (game->selected_mode > 0)
        game->selected_mode--;
}

static void handle_down_key(game_t *game)
{
    int max_mode = (game->state == STATE_PAUSED) ? 1 : 2;

    if (game->selected_mode < max_mode)
        game->selected_mode++;
}

static void handle_enter_paused(game_t *game)
{
    if (game->selected_mode == 0)
        resume_game(game);
    else
        start_pause_to_menu_transition(game);
}

static void handle_enter_menu(game_t *game)
{
    if (game->selected_mode == 2) {
        sfRenderWindow_close(game->window);
        return;
    }
    game->mode = (game->selected_mode == 0) ? MODE_A : MODE_B;
    start_game_transition(game);
}

static void handle_enter_key(game_t *game)
{
    if (game->state == STATE_PAUSED)
        handle_enter_paused(game);
    else
        handle_enter_menu(game);
}

static void handle_key_up(game_t *game, sfKeyCode key)
{
    if (key == sfKeyUp || key == sfKeyW)
        handle_up_key(game);
}

static void handle_key_down(game_t *game, sfKeyCode key)
{
    if (key == sfKeyDown || key == sfKeyS)
        handle_down_key(game);
}

static void handle_key_confirm(game_t *game, sfKeyCode key)
{
    if (key == sfKeyReturn || key == sfKeySpace)
        handle_enter_key(game);
}

void handle_menu_input(game_t *game, sfKeyCode key)
{
    handle_key_up(game, key);
    handle_key_down(game, key);
    handle_key_confirm(game, key);
}
