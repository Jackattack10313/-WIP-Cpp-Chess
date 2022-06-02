#ifndef TILE_H
#define TILE_H
#include <iostream>
#include <string>

struct Coordinate {
	unsigned int row;
	unsigned int col;
	Coordinate() : row(0), col(0) {};
	Coordinate(unsigned int row, unsigned int col) : row(row), col(col) {};
};

class Tile {
	protected:
		// Tile coordinate on board (top left: (0, 0))
		Coordinate pos;
		// Piece type string since c++ cannot check if an object is of a certain type
		std::string type;
	public:
		Tile(Coordinate coord, std::string type = "") : pos(coord), type(type) {}
		
		std::string getType() const {return type;};
		void setType(std::string type) {this->type = type;};
		
		Coordinate getRow() {return pos;}; // coordinate getter
		
		void setCoord(Coordinate coord) {pos = coord;};
		
		virtual ~Tile() {}; // Virtual destructor
};
#endif