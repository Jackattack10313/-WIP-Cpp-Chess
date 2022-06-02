#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
#include "Game.h"
#include <vector>

class Pawn : public Piece {
	public:
		Pawn(unsigned int row, unsigned int col, bool color) : Piece(Coordinate(row, col), "pawn", color) {}; 
		bool attemptMove(Coordinate coord);
		std::vector<Coordinate> pressuredPositions();
};

#endif