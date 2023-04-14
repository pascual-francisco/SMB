#pragma once
#include "stdafx.h"

SuperMarioBros::SuperMarioBros(bool mode, string file, GLuint x, GLuint y, GLuint w, GLuint h) :Game(mode, file, x, y, w, h)
{
	actualScene = WORLD11;
	initUniforms();
	initTextures();
	initBuffers();
	initScenes();
	initSounds();
	update();
}

SuperMarioBros::~SuperMarioBros()
{
	delete ptrTextureManager;
	delete ptrSoundManager;
}

void SuperMarioBros::initScenes()
{
	scenes.push_back(new World11(INTRO, true, viewPort, ptrRenderer->ptrShaders[0]->programID));
	scenes.push_back(new World11(WORLD11, true, viewPort, ptrRenderer->ptrShaders[0]->programID));
}

void SuperMarioBros::initTextures()
{
	ptrTextureManager = new TextureManager();
	ptrTextureManager->initTexture(SKY00001, "Assets/Textures/l0_Sky_1", 1, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(SKY00003, "Assets/Textures/l0_Sky_3", 1, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(SKY00002, "Assets/Textures/l0_Sky_2", 1, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(SKY00004, "Assets/Textures/l0_Sky_4", 1, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(CLOUD001, "Assets/Textures/l0_Cloud_", 5, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(GROUND01, "Assets/Textures/ground_0", 1, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(GROUND02, "Assets/Textures/ground_1", 1, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(GROUND03, "Assets/Textures/ground_2", 1, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(GROUND04, "Assets/Textures/ground_3", 1, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(BLOCK001, "Assets/Textures/l0_Block_1", 1, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(BLOCK002, "Assets/Textures/l0_Block_2", 1, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(BLOCK003, "Assets/Textures/l0_Block_3", 1, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(BLOCK004, "Assets/Textures/l0_Block_4", 1, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(MARIO, "Assets/Textures/l0_Mario_", 14, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(SUPER_MARIO, "Assets/Textures/l0_SuperMario_", 15, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(GOOMBA, "Assets/Textures/l0_Goomba_", 3, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(TROOPA, "Assets/Textures/l0_Troopa_", 6, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTexture(PIRANHA, "Assets/Textures/l0_Piranha_", 8, GL_TEXTURE_2D_ARRAY);
	ptrTextureManager->initTileSet(QUESTIONSET1, "Assets/Textures/l0_QuestionSet1", 16, 16, 5, 5, 0, 0, GL_TEXTURE_2D_ARRAY);

}

void SuperMarioBros::initSounds()
{
	ptrSoundManager = new SoundManager();
	ptrSoundManager->initBGM();
}

void SuperMarioBros::initUniforms()
{
}

void SuperMarioBros::initBuffers()
{
}

void SuperMarioBros::update()
{
	while (active)
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
				dynamic_cast<Mario *>(scenes[actualScene]->ptrObjects->entitiesArray[0])->leftButton = true;
				//scenes[actualScene]->ptrBackground->speedX = -1.0f;
				break;

			case SDLK_d:
				rightButton = true;
				dynamic_cast<Mario *>(scenes[actualScene]->ptrObjects->entitiesArray[0])->rightButton = true;
				//scenes[actualScene]->ptrBackground->speedX = 1.0f;
				break;

			case SDLK_w:
				dynamic_cast<Mario *>(scenes[actualScene]->ptrObjects->entitiesArray[0])->upButton = true;
				upButton = true;

				break;

			case SDLK_s:
				downButton = true;
				dynamic_cast<Mario *>(scenes[actualScene]->ptrObjects->entitiesArray[0])->downButton = true;

				break;

			case SDLK_x:
				scenes[actualScene]->ptrObjects->entitiesArray[0]->sprite[0]->textureID = 10;


				break;

			case SDLK_c:
				scenes[actualScene]->ptrObjects->entitiesArray[0]->sprite[0]->textureID = 14;

				break;

			case SDLK_y:
				break;

			case SDLK_k:
				bButton = true;
				dynamic_cast<Mario *>(scenes[actualScene]->ptrObjects->entitiesArray[0])->fireButton = true;
				break;

			case SDLK_l:
				aButton = true;
				dynamic_cast<Mario *>(scenes[actualScene]->ptrObjects->entitiesArray[0])->jumpButton = true;

				break;

			case SDLK_LEFT:
				scenes[actualScene]->ptrBackground->speedX = 1.0f;
				break;

			case SDLK_RIGHT:
				scenes[actualScene]->ptrBackground->speedX = -1.0f;
				break;


			case SDLK_UP:
				scenes[actualScene]->ptrBackground->speedY = -1.0f;
				break;

			case SDLK_DOWN:
				scenes[actualScene]->ptrBackground->speedY = 1.0f;
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
				dynamic_cast<Mario *>(scenes[actualScene]->ptrObjects->entitiesArray[0])->leftButton = false;
				scenes[actualScene]->ptrBackground->speedX = 0.0f;
				break;

			case SDLK_d:
				rightButton = false;
				dynamic_cast<Mario *>(scenes[actualScene]->ptrObjects->entitiesArray[0])->rightButton = false;
				scenes[actualScene]->ptrBackground->speedX = 0.0f;
				break;

			case SDLK_w:
				upButton = false;
				dynamic_cast<Mario *>(scenes[actualScene]->ptrObjects->entitiesArray[0])->upButton = false;
				break;

			case SDLK_s:
				downButton = false;
				dynamic_cast<Mario *>(scenes[actualScene]->ptrObjects->entitiesArray[0])->downButton = false;
				break;

			case SDLK_k:
				bButton = false;
				dynamic_cast<Mario *>(scenes[actualScene]->ptrObjects->entitiesArray[0])->fireButton = false;
				break;

			case SDLK_l:
				aButton = false;
				dynamic_cast<Mario *>(scenes[actualScene]->ptrObjects->entitiesArray[0])->jumpButton = false;
				break;

			case SDLK_RIGHT:
				scenes[actualScene]->ptrBackground->speedX = 0.0f;
				break;

			case SDLK_LEFT:
				scenes[actualScene]->ptrBackground->speedX = 0.0f;
				break;

			case SDLK_UP:
				scenes[actualScene]->ptrBackground->speedY = 0.0f;
				break;

			case SDLK_DOWN:
				scenes[actualScene]->ptrBackground->speedY = 0.0f;
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
