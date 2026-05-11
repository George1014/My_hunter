/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** menu system
*/
#include "my_hunter.h"

void update_menu(game_t *game, float delta_time)
{
    if (game->state != STATE_PAUSED)
        return;
    game->menu_alpha += delta_time * 2.0f;
    if (game->menu_alpha > 1.0f)
        game->menu_alpha = 1.0f;
}

void pause_game(game_t *game)
{
    game->state = STATE_PAUSED;
    game->menu_alpha = 0;
    game->selected_mode = 0;
}

void resume_game(game_t *game)
{
    game->state = STATE_PLAYING;
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
}

void reset_game_state(game_t *game)
{
    int i;

    game->score = 0;
    game->round = 1;
    game->vehicles_killed = 0;
    game->shots_remaining = SHOTS_PER_VEHICLE;
    game->vehicles_spawned = 0;
    game->min_to_advance = 6;
    game->game_over = 0;
    game->spawn_timer = 0;
    game->vehicle_speed_multiplier = 1.0f;
    game->new_high_score = 0;
    for (i = 0; i < MAX_VEHICLES; i++) {
        game->vehicles[i].alive = 0;
        game->explosions[i].active = 0;
    }
    update_score_text(game);
}
