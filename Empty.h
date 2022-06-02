#ifndef EMPTY_H
#define EMPTY_H
#include "Tile.h"
#include <iostream>

class Empty : public Tile {
	public:
		Empty(unsigned int row, unsigned int col) : Tile(Coordinate(row, col), "empty") {}
};

#endif