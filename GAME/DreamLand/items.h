#pragma once
#include "tools.h"


typedef struct KeyItems keyItems;
struct keyItems {
	sfSprite* sprite;

	bool hasItems;
};





void initsItems();