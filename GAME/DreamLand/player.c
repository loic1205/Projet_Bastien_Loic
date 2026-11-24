#include "player.h"
#include "map.h"

sfTexture* texPlayer;
sfTexture* texPlayer_fly;
sfTexture* texPlayer_idle;
sfTexture* texPlayer_hurt;
sfTexture* texPlayer_death;
sfTexture* texPlayer_attack;

float animtime = 0.0f;
int frameX = 0;
int frameY = 0;
int animLenght = 0;

sfSprite* spPlayer;
sfIntRect irectPlayer = { 0,0,64,64 }; // rectangle du sprite du joueur
sfFloatRect hb_Player = { 70.0f,90.0f,25.0f,10.0f }; // hitbox du joueur ( position.x , position.y , taille.x , taille.y )

bool hasMoved = false;
bool player_attack = false;

sfVector2f position = { 50.0f, 50.0f };
sfVector2f velocity = { 80.0f,80.0f };

//extern sfVector2f posView;


void initPlayer()
{
	player_Gmode = false;
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
	if (state == PAUSE_MENU)
		animtime = 0.0f;
	if (state == GAME)
	{
		// place le joueur sur la map (sprite du joueur, position du joueur)
		sfSprite_setPosition(spPlayer, position);
		animtime += getDeltaTime();


		/////////////////////////////////////////////////////
		////                                             ////
		////             GESTION DU GOD_MODE             ////
		////                                             ////
		/////////////////////////////////////////////////////

		hasMoved = false;
		sfFloatRect playerfrect = hb_Player; // récupère les dimensions du sprite du joueur avec ses coordonnées


		// mod de débug (impact les collisions, la hitbox et la vitesse du joueur
		if (sfKeyboard_isScancodePressed(sfScanSpace) && sfKeyboard_isScancodePressed(sfScanLControl) && animtime > 0.1f && !player_Gmode)
		{
			player_Gmode = true;
			hb_Player = (sfFloatRect) { 70.0f,90.0f,25.0f,10.0f };
			velocity = (sfVector2f){ 300.0f, 300.0f };
			sfSprite_setTexture(spPlayer, texPlayer_fly, NULL);
		}
		// enlever le mod débug ( reset les variables impactées par le Gmode )
		if (sfKeyboard_isScancodePressed(sfScanSpace) && sfKeyboard_isScancodePressed(sfScanRControl) && animtime > 0.1f && player_Gmode)
		{
			player_Gmode = false;
			hb_Player = (sfFloatRect){ (sfSprite_getPosition(spPlayer).x + 20.0f),(sfSprite_getPosition(spPlayer).y + 40.0f),25.0f,10.0f };
			velocity = (sfVector2f){ 80.0f,80.0f };
			sfSprite_setTexture(spPlayer, texPlayer, NULL);
		}

		/////////////////////////////////////////////////////
		////                                             ////
		////      GESTION DES DEPLACEMENT DU JOUEUR      ////
		////                                             ////
		/////////////////////////////////////////////////////

		// déplacement vers le haut

		if (sfKeyboard_isScancodePressed(sfScanW) && position.y > 0 && !player_attack && !isTalking)
		{
			if (!collisionMapPlayer(playerfrect, HAUT, velocity))
			{
				position.y -= velocity.y * getDeltaTime();
				if(!player_Gmode) hb_Player.position.y -= velocity.y * getDeltaTime();
				if (posView.y > 80 && posView.y >= position.y)
					posView.y -= velocity.y * getDeltaTime();
			}
			frameY = HAUT;
			hasMoved = true;
		}


		// déplacement vers le bas

		if (sfKeyboard_isScancodePressed(sfScanS) && position.y < (HEIGHT_WINDOW_GAME - irectPlayer.size.y) && !player_attack && !isTalking)
		{
			if (!collisionMapPlayer(playerfrect, BAS, velocity))
			{
				position.y += velocity.y * getDeltaTime();
				if (!player_Gmode) hb_Player.position.y += velocity.y * getDeltaTime();
				if (posView.y < HEIGHT_WINDOW_GAME - 80 && posView.y <= position.y)
					posView.y += velocity.y * getDeltaTime();
			}
			frameY = BAS;
			hasMoved = true;
		}


		// déplacement vers la gauche

		if (sfKeyboard_isScancodePressed(sfScanA) && position.x > 0 && !player_attack && !isTalking)
		{
			if (!collisionMapPlayer(playerfrect, GAUCHE, velocity))
			{
				position.x -= velocity.x * getDeltaTime();
				if (!player_Gmode) hb_Player.position.x -= velocity.x * getDeltaTime();
				if (posView.x > 160 && posView.x >= position.x)
					posView.x -= velocity.x * getDeltaTime();
			}
			frameY = GAUCHE;
			hasMoved = true;
		}


		// déplacement vers la droite

		if (sfKeyboard_isScancodePressed(sfScanD) && position.x < (WIDTH_WINDOW_GAME - irectPlayer.size.x) && !player_attack && !isTalking)
		{
			if (!collisionMapPlayer(playerfrect, DROITE, velocity))
			{
				position.x += velocity.x * getDeltaTime();
				if (!player_Gmode) hb_Player.position.x += velocity.x * getDeltaTime();
				if (posView.x < WIDTH_WINDOW_GAME - 160 && posView.x <= position.x)
					posView.x += velocity.x * getDeltaTime();
			}
			frameY = DROITE;
			hasMoved = true;
		}


		// bouton d'attaque
		if (sfMouse_isButtonPressed(sfMouseLeft) && !player_attack && animtime > 0.09f)
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

		if (animtime > 0.15f && !player_attack) // animation de marche du joueur
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
			if (frameX > 5 && hasMoved) frameX = 0; // animation de marche du joueur

			if (!player_Gmode)
			{
				irectPlayer.position.x = frameX * irectPlayer.size.x;
				irectPlayer.position.y = frameY * irectPlayer.size.y;
				sfSprite_setTextureRect(spPlayer, irectPlayer);
			}
			else
			{
				sfSprite_setTexture(spPlayer, texPlayer_fly, NULL);
				irectPlayer.position.x = frameX * irectPlayer.size.x;
				irectPlayer.position.y = frameY * irectPlayer.size.y;
				sfSprite_setTextureRect(spPlayer, irectPlayer);
			}
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
