#pragma once
#include "tools.h"


typedef struct KeyItems KeyItems;
struct KeyItems {
	sfSprite* sprite;
	sfVector2f position;
	bool hasItem;
};

KeyItems keys[4];


void initsItems();
void updateItems();
void displayItems(sfRenderWindow* _window);





