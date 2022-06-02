#include "Pawn.h"
#include <vector>

using std::vector;

// Add functionality for en passant (must know previous move)
// Add functionality for promotion!
bool Pawn::attemptMove(Coordinate coord) {
	if (this->isWhite && this->pos.row == 6 && this->pos.col == coord.col && (coord.row == 5 || coord.row == 4)) {
		return true;
	}
	else if (!this->isWhite && this->pos.row == 1 && this->pos.col == coord.col && (coord.row == 2 || coord.row == 3)) {
		return true;
	}
	else if (this->isWhite && this->pos.col == coord.col && this->pos.row - 1 == coord.row) { 
		return true;
	}
	else if (!this->isWhite && this->pos.col == coord.col && this->pos.row + 1 == coord.row) {
		return true;
	}
	return false;
}

vector<Coordinate> Pawn::pressuredPositions() {
	vector<Coordinate> temp;
	if (this->isWhite) {
		addValidPosition(temp, Coordinate(this->pos.row - 1, this->pos.col - 1));
		addValidPosition(temp, Coordinate(this->pos.row - 1, this->pos.col + 1));
	}
	else {
		addValidPosition(temp, Coordinate(this->pos.row + 1, this->pos.col - 1));
		addValidPosition(temp, Coordinate(this->pos.row + 1, this->pos.col + 1));
	}
	return temp;
}