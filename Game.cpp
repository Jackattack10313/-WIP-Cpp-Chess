#include "Game.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using std::string;
using std::cout, std::endl;
using std::ifstream, std::istringstream;
using std::vector;

Game::Game(string filename) : gameboard(new Tile**[8]) {
	ifstream input(filename);
	if (!input.is_open()) {
		throw std::runtime_error("Could not open file");
	}
	unsigned int row = 0;
	while (!input.eof()) {
		gameboard[row] = new Tile*[8];
		
		string line;
		getline(input, line);
		istringstream temp(line);
		
		string tile;
		unsigned int col = 0;
		while (temp >> tile) {
			if (tile == "empty") {
				gameboard[row][col] = new Empty(row, col);
			}
			else {
				bool color = false;
				if (tile.at(0) == 'w') {
					color = true;
				}
				
				if (tile.substr(1) == "pawn") {
					gameboard[row][col] = new Pawn(row, col, color);
				}					
				else if (tile.substr(1) == "knight") {
					gameboard[row][col] = new Knight(row, col, color);
				}
				else if (tile.substr(1) == "rook") {
					gameboard[row][col] = new Rook(row, col, color);
				}
				else if (tile.substr(1) == "bishop") {
					gameboard[row][col] = new Bishop(row, col, color);
				}
				else if (tile.substr(1) == "king") {
					gameboard[row][col] = new Empty(row, col);
				}
				else {
					gameboard[row][col] = new Empty(row, col);
				}	
			}
			col++;
		}
		row++;
	}
}

Game::Game(const Game& game) : gameboard(new Tile**[8]) {
	for (unsigned int row = 0; row < 8; row++) {
		gameboard[row] = new Tile*[8];
		for (unsigned int col = 0; col < 8; col++) {
			if (game.gameboard[row][col]->getType() == "empty") {
				gameboard[row][col] = new Empty(row, col);
			}
			else if (game.gameboard[row][col]->getType() == "pawn") {
				gameboard[row][col] = new Pawn(row, col, (dynamic_cast<Piece*>(game.gameboard[row][col]))->getIsWhite());
			}
			else if (game.gameboard[row][col]->getType() == "knight") {
				gameboard[row][col] = new Knight(row, col, (dynamic_cast<Piece*>(game.gameboard[row][col]))->getIsWhite());
			}
			else if (game.gameboard[row][col]->getType() == "rook") {
				gameboard[row][col] = new Rook(row, col, (dynamic_cast<Piece*>(game.gameboard[row][col]))->getIsWhite());
			}
			else if (game.gameboard[row][col]->getType() == "bishop") {
				gameboard[row][col] = new Bishop(row, col, (dynamic_cast<Piece*>(game.gameboard[row][col]))->getIsWhite());
			}
			else {
				gameboard[row][col] = new Empty(row, col);
			}
		}			
	}
}

Game& Game::operator=(const Game& game) {
	if (this != &game) {
		for (unsigned int row = 0; row < 8; row++) {
			for (unsigned int col = 0; col < 8; col++) {
				delete gameboard[row][col];
			}
			delete[] gameboard[row];
		}
		delete[] gameboard;
	
		gameboard = new Tile**[8];
		for (unsigned int row = 0; row < 8; row++) {
			gameboard[row] = new Tile*[8];
			for (unsigned int col = 0; col < 8; col++) {
				if (game.gameboard[row][col]->getType() == "empty") {
					gameboard[row][col] = new Empty(row, col);
				}
				else if (game.gameboard[row][col]->getType() == "pawn") {
					gameboard[row][col] = new Pawn(row, col, (dynamic_cast<Piece*>(game.gameboard[row][col]))->getIsWhite());
				}
				else if (game.gameboard[row][col]->getType() == "knight") {
					gameboard[row][col] = new Knight(row, col, (dynamic_cast<Piece*>(game.gameboard[row][col]))->getIsWhite());
				}
				else if (game.gameboard[row][col]->getType() == "rook") {
					gameboard[row][col] = new Rook(row, col, (dynamic_cast<Piece*>(game.gameboard[row][col]))->getIsWhite());
				}
				else if (game.gameboard[row][col]->getType() == "bishop") {
					gameboard[row][col] = new Bishop(row, col, (dynamic_cast<Piece*>(game.gameboard[row][col]))->getIsWhite());
				}
				else {
					gameboard[row][col] = new Empty(row, col);
				}
			}			
		}
	}
	return *this;
}

Game::~Game() {
	for (unsigned int row = 0; row < 8; row++) {
		for (unsigned int col = 0; col < 8; col++) {
			delete gameboard[row][col];
		}
		delete[] gameboard[row];
	}
	delete[] gameboard;
}

bool Game::getPieceColor(int row, int col) {
	if (gameboard[row][col]->getType() != "empty") {
		return (dynamic_cast<Piece*>(gameboard[row][col])->getIsWhite());
	}
	throw std::runtime_error("Attempted to get the color of an empty tile");
}

bool Game::move(int startRow, int startCol, int endRow, int endCol) {
	if (startRow > -1 && startRow < 8 && startCol > -1 && startCol < 8 && gameboard[startRow][startCol]->getType() != "empty") {
		Piece* piece = dynamic_cast<Piece*>(gameboard[startRow][startCol]);
		if (piece->attemptMove(Coordinate(endRow, endCol))) {
			//delete gameboard[startRow][startCol];
			gameboard[startRow][startCol] = new Empty(startRow, startCol);
			delete gameboard[endRow][endCol];
			gameboard[endRow][endCol] = piece;
			piece->setCoord(Coordinate(endRow, endCol));
			return true;
		}
	}
	return false;
}

void Game::print() {
	for (unsigned int row = 0; row < 8; row++) {
		for (unsigned int col = 0; col < 8; col++) {
			cout << gameboard[row][col]->getType() << " ";
		}
		cout << endl;
	}
}