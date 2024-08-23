//Tic-Tac-Toe Board
#include <iostream>
#include <string>

class TicTacToe {
private:
	char square[9];
	std::string player1, player2;

public:
	TicTacToe() {
		refreshBoard();
	}

	void refreshBoard() {
		system("cls");
		for (int i = 0; i < 9; i++)
			square[i] = '0' + i;
	}

	void display() {
		system("cls");
		for (int i = 0; i < 9; i++) {
			std::cout << square[i] << "\t";
			if (i == 2 || i == 5 || i == 8)
				std::cout << "\n";
		}
	}

	bool mark(int player, int box) {
		if (box>8 || box < 0)
			return false;
		else
		{
			if (square[box] != 'X' && square[box] != 'Y') {
				square[box] = (player == 1) ? 'X' : 'Y';
				return true;
			}
		}
		return false;
	}

	int checkWin() {
		const int winningCombinations[8][3] = {
			{ 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 }, // Rows
			{ 0, 3, 6 }, { 1, 4, 7 }, { 2, 5, 8 }, // Columns
			{ 0, 4, 8 }, { 2, 4, 6 }             // Diagonals
		};

		for (const auto& combo : winningCombinations) {
			if (square[combo[0]] == square[combo[1]] && square[combo[1]] == square[combo[2]]) {
				if (square[combo[0]] == 'X') return 1;
				if (square[combo[0]] == 'Y') return 2;
			}
		}
		return 0; // No winner
	}

	bool checkDraw() {
		for (char c : square) {
			if (c != 'X' && c != 'Y') return false;
		}
		return true;
	}

	void setPlayerNames() {
		std::cout << "Enter Player 1 name: ";
		std::cin >> player1;
		std::cout << "Enter Player 2 name: ";
		std::cin >> player2;
		system("cls");
	}

	void playGame() {
		int box, result;
		bool exit = false;

		while (!exit) {
			refreshBoard();
			display();

			for (int turn = 0; turn < 9; turn++) {
				int currentPlayer = (turn % 2) + 1; // Player 1 or 2
				std::string currentPlayerName = (currentPlayer == 1) ? player1 : player2;

				do {
					std::cout << "\n" << currentPlayerName << ", enter the box (0-8): ";
					std::cin >> box;
				} while (!mark(currentPlayer, box));

				display();
				result = checkWin();
				if (result != 0) {
					std::cout << "\nCongratulations! " << ((result == 1) ? player1 : player2) << " has won!\n";
					exit = true;
					break;
				}

				if (checkDraw()) {
					std::cout << "\nThe game is a draw!\n";
					exit = true;
					break;
				}
			}

			if (!exit) {
				std::cout << "\nThe game is a draw!\n";
			}

			std::cout << "\nExit(1) / Start a new game(0)? ";
			std::cin >> exit;
		}
	}
};

int main() {
	TicTacToe game;
	game.setPlayerNames();
	game.playGame();
	return 0;
}
