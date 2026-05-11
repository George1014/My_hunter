/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** game state handlers
*/
#include "my_hunter.h"

static void draw_pause_to_menu_state(game_t *game)
{
    sfRectangleShape *overlay;
    float saved_alpha;

    overlay = sfRectangleShape_create();
    sfRectangleShape_setSize(overlay, (sfVector2f){WINDOW_WIDTH,
        WINDOW_HEIGHT});
    sfRectangleShape_setFillColor(overlay, (sfColor){0, 0, 0, 150});
    sfRenderWindow_drawRectangleShape(game->window, overlay, NULL);
    sfRectangleShape_destroy(overlay);
    saved_alpha = game->menu_alpha;
    if (game->transition_timer < MENU_FADE_DURATION * 0.5f)
        draw_pause_menu(game);
    else {
        game->menu_alpha = 1.0f;
        draw_menu(game);
        game->menu_alpha = saved_alpha;
    }
}

void handle_pause_to_menu_state(game_t *game, float delta_time)
{
    update_pause_to_menu(game, delta_time);
    sfRenderWindow_clear(game->window, (sfColor){0, 0, 0, 255});
    draw_game(game);
    draw_pause_to_menu_state(game);
    sfRenderWindow_display(game->window);
}

void handle_menu_state(game_t *game, float delta_time)
{
    update_menu(game, delta_time);
    sfRenderWindow_clear(game->window, (sfColor){0, 0, 0, 255});
    draw_menu(game);
    sfRenderWindow_display(game->window);
}

void handle_transition_state(game_t *game, float delta_time)
{
    update_transition(game, delta_time);
    sfRenderWindow_clear(game->window, (sfColor){0, 0, 0, 255});
    draw_menu(game);
    sfRenderWindow_display(game->window);
}

void handle_paused_state(game_t *game, float delta_time)
{
    update_menu(game, delta_time);
    sfRenderWindow_clear(game->window, (sfColor){0, 0, 0, 255});
    draw_game(game);
    draw_pause_menu(game);
    sfRenderWindow_display(game->window);
}

void handle_playing_state(game_t *game, float delta_time)
{
    if (!game->game_over)
        update_game(game, delta_time);
    sfRenderWindow_clear(game->window, (sfColor){0, 0, 0, 255});
    draw_game(game);
    sfRenderWindow_display(game->window);
}
