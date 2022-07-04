#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Math.hpp"
#include <Entity.hpp>
#include <iostream>

class MainMenu  : public Entity {
  private:
    bool mainMenuActive;
    float frameCounter;
    int frameWidth;
    int textureWidth;
    SDL_Scancode keys[0];
    bool startScreenActive;
    bool optionsMenuActive;
    int enterCount;
 
  public:
    MainMenu(Vector2f p_pos, SDL_Texture* p_mainMenuTex, int width, int height, Vector2f scale);
    void startAnimation(float delta, const Uint8 *keyState);
    void startScreen(const Uint8 *keyState);
    void startOptionsMenu(const Uint8 *keyState, SDL_Texture* p_optionsTexture);
    void profOakLecture(float delta, const Uint8 *keyState);
    void setCurrentTexture(SDL_Texture* newTex) {tex = newTex;}
};