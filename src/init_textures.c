/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** texture initialization
*/
#include "my_hunter.h"

static int load_vehicle_textures(game_t *game)
{
    game->vehicle_textures[0] = sfTexture_createFromFile(
        "sprites/vehicle1.png", NULL);
    game->vehicle_textures[1] = sfTexture_createFromFile(
        "sprites/vehicle2.png", NULL);
    game->vehicle_textures[2] = sfTexture_createFromFile(
        "sprites/vehicle3.png", NULL);
    if (!game->vehicle_textures[0] || !game->vehicle_textures[1] ||
        !game->vehicle_textures[2])
        return 84;
    for (int i = 0; i < 3; i++)
        sfTexture_setSmooth(game->vehicle_textures[i], sfTrue);
    return 0;
}

static int load_explosion_textures(game_t *game)
{
    char explosion_path[256];
    char num[4];

    for (int i = 0; i < EXPLOSION_FRAMES; i++) {
        my_strcpy(explosion_path, "sprites/explosion/bomb-explosion");
        my_itoa(i + 1, num);
        my_strcat(explosion_path, num);
        my_strcat(explosion_path, ".png");
        game->explosion_textures[i] = sfTexture_createFromFile(
            explosion_path, NULL);
        if (!game->explosion_textures[i])
            return 84;
        sfTexture_setSmooth(game->explosion_textures[i], sfTrue);
    }
    return 0;
}

int init_textures(game_t *game)
{
    game->bg_texture = sfTexture_createFromFile("sprites/background.png",
        NULL);
    game->crosshair_texture = sfTexture_createFromFile(
        "sprites/crosshair.png", NULL);
    if (!game->bg_texture || !game->crosshair_texture)
        return 84;
    sfTexture_setSmooth(game->crosshair_texture, sfTrue);
    if (load_vehicle_textures(game) == 84)
        return 84;
    if (load_explosion_textures(game) == 84)
        return 84;
    return 0;
}
