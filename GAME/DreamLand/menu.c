#include "menu.h"

int menu[22][42] =
{ { 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63 },
{63,4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 63},
{ 63,10, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 3, 63 },
{ 63,8, 56, 56, 56, 4, 2, 0, 0, 0, 0, 0, 0, 5, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 1, 63 },
{ 63,8, 56, 56, 56, 10, 56, 56, 56, 56, 56, 56, 56, 1, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 1, 63 },
{ 63,8, 56, 56, 56, 8, 56, 56, 56, 56, 56, 56, 56, 1, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 1, 63 },
{ 63,8, 56, 56, 56, 12, 11, 9, 9, 9, 9, 9, 9, 13, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 1, 63 },
{ 63,8, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 1, 63 },
{ 63,8, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 1, 63 },
{ 63,8, 56, 56, 56, 4, 2, 0, 0, 0, 0, 0, 0, 5, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 1, 63 },
{ 63,8, 56, 56, 56, 10, 56, 56, 56, 56, 56, 56, 56, 1, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 1, 63 },
{ 63,8, 56, 56, 56, 8, 56, 56, 56, 56, 56, 56, 56, 1, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 1 ,63 },
{ 63,8, 56, 56, 56, 12, 11, 9, 9, 9, 9, 9, 9, 13, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 1, 63 },
{ 63,8, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 1, 63 },
{ 63,8, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 1, 63 },
{ 63,8, 56, 56, 56, 4, 2, 0, 0, 0, 0, 0, 0, 5, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 1, 63 },
{ 63,8, 56, 56, 56, 10, 56, 56, 56, 56, 56, 56, 56, 1, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 1, 63 },
{ 63,8, 56, 56, 56, 8, 56, 56, 56, 56, 56, 56, 56, 1, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 1, 63 },
{ 63,8, 56, 56, 56, 12, 11, 9, 9, 9, 9, 9, 9, 13, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 1, 63 },
{ 63,8, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 1, 63 },
{ 63,12, 11, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 13, 63 },
{ 63,63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63 } };


sfTexture* texMenuBackground;
sfSprite* spMenuBackground;
sfIntRect irectMenuBackground = {0, 0, 32, 32};
sfVector2f scaleMenuBackground = {10, 10};



void initMenu()
{
	texMenuBackground = sfTexture_createFromFile(TEXTURE_PATH"tilesetMenu/tilesetMenu.png", NULL);
   	spMenuBackground = sfSprite_create(texMenuBackground);
	sfSprite_setTextureRect(spMenuBackground, irectMenuBackground);
	//sfSprite_setScale(spMenuBackground, scaleMenuBackground);
}

void updateMenu()
{
	sfSprite_setPosition(spMenuBackground, (sfVector2f) { 100, 100 });
	sfSprite_setScale(spMenuBackground, (sfVector2f) { 0.5, 0.5 });
}


void displayMenu(sfRenderWindow* _window)
{
	if (state == MENU) 
	{
		for (int y = 0; y < 22; y++)
		{
			for (int x = 0; x < 42; x++)
			{

				if (menu[y][x] < 8)
				{
					irectMenuBackground.position.x = menu[y][x] * irectMenuBackground.size.x;
					irectMenuBackground.position.y = 0;
				}
				if (menu[y][x] >= 8 && menu[y][x] < 16)
				{
					irectMenuBackground.position.x = (menu[y][x] - 8) * irectMenuBackground.size.x;
					irectMenuBackground.position.y = irectMenuBackground.size.y;
				}
				if (menu[y][x] >= 16 && menu[y][x] < 24)
				{
					irectMenuBackground.position.x = (menu[y][x] - 16) * irectMenuBackground.size.x;
					irectMenuBackground.position.y = irectMenuBackground.size.y * 2;
				}
				if (menu[y][x] >= 24 && menu[y][x] < 32)
				{
					irectMenuBackground.position.x = (menu[y][x] - 24) * irectMenuBackground.size.x;
					irectMenuBackground.position.y = irectMenuBackground.size.y * 3;
				}
				if (menu[y][x] >= 32 && menu[y][x] < 40)
				{
					irectMenuBackground.position.x = (menu[y][x] - 32) * irectMenuBackground.size.x;
					irectMenuBackground.position.y = irectMenuBackground.size.y * 4;
				}
				if (menu[y][x] >= 40 && menu[y][x] < 48)
				{
					irectMenuBackground.position.x = (menu[y][x] - 40) * irectMenuBackground.size.x;
					irectMenuBackground.position.y = irectMenuBackground.size.y * 5;
				}
				if (menu[y][x] >= 48 && menu[y][x] < 56)
				{
					irectMenuBackground.position.x = (menu[y][x] - 48) * irectMenuBackground.size.x;
					irectMenuBackground.position.y = irectMenuBackground.size.y * 6;
				}
				if (menu[y][x] >= 56 && menu[y][x] < 64)
				{
					irectMenuBackground.position.x = (menu[y][x] - 56) * irectMenuBackground.size.x;
					irectMenuBackground.position.y = irectMenuBackground.size.y * 7;
				}



				sfSprite_setTextureRect(spMenuBackground, irectMenuBackground);
				sfVector2f pos = { ((x * irectMenuBackground.size.x) / 2) + 305, ((y * irectMenuBackground.size.y) / 2) + 145 };
				sfSprite_setPosition(spMenuBackground, pos);
				sfRenderWindow_drawSprite(_window, spMenuBackground, NULL);

			}
		}
	}
	if (state == GAME) 
	{

	}

}


