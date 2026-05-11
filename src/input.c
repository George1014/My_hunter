/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** input handling
*/
#include "my_hunter.h"

static void handle_miss(game_t *game)
{
    int i;

    game->shots_remaining--;
    if (game->shots_remaining > 0)
        return;
    for (i = 0; i < MAX_VEHICLES; i++) {
        if (game->vehicles[i].alive)
            game->vehicles[i].alive = 0;
    }
    game->shots_remaining = SHOTS_PER_VEHICLE;
}

static int try_hit_vehicle(game_t *game, sfVector2f mouse_pos)
{
    int i;

    for (i = 0; i < MAX_VEHICLES; i++) {
        if (!game->vehicles[i].alive)
            continue;
        if (check_vehicle_collision(&game->vehicles[i], mouse_pos)) {
            kill_vehicle(game, i, mouse_pos);
            return 1;
        }
    }
    return 0;
}

void handle_mouse_click(game_t *game, sfMouseButtonEvent event)
{
    sfVector2f mouse_pos = {event.x, event.y};
    int hit;

    if (game->game_over)
        return;
    if (game->shoot_sound)
        sfSound_play(game->shoot_sound);
    hit = try_hit_vehicle(game, mouse_pos);
    if (!hit)
        handle_miss(game);
    update_score_text(game);
}

static void handle_escape_key(game_t *game)
{
    if (game->state == STATE_PLAYING)
        pause_game(game);
    else if (game->state == STATE_PAUSED)
        resume_game(game);
    else
        sfRenderWindow_close(game->window);
}

static void handle_key_press(game_t *game, sfKeyCode key)
{
    if (key == sfKeyEscape)
        handle_escape_key(game);
    if (game->state == STATE_MENU || game->state == STATE_PAUSED)
        handle_menu_input(game, key);
}

static void handle_mouse_press(game_t *game, sfMouseButtonEvent event)
{
    if (game->state != STATE_PLAYING)
        return;
    if (event.button != sfMouseLeft)
        return;
    handle_mouse_click(game, event);
}

void handle_events(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (event.type == sfEvtKeyPressed)
            handle_key_press(game, event.key.code);
        if (event.type == sfEvtMouseButtonPressed)
            handle_mouse_press(game, event.mouseButton);
    }
}
