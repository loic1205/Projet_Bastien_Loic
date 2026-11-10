#pragma once
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <Windows.h>
#include <CSFML/Graphics.h>
#include <CSFML/Audio.h>
#include <math.h>

#define TEXTURE_PATH "..\\Data\\textures\\"
#define MAP_PATH "..\\Data\\maps\\"
#define MAP_WIDTH 80
#define MAP_HEIGHT 40
#define TILE_SIZE 32
#define WIDTH_WINDOW_GAME MAP_WIDTH * TILE_SIZE
#define HEIGHT_WINDOW_GAME MAP_HEIGHT * TILE_SIZE


typedef struct Chest Chest;
struct Chest {
	sfVector2i coo;
	bool isOpen;
	float ChestanimTimer;
	int ChestframeX;
	sfTexture* texChest;
	sfSprite* spChest;
	sfIntRect irectChest;
	sfVector2f position;
};



typedef enum { BAS, HAUT, GAUCHE, DROITE }Direction;
typedef enum { MENU, GAME, EDITOR }State;
State state;
FILE* fichier;
sfView* editorView;






void initTools();
void restartClock();
float getDeltaTime();


