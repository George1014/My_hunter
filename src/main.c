/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** program entry point
*/
#include "my_hunter.h"
#include <unistd.h>
#include <time.h>

int main(int ac, char **av)
{
    game_t game;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        display_help();
        return 0;
    }
    srand(time(NULL));
    if (init_game(&game) == 84) {
        write(2, "Error: Failed to initialize game\n", 34);
        return 84;
    }
    game_loop(&game);
    cleanup_game(&game);
    return 0;
}
