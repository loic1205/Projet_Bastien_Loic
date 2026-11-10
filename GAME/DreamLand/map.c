#include "map.h"

//texture
float keyTimer = 0.0f;
sfTexture* tileTexture;
sfSprite* tileSprite;
sfIntRect tileRect = { 0, 0, 32, 32 };
extern sfVector2f position;


//view
extern sfVector2f posEditorView;



//chest
extern Chest chest[20];
sfVector2i chestPos;
bool chestAlreadyexist = false;

int map[MAP_HEIGHT][MAP_WIDTH];
int tileTypeX = 0;
int tileTypeY = 0;

void initMap()
{
	tileTexture = sfTexture_createFromFile(TEXTURE_PATH"/tileset/Document.png", NULL);
	tileSprite = sfSprite_create(tileTexture);


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
		if (sfKeyboard_isScancodePressed(sfScanE) && keyTimer >= 0.2f)
		{
			state = EDITOR;
			keyTimer = 0.0f;


		}

		if (sfMouse_isButtonPressed(sfMouseLeft) && keyTimer > 0.2f)
		{
			keyTimer = 0.0f;
			sfVector2i mouseCoo = sfMouse_getPositionRenderWindow(_window);
		}

		if (sfKeyboard_isKeyPressed(sfKeyF) && keyTimer > 0.2f)
		{
			int i = 0;
			for (int z = 0; z < sizeof(chest) / sizeof(chest[0]); z++)
			{
				if (chest[z].coo.x)
					i++;
			}
			for (int y = 0; y < MAP_WIDTH; y++)
			{
				for (int x = 0; x < MAP_HEIGHT; x++)
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


		


		if (sfKeyboard_isKeyPressed(sfKeyNum1) && !sfKeyboard_isKeyPressed(sfKeyLControl))
			tileTypeX = 0;
		if (sfKeyboard_isKeyPressed(sfKeyNum2) && !sfKeyboard_isKeyPressed(sfKeyLControl))
			tileTypeX = 1;
		if (sfKeyboard_isKeyPressed(sfKeyNum3) && !sfKeyboard_isKeyPressed(sfKeyLControl))
			tileTypeX = 2;
		if (sfKeyboard_isKeyPressed(sfKeyNum4) && !sfKeyboard_isKeyPressed(sfKeyLControl))
			tileTypeX = 3;
		if (sfKeyboard_isKeyPressed(sfKeyNum5) && !sfKeyboard_isKeyPressed(sfKeyLControl))
			tileTypeX = 4;
		if (sfKeyboard_isKeyPressed(sfKeyNum6) && !sfKeyboard_isKeyPressed(sfKeyLControl))
			tileTypeX = 5;
		if (sfKeyboard_isKeyPressed(sfKeyNum7) && !sfKeyboard_isKeyPressed(sfKeyLControl))
			tileTypeX = 6;
		if (sfKeyboard_isKeyPressed(sfKeyNum8) && !sfKeyboard_isKeyPressed(sfKeyLControl))
			tileTypeX = 7;

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

			int x = (mousePos.x) * 2 / TILE_SIZE;
			int y = (mousePos.y) * 2 / TILE_SIZE;
			map[y][x] = 32;
		}

		if (sfMouse_isButtonPressed(sfMouseLeft))
		{
			sfVector2i mousePos = sfMouse_getPositionRenderWindow(_window);
			int x = (mousePos.x * 2) / TILE_SIZE;
			int y = (mousePos.y * 2) / TILE_SIZE;

			map[y][x] = tileTypeX + (8 * tileTypeY);
		}

		if (sfMouse_isButtonPressed(sfMouseMiddle))
		{
			sfVector2i mousePos = sfMouse_getPositionRenderWindow(_window);
			int x = (mousePos.x) * 2 / TILE_SIZE;
			int y = (mousePos.y) * 2 / TILE_SIZE;

			tileTypeX = (map[y][x] % 8);
			tileTypeY = (map[y][x]/8);
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
		tileRect.position.x = tileTypeX * tileRect.size.x;
		tileRect.position.y = tileTypeY * tileRect.size.y;
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

void displayEditorTile(sfRenderWindow* _window)
{

}

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
