#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <Entity.hpp>
#include <SpriteEntity.hpp>

class Map : public Entity {
  private:
    
  public:
    Map(Vector2f p_pos, SDL_Texture* p_tex, int width, int height, Vector2f scale);
    void cameraPosition(SpriteEntity player);
    void changeMap();
};
