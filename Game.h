#ifndef GAME_H
#define GAME_H

#include "Tile.h"
#include "Piece.h"
#include "Empty.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include <string>
#include <iostream>

class Game {
	protected:
		Tile*** gameboard;
	public: 
		Game(std::string filename);
		~Game();
		Game(const Game& game); // Rule of 3 (not necessary for implementation - just for warning)
		Game& operator=(const Game& game); // Rule of 3 (not necessary for implementation - just for warning)
		std::string getPieceType(int row, int col) {return gameboard[row][col]->getType();};
		bool getPieceColor(int row, int col);
		bool move(int startRow, int startCol, int endRow, int endCol); 
		void print();
};

void addValidPosition(std::vector<Coordinate>& coords, Coordinate coordToAdd);

#endif