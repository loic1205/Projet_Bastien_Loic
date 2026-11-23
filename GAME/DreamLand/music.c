#include "music.h"



sfMusic* musiqueMenu;
sfMusic* musiqueGame;



void initMusic()
{
	musiqueMenu = sfMusic_createFromFile(SOUND_PATH"music/musicMenu.mp3");
	sfMusic_setLooping(musiqueMenu, true);
	sfMusic_setVolume(musiqueMenu, 10.0f);


	musiqueGame = sfMusic_createFromFile(SOUND_PATH"music/musicGame.mp3");
	sfMusic_setLooping(musiqueGame, true);
	sfMusic_setVolume(musiqueGame, 10.0f);
}

void updateMusic()
{
	//musique

	switch (state)
	{
		case MENU:

			if (sfMusic_getStatus(musiqueGame) == sfPlaying)
				sfMusic_stop(musiqueGame);

			if (sfMusic_getStatus(musiqueMenu) != sfPlaying)
				sfMusic_play(musiqueMenu);

			break;

		case GAME:

			if (sfMusic_getStatus(musiqueMenu) == sfPlaying)
				sfMusic_stop(musiqueMenu);

			if (sfMusic_getStatus(musiqueGame) != sfPlaying)
				sfMusic_play(musiqueGame);

			break;

		case EDITOR:

			if (sfMusic_getStatus(musiqueMenu) == sfPlaying)
				sfMusic_stop(musiqueMenu);

			if (sfMusic_getStatus(musiqueGame) != sfPlaying)
				sfMusic_play(musiqueGame);

			break;

		case PAUSE_MENU:

			if (sfMusic_getStatus(musiqueGame) != sfPlaying)
				sfMusic_play(musiqueGame);

			break;

		case SETTINGS:

			if (sfMusic_getStatus(musiqueGame) == sfPlaying)
				sfMusic_stop(musiqueGame);

			if (sfMusic_getStatus(musiqueMenu) != sfPlaying)
				sfMusic_play(musiqueMenu);


			break;

		default:
			printf("Erreur state");
	}



}
