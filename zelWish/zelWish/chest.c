#include "chest.h"
Chest chest[20];



void initChest()
{
	for (int i = 0; i < sizeof(chest) / sizeof(chest[0]); i++)
	{
		chest[i].texChest = sfTexture_createFromFile(TEXTURE_PATH"coffre32.png", NULL);
		chest[i].spChest = sfSprite_create(chest[i].texChest);
		sfSprite_setTextureRect(chest[i].spChest, chest[i].irectChest);
	}
}

void updateChest()
{
	
	for (int i = 0; i < sizeof(chest) / sizeof(chest[0]); i++)
	{
		chest[i].ChestanimTimer += getDeltaTime();


		if(!chest[i].isOpen && chest[i].coo.x)
		{
			if (chest[i].ChestanimTimer > 0.20f)
			{
				chest[i].ChestframeX++;
				chest[i].ChestanimTimer = 0.0f;
			}
			if (chest[i].ChestframeX == 3)
			{
				chest[i].ChestframeX = 3;
				chest[i].isOpen = true;
			}
			sfSprite_setPosition(chest[i].spChest, chest[i].position);
		}
	}
}

void displayChest(sfRenderWindow* _window)
{

	for (int i = 0; i < sizeof(chest) / sizeof(chest[0]); i++)
	{
			chest[i].irectChest.position.x = chest[i].ChestframeX * chest[i].irectChest.size.x;
			sfSprite_setTextureRect(chest[i].spChest, chest[i].irectChest);
			sfRenderWindow_drawSprite(_window, chest[i].spChest, NULL);
	}
}
