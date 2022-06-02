#include "Bishop.h"
#include <vector>

using std::vector;

bool Bishop::attemptMove(Coordinate coord) {
	if (this->pos.row - coord.row == this->pos.col - coord.col) {
		return true;
		//for (unsigned int 
	}
	return false;
}

vector<Coordinate> Bishop::pressuredPositions() {
	return vector<Coordinate>();
}