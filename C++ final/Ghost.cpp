#include "Ghost.h"
#include "ThePacmanGame.h"

bool Ghost::move(char ghostnextchar, char ghostcurchar, bool IfMenuIsFirst, char level, int rowBoard, int colBoard,fstream& outputfile,string obj,bool withFiles,int& caseOpt)
{

	if (ghostnextchar == '#' || this->getx() > colBoard || this->gety() > rowBoard|| this->getx() < 0 || this->gety() < 0)
	{	
		if(caseOpt!=4)
		Point::draw(figure,IfMenuIsFirst);
		int randomIndex;
		int DirectionArr[4] = { 1,3,5,7 };
		srand(time(NULL));
		randomIndex = rand() % 4; 
		while ((ghostdirection == DirectionArr[randomIndex]) || (ghostdirection == (DirectionArr[randomIndex] - 1)))
		{
			randomIndex = rand() % 4;
		}
		ghostdirection = DirectionArr[randomIndex];
		return true;
	}
	else if (ghostcurchar == ' ' && this->getx() < colBoard && this->gety() < rowBoard && this->getx() > 0 && this->gety() > 0)
	{
		if (caseOpt != 4)
		Point::draw(figure,IfMenuIsFirst);
		if (caseOpt != 4)
		Point::draw(' ', IfMenuIsFirst);
		Point::move(ghostdirection, rowBoard, colBoard,outputfile,obj,withFiles);
		if (caseOpt != 4)
		Point::draw(figure, IfMenuIsFirst);
		return false;
	}
	else if (ghostcurchar == '.' && this->getx() < colBoard && this->gety() < rowBoard && this->getx() > 0 && this->gety() > 0)
	{
		if (caseOpt != 4)
		Point::draw(figure, IfMenuIsFirst);
		if (caseOpt != 4)
		Point::draw('.', IfMenuIsFirst);
		Point::move(ghostdirection, rowBoard, colBoard,outputfile,obj,withFiles);
		if (caseOpt != 4)
		Point::draw(figure, IfMenuIsFirst);
		return false;
	}
	
}
int Ghost::getghostDirection()
{
	return ghostdirection;
}
