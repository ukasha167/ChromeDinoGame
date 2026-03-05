#ifndef DEFINES_H
#define DEFINES_H

constexpr int SCREEN_WIDTH = 1000;
constexpr int SCREEN_HEIGHT = 600;

constexpr int HALF_SCREEN_WIDTH = SCREEN_WIDTH >> 1;
constexpr int HALF_SCREEN_HEIGHT = SCREEN_HEIGHT >> 1;

constexpr char OBJECTS_COUNT = 6;
constexpr float DEFAULT_MINIMUM_OBJ_GAP = 425.0f;
constexpr float DEFAULT_MAXIMUM_OBJ_GAP = 625.0f;

constexpr float DEFAULT_GAME_SPEED = 450.f;
constexpr int GRAVITY = 2500;
constexpr int JUMP_FORCE = 700;

enum GameStates
{
    Menu = 0,
    Starting,
    Playing,
    GameOver
};

enum ObjectTypes
{
    None = 0,
    CACTUS_SMALL_ONE = 1,
    CACTI_SMALL_TWO = 2,
    CACTI_LARGE_THREE = 3,
    CACTI_LARGE_FOUR = 4,
    FLYING_DINO = 5
};

#endif