#include "shmup.h"
#include "player.h"

int	main(void)
{
	t_game	game;

	init();
	game_loop(&game.player);
	endwin();
	return (0);
}
