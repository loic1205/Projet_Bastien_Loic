#include "map.h"

/////////////////////////////////////////////////////
////                                             ////
////      ATTENTION :                            ////
////      COLLISIONS AVEC LES TILES              ////
////      A CORRIGER, PRENDRE EN COMPTES         ////
////      TOUTES LES TILES                       ////
////                                             ////
/////////////////////////////////////////////////////

sfSprite* summons[MAX_SUMMON];
int summonCount = 0;

//texture rituel
sfTexture* texSummon;
sfSprite* spriteSummon;
sfSprite* previewSummon;

// texture map
sfTexture* tileTexture;
sfSprite* tileSprite;
sfIntRect tileRect = { 0, 0, 32, 32 };
extern sfVector2f position;


float keyTimer = 0.0f;

sfIntRect irectSummon = { 0,0,500,500 }; // rectangle du sprite du rituel
sfVector2f positionSummon = { 1080.0f, 400.0f }; // position du sprite du rituel


//view
extern sfVector2f posEditorView;

bool tileSummon = false;
bool summonOrigin = false;


//chest
extern Chest chest[20];
sfVector2i chestPos;
bool chestAlreadyexist = false;

int map[MAP_HEIGHT][MAP_WIDTH];
int tileTypeX = 0;
int tileTypeY = 0;

// initialise la map en fichier .txt
void initMap()
{
	// récupère le tileSheet de la map
	tileTexture = sfTexture_createFromFile(TEXTURE_PATH"/tileset/Document.png", NULL);
	tileSprite = sfSprite_create(tileTexture);

	// récupère le sprite du rituel 
	texSummon = sfTexture_createFromFile(TEXTURE_PATH"/tileset/rituel.png", NULL);
	spriteSummon = sfSprite_create(texSummon);
	sfSprite_setTextureRect(spriteSummon, irectSummon);
	sfSprite_setScale(spriteSummon, (sfVector2f) { 0.1, 0.1 });

	// créer une preview du sprite rituel a afficher en EDITOR au niveau du curseur
	previewSummon = sfSprite_create(texSummon);
	sfSprite_setScale(previewSummon, (sfVector2f) { 0.1, 0.1 });


	// ouverture en mode lecture du fichier contenant la carte 
	fichier = fopen("../Data/Map/map.txt", "rt");
	if (fichier)
	{
		int tile_initMap = 0;

		for (int y = 0; y < MAP_WIDTH; y++)
		{
			for (int x = 0; x < MAP_HEIGHT; x++)
			{
				fscanf(fichier, "%d", &tile_initMap) == 1;
				map[x][y] = tile_initMap;
				fgetc(fichier);
			}
			tile_initMap = fgetc(fichier);
		}
	}
	else
	{
		fichier = fopen("../Data/MAP/map.txt", "w+"); // créer le fichier si il n'existe pas 
	}
	fclose(fichier);
}

// initialise la map en fichier .bin
void initMapBin()
{
	// récupère le tileSheet de la map
	tileTexture = sfTexture_createFromFile(TEXTURE_PATH"tileset1.png", NULL);
	tileSprite = sfSprite_create(tileTexture);

	// récupère le sprite du rituel (test shader light fade-off)
	texSummon = sfTexture_createFromFile(TEXTURE_PATH"/tileset/rituel.png", NULL);
	spriteSummon = sfSprite_create(texSummon);
	sfSprite_setTextureRect(spriteSummon, irectSummon);

	// créer une preview du sprite rituel a afficher en EDITOR au niveau du curseur
	previewSummon = sfSprite_create(texSummon);
	sfSprite_setScale(previewSummon, (sfVector2f) { 0.1, 0.1 });


	// ouverture en mode lecture du fichier contenant la carte 
	fichier = fopen("../Data/MAP/map_bin.bin", "rb");
	if (fichier)
	{
		fread(map, sizeof(int), MAP_HEIGHT * MAP_WIDTH, fichier);
	}
	else
	{
		fichier = fopen("../Data/MAP/map_bin.bin", "w+");
	}
	fclose(fichier);
}


void updateMap(sfRenderWindow* _window)
{

	keyTimer += getDeltaTime();
	
	if (state == GAME)
	{
		sfSprite_setPosition(spriteSummon, positionSummon); // pose le sprite aux coordonnées de positionSummon

		// passe en mode EDITOR
		if (sfKeyboard_isScancodePressed(sfScanE) && keyTimer >= 0.2f)
		{
			state = EDITOR;
			keyTimer = 0.0f;
		}

		// récupère les coordonnées de la souris dans la fenêtre de jeu
		if (sfMouse_isButtonPressed(sfMouseLeft) && keyTimer > 0.2f)
		{
			keyTimer = 0.0f;
			sfVector2i mouseCoo = sfMouse_getPositionRenderWindow(_window);
		}
	}

	/////////////////////////////////////////////////////
	////                                             ////
	////        GESTION DES COMMANDES EDITOR         ////
	////                                             ////
	/////////////////////////////////////////////////////

	else if (state == EDITOR)
	{
		// passe en mode GAME depuis la fenêtre de jeu
		if (sfKeyboard_isScancodePressed(sfScanE) && keyTimer >= 0.2f)
		{
			state = GAME;
			keyTimer = 0.0f;
		}

		// choix des tiles en fonction du spritesheet de la map sur la ligne sélectionner
		if (sfKeyboard_isKeyPressed(sfKeyNum1) && !sfKeyboard_isKeyPressed(sfKeyLControl))
		{
			tileTypeX = 0;
			tileSummon = false;
		}
		if (sfKeyboard_isKeyPressed(sfKeyNum2) && !sfKeyboard_isKeyPressed(sfKeyLControl))
		{
			tileTypeX = 1;
			tileSummon = false;
		}
		if (sfKeyboard_isKeyPressed(sfKeyNum3) && !sfKeyboard_isKeyPressed(sfKeyLControl))
		{
			tileTypeX = 2;
			tileSummon = false;
		}
		if (sfKeyboard_isKeyPressed(sfKeyNum4) && !sfKeyboard_isKeyPressed(sfKeyLControl))
		{
			tileTypeX = 3;
			tileSummon = false;
		}
		if (sfKeyboard_isKeyPressed(sfKeyNum5) && !sfKeyboard_isKeyPressed(sfKeyLControl))
		{
			tileTypeX = 4;
			tileSummon = false;
		}
		if (sfKeyboard_isKeyPressed(sfKeyNum6) && !sfKeyboard_isKeyPressed(sfKeyLControl))
		{
			tileTypeX = 5;
			tileSummon = false;
		}
		if (sfKeyboard_isKeyPressed(sfKeyNum7) && !sfKeyboard_isKeyPressed(sfKeyLControl))
		{
			tileTypeX = 6;
			tileSummon = false;
		}
		if (sfKeyboard_isKeyPressed(sfKeyNum8) && !sfKeyboard_isKeyPressed(sfKeyLControl))
		{
			tileTypeX = 7;
			tileSummon = false;
		}
		if (sfKeyboard_isScancodePressed(sfScanR) && !sfKeyboard_isKeyPressed(sfKeyLControl))
			tileSummon = true;

		// permet de changer la ligne sélectionner du spritesheet de la map 
		if (sfKeyboard_isKeyPressed(sfKeyLControl) && sfKeyboard_isKeyPressed(sfKeyNum1))
			tileTypeY = 0;
		if (sfKeyboard_isKeyPressed(sfKeyLControl) && sfKeyboard_isKeyPressed(sfKeyNum2))
			tileTypeY = 1;
		if (sfKeyboard_isKeyPressed(sfKeyLControl) && sfKeyboard_isKeyPressed(sfKeyNum3))
			tileTypeY = 2;
		if (sfKeyboard_isKeyPressed(sfKeyLControl) && sfKeyboard_isKeyPressed(sfKeyNum4))
			tileTypeY = 3;
		if (sfKeyboard_isKeyPressed(sfKeyLControl) && sfKeyboard_isKeyPressed(sfKeyNum5))
			tileTypeY = 4;


		if (sfMouse_isButtonPressed(sfMouseRight))
		{
			sfVector2i mousePos = sfMouse_getPositionRenderWindow(_window);

			int x = (mousePos.x) * 2 / TILE_SIZE; // *2 pour adapter la position de la souris a la taille de la map
			int y = (mousePos.y) * 2 / TILE_SIZE; // /TILE_SIZE pour récupérer le numéro de la tile 
			map[y][x] = 32; // numéro de la tile noir (supprime un élément de la map)
		}

		if (sfMouse_isButtonPressed(sfMouseLeft))
		{ 
			sfVector2i mousePos = sfMouse_getPositionRenderWindow(_window);

			if(!tileSummon)
			{
				//permet de poser la tile sélectionner
				sfVector2i mousePos = sfMouse_getPositionRenderWindow(_window);
				int x = (mousePos.x * 2) / TILE_SIZE;
				int y = (mousePos.y * 2) / TILE_SIZE;

				map[y][x] = tileTypeX + (8 * tileTypeY); // 8 * tileTypeY permet de récupérer la tile correspondantes a la ligne du tableau sélectionner 
			}
			else if (keyTimer > 0.2f && summonCount < MAX_SUMMON)
			{
				sfVector2f pos = { (float)mousePos.x * 2 - (tileRect.size.x / 2), (float)mousePos.y * 2 - (tileRect.size.y / 2) };

				if (!summonOrigin) // place le rituel originale
				{
					keyTimer = 0.0f;

					positionSummon = pos;
					sfSprite_setPosition(spriteSummon, positionSummon);
					summonOrigin = true;
				}
				else if (summonCount < MAX_SUMMON)
				{
					// pose une copie du sprite rituel à la position de la souris
					keyTimer = 0.0f;

					summons[summonCount] = sfSprite_copy(spriteSummon);
					sfSprite_setPosition(summons[summonCount], pos);
					summonCount++;
				}
			}
		}

		if (sfKeyboard_isScancodePressed(sfScanD) && keyTimer > 0.1f) // détruis les copies de summon et permet de toutes les replacer
		{
			for (int i = 0; i < summonCount; i++)
				sfSprite_destroy(summons[i]);
			summonCount = 0;
			summonOrigin = false;
		}

		if (sfMouse_isButtonPressed(sfMouseMiddle))
		{
			// récupère la tile de la map pour en poser une copie ailleurss
			sfVector2i mousePos = sfMouse_getPositionRenderWindow(_window);
			int x = (mousePos.x) * 2 / TILE_SIZE;
			int y = (mousePos.y) * 2 / TILE_SIZE;

			tileTypeX = (map[y][x] % 8); // map[y][x] récupère le numéro de la tile aux coordonnées {y,x}, le divise par 8 et récupère le reste de cette division ( donne la colonne )
			tileTypeY = (map[y][x]/8); // récupère la valeur de la tile, la divise par 8 arrondi à l'inférieur ( donne la ligne )
		}

		// zoom dans le mode EDITOR
		if (sfKeyboard_isScancodePressed(sfScanNumpadPlus))
		{
			sfView_zoom(editorView, 0.999f);
		}

		if (sfKeyboard_isScancodePressed(sfScanNumpadMinus))
		{
			sfView_zoom(editorView, 1.001f);
		}

		// déplacement de la view dans le mode EDITOR
		if (sfKeyboard_isScancodePressed(sfScanUp))
		{
			posEditorView.y -= 0.4f;
		}

		if (sfKeyboard_isScancodePressed(sfScanDown))
		{
			posEditorView.y += 0.4f;
		}

		if (sfKeyboard_isScancodePressed(sfScanRight))
		{
			posEditorView.x += 0.4f;
		}

		if (sfKeyboard_isScancodePressed(sfScanLeft))
		{
			posEditorView.x -= 0.4f;
		}
	}
}

// affichage des tiles dans la map en fonction de leur emplacement dans la tilesheet
void displayMap(sfRenderWindow* _window)
{
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			if(map[y][x] < 8)
			{
				tileRect.position.x = map[y][x] * tileRect.size.x;
				tileRect.position.y = 0;
			}
			if (map[y][x] >= 8 && map[y][x] < 16) 
			{
				tileRect.position.x = (map[y][x] - 8) * tileRect.size.x;
				tileRect.position.y = tileRect.size.y;
			}
			if (map[y][x] >= 16 && map[y][x] < 24)
			{
				tileRect.position.x = (map[y][x] - 16) * tileRect.size.x;
				tileRect.position.y = tileRect.size.y*2;
			}
			if (map[y][x] >= 24 && map[y][x] < 32)
			{
				tileRect.position.x = (map[y][x] - 24) * tileRect.size.x;
				tileRect.position.y = tileRect.size.y*3;
			}
			if (map[y][x] >= 32 && map[y][x] < 40)
			{
				tileRect.position.x = (map[y][x] - 32) * tileRect.size.x;
				tileRect.position.y = tileRect.size.y*4;
			}

			sfSprite_setTextureRect(tileSprite, tileRect);
			sfVector2f pos = { x * tileRect.size.x, y * tileRect.size.y };
			sfSprite_setPosition(tileSprite, pos);
			sfRenderWindow_drawSprite(_window, tileSprite, NULL);
		}
	}

	if (state == EDITOR)
	{
		if (!tileSummon)
		{
			tileRect.position.x = tileTypeX * tileRect.size.x;
			tileRect.position.y = tileTypeY * tileRect.size.y;
			sfSprite_setTextureRect(tileSprite, tileRect);
			sfVector2i iMousePos = sfMouse_getPositionRenderWindow(_window);
			iMousePos.x *= 2;
			iMousePos.y *= 2;
			sfVector2f fMousePos = { (float)iMousePos.x - (tileRect.size.x / 2) ,(float)iMousePos.y - (tileRect.size.x / 2) };
			sfSprite_setPosition(tileSprite, fMousePos);
			sfRenderWindow_drawSprite(_window, tileSprite, NULL); // affiche la tile choisi au niveau du curseur
			sfRenderWindow_setMouseCursorVisible(_window, false); // fait disparaitre le curseur pour mieux voir la tile
		}
		else
		{
			sfSprite_setTexture(spriteSummon, texSummon, NULL);
			sfVector2i iMousePos = sfMouse_getPositionRenderWindow(_window);
			iMousePos.x *= 2;
			iMousePos.y *= 2;
			sfVector2f fMousePos = { (float)iMousePos.x - (tileRect.size.x / 2) ,(float)iMousePos.y - (tileRect.size.x / 2) };
			sfSprite_setPosition(previewSummon, fMousePos);
			sfRenderWindow_drawSprite(_window, previewSummon, NULL); // affiche le sprite choisi au niveau du curseur
			sfRenderWindow_setMouseCursorVisible(_window, false); // fait disparaitre le curseur pour mieux voir la tile
		}
	}
}

void displaytest(sfRenderWindow* _window)
{
	sfRenderWindow_drawSprite(_window, spriteSummon, NULL); // affiche le sprite rituel

	for (int i = 0; i < summonCount; i++)
		sfRenderWindow_drawSprite(_window, summons[i], NULL); // dessine les copies de spriteSummon
}

void displayEditorTile(sfRenderWindow* _window)
{

}


/////////////////////////////////////////////////////
////                                             ////
////      GESTION DES COLLISIONS DE LA MAP       ////
////                                             ////
/////////////////////////////////////////////////////

bool collisionMapPlayer(sfFloatRect _sprite, Direction _direction, sfVector2f _vitesse)
{
	sfVector2i nextPosInTab = { 0,0 };
	sfVector2i nextPosInTab2 = { 0,0 };

	if (_direction == HAUT)
	{
		// Calcul la position dans le tableau au prochain mouvement vers le Haut ( dans les 2 cases du tableau possible si le sprite est entre 2 cases )
		nextPosInTab.x = _sprite.position.x / 32;
		nextPosInTab.y = (_sprite.position.y - _vitesse.y * getDeltaTime()) / 32;
		nextPosInTab2.x = (_sprite.position.x + _sprite.size.x) / 32;
		nextPosInTab2.y = (_sprite.position.y - _vitesse.y * getDeltaTime()) / 32;
	}
	else if (_direction == BAS)
	{
		nextPosInTab.x = _sprite.position.x / 32;
		nextPosInTab.y = (_sprite.position.y + _sprite.size.y + _vitesse.y * getDeltaTime()) / 32;
		nextPosInTab2.x = (_sprite.position.x + _sprite.size.x) / 32;
		nextPosInTab2.y = (_sprite.position.y + _sprite.size.y + _vitesse.y * getDeltaTime()) / 32;
	}
	else if (_direction == GAUCHE)
	{
		nextPosInTab.x = (_sprite.position.x - _vitesse.x * getDeltaTime()) / 32;
		nextPosInTab.y = (_sprite.position.y) / 32;
		nextPosInTab2.x = (_sprite.position.x - _vitesse.x * getDeltaTime()) / 32;
		nextPosInTab2.y = (_sprite.position.y + _sprite.size.y) / 32;
	}
	else if (_direction == DROITE)
	{
		nextPosInTab.x = (_sprite.position.x + _sprite.size.x + _vitesse.x * getDeltaTime()) / 32;
		nextPosInTab.y = _sprite.position.y / 32;
		nextPosInTab2.x = (_sprite.position.x + _sprite.size.x + _vitesse.x * getDeltaTime()) / 32;
		nextPosInTab2.y = (_sprite.position.y + _sprite.size.y) / 32;
	}
	// Si la ou les case(s) est une case non traversable ( entre 3 et 39 )
	if (map[nextPosInTab.y][nextPosInTab.x] >= 3 && map[nextPosInTab.y][nextPosInTab.x] <= 39 ||
		map[nextPosInTab2.y][nextPosInTab2.x] >= 3 && map[nextPosInTab2.y][nextPosInTab2.x] <= 39)
	{
		return true; // retourne sfTrue si collision
	}

	return false; // retourne sfFalse si pas de collision
}


/////////////////////////////////////////////////////
////                                             ////
////    SAUVEGARDE DE LA MAP EN .TXT ET .BIN     ////
////                                             ////
/////////////////////////////////////////////////////

void saveMap()
{
	fichier = fopen("../Data/MAP/map.txt", "wt");

	for (int y = 0; y < MAP_WIDTH; y++)
	{
		for (int x = 0;x < MAP_HEIGHT; x++)
			fprintf(fichier, "%d ", map[x][y]);
		fprintf(fichier, "\n");
	}
	fclose(fichier);
	return true;
}

void saveMapBin()
{
	fichier = fopen("../Data/MAP/map_bin.bin", "wb");

	fwrite(map, sizeof(int), MAP_HEIGHT * MAP_WIDTH, fichier);

	fclose(fichier);
	return true;
}

void destroyMap()
{
}