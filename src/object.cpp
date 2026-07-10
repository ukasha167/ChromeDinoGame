#include "defines.h"

struct ObjectData
{
    alignas(16) float x[OBJECTS_COUNT] = {0};
    alignas(16) float y[OBJECTS_COUNT] = {0};
    alignas(16) float positionX[OBJECTS_COUNT] = {0};
    alignas(16) float positionY[OBJECTS_COUNT] = {0};

    alignas(16) float width[OBJECTS_COUNT] = {0};
    alignas(16) float height[OBJECTS_COUNT] = {0};

    int currentObjectType[OBJECTS_COUNT] = {None};

    float getRenderWidth(int index) const
    {
        return (currentObjectType[index] == CACTI_LARGE_FOUR || currentObjectType[index] == CACTI_LARGE_THREE || currentObjectType[index] == FLYING_DINO) ? width[index] * 0.5f : width[index] * 0.6f;
    }

    float getRenderHeight(int index) const
    {
        return (currentObjectType[index] == CACTI_LARGE_FOUR || currentObjectType[index] == CACTI_LARGE_THREE || currentObjectType[index] == FLYING_DINO) ? height[index] * 0.5f : height[index] * 0.6f;
    }
};