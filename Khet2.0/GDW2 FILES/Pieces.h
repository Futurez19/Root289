#pragma once

#include <iostream>
#include <string>

// Scarab Object
struct Piece {

	int player; //Which player does this piece belong to? Should be declared upon piece declaration.
	
	bool destroyed = false;	//Not sure how to remove it from board, so just check if destroyed first.

	bool hasMirror = false; // Checks if has mirror

	bool hasLaser = false; // For the sphinx. Otherwise False

	//Checks active mirror intake angles or defense angle.
	bool up = false;	
	bool down = false;
	bool left = false;
	bool right = false;

	int angle; //A int signifying the angle of the mirror , 1 = orient1 , 2 = orient2 etc..


	// How the pieces are drawn line by line. includes orientations

	std::string line_1Orient1;
	std::string line_2Orient1;
	std::string line_3Orient1;

	std::string line_1Orient2;
	std::string line_2Orient2;
	std::string line_3Orient2;

	std::string line_1Orient3;
	std::string line_2Orient3;
	std::string line_3Orient3;

	std::string line_1Orient4;
	std::string line_2Orient4;
	std::string line_3Orient4;

};

extern void initScarab(Piece, int, int);
extern void initPyramid(Piece, int, int);
extern void initAnubis(Piece, int, int);
extern void initSphinx(Piece, int, int);
extern void initPharoah(Piece, int, int);