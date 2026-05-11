/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** audio initialization
*/
#include "my_hunter.h"

void init_sounds(game_t *game)
{
    game->shoot_buffer = sfSoundBuffer_createFromFile("sprites/shooting.mp3");
    game->hit_buffer = sfSoundBuffer_createFromFile(
        "sprites/explosion_sound.mp3");
    if (game->shoot_buffer) {
        game->shoot_sound = sfSound_create();
        sfSound_setBuffer(game->shoot_sound, game->shoot_buffer);
        sfSound_setVolume(game->shoot_sound, 50);
    } else
        game->shoot_sound = NULL;
    if (game->hit_buffer) {
        game->hit_sound = sfSound_create();
        sfSound_setBuffer(game->hit_sound, game->hit_buffer);
        sfSound_setVolume(game->hit_sound, 60);
    } else
        game->hit_sound = NULL;
}

void init_music(game_t *game)
{
    game->menu_music = sfMusic_createFromFile(
        "sprites/main_menu_song.mp3");
    if (game->menu_music) {
        sfMusic_setLoop(game->menu_music, sfTrue);
        sfMusic_setVolume(game->menu_music, 30);
        sfMusic_play(game->menu_music);
    }
    game->bg_music = sfMusic_createFromFile("sprites/music.mp3");
    if (game->bg_music) {
        sfMusic_setLoop(game->bg_music, sfTrue);
        sfMusic_setVolume(game->bg_music, 0);
    }
}

void init_game_state(game_t *game)
{
    game->score = 0;
    game->round = 1;
    game->vehicles_killed = 0;
    game->shots_remaining = SHOTS_PER_VEHICLE;
    game->vehicles_spawned = 0;
    game->min_to_advance = 6;
    game->game_over = 0;
    game->spawn_timer = 0;
    game->vehicle_speed_multiplier = 1.0f;
    game->state = STATE_MENU;
    game->mode = MODE_A;
    game->selected_mode = 0;
    game->transition_timer = 0;
    game->menu_alpha = 1.0f;
    game->new_high_score = 0;
}
