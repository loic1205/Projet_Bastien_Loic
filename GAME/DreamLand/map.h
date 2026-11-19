#pragma once
#include "tools.h"

#define MAX_SUMMON 4

void initMap();
void initMapBin();
void updateMap(sfRenderWindow* _window);
void displayMap(sfRenderWindow* _window);
void displaySummon(sfRenderWindow* _window);
void displayEditorTile(sfRenderWindow* _window);
void saveMap();
void saveMapBin();
void destroyMap();

bool collisionMapPlayer(sfFloatRect _sprite, Direction _direction, sfVector2f _vitesse);