/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** my_hunter header file
*/

#ifndef MY_HUNTER_H
    #define MY_HUNTER_H

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <time.h>
    #include <math.h>
    #include <string.h>

    #define WINDOW_WIDTH 1280
    #define WINDOW_HEIGHT 720
    #define MAX_VEHICLES 10
    #define VEHICLES_PER_ROUND 10
    #define SHOTS_PER_VEHICLE 3
    #define VEHICLE_FRAMES 3
    #define ANIMATION_SPEED 0.1f
    #define EXPLOSION_FRAMES 6
    #define EXPLOSION_DURATION 0.6f
    #define MENU_FADE_DURATION 1.0f
    #define MUSIC_FADE_DURATION 1.5f

typedef enum game_state_e {
    STATE_MENU,
    STATE_TRANSITION,
    STATE_PLAYING,
    STATE_PAUSED,
    STATE_PAUSE_TO_MENU
} game_state_t;

typedef enum game_mode_e {
    MODE_A,
    MODE_B
} game_mode_t;

typedef struct vehicle_s {
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f velocity;
    int alive;
    int frame;
    float animation_timer;
    float rotation;
    float scale;
    int type;
} vehicle_t;

typedef struct explosion_s {
    sfSprite *sprite;
    sfVector2f position;
    int active;
    int frame;
    float timer;
    float scale;
} explosion_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfTexture *vehicle_textures[3];
    sfTexture *bg_texture;
    sfTexture *crosshair_texture;
    sfTexture *explosion_textures[EXPLOSION_FRAMES];
    sfSprite *bg_sprite;
    sfSprite *crosshair_sprite;
    sfFont *font;
    sfText *score_text;
    sfText *round_text;
    sfText *shots_text;
    sfText *game_over_text;
    sfText *title_text;
    sfText *mode_a_text;
    sfText *mode_b_text;
    sfText *exit_text;
    sfText *instruction_text;
    sfText *resume_text;
    sfText *quit_text;
    sfText *highscore_title_text;
    sfText *highscore_a_text;
    sfText *highscore_b_text;
    sfText *new_highscore_text;
    sfClock *clock;
    sfClock *spawn_clock;
    sfClock *transition_clock;
    sfSound *shoot_sound;
    sfSound *hit_sound;
    sfMusic *bg_music;
    sfMusic *menu_music;
    sfSoundBuffer *shoot_buffer;
    sfSoundBuffer *hit_buffer;
    vehicle_t vehicles[MAX_VEHICLES];
    explosion_t explosions[MAX_VEHICLES];
    int score;
    int round;
    int vehicles_killed;
    int shots_remaining;
    int vehicles_spawned;
    int min_to_advance;
    int game_over;
    int high_score_a;
    int high_score_b;
    int new_high_score;
    float spawn_timer;
    float vehicle_speed_multiplier;
    game_state_t state;
    game_mode_t mode;
    int selected_mode;
    float transition_timer;
    float menu_alpha;
} game_t;

void display_help(void);
int init_game(game_t *game);
void cleanup_game(game_t *game);
void game_loop(game_t *game);
void handle_events(game_t *game);
typedef void (*state_handler_t)(game_t *, float);

void handle_menu_state(game_t *game, float delta_time);
void handle_transition_state(game_t *game, float delta_time);
void handle_paused_state(game_t *game, float delta_time);
void handle_pause_to_menu_state(game_t *game, float delta_time);
void handle_playing_state(game_t *game, float delta_time);
void handle_mouse_click(game_t *game, sfMouseButtonEvent event);
void handle_menu_input(game_t *game, sfKeyCode key);
void update_game(game_t *game, float delta_time);
void update_menu(game_t *game, float delta_time);
void update_transition(game_t *game, float delta_time);
void update_pause_to_menu(game_t *game, float delta_time);
void update_vehicles(game_t *game, float delta_time);
void update_explosions(game_t *game, float delta_time);
void spawn_vehicle(game_t *game);
void draw_game(game_t *game);
void draw_menu(game_t *game);
void draw_pause_menu(game_t *game);
void start_game_transition(game_t *game);
void pause_game(game_t *game);
void resume_game(game_t *game);
void reset_game_state(game_t *game);
void update_pause_to_menu(game_t *game, float delta_time);
void update_transition(game_t *game, float delta_time);
void start_pause_to_menu_transition(game_t *game);
void load_highscores(game_t *game);
void save_highscores(game_t *game);
void check_highscore(game_t *game);
void update_highscore_text(game_t *game);
void configure_all_text(game_t *game);
void init_sounds(game_t *game);
void init_music(game_t *game);
void init_game_state(game_t *game);
int init_textures(game_t *game);
int init_sprites(game_t *game);
int init_text(game_t *game);
void my_itoa(int num, char *str);
int my_strlen(const char *str);
void my_strcpy(char *dest, const char *src);
void my_strcat(char *dest, const char *src);
void update_score_text(game_t *game);
void next_round(game_t *game);
int check_vehicle_collision(vehicle_t *vehicle, sfVector2f mouse_pos);
void kill_vehicle(game_t *game, int index, sfVector2f hit_pos);
void reset_round(game_t *game);
void create_explosion(game_t *game, sfVector2f position, float scale);

#endif /* MY_HUNTER_H */
