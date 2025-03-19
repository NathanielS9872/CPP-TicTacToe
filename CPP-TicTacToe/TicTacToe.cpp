#include "TicTacToe.h"
#include <iostream>
bool TicTacToe::IsGameOver() const{
	if (CheckLines(0, 1, 2) || CheckLines(3, 4, 5) || CheckLines(6, 7, 8) || CheckLines(0, 3, 6) || CheckLines(1, 4, 7) || CheckLines(2, 5, 8) || CheckLines(0, 4, 8) || CheckLines(2, 4, 6)) {
		return true;
	}
	else {
		if (GetCount() > 9) { return true; }
		return false;
	}
}
void TicTacToe::TakeTurn() {
	std::string input;
	bool loop = true;
	std::string board = GetBoard();
	std::cout << "Where would you like to go? (1-9): ";
	while (loop) {
		std::cin >> input;
		if (std::stoi(input) > 0 && std::stoi(input) < 10) {
			if (board[stoi(input) - 1] != 'X'&&board[stoi(input)-1] != 'Y') {
				board[stoi(input) - 1] = GetTurn();
				loop = false;
			}
			else {
				Display();
				std::cout << "Spot already taken.\nWhere would you like to go? (1-9): ";
			}
		}
		else {
			Display();
			std::cout << "Invalid number.\nWhere would you like to go ? (1-9) : ";
		}
	}
	SetBoard(board);
	GetTurn() == 'X' ? SetTurn('Y') : SetTurn('X');
	SetCount(GetCount() + 1);
}
//1,2,3  (0,1,2
//4,5,6   3,4,5
//7,8,9   6,7,8)
void TicTacToe::Display() const{
	system("cls");
	std::string board = GetBoard();
	if (CheckLines(0, 1, 2) || CheckLines(3, 4, 5) || CheckLines(6, 7, 8) || CheckLines(0, 3, 6) || CheckLines(1, 4, 7) || CheckLines(2, 5, 8) || CheckLines(0, 4, 8) || CheckLines(2, 4, 6)) {
		char winner = GetTurn() == 'X' ? 'Y':'X';
		std::cout<<"\n\n" << board[0] << "|" << board[1] << "|" << board[2] << "\n------\n" << board[3] << "|" << board[4] << "|" << board[5] << "\n------\n" << board[6] << "|" << board[7] << "|" << board[8] << "\n\n" << winner << " has won the game!\n";
	}
	else if(GetCount() > 9){
		std::cout <<"\n\n" << board[0] << "|" << board[1] << "|" << board[2] << "\n------\n" << board[3] << "|" << board[4] << "|" << board[5] << "\n------\n" << board[6] << "|" << board[7] << "|" << board[8] << "\n\nThe game has ended in a Draw!\n";
	}
	else {
		std::cout << "Turn " << GetCount() << " (" << GetTurn() << "'s turn):\n\n" << board[0] << "|" << board[1] << "|" << board[2] << "\n------\n" << board[3] << "|" << board[4] << "|" << board[5] << "\n------\n" << board[6] << "|" << board[7] << "|" << board[8] << "\n\n";
	}
}
bool TicTacToe::CheckLines(const int num1,const int num2, const int num3) const{
	std::string board = GetBoard();
	if (board[num1] == board[num2] && board[num2] == board[num3] && (board[num1] == 'X'||board[num1] == 'Y')) { return true; }
	return false;
}
