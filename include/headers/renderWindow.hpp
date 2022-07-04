#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Entity;

class renderWindow {
    public:
        renderWindow(const char* p_title, int p_w, int p_h);
        SDL_Texture* loadTexture(const char* p_filePath);
        void cleanUp();
        void clear();
        void render(Entity& p_entity, int xscale=1, int yscale=1, int wscale=1, int hscale=1);
        void display();

    private:
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
};