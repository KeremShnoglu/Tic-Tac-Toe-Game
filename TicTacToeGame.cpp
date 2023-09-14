#include <iostream>
#include <iomanip>//setw()
#include <cstdlib>//system()
#include <ctime>

using namespace std;
char board[10] = { '0','1','2','3','4','5','6','7','8','9' };//Location in Game Board
char turn; //Player's turn ( X or O )
int location;

int Start_Screen();//Begining Screen
void AI_level1();//This function to singleplayer->easy
int AI_level2();//This function to singleplayer->medium
bool locationcontrol();
int randomnumber();//This function to turn random number
int firsrowcontrol();//1,2,3 locations
int secondrowcontrol();//4,5,6 locations
int thirdrowcontrol();//7,8,9 locations
int firstcolumncontrol();//1,4,7 locations
int secondcolumncontrol();//2,5,8 locations 
int thirdcolumncontrol();//3,6,9 locations
int crosscontrol1();//1,5,9 locations
int crosscontrol2();//3,5,7 locations
void Display_Board();//This function to show the board of Tic Tac Toe Game 
void Player_Turn_TwoPlayer();//Player will make a move in this function 
int gameover();//This function to understand end game 

int main() {
	srand(time(0));
	int number=Start_Screen();
	if (number == 1) {
	k:
		system("cls");
		cout << "(1) Easy Level"<<endl;
		cout << "(2) Medium Level" << endl;
		cout << "Choose number which you want level:";
		int level;
        cin >> level;
		try
		{
			if (level!=1 && level!=2)
			{
				cout << "You haven't choose number between 1 and 2,Try Again" << endl;
                 throw 101;
			}
			
		}
		catch (int error)
		{
			cout << "Error " << error << ":You haven't choose number between 1 and 2,Try Again";
			goto k;
		}

		if (level == 1) {
			while(gameover()!=-1){
				
				Display_Board();
				cout << "Player 1 is you ,Player 2 is AI" << endl;
				AI_level1();
				gameover();
			}
		}
		else if (level == 2) {
			while (gameover() != -1) {
				Display_Board();
				cout << "Player 1 is you ,Player 2 is AI" << endl;
				AI_level2();
				gameover();
			}
		}

	}

	else {
		while (gameover()!=-1)
		{
			Display_Board();
			Player_Turn_TwoPlayer();
			gameover();
		}
	}
	return 0;
}

int Start_Screen() {
b:
	system("cls");
	cout << "-------Welcome The Tic Tac Toe Game-------" << endl << endl;
	cout << "(1) Single Player (Against AI)" << endl;
	cout << "(2) Two Player (Against Your Friend) " << endl;
	cout << "Choose number which you want between 1 and 2 and Start game -->";
	int number;//to start game
	cin >> number;
	if (number == 2 || number == 1) {
		return number;
	}
	else {
		cout << "You haven't choose number between 1 and 2,Try Again" << endl;
		goto b;
	}
}

	bool locationcontrol(int location) {
		return (int)(board[location] != 'X' && board[location] != 'O');
	}

	int randomnumber() {
		return (rand() % 9 + 1);
	}

	int firsrowcontrol() {
		if ((board[1] == 'X' && board[2] == 'X') || (board[1] == 'O' && board[2] == 'O')) {
			board[3] = 'O';
			return -1;
		}
		if ((board[2] == 'X' && board[3] == 'X') || (board[2] == 'O' && board[3] == 'O')) {
			board[1] = 'O';
			return -1;
		}
		if ((board[1] == 'X' && board[3] == 'X') || (board[1] == 'O' && board[3] == 'O')) {
			board[2] = 'O';
			return -1;
		}
	}
	int secondrowcontrol() {
		if ((board[4] == 'X' && board[5] == 'X') || (board[4] == 'O' && board[5] == 'O')) {
			board[6] = 'O';
			return -1;
		}
		if ((board[5] == 'X' && board[6] == 'X') || (board[5] == 'O' && board[6] == 'O')) {
			board[4] = 'O';
			return -1;
		}
		if ((board[4] == 'X' && board[6] == 'X') || (board[4] == 'O' && board[6] == 'O')) {
			board[5] = 'O';
			return -1;
		}
	}
	int thirdrowcontrol() {
		if ((board[7] == 'X' && board[8] == 'X') || (board[7] == 'O' && board[8] == 'O')) {
			board[9] = 'O';
			return -1;
		}
		if ((board[8] == 'X' && board[9] == 'X') || (board[8] == 'O' && board[9] == 'O')) {
			board[7] = 'O';
			return -1;
		}
		if ((board[7] == 'X' && board[9] == 'X') || (board[7] == 'O' && board[9] == 'O')) {
			board[8] = 'O';
			return -1;
		}
	}
	int firstcolumncontrol() {
		if ((board[1] == 'X' && board[4] == 'X') || (board[1] == 'O' && board[4] == 'O')) {
			board[7] = 'O';
			return -1;
		}
		if ((board[1] == 'X' && board[7] == 'X') || (board[1] == 'O' && board[7] == 'O')) {
			board[4] = 'O';
			return -1;
		}
		if ((board[4] == 'X' && board[7] == 'X') || (board[4] == 'O' && board[7] == 'O')) {
			board[1] = 'O';
			return -1;
		}
	}
	int secondcolumncontrol() {
		if ((board[2] == 'X' && board[5] == 'X') || (board[2] == 'O' && board[5] == 'O')) {
			board[8] = 'O';
			return -1;
		}
		if ((board[2] == 'X' && board[8] == 'X') || (board[2] == 'O' && board[8] == 'O')) {
			board[5] = 'O';
			return -1;
		}
		if ((board[5] == 'X' && board[8] == 'X') || (board[5] == 'O' && board[8] == 'O')) {
			board[2] = 'O';
			return -1;
		}
	}
	int thirdcolumncontrol() {
		if ((board[3] == 'X' && board[6] == 'X') || (board[3] == 'O' && board[6] == 'O')) {
			board[9] = 'O';
			return -1;
		}
		if ((board[3] == 'X' && board[9] == 'X') || (board[3] == 'O' && board[9] == 'O')) {
			board[6] = 'O';
			return -1;
		}
		if ((board[9] == 'X' && board[6] == 'X') || (board[9] == 'O' && board[6] == 'O')) {
			board[3] = 'O';
			return -1;
		}
	}
	int crosscontrol1() {
		if ((board[1] == 'X' && board[5] == 'X') || (board[1] == 'O' && board[5] == 'O')) {
			board[9] = 'O';
			return -1;
		}
		if ((board[5] == 'X' && board[9] == 'X') || (board[5] == 'O' && board[9] == 'O')) {
			board[1] = 'O';
			return -1;
		}
		if ((board[1] == 'X' && board[9] == 'X') || (board[1] == 'O' && board[9] == 'O')) {
			board[5] = 'O';
			return -1;
		}
	}
	int crosscontrol2() {
		if ((board[3] == 'X' && board[5] == 'X') || (board[3] == 'O' && board[5] == 'O')) {
			board[7] = 'O';
			return -1;
		}
		if ((board[5] == 'X' && board[7] == 'X') || (board[5] == 'O' && board[7] == 'O')) {
			board[3] = 'O';
			return -1;
		}
		if ((board[3] == 'X' && board[7] == 'X') || (board[3] == 'O' && board[7] == 'O')) {
			board[5] = 'O';
			return -1;
		}
	}

	void Display_Board() {
		system("cls");
		cout << "-----Game Board-----" << endl << endl;
		cout << " " << board[1] << " | " << board[2] << " | " << board[3] << endl;
		cout << "___|___|___" << endl;
		cout << " " << board[4] << " | " << board[5] << " | " << board[6] << endl;
		cout << "___|___|___" << endl;
		cout << " " << board[7] << " | " << board[8] << " | " << board[9] << endl;
		cout << "___|___|___" << endl;

	}
	void Player_Turn_TwoPlayer() {
		static int value = 0; //to understand whose turn.The turn player 1 if value % 2 = 0 .The turn player 2 if value % 2 = 1
	a:
		if (value % 2 == 0) {
			cout << "Player 1 [X] choose location which you want (Enter between 1 and 9 ):";
			turn = 'X';
			cin >> location;
		}
		if (value % 2 == 1) {
			cout << "Player 2 [O] choose location which you want:";
			turn = 'O';
			cin >> location;
		}
		try
		{
			if (location < 1 && location>9) {
				throw 101;
			}
		}
		catch (int e)
		{
			cout << "Error : " << e << " Location which you entered not between 1 and 9 ." << endl;
			goto a;
		}

		switch (location)
		{
		default:
		case 1:
			if (board[1] == '1')
			{
				board[1] = turn;
			}
			else {
				cout << "Location is full,Please enter again" << endl;
				goto a;
			}
			value++;
			break;
		case 2:
			if (board[2] == '2')
			{
				board[2] = turn;
			}
			else {
				cout << "Location is full,Please enter again" << endl;
				goto a;
			}
			value++;
			break;
		case 3:
			if (board[3] == '3')
			{
				board[3] = turn;
			}
			else {
				cout << "Location is full,Please enter again" << endl;
				goto a;
			}
			value++;
			break;
		case 4:
			if (board[4] == '4')
			{
				board[4] = turn;
			}
			else {
				cout << "Location is full,Please enter again" << endl;
				goto a;
			}
			value++;
			break;
		case 5:
			if (board[5] == '5')
			{
				board[5] = turn;
			}
			else {
				cout << "Location is full,Please enter again" << endl;
				goto a;
			}
			value++;
			break;
		case 6:
			if (board[6] == '6')
			{
				board[6] = turn;
			}
			else {
				cout << "Location is full,Please enter again" << endl;
				goto a;
			}
			value++;
			break;
		case 7:
			if (board[7] == '7')
			{
				board[7] = turn;
			}
			else {
				cout << "Location is full,Please enter again" << endl;
				goto a;
			}
			value++;
			break;
		case 8:

			if (board[8] == '8')
			{
				board[8] = turn;
			}
			else {
				cout << "Location is full,Please enter again" << endl;
				goto a;
			}
			value++;
			break;
		case 9:

			if (board[9] == '9')
			{
				board[9] = turn;
			}
			else {
				cout << "Location is full,Please enter again" << endl;
				goto a;
			}
			value++;
			break;
		}
	}
	int gameover() {

		if ((board[1] == 'X' && board[2] == 'X' && board[3] == 'X') ||
			(board[4] == 'X' && board[5] == 'X' && board[6] == 'X') ||
			(board[7] == 'X' && board[8] == 'X' && board[9] == 'X') ||
			(board[1] == 'X' && board[4] == 'X' && board[7] == 'X') ||
			(board[2] == 'X' && board[5] == 'X' && board[8] == 'X') ||
			(board[3] == 'X' && board[6] == 'X' && board[9] == 'X') ||
			(board[1] == 'X' && board[5] == 'X' && board[9] == 'X') ||
			(board[3] == 'X' && board[5] == 'X' && board[7] == 'X')) {
			cout << "-----Player 1 Win-----";
			return -1;
		}
		if ((board[1] == 'O' && board[2] == 'O' && board[3] == 'O') ||
			(board[4] == 'O' && board[5] == 'O' && board[6] == 'O') ||
			(board[7] == 'O' && board[8] == 'O' && board[9] == 'O') ||
			(board[1] == 'O' && board[4] == 'O' && board[7] == 'O') ||
			(board[2] == 'O' && board[5] == 'O' && board[8] == 'O') ||
			(board[3] == 'O' && board[6] == 'O' && board[9] == 'O') ||
			(board[1] == 'O' && board[5] == 'O' && board[9] == 'O') ||
			(board[3] == 'O' && board[5] == 'O' && board[7] == 'O')) {
			cout << "-----Player 2 Win-----";
			return -1;
		}
		else {
			int number = 0;
			for (int i = 1; i <= 9; i++) {
				if (board[i] == 'X' || board[i] == 'O') {
					number++;
				}
			}
			if (number == 9) {
				cout << "-------Draw-------" << endl;
				return -1;
			}
		}
	}

void AI_level1() {

	static int value = 0; //to understand whose turn.The turn player 1 if value % 2 = 0 .The turn player AI if value % 2 = 1
	if (value % 2 == 0) {
		k:
		cout << "Player 1 [X] choose location which you want (Enter between 1 and 9 ):";
		cin >> location;
		if (board[location] != 'X' && board[location] != 'O') {
         board[location] = 'X';
		}
		else {
			cout << "Location is full, Please enter again" << endl;
			goto k;
		}

		value++;
	}
	if (value % 2 == 1) {
	c:
		int num = randomnumber();
		if (locationcontrol(num))
		{
			board[num] = 'O';
		}
		else {
			goto c;
		}
		value++;
	}
}

int AI_level2() {
	static int value = 0; //to understand whose turn.The turn player 1 if value % 2 = 0 .The turn player AI if value % 2 = 1	
	if (value % 2 == 0) {
	k:
		cout << "Player 1 [X] choose location which you want (Enter between 1 and 9 ):";
		cin >> location;
		if (board[location] != 'X' && board[location] != 'O') {
			board[location] = 'X';
           value++;
		return -1;
		}
		else {
			cout << "Location is full, Please enter again" << endl;
			goto k;
		}
	}
	if (value % 2 == 1) {
		if (secondrowcontrol()==-1)
		{
			value++;
			return -1;
		}
		else if (firsrowcontrol()==-1)
		{
			value++;
			return -1;
		}
		else if (thirdrowcontrol()==-1)
		{
			value++;
			return -1;
		}
		else if (firstcolumncontrol() == -1)
		{
			value++;
			return -1;
		}
		else if (secondcolumncontrol() == -1)
		{
			value++;
			return -1;
		}
		else if (thirdcolumncontrol() == -1)
		{
			value++;
			return -1;
		}
		else if (crosscontrol1()==-1)
		{
			value++;
			return -1;
		}
		else if (crosscontrol2()==-1)
		{
			value++;
			return -1;
		}        
	d:
		int num = randomnumber();
		if (locationcontrol(num))
		{
			board[num] = 'O';
            value++;
			return -1;
		}
		else {
			goto d;
		}
	}
}

