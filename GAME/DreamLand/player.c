#include "player.h"
#include "map.h"

sfTexture* texPlayer;
sfSprite* spPlayer;
sfIntRect irectPlayer = { 0,0,23,30 }; // sprite a décaler de 1 pixel

float animtime = 0.0f;
int frameX = 0;
int frameY = 0;

bool hasMoved = false;

bool isTrolling = false;

sfVector2f position = { 1.0f, 1.0f };
sfVector2f velocity = { 100.0f,100.0f };


void initPlayer()
{
	// animation de marche du joueur
	texPlayer = sfTexture_createFromFile(TEXTURE_PATH"tilesetPlayer/player_walk.png", NULL);
	spPlayer = sfSprite_create(texPlayer);
	sfSprite_setTextureRect(spPlayer, irectPlayer);
}

void updatePlayer()
{
	if (state == GAME)
	{
		// place le joueur sur la map (sprit du joueur, position du joueur)
		sfSprite_setPosition(spPlayer, position);

		hasMoved = false;
		sfFloatRect playerfrect = sfSprite_getGlobalBounds(spPlayer); // récupère les dimensions du sprite du joueur avec ses coordonnées
		if (sfKeyboard_isScancodePressed(sfScanW) && position.y > 0)
		{
			if (!collisionMapPlayer(playerfrect, HAUT, velocity))
			{
				position.y -= velocity.y * getDeltaTime();
			}
			frameY = HAUT;
			hasMoved = true;                                                       
		}
		if (sfKeyboard_isScancodePressed(sfScanS) && position.y < HEIGHT_WINDOW_GAME - irectPlayer.size.x)
		{
			if (!collisionMapPlayer(playerfrect, BAS, velocity))
			{
				position.y += velocity.y * getDeltaTime();
			}
			frameY = BAS;
			hasMoved = true;
		}
		if (sfKeyboard_isScancodePressed(sfScanA) && position.x > 0)
		{
			if (!collisionMapPlayer(playerfrect, GAUCHE, velocity))
			{
				position.x -= velocity.x * getDeltaTime();
			}
			frameY = GAUCHE;
			hasMoved = true;
		}
		if (sfKeyboard_isScancodePressed(sfScanD) && position.x < WIDTH_WINDOW_GAME - irectPlayer.size.x)
		{
			if (!collisionMapPlayer(playerfrect, DROITE, velocity))
			{
				position.x += velocity.x * getDeltaTime();
			}
			frameY = DROITE;
			hasMoved = true;
		}

		animtime += getDeltaTime();

		if (animtime > 0.1f)
		{
			if (hasMoved) frameX++;
			else frameX = 0;

			if (frameX > 5) frameX = 0;

			irectPlayer.position.x = frameX * irectPlayer.size.x;
			irectPlayer.position.y = frameY * irectPlayer.size.y;
			sfSprite_setTextureRect(spPlayer, irectPlayer);
			animtime = 0.0f;
		}
		sfSprite_setPosition(spPlayer, position);
		playerfrect = sfSprite_getGlobalBounds(spPlayer);

	}
}

void displayPlayer(sfRenderWindow* _window)
{
	sfRenderWindow_drawSprite(_window, spPlayer, NULL);
}

void destroyPLayer()
{


}
