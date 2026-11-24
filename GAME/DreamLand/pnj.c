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

isTalking = false;

float pnjTimer = 0.0f;
int dialog = 0;

void initPNJ()
{
	texPNJ = sfTexture_createFromFile(TEXTURE_PATH"tilesetPNJ/sbire_idle.png", NULL);
	spPNJ = sfSprite_create(texPNJ);
	sfSprite_setTextureRect(spPNJ, irectPNJ);
	sfSprite_setPosition(spPNJ, positionPNJ);


	font = sfFont_createFromFile(FONT_PATH"fontPNJ.ttf");
	text = sfText_create(font);
	sfText_setCharacterSize(text, 100);
	sfText_scale(text, scaleText);


	texDialogue = sfTexture_createFromFile(TEXTURE_PATH"dialogue_text.png", NULL);
	spDialogue = sfSprite_create(texDialogue);
	sfSprite_setTextureRect(spDialogue, irectDialogue);
	sfSprite_setScale(spDialogue, scaleDialogue);
}

void updatePNJ() 
{
	if (state == GAME)
	{
		pnjTimer += getDeltaTime();

		// interactions avec le pnj pour initier le dialogue
		if (sfKeyboard_isScancodePressed(sfScanF) && pnjTimer > 0.2f)
		{
			pnjTimer = 0.0f;
			isTalking = true;
			if (dialog == 0)
				dialog = 1;
		}

		if(isTalking)
			

		// continue le dialogue une fois qu'il a était initié et le remet à zéro pour pouvoir relancer le dialogue
		if (sfKeyboard_isScancodePressed(sfScanEnter) && pnjTimer > 0.2f && isTalking)
		{
			pnjTimer = 0.0f;
			if (dialog >= 1)
				dialog++;
			if (dialog > 4)
			{
				dialog = 0;
				isTalking = false;
			}

		}
	}
	sfText_setPosition(text, (sfVector2f) { posView.x - 60, posView.y + 40 });
	sfSprite_setPosition(spDialogue, (sfVector2f) { posView.x - 70, posView.y + 10 });
}

void afficher_lettre_par_lettre(const char* str) {
	if (!str) return;

	for (size_t i = 0; str[i] != '\0'; i++) {
		printf("%c\n", str[i]);
	}
}

void displayPNJ(sfRenderWindow* _window)
{
	/////////////////////////////////////////////////////
	////                DIALOGUE PNJ                 ////
	/////////////////////////////////////////////////////

	if(isTalking && dialog == 1)
	{
		sfText_setString(text, "Je m'appelle Upir. \nje ne te veux aucun mal.\nje suis l\x00E1 pour t'aider.");
		sfRenderWindow_drawSprite(_window, spDialogue, NULL);
		sfRenderWindow_drawText(_window, text, NULL);
	}

	if (isTalking && dialog == 2)
	{
		sfText_setString(text, "Dracula m'a enferm\x00E8 ici\ncar je m'opposais \n\x00E1 son plan.");
		sfRenderWindow_drawSprite(_window, spDialogue, NULL);
		sfRenderWindow_drawText(_window, text, NULL);
	}

	if (isTalking && dialog == 3)
	{
		sfText_setString(text, "Nous nous trouvons \nretenus sous son\nch\x00E2teau.");
		sfRenderWindow_drawSprite(_window, spDialogue, NULL);
		sfRenderWindow_drawText(_window, text, NULL);
	}

	if (isTalking && dialog == 4)
	{
		sfText_setString(text, "Trouve les rituels \n\x00E8parpill\x00E8s dans la cave \npour sortir d'ici.");
		sfRenderWindow_drawSprite(_window, spDialogue, NULL);
		sfRenderWindow_drawText(_window, text, NULL);
	}

	sfRenderWindow_drawSprite(_window, spPNJ, NULL);
}