#include "tools.h"
#include "chest.h"
#include "player.h"
#include "map.h"

sfVector2f posView = { 100.0f, 50.f };
sfVector2f posEditorView = { (MAP_WIDTH * TILE_SIZE) / 2, (MAP_HEIGHT * TILE_SIZE) / 2 };

int main()
{
	//////////////////////////
	//		  Inits 		//
	//////////////////////////

	sfVideoMode mode = { WIDTH_WINDOW_GAME / 2, HEIGHT_WINDOW_GAME / 2, 32 }; // fenêtre de jeu 
	sfRenderWindow* window = sfRenderWindow_create(mode, "CSFML Window", sfResize | sfClose, sfWindowed, NULL);
	sfEvent event;

	initTools();
	initPlayer();
	initMap();
	state = GAME;


	//////////////////////////
	//		   View			//
	//////////////////////////

	editorView = sfView_createFromRect((sfFloatRect) { 0.0f, 0.0f, MAP_WIDTH* TILE_SIZE, MAP_HEIGHT* TILE_SIZE });

	sfView* viewMinimap = sfView_createFromRect((sfFloatRect) { 0.0f, 0.0f, MAP_WIDTH* TILE_SIZE, MAP_HEIGHT* TILE_SIZE });
	sfVector2f posViewMinimap = { 0.f, 0.f };
	sfView_setViewport(viewMinimap, (sfFloatRect) { 0.75f, 0.0f, 0.25f, 0.25f });


	sfView* view = sfView_createFromRect((sfFloatRect) { HEIGHT_WINDOW_GAME / 2, WIDTH_WINDOW_GAME / 2, 100.f, 50.f });
	sfView_zoom(view, 3.2f);


	//////////////////////////
	//      Game Loop		//
	//////////////////////////

	while (sfRenderWindow_isOpen(window))
	{
		restartClock();
		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}

		//////////////////////////
		//		  Update		//
		//////////////////////////
		
		updatePlayer();
		updateMap(window);


		//////////////////////////
		//		  Display		//
		//////////////////////////
		sfRenderWindow_clear(window, sfBlack);
		if (state == GAME)
		{
			//View player
			sfView_setCenter(view, posView);
			sfRenderWindow_setView(window, view);
			displayMap(window);
			//displayChest(window);
			displayPlayer(window);

			//View minimap
			sfRenderWindow_setView(window, viewMinimap);
			displayMap(window);
			//displayChest(window);
			displayPlayer(window);
		}
		if (state == EDITOR)
		{
			//View editor
			sfView_setCenter(editorView, posEditorView);
			sfRenderWindow_setView(window, editorView);
			//displayChest(window);
			displayMap(window);
		}
		sfRenderWindow_display(window);
	}	
	//////////////////////////
	//		   Save		    //
	//////////////////////////
	saveMap();
	saveMapBin();

	return 0;
}