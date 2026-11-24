#include "tools.h"
sfTime sftime;
sfClock* sfclock;



//////////////////////////////////////////////////
// - fonction random entre min et max           //
// - Retourne un entier                         //
//////////////////////////////////////////////////
int irand(int _min, int _max)
{
	return rand() % (_max - _min + 1) + _min;
}

void restartClock()
{
	sftime = sfClock_restart(sfclock);
}

float getDeltaTime()
{

	return sfTime_asSeconds(sftime);
}

void saisie_nomFichier(char* nomFichier)
{
	char fileName[20];
	char file[40] = "../Data/";

	printf("Entrez le nom de votre fichier: ");
	scanf("%s", fileName);
	printf("\n");
	strcat(nomFichier, file);
	strcat(nomFichier, fileName);
}

void saisie_Format(char* strFormat)
{
	printf("entrez r pour lire le fichier, w pour ecrire dedans ou a pour ajouter: ");
	scanf("%s", strFormat);
	printf("\n");
}

int ouverture_Fichier(char* nomFichier, char* mode_acces)
{
	fichier = fopen(nomFichier, mode_acces);
	if (!fichier)
	{
		printf("ce fichier n'existe pas");
		return 0;
	}
	else
		return 1;
}



void initTools()
{
	sfclock = sfClock_create();
	srand(time(NULL));
}



