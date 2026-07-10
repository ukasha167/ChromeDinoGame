# Chrome Dino Game Clone

A hardware-accelerated, lightweight, and faithful clone of the iconic Google Chrome offline Dinosaur game (`chrome://dino`), built with **C++23** and **Raylib**.

---

## Features

- **Modern C++23**: Leverages modern C++ standards, clean object-oriented architecture, and structured game loop mechanics.
- **Raylib Rendering**: Hardware-accelerated graphics targeting smooth 144 FPS with low CPU overhead.
- **Automatic Dependency Resolution**: Utilizes CMake's `FetchContent` to download, build, and link Raylib 5.0 automatically.
- **Dynamic Difficulty Scaling**: Game speed, obstacle spawn probability, and horizontal gaps scale gradually as the player's score increases.
- **Object Pooling**: Implements an efficient recycling system using a circular buffer for obstacle spawning, maintaining a zero-allocation gameplay loop.
- **Faithful Gameplay Loop**: Features the intro starting animation, jumping/ducking mechanics with customized collision boxes, flying dinosaurs, and score tracking.

---

## Controls

| Action | Key(s) |
| :--- | :--- |
| **Start / Restart Game** | `Space` / `Up Arrow` |
| **Jump** | `Space` / `Up Arrow` |
| **Duck** | `Down Arrow` |

---

## Prerequisites

- **CMake**: version `3.24` or higher
- **C++ Compiler**: with C++23 support
  - GCC 13+
  - Clang 16+
  - MSVC 2022+

*(Note: Raylib dependencies like OpenGL and X11 development files are required if building on Linux/X11 systems)*

---

## How to Build and Run

1. Clone this repository (ensure to preserve the directory structure):
   ```bash
   git clone <repository-url>
   cd ChromeDinoGame
   ```

2. Generate the build configuration and compile using CMake:
   ```bash
   cmake -B build -S . -DCMAKE_BUILD_TYPE=Release
   cmake --build build
   ```

3. Run the compiled executable:
   - **Windows**: `build\Release\main.exe`
   - **macOS / Linux**: `./build/main`

---

## Project Structure

- `src/` — Game logic and engine wrapper.
  - `main.cpp` — Main loop and window lifecycle initialization.
  - `solver.cpp` / `solver.h` — Physics, collision checking, score tracking, and object recycling.
  - `renderer.cpp` / `renderer.h` — Rendering logic and texture asset handling.
  - `dino.cpp` — Dinosaur player state, gravity, controls, and dynamic box bounds.
  - `object.cpp` — Obstacle types (cacti, flying dinosaurs).
  - `background.cpp` — Parallax scrolling ground and background logic.
  - `defines.h` — Game constants, coordinates, and state definitions.
- `assets/` — Texture sheet (`sprite.png`) and coordinates text mapping (`coordinates.txt`).
