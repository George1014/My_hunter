/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** score display
*/

#include "my_hunter.h"

static void build_score_string(char *str, int score)
{
    char num[16];

    my_strcpy(str, "Score: ");
    my_itoa(score, num);
    my_strcat(str, num);
}

static void build_round_string(char *str, int round)
{
    char num[16];

    my_strcpy(str, "Round: ");
    my_itoa(round, num);
    my_strcat(str, num);
}

static void build_shots_string(char *str, game_t *game)
{
    char num[16];

    my_strcpy(str, "Shots: ");
    my_itoa(game->shots_remaining, num);
    my_strcat(str, num);
    my_strcat(str, " | Killed: ");
    my_itoa(game->vehicles_killed, num);
    my_strcat(str, num);
    my_strcat(str, "/");
    my_itoa(game->min_to_advance, num);
    my_strcat(str, num);
}

void update_score_text(game_t *game)
{
    char score_str[64];
    char round_str[64];
    char shots_str[128];

    build_score_string(score_str, game->score);
    build_round_string(round_str, game->round);
    build_shots_string(shots_str, game);
    sfText_setString(game->score_text, score_str);
    sfText_setString(game->round_text, round_str);
    sfText_setString(game->shots_text, shots_str);
}
