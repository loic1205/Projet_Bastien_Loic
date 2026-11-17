#include "player.h"
#include "map.h"

sfTexture* texPlayer;
sfTexture* texPlayer_fly;
sfTexture* texPlayer_idle;
sfTexture* texPlayer_hurt;
sfTexture* texPlayer_death;
sfTexture* texPlayer_attack;

sfSprite* spPlayer;
sfIntRect irectPlayer = { 0,0,64,64 }; // rectangle du sprite du joueur
sfFloatRect hb_Player = { 70.0f,90.0f,25.0f,10.0f }; // hitbox du joueur ( position.x , position.y , taille.x , taille.y )

float animtime = 0.0f;
int frameX = 0;
int frameY = 0;
int animLenght = 0;

bool hasMoved = false;
bool player_attack = false;

sfVector2f position = { 50.0f, 50.0f };
sfVector2f velocity = { 100.0f,100.0f };

//extern sfVector2f posView;


void initPlayer()
{
	// initialisations des textures du joueur
	texPlayer_fly = sfTexture_createFromFile(TEXTURE_PATH"tilesetPlayer/player_fly.png", NULL);
	texPlayer_idle = sfTexture_createFromFile(TEXTURE_PATH"tilesetPlayer/player_idle.png", NULL);
	texPlayer_hurt = sfTexture_createFromFile(TEXTURE_PATH"tilesetPlayer/player_hurt.png", NULL);
	texPlayer_death = sfTexture_createFromFile(TEXTURE_PATH"tilesetPlayer/player_death.png", NULL);
	texPlayer_attack = sfTexture_createFromFile(TEXTURE_PATH"tilesetPlayer/player_attack.png", NULL);

	texPlayer = sfTexture_createFromFile(TEXTURE_PATH"tilesetPlayer/player_walk.png", NULL);
	spPlayer = sfSprite_create(texPlayer);
	sfSprite_setTextureRect(spPlayer, irectPlayer);
}

void updatePlayer()
{
	if (state == GAME)
	{
		// place le joueur sur la map (sprite du joueur, position du joueur)
		sfSprite_setPosition(spPlayer, position);
		animtime += getDeltaTime();


		/////////////////////////////////////////////////////
		////                                             ////
		////      GESTION DU DEPLACEMENT DU JOUEUR       ////
		////                                             ////
		/////////////////////////////////////////////////////

		hasMoved = false;
		sfFloatRect playerfrect = hb_Player; // récupère les dimensions du sprite du joueur avec ses coordonnées
		// déplacement vers le haut
		if (sfKeyboard_isScancodePressed(sfScanW) && position.y > 0)
		{
			if (!collisionMapPlayer(playerfrect, HAUT, velocity) && !player_attack)
			{
				position.y -= velocity.y * getDeltaTime();
				hb_Player.position.y -= velocity.y * getDeltaTime();
				if (posView.y > 80 && posView.y >= position.y)
					posView.y -= velocity.y * getDeltaTime();
			}
			frameY = HAUT;
			hasMoved = true;
		}
		// déplacement vers le bas
		if (sfKeyboard_isScancodePressed(sfScanS) && position.y < (HEIGHT_WINDOW_GAME - irectPlayer.size.y) && !player_attack)
		{
			if (!collisionMapPlayer(playerfrect, BAS, velocity))
			{
				position.y += velocity.y * getDeltaTime();
				hb_Player.position.y += velocity.y * getDeltaTime();
				if (posView.y < HEIGHT_WINDOW_GAME - 80 && posView.y <= position.y)
					posView.y += velocity.y * getDeltaTime();
			}
			frameY = BAS;
			hasMoved = true;
		}
		// déplacement vers la gauche
		if (sfKeyboard_isScancodePressed(sfScanA) && position.x > 0 && !player_attack)
		{
			if (!collisionMapPlayer(playerfrect, GAUCHE, velocity))
			{
				position.x -= velocity.x * getDeltaTime();
				hb_Player.position.x -= velocity.x * getDeltaTime();
				if (posView.x > 160 && posView.x >= position.x)
					posView.x -= velocity.x * getDeltaTime();
			}
			frameY = GAUCHE;
			hasMoved = true;
		}
		// déplacement vers la droite
		if (sfKeyboard_isScancodePressed(sfScanD) && position.x < (WIDTH_WINDOW_GAME - irectPlayer.size.x) && !player_attack)
		{
			if (!collisionMapPlayer(playerfrect, DROITE, velocity))
			{
				position.x += velocity.x * getDeltaTime();
				hb_Player.position.x += velocity.x * getDeltaTime();
				if (posView.x < WIDTH_WINDOW_GAME - 160 && posView.x <= position.x)
					posView.x += velocity.x * getDeltaTime();
			}
			frameY = DROITE;
			hasMoved = true;
		}

		if (sfMouse_isButtonPressed(sfMouseLeft) && !player_attack)
		{
			frameX = 0;
			player_attack = true; // permet de laisser l'animation d'attaque sans rester appuyez sur le clic droit de la souris
		}


		/////////////////////////////////////////////////////
		////                                             ////
		////      GESTION DE L'ANIMATION DU JOUEUR       ////
		////                                             ////
		/////////////////////////////////////////////////////

		if (player_attack) // animation d'attaque du joueur
		{
			if (animtime > 0.1f)
			{
				frameX++;
				irectPlayer.position.x = frameX * irectPlayer.size.x;
				irectPlayer.position.y = frameY * irectPlayer.size.y;
				sfSprite_setTexture(spPlayer, texPlayer_attack, NULL); // Récupère le spriteSheet de l'animation d'attaque 
				sfSprite_setTextureRect(spPlayer, irectPlayer); // l'applique au rectangle du sprite du joueur
				if (frameX == 11)
				{
					frameX = 0;
					player_attack = false; // arrête l'animation d'attaque une fois celle-ci terminer
				}
				animtime = 0.0f;
			}
		}

		if (animtime > 0.1f && !player_attack) // animation de marche du joueur
		{
			if (!hasMoved) // animation idle si le personnage ne bouge pas 
			{
				frameX++;
				irectPlayer.position.x = frameX * irectPlayer.size.x;
				irectPlayer.position.y = frameY * irectPlayer.size.y;
				sfSprite_setTexture(spPlayer, texPlayer_idle, NULL); // Récupère le spriteSheet de l'animation idle
				sfSprite_setTextureRect(spPlayer, irectPlayer); // l'applique au rectangle du sprite du joueur
				if (frameX > 3)
				{
					frameX = 0;
				}
				animtime = 0.0f;
			}
			else
			{
				frameX++;
				sfSprite_setTexture(spPlayer, texPlayer, NULL);
			}


			if (frameX > 5 && hasMoved) frameX = 0;

			irectPlayer.position.x = frameX * irectPlayer.size.x; 
			irectPlayer.position.y = frameY * irectPlayer.size.y;
			sfSprite_setTextureRect(spPlayer, irectPlayer);
			animtime = 0.0f;
		}


		sfSprite_setPosition(spPlayer, position);
		playerfrect = sfSprite_getGlobalBounds(spPlayer);
		printf("%d\n", frameX);
	}
}




void displayPlayer(sfRenderWindow* _window)
{
	sfRenderWindow_drawSprite(_window, spPlayer, NULL);
}

void destroyPLayer()
{

}
