#include "defines.h"

struct Object
{
    float x = 0;
    float y = 0;
    float positionX = SCREEN_WIDTH;
    float positionY = HALF_SCREEN_HEIGHT;

    float width;
    float height;

    int currentObjectType = None;

    float getRenderWidth() const
    {
        return (currentObjectType == CACTI_LARGE_FOUR || currentObjectType == CACTI_LARGE_THREE || currentObjectType == FLYING_DINO) ? width * 0.5f : width * 0.6f;
    }

    float getRenderHeight() const
    {
        return (currentObjectType == CACTI_LARGE_FOUR || currentObjectType == CACTI_LARGE_THREE || currentObjectType == FLYING_DINO) ? height * 0.5f : height * 0.6f;
    }

    void update(const float &dt, const float &gameSpeed)
    {
        positionX -= gameSpeed * dt;
    }
};