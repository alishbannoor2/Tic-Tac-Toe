#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <string>

class TicTacToe {
private:
	char square[9];
	std::string player1, player2;

public:
	TicTacToe();
	void refreshBoard();
	void display();
	bool mark(int player, int box);
	int checkWin();
	bool checkDraw();
	void setPlayerNames();
	void playGame();
};

#endif 
