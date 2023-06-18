#include "mainMenu.h"

mainMenu::mainMenu()
	: start{ false }, exit{ false }, controls{ false } {}

void mainMenu::DisplayControls()
{
	std::cout << "\n\n\n\n\n\n\n\n";
	std::cout << "\t\t\t   Move the snake with WASDbuttons and find the food to eat." << std::endl;
	std::cout << "\t\t\t   As you eat food the snake gets bigger.  You have to avoid" << std::endl;
	std::cout << "\t\t\t   the map bounds and the obstacles which will be spawned as" << std::endl;
	std::cout << "\t\t\t   as you get bigger. Snakes dont eat snakes so avoid eating" << std::endl;
	std::cout << "\t\t\t   your own body.  If you eat slowly you will lose parts one" << std::endl;
	std::cout << "\t\t\t   one by one, so pay attantion to the time.	Good luck!" << std::endl;
	std::cout << std::endl << "\t\t\t   1. Back";
}

void mainMenu::Update()
{
	if (_kbhit() && !controls)
	{
		start = controls = exit = false;
		switch (_getch())
		{
		case '1':
			start = true;
			break;
		case '2':
			controls = true;
			break;
		case '3':
			exit = true;
			break;
		}
	}
	else if (controls)
	{
		if (_kbhit() && _getch() == '1')
			controls = false;
	}
}

void mainMenu::Render()
{
	system("CLS");

	if (controls)
		DisplayControls();
	else
	{
		std::cout << "\n\n\n\n\n\n\n\n\n";
		std::cout << "\t\t\t\t\t\t---SNAKEoop---" << std::endl << std::endl;
		std::cout << "\t\t\t\t\t\t1. New Game" << std::endl;
		std::cout << "\t\t\t\t\t\t2. How to play" << std::endl;
		std::cout << "\t\t\t\t\t\t3. Exit" << std::endl;
	}
	Sleep(100);
}


