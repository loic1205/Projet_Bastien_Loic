#include "tools.h"



int main()
{
	sfVideoMode mode = { WIDTH_WINDOW_GAME / 2, HEIGHT_WINDOW_GAME / 2, 32 }; // fenêtre de jeu 
	sfRenderWindow* window = sfRenderWindow_create(mode, "CSFML Window", sfResize | sfClose, sfWindowed, NULL);

}