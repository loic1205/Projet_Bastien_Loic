#include "tools.h"
#include "player.h"
#include "chest.h"
#include "map.h"
#include "PNJ.h"
#include "menu.h"


int main()
{
	//////////////////////////
	//		  Inits 		//
	//////////////////////////

	sfVideoMode mode = { WIDTH_WINDOW_GAME / 2, HEIGHT_WINDOW_GAME / 2, 32 }; // fenêtre de jeu 
	sfRenderWindow* window = sfRenderWindow_create(mode, "CSFML Window", sfResize | sfClose, sfWindowed, NULL);
	sfEvent event;
	posView = (sfVector2f){ 100.f, 50.f };
	posEditorView = (sfVector2f){ (MAP_WIDTH * TILE_SIZE) / 2, (MAP_HEIGHT * TILE_SIZE) / 2 };


	initTools();
	initPlayer();
	initMap();
	initPNJ();
	initMenu();
	state = MENU;


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

		// Dimensions de la map
		sfVector2f mapSize = { MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE };

		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}

		if ((state == GAME || state == EDITOR) && sfKeyboard_isScancodePressed(sfScanEscape))
			state = PAUSE_MENU;


		//////////////////////////
		//		  Update		//
		//////////////////////////

		updateMap(window);
		updatePlayer();
		updatePNJ();

		if(state == MENU)
			updateMenu(window);

		if (state == SETTINGS)
			updateSettings(window);

		if (state == PAUSE_MENU)
			updatePauseMenu(window);



		//////////////////////////
		//		  Display		//
		//////////////////////////

		sfRenderWindow_clear(window, sfBlack);
		if (state == GAME)
		{
			/////////////////////////////////////////////////////
			////                                             ////
			////      GESTION DE LA VUE SUR LE JOUEUR        ////
			////                                             ////
			/////////////////////////////////////////////////////

			// Récupération de la position du joueur
			sfVector2f playerCenter = { 0.0f, 0.0f };
			playerCenter.x = position.x + irectPlayer.size.x / 2.0f;
			playerCenter.y = position.y + irectPlayer.size.y / 2.0f;

			// Récupération de la taille de la vue
			sfVector2f viewSize = sfView_getSize(view);

			// Calcul des limites de la caméra 
			float halfWidth = viewSize.x / 2.0f; // on attribut a cette variable la moitié de la taille de la vue en largeur
			float halfHeight = viewSize.y / 2.0f; // on attribut a cette variable la moitié de la taille de la vue en longueur

			// Limite gauche et droite
			if (viewSize.x >= mapSize.x) // vérifie si la map est plus petite que la vue (on l'affiche au centre)
				playerCenter.x = mapSize.x / 2.0f;
			else
			{
				if (playerCenter.x < halfWidth) // si le joueur est trop proche du bord gauche on arrête la caméra a la moitié de la taille de la vue pour pas dépasser
					playerCenter.x = halfWidth;

				if (playerCenter.x > mapSize.x - halfWidth) // pareil pour la droite
					playerCenter.x = mapSize.x - halfWidth;
			}

			// Limite haut et bas
			if (viewSize.y >= mapSize.y) // idem pour la map trop petite en hauteur (on la met au centre)
				playerCenter.y = mapSize.y / 2.0f;
			else
			{
				if (playerCenter.y < halfHeight) // la limite en haut
					playerCenter.y = halfHeight;

				if (playerCenter.y > mapSize.y - halfHeight) // la limite en bas
					playerCenter.y = mapSize.y - halfHeight;
			}

			// Mise à jour de la caméra
			sfView_setCenter(view, playerCenter);

			//View player
			sfView_setCenter(view, playerCenter);
			sfRenderWindow_setView(window, view);
			displayMap(window);
			//displayChest(window);
			//displayPNJ(window);
			displayPlayer(window);

			//View minimap
			sfView_setCenter(view, posViewMinimap);
			sfRenderWindow_setView(window, viewMinimap);
			displayMap(window);
			//displayChest(window);
			//displayPNJ(window);
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
		if (state == MENU || state == SETTINGS || state == PAUSE_MENU)
		{
			sfRenderWindow_setView(window, sfRenderWindow_getDefaultView(window));

			if (state != SETTINGS)
				displayBackground(window);

			displayMenu(window);
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