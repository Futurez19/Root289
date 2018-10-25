#pragma once

#include <iostream>
#include <string>

#include <iostream>

// Initializes base statistics for pieces.
void initScarab(Piece, int, int);
void initPyramid(Piece, int, int);
void initAnubis(Piece, int, int);
void initSphinx(Piece, int, int);
void initPharoah(Piece, int, int);

//Piece interactions.
void rotateCCW(Piece);
void rotateCW(Piece);

//int deflect(laser,piece);


// Scarab Object
class Piece {
public:


	int player; //Which player does this piece belong to? Should be declared upon piece declaration.
	
	bool destroyed = false;	//Not sure how to remove it from board, so just check if destroyed first.

	bool hasMirror = false; // Checks if has mirror

	bool hasLaser = false; // For the sphinx. Otherwise False

	// Denotes what piece it is.
	bool isScarab = false;
	bool isAnubis = false;
	bool isPyramid = false;
	bool isSphinx = false;
	bool isPharoah = false;

	//Checks active mirror intake angles or defense angle.
	bool up = false;	
	bool down = false;
	bool left = false;
	bool right = false;

	int angle; //A int signifying the angle of the mirror , 1 = orient1 , 2 = orient2 etc..


	// How the pieces are drawn line by line. includes orientations

	std::string Orient1;


	std::string Orient2;


	std::string Orient3;


	std::string Orient4;

private:
};