#include <SDL.h>
#include <SDL_image.h>
#include "Map.hpp"
#include "SpriteEntity.hpp"

Map::Map(Vector2f p_pos, SDL_Texture* p_tex, int width, int height, Vector2f scale)
:Entity(p_pos, p_tex, width, height,scale){

}

void Map::cameraPosition(SpriteEntity player){

}