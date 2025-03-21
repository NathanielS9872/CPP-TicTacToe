#pragma once
#include "Game.h"
#include <string>
class TicTacToe : public Game {
private:
	std::string m_board = "123456789";//Tracks board state. had some troubles making an array, so just made a string since that is a character array
	char m_turn = 'X';//Tracks current turn starting at X
	int m_turnCount = 1;//Tracks turn count
public:
	bool IsGameOver() const;
	void TakeTurn();
	void Display() const;
	bool CheckLines(const int num1, const int num2, const int num3) const;
	void SetBoard(const std::string board) { m_board = board; }//Start of Getters/Setters
	std::string GetBoard() const { return m_board; }
	char GetTurn() const { return m_turn; }
	void SetTurn(const char turn) { m_turn = turn; }
	int GetCount() const { return m_turnCount; }
	void SetCount(const int count) { m_turnCount = count; }
};
