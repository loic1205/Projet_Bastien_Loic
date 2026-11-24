#pragma once
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <Windows.h>
#include <CSFML/Graphics.h>
#include <CSFML/Audio.h>
#include <math.h>

#define TEXTURE_PATH "..\\Data\\textures\\"
#define ITEMS_PATH "..\\Data\\textures\\items\\"
#define MAP_PATH "..\\Data\\maps\\"
#define FONT_PATH "..\\Data\\font\\"
#define SOUND_PATH "..\\Data\\sounds\\"
#define MAP_WIDTH 80
#define MAP_HEIGHT 40
#define TILE_SIZE 32
#define WIDTH_WINDOW_GAME MAP_WIDTH * TILE_SIZE
#define HEIGHT_WINDOW_GAME MAP_HEIGHT * TILE_SIZE


typedef struct Chest Chest;
struct Chest 
{
	sfVector2i coo;
	bool isOpen;
	float ChestanimTimer;
	int ChestframeX;
	sfTexture* texChest;
	sfSprite* spChest;
	sfIntRect irectChest;
	sfVector2f position;
};

bool generalSound;
bool sfxSound;
bool musicSound;

typedef enum { BAS, HAUT, GAUCHE, DROITE }Direction;
typedef enum { MENU, GAME, EDITOR, PAUSE_MENU, SETTINGS}State;
bool player_Gmode;
State state;
FILE* fichier;

sfView* editorView;
sfVector2f posView;
sfVector2f posEditorView;




void initTools();
void restartClock();
float getDeltaTime();


