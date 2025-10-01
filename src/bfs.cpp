//
// Created by Karthikeyan on 28-09-2025.
//

#include "../inc/bfs.h"

#include <algorithm>

void bfs::initialize(const graph *G) {

    // initialize processed, discovered and parent array
    for (int i = 1; i <= G->nvertices; i++) {
        done[i] = visited[i] = false;
        parent[i] = -1;
    }

    // initialize queue container
    while (bfsqueue.empty() == false) {
        bfsqueue.pop();
    }
}

void bfs::dobfs(graph *G, int start) {

    std::cout << "Starting BFS on Graph" << std::endl;
    //initialize(G);

    int u, v;
    node* p;

    bfsqueue.push(start);
    visited[start] = true;

    while (!bfsqueue.empty()) {
        u = bfsqueue.front();
        bfsqueue.pop();

        std::cout << "processed vertex: " << u << std::endl;
        done[u] = true;

        // traverse all the edges
        for (int i = 0; i < G->adjlist[u].size(); i++) {

            v = G->adjlist[u][i]->v;

            // if v is already done means, it is already visited and pushed to queue.
            // Already an edge is processed if done is set for v
            if (done[v] == false || G->directed) {
                std::cout << "Edge: " << u << "->" << v << std::endl;
            }

            if (visited[v] == false) {
                bfsqueue.push(v);
                visited[v] = true;
                parent[v] = u;
            }
        }

        /*
        while (p != nullptr) {
            v = p->v;

            if (done[v] == false || G->directed) {
                std::cout << "Edge: " << u << "->" << v << std::endl;
            }

            if (visited[v] == false) {
                bfsqueue.push(v);
                visited[v] = true;
                parent[v] = u;
            }

            p = p->next;
        } */

    }

    print_parentarray(G);


}

void bfs::print_parentarray(const graph* G) const {

    std::cout << "vertex : ";
    for (int i = 1; i <= G->nvertices; i++) {
        std:: cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "parent: ";
    for (int i = 1; i <= G->nvertices; i++) {
        std:: cout << parent[i] << " ";
    }
    std::cout << std::endl;
}

// recursive function which find and print path from start to end
// BFS should be called before calling this and fill parent array
void bfs::find_path(int start, int end, bool isStart) {

    if (start == end) {

        std::cout << "Path found: ";
        std::cout << start << " -> ";
    }
    else if (end == -1) {
        std::cout << "Path found" << std::endl;
    }
    else {
        find_path(start, parent[end], false);

        std::cout << end;
        if (isStart) {
            std::cout << std::endl;
        } else {
            std::cout << " -> ";
        }
    }
}

// Graph should be populated before calling this
void bfs::connected_components(graph *G)
{
    int c = 0;
    for (int i = 1; i<=G->nvertices; i++) {
        if (visited[i] == false) {
            c++;
            dobfs(G,i);
        }
    }
    std::cout << "connected components: " << c << std::endl;
}