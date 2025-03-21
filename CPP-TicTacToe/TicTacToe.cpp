#include "TicTacToe.h"
#include <iostream>
bool TicTacToe::IsGameOver() const{
	if (CheckLines(0, 1, 2) || CheckLines(3, 4, 5) || CheckLines(6, 7, 8) || CheckLines(0, 3, 6) || CheckLines(1, 4, 7) || CheckLines(2, 5, 8) || CheckLines(0, 4, 8) || CheckLines(2, 4, 6)) {
		return true;
	}//Uses CheckLines() to determine if there is 3 in a row vertically, horizontally, or diagonally anywhere, indicating a completed game
	else {
		if (GetCount() > 9) { return true; }//Returns true if the turn count is 9, indicating a filled board and completed game
		return false;//Returns false if it does not return true
	}
}
void TicTacToe::TakeTurn() {
	std::string input;
	bool loop = true;
	std::string board = GetBoard();
	std::cout << "Where would you like to go? (1-9): ";
	while (loop) {//loops until the input is 1-9, and in a spot not marked by X or O (defaults to the position number)
		std::cin >> input;
		if (std::stoi(input) > 0 && std::stoi(input) < 10) {
			if (board[stoi(input) - 1] != 'X'&&board[stoi(input)-1] != 'O') {
				board[stoi(input) - 1] = GetTurn();//Ends loop and changes appropriate index to X or O depending on the current turn
				loop = false;
			}
			else {
				Display();
				std::cout << "Spot already taken.\nWhere would you like to go? (1-9): ";//Redisplays board and error message if spot is taken
			}
		}
		else {
			Display();
			std::cout << "Invalid number.\nWhere would you like to go ? (1-9) : ";//Redisplays board and error message if the number is not 1-9
		}
	}
	SetBoard(board);//Updates m_board
	GetTurn() == 'X' ? SetTurn('O') : SetTurn('X');//Changes turn
	SetCount(GetCount() + 1);//Increases turn count by 1
}
//1,2,3  (0,1,2
//4,5,6   3,4,5
//7,8,9   6,7,8)
void TicTacToe::Display() const{
	system("cls");
	std::string board = GetBoard();
	if (CheckLines(0, 1, 2) || CheckLines(3, 4, 5) || CheckLines(6, 7, 8) || CheckLines(0, 3, 6) || CheckLines(1, 4, 7) || CheckLines(2, 5, 8) || CheckLines(0, 4, 8) || CheckLines(2, 4, 6)) {
		std::cout<<"\n\n " << board[0] << "|" << board[1] << "|" << board[2] << "\n ------\n " << board[3] << "|" << board[4] << "|" << board[5] << "\n ------\n " << board[6] << "|" << board[7] << "|" << board[8] << "\n\n" << (GetTurn() == 'X' ? 'O':'X') << " has won the game!\n";
	}//Displays board state and the winner if CheckLines returns true with any line combination
	else if(GetCount() > 9){
		std::cout <<"\n\n " << board[0] << "|" << board[1] << "|" << board[2] << "\n ------\n " << board[3] << "|" << board[4] << "|" << board[5] << "\n ------\n " << board[6] << "|" << board[7] << "|" << board[8] << "\n\nThe game has ended in a Draw!\n";
	}//Displays board state and declares the match a draw if board is filled (done after checking for winners)
	else {
		std::cout << "Turn " << GetCount() << " (" << GetTurn() << "'s turn):\n\n " << board[0] << "|" << board[1] << "|" << board[2] << "\n ------\n " << board[3] << "|" << board[4] << "|" << board[5] << "\n ------\n " << board[6] << "|" << board[7] << "|" << board[8] << "\n\n";
	}//Displays board state in preperation for TakeTurn()
}
bool TicTacToe::CheckLines(const int num1,const int num2, const int num3) const{
	std::string board = GetBoard();
	if (board[num1] == board[num2] && board[num2] == board[num3]) { return true; }
	return false;//returns true if 3 designated locations in the board are the same
}