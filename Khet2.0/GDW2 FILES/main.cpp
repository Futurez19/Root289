#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>

#include "InputManager.h"
#include "ConsoleManager.h"

#define COLS 200
#define ROWS 50

bool running = true;

int main()
{
	initConsole(COLS, ROWS);
	setCursorVisibility(false);
	setConsoleWindowTitle("Khet 2.0");

	while (running) {

		if (isButton(Events::Escape)) {
			running = false;
			continue;
		}

		// vv Input Checking vv



		// ^^ Input Checking ^^

		// vv Game Logic vv



		// ^^ Game Logic ^^
		
		// vv Output vv 
		setCursorPos(0, 0);
		//cls();

		printf("x: %d y: %d           \n", getMouseX(), getMouseY());
	
		setCursorPos(COLS, ROWS);
		// ^^ Output ^^
	}
	return 0;
}