#include "pnj.h"

sfTexture* texPNJ;
sfSprite* spPNJ;
sfIntRect irectPNJ = { 0, 0, 64, 64 };
sfVector2f positionPNJ = {30.0f, 30.0f};

sfText* dialogue;
sfFont* font;
sfTexture* texDialogue;
sfSprite* spDialogue;
sfIntRect irectDialogue = { 0, 0, 64, 64 };


void initPNJ()
{
	texPNJ = sfTexture_createFromFile(TEXTURE_PATH"tilesetPNJ/sbire_idle.png", NULL);
	spPNJ = sfSprite_create(texPNJ);
	sfSprite_setTextureRect(spPNJ, irectPNJ);
	sfSprite_setPosition(spPNJ, positionPNJ);





	font = sfFont_createFromFile(FONT_PATH"Crimson_Horror_One.ttf");
	dialogue = sfText_create(font);
	sfText_setString(dialogue, "HELLO WORLD!!!");
	sfText_setCharacterSize(dialogue, 20);


	texDialogue = sfTexture_createFromFile(FONT_PATH"dialogue_text.png", NULL);
	spDialogue = sfSprite_create(texDialogue);
	sfSprite_setTextureRect(spDialogue, irectDialogue);
}

void updatePNJ() 
{
	sfText_setPosition(dialogue, (sfVector2f) { posView.x - 80, posView.y + 50 });
	sfSprite_setPosition(spDialogue, (sfVector2f) { posView.x - 80, posView.y + 50 });
}



void displayPNJ(sfRenderWindow* _window)
{
	sfRenderWindow_drawText(_window, dialogue, NULL);
	sfRenderWindow_drawSprite(_window, spDialogue, NULL);
	sfRenderWindow_drawSprite(_window, spPNJ, NULL);
}