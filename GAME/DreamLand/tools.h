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





bool generalSound;
bool sfxSound;
bool musicSound;
bool isTalking;
bool player_Gmode;
bool endGame;

typedef enum { BAS, HAUT, GAUCHE, DROITE }Direction;
typedef enum { MENU, GAME, EDITOR, PAUSE_MENU, SETTINGS, END }State;
State state;
FILE* fichier;

sfView* editorView;
sfVector2f posView;
sfVector2f posEditorView;
sfVector2f position;

sfSprite* spPlayer;


void initTools();
void restartClock();
float getDeltaTime();


