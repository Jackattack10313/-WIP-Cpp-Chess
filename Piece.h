#ifndef PIECE_H
#define PIECE_H
#include "Tile.h"
#include <string>
#include <iostream>
#include <vector>

// Parent class of all the chess pieces
class Piece : public Tile {
	protected:
		// A binary choice between white & black
		bool isWhite;
	public:
		// Constructor so children can instantiate parent members in member initialization list
		Piece(Coordinate coord, std::string type, bool color) : Tile(coord, type), isWhite(color) {}
		
		bool getIsWhite() {return isWhite;}; // Color getter
		void setIsWhite(bool color) {isWhite = color;}; // Color setter
				
		virtual bool attemptMove(Coordinate coord) = 0; // Attempting to make a move
		virtual std::vector<Coordinate> pressuredPositions() = 0; // 
};

#endif