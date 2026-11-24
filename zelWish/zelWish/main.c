#include "tools.h"
#include "map.h"
#include "player.h"
#include "chest.h"

sfVector2f posView = { 650.f, 100.f };
sfVector2f posEditorView = { (MAP_Y * TILE_SIZE) / 2, (MAP_X * TILE_SIZE)/2 };

//ajouter un systeme d'inventaire

//ajouter plusieurs joueur

//ajouter un menu + parametre + choix nombre joueur


int main()
{
	
	sfVideoMode mode = { WINDOW_SIZE_X, WINDOW_SIZE_Y, 32 };
	sfRenderWindow* window = sfRenderWindow_create(mode, "Zelwish", sfResize | sfClose, sfWindowed, NULL);
	sfEvent event;
	float timerMusic = 0.0f;
	int playerNumber = 1;
	//////////////////////////
	//Inits 				//
	//////////////////////////
	initTools();
	initMap();
	//initMapBin();
	initPlayer(playerNumber);
	initChest();
	state = GAME;



	

	//////////////////////////
	//Sound					//
	//////////////////////////
	sfMusic* music = sfMusic_createFromFile(SOUND_PATH"Music.mp3");
	sfMusic_play(music);
	sfMusic_setLooping(music, true);

	/*
	sfSound* sound = sfSound_create();
	sfSoundBuffer* soundBuffer = sfSoundBuffer_createFromFile(SOUND_PATH"Chest.ogg");
	sfSound_setBuffer(sound, soundBuffer);
	*/

	
	//////////////////////////
	//View					//
	//////////////////////////
	editorView = sfView_createFromRect((sfFloatRect) { 0.0f, 0.0f, MAP_Y* TILE_SIZE, MAP_X* TILE_SIZE});

	sfView* viewMinimap = sfView_createFromRect((sfFloatRect) { 0.0f, 0.0f, MAP_Y* TILE_SIZE, MAP_X* TILE_SIZE });
	sfVector2f posViewMinimap = { 0.f, 0.f };
	sfView_setViewport(viewMinimap, (sfFloatRect) { 0.75f, 0.0f, 0.25f, 0.25f });


	sfView* view = sfView_createFromRect((sfFloatRect){ WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 2, 100.f, 50.f });
	sfView_zoom(view, 3.2f);

	//////////////////////////
	//Game Loop				//
	//////////////////////////
	while (sfRenderWindow_isOpen(window))
	{
		restartClock();
		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}
		timerMusic += getDeltaTime();

		if (sfKeyboard_isKeyPressed(sfKeySpace) && sfMusic_getStatus(music) == sfPlaying && timerMusic > 0.2f)
		{
			sfMusic_pause(music);
			timerMusic = 0.0f;
		}
		else if(sfKeyboard_isKeyPressed(sfKeySpace) && sfMusic_getStatus(music) == sfPaused && timerMusic > 0.2f)
		{
			sfMusic_play(music);
			timerMusic = 0.0f;
		}




		//////////////////////////
		//Update				//
		//////////////////////////
		if(state == GAME)
			updatePlayer(playerNumber);
		updateMap(window);
		updateChest();


		//////////////////////////
		//Display				//
		//////////////////////////
		sfRenderWindow_clear(window, sfBlack);

		if (state == GAME)
		{
			//View player
			sfView_setCenter(view, posView);
			sfRenderWindow_setView(window, view);
			displayMap(window);
			displayChest(window);
			displayPlayer(window, playerNumber);

			//View minimap
			sfRenderWindow_setView(window, viewMinimap);
			displayMap(window);
			displayChest(window);
			displayPlayer(window, playerNumber);
		}
		if(state == EDITOR)
		{
			//View editor
			sfView_setCenter(editorView, posEditorView);
			sfRenderWindow_setView(window, editorView);
			displayChest(window);
			displayMap(window);
		}

		sfRenderWindow_display(window);
	}

	//////////////////////////
	//Save					//
	//////////////////////////
	saveMap();
	saveMapBin();

	//////////////////////////
	//Destroy				//
	//////////////////////////
	sfRenderWindow_destroy(window);
	return 0;
}

