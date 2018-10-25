#include "Pieces.h"

// Mostly Function definitions

void Piece::initScarab(int team, int angle)
{
	this->player = team;

	this->hasMirror = true;
	this->angle = angle;


	this->up = true;
	this->down = true;
	this->left = true;
	this->right = true;



	this->Orient1 = "\\··";
	this->Orient1 += "·\\·";
	this->Orient1 += "··\\";

	this->Orient2 = "··/";
	this->Orient2 += "·/·";
	this->Orient2 += "/··";

	this->Orient3 = "\\··";
	this->Orient3 += "·\\·";
	this->Orient3 += "··\\";

	this->Orient4 = "··/";
	this->Orient4 += "·/·";
	this->Orient4 += "/··";


}

void Piece::initPyramid(int team, int angle)
{

	this->player = team;
	this->hasMirror = true;
	this->angle = angle;
	
	switch (this->angle)
	{
	 case 1:
		 this->up = true;
		 this->down = false;
		 this->left = false;
		 this->right = true;
		break;
	 case 2:
		 this->up = true;
		 this->down = false;
		 this->left = true;
		 this->right = false;
		 break;
	 case 3:
		 this->up = false;
		 this->down = true;
		 this->left = true;
		 this->right = false;
		 break;
	 case 4:
		 this->up = false;
		 this->down = true;
		 this->left = false;
		 this->right = true;
		 break;
	 default:
		 std::cout << "OOF something broke.";
		 
	}

	this->Orient1 = "\\··";
	this->Orient1 += "#\\·";
	this->Orient1 += "##\\";
//	
	this->Orient2 = "··/";
	this->Orient2 += "·/#";
	this->Orient2 += "/##";
//	
	this->Orient3 = "\\##";
	this->Orient3 += "·\\#";
	this->Orient3 += "··\\";
//	
	this->Orient4 = "##/";
	this->Orient4 += "#/·";
	this->Orient4 += "/··";

}

void Piece::initAnubis(int team, int angle)
{

	this->player = team;
	this->hasMirror = true; // it doesnt actually have a mirror
	this->angle = angle;

	switch (this->angle)
	{
	case 1:
		this->up = true;
		this->down = false;
		this->left = false;
		this->right = true;
		break;
	case 2:
		this->up = false;
		this->down = false;
		this->left = true;
		this->right = false;
		break;
	case 3:
		this->up = false;
		this->down = true;
		this->left = false;
		this->right = false;
		break;
	case 4:
		this->up = false;
		this->down = false;
		this->left = false;
		this->right = true;
		break;
	default:
		std::cout << "OOF something broke.";

	}

	this->Orient1 = "---";
	this->Orient1 += "###";
	this->Orient1 += "###";
	//	
	this->Orient2 = "|##";
	this->Orient2 += "|##";
	this->Orient2 += "|##";		 
	//	
	this->Orient3 = "###";
	this->Orient3 += "###";
	this->Orient3 += "---";
	//	
	this->Orient4 = "##|";
	this->Orient4 += "##|";
	this->Orient4 += "##|";

}

void Piece::initSphinx(int team, int angle)
{
	this->player = team;
	this->hasMirror = false;
	this->hasLaser = true;
	this->angle = angle;

	switch (this->angle)
	{
	case 1:
		this->up = true;
		this->down = true;
		this->left = true;
		this->right = true;
		break;
	case 2:
		this->up = true;
		this->down = true;
		this->left = true;
		this->right = true;
		break;
	case 3:
		this->up = true;
		this->down = true;
		this->left = true;
		this->right = true;
		break;
	case 4:
		this->up = true;
		this->down = true;
		this->left = true;
		this->right = true;
		break;
	default:
		std::cout << "OOF something broke.";

	}


	this->Orient1 = "·A·";
	this->Orient1 += "#0#";
	this->Orient1 += "###";
	//	
	this->Orient2 = "·##";
	this->Orient2 += "<0#";
	this->Orient2 += "·##";
	//	
	this->Orient3 = "###";
	this->Orient3 += "#0#";
	this->Orient3 += "·V·";
	//	
	this->Orient4 = "##·";
	this->Orient4 += "#0>";
	this->Orient4 += "##·";
}

void Piece::initPharoah(int team, int angle = 1)
{
	this->player = team;
	this->hasMirror = false;
	this->angle = angle;

	this->up = false;
	this->down = false;
	this->left = false;
	this->right = false;

	this->Orient1 = "/-\\";
	this->Orient1 += "-+-";
	this->Orient1 += "\\-/";
	//	

}

void Piece::rotateCCW()
{	
	if (!(this->angle == 4))
	{
		this->angle += 1;
	}
	else
		this->angle = 1;

	switch (this->angle)  // may not even need this but just incase
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

void Piece::rotateCW()
{
	if (!(this->angle == 1))
	{
		this->angle -= 1;
	}
	else
		this->angle = 4;

	switch (this->angle)
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
