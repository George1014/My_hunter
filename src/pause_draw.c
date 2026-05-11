/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** pause menu drawing
*/
#include "my_hunter.h"

static void set_pause_text_colors(game_t *game, sfColor sel, sfColor txt)
{
    if (game->selected_mode == 0) {
        sfText_setFillColor(game->resume_text, sel);
        sfText_setFillColor(game->quit_text, txt);
    } else {
        sfText_setFillColor(game->resume_text, txt);
        sfText_setFillColor(game->quit_text, sel);
    }
}

static void setup_pause_title(game_t *game)
{
    sfText_setString(game->title_text, "PAUSED");
    sfText_setPosition(game->title_text,
        (sfVector2f){WINDOW_WIDTH / 2 - 150, 150});
}

static void restore_title(game_t *game)
{
    sfText_setString(game->title_text, "MY HUNTER");
    sfText_setPosition(game->title_text,
        (sfVector2f){WINDOW_WIDTH / 2 - 240, 150});
}

static void draw_background_overlay(game_t *game, sfColor bg_overlay)
{
    sfRectangleShape *overlay = sfRectangleShape_create();

    sfRectangleShape_setSize(overlay,
        (sfVector2f){WINDOW_WIDTH, WINDOW_HEIGHT});
    sfRectangleShape_setFillColor(overlay, bg_overlay);
    sfRenderWindow_drawRectangleShape(game->window, overlay, NULL);
    sfRectangleShape_destroy(overlay);
}

void draw_pause_menu(game_t *game)
{
    sfColor bg = {0, 0, 0, (sfUint8)(150 * game->menu_alpha)};
    sfColor title = {255, 215, 0, (sfUint8)(255 * game->menu_alpha)};
    sfColor sel = {255, 100, 100, (sfUint8)(255 * game->menu_alpha)};
    sfColor text = {255, 255, 255, (sfUint8)(255 * game->menu_alpha)};

    draw_background_overlay(game, bg);
    setup_pause_title(game);
    sfText_setFillColor(game->title_text, title);
    set_pause_text_colors(game, sel, text);
    sfRenderWindow_drawText(game->window, game->title_text, NULL);
    sfRenderWindow_drawText(game->window, game->resume_text, NULL);
    sfRenderWindow_drawText(game->window, game->quit_text, NULL);
    restore_title(game);
}
