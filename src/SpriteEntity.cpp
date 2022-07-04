#include "Entity.hpp"
#include "SpriteEntity.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <vector>




SpriteEntity::SpriteEntity(Vector2f p_pos, SDL_Texture* p_tex, int width, int height, Vector2f scale, int numFramesX, int numFramesY)
:Entity(p_pos, p_tex, width, height,scale){
	
  textureWidth = width;

	currentFrame.w /= numFramesX;
	currentFrame.h /= numFramesY;

  frameWidth = currentFrame.w; 
	frameHeight = currentFrame.h;

  isActive = false; 

	keys[0] = SDL_SCANCODE_W;
	keys[1] = SDL_SCANCODE_S;
	keys[2] = SDL_SCANCODE_A;
	keys[3] = SDL_SCANCODE_D;

	moveSpeed = 200.0f;

    

}


void SpriteEntity::update(float delta, const Uint8 *keyState){
	isActive = true;
    oldPos.x = pos.x;
    oldPos.y = pos.y;
	if(keyState[keys[0]])
	{
		pos.y -= (int)(moveSpeed * delta); 
		currentFrame.y = frameHeight * 3;
	}
	else if(keyState[keys[1]])
	{
		pos.y += (int)(moveSpeed * delta); 
		currentFrame.y = 0;
	}
	else if(keyState[keys[2]])
	{
		pos.x -= (int)(moveSpeed * delta); 
		currentFrame.y = frameHeight;
	}
	else if(keyState[keys[3]])
	{
		pos.x += (int)(moveSpeed * delta); 
		currentFrame.y = frameHeight * 2;
	}
	else 
		isActive = false;

	if(isActive)
	{
		frameCounter += delta; 

		if(frameCounter >= 0.25f)
		{
			frameCounter = 0; 
			currentFrame.x += frameWidth; 
			if(currentFrame.x >=  textureWidth){
        currentFrame.x = 0; 
      }	
		}
	}
	else
	{
		frameCounter = 0;
		currentFrame.x = 0;
	}
}

void SpriteEntity::collision(Entity object) {

    //Get left/right/top/bottom of sprite and object
    //Left = leftmost point on image, right = rightmost point on image, top is topmost point and bottom is bottom most point
    float left;
    float right;
    float top;
    float bottom;

    float objectLeft;
    float objectRight;
    float objectTop;
    float objectBottom;

    //X is top left so is just left
    //We get the top left and add the width multiplied by the scale of the image to find the rightmost point.
    //Similar process with top and bottom 
    
    left = pos.x;
    right = pos.x + (currentFrame.w * getXScale());
    top = pos.y;
    bottom = pos.y + (currentFrame.h * getYScale());

    objectLeft = object.getPos().x;
    objectRight = object.getPos().y + (object.getCurrentFrame().w * getXScale());
    objectTop = object.getPos().y;
    objectBottom = object.getPos().y + (object.getCurrentFrame().h * getYScale());

    //Checks made on each to see if collision happens
    if (left < (objectRight) && right > (objectLeft) && top < (objectBottom) && bottom > (objectTop)) {
        pos.x = oldPos.x;
        pos.y = oldPos.y;
        std::cout << "Collision Detected 1" << std::endl;
        
    }
    else {
        std::cout << "No collision detected" << std::endl;
    
    }
}
