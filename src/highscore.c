/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** highscore system
*/

#include "my_hunter.h"
#include <fcntl.h>
#include <unistd.h>

static int my_atoi(const char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        i++;
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result * sign;
}

static int find_space_position(char *buffer)
{
    int i = 0;

    while (buffer[i] && buffer[i] != ' ' && buffer[i] != '\n')
        i++;
    if (buffer[i] == ' ')
        return i;
    return -1;
}

static void parse_scores(game_t *game, char *buffer, int space_pos)
{
    if (space_pos != -1) {
        buffer[space_pos] = '\0';
        game->high_score_a = my_atoi(buffer);
        game->high_score_b = my_atoi(buffer + space_pos + 1);
    } else {
        game->high_score_a = my_atoi(buffer);
        game->high_score_b = 0;
    }
}

static void reset_scores(game_t *game)
{
    game->high_score_a = 0;
    game->high_score_b = 0;
}

static int read_score_file(int fd, char *buffer)
{
    int bytes_read;

    bytes_read = read(fd, buffer, 63);
    close(fd);
    if (bytes_read <= 0)
        return -1;
    buffer[bytes_read] = '\0';
    return 0;
}

void load_highscores(game_t *game)
{
    int fd;
    char buffer[64];
    int space_pos;

    fd = open("highscores.txt", O_RDONLY);
    if (fd == -1) {
        reset_scores(game);
        return;
    }
    if (read_score_file(fd, buffer) == -1) {
        reset_scores(game);
        return;
    }
    space_pos = find_space_position(buffer);
    parse_scores(game, buffer, space_pos);
}

static void build_score_buffer(game_t *game, char *buffer)
{
    char num1[16];
    char num2[16];

    my_itoa(game->high_score_a, num1);
    my_itoa(game->high_score_b, num2);
    my_strcpy(buffer, num1);
    my_strcat(buffer, " ");
    my_strcat(buffer, num2);
    my_strcat(buffer, "\n");
}

void save_highscores(game_t *game)
{
    int fd;
    char buffer[64];

    fd = open("highscores.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
        return;
    build_score_buffer(game, buffer);
    write(fd, buffer, my_strlen(buffer));
    close(fd);
}

void check_highscore(game_t *game)
{
    int current_highscore;

    if (game->mode == MODE_A)
        current_highscore = game->high_score_a;
    else
        current_highscore = game->high_score_b;
    if (game->score > current_highscore) {
        game->new_high_score = 1;
        if (game->mode == MODE_A)
            game->high_score_a = game->score;
        else
            game->high_score_b = game->score;
        save_highscores(game);
        update_highscore_text(game);
    }
}
