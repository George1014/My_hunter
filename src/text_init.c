/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** text initialization split functions
*/
#include "my_hunter.h"

static void set_text_fonts(game_t *game)
{
    if (!game->font)
        return;
    sfText_setFont(game->score_text, game->font);
    sfText_setFont(game->round_text, game->font);
    sfText_setFont(game->shots_text, game->font);
    sfText_setFont(game->game_over_text, game->font);
    sfText_setFont(game->title_text, game->font);
    sfText_setFont(game->mode_a_text, game->font);
    sfText_setFont(game->mode_b_text, game->font);
    sfText_setFont(game->exit_text, game->font);
    sfText_setFont(game->instruction_text, game->font);
    sfText_setFont(game->resume_text, game->font);
    sfText_setFont(game->quit_text, game->font);
    sfText_setFont(game->highscore_title_text, game->font);
    sfText_setFont(game->highscore_a_text, game->font);
    sfText_setFont(game->highscore_b_text, game->font);
    sfText_setFont(game->new_highscore_text, game->font);
}

static void set_text_sizes(game_t *game)
{
    sfText_setCharacterSize(game->score_text, 30);
    sfText_setCharacterSize(game->round_text, 30);
    sfText_setCharacterSize(game->shots_text, 30);
    sfText_setCharacterSize(game->game_over_text, 60);
    sfText_setCharacterSize(game->title_text, 80);
    sfText_setCharacterSize(game->mode_a_text, 50);
    sfText_setCharacterSize(game->mode_b_text, 50);
    sfText_setCharacterSize(game->exit_text, 50);
    sfText_setCharacterSize(game->instruction_text, 30);
    sfText_setCharacterSize(game->resume_text, 50);
    sfText_setCharacterSize(game->quit_text, 50);
    sfText_setCharacterSize(game->highscore_title_text, 40);
    sfText_setCharacterSize(game->highscore_a_text, 30);
    sfText_setCharacterSize(game->highscore_b_text, 30);
    sfText_setCharacterSize(game->new_highscore_text, 50);
}

static void set_game_text_content(game_t *game)
{
    sfText_setPosition(game->score_text, (sfVector2f){10, 10});
    sfText_setPosition(game->round_text, (sfVector2f){10, 50});
    sfText_setPosition(game->shots_text, (sfVector2f){10, 90});
    sfText_setString(game->game_over_text, "GAME OVER!");
    sfText_setPosition(game->game_over_text, (sfVector2f){WINDOW_WIDTH / 2 -
        200, WINDOW_HEIGHT / 2 - 50});
}

static void set_menu_text_content(game_t *game)
{
    sfText_setString(game->title_text, "MY HUNTER");
    sfText_setPosition(game->title_text, (sfVector2f){WINDOW_WIDTH / 2 - 240,
        150});
    sfText_setString(game->mode_a_text, "GAME A - One Vehicle");
    sfText_setPosition(game->mode_a_text, (sfVector2f){WINDOW_WIDTH / 2 - 250,
        300});
    sfText_setString(game->mode_b_text, "GAME B - Two Vehicles");
    sfText_setPosition(game->mode_b_text, (sfVector2f){WINDOW_WIDTH / 2 - 270,
        380});
    sfText_setString(game->exit_text, "Exit");
    sfText_setPosition(game->exit_text, (sfVector2f){WINDOW_WIDTH / 2 - 50,
        460});
    sfText_setString(game->instruction_text,
        "Use Arrow Keys or W/S to select, ENTER to start");
    sfText_setPosition(game->instruction_text, (sfVector2f){WINDOW_WIDTH / 2 -
        350, 540});
}

static void set_pause_text_content(game_t *game)
{
    sfText_setString(game->resume_text, "Resume Game");
    sfText_setPosition(game->resume_text, (sfVector2f){WINDOW_WIDTH / 2 - 160,
        300});
    sfText_setString(game->quit_text, "Main Menu");
    sfText_setPosition(game->quit_text, (sfVector2f){WINDOW_WIDTH / 2 - 130,
        380});
    sfText_setString(game->highscore_title_text, "HIGH SCORES");
    sfText_setPosition(game->highscore_title_text,
        (sfVector2f){WINDOW_WIDTH - 300, 50});
    sfText_setString(game->new_highscore_text, "NEW HIGH SCORE!");
    sfText_setPosition(game->new_highscore_text,
        (sfVector2f){WINDOW_WIDTH / 2 - 200, WINDOW_HEIGHT / 2 + 50});
}

void configure_all_text(game_t *game)
{
    set_text_fonts(game);
    set_text_sizes(game);
    set_game_text_content(game);
    set_menu_text_content(game);
    set_pause_text_content(game);
}
