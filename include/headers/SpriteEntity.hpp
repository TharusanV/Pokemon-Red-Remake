#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <Math.hpp>
#include <Entity.hpp>


class SpriteEntity : public Entity {

    public:
        SpriteEntity(Vector2f p_pos, SDL_Texture* p_tex, int width, int height, Vector2f scale, int numFramesX, int numFramesY);
        void update(float delta, const Uint8 *keyState);
        void collision(Entity object);
        

    private:
        float moveSpeed;
        float frameCounter; 
        int frameWidth, frameHeight;
        int textureWidth;
        bool isActive; 
        SDL_Scancode keys[4];
        Vector2f oldPos;
};




