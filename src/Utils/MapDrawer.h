#ifndef MAP_DRAWER_H_
#define MAP_DRAWER_H_

#include "../GraphViewer/cpp/graphviewer.h"
#include "MapTag.h"

class Graph;
class ServicesPlanner;

class MapDrawer {
private:
	int width, height;
	GraphViewer * graphViewer;

	bool buildVerticesFromFile(std::string location);
	bool buildEdgesFromFile(std::string location);
	void resetGraphViewer();

public:
	MapDrawer(int width, int height);
	~MapDrawer();

	GraphViewer * getViewer();

	bool drawMapFromFile(std::string location);
	bool drawMapFromGraph(Graph * graph);
	bool drawMapFromPlannerSingleVan(ServicesPlanner * planner);

	static MapTag getStringTag(std::string tag);
	static std::string getTagColor(MapTag);
};

#endif
