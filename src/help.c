/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** help display
*/
#include "my_hunter.h"
#include <unistd.h>

void display_help(void)
{
    write(1, "MY HUNTER - Space Shooter Edition\n\n", 36);
    write(1, "DESCRIPTION:\n", 13);
    write(1, "    An exciting arcade space shooter game!\n", 46);
    write(1, "    Enemy vehicles fly across the screen and you must\n", 57);
    write(1, "    shoot them before they escape. Watch explosions!\n\n", 57);
    write(1, "USAGE:\n", 7);
    write(1, "    ./my_hunter [-h]\n\n", 23);
    write(1, "OPTIONS:\n", 9);
    write(1, "    -h    Display this help message\n\n", 39);
    write(1, "CONTROLS:\n", 10);
    write(1, "    Mouse Click    - Shoot vehicles\n", 37);
    write(1, "    ESC / Close    - Exit game\n\n", 33);
    write(1, "GAMEPLAY:\n", 10);
    write(1, "    - Each round has 10 vehicles to destroy\n", 46);
    write(1, "    - You have 3 shots per vehicle\n", 37);
    write(1, "    - Hit minimum targets to advance to next round\n", 53);
    write(1, "    - Difficulty increases with each round\n", 45);
    write(1, "    - Enjoy the explosions and cyberpunk cityscape!\n\n", 55);
}
