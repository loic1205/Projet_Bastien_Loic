#include "pnj.h"
#include <string.h>

sfTexture* texPNJ;
sfSprite* spPNJ;
sfIntRect irectPNJ = { 0, 0, 64, 64};
sfVector2f positionPNJ = {30.0f, 30.0f};
sfRectangleShape* hb_PNJ;

sfText* text;
sfFont* font;
sfVector2f scaleText = { 0.1, 0.1 };

sfTexture* texDialogue;
sfSprite* spDialogue;
sfIntRect irectDialogue = { 0, 0, 10000, 10000 };
sfVector2f scaleDialogue = { 0.125, 0.08 };

#define TYPE_SPEED 20.0f // lettres par seconde 

float typeTimer = 0.0f;  // temps écoulé depuis le début de la réplique
int lastDialog = 0;      // réplique de la frame précédente (pour détecter un changement)


float pnjTimer = 0.0f;
int dialog = 0;

// texte dit par le PNJ (tableau pour utiliser strlen et faire un décompte de chaque lettres)
static const char* lines[5] =
{
	"",
	"Je m'appelle Upir. \nje ne te veux aucun mal.\nje suis l\x00E1 pour t'aider.",
	"Dracula m'a enferm\x00E8 ici\ncar je m'opposais \n\x00E1 son plan.",
	"Nous nous trouvons \nretenus sous son\nch\x00E2teau.",
	"Trouve les rituels \n\x00E8parpill\x00E8s dans la cave \npour sortir d'ici."
};

void initPNJ()
{
	// init du PNJ
	texPNJ = sfTexture_createFromFile(TEXTURE_PATH"tilesetPNJ/sbire_idle.png", NULL);
	spPNJ = sfSprite_create(texPNJ);
	sfSprite_setTextureRect(spPNJ, irectPNJ);
	sfSprite_setPosition(spPNJ, positionPNJ);
	hb_PNJ = sfRectangleShape_create(); // hitbox du PNJ
	sfRectangleShape_setPosition(hb_PNJ, positionPNJ); // place la hitbox du PNJ sur le sprite du PNJ
	sfRectangleShape_setTextureRect(hb_PNJ, irectPNJ);
	sfRectangleShape_setOutlineColor(hb_PNJ, sfRed);
	sfRectangleShape_setOutlineThickness(hb_PNJ, 10.0f);

	// init du texte
	font = sfFont_createFromFile(FONT_PATH"fontPNJ.ttf");
	text = sfText_create(font);
	sfText_setCharacterSize(text, 100);
	sfText_scale(text, scaleText);

	// init de la bulle de dialogue
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
		if (sfKeyboard_isScancodePressed(sfScanF) && pnjTimer > 0.2f && abs(position.x - positionPNJ.x) <= 20 && abs(position.y - positionPNJ.y) <= 20)
		{
			pnjTimer = 0.0f;
			isTalking = true;
			if (dialog == 0)
				dialog = 1;
		}			

		// continue le dialogue une fois qu'il a était initié et le remet à zéro pour pouvoir relancer le dialogue
		if (sfKeyboard_isScancodePressed(sfScanEnter) && pnjTimer > 0.2f && isTalking)
		{
			pnjTimer = 0.0f;

			int total = (int)strlen(lines[dialog]);
			if ((int)(typeTimer * TYPE_SPEED) < total)
			{
				typeTimer = total / TYPE_SPEED; 
			}
			else
			{
				dialog++;
				if (dialog > 4)
				{
					dialog = 0;
					isTalking = false;
				}
			}
		}
		sfSprite_setPosition(spPNJ, positionPNJ);
	}

	// nouvelle réplique : on repart de zéro
	if (dialog != lastDialog)
	{
		typeTimer = 0.0f;
		lastDialog = dialog;
	}
	if (isTalking)
		typeTimer += getDeltaTime();

	sfText_setPosition(text, (sfVector2f) { posView.x - 60, posView.y + 40 });
	sfSprite_setPosition(spDialogue, (sfVector2f) { posView.x - 70, posView.y + 10 });
}

void displayPNJ(sfRenderWindow* _window)
{
	/////////////////////////////////////////////////////
	////                DIALOGUE PNJ                 ////
	/////////////////////////////////////////////////////

	if (isTalking && dialog >= 1 && dialog <= 4)
	{
		static char buffer[256];

		int total = (int)strlen(lines[dialog]);
		int shown = (int)(typeTimer * TYPE_SPEED);
		if (shown > total) shown = total;

		memcpy(buffer, lines[dialog], shown); //  memcpy( copy, array, length )
		buffer[shown] = '\0';

		sfText_setString(text, buffer);
		sfRenderWindow_drawSprite(_window, spDialogue, NULL);
		sfRenderWindow_drawText(_window, text, NULL);
	}

	sfRenderWindow_drawSprite(_window, spPNJ, NULL);
	sfRenderWindow_drawRectangleShape(_window, hb_PNJ, NULL);


}

bool collisionPlayer_PNJ(sfVector2f _position, Direction _direction, sfVector2f positionPNJ, sfVector2f _vitesse)
{
	sfVector2f nextPosInMap = _position;
	const float zone = 20.0f;

	// calcul la prochaine position du joueur selon la direction qu'il prend
	if (_direction == HAUT)
		nextPosInMap.y -= _vitesse.y * getDeltaTime();
	else if (_direction == BAS)
		nextPosInMap.y += _vitesse.y * getDeltaTime();
	else if (_direction == GAUCHE)
		nextPosInMap.x -= _vitesse.x * getDeltaTime();
	else if (_direction == DROITE)
		nextPosInMap.x += _vitesse.x * getDeltaTime();

	float distxNow = fabsf(_position.x - positionPNJ.x); // calcul la distance entre le jouer et le PNJ
	float distyNow = fabsf(_position.y - positionPNJ.y);
	float distxNext = fabsf(nextPosInMap.x - positionPNJ.x); // calcul la distance prévue entre le joueur et le PNJ après le déplacement
	float distyNext = fabsf(nextPosInMap.y - positionPNJ.y);

	// le prochain pas reste hors de la zone : pas de collision
	if (distxNext > zone || distyNext > zone)
		return false;

	// collision avec le PNJ
	if (distxNext < distxNow || distyNext < distyNow)
		return true;

	return false; // pas de collision
}