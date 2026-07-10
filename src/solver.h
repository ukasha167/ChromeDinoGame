#ifndef SOLVER_H
#define SOLVER_H

#include <raylib.h>
#include <iostream>

#include "defines.h"

class Dino;
class ObjectData;
class Background;

class Solver
{
private:
    inline static Rectangle playerStates[6] = {
        {1338, 2, 88, 94},    // WALKING I
        {1514, 2, 88, 94},    // WALKING II
        {1602, 2, 88, 94},    // WALKING III
        {1426, 2, 88, 94},    // JUMP I
        {1866, 36, 118, 60},  // DUCKIND I
        {1984, 36, 118, 60}}; // DUCKING II

    inline static Rectangle flyingDinoStates[2] = {
        {260, 2, 92, 80},
        {252, 2, 92, 80}};

    inline static float objectSpawnProbability = 1.0f; // VARIETY OF OBJECTS (INCREASED OVERTIME)
    inline static float playerStateIterator = 0.0f;
    inline static int currentItereratedState = 0;
    inline static float gameSpeed = DEFAULT_GAME_SPEED;

    inline static int FIRST_OBJECT = 0;
    inline static int CURRENT_OBJECT = FIRST_OBJECT;

    inline static float minimumGapX = DEFAULT_MINIMUM_OBJ_GAP;
    inline static float maximumGapX = DEFAULT_MAXIMUM_OBJ_GAP;

public:
    static Dino dino;
    static Background bg[2];
    static ObjectData objects;

    inline static GameStates currentGameState = Menu;
    inline static Rectangle *currentPlayerState = &playerStates[3]; // BY DEFAULT IT IS SET TO STARTING ANIMATION WHICH IS JUMPING

    inline static unsigned int currentScore = 0;
    inline static unsigned int highScore = 0;

    static bool startAnimation(const float &dt); // RETURNS TRUE IF THE ANIMATION HAS COMPLETED
    static void initGamePositions();
    static void updateGame(const float &dt);
    static void updateScore();
    static void updatePlayerStates(const float &dt);
    static void recyleObject();
    static void spawnObject(const int &index);
    static bool checkCollisions();
    static void reset();
};

#endif