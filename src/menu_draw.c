/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** menu drawing functions
*/
#include "my_hunter.h"

static void set_menu_colors_mode0(game_t *game, sfColor s, sfColor t)
{
    sfText_setFillColor(game->mode_a_text, s);
    sfText_setFillColor(game->mode_b_text, t);
    sfText_setFillColor(game->exit_text, t);
}

static void set_menu_colors_mode1(game_t *game, sfColor s, sfColor t)
{
    sfText_setFillColor(game->mode_a_text, t);
    sfText_setFillColor(game->mode_b_text, s);
    sfText_setFillColor(game->exit_text, t);
}

static void set_menu_colors_mode2(game_t *game, sfColor s, sfColor t)
{
    sfText_setFillColor(game->mode_a_text, t);
    sfText_setFillColor(game->mode_b_text, t);
    sfText_setFillColor(game->exit_text, s);
}

static void set_menu_text_colors(game_t *game, sfColor s, sfColor t)
{
    if (game->selected_mode == 0)
        set_menu_colors_mode0(game, s, t);
    else if (game->selected_mode == 1)
        set_menu_colors_mode1(game, s, t);
    else
        set_menu_colors_mode2(game, s, t);
}

static void draw_background_overlay(game_t *game, sfColor bg_overlay)
{
    sfRectangleShape *overlay = sfRectangleShape_create();

    sfRectangleShape_setSize(overlay,
        (sfVector2f){WINDOW_WIDTH, WINDOW_HEIGHT});
    sfRectangleShape_setFillColor(overlay, bg_overlay);
    sfRenderWindow_drawSprite(game->window, game->bg_sprite, NULL);
    sfRenderWindow_drawRectangleShape(game->window, overlay, NULL);
    sfRectangleShape_destroy(overlay);
}

static void draw_menu_texts(game_t *game)
{
    sfRenderWindow_drawText(game->window, game->title_text, NULL);
    sfRenderWindow_drawText(game->window, game->mode_a_text, NULL);
    sfRenderWindow_drawText(game->window, game->mode_b_text, NULL);
    sfRenderWindow_drawText(game->window, game->exit_text, NULL);
    sfRenderWindow_drawText(game->window, game->instruction_text, NULL);
}

static void draw_highscore_texts(game_t *game)
{
    sfRenderWindow_drawText(game->window, game->highscore_title_text,
        NULL);
    sfRenderWindow_drawText(game->window, game->highscore_a_text, NULL);
    sfRenderWindow_drawText(game->window, game->highscore_b_text, NULL);
}

void draw_menu(game_t *game)
{
    sfColor bg = {0, 0, 0, (sfUint8)(150 * game->menu_alpha)};
    sfColor title = {255, 215, 0, (sfUint8)(255 * game->menu_alpha)};
    sfColor text = {255, 255, 255, (sfUint8)(255 * game->menu_alpha)};
    sfColor sel = {255, 100, 100, (sfUint8)(255 * game->menu_alpha)};

    draw_background_overlay(game, bg);
    sfText_setFillColor(game->title_text, title);
    sfText_setFillColor(game->instruction_text, text);
    set_menu_text_colors(game, sel, text);
    draw_menu_texts(game);
    sfText_setFillColor(game->highscore_title_text, title);
    sfText_setFillColor(game->highscore_a_text, text);
    sfText_setFillColor(game->highscore_b_text, text);
    draw_highscore_texts(game);
}
