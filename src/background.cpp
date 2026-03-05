#include "defines.h"

struct Background
{
    float x = 0.0f;
    float y = 0.0f;

    float positionX = 0.0f;
    float positionY = HALF_SCREEN_HEIGHT + 30; // CLOSE TO DINO'S FEET

    float width = 0.0f;
    float height = 0.0f;

    void update(const float &dt, const float &gameSpeed)
    {
        positionX -= gameSpeed * dt;

        if (positionX + width < 0)
        {
            positionX = width;
        }
    }
};