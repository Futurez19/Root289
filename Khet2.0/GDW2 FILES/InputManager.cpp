#include <iostream>
#include <ctime>
#include <Windows.h>

#include "InputManager.h"
#include "ConsoleManager.h"

// Arrays that hold information about the current keyboard state
bool keys[0xFF] { false };
bool keysLast[0xFF] { false };
float keysTime[0xFF] { 0 };

clock_t timeStart = 0, timeEnd = 0, timeElapsed = 0;

POINT cursorPos;

// To be called at the beginning of every frame
// Updates the keys buffer to reflect the current keyboard state
void updateButtons() {

	// Calculate how many clock cycles have happened since the last time updateKeys was executed
	timeStart = clock();
	timeElapsed = timeStart - timeEnd;

	// Actually update the keyboard state
	for (int i = 0; i < 0xFF; i++) {
		keysLast[i] = keys[i];
		keys[i] = GetAsyncKeyState(i) == 0 ? 0 : 1;
	}

	// Update the cursor position
	updateMousePos();

	timeEnd = timeStart;
}

void updateMousePos() {
	GetCursorPos(&cursorPos);
	ScreenToClient(GetConsoleWindow(), &cursorPos);
}

// Returns true if the key is currently actuated
bool isButton(unsigned char event) {
	updateButtons();
	return keys[event];
}

// Returns true if the key was pressed this frame
bool isButtonDown(unsigned char event) {
	updateButtons();
	return keys[event] && !keysLast[event];
}

// returns true if the key was released this frame
bool isButtonUp(unsigned char event) {
	updateButtons();
	return !keys[event] && keysLast[event];
}

// returns true if the key has been held for the specified amount of time in seconds
bool isButtonHeld(unsigned char event, float time) {
	updateButtons();

	// return false if the key is not being held
	if (!isButton(event)) {
		keysTime[event] = 0;
		return false;
	}

	// update the variable that specifies how long the key has been held
	keysTime[event] += float (timeElapsed / (double) CLOCKS_PER_SEC);
	
	// return true if the key has been held for the specified amount of time
	if (keysTime[event] >= time)
		return true;
	else 
		return false;
}

int getMouseX() {
	return cursorPos.x;
}

int getMouseY() {
	return cursorPos.y;
}
