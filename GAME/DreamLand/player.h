#pragma once
#include "tools.h"

extern sfVector2f position;
extern sfIntRect irectPlayer;
extern sfVector2f velocity;

void initPlayer();
void updatePlayer();
void displayPlayer(sfRenderWindow* _window);
void destroyPLayer();