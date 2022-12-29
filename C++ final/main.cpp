#include "ThePacmanGame.h"

using  std::cin;
using  std::cout;
using std::getline;


int main(int argc, char* argv[])
{
	fstream boardfile;
	fstream stepfile;
	fstream resfile;
	int gameMode = 0,userChoise=0;
	
		if (argc == 1)
		gameMode = 1;

		if (strcmp(argv[1], "[-silent]") == 0)
			gameMode = 4;
		if ((strcmp(argv[1],"-save") == 0))// && (strcmp(argv[2], "[-silent]") == 0))
			gameMode = 2;
		if ((strcmp(argv[1],"-load") == 0)) //&& (strcmp(argv[2], "[-silent]") == 0))
			gameMode = 3;
	
		clear_screen();
		ThePacmanGame p;
		if (p.GetNumOfBoard() <= 0)
		{
			cout << "No screen files was found.";
			return 0;
		}
		else
		{
			vector<string>	files = p.getScreenFiles();
			enum { WON = 1, LOSE = 0 };
			bool withcolors = false;
			int level;
			bool breakplay = false;
			switch (gameMode)
			{
				//Simple Option
				case 1:
				{
				int totalPacmanMoves = 1;
				level = p.Selectlevel();
				for (int i = 0; i < p.GetNumOfBoard(); i++)
				{
					boardfile.open(files[i], ios_base::in);
					int res;
					if (breakplay != true)
					{
						try
						{
							res = p.StartGame(boardfile, stepfile, resfile, p, level, 1, totalPacmanMoves);
						}
						catch (const string& msg) { clear_screen(); cout << msg << endl; return 1; }
						if (res == WON)
						{
							totalPacmanMoves = 0;
							continue;
						}
						else if (res == LOSE)
						{
							clear_screen();
							breakplay = true;
							break;
						}
					}

				}
				//if won after all boards:
				resfile << "Won after:" << totalPacmanMoves << endl;
				boardfile.close();
				stepfile.close();
				resfile.close();
				break;
			}
				//Save Option
				case 2:
				{
				level = p.Selectlevel();
				int totalPacmanMoves = 1;
				for (int i = 0; i < p.GetNumOfBoard(); i++)
				{
					int res;
					boardfile.open(files[i], ios_base::in);
					string stepfilename = "pacman_" + std::to_string(i) + ".steps";
					stepfile.open(stepfilename, ios_base::out);
					string resname = "pacman_" + std::to_string(i) + ".result";
					resfile.open(resname, ios_base::out);
					if (breakplay != true)
					{
						try
						{
							res = p.StartGame(boardfile, stepfile, resfile, p, level, 2, totalPacmanMoves);
							boardfile.close();

						}
						catch (string& msg)
						{
							clear_screen();
							cout << msg << endl;
							return 1;
						}
						if (res == WON)
						{
							totalPacmanMoves = 0;
						continue;
						}
						else if (res == LOSE)
						{
							breakplay = true;
							break;
						}
						
					}
					//if won after all boards:
					//resfile << "Won after:" << totalPacmanMoves << endl;
					
				}
				//Load Option
				break;
			}
				//load option
				case 3:
				{
				int totalPacmanMoves = 1;
				for (int i = 0; i < p.GetNumOfBoard(); i++)
				{
					try{FindStepsFiles(p.GetNumOfBoard());}
					catch (const string& msg) { clear_screen(); cout << msg << endl; return 1; }
					int res;
					totalPacmanMoves = 0;
					boardfile.open(files[i], ios_base::in);
					string stepfilename = "pacman_" + std::to_string(i) + ".steps";
					stepfile.open(stepfilename, ios_base::in);
					string resname = "pacman_" + std::to_string(i) + ".result";
					resfile.open(resname, ios_base::in);
					if (breakplay != true)
					{
						try {
						res = p.StartGame(boardfile, stepfile, resfile, p, 1, 3, totalPacmanMoves);
						boardfile.close();
						}
						catch (string& msg)
						{
							clear_screen();
							cout << msg << endl;
							return 1;
						}
						if (res == WON)
						{
							clear_screen();
							continue;
						}
						else if (res == LOSE)
						{
							clear_screen();
							breakplay = true;
							break;
						}
					}
				}
				break;
			}
				//Silence Option
				case 4: {
					int res,totalPacmanMoves = 1;
					for (int i = 0; i < p.GetNumOfBoard(); i++)
					{
						try { FindStepsFiles(p.GetNumOfBoard()); }
						catch (const string& msg) { clear_screen(); cout << msg << endl; return 1; }
						int res;
						totalPacmanMoves = 0;
						boardfile.open(files[i], ios_base::in);
						string stepfilename = "pacman_" + std::to_string(i) + ".steps";
						stepfile.open(stepfilename, ios_base::in);
						string resname = "pacman_" + std::to_string(i) + ".result";
						resfile.open(resname, ios_base::in);
						if (breakplay != true)
						{
							try {
								res = p.StartGame(boardfile, stepfile, resfile, p, 1, 4, totalPacmanMoves);
								boardfile.close();
							}
							catch (string& msg)
							{
								clear_screen();
								cout << msg << endl;
								return 1;
							}
							if (res == WON)
							{
								clear_screen();
								continue;
							}
							else if (res == LOSE)
							{
								clear_screen();
								breakplay = true;
								break;
							}
						}
					}
					break;
				}
			
			}

		}
	
}

