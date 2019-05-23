#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <algorithm>
#include <unordered_map>

#include "Vertex.h"
#include "../Utils/MutablePriorityQueue.h"

#define INF std::numeric_limits<double>::max()

class Graph {
private:
	std::unordered_map<int, Vertex *> vertexHashMap;
	std::vector<Vertex *> vertexSet;

	void DFSVisit(Vertex * v);
public:
	Vertex *findVertex(const int &id) const;
	bool addVertex(const int &id, int x, int y);
	bool addEdge(int id, int v_id1, int v_id2);
	int getNumVertex() const;

	std::vector<Vertex *> getVertexSet() const;

	//single source algorithms
	Vertex * initSingleSource(const int &origin);
	bool relax(Vertex *v, Edge edge); //Vertex *w, double weight);
	void dijkstraShortestPath(const int &source);
	std::vector<int> getPathVertices(const int source, const int dest);
	std::vector<Edge> getPathEdges(const int source, const int dest);


	void reset();
	~Graph();

	void DFSConnectivity(Vertex * start);
	void removeUnvisitedVertices();
};

#endif
