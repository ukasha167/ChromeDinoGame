#include <raylib.h>
#include <string>

#include "renderer.h"
#include "defines.h"
#include "solver.h"

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "1.67");
    SetTargetFPS(144);

    Renderer::importAssets(Solver::dino, Solver::bg);

    float dt;
    Solver::currentGameState = Menu;
    while (WindowShouldClose() == false)
    {
        dt = GetFrameTime();

        switch (Solver::currentGameState)
        {
        case Menu:
            if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_UP))
                Solver::currentGameState = Starting;

            break;

        case Starting:
            if (Solver::startAnimation(dt)) // ANIMATION IS DONE? (returns true)
            {
                Solver::currentGameState = Playing; // INTIATE GAME
                Solver::initGamePositions();
            }
            Solver::updatePlayerStates(dt); // DINO SHOULD ALSO WALK IN ANIMATION
            break;

        case Playing:
            Solver::updatePlayerStates(dt);
            Solver::updateGame(dt);
            Solver::updateScore();

            if (Solver::checkCollisions())
                Solver::currentGameState = GameOver;
            else
                Solver::recyleObject();

            break;

        case GameOver:
            if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_UP))
            {
                Solver::reset();
                Solver::currentGameState = Playing;
            }
            break;
        }

        BeginDrawing();
        ClearBackground(WHITE);

        Renderer::drawScene(Solver::currentGameState, Solver::currentScore, Solver::highScore, Solver::dino, Solver::currentPlayerState, Solver::bg, Solver::objects);

        EndDrawing();
    }

    Renderer::unloadAssets();
    CloseWindow();

    return 0;
}