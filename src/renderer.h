#ifndef RENDERER_H
#define RENDERER_H

#include <raylib.h>
#include <string.h>

#include "defines.h"

class Dino;
class ObjectData;
class Background;
class Solver;

class Renderer
{
private:
    static Texture2D sprite;

public:
    static void importAssets(Dino &dino, Background (&bg)[2]);
    static void unloadAssets();
    static void drawScene(const int &currentGameState, const int &currentScore, const int &highScore, const Dino &dino, const Rectangle *const currentPlayerState, const Background (&bg)[2], const ObjectData &objects);

private:
    static void drawMenu(const int &currentScore, const int &highScore, const Dino &dino, const Rectangle *const currentPlayerState, const Background (&bg)[2], const ObjectData &objects);
    static void drawStart(const int &currentScore, const int &highScore, const Dino &dino, const Rectangle *const currentPlayerState, const Background (&bg)[2], const ObjectData &objects);
    static void drawPlaying(const int &currentScore, const int &highScore, const Dino &dino, const Rectangle *const currentPlayerState, const Background (&bg)[2], const ObjectData &objects);
    static void drawOver(const int &currentScore, const int &highScore, const Dino &dino, const Rectangle *const currentPlayerState, const Background (&bg)[2], const ObjectData &objects);
};

#endif