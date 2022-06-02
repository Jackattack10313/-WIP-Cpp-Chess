#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"
#include "Game.h"
#include <vector>

class Rook : public Piece {
	public:
		Rook(unsigned int row, unsigned int col, bool color) : Piece(Coordinate(row, col), "rook", color) {}; 
		bool attemptMove(Coordinate coord);
		std::vector<Coordinate> pressuredPositions();
};

#endif