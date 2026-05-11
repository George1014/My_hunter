/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** highscore text display
*/
#include "my_hunter.h"

static void set_highscore_text(sfText *text, const char *label, int score)
{
    char buffer[64];
    char num[16];

    my_strcpy(buffer, label);
    my_itoa(score, num);
    my_strcat(buffer, num);
    sfText_setString(text, buffer);
}

void update_highscore_text(game_t *game)
{
    set_highscore_text(game->highscore_a_text, "Game A: ",
        game->high_score_a);
    sfText_setPosition(game->highscore_a_text,
        (sfVector2f){WINDOW_WIDTH - 300, 110});
    set_highscore_text(game->highscore_b_text, "Game B: ",
        game->high_score_b);
    sfText_setPosition(game->highscore_b_text,
        (sfVector2f){WINDOW_WIDTH - 300, 150});
}

