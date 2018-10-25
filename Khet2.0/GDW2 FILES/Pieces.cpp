#include "Pieces.h"

void initScarab(Piece &scarab, int team, int angle)
{
	scarab.player = team;

	scarab.hasMirror = true;
	scarab.angle = angle;


	scarab.up = true;
	scarab.down = true;
	scarab.left = true;
	scarab.right = true;



	scarab.Orient1 = "\\··";
	scarab.Orient1 += "·\\·";
	scarab.Orient1 += "··\\";

	scarab.Orient2 = "··/";
	scarab.Orient2 += "·/·";
	scarab.Orient2 += "/··";

	scarab.Orient3 = "\\··";
	scarab.Orient3 += "·\\·";
	scarab.Orient3 += "··\\";

	scarab.Orient4 = "··/";
	scarab.Orient4 += "·/·";
	scarab.Orient4 += "/··";


}

void initPyramid(Piece &pyramid, int team, int angle)
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

	pyramid.Orient1 = "\\··";
	pyramid.Orient1 += "#\\·";
	pyramid.Orient1 += "##\\";
//	
	pyramid.Orient2 = "··/";
	pyramid.Orient2 += "·/#";
	pyramid.Orient2 += "/##";
//	
	pyramid.Orient3 = "\\##";
	pyramid.Orient3 += "·\\#";
	pyramid.Orient3 += "··\\";
//	
	pyramid.Orient4 = "##/";
	pyramid.Orient4 += "#/·";
	pyramid.Orient4 += "/··";

}

void initAnubis(Piece &anubis, int team, int angle)
{

	anubis.player = team;
	anubis.hasMirror = true; // it doesnt actually have a mirror
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

	anubis.Orient1 = "---";
	anubis.Orient1 += "###";
	anubis.Orient1 += "###";
	//	
	anubis.Orient2 = "|##";
	anubis.Orient2 += "|##";
	anubis.Orient2 += "|##";		 
	//	
	anubis.Orient3 = "###";
	anubis.Orient3 += "###";
	anubis.Orient3 += "---";
	//	
	anubis.Orient4 = "##|";
	anubis.Orient4 += "##|";
	anubis.Orient4 += "##|";

}

void initSphinx(Piece &sphinx, int team, int angle)
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


	sphinx.Orient1 = "·A·";
	sphinx.Orient1 += "#0#";
	sphinx.Orient1 += "###";
	//	
	sphinx.Orient2 = "·##";
	sphinx.Orient2 += "<0#";
	sphinx.Orient2 += "·##";
	//	
	sphinx.Orient3 = "###";
	sphinx.Orient3 += "#0#";
	sphinx.Orient3 += "·V·";
	//	
	sphinx.Orient4 = "##·";
	sphinx.Orient4 += "#0>";
	sphinx.Orient4 += "##·";
}

void initPharoah(Piece &pharoah, int team, int angle = 1)
{
	pharoah.player = team;
	pharoah.hasMirror = false;
	pharoah.angle = angle;

	pharoah.up = false;
	pharoah.down = false;
	pharoah.left = false;
	pharoah.right = false;

	pharoah.Orient1 = "/-\\";
	pharoah.Orient1 += "-+-";
	pharoah.Orient1 += "\\-/";
	//	

}

void rotateCCW(Piece p1)
{	
	if (!(p1.angle == 4))
	{
		p1.angle += 1;
	}
	else
		p1.angle = 1;

	switch (p1.angle)  // may not even need this but just incase
	{
	case 1:
		//redraw the piece with Orient 1
		break;
	case 2:
		//redaw the piece with Orient 2
		break;
	case 3:
		//redraw the piece with Orient 3
		break;
	case 4:
		//redraw the piece with Orient 4
		break;
	}
}

void rotateCW(Piece p1)
{
	if (!(p1.angle == 1))
	{
		p1.angle -= 1;
	}
	else
		p1.angle = 4;

	switch (p1.angle)
	{
	case 1:
		//redraw the piece with Orient 1
		break;
	case 2:
		//redaw the piece with Orient 2
		break;
	case 3:
		//redraw the piece with Orient 3
		break;
	case 4:
		//redraw the piece with Orient 4
		break;
	}
}


//Needs a laser class//obj//struct that has a variable that represents it's direct.
//In this case i used 1-4 to represent the cardinal directions. (1 = up / 2 = left / 3 = down / 4 = right)
//I apologize for the messy switches.

//int deflect(Laser laser, Piece p1)
//{
	//if (p1.hasMirror)
	//{
	//	switch (laser.angle)//dependant on incoming laser
	//	{
	//	case 1:		  //laser is going up;

	//		if (p1.down)
	//		{//first checks that it can recieve the laser
	//			if (p1.left)//sets the laser's direction depending on resultant mirror
	//			{
	//				laser.angle = 2;
	//			}
	//			else if (p1.right)
	//			{
	//				laser.angle = 4;
	//			}
	//			else if (p1.isAnubis)
	//				stop();//stop the laser
	//			else
	//				// piece dies
	//		}
	//		else
	//			//piece dies

	//		break;
	//	case 2:		 // laser going left

	//		if (p1.right)
	//		{//first checks that it can recieve the laser
	//			if (p1.up)//sets the laser's direction depending on resultant mirror
	//			{
	//				laser.angle = 1;
	//			}
	//			else if (p1.down)
	//			{
	//				laser.angle = 3;
	//			}
	//			else if (p1.isAnubis)
	//				stop();//stop the laser
	//			else
	//				// piece dies
	//		}
	//		else
	//			//piece dies
	//		break;
	//	case 3:		 // laser going down
	//		if (p1.up)
	//		{//first checks that it can recieve the laser
	//			if (p1.left)//sets the laser's direction depending on resultant mirror
	//			{
	//				laser.angle = 2;
	//			}
	//			else if (p1.right)
	//			{
	//				laser.angle = 4;
	//			}
	//			else if (p1.isAnubis)
	//				stop();//stop the laser
	//			else
	//				// piece dies
	//		}
	//		else
	//			//piece dies
	//		break;
	//	case 4:		  //laser going right
	//		if (p1.left)
	//		{//first checks that it can recieve the laser
	//			if (p1.up)//sets the laser's direction depending on resultant mirror
	//			{
	//				laser.angle = 1;
	//			}
	//			else if (p1.down)
	//			{
	//				laser.angle = 3;
	//			}
	//			else if (p1.isAnubis)
	//				stop();//stop the laser
	//			else
	//				// piece dies
	//		}
	//		else
	//			//piece dies
	//		break;
	//	}
 //   }
	//else
	//	//piece dies

//}
