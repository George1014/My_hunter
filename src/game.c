/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** main game loop
*/
#include "my_hunter.h"

static state_handler_t get_state_handler(game_state_t state)
{
    if (state == STATE_MENU)
        return handle_menu_state;
    if (state == STATE_TRANSITION)
        return handle_transition_state;
    if (state == STATE_PAUSED)
        return handle_paused_state;
    if (state == STATE_PAUSE_TO_MENU)
        return handle_pause_to_menu_state;
    return handle_playing_state;
}

void game_loop(game_t *game)
{
    sfTime time;
    float delta_time;
    state_handler_t handler;

    while (sfRenderWindow_isOpen(game->window)) {
        time = sfClock_restart(game->clock);
        delta_time = sfTime_asSeconds(time);
        handle_events(game);
        handler = get_state_handler(game->state);
        handler(game, delta_time);
    }
}
