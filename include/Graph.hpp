#ifndef GRAPH_HPP
#define GRAPH_HPP

class Graph {
private:
    bool** adjacencyMatrix;
    int numV;
    int numE;
    bool directed;

public:
    Graph(bool isDirected);
    ~Graph();
    bool isEmpty();
    bool isDirected();
    void addVertex();
    void addEdge(int vertex1, int vertex2);
    void removeVertex(int vertexToRemove);
    void removeEdge(int vertex1, int vertex2);
    int numVerticesCount();
    int numEdgesCount();
    int indegree(int vertex);
    int outdegree(int vertex);
    int degree(int vertex);
    int* neighbours(int vertex);
    bool neighbour(int vertex1, int vertex2);
};

#endif