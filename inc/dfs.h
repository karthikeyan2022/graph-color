//
// Created by Karthikeyan on 01-10-2025.
//

#ifndef GRAPH_COLOR_DFS_H
#define GRAPH_COLOR_DFS_H

#include "graph.h"

#define MAXV    1000 // maximum number of vertices

// create singleton class
class dfs {
    // used in dfs
private:
    dfs() {};
    bool done[MAXV+1];             /* which vertices have been processed */
    bool visited[MAXV+1];          /* which vertices have been found */
    int parent[MAXV+1];            /* discovery relation */

    // dfs specific ds
    bool finished;
    int time;
    int entry_time[MAXV+1];
    int exit_time[MAXV+1];
    void print_parentarray(const graph* G) const; // private function called in dodfs
    void process_edge(int, int);
public:
    static dfs& getInstance() {
        static dfs instance;
        return instance;
    }
    void initialize(const graph* G);
    void dodfs(graph* G, int u);

};
#endif //GRAPH_COLOR_DFS_H