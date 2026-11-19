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


int menuSettings[8][7] =
{	{ 63, 63, 32, 33, 34, 63, 63},
		{ 4, 0, 40, 41, 42, 0, 5},
		{ 10, 56, 56, 56, 56, 56, 3},
		{ 8, 56, 56, 56, 56, 56, 1},
		{ 8, 56, 56, 56, 56, 56, 1},
		{ 8, 56, 56, 56, 56, 56, 1},
		{ 8, 56, 56, 56, 56, 56, 1},
		{ 12, 11, 9, 9, 9, 9, 13}
};

int menuPause[9][8][2] =
{ { 63, 63, 32, 33, 34, 63, 63},
	{ 4, 0, 40, 41, 42, 0, 5},
	{ 10, 56, 56, 56, 56, 56, 3},
	{ 8, 56, 56, 56, 56, 56, 1},
	{ 8, 56, 56, 56, 56, 56, 1},
	{ 8, 56, 56, 56, 56, 56, 1},
	{ 8, 56, 56, 56, 56, 56, 1},
	{ 12, 11, 9, 9, 9, 9, 13}
};


sfTexture* texMenuBackground;
sfSprite* spMenuBackground;
sfIntRect irectMenuBackground = { 0, 0, 32, 32 };


sfTexture* texSettingsLogo;
sfSprite* spSettingsLogo;
sfIntRect irectSettingsLogo = { 0, 0, 24, 24 };


sfFont* fontMenu;
sfText* playText;
sfText* editorText;
sfText* quitterText;
sfText* gameNameText;
sfTexture* texSettingsButtonPressed;
sfSprite* spSettingsButton;
sfIntRect irectSettingsButton = { 32 * 4, 32 * 3, 32, 32 };
sfVector2f scaleTextMenu = { 0.3, 0.3 };




sfTexture* texButtonPM;


sfSprite* spPlayButtonPM;
sfIntRect irectPlayButtonPM = { 308, 96, 197, 47 };
sfSprite* spSettingsButtonPM;
sfIntRect irectSettingsButtonPM = { 58, 24, 197, 47 };
sfSprite* spRetourButtonPM;
sfIntRect irectRetourButtonPM = { 0, 0, 197, 47 };
sfSprite* spQuitterButtonPM;
sfIntRect irectQuitterButtonPM = { 0, 0, 197, 47 };

float butonPressedTimer = 0.0f;

void initMenu()
{
	texMenuBackground = sfTexture_createFromFile(TEXTURE_PATH"tilesetMenu/tilesetMenu.png", NULL);
	spMenuBackground = sfSprite_create(texMenuBackground);
	sfSprite_setTextureRect(spMenuBackground, irectMenuBackground);
	sfSprite_setPosition(spMenuBackground, (sfVector2f) { 100, 100 });
	sfSprite_setScale(spMenuBackground, (sfVector2f) { 0.5, 0.5 });


	texSettingsLogo = sfTexture_createFromFile(TEXTURE_PATH"tilesetMenu/logoSettings.png", NULL);
	spSettingsLogo = sfSprite_create(texSettingsLogo);
	sfSprite_setTextureRect(spSettingsLogo, irectSettingsLogo);
	sfSprite_setPosition(spSettingsLogo, (sfVector2f) { 900, 425 });
	sfSprite_setScale(spSettingsLogo, (sfVector2f) { 1.2, 1.2 });


	fontMenu = sfFont_createFromFile(FONT_PATH"fontMenu.ttf");

	playText = sfText_create(fontMenu);
	sfText_setString(playText, "JOUER");
	sfText_setCharacterSize(playText, 100);
	sfText_scale(playText, scaleTextMenu);
	sfText_setPosition(playText, (sfVector2f) { 415, 205 });

	editorText = sfText_create(fontMenu);
	sfText_setString(editorText, "EDITER");
	sfText_setCharacterSize(editorText, 100);
	sfText_scale(editorText, scaleTextMenu);
	sfText_setPosition(editorText, (sfVector2f) { 413, 300 });

	quitterText = sfText_create(fontMenu);
	sfText_setString(quitterText, "QUITTER");
	sfText_setCharacterSize(quitterText, 100);
	sfText_scale(quitterText, scaleTextMenu);
	sfText_setPosition(quitterText, (sfVector2f) { 400, 397 });

	gameNameText = sfText_create(fontMenu);
	sfText_setString(gameNameText, " BLOODY\nBLOODLINE");
	sfText_setCharacterSize(gameNameText, 100);
	sfText_scale(gameNameText, scaleTextMenu);
	sfText_setPosition(gameNameText, (sfVector2f) { 600, 205 });

	texSettingsButtonPressed = sfTexture_createFromFile(TEXTURE_PATH"tilesetMenu/caillou.png", NULL);
	spSettingsButton = sfSprite_create(texMenuBackground);
	sfSprite_setTextureRect(spSettingsButton, irectSettingsButton);
	sfSprite_setPosition(spSettingsButton, (sfVector2f) { 890, 415 });
	sfSprite_setScale(spSettingsButton, (sfVector2f) { 1.5, 1.5 });


	texButtonPM = sfTexture_createFromFile(TEXTURE_PATH"tilesetMenu/buttonPM.png", NULL);

	texSettingsButtonPressed = sfTexture_createFromFile(TEXTURE_PATH"tilesetMenu/caillou.png", NULL);
	spPlayButtonPM = sfSprite_create(texButtonPM);
	sfSprite_setTextureRect(spPlayButtonPM, irectPlayButtonPM);
	sfSprite_setPosition(spPlayButtonPM, (sfVector2f) { 500, 215 });
	sfSprite_setScale(spPlayButtonPM, (sfVector2f) { 1.5, 1.5 });



}

void initPauseMenu()
{
	
	 

	/*
	-play
	-parametre
	-retour menu
	-quitter
	*/


}

void initSettings()
{
	/*
	-volume jeu
	-volume music
	-volume sfx
	_bind touche
	*/

}

void updateMenu(sfRenderWindow* _window)
{
	sfVector2i mousePos = sfMouse_getPosition(_window);
	//printf("%d %d\n", mousePos.x, mousePos.y);

	butonPressedTimer += getDeltaTime();

	sfText_setOutlineThickness(playText, 0);
	sfText_setOutlineThickness(editorText, 0);
	sfText_setOutlineThickness(quitterText, 0);


	if (mousePos.x > 385 && mousePos.x < 528 && mousePos.y > 193 && mousePos.y < 256)
	{
		sfText_setOutlineThickness(playText, 15);
		if (sfMouse_isButtonPressed(sfMouseLeft) && butonPressedTimer > 0.2f)
		{
			butonPressedTimer = 0.0f;
			state = GAME;
		}
	}

	if (mousePos.x > 385 && mousePos.x < 528 && mousePos.y > 289 && mousePos.y < 352)
	{
		sfText_setOutlineThickness(editorText, 15);
		if(sfMouse_isButtonPressed(sfMouseLeft) && butonPressedTimer > 0.2f)
		{
			butonPressedTimer = 0.0f;
			state = EDITOR;
		}
	}

	if (mousePos.x > 385 && mousePos.x < 528 && mousePos.y > 385 && mousePos.y < 448)
	{
		sfText_setOutlineThickness(quitterText, 15);
		if (sfMouse_isButtonPressed(sfMouseLeft) && butonPressedTimer > 0.2f)
		{
			butonPressedTimer = 0.0f;
			sfRenderWindow_close(_window);
		}
	}

	if (mousePos.x > 890 && mousePos.x < 938 && mousePos.y > 415 && mousePos.y < 462)
	{
		sfSprite_setTexture(spSettingsButton, texSettingsButtonPressed, NULL);
		sfSprite_setTextureRect(spSettingsButton, (sfIntRect){0, 0, 32, 32});
		if(sfMouse_isButtonPressed(sfMouseLeft) && butonPressedTimer > 0.2f)
		{
			butonPressedTimer = 0.0f;
			state = SETTINGS;
		}
	}
	else
	{
		sfSprite_setTexture(spSettingsButton, texMenuBackground, NULL);
		sfSprite_setTextureRect(spSettingsButton, irectSettingsButton);
	}
}

void updateSettings(sfRenderWindow* window)
{











}








void displayMenu(sfRenderWindow* _window)
{
	sfRenderWindow_setMouseCursorVisible(_window, true);
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
		


		sfRenderWindow_drawSprite(_window, spSettingsButton, NULL);
		sfRenderWindow_drawSprite(_window, spSettingsLogo, NULL);
		sfRenderWindow_drawText(_window, playText, NULL);
		sfRenderWindow_drawText(_window, editorText, NULL);
		sfRenderWindow_drawText(_window, quitterText, NULL);
		sfRenderWindow_drawText(_window, gameNameText, NULL);

		sfRenderWindow_drawSprite(_window, spPlayButtonPM, NULL);


	}

	if (state == SETTINGS)
	{
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 7; x++)
			{

				if (menuSettings[y][x] < 8)
				{
					irectMenuBackground.position.x = menuSettings[y][x] * irectMenuBackground.size.x;
					irectMenuBackground.position.y = 0;
				}
				if (menuSettings[y][x] >= 8 && menuSettings[y][x] < 16)
				{
					irectMenuBackground.position.x = (menuSettings[y][x] - 8) * irectMenuBackground.size.x;
					irectMenuBackground.position.y = irectMenuBackground.size.y;
				}
				if (menuSettings[y][x] >= 16 && menuSettings[y][x] < 24)
				{
					irectMenuBackground.position.x = (menuSettings[y][x] - 16) * irectMenuBackground.size.x;
					irectMenuBackground.position.y = irectMenuBackground.size.y * 2;
				}
				if (menuSettings[y][x] >= 24 && menuSettings[y][x] < 32)
				{
					irectMenuBackground.position.x = (menuSettings[y][x] - 24) * irectMenuBackground.size.x;
					irectMenuBackground.position.y = irectMenuBackground.size.y * 3;
				}
				if (menuSettings[y][x] >= 32 && menuSettings[y][x] < 40)
				{
					irectMenuBackground.position.x = (menuSettings[y][x] - 32) * irectMenuBackground.size.x;
					irectMenuBackground.position.y = irectMenuBackground.size.y * 4;
				}
				if (menuSettings[y][x] >= 40 && menuSettings[y][x] < 48)
				{
					irectMenuBackground.position.x = (menuSettings[y][x] - 40) * irectMenuBackground.size.x;
					irectMenuBackground.position.y = irectMenuBackground.size.y * 5;
				}
				if (menuSettings[y][x] >= 48 && menuSettings[y][x] < 56)
				{
					irectMenuBackground.position.x = (menuSettings[y][x] - 48) * irectMenuBackground.size.x;
					irectMenuBackground.position.y = irectMenuBackground.size.y * 6;
				}
				if (menuSettings[y][x] >= 56 && menuSettings[y][x] < 64)
				{
					irectMenuBackground.position.x = (menuSettings[y][x] - 56) * irectMenuBackground.size.x;
					irectMenuBackground.position.y = irectMenuBackground.size.y * 7;
				}



				sfSprite_setTextureRect(spMenuBackground, irectMenuBackground);
				sfVector2f pos = { ((x * irectMenuBackground.size.x) + 205) * 2, ((y * irectMenuBackground.size.y) + 20) * 2 };
				sfSprite_setPosition(spMenuBackground, pos);
				sfSprite_setScale(spMenuBackground, (sfVector2f) { 2, 2 });
				sfRenderWindow_drawSprite(_window, spMenuBackground, NULL);


			}

		}
	}
	if (state == PAUSE_MENU)
	{
		
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 7; x++)
			{

				if (menuSettings[y][x] < 8)
				{
					irectMenuBackground.position.x = menuSettings[y][x] * irectMenuBackground.size.x;
					irectMenuBackground.position.y = 0;
				}
				if (menuSettings[y][x] >= 8 && menuSettings[y][x] < 16)
				{
					irectMenuBackground.position.x = (menuSettings[y][x] - 8) * irectMenuBackground.size.x;
					irectMenuBackground.position.y = irectMenuBackground.size.y;
				}
				if (menuSettings[y][x] >= 16 && menuSettings[y][x] < 24)
				{
					irectMenuBackground.position.x = (menuSettings[y][x] - 16) * irectMenuBackground.size.x;
					irectMenuBackground.position.y = irectMenuBackground.size.y * 2;
				}
				if (menuSettings[y][x] >= 24 && menuSettings[y][x] < 32)
				{
					irectMenuBackground.position.x = (menuSettings[y][x] - 24) * irectMenuBackground.size.x;
					irectMenuBackground.position.y = irectMenuBackground.size.y * 3;
				}
				if (menuSettings[y][x] >= 32 && menuSettings[y][x] < 40)
				{
					irectMenuBackground.position.x = (menuSettings[y][x] - 32) * irectMenuBackground.size.x;
					irectMenuBackground.position.y = irectMenuBackground.size.y * 4;
				}
				if (menuSettings[y][x] >= 40 && menuSettings[y][x] < 48)
				{
					irectMenuBackground.position.x = (menuSettings[y][x] - 40) * irectMenuBackground.size.x;
					irectMenuBackground.position.y = irectMenuBackground.size.y * 5;
				}
				if (menuSettings[y][x] >= 48 && menuSettings[y][x] < 56)
				{
					irectMenuBackground.position.x = (menuSettings[y][x] - 48) * irectMenuBackground.size.x;
					irectMenuBackground.position.y = irectMenuBackground.size.y * 6;
				}
				if (menuSettings[y][x] >= 56 && menuSettings[y][x] < 64)
				{
					irectMenuBackground.position.x = (menuSettings[y][x] - 56) * irectMenuBackground.size.x;
					irectMenuBackground.position.y = irectMenuBackground.size.y * 7;
				}



				sfSprite_setTextureRect(spMenuBackground, irectMenuBackground);
				sfVector2f pos = { ((x * irectMenuBackground.size.x) + 205) * 2, ((y * irectMenuBackground.size.y) + 20) * 2 };
				sfSprite_setPosition(spMenuBackground, pos);
				sfSprite_setScale(spMenuBackground, (sfVector2f) { 2, 2 });
				sfRenderWindow_drawSprite(_window, spMenuBackground, NULL);

				
			}
		}








	}

}


