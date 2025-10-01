//
// DFS problem list:
// 1. Course schedule - https://leetcode.com/problems/course-schedule/description/
//
#include "../inc/dfs.h"
void dfs::initialize(const graph *G) {

    // initialize processed, discovered and parent array
    for (int i = 1; i <= G->nvertices; i++) {
        done[i] = visited[i] = false;
        parent[i] = -1;
    }

    finished = false;
}

void dfs::process_edge(int u, int v) {

    if (parent[v] != u) {
        std::cout << "found cycle!!!" << std::endl;
        finished = true;
    }
}

void dfs::dodfs(graph *G, int u) {

    int v;

    if (finished)
        return;

    visited[u] = true;
    time++;
    entry_time[u] = time;

    // process_vertex_early();

    // traverse adjacent nodes of node 'u'
    for (int i = 0; i < G->adjlist[u].size(); i++) {

        v = G->adjlist[u][i]->v;

        // first time this edge is processed (tree edge)
        if (visited[v] == false) {
            parent[v] = u;
            process_edge(u, v);
            std::cout << "Edge: " << u << "->" << v << std::endl;
            dodfs(G, v);
        }
        // not done for node 'v' means it is still in the stack
        else if ((done[v] == false) || G->directed) {
            // process_edge(u, v);
            process_edge(u, v);
        }

        if (finished)
            return;
    }

    // process_vertex_late()
    time++;
    exit_time[u] = time;

    // done means out of stack
    done[u] = true;
}
