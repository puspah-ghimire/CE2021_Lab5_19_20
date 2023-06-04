#include "Graph.hpp"
#include <iostream>
using namespace std;

Graph::Graph(bool isDirected) : numV(0), numE(0), directed(isDirected), adjacencyMatrix(nullptr) {}

Graph::~Graph() {
    if (adjacencyMatrix) {
        for (int i = 0; i < numV; i++) {
            delete[] adjacencyMatrix[i];
        }
        delete[] adjacencyMatrix;
    }
}

bool Graph::isEmpty()
{
    return (numV == 0);
}

bool Graph::isDirected()
{
    return directed;
}




