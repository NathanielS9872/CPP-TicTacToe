#pragma once
#include "Game.h"
#include <string>
class TicTacToe : public Game {
private:
	std::string m_board = "123456789";
	char m_turn = 'X';
	int m_turnCount = 1;
public:
	bool IsGameOver() const;
	void TakeTurn();
	void Display() const;
	bool CheckLines(const int num1, const int num2, const int num3) const;
	void SetBoard(const std::string board) { m_board = board; }
	std::string GetBoard() const { return m_board; }
	char GetTurn() const { return m_turn; }
	void SetTurn(const char turn) { m_turn = turn; }
	int GetCount() const { return m_turnCount; }
	void SetCount(const int count) { m_turnCount = count; }
};
