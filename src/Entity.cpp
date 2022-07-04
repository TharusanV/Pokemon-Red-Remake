#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "Math.hpp"
#include "Entity.hpp"


//Constructor used for textures / Without just put null
Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex, int width, int height,Vector2f p_scale) 
: pos(p_pos), tex(p_tex), scale(p_scale)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = width;
    currentFrame.h = height;

}

SDL_Texture* Entity::getTex() {
    return tex;
}

SDL_Rect Entity::getCurrentFrame() {
    return currentFrame;
}

void Entity::TransformPos(float x, float y) {
    pos.x = x;
    pos.y = y;
}

float Entity::getXScale() {
    return scale.x;
}

float Entity::getYScale() {
    return scale.y;
}


//Sets the current frame to a specific rectangle
void Entity::setCurrentFrame(SDL_Rect rect) {
    currentFrame = rect;
}

//Sets current frame to specific dimensions of the image
void Entity::setCurrentFrame(int p_x, int p_y, int p_w, int p_h) {
    currentFrame.x = p_x;
    currentFrame.y = p_y;
    currentFrame.w = p_w;
    currentFrame.h = p_h;
}

