/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** sprite initialization
*/
#include "my_hunter.h"

static void init_background_sprite(game_t *game)
{
    sfVector2u bg_size;
    float scale_x;
    float scale_y;

    sfSprite_setTexture(game->bg_sprite, game->bg_texture, sfTrue);
    bg_size = sfTexture_getSize(game->bg_texture);
    scale_x = (float)WINDOW_WIDTH / bg_size.x;
    scale_y = (float)WINDOW_HEIGHT / bg_size.y;
    sfSprite_setScale(game->bg_sprite, (sfVector2f){scale_x, scale_y});
}

static void init_crosshair_sprite(game_t *game)
{
    sfVector2u tex_size;

    tex_size = sfTexture_getSize(game->crosshair_texture);
    sfSprite_setTexture(game->crosshair_sprite, game->crosshair_texture,
        sfTrue);
    sfSprite_setOrigin(game->crosshair_sprite,
        (sfVector2f){tex_size.x / 2.0f, tex_size.y / 2.0f});
    sfSprite_setScale(game->crosshair_sprite, (sfVector2f){0.5f, 0.5f});
}

static void init_vehicle_sprites(game_t *game, int i)
{
    sfVector2u tex_size;

    game->vehicles[i].sprite = sfSprite_create();
    game->explosions[i].sprite = sfSprite_create();
    sfSprite_setOrigin(game->vehicles[i].sprite, (sfVector2f){60, 40});
    tex_size = sfTexture_getSize(game->explosion_textures[0]);
    sfSprite_setOrigin(game->explosions[i].sprite,
        (sfVector2f){tex_size.x / 2.0f, tex_size.y / 2.0f});
    sfSprite_setTexture(game->explosions[i].sprite,
        game->explosion_textures[0], sfTrue);
    game->vehicles[i].alive = 0;
    game->explosions[i].active = 0;
    game->explosions[i].scale = 1.0f;
}

int init_sprites(game_t *game)
{
    game->bg_sprite = sfSprite_create();
    game->crosshair_sprite = sfSprite_create();
    if (!game->bg_sprite || !game->crosshair_sprite)
        return 84;
    init_background_sprite(game);
    init_crosshair_sprite(game);
    for (int i = 0; i < MAX_VEHICLES; i++) {
        init_vehicle_sprites(game, i);
        if (!game->vehicles[i].sprite || !game->explosions[i].sprite)
            return 84;
    }
    return 0;
}
