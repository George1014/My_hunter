/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** vehicle entity management
*/
#include "my_hunter.h"

static int find_free_vehicle_slot(game_t *game)
{
    for (int i = 0; i < MAX_VEHICLES; i++) {
        if (!game->vehicles[i].alive)
            return i;
    }
    return -1;
}

static void setup_left_spawn(game_t *game, int index, float *scale_x)
{
    game->vehicles[index].position.x = -100;
    game->vehicles[index].position.y = rand() % (WINDOW_HEIGHT - 200) + 100;
    game->vehicles[index].velocity.x = (150 + rand() % 150) *
        game->vehicle_speed_multiplier;
    game->vehicles[index].velocity.y = ((rand() % 60) - 30) *
        game->vehicle_speed_multiplier * 0.5f;
    *scale_x = game->vehicles[index].scale;
}

static void setup_right_spawn(game_t *game, int index, float *scale_x)
{
    game->vehicles[index].position.x = WINDOW_WIDTH + 100;
    game->vehicles[index].position.y = rand() % (WINDOW_HEIGHT - 200) + 100;
    game->vehicles[index].velocity.x = -(150 + rand() % 150) *
        game->vehicle_speed_multiplier;
    game->vehicles[index].velocity.y = ((rand() % 60) - 30) *
        game->vehicle_speed_multiplier * 0.5f;
    *scale_x = -game->vehicles[index].scale;
}

static void setup_vehicle_sprite(game_t *game, int index, int type)
{
    sfVector2u tex_size;
    int frame_width;
    sfIntRect rect;

    sfSprite_setTexture(game->vehicles[index].sprite,
        game->vehicle_textures[type], sfTrue);
    tex_size = sfTexture_getSize(game->vehicle_textures[type]);
    frame_width = tex_size.x / VEHICLE_FRAMES;
    rect = (sfIntRect){0, 0, frame_width, tex_size.y};
    sfSprite_setTextureRect(game->vehicles[index].sprite, rect);
    sfSprite_setPosition(game->vehicles[index].sprite,
        game->vehicles[index].position);
    sfSprite_setRotation(game->vehicles[index].sprite, 0);
}

static void init_vehicle_data(game_t *game, int index, int type)
{
    game->vehicles[index].alive = 1;
    game->vehicles[index].frame = 0;
    game->vehicles[index].animation_timer = 0;
    game->vehicles[index].type = type;
    game->vehicles[index].rotation = 0;
}

static void finalize_vehicle_spawn(game_t *game, int index, float scale_x)
{
    float scale_y = game->vehicles[index].scale;

    sfSprite_setScale(game->vehicles[index].sprite,
        (sfVector2f){scale_x, scale_y});
    game->vehicles_spawned++;
}

void spawn_vehicle(game_t *game)
{
    int index = find_free_vehicle_slot(game);
    int side;
    int type;
    float scale_x;

    if (index == -1 || game->vehicles_spawned >= VEHICLES_PER_ROUND)
        return;
    type = rand() % 3;
    side = rand() % 2;
    game->vehicles[index].scale = 0.6f + (rand() % 40) / 100.0f;
    if (side == 0)
        setup_left_spawn(game, index, &scale_x);
    else
        setup_right_spawn(game, index, &scale_x);
    init_vehicle_data(game, index, type);
    setup_vehicle_sprite(game, index, type);
    finalize_vehicle_spawn(game, index, scale_x);
}

int check_vehicle_collision(vehicle_t *vehicle, sfVector2f mouse_pos)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(vehicle->sprite);

    return mouse_pos.x >= bounds.left &&
        mouse_pos.x <= bounds.left + bounds.width &&
        mouse_pos.y >= bounds.top &&
        mouse_pos.y <= bounds.top + bounds.height;
}
