#include "Rook.h"
#include <vector>

using std::vector;

// TODO: Introduce Castling 
bool Rook::attemptMove(Coordinate coord) {
	if ((this->pos.row == coord.row || this->pos.col == coord.col)) {
		return true;
	}
	return false;
}

vector<Coordinate> Rook::pressuredPositions() {
	return vector<Coordinate>();
}