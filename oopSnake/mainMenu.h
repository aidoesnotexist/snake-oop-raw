#pragma once

#include <iostream>
#include "Windows.h"
#include <conio.h>

// Class that implemets main menu behavior
class mainMenu
{
	bool controls;

public:
	mainMenu();
	~mainMenu() {};

	bool start;
	bool exit;

	void DisplayControls();

	void Update();
	void Render();
};

