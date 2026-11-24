#pragma once
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <Windows.h>
#include <CSFML/Graphics.h>
#include <CSFML/Audio.h>
#include <math.h>

#define TEXTURE_PATH "..\\Data\\Textures\\"
#define SOUND_PATH "..\\Data\\Son\\"
#define MAP_X 40
#define MAP_Y 80
#define TILE_SIZE 32
#define WINDOW_SIZE_X 1280
#define WINDOW_SIZE_Y 640




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


typedef enum { BAS, DROITE, GAUCHE, HAUT }Direction;
typedef enum {MENU, GAME, EDITOR }State;
State state;
FILE* fichier;
sfView* editorView;



void initTools();
void restartClock();
float getDeltaTime();

void saisie_nomFichier(char* nomFichier);

void saisie_Format(char* strFormat);

int ouverture_Fichier(char* nomFichier, char* mode_acces);

int irand(int _min, int _max);
