#include <iostream>
#include <thread>
#include <cstdlib>
#include "mainMenu.h"
#include "Engine.h"

using namespace std;

int main()
{
_begin:;
{
	mainMenu menu;
	while (!menu.start)
	{
		thread sub_thread([&menu]() {
			menu.Update(); });
		sub_thread.join();

		menu.Render();

		if (menu.exit)
			exit(0);
	}
}

{
	Engine game;
	while (game.running)
	{
		thread sub_thread([&game]() {
			game.Update(); });
		sub_thread.join();

		game.Render();

		if (!game.running)
			goto _begin;
	}
}
return 0;
}