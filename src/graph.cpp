//
// Created by Karthikeyan on 28-09-2025.
//

#include "../inc/graph.h"

void graph::initialize_graph(bool directed) {

    nvertices = 0;
    nedges = 0;
    this->directed = directed;

    for (int i = 0; i <= MAXV; i++) {
        degree[i] = 0;
        adjlist[i].clear();
    }

    std::cout << "graph initialized" << std::endl;

}

void graph::read_graph(FILE* fp, bool directed) {

    int i;
    int m;
    int x, y;

    initialize_graph(directed);

    fscanf(fp,"%d %d", &nvertices, &m);

    for (i = 0; i < m; i++) {
        fscanf(fp, "%d %d", &x, &y);
        insert_edge(x,y,directed);
    }

}

// insert edge. x is source vertex, y is destination vertex
void graph::insert_edge(const int u, const int v, bool directed) {

    adjlist[u].push_back(new node(v, 0));
    degree[u]++;

    if (directed) {
        insert_edge(v, u, directed);
    }
    else {
        nedges++;
    }
}

void graph::print_graph() const {
    std::vector<node*>::const_iterator it;

    for (int i = 0; i < nvertices; i++) {
        std::cout << "vertex: " << i << ", edges: ";

        for (it = adjlist[i].begin(); it != adjlist[i].end(); ++it) {
            std::cout << (*it)->v << " ";
        }
        std::cout << std::endl;
    }
    /*
    node* p;
    for (int i = 0; i < nvertices; i++) {
        std::cout << "vertex: " << i << ", edges: ";
        p = adjlist[i];
        while (p != nullptr) {
            std::cout << p->v << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }*/
}
