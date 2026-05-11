/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** cleanup resources
*/
#include "my_hunter.h"

static void cleanup_textures(game_t *game)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (game->vehicle_textures[i])
            sfTexture_destroy(game->vehicle_textures[i]);
    }
    for (i = 0; i < EXPLOSION_FRAMES; i++) {
        if (game->explosion_textures[i])
            sfTexture_destroy(game->explosion_textures[i]);
    }
    if (game->bg_texture)
        sfTexture_destroy(game->bg_texture);
    if (game->crosshair_texture)
        sfTexture_destroy(game->crosshair_texture);
}

static void cleanup_sprites(game_t *game)
{
    int i;

    if (game->bg_sprite)
        sfSprite_destroy(game->bg_sprite);
    if (game->crosshair_sprite)
        sfSprite_destroy(game->crosshair_sprite);
    for (i = 0; i < MAX_VEHICLES; i++) {
        if (game->vehicles[i].sprite)
            sfSprite_destroy(game->vehicles[i].sprite);
        if (game->explosions[i].sprite)
            sfSprite_destroy(game->explosions[i].sprite);
    }
}

static void cleanup_game_texts(game_t *game)
{
    if (game->score_text)
        sfText_destroy(game->score_text);
    if (game->round_text)
        sfText_destroy(game->round_text);
    if (game->shots_text)
        sfText_destroy(game->shots_text);
    if (game->game_over_text)
        sfText_destroy(game->game_over_text);
}

static void cleanup_menu_texts(game_t *game)
{
    if (game->title_text)
        sfText_destroy(game->title_text);
    if (game->mode_a_text)
        sfText_destroy(game->mode_a_text);
    if (game->mode_b_text)
        sfText_destroy(game->mode_b_text);
    if (game->exit_text)
        sfText_destroy(game->exit_text);
    if (game->instruction_text)
        sfText_destroy(game->instruction_text);
    if (game->resume_text)
        sfText_destroy(game->resume_text);
    if (game->quit_text)
        sfText_destroy(game->quit_text);
}

static void cleanup_highscore_texts(game_t *game)
{
    if (game->highscore_title_text)
        sfText_destroy(game->highscore_title_text);
    if (game->highscore_a_text)
        sfText_destroy(game->highscore_a_text);
    if (game->highscore_b_text)
        sfText_destroy(game->highscore_b_text);
    if (game->new_highscore_text)
        sfText_destroy(game->new_highscore_text);
    if (game->font)
        sfFont_destroy(game->font);
}

static void cleanup_clocks(game_t *game)
{
    if (game->clock)
        sfClock_destroy(game->clock);
    if (game->spawn_clock)
        sfClock_destroy(game->spawn_clock);
    if (game->transition_clock)
        sfClock_destroy(game->transition_clock);
}

static void cleanup_sounds(game_t *game)
{
    if (game->shoot_sound)
        sfSound_destroy(game->shoot_sound);
    if (game->hit_sound)
        sfSound_destroy(game->hit_sound);
    if (game->bg_music)
        sfMusic_destroy(game->bg_music);
    if (game->menu_music)
        sfMusic_destroy(game->menu_music);
    if (game->shoot_buffer)
        sfSoundBuffer_destroy(game->shoot_buffer);
    if (game->hit_buffer)
        sfSoundBuffer_destroy(game->hit_buffer);
}

void cleanup_game(game_t *game)
{
    if (game->window)
        sfRenderWindow_destroy(game->window);
    cleanup_textures(game);
    cleanup_sprites(game);
    cleanup_game_texts(game);
    cleanup_menu_texts(game);
    cleanup_highscore_texts(game);
    cleanup_clocks(game);
    cleanup_sounds(game);
}
