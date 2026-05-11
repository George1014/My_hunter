/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** text object initialization
*/
#include "my_hunter.h"

static int create_all_text_objects(game_t *game)
{
    game->score_text = sfText_create();
    game->round_text = sfText_create();
    game->shots_text = sfText_create();
    game->game_over_text = sfText_create();
    game->title_text = sfText_create();
    game->mode_a_text = sfText_create();
    game->mode_b_text = sfText_create();
    game->exit_text = sfText_create();
    game->instruction_text = sfText_create();
    game->resume_text = sfText_create();
    game->quit_text = sfText_create();
    game->highscore_title_text = sfText_create();
    game->highscore_a_text = sfText_create();
    game->highscore_b_text = sfText_create();
    game->new_highscore_text = sfText_create();
    return 0;
}

static int check_all_text_objects(game_t *game)
{
    if (!game->score_text || !game->round_text || !game->shots_text)
        return 84;
    if (!game->game_over_text || !game->title_text || !game->mode_a_text)
        return 84;
    if (!game->mode_b_text || !game->exit_text || !game->instruction_text)
        return 84;
    if (!game->resume_text || !game->quit_text)
        return 84;
    if (!game->highscore_title_text || !game->highscore_a_text)
        return 84;
    if (!game->highscore_b_text || !game->new_highscore_text)
        return 84;
    return 0;
}

int init_text(game_t *game)
{
    game->font = sfFont_createFromFile("/System/Library/Fonts/Helvetica.ttc");
    if (!game->font)
        game->font = sfFont_createFromFile(
            "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");
    create_all_text_objects(game);
    if (check_all_text_objects(game) == 84)
        return 84;
    configure_all_text(game);
    return 0;
}
