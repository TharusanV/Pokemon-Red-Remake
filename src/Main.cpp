#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include "renderWindow.hpp"
#include "Entity.hpp"
#include "SpriteEntity.hpp"
#include "MainMenu.hpp"

//USE - mingw32-make -f MakeFile


int main(int argc, char *argv[]){
	// Initializing and loading variables
	
	int currentTime = 0; 
	int prevTime = 0; 
	float delta = 0.0f;
	const Uint8 *keyState;

	
	renderWindow window("Pokemon Red - v1.0", 480, 432);

	SDL_Texture* playerTexture = window.loadTexture("res/gfx/characters/red.png");
	SDL_Texture* mainMenuTexture = window.loadTexture("res/gfx/StartUp/startUpTimelineV1.png");
	SDL_Texture* mainMenuOptionsTexture = window.loadTexture("res/gfx/StartUp/optionsTexture.png");

	SpriteEntity player(Vector2f(5,5), playerTexture, 256, 256, Vector2f(1, 1), 4, 4);
	Entity wallLeft(Vector2f(0,0), NULL, 1, 1280, Vector2f(1, 1));
	MainMenu mainMenu(Vector2f(0,0), mainMenuTexture, 16320, 144, Vector2f(3, 3));

	mainMenu.setCurrentFrame(0,0,160,144);

	bool isRunning = true; 
	SDL_Event ev;
	keyState = SDL_GetKeyboardState(NULL);

	while(isRunning){
		prevTime = currentTime; 
		currentTime = SDL_GetTicks(); 
		delta = (currentTime - prevTime) / 1000.0f;
		while(SDL_PollEvent(&ev) != 0)
		{
			// Getting the events
			if(ev.type == SDL_QUIT)
				isRunning = false;
		}

		player.update(delta, keyState);
		mainMenu.startAnimation(delta, keyState);
	

		window.clear();
		//player.collision(wallLeft);
		window.render(wallLeft);
		//window.render(player);
		window.render(mainMenu);
		window.display();

		
	}

	window.cleanUp();
	IMG_Quit();
	SDL_Quit();

	return 0;
}