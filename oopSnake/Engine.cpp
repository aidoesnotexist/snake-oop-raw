#include "Engine.h"

Engine::Engine()
	: map{ new Map{} }, snake{ new Snake{} }, fruit{ new Fruit }, obstacle{ new Obstacle },
	direction{ DIRECTION::STATIC }, nextMove{ DIRECTION::STATIC }, running{ true }, time{ 15 }
{
	fruit->Spawn();
}

Engine::~Engine()
{
	system("CLS");
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  GAME OVER" << std::endl;
	std::cout << "\t\t\t\t\t        You scored: " << snake->size() << std::endl;
	Sleep(2000);

	delete obstacle;
	delete fruit;
	delete snake;
	delete map;
}

void Engine::updateKeyboardInput()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			nextMove = DIRECTION::UPWARD;
			break;
		case 's':
			nextMove = DIRECTION::DOWNWARD;
			break;
		case 'a':
			nextMove = DIRECTION::LEFT;
			break;
		case 'd':
			nextMove = DIRECTION::RIGHT;
			break;
		default:
			nextMove = DIRECTION::STATIC;
			break;
		}
	}
}

void Engine::CheckCorrectInput()
{
	if (direction == DIRECTION::UPWARD && nextMove == DIRECTION::DOWNWARD)
		direction = DIRECTION::UPWARD;
	else if (direction == DIRECTION::DOWNWARD && nextMove == DIRECTION::UPWARD)
		direction = DIRECTION::DOWNWARD;
	else if (direction == DIRECTION::LEFT && nextMove == DIRECTION::RIGHT)
		direction = DIRECTION::LEFT;
	else if (direction == DIRECTION::RIGHT && nextMove == DIRECTION::LEFT)
		direction = DIRECTION::RIGHT;
	else
		direction = nextMove;

}

void Engine::updateSnake()
{
	snake->Move(direction);
	snake->Slither();
	if (snake->size() >= 5 && snake->cannibalism)
		running = false;
}

void Engine::Update()
{
	srand(std::time(NULL));

	updateKeyboardInput();
	CheckCorrectInput();

	if (direction != DIRECTION::STATIC)		// Once the snake appeares it is static. When the button is
	{										// pressed it starts moving
		updateSnake();
		timer.start();
	}

	fruit->LoadToMap();
	obstacle->LoadToMap();
	try {									// The map is basically a 2d vector. If we try loading a snakeHead 
		snake->LoadToMap();					// out of the vector bounds, function at() will throw an exception
	}
	catch (const std::out_of_range& ex) {
		running = false;
	}
	if (obstacle->CheckIfCollide(snake->getSnake()->getPosition()))		// Checking the collision of all the 
		running = false;												// obsicales with the snake head

	if (snake->Contains(fruit->getPosition()))		// If snake head collides with the fruit a new one should
	{												// be spawned, a new body node added
		do {
			fruit->Spawn();
		} while (obstacle->CheckIfCollide(fruit->getPosition()));
		snake->AddNode();

		if (snake->size() >= 5)			// If the snake reaches the size of 5 obstacles are being spawned
			obstacle->Spawn();

		time = 15;
	}
	if (std::chrono::duration_cast<std::chrono::seconds>
		(timer.GetElapsedTime()).count() >= 1)
	{
		timer.reset();
		--time;
	}
	if (time == 0)
	{
		snake->DeleteNode();
		if (snake->size() == 0)
			running = false;
		time = 15;
	}
}

void Engine::Render()
{
	system("CLS");

	std::cout << std::endl << "SCORE: " << snake->size() << ' ' << "TIME" << ' ' << time;
	if (direction == DIRECTION::STATIC)
		std::cout << "\tUse WASD to start";
	std::cout << std::endl << std::endl;

	map->Draw();
	map->clear();

	std::this_thread::sleep_for(std::chrono::milliseconds(25));
	if (direction == DIRECTION::UPWARD ||
		direction == DIRECTION::DOWNWARD)
		Sleep(25);
}
