#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <Math.hpp>
#include <vector>
#include "renderWindow.hpp"

class Entity {

    public:
        Entity(Vector2f p_pos, SDL_Texture* p_tex, int width, int height, Vector2f scale=Vector2f(1,1));
    
        Vector2f& getPos() { return pos;}       
        float getX();
        float getY();
        float getXScale();
        float getYScale();
        SDL_Texture* getTex();
        SDL_Rect getCurrentFrame();
        void printCurrentFrame();
        void setCurrentFrame(SDL_Rect rect);
        void setCurrentFrame(int p_x, int p_y, int p_w, int p_h);
        void init();
        virtual void update() {};
        void TransformPos(float x, float y);

    protected:
        Vector2f scale;
        SDL_Texture* tex;
        float topLeft, topRight, bottomLeft, bottomRight;
        Vector2f pos;
        SDL_Rect currentFrame;

};

