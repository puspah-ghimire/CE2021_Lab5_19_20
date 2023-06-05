#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include "Graph.hpp"

// Function to generate a random graph using Erdős-Rényi model
Graph generateRandomGraph(int numVertices, double edgeProbability)
{
    Graph graph(false); // Undirected graph

    // Add vertices to the graph
    for (int i = 1; i <= numVertices; i++)
    {
        graph.addVertex(i);
    }

    // Generate random edges based on the probability
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 1; i <= numVertices; i++)
    {
        for (int j = i + 1; j <= numVertices; j++)
        {
            if (dis(gen) <= edgeProbability)
            {
                graph.addEdge(i, j);
            }
        }
    }

    return graph;
}

int main()
{
    int numVertices;
    double edgeProbability;

    std::cout << "Enter the number of vertices: ";
    std::cin >> numVertices;

    std::cout << "Enter the edge probability (between 0 and 1): ";
    std::cin >> edgeProbability;

    Graph randomGraph = generateRandomGraph(numVertices, edgeProbability);

    std::cout << "Random Graph:" << std::endl;
    randomGraph.display();

    return 0;
}
