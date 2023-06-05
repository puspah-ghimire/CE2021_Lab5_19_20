#include "Graph.hpp"
#include <iostream>

int main() {
    // Create a directed graph
    Graph graph(true);

    // Add vertices
    for (int i = 1; i <= 5; i++) {
        graph.addVertex(i);
    }

    // Add edges
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);

    // Display the graph
    std::cout << "Graph adjacency matrix:" << std::endl;
    graph.display();

    // Test graph operations
    std::cout << "Number of vertices: " << graph.numVertices() << std::endl;
    std::cout << "Number of edges: " << graph.numEdges() << std::endl;
    std::cout << "Indegree of vertex 4: " << graph.indegree(4) << std::endl;
    std::cout << "Outdegree of vertex 2: " << graph.outdegree(2) << std::endl;
    std::cout << "Degree of vertex 3: " << graph.degree(3) << std::endl;

    std::cout << "Neighbours of vertex 2: ";
    std::vector<int> neighbors = graph.neighbours(2);
    for (int neighbor : neighbors) {
        std::cout << neighbor << " ";
    }
    std::cout << std::endl;

    std::cout << "Is vertex 3 a neighbor of vertex 4? ";
    std::cout << (graph.neighbour(3, 4) ? "Yes" : "No") << std::endl;

    // Remove a vertex and an edge
    graph.removeVertex(3);
    std::cout<<"Removed vertex 3"<<std::endl;
    graph.removeEdge(2, 4);
    std::cout<<"Removed Edge (2, 4)"<<std::endl;

    // Display the updated graph
    std::cout << "Updated graph adjacency matrix:" << std::endl;
    graph.display();

    return 0;
}