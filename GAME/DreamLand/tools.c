#include "tools.h"
sfTime sftime;
sfClock* sfclock;



void initTools()
{
	sfclock = sfClock_create();
	srand(time(NULL));
}

void restartClock()
{
	sftime = sfClock_restart(sfclock);
}

float getDeltaTime()
{
	return sfTime_asSeconds(sftime);
}
