#pragma once
#include "tools.h"

#define NB_LAYERS 3
extern int map[NB_LAYERS][MAP_HEIGHT][MAP_WIDTH];
extern int currentLayer;

void initMap();
void initMapBin();
void updateMap(sfRenderWindow* _window);
void displayMap(sfRenderWindow* _window);
void saveMap();
void saveMapBin();
void destroyMap();

bool collisionMapPlayer(sfFloatRect _sprite, Direction _direction, sfVector2f _vitesse);