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
    void addVertex(int newVertex);
    void addEdge(int vertex1, int vertex2);
    void removeVertex(int vertexToRemove);
    void removeEdge(int vertex1, int vertex2);
    int numVertices();
    int numEdges();
    int indegree(int vertex);
    int outdegree(int vertex);
    int degree(int vertex);
    bool neighbour(int vertex1, int vertex2);
    void display();
};

#endif