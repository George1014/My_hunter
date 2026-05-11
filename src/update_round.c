/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** round management
*/
#include "my_hunter.h"

void next_round(game_t *game)
{
    game->round++;
    game->vehicles_killed = 0;
    game->vehicles_spawned = 0;
    game->shots_remaining = SHOTS_PER_VEHICLE;
    game->vehicle_speed_multiplier += 0.2f;
    game->min_to_advance = 6 + (game->round - 1) / 2;
    if (game->min_to_advance > 10)
        game->min_to_advance = 10;
    game->spawn_timer = 0;
}

void reset_round(game_t *game)
{
    game->game_over = 1;
}

static int count_alive_vehicles(game_t *game)
{
    int count = 0;

    for (int i = 0; i < MAX_VEHICLES; i++) {
        if (game->vehicles[i].alive)
            count++;
    }
    return count;
}

static void handle_spawn_timer(game_t *game, int vehicles_to_spawn)
{
    int i;

    if (game->spawn_timer < 2.0f / game->vehicle_speed_multiplier)
        return;
    if (game->vehicles_spawned >= VEHICLES_PER_ROUND)
        return;
    for (i = 0; i < vehicles_to_spawn && game->vehicles_spawned <
        VEHICLES_PER_ROUND; i++)
        spawn_vehicle(game);
    sfClock_restart(game->spawn_clock);
}

static void check_round_end(game_t *game, int alive_count)
{
    if (game->vehicles_spawned < VEHICLES_PER_ROUND)
        return;
    if (alive_count != 0)
        return;
    if (game->vehicles_killed >= game->min_to_advance) {
        game->score += 500 * game->round;
        next_round(game);
    } else {
        reset_round(game);
        check_highscore(game);
    }
}

void update_game(game_t *game, float delta_time)
{
    sfTime spawn_time;
    int alive_count;
    int vehicles_to_spawn;

    update_vehicles(game, delta_time);
    update_explosions(game, delta_time);
    spawn_time = sfClock_getElapsedTime(game->spawn_clock);
    game->spawn_timer = sfTime_asSeconds(spawn_time);
    vehicles_to_spawn = (game->mode == MODE_A) ? 1 : 2;
    handle_spawn_timer(game, vehicles_to_spawn);
    alive_count = count_alive_vehicles(game);
    check_round_end(game, alive_count);
    update_score_text(game);
}
