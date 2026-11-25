#pragma once
#include "tools.h"

extern sfVector2f positionPNJ;

void initPNJ();
void updatePNJ();
void displayPNJ(sfRenderWindow* _window);

bool collisionPlayer_PNJ(sfVector2f _position, Direction _direction, sfVector2f positionPNJ, sfVector2f _vitesse);