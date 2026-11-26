#include "mob.h"
#include "map.h"


sfTexture* texBoss_idle;
sfTexture* texBoss_attack;
sfTexture* texBoss_walk;
sfSprite* spBoss;
sfIntRect irectBoss = { 0, 0, 64, 64 };
sfRectangleShape* hbBossRect;
sfVector2f velocityBoss = { 50.0f, 50.0f };
sfFloatRect zoneAgroBoss = { 50, 50, 200, 200 };
sfRectangleShape* hbZonAgroBossRect;


float bossAnimtime = 0.0f;
int bossFrameX = 0;
int bossFrameY = 0;
int bossAnimLenght = 0;


bool bossHasMoved = false;
bool boss_attack = false;

float bossTimer = 0.0f;


void initsMob()
{





	positionBoss = (sfVector2f){ 80.0f, 80.0f };
	texBoss_idle = sfTexture_createFromFile(TEXTURE_PATH"tilesetMob/Vampires_Boss_Idle.png", NULL);
	texBoss_attack = sfTexture_createFromFile(TEXTURE_PATH"tilesetMob/Vampires_Boss_Attack.png", NULL);
	texBoss_walk = sfTexture_createFromFile(TEXTURE_PATH"tilesetMob/Vampires_Boss_Walk.png", NULL);
	spBoss = sfSprite_create(texBoss_idle);
	sfSprite_setTextureRect(spBoss, irectBoss);
	sfSprite_setPosition(spBoss, positionBoss);



	hb_boss = (sfFloatRect){ positionBoss.x + 27, positionBoss.y + 35.0f,10.0f,20.0f };// hitbox du Boss
	hbBossRect = sfRectangleShape_create();
	sfRectangleShape_setFillColor(hbBossRect, sfTransparent);
	sfRectangleShape_setOutlineColor(hbBossRect, sfRed);
	sfRectangleShape_setOutlineThickness(hbBossRect, 0.5f);

	hbZonAgroBossRect = sfRectangleShape_create();
	sfRectangleShape_setPosition(hbZonAgroBossRect, (sfVector2f){ zoneAgroBoss.position.x + 27.0f, zoneAgroBoss.position.y + 35.0f });
	sfRectangleShape_setSize(hbZonAgroBossRect, (sfVector2f) { zoneAgroBoss.size.x + 10.0f, zoneAgroBoss.size.y+20.0f});
	sfRectangleShape_setFillColor(hbZonAgroBossRect, (sfColor){255, 192, 203, 150});
	sfRectangleShape_setOutlineColor(hbZonAgroBossRect, sfRed);
	sfRectangleShape_setOutlineThickness(hbZonAgroBossRect, 0.5f);
	

}

void updateMob()
{
	hb_boss = (sfFloatRect){ positionBoss.x + 27, positionBoss.y + 35.0f,10.0f,20.0f };
	sfRectangleShape_setPosition(hbBossRect, hb_boss.position);
	sfRectangleShape_setSize(hbBossRect, hb_boss.size);

	if (state == GAME)
	{
		bossTimer += getDeltaTime();
		bossAnimtime += getDeltaTime();
		bossHasMoved = false;
		sfFloatRect bossfrect = hb_boss;

		/////////////////////////////////////////////////////
		////                                             ////
		////      GESTION DES DEPLACEMENT DU BOSS        ////
		////                                             ////
		/////////////////////////////////////////////////////d

		

		if(!isTalking)
		{

			// déplacement vers le haut

			if (positionBoss.y >= position.y - 20 && positionBoss.y > zoneAgroBoss.position.y && !boss_attack && !collisionPlayer_Sprite(hb_boss, hb_pnj, HAUT, velocityBoss) && !collisionPlayer_Sprite(hb_boss, hb_portal, HAUT, velocityBoss))
			{
				if (!collisionMapPlayer(bossfrect, HAUT, velocityBoss))
				{
					positionBoss.y -= velocityBoss.y * getDeltaTime();
					hb_boss.position.y -= velocityBoss.y * getDeltaTime();
				}
				bossFrameY = HAUT;
				bossHasMoved = true;
			}


			// déplacement vers le bas

			if (positionBoss.y <= position.y + 20 && positionBoss.y < zoneAgroBoss.position.y + zoneAgroBoss.size.y && positionBoss.y < zoneAgroBoss.size.y + zoneAgroBoss.position.y && !boss_attack && !collisionPlayer_Sprite(hb_boss, hb_pnj, BAS, velocityBoss) && !collisionPlayer_Sprite(hb_boss, hb_portal, BAS, velocityBoss))
			{
				if (!collisionMapPlayer(bossfrect, BAS, velocityBoss))
				{
					positionBoss.y += velocityBoss.y * getDeltaTime();
					hb_boss.position.y += velocityBoss.y * getDeltaTime();
				}
				bossFrameY = BAS;
				bossHasMoved = true;
			}


			// déplacement vers la gauche

			if (positionBoss.x >= position.x - 20 && positionBoss.x > zoneAgroBoss.position.x && !boss_attack && !collisionPlayer_Sprite(hb_boss, hb_pnj, GAUCHE, velocityBoss) && !collisionPlayer_Sprite(hb_boss, hb_portal, GAUCHE, velocityBoss))
			{
				if (!collisionMapPlayer(bossfrect, GAUCHE, velocityBoss))
				{
					positionBoss.x -= velocityBoss.x * getDeltaTime();
					hb_boss.position.x -= velocityBoss.x * getDeltaTime();
				}
				bossFrameY = GAUCHE;
				bossHasMoved = true;
			}


			// déplacement vers la droite

			if (positionBoss.x <= position.x + 20 && positionBoss.x < zoneAgroBoss.position.x + zoneAgroBoss.size.x && !boss_attack && !collisionPlayer_Sprite(hb_boss, hb_pnj, DROITE, velocityBoss) && !collisionPlayer_Sprite(hb_boss, hb_portal, DROITE, velocityBoss))
			{
				if (!collisionMapPlayer(bossfrect, DROITE, velocityBoss))
				{
					positionBoss.x += velocityBoss.x * getDeltaTime();
					hb_boss.position.x += velocityBoss.x * getDeltaTime();
				}
				bossFrameY = DROITE;
				bossHasMoved = true;
			}


		}


		// bouton d'attaque
		if (sfMouse_isButtonPressed(sfMouseLeft) && !boss_attack && bossAnimtime > 0.09f)
		{
			bossFrameX = 0;
			boss_attack = true;
		}


		/////////////////////////////////////////////////////
		////                                             ////
		////      GESTION DE L'ANIMATION DU BOSS         ////
		////                                             ////
		/////////////////////////////////////////////////////

		if (boss_attack) // animation d'attaque du boss
		{
			if (bossAnimtime > 0.1f)
			{
				bossFrameX++;
				irectBoss.position.x = bossFrameX * irectBoss.size.x;
				irectBoss.position.y = bossFrameY * irectBoss.size.y;
				sfSprite_setTexture(spBoss, texBoss_attack, NULL); // Récupère le spriteSheet de l'animation d'attaque 
				sfSprite_setTextureRect(spBoss, irectBoss); // l'applique au rectangle du sprite du joueur
				if (bossFrameX == 11)
				{
					bossFrameX = 0;
					boss_attack = false; // arrête l'animation d'attaque une fois celle-ci terminer
				}
				bossAnimtime = 0.0f;
			}
		}

		if (bossAnimtime > 0.15f && !boss_attack) // animation de marche du joueur
		{
			if (!bossHasMoved) // animation idle si le personnage ne bouge pas 
			{
				bossFrameX++;
				irectBoss.position.x = bossFrameX * irectBoss.size.x;
				irectBoss.position.y = bossFrameY * irectBoss.size.y;
				sfSprite_setTexture(spBoss, texBoss_idle, NULL); // Récupère le spriteSheet de l'animation idle
				sfSprite_setTextureRect(spBoss, irectBoss); // l'applique au rectangle du sprite du joueur
				if (bossFrameX > 3)
				{
					bossFrameX = 0;
				}
				bossAnimtime = 0.0f;
			}
			else
			{
				bossFrameX++;
				sfSprite_setTexture(spBoss, texBoss_walk, NULL);
			}
			if (bossFrameX > 5 && bossHasMoved) bossFrameX = 0; // animation de marche du joueur

			irectBoss.position.x = bossFrameX * irectBoss.size.x;
			irectBoss.position.y = bossFrameY * irectBoss.size.y;
			sfSprite_setTextureRect(spBoss, irectBoss);

			bossAnimtime = 0.0f;
		}





		sfSprite_setPosition(spBoss, positionBoss);
		bossfrect = sfSprite_getGlobalBounds(spBoss);

	}


}

void displayMob(sfRenderWindow* _window)
{


	sfRenderWindow_drawSprite(_window, spBoss, NULL);
	if (debugMode)
	{
		sfRenderWindow_drawRectangleShape(_window, hbBossRect, NULL);
		sfRenderWindow_drawRectangleShape(_window, hbZonAgroBossRect, NULL);
	}


}
