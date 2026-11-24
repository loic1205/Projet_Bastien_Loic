#pragma once
#include "tools.h"

#define PALETTE_RATIO  0.15f // largeur du panneau = 15% de la fenêtre
#define TILESHEET_COLS 8
#define TILESHEET_ROWS 5
#define NB_LAYERS 3
extern int map[NB_LAYERS][MAP_HEIGHT][MAP_WIDTH];
extern int currentLayer;

sfVector2i chestPos;

void initMap();
void initMapBin();
void updateMap(sfRenderWindow* _window);
void displayMap(sfRenderWindow* _window);
void displayTilePalette(sfRenderWindow* _window);
void saveMap();
void saveMapBin();
void destroyMap();

bool collisionMapPlayer(sfFloatRect _sprite, Direction _direction, sfVector2f _vitesse);
bool mouseOnPalette(sfRenderWindow* _window);
