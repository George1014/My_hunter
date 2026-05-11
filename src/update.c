/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** game update logic
*/
#include "my_hunter.h"

static void update_vehicle_animation(game_t *game, int i)
{
    sfVector2u tex_size;
    int frame_width;
    sfIntRect rect;

    game->vehicles[i].frame = (game->vehicles[i].frame + 1) %
        VEHICLE_FRAMES;
    game->vehicles[i].animation_timer = 0;
    tex_size = sfTexture_getSize(game->vehicle_textures[
        game->vehicles[i].type]);
    frame_width = tex_size.x / VEHICLE_FRAMES;
    rect = (sfIntRect){game->vehicles[i].frame * frame_width, 0,
        frame_width, tex_size.y};
    sfSprite_setTextureRect(game->vehicles[i].sprite, rect);
}

static int is_vehicle_out_of_bounds(vehicle_t *vehicle)
{
    if (vehicle->position.x < -200)
        return 1;
    if (vehicle->position.x > WINDOW_WIDTH + 200)
        return 1;
    if (vehicle->position.y < -200)
        return 1;
    if (vehicle->position.y > WINDOW_HEIGHT + 200)
        return 1;
    return 0;
}

static void update_single_vehicle(game_t *game, int i, float delta_time)
{
    game->vehicles[i].position.x += game->vehicles[i].velocity.x * delta_time;
    game->vehicles[i].position.y += game->vehicles[i].velocity.y * delta_time;
    game->vehicles[i].animation_timer += delta_time;
    if (game->vehicles[i].animation_timer >= ANIMATION_SPEED)
        update_vehicle_animation(game, i);
    sfSprite_setPosition(game->vehicles[i].sprite,
        game->vehicles[i].position);
    if (is_vehicle_out_of_bounds(&game->vehicles[i])) {
        game->vehicles[i].alive = 0;
        game->shots_remaining = SHOTS_PER_VEHICLE;
    }
}

void update_vehicles(game_t *game, float delta_time)
{
    for (int i = 0; i < MAX_VEHICLES; i++) {
        if (game->vehicles[i].alive)
            update_single_vehicle(game, i, delta_time);
    }
}

static void update_explosion_frame(game_t *game, int i)
{
    int new_frame;

    new_frame = (int)(game->explosions[i].timer /
        EXPLOSION_DURATION * EXPLOSION_FRAMES);
    if (new_frame >= EXPLOSION_FRAMES)
        new_frame = EXPLOSION_FRAMES - 1;
    if (new_frame != game->explosions[i].frame) {
        game->explosions[i].frame = new_frame;
        sfSprite_setTexture(game->explosions[i].sprite,
            game->explosion_textures[new_frame], sfTrue);
    }
}

static void update_single_explosion(game_t *game, int i, float delta_time)
{
    game->explosions[i].timer += delta_time;
    if (game->explosions[i].timer >= EXPLOSION_DURATION) {
        game->explosions[i].active = 0;
        return;
    }
    update_explosion_frame(game, i);
}

void update_explosions(game_t *game, float delta_time)
{
    for (int i = 0; i < MAX_VEHICLES; i++) {
        if (game->explosions[i].active)
            update_single_explosion(game, i, delta_time);
    }
}
