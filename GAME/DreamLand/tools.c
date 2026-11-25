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


//bool collisionPlayer_Sprite(sfFloatRect _fRectPlayer, sfFloatRect _fRectSprite, Direction _direction, sfVector2f _vitesse)
//{
//	const sfVector2f playerCenter = { _fRectPlayer.position.x + _fRectPlayer.size.x / 2.0f, _fRectPlayer.position.y + _fRectPlayer.size.y / 2.0f, };
//	const sfVector2f spriteCenter = { _fRectSprite.position.x + _fRectSprite.size.x / 2.0f, _fRectSprite.position.y + _fRectSprite.size.y / 2.0f, };
//
//	sfVector2f nextPosInMap = playerCenter;
//
//	if (_direction = HAUT)
//		nextPosInMap.y -= _vitesse.y * getDeltaTime();
//	else if (_direction = BAS)
//		nextPosInMap.y += _vitesse.y * getDeltaTime();
//	if (_direction = GAUCHE)
//		nextPosInMap.x -= _vitesse.x * getDeltaTime();
//	else if (_direction = DROITE)
//		nextPosInMap.x += _vitesse.x * getDeltaTime();
//
//	const float zoneX = (_fRectPlayer.size.x - _fRectSprite.size.x) / 2.0f;
//	const float zoneY = (_fRectPlayer.size.y - _fRectSprite.size.y) / 2.0f;
//
//	float distXNow = fabs(playerCenter.x - spriteCenter.x);
//	float distYNow = fabs(playerCenter.y - spriteCenter.y);
//	float distXNext = fabs(nextPosInMap.x - spriteCenter.x);
//	float distYNext = fabs(nextPosInMap.y - spriteCenter.y);
//
//	if (distXNext >= zoneX || distYNext >= zoneY)
//		return false;
//
//
//	if (distXNext >= distXNow || distYNext >= distYNow)
//		return true;
//
//	return false;
//}


bool collisionPlayer_Sprite(sfFloatRect _fRectPlayer, sfFloatRect _fRectSprite, Direction _direction, sfVector2f _vitesse)
{
	// on déplace le rectangle du joueur selon la direction qu'il prend
	if (_direction == HAUT)
		_fRectPlayer.position.y -= _vitesse.y * getDeltaTime();
	else if (_direction == BAS)
		_fRectPlayer.position.y += _vitesse.y * getDeltaTime();
	else if (_direction == GAUCHE)
		_fRectPlayer.position.x -= _vitesse.x * getDeltaTime();
	else if (_direction == DROITE)
		_fRectPlayer.position.x += _vitesse.x * getDeltaTime();

	// true dès que les deux rectangles se touchent ou se chevauchent
	return _fRectPlayer.position.x <= _fRectSprite.position.x + _fRectSprite.size.x
		&& _fRectPlayer.position.x + _fRectPlayer.size.x >= _fRectSprite.position.x
		&& _fRectPlayer.position.y <= _fRectSprite.position.y + _fRectSprite.size.y
		&& _fRectPlayer.position.y + _fRectPlayer.size.y >= _fRectSprite.position.y;
}