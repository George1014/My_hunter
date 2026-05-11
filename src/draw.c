/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** drawing and rendering
*/
#include "my_hunter.h"

static void draw_vehicles(game_t *game)
{
    int i;

    for (i = 0; i < MAX_VEHICLES; i++) {
        if (game->vehicles[i].alive)
            sfRenderWindow_drawSprite(game->window, game->vehicles[i].sprite,
                NULL);
    }
}

static void draw_explosions(game_t *game)
{
    int i;

    for (i = 0; i < MAX_VEHICLES; i++) {
        if (game->explosions[i].active)
            sfRenderWindow_drawSprite(game->window, game->explosions[i].sprite,
                NULL);
    }
}

static void draw_game_texts(game_t *game)
{
    sfRenderWindow_drawText(game->window, game->score_text, NULL);
    sfRenderWindow_drawText(game->window, game->round_text, NULL);
    sfRenderWindow_drawText(game->window, game->shots_text, NULL);
}

static void draw_game_over(game_t *game)
{
    if (!game->game_over)
        return;
    sfRenderWindow_drawText(game->window, game->game_over_text, NULL);
    if (!game->new_high_score)
        return;
    sfText_setFillColor(game->new_highscore_text, (sfColor){255, 215, 0, 255});
    sfRenderWindow_drawText(game->window, game->new_highscore_text, NULL);
}

static void draw_crosshair(game_t *game)
{
    sfVector2i mouse_pos;
    sfVector2f crosshair_pos;

    if (game->state != STATE_PLAYING)
        return;
    mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    crosshair_pos.x = mouse_pos.x;
    crosshair_pos.y = mouse_pos.y;
    sfSprite_setPosition(game->crosshair_sprite, crosshair_pos);
    sfRenderWindow_drawSprite(game->window, game->crosshair_sprite, NULL);
}

void draw_game(game_t *game)
{
    sfRenderWindow_clear(game->window, (sfColor){0, 0, 0, 255});
    sfRenderWindow_drawSprite(game->window, game->bg_sprite, NULL);
    draw_vehicles(game);
    draw_explosions(game);
    draw_game_texts(game);
    draw_game_over(game);
    draw_crosshair(game);
}
