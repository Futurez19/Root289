#include "Pieces.h"
#include <iostream>

void initScarab(Piece, int, int);
void initPyramid(Piece, int, int);
void initAnubis(Piece, int, int);
void initSphinx(Piece, int, int);
void initPharoah(Piece, int, int);

void initScarab(Piece scarab, int team, int angle)
{
	scarab.player = team;

	scarab.hasMirror = true;
	scarab.angle = angle;


	scarab.up = true;
	scarab.down = true;
	scarab.left = true;
	scarab.right = true;



	scarab.line_1Orient1 = "\``";
	scarab.line_2Orient1 = "`\`";
	scarab.line_3Orient1 = "``\\";

	scarab.line_1Orient2 = "``/";
	scarab.line_2Orient2 = "`/`";
	scarab.line_3Orient2 = "/``";

	scarab.line_1Orient3 = "\``";
	scarab.line_2Orient3 = "`\`";
	scarab.line_3Orient3 = "``\\";

	scarab.line_1Orient4 = "``/";
	scarab.line_2Orient4 = "`/`";
	scarab.line_3Orient4 = "/``";


}

void initPyramid(Piece pyramid, int team, int angle)
{

	pyramid.player = team;
	pyramid.hasMirror = true;
	pyramid.angle = angle;
	
	switch (pyramid.angle)
	{
	 case 1:
		 pyramid.up = true;
		 pyramid.down = false;
		 pyramid.left = false;
		 pyramid.right = true;
		break;
	 case 2:
		 pyramid.up = true;
		 pyramid.down = false;
		 pyramid.left = true;
		 pyramid.right = false;
		 break;
	 case 3:
		 pyramid.up = false;
		 pyramid.down = true;
		 pyramid.left = true;
		 pyramid.right = false;
		 break;
	 case 4:
		 pyramid.up = false;
		 pyramid.down = true;
		 pyramid.left = false;
		 pyramid.right = true;
		 break;
	 default:
		 std::cout << "OOF something broke.";
		 
	}

	pyramid.line_1Orient1 = "\``";
	pyramid.line_2Orient1 = "#\`";
	pyramid.line_3Orient1 = "##\\";
//	
	pyramid.line_1Orient2 = "``/";
	pyramid.line_2Orient2 = "`/#";
	pyramid.line_3Orient2 = "/##";
//	
	pyramid.line_1Orient3 = "\##";
	pyramid.line_2Orient3 = "`\#";
	pyramid.line_3Orient3 = "``\\";
//	
	pyramid.line_1Orient4 = "##/";
	pyramid.line_2Orient4 = "#/`";
	pyramid.line_3Orient4 = "/``";

}

void initAnubis(Piece anubis, int team, int angle)
{

	anubis.player = team;
	anubis.hasMirror = false;
	anubis.angle = angle;

	switch (anubis.angle)
	{
	case 1:
		anubis.up = true;
		anubis.down = false;
		anubis.left = false;
		anubis.right = true;
		break;
	case 2:
		anubis.up = false;
		anubis.down = false;
		anubis.left = true;
		anubis.right = false;
		break;
	case 3:
		anubis.up = false;
		anubis.down = true;
		anubis.left = false;
		anubis.right = false;
		break;
	case 4:
		anubis.up = false;
		anubis.down = false;
		anubis.left = false;
		anubis.right = true;
		break;
	default:
		std::cout << "OOF something broke.";

	}

	anubis.line_1Orient1 = "---";
	anubis.line_2Orient1 = "###";
	anubis.line_3Orient1 = "###";
	//	
	anubis.line_1Orient2 = "|##";
	anubis.line_2Orient2 = "|##";
	anubis.line_3Orient2 = "|##";		 
	//	
	anubis.line_1Orient3 = "###";
	anubis.line_2Orient3 = "###";
	anubis.line_3Orient3 = "---";
	//	
	anubis.line_1Orient4 = "##|";
	anubis.line_2Orient4 = "##|";
	anubis.line_3Orient4 = "##|";

}

void initSphinx(Piece sphinx, int team, int angle)
{
	sphinx.player = team;
	sphinx.hasMirror = false;
	sphinx.hasLaser = true;
	sphinx.angle = angle;

	switch (sphinx.angle)
	{
	case 1:
		sphinx.up = true;
		sphinx.down = true;
		sphinx.left = true;
		sphinx.right = true;
		break;
	case 2:
		sphinx.up = true;
		sphinx.down = true;
		sphinx.left = true;
		sphinx.right = true;
		break;
	case 3:
		sphinx.up = true;
		sphinx.down = true;
		sphinx.left = true;
		sphinx.right = true;
		break;
	case 4:
		sphinx.up = true;
		sphinx.down = true;
		sphinx.left = true;
		sphinx.right = true;
		break;
	default:
		std::cout << "OOF something broke.";

	}

	sphinx.line_1Orient1 = "`A`";
	sphinx.line_2Orient1 = "#0#";
	sphinx.line_3Orient1 = "###";
	//	
	sphinx.line_1Orient2 = "`##";
	sphinx.line_2Orient2 = "<0#";
	sphinx.line_3Orient2 = "`##";
	//	
	sphinx.line_1Orient3 = "###";
	sphinx.line_2Orient3 = "#0#";
	sphinx.line_3Orient3 = "`V`";
	//	
	sphinx.line_1Orient4 = "##`";
	sphinx.line_2Orient4 = "#0>";
	sphinx.line_3Orient4 = "##`";
}

void initPharoah(Piece pharoah, int team, int angle = 1)
{
	pharoah.player = team;
	pharoah.hasMirror = false;
	pharoah.angle = angle;

	pharoah.up = false;
	pharoah.down = false;
	pharoah.left = false;
	pharoah.right = false;

	pharoah.line_1Orient1 = "/-\\";
	pharoah.line_2Orient1 = "-+-";
	pharoah.line_3Orient1 = "\-/";
	//	

}
