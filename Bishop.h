#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
#include "Game.h"
#include <vector>

class Bishop : public Piece {
	public:
		Bishop(unsigned int row, unsigned int col, bool color) : Piece(Coordinate(row, col), "bishop", color) {};
		bool attemptMove(Coordinate coord);
		std::vector<Coordinate> pressuredPositions();
};
#endif