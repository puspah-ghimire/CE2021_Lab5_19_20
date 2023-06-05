#include "Graph.hpp"
#include <iostream>

Graph::Graph(bool isDirected) : numV(0), numE(0), directed(isDirected), adjacencyMatrix(nullptr) {}

Graph::~Graph() {
    if (adjacencyMatrix) {
        for (int i = 0; i < numV; i++) {
            delete[] adjacencyMatrix[i];
        }
        delete[] adjacencyMatrix;
    }
}

bool Graph::isEmpty() {
    return (numV == 0);
}

bool Graph::isDirected() {
    return directed;
}

void Graph::addVertex(int newVertex) {
    if (newVertex <= 0) {
        std::cout << "Invalid vertex!" << std::endl;
    }
    numV++;

    bool** newMatrix = new bool*[numV];
    for (int i = 0; i < numV; i++) {
        newMatrix[i] = new bool[numV];
        for (int j = 0; j < numV; j++) {
            // Initialize with zeros
            newMatrix[i][j] = 0;   
        }
    }

    if (adjacencyMatrix) {
        for (int i = 0; i < numV - 1; i++) {
            for (int j = 0; j < numV - 1; j++) {
                newMatrix[i][j] = adjacencyMatrix[i][j];
            }
            delete[] adjacencyMatrix[i];
        }
        delete[] adjacencyMatrix;
    }

    adjacencyMatrix = newMatrix;
}

void Graph::addEdge(int vertex1, int vertex2) {
    if (isEmpty()) {
        std::cout << "The graph is empty." << std::endl;
        return;
    }
    else if (vertex1 > numV || vertex2 > numV) {
        if (vertex1 > numV) {
            std::cout << "Vertex " << vertex1 << " doesn't exist in the graph." << std::endl;
        }
        if (vertex2 > numV) {
            std::cout << "Vertex " << vertex2 << " doesn't exist in the graph." << std::endl;
        }
        return;
    }
    else {
        adjacencyMatrix[vertex1 - 1][vertex2 - 1] = 1;
        if (!directed) {
            adjacencyMatrix[vertex2 - 1][vertex1 - 1] = 1;
        }
    }
    numE++;
}

int Graph::numVertices() {
    return numV;
}

int Graph::numEdges() {
    return numE;
}

int Graph::indegree(int vertex) {
    if (isEmpty()) {
        std::cout << "The graph is empty." << std::endl;
        return 0;
    }

    if (vertex > numV) {
        std::cout << "Invalid vertex!" << std::endl;
        return -1;
    }

    int count = 0;
    for (int i = 0; i < numV; i++) {
        if (adjacencyMatrix[i][vertex - 1]) {
            count++;
        }
    }

    return count;
}

int Graph::outdegree(int vertex) {
    if (isEmpty()) {
        std::cout << "The graph is empty." << std::endl;
        return 0;
    }

    if (vertex > numV) {
        std::cout << "Invalid vertex!" << std::endl;
        return -1;
    }

    int count = 0;
    for (int j = 0; j < numV; j++) {
        if (adjacencyMatrix[vertex - 1][j]) {
            count++;
        }
    }

    return count;
}

int Graph::degree(int vertex) {
    if (isEmpty()) {
        std::cout << "The graph is empty." << std::endl;
        return 0;
    }

    if (vertex > numV) {
        std::cout << "Invalid vertex!" << std::endl;
        return -1;
    }

    return indegree(vertex) + outdegree(vertex);
}

bool Graph::neighbour(int vertex1, int vertex2) {
    if (isEmpty()) {
        std::cout << "The graph is empty." << std::endl;
        return false;
    }

    if (vertex1 > numV || vertex2 > numV) {
        std::cout << "Invalid vertices!" << std::endl;
        return false;
    }

    return adjacencyMatrix[vertex1 - 1][vertex2 - 1] || adjacencyMatrix[vertex2 - 1][vertex1 - 1];
}

void Graph::display() {
    for (int i = 0; i < numV; i++) {
        for (int j = 0; j < numV; j++) {
            std::cout << adjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
