#include "stdafx.h"

SuperMarioBros::SuperMarioBros(bool mode, string file, GLuint x, GLuint y, GLuint w, GLuint h) :Game(mode, file, x, y, w, h)
{
	actualScene = 0;
	initUniforms();
	initTextures();
	initBuffers();
	initSounds();
	initScenes();
	actualScene = 1;
   update();
}

SuperMarioBros::~SuperMarioBros()
{
	delete ptrTextureManager;
	delete ptrSoundManager;
}

void SuperMarioBros::initScenes()
{
   scenes.push_back(new World11(INTRO, ptrRenderer->shaders[0]->programID));
   scenes.push_back(new World11(WORLD11, ptrRenderer->shaders[0]->programID));
//   scenes.push_back(new World11(WORLD12, ptrRenderer->shaders[0]->programID));
//   scenes.push_back(new World11(WORLD13, ptrRenderer->shaders[0]->programID));
//   scenes.push_back(new World11(WORLD14, ptrRenderer->shaders[0]->programID));
//   scenes.push_back(new World11(WORLD21, ptrRenderer->shaders[0]->programID));
//   scenes.push_back(new World11(WORLD22, ptrRenderer->shaders[0]->programID));
//   scenes.push_back(new World11(WORLD23, ptrRenderer->shaders[0]->programID));
//   scenes.push_back(new World11(WORLD24, ptrRenderer->shaders[0]->programID));
//   scenes.push_back(new World11(WORLD31, ptrRenderer->shaders[0]->programID));
//   scenes.push_back(new World11(WORLD32, ptrRenderer->shaders[0]->programID));
//   scenes.push_back(new World11(WORLD33, ptrRenderer->shaders[0]->programID));
//   scenes.push_back(new World11(WORLD34, ptrRenderer->shaders[0]->programID));
}

void SuperMarioBros::initTextures()
{
	ptrTextureManager = new TextureManager();
	ptrTextureManager->initTexture(PALETTE_1, "Assets/Textures/palette_1_", 5, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(PALETTE_2, "Assets/Textures/palette_2_", 4, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(PALETTE_3, "Assets/Textures/palette_3_", 4, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(PALETTE_4, "Assets/Textures/palette_4_", 4, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(PALETTE_5, "Assets/Textures/palette_5_", 4, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(PALETTE_6, "Assets/Textures/palette_6_", 4, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(PALETTE_7, "Assets/Textures/palette_7_", 4, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(PALETTE_8, "Assets/Textures/palette_8_", 11, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(PALETTE_9, "Assets/Textures/palette_9_", 1, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(PALETTE_10, "Assets/Textures/palette_10_", 1, GL_TEXTURE_2D_ARRAY);
}

void SuperMarioBros::initSounds()
{
	ptrSoundManager = new SoundManager();
	ptrSoundManager->initBGM(0, "Assets/BGM/01 - Super Mario Bros.mp3");
	ptrSoundManager->initBGM(1, "Assets/BGM/02 - Invincibility Star.mp3");
	ptrSoundManager->initBGM(2, "Assets/BGM/03 - Hurry - Super Mario Bros.mp3");
	ptrSoundManager->initBGM(3, "Assets/BGM/04 - Area Clear.mp3");
	ptrSoundManager->initBGM(4, "Assets/BGM/05 - Warp Pipe.mp3");
	ptrSoundManager->initBGM(5, "Assets/BGM/06 - Underground.mp3");
	ptrSoundManager->initBGM(6, "Assets/BGM/08 - Water World.mp3");
	ptrSoundManager->initBGM(7, "Assets/BGM/09 - Hurry - Water World.mp3");
	ptrSoundManager->initBGM(8, "Assets/BGM/11 - Hurry - Castle.mp3");
	ptrSoundManager->initBGM(9, "Assets/BGM/12 - World Clear.mp3");
	ptrSoundManager->initBGM(10, "Assets/BGM/13 - Ending.mp3");
	ptrSoundManager->initBGM(11, "Assets/BGM/13 - Ending.mp3");
	ptrSoundManager->initSFX(13, "Assets/SFX/Beep.wav");
	ptrSoundManager->initSFX(14, "Assets/SFX/Big Jump.wav");
	ptrSoundManager->initSFX(15, "Assets/SFX/Bowser Die.wav");
	ptrSoundManager->initSFX(16, "Assets/SFX/Break.wav");
	ptrSoundManager->initSFX(17, "Assets/SFX/Bump.wav");
	ptrSoundManager->initSFX(18, "Assets/SFX/Coin.wav");
	ptrSoundManager->initSFX(19, "Assets/SFX/Die.wav");
	ptrSoundManager->initSFX(20, "Assets/SFX/Enemy Fire.wav");
	ptrSoundManager->initSFX(21, "Assets/SFX/Flagpole.wav");
	ptrSoundManager->initSFX(22, "Assets/SFX/Game Over.wav");
	ptrSoundManager->initSFX(23, "Assets/SFX/Item.wav");
	ptrSoundManager->initSFX(24, "Assets/SFX/Jump.wav");
	ptrSoundManager->initSFX(25, "Assets/SFX/Kick.wav");
	ptrSoundManager->initSFX(26, "Assets/SFX/Powerup.wav");
	ptrSoundManager->initSFX(27, "Assets/SFX/Skid.wav");
	ptrSoundManager->initSFX(28, "Assets/SFX/Squish.wav");
	ptrSoundManager->initSFX(29, "Assets/SFX/Thwomp.wav");
	ptrSoundManager->initSFX(30, "Assets/SFX/Vine.wav");
   ptrSoundManager->initSFX(31, "Assets/SFX/Warp.wav");
}

void SuperMarioBros::initUniforms()
{

}

void SuperMarioBros::initBuffers()
{

}

void SuperMarioBros::update()
{
	while(active)
	{
		updateScene();
		updateUniforms();
		updateBuffers();
		updateTextures();
		updateSounds();
		checkEvents();
		ptrRenderer->update();
	}
}

void SuperMarioBros::updateScene()
{
	if (scenes[actualScene] != nullptr)
		scenes[actualScene]->update();
}

void SuperMarioBros::updateUniforms()
{

}

void SuperMarioBros::updateTextures()
{

}

void SuperMarioBros::updateSounds()
{

}

void SuperMarioBros::updateBuffers()
{

}

void SuperMarioBros::checkEvents()
{
	while (SDL_PollEvent(&gameEvents))
	{
		switch (gameEvents.key.type)
		{
		case SDL_KEYDOWN:
		{
			switch (gameEvents.key.keysym.sym)
			{
			case SDLK_a:
				leftButton = true;

				break;

			case SDLK_d:
				rightButton = true;

				break;

			case SDLK_w:

				upButton = true;

				break;

			case SDLK_s:
				downButton = true;


				break;

			case SDLK_x:



				break;

			case SDLK_c:


				break;

			case SDLK_y:
				break;

			case SDLK_k:
				bButton = true;

				break;

			case SDLK_l:
				aButton = true;


				break;

			case SDLK_LEFT:

				break;

			case SDLK_RIGHT:

				break;


			case SDLK_UP:

				break;

			case SDLK_DOWN:

				break;

			case SDLK_RETURN:

				break;

			case SDLK_ESCAPE:
				active = false;
				break;
			}
		}
		break;

		case SDL_KEYUP:
		{
			switch (gameEvents.key.keysym.sym)
			{
			case SDLK_a:
				leftButton = false;

				break;

			case SDLK_d:
				rightButton = false;

				break;

			case SDLK_w:
				upButton = false;

				break;

			case SDLK_s:
				downButton = false;

				break;

			case SDLK_k:
				bButton = false;

				break;

			case SDLK_l:
				aButton = false;

				break;

			case SDLK_RIGHT:

				break;

			case SDLK_LEFT:

				break;

			case SDLK_UP:

				break;

			case SDLK_DOWN:

				break;

			case SDLK_z:

				break;

			case SDLK_x:

				break;

			case SDLK_c:

				break;

			case SDLK_ESCAPE:
				active = false;
				break;
			}
		}
		break;

		default:
			break;
		}
	}
}
