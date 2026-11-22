#include "map.h"

/////////////////////////////////////////////////////
////                                             ////
////      ATTENTION :                            ////
////      COLLISIONS AVEC LES TILES              ////
////      A CORRIGER, PRENDRE EN COMPTES         ////
////      TOUTES LES TILES                       ////
////                                             ////
/////////////////////////////////////////////////////

// texture map
sfTexture* tileTexture;
sfSprite* tileSprite;
sfIntRect tileRect = { 0, 0, 32, 32 };
extern sfVector2f position;


float keyTimer = 0.0f;


//view
extern sfVector2f posEditorView;


//chest
extern Chest chest[20];
sfVector2i chestPos;
bool chestAlreadyexist = false;


int map[NB_LAYERS][MAP_HEIGHT][MAP_WIDTH]; // remplace l'ancien map[MAP_HEIGHT][MAP_WIDTH]
int currentLayer = 0;
int tileTypeX = 0;
int tileTypeY = 0;

// renvoie true si la souris est au-dessus du panneau de tiles
static bool mouseOnPalette(sfRenderWindow* _window)
{
	sfVector2u winSize = sfRenderWindow_getSize(_window);
	sfVector2i m = sfMouse_getPositionRenderWindow(_window);
	return m.x >= winSize.x * (1.0f - PALETTE_RATIO);
}

// initialise la map en fichier .txt
void initMap()
{
	// récupère le tileSheet de la map
	tileTexture = sfTexture_createFromFile(TEXTURE_PATH"/tileset/Document.png", NULL);
	tileSprite = sfSprite_create(tileTexture);


	// initialise les couches 1 et 2 de la tilemap a -1 pour pouvoir afficher la couche 0 sans avoir une map toute noir.
	for (int l = 1; l < NB_LAYERS; l++)
		for (int y = 0; y < MAP_HEIGHT; y++)
			for (int x = 0; x < MAP_WIDTH; x++)
				map[l][y][x] = -1; // permet d'afficher une case invisible plutot qu'une case noire si c'était égale à 0.
	
	// ouverture en mode lecture du fichier contenant la carte 
	fichier = fopen("../Data/Map/map.txt", "rt");
	if (fichier)
	{
		int tile_initMap = 0;

		for (int l = 0; l < NB_LAYERS; l++)
		{
			for (int y = 0; y < MAP_WIDTH; y++)
			{
				for (int x = 0; x < MAP_HEIGHT; x++)
				{
					if (fscanf(fichier, "%d", &tile_initMap) == 1)
						map[l][x][y] = tile_initMap;
					fgetc(fichier);
				}
				tile_initMap = fgetc(fichier);
			}
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


	for (int l = 1; l < NB_LAYERS; l++)
		for (int y = 0; y < MAP_HEIGHT; y++)
			for (int x = 0; x < MAP_WIDTH; x++)
				map[l][y][x] = -1;

	// ouverture en mode lecture du fichier contenant la carte 
	fichier = fopen("../Data/MAP/map_bin.bin", "rb");
	if (fichier)
	{
		fread(map, sizeof(int), NB_LAYERS * MAP_HEIGHT * MAP_WIDTH, fichier);
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

		// gestion des différentes couches de la map
		if (sfKeyboard_isKeyPressed(sfKeyF1)) 
			currentLayer = 0;

		if (sfKeyboard_isKeyPressed(sfKeyF2))
			currentLayer = 1;

		if (sfKeyboard_isKeyPressed(sfKeyF3))
			currentLayer = 2;

		// choix des tiles en fonction du spritesheet de la map sur la ligne sélectionner
		if (sfKeyboard_isKeyPressed(sfKeyNum1) && !sfKeyboard_isKeyPressed(sfKeyLControl))
		{
			tileTypeX = 0;
		}
		if (sfKeyboard_isKeyPressed(sfKeyNum2) && !sfKeyboard_isKeyPressed(sfKeyLControl))
		{
			tileTypeX = 1;
		}
		if (sfKeyboard_isKeyPressed(sfKeyNum3) && !sfKeyboard_isKeyPressed(sfKeyLControl))
		{
			tileTypeX = 2;
		}
		if (sfKeyboard_isKeyPressed(sfKeyNum4) && !sfKeyboard_isKeyPressed(sfKeyLControl))
		{
			tileTypeX = 3;
		}
		if (sfKeyboard_isKeyPressed(sfKeyNum5) && !sfKeyboard_isKeyPressed(sfKeyLControl))
		{
			tileTypeX = 4;
		}
		if (sfKeyboard_isKeyPressed(sfKeyNum6) && !sfKeyboard_isKeyPressed(sfKeyLControl))
		{
			tileTypeX = 5;
		}
		if (sfKeyboard_isKeyPressed(sfKeyNum7) && !sfKeyboard_isKeyPressed(sfKeyLControl))
		{
			tileTypeX = 6;
		}
		if (sfKeyboard_isKeyPressed(sfKeyNum8) && !sfKeyboard_isKeyPressed(sfKeyLControl))
		{
			tileTypeX = 7;
		}


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

		bool onPalette = mouseOnPalette(_window);

		// clic sur le panneau : sélectionne la tile cliquée
		if (onPalette && sfMouse_isButtonPressed(sfMouseLeft))
		{
			sfVector2u winSize = sfRenderWindow_getSize(_window);
			sfVector2i m = sfMouse_getPositionRenderWindow(_window);
			float panelW = winSize.x * PALETTE_RATIO;
			float tileSize = panelW / TILESHEET_COLS;

			int col = (m.x - (winSize.x - panelW)) / tileSize;
			int row = m.y / tileSize;

			if (col >= 0 && col < TILESHEET_COLS && row >= 0 && row < TILESHEET_ROWS)
			{
				tileTypeX = col;
				tileTypeY = row;
			}
		}

		if (!onPalette && sfMouse_isButtonPressed(sfMouseRight))
		{
			sfVector2i mousePos = sfMouse_getPositionRenderWindow(_window);

			int x = (mousePos.x) * 2 / TILE_SIZE; // *2 pour adapter la position de la souris a la taille de la map
			int y = (mousePos.y) * 2 / TILE_SIZE; // /TILE_SIZE pour récupérer le numéro de la tile 
			if (currentLayer == 0) 
				map[currentLayer][y][x] = 32; // case noir 
			else
				map[currentLayer][y][x] = -1; // case transparente
		}

		if (!onPalette && sfMouse_isButtonPressed(sfMouseLeft))
		{ 
			sfVector2i mousePos = sfMouse_getPositionRenderWindow(_window);
			sfVector2f pos = { (float)mousePos.x * 2 - (tileRect.size.x / 2), (float)mousePos.y * 2 - (tileRect.size.y / 2) };

			//permet de poser la tile sélectionner
			int x = (mousePos.x * 2) / TILE_SIZE;
			int y = (mousePos.y * 2) / TILE_SIZE;

			map[currentLayer][y][x] = tileTypeX + (8 * tileTypeY); // 8 * tileTypeY permet de récupérer la tile correspondantes a la ligne du tableau sélectionner 
		}

		if (!onPalette && sfMouse_isButtonPressed(sfMouseMiddle))
		{
			// récupère la tile de la map pour en poser une copie ailleurss
			sfVector2i mousePos = sfMouse_getPositionRenderWindow(_window);
			int x = (mousePos.x) * 2 / TILE_SIZE;
			int y = (mousePos.y) * 2 / TILE_SIZE;


			if (map[currentLayer][y][x] >= 0)
			{
				tileTypeX = (map[currentLayer][y][x] % 8); // map[y][x] récupère le numéro de la tile aux coordonnées {y,x}, le divise par 8 et récupère le reste de cette division ( donne la colonne )
				tileTypeY = (map[currentLayer][y][x] / 8); // récupère la valeur de la tile, la divise par 8 arrondi à l'inférieur ( donne la ligne )
			}
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

// affiche le panneau de sélection des tiles à droite de l'écran (mode EDITOR)
void displayTilePalette(sfRenderWindow* _window)
{
	if (state != EDITOR) return;

	static sfRectangleShape* bg = NULL;
	static sfRectangleShape* selection = NULL;
	if (!bg)
	{
		bg = sfRectangleShape_create();
		sfRectangleShape_setFillColor(bg, (sfColor) { 30, 30, 30, 255 });

		selection = sfRectangleShape_create();
		sfRectangleShape_setFillColor(selection, sfTransparent);
		sfRectangleShape_setOutlineColor(selection, sfYellow);
		sfRectangleShape_setOutlineThickness(selection, 2.0f);
	}

	sfVector2u winSize = sfRenderWindow_getSize(_window);
	float panelW = winSize.x * PALETTE_RATIO;
	float panelX = winSize.x - panelW;
	float tileSize = panelW / TILESHEET_COLS; // taille d'une tile à l'écran

	// vue fixe qui couvre toute la fenêtre (on garde l'ancienne pour la remettre après)
	sfView* oldView = sfView_copy(sfRenderWindow_getView(_window));
	sfView* uiView = sfView_createFromRect((sfFloatRect) { { 0.0f, 0.0f }, { (float)winSize.x, (float)winSize.y } });
	sfRenderWindow_setView(_window, uiView);

	// fond du panneau
	sfRectangleShape_setPosition(bg, (sfVector2f) { panelX, 0.0f });
	sfRectangleShape_setSize(bg, (sfVector2f) { panelW, (float)winSize.y });
	sfRenderWindow_drawRectangleShape(_window, bg, NULL);

	// toutes les tiles du tileset
	sfSprite_setScale(tileSprite, (sfVector2f) { tileSize / 32.0f, tileSize / 32.0f });
	for (int r = 0; r < TILESHEET_ROWS; r++)
	{
		for (int c = 0; c < TILESHEET_COLS; c++)
		{
			sfIntRect rect = { { c * 32, r * 32 },{ 32, 32 } };
			sfSprite_setTextureRect(tileSprite, rect);
			sfSprite_setPosition(tileSprite, (sfVector2f) { panelX + c * tileSize, r* tileSize });
			sfRenderWindow_drawSprite(_window, tileSprite, NULL);
		}
	}
	sfSprite_setScale(tileSprite, (sfVector2f) { 1.0f, 1.0f }); // remet l'échelle normale

	// contour jaune autour de la tile sélectionnée
	sfRectangleShape_setPosition(selection, (sfVector2f) { panelX + tileTypeX * tileSize, tileTypeY* tileSize });
	sfRectangleShape_setSize(selection, (sfVector2f) { tileSize, tileSize });
	sfRenderWindow_drawRectangleShape(_window, selection, NULL);

	// on remet la vue d'origine
	sfRenderWindow_setView(_window, oldView);
	sfView_destroy(uiView);
	sfView_destroy(oldView);
}

// affichage des tiles dans la map en fonction de leur emplacement dans la tilesheet
void displayMap(sfRenderWindow* _window)
{
	for (int l = 0; l < NB_LAYERS; l++)
	{
		for (int y = 0; y < MAP_HEIGHT; y++)
		{
			for (int x = 0; x < MAP_WIDTH; x++)
			{
				if (map[l][y][x] < 0) continue; // continue == break d'un switch mais pour le if, passse à l'itération suivante (prochaine boucle du for)
			if(map[l][y][x] < 8)
			{
				tileRect.position.x = map[l][y][x] * tileRect.size.x;
				tileRect.position.y = 0;
			}
			if (map[l][y][x] >= 8 && map[l][y][x] < 16)
			{
				tileRect.position.x = (map[l][y][x] - 8) * tileRect.size.x;
				tileRect.position.y = tileRect.size.y;
			}
			if (map[l][y][x] >= 16 && map[l][y][x] < 24)
			{
				tileRect.position.x = (map[l][y][x] - 16) * tileRect.size.x;
				tileRect.position.y = tileRect.size.y*2;
			}
			if (map[l][y][x] >= 24 && map[l][y][x] < 32)
			{
				tileRect.position.x = (map[l][y][x] - 24) * tileRect.size.x;
				tileRect.position.y = tileRect.size.y*3;
			}
			if (map[l][y][x] >= 32 && map[l][y][x] < 40)
			{
				tileRect.position.x = (map[l][y][x] - 32) * tileRect.size.x;
				tileRect.position.y = tileRect.size.y*4;
			}

			sfSprite_setTextureRect(tileSprite, tileRect);
			sfVector2f pos = { x * tileRect.size.x, y * tileRect.size.y };
			sfSprite_setPosition(tileSprite, pos);
			sfRenderWindow_drawSprite(_window, tileSprite, NULL);
			}
		}
	}


	/////////////////////////////////////////////////////
	////                                             ////
	////   GESTION DU SPRITE SELECTIONNER AFICHER    ////
	////                                             ////
	/////////////////////////////////////////////////////

	if (state == EDITOR)
	{
		if (mouseOnPalette(_window))
		{
			sfRenderWindow_setMouseCursorVisible(_window, true); // curseur normal sur le panneau
		}
		else
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
	}
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
	for (int l = 0; l < NB_LAYERS; l++)
	{
		if (map[l][nextPosInTab.y][nextPosInTab.x] >= 3 && map[l][nextPosInTab.y][nextPosInTab.x] <= 39 ||
			map[l][nextPosInTab2.y][nextPosInTab2.x] >= 3 && map[l][nextPosInTab2.y][nextPosInTab2.x] <= 39)
		{
			return true; // retourne sfTrue si collision
		}
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

	for (int l = 0; l < NB_LAYERS; l++)
	{
		for (int y = 0; y < MAP_WIDTH; y++)
		{
			for (int x = 0; x < MAP_HEIGHT; x++)
				fprintf(fichier, "%d ", map[l][x][y]);
			fprintf(fichier, "\n");
		}
		fprintf(fichier, "\n"); // ligne vide entre deux couches
	}
	fclose(fichier);
	return true;
}

void saveMapBin()
{
	fichier = fopen("../Data/MAP/map_bin.bin", "wb");

	fwrite(map, sizeof(int), NB_LAYERS * MAP_HEIGHT * MAP_WIDTH, fichier);

	fclose(fichier);
	return true;
}

void destroyMap()
{

}