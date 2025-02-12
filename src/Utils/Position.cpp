#include <cmath>

#include "Position.h"

Position::Position(double x, double y) {
	this->x = x;
	this->y = y;
}

Position::Position(const Position & pos) {
	this->x = pos.x;
	this->y = pos.y;
}

double Position::getX() const {
	return x;
}

double Position::getY() const {
	return y;
}

double Position::euclidianDistance(const Position &p2) {
	return sqrt(pow(p2.x - x, 2) + pow(p2.y - y, 2));
}
