#include "Game.h"

using namespace std;

int main()
{
	srand(time(0));
	Game game = Game();
	for (int i = 0; i < 5; i++)
	{
		if (i == 0) { game.chooseCharacter(); }
		if (i == 1 || i == 2) { game.upgradeCharacter(); }
		if (i == 3 || i == 4) { game.changeCharacter(); }
		game.chooseEnemy();
		if (game.fight() == 0)		// fight() = 1 <=> Игрок победил
		{
			game.lose();
			break;
		}
		if (i == 4) game.win();
	}

	return 0;
}