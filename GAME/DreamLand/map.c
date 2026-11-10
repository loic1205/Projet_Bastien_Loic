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
int tileType = 3;

void initMap()
{
	tileTexture = sfTexture_createFromFile(TEXTURE_PATH"tileDamien.png", NULL);
	tileSprite = sfSprite_create(tileTexture);


	fichier = fopen("../Data/MAP/map.txt", "rt");

	if (fichier)
	{
		char tile_initMap = 0;

		for (int y = 0; y < MAP_WIDTH; y++)
		{
			for (int x = 0; x < MAP_HEIGHT; x++)
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


		if (sfMouse_isButtonPressed(sfMouseRight))
		{
			sfVector2i mousePos = sfMouse_getPositionRenderWindow(_window);

			int x = (mousePos.x) * 2 / TILE_SIZE;
			int y = (mousePos.y) * 2 / TILE_SIZE;
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
			int x = (mousePos.x) * 2 / TILE_SIZE;
			int y = (mousePos.y) * 2 / TILE_SIZE;

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
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
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
