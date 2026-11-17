#include "pnj.h"

sfTexture* texPNJ;
sfSprite* spPNJ;
sfIntRect irectPNJ = { 0, 0, 64, 64 };
sfVector2f positionPNJ = {30.0f, 30.0f};

sfText* text;
sfFont* font;
sfVector2f scaleText = { 0.1, 0.1 };

sfTexture* texDialogue;
sfSprite* spDialogue;
sfIntRect irectDialogue = { 0, 0, 10000, 10000 };
sfVector2f scaleDialogue = { 0.125, 0.08 };

void initPNJ()
{
	texPNJ = sfTexture_createFromFile(TEXTURE_PATH"tilesetPNJ/sbire_idle.png", NULL);
	spPNJ = sfSprite_create(texPNJ);
	sfSprite_setTextureRect(spPNJ, irectPNJ);
	sfSprite_setPosition(spPNJ, positionPNJ);





	font = sfFont_createFromFile(FONT_PATH"fontPNJ.ttf");
	text = sfText_create(font);
	sfText_setString(text, "HELLO WORLD!!!");
	sfText_setCharacterSize(text, 100);
	sfText_scale(text, scaleText);


	texDialogue = sfTexture_createFromFile(TEXTURE_PATH"dialogue_text.png", NULL);
	spDialogue = sfSprite_create(texDialogue);
	sfSprite_setTextureRect(spDialogue, irectDialogue);
	sfSprite_setScale(spDialogue, scaleDialogue);
}

void updatePNJ() 
{
	sfText_setPosition(text, (sfVector2f) { posView.x - 60, posView.y + 40 });
	sfSprite_setPosition(spDialogue, (sfVector2f) { posView.x - 70, posView.y + 10 });
}



void displayPNJ(sfRenderWindow* _window)
{
	sfRenderWindow_drawSprite(_window, spDialogue, NULL);
	sfRenderWindow_drawSprite(_window, spPNJ, NULL);
	sfRenderWindow_drawText(_window, text, NULL);
}