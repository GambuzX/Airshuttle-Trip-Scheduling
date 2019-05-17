#include "Graph.h"

using namespace std;

Vertex* Graph::findVertex(const int &id) const {
	for (Vertex * v : vertexSet)
		if(v->id == id)
			return v;
	return nullptr;
}

bool Graph::addVertex(const int &id, int x, int y) {
	if (findVertex(id) != nullptr) return false;
	vertexSet.push_back(new Vertex(id, x, y));
	return true;
}

bool Graph::addEdge(int id, int v_id1, int v_id2) {
	Vertex * v1 = findVertex(v_id1);
	Vertex * v2 = findVertex(v_id2);
	if(v1 == nullptr || v2 == nullptr) return false;
	double dist = v1->pos.euclidianDistance(v2->pos);
	v1->addEdge(id, v2, dist);
	v2->addEdge(id+1, v1, dist);
	return true;
}

int Graph::getNumVertex() const {
	return vertexSet.size();
}

vector<Vertex*> Graph::getVertexSet() const {
	return vertexSet;
}

void Graph::reset() {
	for (size_t i = 0; i < vertexSet.size(); i++)
			delete vertexSet[i];
	vertexSet.clear();
}

Graph::~Graph() {
	for (size_t i = 0; i < vertexSet.size(); i++)
		delete vertexSet[i];
}
