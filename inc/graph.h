//
// Created by Karthikeyan on 28-09-2025.
//

#ifndef GRAPH_COLOR_GRAPH_H
#define GRAPH_COLOR_GRAPH_H

#include <iostream>
#include <vector>
#define MAXV    1000 // maximum number of vertices

class node
{
public:
    int v;
    int weight;

    node(int v, int weight) {  this->v = v; this->weight = weight; };
    node() {v = 0; weight = 0;}
};

class graph
{
public:
    std::vector<node*> adjlist[MAXV+1]; // list of vertices node connecting edges
    //node *adjlist[MAXV+1];
    int degree[MAXV+1];
    int nvertices;                      // number of vertices
    int nedges;                         // number of edges
    bool directed;

    void initialize_graph(bool directed);
    void read_graph(FILE*, bool);
    void insert_edge(int, int, bool);
    void print_graph() const;
};

#endif //GRAPH_COLOR_GRAPH_H