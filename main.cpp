#include <fstream>
#include <iostream>

#include "inc/bfs.h"
#include "inc/graph.h"

int main(int argc, char *argv[]) {

    std::cout << "Graph problem" << std::endl;
    std::cout << "Argument count: " << argc << std::endl;

    // open input file
    FILE* fp = fopen("input/sample_input.txt", "r");

    if (fp == nullptr) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    for (auto i = 0; i < argc; i++) {
        std::cout << "arg " << i << ": " << argv[i] << std::endl;
    }

    auto* g = new graph();

    g->read_graph(fp, false);
    g->print_graph();

    bfs::getInstance().initialize(g);
    bfs::getInstance().dobfs(g, 1);
    bfs::getInstance().find_path(1, 4);
    bfs::getInstance().find_path(1, 3);

    bfs::getInstance().initialize(g);
    bfs::getInstance().connected_components(g);

    return 0;
}