/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** explosion management
*/
#include "my_hunter.h"

void kill_vehicle(game_t *game, int index, sfVector2f hit_pos)
{
    float vehicle_scale = game->vehicles[index].scale;

    game->vehicles[index].alive = 0;
    game->vehicles_killed++;
    game->score += 100 * game->round;
    game->shots_remaining = SHOTS_PER_VEHICLE;
    create_explosion(game, hit_pos, vehicle_scale);
    if (game->hit_sound)
        sfSound_play(game->hit_sound);
}

void create_explosion(game_t *game, sfVector2f position, float scale)
{
    for (int i = 0; i < MAX_VEHICLES; i++) {
        if (!game->explosions[i].active) {
            game->explosions[i].active = 1;
            game->explosions[i].position = position;
            game->explosions[i].frame = 0;
            game->explosions[i].timer = 0;
            game->explosions[i].scale = scale * 5.0f;
            sfSprite_setPosition(game->explosions[i].sprite, position);
            sfSprite_setScale(game->explosions[i].sprite,
                (sfVector2f){game->explosions[i].scale,
                game->explosions[i].scale});
            break;
        }
    }
}
