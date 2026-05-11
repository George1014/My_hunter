# My Hunter

> A fast-paced C arcade shooter built with CSFML — shoot enemy vehicles out of a cyberpunk sky before they escape.

<div align="center">

![Language](https://img.shields.io/badge/Language-C-blue?style=flat-square)
![Library](https://img.shields.io/badge/Library-CSFML-orange?style=flat-square)
![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS-lightgrey?style=flat-square)
![License](https://img.shields.io/badge/License-MIT-green?style=flat-square)

</div>

---

## Preview

<div align="center">
  <img src="preview.gif" alt="My Hunter gameplay preview" width="800" />
</div>

---

## What Is It?

**My Hunter** is an arcade vehicle-shooter written entirely in C using the CSFML library. Enemies — three distinct animated vehicle types — fly horizontally across a cyberpunk cityscape. Your job: click to fire, destroy as many targets as you can before your shots run out, and survive as long as possible while the game gets progressively faster and harder.

Think of it as a modern homage to classic shooting gallery games, wrapped in a neon city aesthetic with full audio, animated explosions, and a persistent high-score system for two different game modes.

---

## Features

| Feature | Details |
|---|---|
| **Two game modes** | Mode A (one vehicle at a time) and Mode B (two simultaneous targets) |
| **3 vehicle types** | Each with its own sprite and 3-frame flying animation |
| **6-frame explosions** | Satisfying animated blasts on every kill |
| **Progressive difficulty** | Each round vehicles spawn faster and more kills are required to advance |
| **Round bonuses** | Clear a round and earn `500 × round number` bonus points |
| **Persistent high scores** | Best scores for each mode are saved to disk and survive restarts |
| **Full audio** | Background music, menu music, shooting SFX, and explosion SFX |
| **Smooth transitions** | Fade in/out between menus and gameplay |
| **Custom crosshair** | Mouse cursor replaced with a crosshair sprite during play |
| **Pause menu** | Press ESC in-game to pause and resume or return to the main menu |

---

## Gameplay

```
Round starts → vehicles fly across the screen from left or right
     ↓
Click to shoot — each vehicle allows 3 shots before it escapes
     ↓
Destroy the minimum required kills before all 10 vehicles are gone
     ↓
   SUCCESS → bonus points + next round (faster, harder)
   FAILURE → game over, high score checked and saved
```

**Key numbers:**
- 10 vehicles per round
- 3 shots per vehicle
- Minimum kills to advance starts at **6** and climbs every two rounds (capped at 10)
- Vehicle speed increases by **0.2×** every round

---

## Controls

| Input | Action |
|---|---|
| **Left click** | Shoot |
| **Arrow keys / mouse** | Navigate menus |
| **Enter / click** | Confirm menu selection |
| **ESC** | Pause game / close window |

---

## Getting Started

### Prerequisites

You need **CSFML** (C bindings for SFML) installed on your system.

**macOS (Homebrew):**
```bash
brew install csfml
```

**Ubuntu / Debian:**
```bash
sudo apt install libcsfml-dev
```

**Arch Linux:**
```bash
sudo pacman -S csfml
```

### Build

```bash
git clone https://github.com/your-username/my-hunter.git
cd my-hunter
make
```

### Run

```bash
./my_hunter
```

### Help

```bash
./my_hunter -h
```

### Clean up

```bash
make clean    # remove object files
make fclean   # remove object files + binary
make re       # full rebuild
```

---

## Project Structure

```
my-hunter/
├── src/                  # All C source files
│   ├── main.c            # Entry point
│   ├── game.c            # Main game loop
│   ├── game_states.c     # State machine (menu, playing, paused…)
│   ├── vehicle.c         # Vehicle spawning & collision
│   ├── explosion.c       # Explosion animation logic
│   ├── input.c           # Event handling
│   ├── draw.c            # Rendering
│   ├── update.c          # Per-frame update logic
│   ├── update_round.c    # Round progression
│   ├── score.c           # Score text management
│   ├── highscore.c       # High score load/save
│   ├── menu.c            # Pause & game state management
│   ├── menu_input.c      # Menu keyboard handling
│   ├── menu_draw.c       # Menu rendering
│   ├── menu_transition.c # Fade transitions
│   ├── init.c            # Full game initialization
│   ├── init_textures.c   # Texture loading
│   ├── init_sprites.c    # Sprite setup
│   ├── init_text.c       # Font & text setup
│   ├── init_audio.c      # Sound & music setup
│   ├── cleanup.c         # Resource deallocation
│   ├── help.c            # CLI help output
│   ├── string_utils.c    # Custom string helpers
│   └── text_init.c       # Text configuration
├── include/
│   └── my_hunter.h       # Shared structs, enums, and function declarations
├── sprites/              # All game assets
│   ├── background.png
│   ├── crosshair.png
│   ├── vehicle1.png / vehicle2.png / vehicle3.png
│   ├── explosion/        # 6 explosion frames
│   ├── music.mp3
│   ├── main_menu_song.mp3
│   ├── shooting.mp3
│   └── explosion_sound.mp3
├── highscores.txt        # Auto-generated on first playthrough
├── Makefile
└── README.md
```

---

## Technical Overview

- **Language:** C (C11)
- **Graphics & Audio:** [CSFML](https://www.sfml-dev.org/download/csfml/) — the official C binding for SFML
- **Architecture:** State-machine driven game loop with function-pointer dispatch
- **Window:** 1280 × 720
- **Build system:** GNU Make + GCC

The game loop runs a tight `while (window is open)` cycle. Each iteration computes a `delta_time` from an `sfClock`, then dispatches to the appropriate state handler (menu, transition, playing, paused, pause-to-menu). This keeps game logic fully frame-rate independent.

---

## High Scores

High scores are stored separately for **Mode A** and **Mode B** in `highscores.txt` in the working directory. The file is created automatically and updated instantly whenever you beat your record.

---

## License

This project is open source and available under the [MIT License](LICENSE).

---

<div align="center">
  Made with C and CSFML
</div>