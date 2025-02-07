#ifndef VERTEX_H_
#define VERTEX_H_

#include <vector>
#include <string>
#include "Edge.h"
#include "../Utils/Position.h"
#include "../Utils/MutablePriorityQueue.h"
#include "../Utils/MapDrawer.h"
#include "../Utils/MapTag.h"

class Vertex {
private:
	int id;
	Position pos;
	std::vector<MapTag> tags;
	std::vector<Edge> adj;
	bool visited = false;

	double distance = 0; //Represents total cost in dijkstra algorithm and fScore in A*
	Vertex *path = nullptr;
	Edge pathEdge;

	//A*
	double gScore = 0;
	Vertex* Apath = nullptr;
	Edge ApathEdge;


	int queueIndex = 0;//for MutablePriorityQueue

	void addEdge(int id, Vertex * orig, Vertex * dest, double weight);

public:
	Vertex(int id, int x, int y);

	int getID() const;
	Position getPosition() const;
	std::vector<Edge> getAdj() const;
	bool getVisited() const;

	void addTag(MapTag tag);
	std::vector<MapTag> getTags() const;
	double getDistance();
	bool operator<(Vertex & vertex) const;

	friend class Graph;
	friend class MutablePriorityQueue<Vertex>;
};

struct VertexHash {
	bool operator()(const Vertex * v1, const Vertex * v2) const {
		return v1->getID() == v2->getID();
	}

	int operator()(const Vertex * v) const {
		return v->getID();
	}
};

#endif
