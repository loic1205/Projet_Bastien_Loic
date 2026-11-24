#include "map.h"

//🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐🥐
float keyTimer = 0.0f;
sfSprite* tileSprite;
sfTexture* tileTexture;
sfIntRect tileRect = { 0, 0, 32, 32 };
int tileType = 3;
extern sfVector2f position;
extern sfVector2f posEditorView;
extern Chest chest[20];
bool chestAlreadyexist = false;

int map[MAP_X][MAP_Y];
 


void initMap()
{
	tileTexture = sfTexture_createFromFile(TEXTURE_PATH"tileDamien.png", NULL);
	tileSprite = sfSprite_create(tileTexture);


	fichier = fopen("../Data/MAP/map.txt", "rt");

	if(fichier)
	{
		char tile_initMap = 0;

		for (int y = 0; y < MAP_Y; y++)
		{
			for (int x = 0; x < MAP_X; x++)
			{
				tile_initMap = fgetc(fichier);
				map[x][y] = tile_initMap - 48;
			}
			tile_initMap = fgetc(fichier);
		}
	}
	else
	{
		fichier = fopen("../Data/MAP/map.txt", "w+");
	}
	fclose(fichier);
}

void initMapBin()
{
	tileTexture = sfTexture_createFromFile(TEXTURE_PATH"tileset1.png", NULL);
	tileSprite = sfSprite_create(tileTexture);

	fichier = fopen("../Data/MAP/map_bin.bin", "rb");

	if (fichier)
	{
		fread(map, sizeof(int), MAP_X * MAP_Y, fichier);
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
		if (sfKeyboard_isScancodePressed(sfScanE) && keyTimer >= 0.2f)
		{
			state = EDITOR;
			keyTimer = 0.0f;


		}

		if (sfMouse_isButtonPressed(sfMouseLeft) && keyTimer > 0.2f)
		{
			keyTimer = 0.0f;
			sfVector2i mouseCoo = sfMouse_getPositionRenderWindow(_window);
			printf("x:%d y:%d\n", mouseCoo.x, mouseCoo.y);
		}

		if (sfKeyboard_isKeyPressed(sfKeyF) && keyTimer > 0.2f)
		{
			int i = 0;
			for (int z = 0; z < sizeof(chest) / sizeof(chest[0]); z++)
			{
				if (chest[z].coo.x)
					i++;
			}
			for (int y = 0; y < MAP_Y; y++)
			{
				for (int x = 0; x < MAP_X; x++)
				{
					if (map[x][y] == 6)
					{
						keyTimer = 0.0f;
						chestPos = (sfVector2i){ (y * tileRect.size.y), (x * tileRect.size.x) };
						float distance = (float)sqrt(pow((chestPos.x - (position.x) + 17 / 2), 2) + pow((chestPos.y - 5 - (position.y) + 23 / 2), 2));


						


						chestAlreadyexist = false;

						for (int z = 0; z < sizeof(chest) / sizeof(chest[0]); z++)
						{
							if (chest[z].coo.x == chestPos.x && chest[z].coo.y == chestPos.y)
								chestAlreadyexist = true;
						}


						if (distance <= 40.0f && !chestAlreadyexist)
						{
							chest[i].coo = chestPos;
							chest[i].isOpen = false;
							chest[i].ChestanimTimer = 0.0f;
							chest[i].ChestframeX = 0;
							chest[i].irectChest = (sfIntRect){ 0, 0, 32, 32 };
							chest[i].position = (sfVector2f){ (float)chestPos.x, (float)chestPos.y };
							i++;
						}

						

						
							
					}
				}
			}
		}







	}
	else if (state == EDITOR)
	{
		if (sfKeyboard_isScancodePressed(sfScanE) && keyTimer >= 0.2f)
		{
			state = GAME;
			keyTimer = 0.0f;	
		}


		if (sfMouse_isButtonPressed(sfMouseRight))
		{
			sfVector2i mousePos = sfMouse_getPositionRenderWindow(_window);

			int x = (mousePos.x)*2 / TILE_SIZE;
			int y = (mousePos.y)*2 / TILE_SIZE;
			map[y][x] = 0;
		}


		if (sfKeyboard_isKeyPressed(sfKeyNum1))
			tileType = 1;
		if (sfKeyboard_isKeyPressed(sfKeyNum2))
			tileType = 2;
		if (sfKeyboard_isKeyPressed(sfKeyNum3))
			tileType = 3;
		if (sfKeyboard_isKeyPressed(sfKeyNum4))
			tileType = 4;
		if (sfKeyboard_isKeyPressed(sfKeyNum5))
			tileType = 5;
		if (sfKeyboard_isKeyPressed(sfKeyNum6))
			tileType = 6;
		if (sfKeyboard_isKeyPressed(sfKeyNum7))
			tileType = 7;


		if (sfMouse_isButtonPressed(sfMouseLeft))
		{
			sfVector2i mousePos = sfMouse_getPositionRenderWindow(_window);
			int x = (mousePos.x * 2) / TILE_SIZE;
			int y = (mousePos.y * 2) / TILE_SIZE;

			map[y][x] = tileType;

		}

		if (sfMouse_isButtonPressed(sfMouseMiddle))
		{

			sfVector2i mousePos = sfMouse_getPositionRenderWindow(_window);
			int x = (mousePos.x)*2 / TILE_SIZE;
			int y = (mousePos.y)*2 / TILE_SIZE;

			tileType = map[y][x];
		}

		if (sfKeyboard_isScancodePressed(sfScanNumpadPlus))
		{
			sfView_zoom(editorView, 0.999f);

		}
		
		if (sfKeyboard_isScancodePressed(sfScanNumpadMinus))
		{
			sfView_zoom(editorView, 1.001f);

		}
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

void displayMap(sfRenderWindow* _window)
{
	for (int y = 0; y < MAP_X; y++)
	{
		for (int x = 0; x < MAP_Y; x++)
		{
			tileRect.position.x = map[y][x] * tileRect.size.x;
			sfSprite_setTextureRect(tileSprite, tileRect);
			sfVector2f pos = { x * tileRect.size.x, y * tileRect.size.y };
			sfSprite_setPosition(tileSprite, pos);
			sfRenderWindow_drawSprite(_window, tileSprite, NULL);
		}
	}

	if (state == EDITOR)
	{
		tileRect.position.x = tileType * tileRect.size.x;
		sfSprite_setTextureRect(tileSprite, tileRect);
		sfVector2i iMousePos = sfMouse_getPositionRenderWindow(_window);
		iMousePos.x *= 2;
		iMousePos.y *= 2;
		sfVector2f fMousePos = { (float)iMousePos.x - (tileRect.size.x / 2) ,(float)iMousePos.y - (tileRect.size.x / 2) };
		sfSprite_setPosition(tileSprite, fMousePos);
		sfRenderWindow_drawSprite(_window, tileSprite, NULL);
		sfRenderWindow_setMouseCursorVisible(_window, false);
	}


}

void destroyMap()
{


}

void saveMap()
{
	fichier = fopen("../Data/MAP/map.txt", "wt");

	for (int y = 0; y < MAP_Y; y++)
	{
		for (int x = 0;x < MAP_X; x++)
			fprintf(fichier, "%d", map[x][y]);
		fprintf(fichier, "\n");
	}
	fclose(fichier);
	return true;
}

void saveMapBin()
{
	fichier = fopen("../Data/MAP/map_bin.bin", "wb");

	fwrite(map, sizeof(int), MAP_X * MAP_Y, fichier);

	fclose(fichier);
	return true;
}

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
	// Si la ou les case(s) est une case non traversable ( entre 3 et 6 )
	if (map[nextPosInTab.y][nextPosInTab.x] >= 3 && map[nextPosInTab.y][nextPosInTab.x] <= 6 ||
		map[nextPosInTab2.y][nextPosInTab2.x] >= 3 && map[nextPosInTab2.y][nextPosInTab2.x] <= 6)
	{
		return true; // retourne sfTrue si il y a collision
	}

	return false; // retourne sfFalse si pas de collision


}











/*bool collisionMapPlayer(sfFloatRect _sprite, direction _direction, sfVector2f _vitesse, int _tilesMap[10][20])
{
	sfVector2f nextPoint1, nextPoint2;
	sfVector2f point1, point2;

	switch (_direction)
	{
	case HAUT:
		nextPoint1.x = _sprite.position.x / 32;
		nextPoint1.y = _sprite.position.y / 32;

		nextPoint2.x = (_sprite.position.x + _sprite.size.x) / 32;
		nextPoint2.y = _sprite.position.y / 32;

		if (_tilesMap[nextPoint1.x][nextPoint1.y - _vitesse.y] >= 3 || _tilesMap[nextPoint1.x][nextPoint1.y - _vitesse.y] <= 6 && _tilesMap[nextPoint2.x][nextPoint2.y - _vitesse.y] >= 3 || _tilesMap[nextPoint2.x][nextPoint2.y - _vitesse.y] <= 6)
			return true;
		else
			return false;
		break;

	case BAS:
		point1.x = _sprite.position.x;
		point1.y = _sprite.position.y + _sprite.size.y;

		point2.x = _sprite.position.x + _sprite.size.x;
		point2.y = _sprite.position.y + _sprite.size.y;

		if (_tilesMap[(int)(point1.x / 32)][(int)((point1.y + _vitesse.y) / 32)] == 1 || _tilesMap[(int)(point1.x / 32)][(int)((point1.y + _vitesse.y) / 32)] == 2 && _tilesMap[(int)(point2.x / 32)][(int)((point2.y + _vitesse.y) / 32)] == 1 || _tilesMap[(int)(point2.x / 32)][(int)((point2.y + _vitesse.y) / 32)] == 2)
			return false;
		else
			return true;
		break;



	case DROITE:
		point1.x = _sprite.position.x + _sprite.size.x;
		point1.y = _sprite.position.y;

		point2.x = _sprite.position.x + _sprite.size.x;
		point2.y = _sprite.position.y + _sprite.size.y;

		if (_tilesMap[(int)((point1.x + _vitesse.x) / 32)][(int)(point1.y / 32)] == 1 || _tilesMap[(int)((point1.x + _vitesse.x) / 32)][(int)(point1.y / 32)] == 2 && _tilesMap[(int)((point2.x + _vitesse.x) / 32)][(int)(point2.y / 32)] == 1 || _tilesMap[(int)((point2.x + _vitesse.x) / 32)][(int)(point2.y / 32)] == 2)
			return false;
		else
			return true;
		break;


	case GAUCHE:
		point1.x = _sprite.position.x;
		point1.y = _sprite.position.y;

		point2.x = _sprite.position.x;
		point2.y = _sprite.position.y + _sprite.size.y;

		if (_tilesMap[(int)((point1.x - _vitesse.x) / 32)][(int)(point1.y / 32)] == 1 || _tilesMap[(int)((point1.x - _vitesse.x) / 32)][(int)(point1.y / 32)] == 2 && _tilesMap[(int)((point2.x - _vitesse.x) / 32)][(int)(point2.y / 32)] == 1 || _tilesMap[(int)((point2.x - _vitesse.x) / 32)][(int)(point2.y / 32)] == 2)
			return false;
		else
			return true;
		break;


	default:
		return false;
	}


}*/