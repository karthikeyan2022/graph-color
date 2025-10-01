//
// Created by Karthikeyan on 28-09-2025.
//
#ifndef GRAPH_COLOR_BFS_H
#define GRAPH_COLOR_BFS_H

#include <queue>
#include "graph.h"

#define MAXV    1000 // maximum number of vertices

// create singleton class
class bfs {
    // used in bfs
private:
    bfs() {};
    bool done[MAXV+1];             /* which vertices have been processed */
    bool visited[MAXV+1];            /* which vertices have been found */
    int parent[MAXV+1];                 /* discovery relation */
    std::queue<int> bfsqueue;           // queue of vertex int



public:
    static bfs& getInstance() {
        static bfs instance;
        return instance;
    }
    void initialize(const graph* G);
    void dobfs(graph* G, int start);
    void print_parentarray(const graph* G) const;
    void find_path(int start, int end, bool isStart = true);
    void connected_components(graph *G);

};

#endif //GRAPH_COLOR_BFS_H