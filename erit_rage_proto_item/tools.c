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
int iRand(int _min, int _max)
{
	if (_max > _min)
		return rand() % (_max - _min + 1) + _min;
	else
		return _min;
}

// Fonction pour gérer si la souris passe sur un élément ayant une hitbox pour position en float et retourner une valeur
int isInsideMouse(sfVector2f item, sfFloatRect obstacle)
{
	if (item.x > obstacle.left &&
		item.x < (obstacle.width + obstacle.left) &&
		item.y > obstacle.top &&
		item.y < (obstacle.top + obstacle.height))
	{

		return 1;

	}
	return 0;
}

// Fonction pour gérer si la souris passe sur un élément ayant une hitbox pour position en int et retourner une valeur
int isInsideMousei(sfVector2i item, sfFloatRect obstacle)
{
	if (item.x > obstacle.left &&
		item.x < (obstacle.width + obstacle.left) &&
		item.y > obstacle.top &&
		item.y < (obstacle.top + obstacle.height))
	{
		return 1;
	}
	return 0;
}

// Fonction pour gérer si le joueur passe sur un élément ayant une hitbox pour position en int et retourner une valeur
int isInsidePlayer(sfFloatRect player, sfFloatRect obstacle)
{

	if (player.left > obstacle.left &&
		player.left < (obstacle.width + obstacle.left) &&
		player.top > obstacle.top &&
		player.top < (obstacle.top + obstacle.height) ||
		player.left + player.width > obstacle.left &&
		player.left + player.width < (obstacle.width + obstacle.left) &&
		player.top + player.height > obstacle.top &&
		player.top + player.height < (obstacle.top + obstacle.height) ||
		player.left  > obstacle.left &&
		player.left < (obstacle.width + obstacle.left) &&
		player.top + player.height > obstacle.top &&
		player.top + player.height < (obstacle.top + obstacle.height) ||
		player.left + player.width > obstacle.left &&
		player.left + player.width< (obstacle.width + obstacle.left) &&
		player.top  > obstacle.top &&
		player.top < (obstacle.top + obstacle.height)
		)
	{
		return 1;

	}


	return 0;
}

// fonction pour initialiser tout les inits dans le main et rendre plus propre
// cette fonction est liée à tous les inits de notre code

// fonction pour rassembler les updates de dans le main et rendre plus propre

// fonction de display en fonction du state 
