/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** menu transitions
*/
#include "my_hunter.h"

static void finalize_pause_to_menu(game_t *game)
{
    game->state = STATE_MENU;
    game->menu_alpha = 1.0f;
    game->selected_mode = 0;
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    if (!game->menu_music)
        return;
    sfMusic_setVolume(game->menu_music, 30);
    if (sfMusic_getStatus(game->menu_music) != sfPlaying)
        sfMusic_play(game->menu_music);
}

void update_pause_to_menu(game_t *game, float delta_time)
{
    float fade_progress;

    game->transition_timer += delta_time;
    if (game->transition_timer < MENU_FADE_DURATION * 0.5f) {
        game->menu_alpha = 1.0f - (game->transition_timer /
            (MENU_FADE_DURATION * 0.5f));
        return;
    }
    if (game->transition_timer < MENU_FADE_DURATION) {
        fade_progress = (game->transition_timer - (MENU_FADE_DURATION * 0.5f))
            / (MENU_FADE_DURATION * 0.5f);
        game->menu_alpha = fade_progress;
        return;
    }
    finalize_pause_to_menu(game);
}

static void finalize_transition(game_t *game)
{
    game->state = STATE_PLAYING;
    if (game->menu_music)
        sfMusic_stop(game->menu_music);
    if (game->bg_music) {
        sfMusic_setVolume(game->bg_music, 30);
        sfMusic_play(game->bg_music);
    }
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
}

static void update_music_fade(game_t *game, float fade_progress)
{
    if (game->menu_music)
        sfMusic_setVolume(game->menu_music, 30 * (1.0f - fade_progress));
    if (game->bg_music)
        sfMusic_setVolume(game->bg_music, 30 * fade_progress);
}

void update_transition(game_t *game, float delta_time)
{
    float fade_progress;

    game->transition_timer += delta_time;
    game->menu_alpha = 1.0f - (game->transition_timer / MENU_FADE_DURATION);
    if (game->menu_alpha < 0)
        game->menu_alpha = 0;
    if (game->transition_timer >= MUSIC_FADE_DURATION) {
        finalize_transition(game);
        return;
    }
    fade_progress = game->transition_timer / MUSIC_FADE_DURATION;
    update_music_fade(game, fade_progress);
}

void start_game_transition(game_t *game)
{
    reset_game_state(game);
    game->state = STATE_TRANSITION;
    game->transition_timer = 0;
    game->menu_alpha = 1.0f;
    sfClock_restart(game->transition_clock);
    if (game->bg_music)
        sfMusic_play(game->bg_music);
}

void start_pause_to_menu_transition(game_t *game)
{
    if (game->bg_music) {
        sfMusic_stop(game->bg_music);
        sfMusic_setVolume(game->bg_music, 0);
    }
    if (game->menu_music) {
        sfMusic_stop(game->menu_music);
        sfMusic_setVolume(game->menu_music, 30);
        sfMusic_play(game->menu_music);
    }
    game->state = STATE_PAUSE_TO_MENU;
    game->transition_timer = 0;
    sfClock_restart(game->transition_clock);
}
