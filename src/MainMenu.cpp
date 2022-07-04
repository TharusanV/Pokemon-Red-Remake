#include "MainMenu.hpp" 

MainMenu::MainMenu(Vector2f p_pos, SDL_Texture* p_mainMenuTex, int width, int height, Vector2f scale)
:Entity(p_pos, p_mainMenuTex, width, height,scale){
  frameWidth = 160;
  textureWidth = width;
  mainMenuActive = false;
	startScreenActive = false;
	optionsMenuActive = false;
	enterCount = 0;
	keys[0] = SDL_SCANCODE_RETURN;
}

void MainMenu::startAnimation(float delta, const Uint8 *keyState){
  mainMenuActive = true;
	if(keyState[keys[0]]){
		mainMenuActive = false;
		return;
	}
	else{
		mainMenuActive = true;
	}


	if(mainMenuActive){
		frameCounter += delta; 
		if(frameCounter >= 0.25f){
			frameCounter = 0; 
			currentFrame.x += frameWidth; 
			if(currentFrame.x >=  textureWidth){
					mainMenuActive = false;;
      }
		}
	}
	else{
		startScreenActive = true;
		startScreen(keyState);
	}
}

void MainMenu::startScreen(const Uint8 *keyState){
	if(keyState[keys[0]]){
		startScreenActive = false;
		return;
	}
	else{
		startScreenActive = true;
	}

	if(startScreenActive == true){
		frameCounter = 101;
		currentFrame.x = 16160;
	}
	else{
		std::cout << "Hello" << std::endl;
	}

}

void MainMenu::startOptionsMenu(const Uint8 *keyState, SDL_Texture* p_optionsTexture){
	if(optionsMenuActive == true){
		setCurrentTexture(p_optionsTexture);
		frameCounter = 0;
		currentFrame.x = 0;
		if(keyState[keys[0]]){
		}
	}
}