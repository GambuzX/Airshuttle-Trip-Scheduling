#ifndef VERTEX_H_
#define VERTEX_H_

#include <vector>
#include <string>
#include "Edge.h"
#include "../Utils/Position.h"

class Edge;

class Vertex {
private:
	int id;
	Position pos;
	std::vector<std::string> tags;
	std::vector<Edge> adj;
	bool visited = false;
	double distance = 0; //auxiliary

	void addEdge(int id, Vertex * dest, double weight);

public:
	Vertex(int id, int x, int y);

	int getID() const;
	Position getPosition() const;
	std::vector<Edge> getAdj() const;

	void addTag(std::string tag);
	std::vector<std::string> getTags() const;

	friend class Graph;
};

#endif