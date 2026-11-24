#pragma once
#include "tools.h"

sfVector2i chestPos;


void initMap();
void initMapBin();
void updateMap(sfRenderWindow* _window);
void displayMap(sfRenderWindow* _window);
void destroyMap();
void saveMap();
void saveMapBin();

bool collisionMapPlayer(sfFloatRect _sprite, Direction _direction, sfVector2f _vitesse);









