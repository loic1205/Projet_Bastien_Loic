#include "tools.h"

sfVector2f posEditorView = { (MAP_WIDTH * TILE_SIZE) / 2, (MAP_HEIGHT * TILE_SIZE) / 2 };

int main()
{
	sfVideoMode mode = { WIDTH_WINDOW_GAME / 2, HEIGHT_WINDOW_GAME / 2, 32 }; // fenêtre de jeu 
	sfRenderWindow* window = sfRenderWindow_create(mode, "CSFML Window", sfResize | sfClose, sfWindowed, NULL);
	sfEvent event;




	//////////////////////////
	//      Game Loop		//
	//////////////////////////
	while (sfRenderWindow_isOpen(window))
	{
		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}

		//////////////////////////
		//		  Update		//
		//////////////////////////




		//////////////////////////
		//		  Display		//
		//////////////////////////
		sfRenderWindow_clear(window, sfBlack);

		sfRenderWindow_display(window);
	}

	return 0;
}