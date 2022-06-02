#include "Knight.h"
#include <vector>

using std::vector;

bool Knight::attemptMove(Coordinate coord) {
	if ((this->pos.row == coord.row - 2 || this->pos.row == coord.row + 2 || this->pos.col == coord.col - 2 || this->pos.col == coord.col + 2) && 
	(this->pos.row == coord.row - 1 || this->pos.row == coord.row + 1 || this->pos.col == coord.col - 1 || this->pos.col == coord.col + 1)) {
		return true;
	}
	return false;
}

// Could not think of a more elegant / readable approach to getting all of the knight positions
vector<Coordinate> Knight::pressuredPositions() {
	vector<Coordinate> temp;
	addValidPosition(temp, Coordinate(this->pos.row - 2, this->pos.row - 1));
	addValidPosition(temp, Coordinate(this->pos.row - 2, this->pos.row + 1));
	addValidPosition(temp, Coordinate(this->pos.row + 2, this->pos.row - 1));
	addValidPosition(temp, Coordinate(this->pos.row + 2, this->pos.row + 1));
	addValidPosition(temp, Coordinate(this->pos.row - 1, this->pos.row - 2));
	addValidPosition(temp, Coordinate(this->pos.row - 1, this->pos.row + 2));
	addValidPosition(temp, Coordinate(this->pos.row + 1, this->pos.row - 2));
	addValidPosition(temp, Coordinate(this->pos.row + 1, this->pos.row - 2));
	return temp;
}

