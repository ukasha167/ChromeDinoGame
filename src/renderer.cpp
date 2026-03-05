#include <raylib.h>
#include <string.h>
#include <iostream>

#include "dino.cpp"
#include "object.cpp"
#include "background.cpp"
#include "solver.h"
#include "renderer.h"

Texture2D Renderer::sprite;

void Renderer::importAssets(Dino &dino, Background (&bg)[2])
{
    sprite = LoadTexture("../assets/sprite.png");

    // SPRITE LOCATIONS
    bg[0].x = bg[1].x = 2;
    bg[0].y = bg[1].y = 104;
    bg[0].height = bg[1].height = 24;
    bg[1].width = 2400;

    bg[0].width = dino.positionX + dino.getRenderingWidth();
}

void Renderer::unloadAssets()
{
    UnloadTexture(sprite);
}

void Renderer::drawScene(const int &currentGameState, const int &currentScore, const int &highScore, const Dino &dino, const Rectangle *const currentPlayerState, const Background (&bg)[2], const Object (&objects)[OBJECTS_COUNT])
{
    switch (currentGameState)
    {
    case Menu:
        drawMenu(currentScore, highScore, dino, currentPlayerState, bg, objects);
        break;

    case Starting:
        drawMenu(currentScore, highScore, dino, currentPlayerState, bg, objects);
        break;

    case Playing:
        drawPlaying(currentScore, highScore, dino, currentPlayerState, bg, objects);
        break;

    case GameOver:
        drawOver(currentScore, highScore, dino, currentPlayerState, bg, objects);
        break;
    }

    // DRAWING HITBOXES
    DrawRectangleLinesEx({dino.positionX, dino.getPositionY(), dino.getRenderingWidth(), dino.getRenderingHeight()}, 2.0f, RED);

    for (unsigned char i = 0; i < OBJECTS_COUNT; i++)
    {
        DrawRectangleLinesEx({objects[i].positionX, objects[i].positionY, objects[i].getRenderWidth(), objects[i].getRenderHeight()}, 2.0f, RED);
    }
}

void Renderer::drawMenu(const int &currentScore, const int &highScore, const Dino &dino, const Rectangle *const currentDinoState, const Background (&bg)[2], const Object (&objects)[OBJECTS_COUNT])
{
    // DrawTexturePro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint)

    // Draw Dino
    DrawTexturePro(
        sprite,
        *currentDinoState,
        {dino.positionX, dino.getPositionY(), dino.getRenderingWidth(), dino.getRenderingHeight()},
        {0.0f, 0.0f},
        0.0f,
        WHITE);

    // Draw BG[0]
    DrawTexturePro(
        sprite,
        {bg[0].x, bg[0].y, bg[0].width, bg[0].height},
        {bg[0].positionX, bg[0].positionY, bg[0].width, bg[0].height},
        {0.0f, 0.0f},
        0.0f,
        WHITE);
}

void Renderer::drawStart(const int &currentScore, const int &highScore, const Dino &dino, const Rectangle *const currentDinoState, const Background (&bg)[2], const Object (&objects)[OBJECTS_COUNT])
{
    // DrawTexturePro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint)

    // Draw Dino
    DrawTexturePro(
        sprite,
        *currentDinoState,
        {dino.positionX, dino.getPositionY(), dino.getRenderingWidth(), dino.getRenderingHeight()},
        {0.0f, 0.0f},
        0.0f,
        WHITE);

    // Draw BG[0]
    DrawTexturePro(
        sprite,
        {bg[0].x, bg[0].y, bg[0].width, bg[0].height},
        {bg[0].positionX, bg[0].positionY, bg[0].width, bg[0].height},
        {0.0f, 0.0f},
        0.0f,
        WHITE);
}

void Renderer::drawPlaying(const int &currentScore, const int &highScore, const Dino &dino, const Rectangle *const currentDinoState, const Background (&bg)[2], const Object (&objects)[OBJECTS_COUNT])
{
    // Draw Dino
    DrawTexturePro(
        sprite,
        *currentDinoState,
        {dino.positionX, dino.getPositionY(), dino.getRenderingWidth(), dino.getRenderingHeight()},
        {0.0f, 0.0f},
        0.0f,
        WHITE);

    // Draw BG[0]
    DrawTexturePro(
        sprite,
        {bg[0].x, bg[0].y, bg[0].width, bg[0].height},
        {bg[0].positionX, bg[0].positionY, bg[0].width, bg[0].height},
        {0.0f, 0.0f},
        0.0f,
        WHITE);

    // Draw BG[1]
    DrawTexturePro(
        sprite,
        {bg[1].x, bg[1].y, bg[1].width, bg[1].height},
        {bg[1].positionX, bg[1].positionY, bg[1].width, bg[1].height},
        {0.0f, 0.0f},
        0.0f,
        WHITE);

    // Draw OBJECTS
    for (unsigned char i = 0; i < OBJECTS_COUNT; i++)
    {
        DrawTexturePro(
            sprite,
            {objects[i].x, objects[i].y, objects[i].width, objects[i].height},
            {objects[i].positionX, objects[i].positionY, objects[i].getRenderWidth(), objects[i].getRenderHeight()},
            {0.0f, 0.0f},
            0.0f,
            WHITE);
    }

    // Draw HI (TEXTURE)
    DrawTexturePro(
        sprite,
        {1154, 2, 38, 21},
        {SCREEN_WIDTH - 225, 14, 27, 16},
        {0.0f, 0.0f},
        0.0f,
        WHITE);

    // Draw HIGH SCORE
    DrawText(TextFormat("%05i", highScore), SCREEN_WIDTH - 185, 11, 25, GRAY);

    // DRAW CURRENT SCORE
    DrawText(TextFormat("%05i", currentScore), SCREEN_WIDTH - 90, 11, 25, GRAY);

    // DRAW FPS
    DrawText(TextFormat("FPS: %02i", GetFPS()), 14, 14, 25, GRAY);
}

void Renderer::drawOver(const int &currentScore, const int &highScore, const Dino &dino, const Rectangle *const currentDinoState, const Background (&bg)[2], const Object (&objects)[OBJECTS_COUNT])
{
    // Draw Dino
    DrawTexturePro(
        sprite,
        *currentDinoState,
        {dino.positionX, dino.getPositionY(), dino.getRenderingWidth(), dino.getRenderingHeight()},
        {0.0f, 0.0f},
        0.0f,
        WHITE);

    // Draw BG[0]
    DrawTexturePro(
        sprite,
        {bg[0].x, bg[0].y, bg[0].width, bg[0].height},
        {bg[0].positionX, bg[0].positionY, bg[0].width, bg[0].height},
        {0.0f, 0.0f},
        0.0f,
        WHITE);

    // Draw BG[1]
    DrawTexturePro(
        sprite,
        {bg[1].x, bg[1].y, bg[1].width, bg[1].height},
        {bg[1].positionX, bg[1].positionY, bg[1].width, bg[1].height},
        {0.0f, 0.0f},
        0.0f,
        WHITE);

    for (unsigned char i = 0; i < OBJECTS_COUNT; i++)
    {
        DrawTexturePro(
            sprite,
            {objects[i].x, objects[i].y, objects[i].width, objects[i].height},
            {objects[i].positionX, objects[i].positionY, objects[i].getRenderWidth(), objects[i].getRenderHeight()},
            {0.0f, 0.0f},
            0.0f,
            WHITE);
    }

    // GAME-OVER
    DrawTexturePro(
        sprite,
        {954, 29, 381, 21},
        {HALF_SCREEN_WIDTH - (381 >> 1), HALF_SCREEN_HEIGHT - (21 >> 1) - 90, 381, 21},
        {0.0f, 0.0f},
        0.0f,
        WHITE);

    // RELOAD BUTTON
    DrawTexturePro(
        sprite,
        {2, 2, 72, 64},
        {HALF_SCREEN_WIDTH - (50 >> 1), HALF_SCREEN_HEIGHT - (45 >> 1) - 20, 50, 45},
        {0.0f, 0.0f},
        0.0f,
        WHITE);

    // Draw HI (TEXTURE)
    DrawTexturePro(
        sprite,
        {1154, 2, 38, 21},
        {SCREEN_WIDTH - 225, 14, 27, 16},
        {0.0f, 0.0f},
        0.0f,
        WHITE);

    // Draw HIGH SCORE
    DrawText(TextFormat("%05i", highScore), SCREEN_WIDTH - 185, 11, 25, GRAY);

    // DRAW CURRENT SCORE
    DrawText(TextFormat("%05i", currentScore), SCREEN_WIDTH - 90, 11, 25, GRAY);
}