#include "Fruit.h"
#include "ThePacmanGame.h"

bool Fruit::move(char fruitnextchar, char fruitcurchar, bool IfMenuIsFirst,int rowBoard,int colBoard,fstream& outputfile,string obj,bool withFiles,int& caseOpt)
{

	if (fruitnextchar == '#' || this->getx() > colBoard || this->gety() > rowBoard||this->getx()<0||this->gety()<0)
	{
		if (this->getfruitDirection() == 8)
		{
			if(caseOpt!=4)
			Point::draw(' ', IfMenuIsFirst);
		}
		else
		{
			if (caseOpt != 4)
			Point::draw(figure, IfMenuIsFirst);
		}
		int randomIndex;
		int DirectionArr[4] = { 1,3,5,7 };
		srand(time(NULL));
		randomIndex = rand() % 4;
		while (DirectionArr[randomIndex] == fruitdirection || DirectionArr[randomIndex] - 1 == fruitdirection)
		{
			randomIndex = rand() % 4;
		}
		fruitdirection = DirectionArr[randomIndex];

		return true;
	}
	else if (fruitcurchar == ' ' && this->getx() < colBoard && this->gety() < rowBoard && this->getx() > 0 && this->gety() > 0)
	{
		if (caseOpt != 4)
		Point::draw(figure, IfMenuIsFirst);
		if (caseOpt != 4)
		Point::draw(' ', IfMenuIsFirst);
		Point::move(fruitdirection, rowBoard, colBoard,outputfile,obj,withFiles);
		if (caseOpt != 4)
		Point::draw(figure, IfMenuIsFirst);
		return false;
	}
	else if (fruitcurchar == '.' && this->getx() < colBoard && this->gety() < rowBoard && this->getx() > 0 && this->gety() > 0)
	{
		if (caseOpt != 4)
		Point::draw(figure, IfMenuIsFirst);
		if (caseOpt != 4)
		Point::draw('.', IfMenuIsFirst);
		Point::move(fruitdirection,rowBoard,colBoard,outputfile,obj,withFiles);
		if (caseOpt != 4)
		Point::draw(figure, IfMenuIsFirst);
		return false;
	}
}
int Fruit::getfruitDirection()
{
	return fruitdirection;
}


