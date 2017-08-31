#include <iostream>
using namespace std;

char pos[10] = {'o','1','2','3','4','5','6','7','8','9'};

int checkwin();
void board();

int main()
{
	int player = 1,i,choice;

	char mark;
	do
	{
		board();
		player=(player%2)?1:2;

		cout << "Player " << player << ", enter a number:  ";
		cin >> choice;

		mark=(player == 1) ? 'X' : 'O';

		if((choice>=1&&choice<=9)&&pos[choice]==choice+48)
			pos[choice]=mark;
		else
		{
			cout<<"Invalid move ";

			player--;
			cin.ignore();
			cin.get();
		}
		i=checkwin();

		player++;
	}while(i==-1);
	board();
	if(i==1)

		cout<<"==>\aPlayer "<<--player<<" win ";
	else
		cout<<"==>\aGame draw";

	cin.ignore();
	cin.get();
	return 0;
}


int checkwin()
{
	if (pos[1] == pos[2] && pos[2] == pos[3])

		return 1;
	else if (pos[4] == pos[5] && pos[5] == pos[6])

		return 1;
	else if (pos[7] == pos[8] && pos[8] == pos[9])

		return 1;
	else if (pos[1] == pos[4] && pos[4] == pos[7])

		return 1;
	else if (pos[2] == pos[5] && pos[5] == pos[8])

		return 1;
	else if (pos[3] == pos[6] && pos[6] == pos[9])

		return 1;
	else if (pos[1] == pos[5] && pos[5] == pos[9])

		return 1;
	else if (pos[3] == pos[5] && pos[5] == pos[7])

		return 1;
	else if (pos[1] != '1' && pos[2] != '2' && pos[3] != '3' 
                    && pos[4] != '4' && pos[5] != '5' && pos[6] != '6' 
                  && pos[7] != '7' && pos[8] != '8' && pos[9] != '9')

		return 0;
	else
		return -1;
}


void board()
{
	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << pos[1] << "  |  " << pos[2] << "  |  " << pos[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << pos[4] << "  |  " << pos[5] << "  |  " << pos[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << pos[7] << "  |  " << pos[8] << "  |  " << pos[9] << endl;

	cout << "     |     |     " << endl << endl;
}
