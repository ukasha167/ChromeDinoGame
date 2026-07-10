#include <raylib.h>
#include <iostream>

#include "solver.h"
#include "dino.cpp"
#include "object.cpp"
#include "background.cpp"

Dino Solver::dino;
Background Solver::bg[2];
ObjectData Solver::objects;

bool Solver::startAnimation(const float &dt)
{
    if ((bg[0].width >= SCREEN_WIDTH) || (bg[0].width >= 2400))
    {
        bg[0].width = bg[1].width;
        return true;
    }

    Solver::dino.update(dt);
    dino.positionX += 35.0f * dt;

    bg[0].width += 1000.0f * dt;
    return false;
}

void Solver::initGamePositions()
{
    bg[0].positionX = 0;
    bg[1].positionX = bg[0].width;

    for (int i = 0; i < OBJECTS_COUNT; i++)
    {
        spawnObject(i);
    }
}

void Solver::recyleObject()
{
    if (objects.positionX[FIRST_OBJECT] + objects.getRenderWidth(FIRST_OBJECT) > 0)
    {
        return;
    }

    spawnObject(FIRST_OBJECT);
    FIRST_OBJECT = (FIRST_OBJECT + 1) % OBJECTS_COUNT;
}

void Solver::spawnObject(const int &index)
{
    int randomGap = GetRandomValue(minimumGapX, maximumGapX);
    objects.positionX[index] = objects.positionX[(index + OBJECTS_COUNT - 1) % OBJECTS_COUNT] + randomGap;

    int type = GetRandomValue(1, (int)objectSpawnProbability);

    switch (type)
    {
    case CACTUS_SMALL_ONE:
        objects.currentObjectType[index] = CACTUS_SMALL_ONE;
        objects.x[index] = 446;
        objects.y[index] = 2;
        objects.width[index] = 34;
        objects.height[index] = 70;
        objects.positionY[index] = bg[0].positionY - objects.getRenderHeight(index) + 30;
        break;

    case CACTI_SMALL_TWO:
        objects.currentObjectType[index] = CACTI_SMALL_TWO;
        objects.x[index] = 446;
        objects.y[index] = 2;
        objects.width[index] = 68;
        objects.height[index] = 70;
        objects.positionY[index] = bg[0].positionY - objects.getRenderHeight(index) + 30;
        break;

    case CACTI_LARGE_THREE:
        objects.currentObjectType[index] = CACTI_LARGE_THREE;
        objects.x[index] = 652;
        objects.y[index] = 2;
        objects.width[index] = 150;
        objects.height[index] = 98;
        objects.positionY[index] = bg[0].positionY - objects.getRenderHeight(index) + 30;
        break;

    case CACTI_LARGE_FOUR:
        objects.currentObjectType[index] = CACTI_LARGE_FOUR;
        objects.x[index] = 802;
        objects.y[index] = 2;
        objects.width[index] = 150;
        objects.height[index] = 98;
        objects.positionY[index] = bg[0].positionY - objects.getRenderHeight(index) + 30;
        break;

    case FLYING_DINO:
        objects.currentObjectType[index] = FLYING_DINO;
        objects.x[index] = 260;
        objects.y[index] = 2;
        objects.width[index] = 92;
        objects.height[index] = 80;

        int objHeight = GetRandomValue(0, 2);
        if (objHeight == 0)
        {
            objects.positionY[index] = (bg[0].positionY - objects.getRenderHeight(index)) - 35;
        }
        else if (objHeight == 1)
        {
            objects.positionY[index] = (bg[0].positionY - objects.getRenderHeight(index)) - 10;
        }
        else
        {
            objects.positionY[index] = (bg[0].positionY - objects.getRenderHeight(index)) + 15;
        }

        break;
    }
}

void Solver::updateGame(const float &dt)
{
    dino.update(dt);
    bg[0].update(dt, gameSpeed);
    bg[1].update(dt, gameSpeed);

    for (unsigned char i = 0; i < OBJECTS_COUNT; i++)
    {
        objects.positionX[i] -= gameSpeed * dt;
    }
}

void Solver::updatePlayerStates(const float &dt)
{
    playerStateIterator += 7.0f * dt;

    if (dino.onGround)
    {
        if (dino.isDucking)
        {
            currentItereratedState = 4 + (int(playerStateIterator) % 2);
            currentPlayerState = &playerStates[currentItereratedState]; // DUCKING STATES: 4 & 5
        }
        else
        {
            currentItereratedState = 0 + int(playerStateIterator + 5.5f * dt) % 3; // A LITTLE FASTER SWITCHING FOR WALKING
            currentPlayerState = &playerStates[currentItereratedState];            // WALKING STATES: 0, 1 & 2
        }
    }
    else
    {
        currentPlayerState = &playerStates[3]; // JUMPING STATE: 3
    }

    // FLYING DINO STATES ARE ONLY TWO, WE ALTERNATE BETWEEN THOSE TWO BASED ON EVEN/ODD
    for (unsigned char i = 0; i < OBJECTS_COUNT; i++)
    {
        if (objects.currentObjectType[i] == FLYING_DINO)
        {
            if (int(playerStateIterator) % 2)
            {
                objects.x[i] = 260;
            }
            else
            {
                objects.x[i] = 352;
            }
        }
    }

    if (playerStateIterator + 100.0f >= MAXFLOAT)
    {
        playerStateIterator = 0.0f; // PREVENT FROM CRASHING
    }
}

void Solver::updateScore()
{
    if (objects.positionX[CURRENT_OBJECT] + objects.getRenderWidth(CURRENT_OBJECT) >= dino.positionX)
    {
        return;
    }

    currentScore++;
    gameSpeed = gameSpeed < (DEFAULT_GAME_SPEED + 100) ? gameSpeed + 0.5 : gameSpeed;
    CURRENT_OBJECT = (CURRENT_OBJECT + 1) % OBJECTS_COUNT;
    objectSpawnProbability = objectSpawnProbability > 5.0f ? 5.0f : objectSpawnProbability + 0.4;

    if (maximumGapX < DEFAULT_MAXIMUM_OBJ_GAP + 150)
    {
        minimumGapX += 0.01f;
        maximumGapX += 0.01f;
    }
}

bool Solver::checkCollisions()
{
    Rectangle player = {dino.positionX, dino.getPositionY(), dino.getRenderingWidth(), dino.getRenderingHeight()};
    Rectangle obj = {objects.positionX[CURRENT_OBJECT], objects.positionY[CURRENT_OBJECT], objects.getRenderWidth(CURRENT_OBJECT), objects.getRenderHeight(CURRENT_OBJECT)};

    if (CheckCollisionRecs(player, obj))
    {
        return true;
    }

    return false;
}

void Solver::reset()
{
    if (currentScore > highScore)
    {
        highScore = currentScore;
    }

    currentScore = 0;
    gameSpeed = DEFAULT_GAME_SPEED;

    objectSpawnProbability = 1.0f;
    playerStateIterator = 0.0f;
    currentItereratedState = 0;

    FIRST_OBJECT = CURRENT_OBJECT = 0;

    minimumGapX = DEFAULT_MINIMUM_OBJ_GAP;
    maximumGapX = DEFAULT_MAXIMUM_OBJ_GAP;

    dino.setDefaultPositionY();
    for (int i = 0; i < OBJECTS_COUNT; i++)
    {
        objects.positionX[i] = SCREEN_WIDTH;
    }

    initGamePositions();
}