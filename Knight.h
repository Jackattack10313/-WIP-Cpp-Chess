#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
#include "Game.h"
#include <vector>

class Knight : public Piece {
	public:
		Knight(unsigned int row, unsigned int col, bool color) : Piece(Coordinate(row, col), "knight", color) {}; 
		bool attemptMove(Coordinate coord);
		std::vector<Coordinate> pressuredPositions();
};

#endif