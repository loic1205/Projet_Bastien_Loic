#include "player.h"
#include "map.h"

sfTexture* texPlayer;
sfSprite* spPlayer;
sfIntRect irectPlayer = {0,0,17,23};
float animtime = 0.0f;
int frameX = 0;
int frameY = 0;
bool hasMoved = false;
sfVector2f velocity = {100.0f, 100.0f};
sfVector2f position = { 650.0f, 100.0f };
extern sfVector2f posView;


void initPlayer(int _playerNumber)
{
	texPlayer = sfTexture_createFromFile(TEXTURE_PATH"link.png", NULL);
	spPlayer = sfSprite_create(texPlayer);
	sfSprite_setTextureRect(spPlayer, irectPlayer);
}

void updatePlayer(int _playerNumber)
{

	if (state == GAME)
	{
		hasMoved = false;
		sfFloatRect playerfrect = sfSprite_getGlobalBounds(spPlayer);


		if (sfKeyboard_isScancodePressed(sfScanW) && position.y > 0)
		{
			if (!collisionMapPlayer(playerfrect, HAUT, velocity) && !sfKeyboard_isScancodePressed(sfScanLShift))
			{
				position.y -= velocity.y * getDeltaTime();
				if (posView.y > 80 && posView.y >= position.y)
					posView.y -= velocity.y * getDeltaTime();
			}
			if (!collisionMapPlayer(playerfrect, HAUT, (sfVector2f) { velocity.x*2, velocity.y*2 }) && sfKeyboard_isScancodePressed(sfScanLShift))
			{
				position.y -= velocity.y * 2 * getDeltaTime();
				if (posView.y > 80 && posView.y >= position.y)
					posView.y -= velocity.y * 2 * getDeltaTime();
			}
			frameY = HAUT;
			hasMoved = true;
		}
		if (sfKeyboard_isScancodePressed(sfScanS) && position.y < WINDOW_SIZE_Y*2 - irectPlayer.size.x)
		{
			if (!collisionMapPlayer(playerfrect, BAS, velocity) && !sfKeyboard_isScancodePressed(sfScanLShift))
			{
				position.y += velocity.y * getDeltaTime();
				if (posView.y < WINDOW_SIZE_Y*2  - 80 && posView.y <= position.y)
					posView.y += velocity.y * getDeltaTime();
			}
			if (!collisionMapPlayer(playerfrect, BAS, (sfVector2f) { velocity.x * 2, velocity.y * 2 }) && sfKeyboard_isScancodePressed(sfScanLShift))
			{
				position.y += velocity.y * 2 * getDeltaTime();
				if (posView.y < WINDOW_SIZE_Y * 2 - 80 && posView.y <= position.y)
					posView.y += velocity.y * 2 * getDeltaTime();
			}
			frameY = BAS;
			hasMoved = true;
		}
		if (sfKeyboard_isScancodePressed(sfScanA) && position.x > 0)
		{
			if (!collisionMapPlayer(playerfrect, GAUCHE, velocity) && !sfKeyboard_isScancodePressed(sfScanLShift))
			{
				position.x -= velocity.x * getDeltaTime();
				if (posView.x >160 && posView.x >= position.x)
					posView.x -= velocity.x * getDeltaTime();
			}
			if (!collisionMapPlayer(playerfrect, GAUCHE, (sfVector2f) { velocity.x * 2, velocity.y * 2 }) && sfKeyboard_isScancodePressed(sfScanLShift))
			{
				position.x -= velocity.x * 2 * getDeltaTime();
				if (posView.x > 160 && posView.x >= position.x)
					posView.x -= velocity.x * 2 * getDeltaTime();
			}
			frameY = GAUCHE;
			hasMoved = true;
		}
		if (sfKeyboard_isScancodePressed(sfScanD) && position.x < WINDOW_SIZE_X*2 - irectPlayer.size.x)
		{
			if (!collisionMapPlayer(playerfrect, DROITE, velocity) && !sfKeyboard_isScancodePressed(sfScanLShift))
			{
				position.x += velocity.x * getDeltaTime();
				if (posView.x < WINDOW_SIZE_X*2 - 160 && posView.x <= position.x)
					posView.x += velocity.x * getDeltaTime();
			}
			if (!collisionMapPlayer(playerfrect, DROITE, (sfVector2f) { velocity.x * 2, velocity.y * 2 }) && sfKeyboard_isScancodePressed(sfScanLShift))
			{
				position.x += velocity.x * 2 * getDeltaTime();
				if (posView.x < WINDOW_SIZE_X * 2 - 160 && posView.x <= position.x)
					posView.x += velocity.x * 2 * getDeltaTime();
			}
			frameY = DROITE;
			hasMoved = true;
		}  
		animtime += getDeltaTime();
		if (animtime > 0.2f)
		{
			if (hasMoved) frameX++;
			else frameX = 0;

			if (frameX > 8) frameX = 0;

			irectPlayer.position.x = frameX * irectPlayer.size.x;
			irectPlayer.position.y = frameY * irectPlayer.size.y;
			sfSprite_setTextureRect(spPlayer, irectPlayer);
			animtime = 0.0f;
		}
		sfSprite_setPosition(spPlayer, position);
	}


}

void displayPlayer(sfRenderWindow* _window, int _playerNumber)
{
	sfRenderWindow_drawSprite(_window, spPlayer, NULL);
}

void destroyPlayer()
{


}
