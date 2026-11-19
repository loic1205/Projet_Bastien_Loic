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

// inits sprite background fenêtre de jeu state = MENU
sfTexture* texBackground_MenuWindow;
sfSprite* spBackground_MenuWindow;
sfIntRect irectBackground_MenuWindow = { 0, 0, 1200, 700 };




// inits sprite fenêtre de jeu state = PAUSE_MENU

sfTexture* texButtonPM;
sfTexture* texButtonPressedPM;
sfIntRect irectButtonPM = { 0, 0, 690, 260 };
sfFont* font;

sfSprite* spPlayButtonPM;
sfSprite* spSettingsButtonPM;
sfSprite* spMenuButtonPM;
sfSprite* spLeaveButtonPM;

sfText* textPlayButtonPM;
sfText* textSettingsButtonPM;
sfText* textMenuButtonPM;
sfText* textLeaveButtonPM;



// inits sprite fenêtre de jeu state = SETTINGS

sfSprite* spMenuButtonSM;
sfText* textSettingsButtonSM;


// inits des musique du menu

sfMusic* musiqueMenu;




float butonPressedTimer = 0.0f;

void initMenu()
{
	// background de la fenêtre de jeu dans le state MENU
	texBackground_MenuWindow = sfTexture_createFromFile(TEXTURE_PATH"background/background_menu.jpg", NULL);
	spBackground_MenuWindow = sfSprite_create(texBackground_MenuWindow);
	sfSprite_setTextureRect(spBackground_MenuWindow, irectBackground_MenuWindow);
	sfSprite_setScale(spBackground_MenuWindow, (sfVector2f) { 1.1, 1.1 });


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


	texButtonPM = sfTexture_createFromFile(TEXTURE_PATH"tilesetMenu/ButtonPM.png", NULL);
	texButtonPressedPM = sfTexture_createFromFile(TEXTURE_PATH"tilesetMenu/ButtonPressedPM.png", NULL);
	font = sfFont_createFromFile(FONT_PATH"fontMenu.ttf");
	
	spPlayButtonPM = sfSprite_create(texButtonPM);
	sfSprite_setTextureRect(spPlayButtonPM, irectButtonPM);
	sfSprite_setPosition(spPlayButtonPM, (sfVector2f) { 547, 175 });
	sfSprite_setScale(spPlayButtonPM, (sfVector2f) { 0.25, 0.25 });

	textPlayButtonPM = sfText_create(font);
	sfText_setString(textPlayButtonPM, "JOUER");
	sfText_setPosition(textPlayButtonPM, (sfVector2f){ 592, 182 });
	sfText_setFillColor(textPlayButtonPM, (sfColor){0, 0, 0, 255});




	spSettingsButtonPM = sfSprite_create(texButtonPM);
	sfSprite_setTextureRect(spSettingsButtonPM, irectButtonPM);
	sfSprite_setPosition(spSettingsButtonPM, (sfVector2f) { 547, 260 });
	sfSprite_setScale(spSettingsButtonPM, (sfVector2f) { 0.25, 0.25 });

	textSettingsButtonPM = sfText_create(font);
	sfText_setString(textSettingsButtonPM, "PARAMETRE");
	sfText_setPosition(textSettingsButtonPM, (sfVector2f) { 570, 272 });
	sfText_setFillColor(textSettingsButtonPM, (sfColor) { 0, 0, 0, 255 });
	sfText_setScale(textSettingsButtonPM, (sfVector2f) { 0.8, 0.8});



	spMenuButtonPM = sfSprite_create(texButtonPM);
	sfSprite_setTextureRect(spMenuButtonPM, irectButtonPM);
	sfSprite_setPosition(spMenuButtonPM, (sfVector2f) { 547, 345});
	sfSprite_setScale(spMenuButtonPM, (sfVector2f) { 0.25, 0.25 });

	textMenuButtonPM = sfText_create(font);
	sfText_setString(textMenuButtonPM, "MENU");
	sfText_setPosition(textMenuButtonPM, (sfVector2f) { 597, 352 });
	sfText_setFillColor(textMenuButtonPM, (sfColor) { 0, 0, 0, 255 });




	spLeaveButtonPM = sfSprite_create(texButtonPM);
	sfSprite_setTextureRect(spLeaveButtonPM, irectButtonPM);
	sfSprite_setPosition(spLeaveButtonPM, (sfVector2f) { 547, 430 });
	sfSprite_setScale(spLeaveButtonPM, (sfVector2f) { 0.25, 0.25 });

	textLeaveButtonPM = sfText_create(font);
	sfText_setString(textLeaveButtonPM, "QUITTER");
	sfText_setPosition(textLeaveButtonPM, (sfVector2f) { 578, 437 });
	sfText_setFillColor(textLeaveButtonPM, (sfColor) { 0, 0, 0, 255 });







	

	spMenuButtonSM = sfSprite_create(texButtonPM);
	sfSprite_setTextureRect(spMenuButtonSM, irectButtonPM);
	sfSprite_setPosition(spMenuButtonSM, (sfVector2f) { 547, 430 });
	sfSprite_setScale(spMenuButtonSM, (sfVector2f) { 0.25, 0.25 });

	textSettingsButtonSM = sfText_create(font);
	sfText_setString(textSettingsButtonSM, "MENU");
	sfText_setPosition(textSettingsButtonSM, (sfVector2f) { 597, 437 });
	sfText_setFillColor(textSettingsButtonSM, (sfColor) { 0, 0, 0, 255 });


	//inits musique

	musiqueMenu = sfMusic_createFromFile(SOUND_PATH"music/musicMenu.mp3");
	sfMusic_setLooping(musiqueMenu, true);
	sfMusic_setVolume(musiqueMenu, 10.0f);

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
	//musique

	if (sfMusic_getStatus(musiqueMenu) != sfPlaying)
		sfMusic_play(musiqueMenu);







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

void updatePauseMenu(sfRenderWindow* _window)
{

	sfVector2i mousePos = sfMouse_getPosition(_window);
	butonPressedTimer += getDeltaTime();


	/*if (sfMouse_isButtonPressed(sfMouseLeft) && butonPressedTimer > 0.2f)
	{
		printf("%d %d\n", mousePos.x, mousePos.y);
		butonPressedTimer = 0.0f;
	}*/


	sfText_setOutlineThickness(textPlayButtonPM, 0);
	sfText_setOutlineThickness(textSettingsButtonPM, 0);
	sfText_setOutlineThickness(textMenuButtonPM, 0);
	sfText_setOutlineThickness(textLeaveButtonPM, 0);


	if (mousePos.x > 547 && mousePos.x < 719 && mousePos.y > 175 && mousePos.y < 240 && sfMouse_isButtonPressed(sfMouseLeft) && butonPressedTimer > 0.2f)
	{
		butonPressedTimer = 0.0f;
		state = GAME;
	}

	if (mousePos.x > 547 && mousePos.x < 719 && mousePos.y > 260 && mousePos.y < 325 && sfMouse_isButtonPressed(sfMouseLeft) && butonPressedTimer > 0.2f)
	{
		butonPressedTimer = 0.0f;
		state = SETTINGS;
	}

	if (mousePos.x > 547 && mousePos.x < 719 && mousePos.y > 345 && mousePos.y < 410 && sfMouse_isButtonPressed(sfMouseLeft) && butonPressedTimer > 0.2f)
	{
		butonPressedTimer = 0.0f;
		state = MENU;
	}

	if (mousePos.x > 547 && mousePos.x < 719 && mousePos.y > 430 && mousePos.y < 495 && sfMouse_isButtonPressed(sfMouseLeft) && butonPressedTimer > 0.2f)
	{
		butonPressedTimer = 0.0f;
		sfRenderWindow_close(_window);
	}
}

void updateSettings(sfRenderWindow* _window)
{

	sfVector2i mousePos = sfMouse_getPosition(_window);
	butonPressedTimer += getDeltaTime();

	sfSprite_setTexture(spMenuButtonSM, texButtonPM, NULL);

	
	if (mousePos.x > 547 && mousePos.x < 719 && mousePos.y > 430 && mousePos.y < 495)
	{
		sfSprite_setTexture(spMenuButtonSM, texButtonPressedPM, NULL);
		if (sfMouse_isButtonPressed(sfMouseLeft) && butonPressedTimer > 0.2f)
		{
			butonPressedTimer = 0.0f;
			state = MENU;
		}
	}

}


void displayBackground(sfRenderWindow* _window)
{
	// dessine le background de la fenêtre de jeu dans le Menu
	sfRenderWindow_drawSprite(_window, spBackground_MenuWindow, NULL);
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
				sfSprite_setScale(spMenuBackground, (sfVector2f) { 0.5, 0.5 });
				sfRenderWindow_drawSprite(_window, spMenuBackground, NULL);
			}
		}
		


		sfRenderWindow_drawSprite(_window, spSettingsButton, NULL);
		sfRenderWindow_drawSprite(_window, spSettingsLogo, NULL);
		sfRenderWindow_drawText(_window, playText, NULL);
		sfRenderWindow_drawText(_window, editorText, NULL);
		sfRenderWindow_drawText(_window, quitterText, NULL);
		sfRenderWindow_drawText(_window, gameNameText, NULL);



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
		sfRenderWindow_drawSprite(_window, spMenuButtonSM, NULL);
		sfRenderWindow_drawText(_window, textSettingsButtonSM, NULL);
		

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

		sfRenderWindow_drawSprite(_window, spPlayButtonPM, NULL);
		sfRenderWindow_drawText(_window, textPlayButtonPM, NULL);
		sfRenderWindow_drawSprite(_window, spSettingsButtonPM, NULL);
		sfRenderWindow_drawText(_window, textSettingsButtonPM, NULL);
		sfRenderWindow_drawSprite(_window, spMenuButtonPM, NULL);
		sfRenderWindow_drawText(_window, textMenuButtonPM, NULL);
		sfRenderWindow_drawSprite(_window, spLeaveButtonPM, NULL);
		sfRenderWindow_drawText(_window, textLeaveButtonPM, NULL);
	}

}


