#include <raylib.h>

#include "defines.h"

class Dino
{
private:
    float positionY = HALF_SCREEN_HEIGHT;

public:
    bool onGround = true;
    bool isDucking = false;
    float velocityY = 0.0f;
    float positionX = 1.0f;

    float getActualWidth() const
    {
        return isDucking && onGround ? 118.0f : 88.0f;
    }

    float getActualHeight() const
    {
        return isDucking && onGround ? 60.0f : 94.0f;
    }

    float getRenderingWidth() const
    {
        return isDucking && onGround ? 118.0f * 0.5f : 88.0f * 0.5f;
    }

    float getRenderingHeight() const
    {
        return isDucking && onGround ? 60.0f * 0.5f : 94.0f * 0.5f;
    }

    float getPositionY() const
    {
        return isDucking && onGround ? positionY + 25 : positionY;
    }

    void setDefaultPositionY()
    {
        positionY = HALF_SCREEN_HEIGHT;
        velocityY = 0.0f;
    }

    void update(const float &dt)
    {
        if ((IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_UP)) && onGround)
        {
            isDucking = false;
            onGround = false;
            velocityY = -JUMP_FORCE;
        }
        else if (IsKeyDown(KEY_DOWN))
        {
            isDucking = true;
            velocityY = JUMP_FORCE;
        }
        else
        {
            isDucking = false;
        }

        if (velocityY < 0 && !(IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_UP)))
        {
            velocityY += GRAVITY * 2.0f * dt;
        }
        else
        {
            velocityY += GRAVITY * dt;
        }

        positionY += velocityY * dt;

        if (positionY > HALF_SCREEN_HEIGHT)
        {
            positionY = HALF_SCREEN_HEIGHT;
            velocityY = 0.0f;
            onGround = true;
        }
    }
};