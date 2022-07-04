#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "renderWindow.hpp"
#include "entity.hpp"

renderWindow::renderWindow(const char* p_title, int p_w, int p_h) :window(NULL), renderer(NULL) {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_w, p_h, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

SDL_Texture* renderWindow::loadTexture(const char* p_filePath) {
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);
    return texture;
}


void renderWindow::clear() {
    SDL_RenderClear(renderer);
}

void renderWindow::render(Entity& p_entity, int xscale, int yscale, int wscale, int hscale) {

    //This structure explains how big the source is (image) and where you want to start rendering
    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;

    //This structure explains the destination of the final output
    SDL_Rect dst;
    dst.x = p_entity.getPos().x;
    dst.y = p_entity.getPos().y;
    dst.w = p_entity.getCurrentFrame().w * (p_entity).getXScale();
    dst.h = p_entity.getCurrentFrame().h * (p_entity).getYScale();
 
    SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
}

void renderWindow::display() {
    SDL_RenderPresent(renderer);
}

void renderWindow::cleanUp() {
    SDL_DestroyWindow(window);
}
