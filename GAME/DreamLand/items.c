#include "items.h"

extern 

void initsItems()
{
	sfTexture* keyTex = sfTexture_createFromFile(ITEMS_PATH"key.png", NULL);
	for (int i = 0; i < 4; i++)
	{
		keys[i].sprite = sfSprite_create(keyTex);
		keys[i].position = (sfVector2f){ 0.0f, 0.0f };
		keys[i].hasItem = false;

		sfSprite_setTextureRect(keys[i].sprite, (sfIntRect) { 0, 0, 28 ,32 });
		sfSprite_setColor(keys[i].sprite, (sfColor){255, 255, 255, 80});
		sfSprite_setScale(keys[i].sprite, (sfVector2f) { 0.4, 0.4 });

	}





}

void updateItems()
{

	for (int i = 0; i < 4; i++)
	{
		if (keys[i].hasItem)
			sfSprite_setColor(keys[i].sprite, (sfColor) { 255, 255, 255, 255 });

		sfSprite_setPosition(keys[i].sprite, (sfVector2f) { posView.x-158 + 15*i , posView.y + 65  });
	}



}

void displayItems(sfRenderWindow* _window)
{
	for (int i = 0; i < 4; i++)
		sfRenderWindow_drawSprite(_window, keys[i].sprite, NULL);


}
