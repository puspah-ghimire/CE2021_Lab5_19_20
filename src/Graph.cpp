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

void Graph::addVertex(int newVertex) 
{
    if (newVertex <= 0) {
        cout<<"Invalid vertex!"<<endl;
    }
    numV++;

    bool** newMatrix = new bool*[numV];
    for (int i = 0; i < numV; i++) 
    {
        newMatrix[i] = new bool[numV];
        for (int j = 0; j < numV; j++) 
        {
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

void Graph::addEdge(int vertex1, int vertex2)
{
    if(isEmpty())
    {
        cout<<"The graph is empty."<<endl;
        return;
    }

    else if(vertex1 > numV || vertex2 > numV)
    {
        if(vertex1 > numV)
        {
            cout<<"Vertex "<<vertex1<<"doesn't exist in graph."<<endl;
        }
        if(vertex2 > numV)
        {
            cout<<"Vertex "<<vertex2<<"doesn't exist in graph."<<endl;
        }
        return;
    }

    else
    {
        adjacencyMatrix[vertex1 - 1][vertex2 - 1] = 1;
        if(!directed)
        {
            adjacencyMatrix[vertex2 - 1][vertex1 - 1] = 1;
        }
        
    }
    numE++;
}

int Graph::numVertices(){
    return numV;
}

int Graph::numEdges(){
    return numE;
}

int Graph::indegree(int vertex)
{
    if (isEmpty()) 
    {
        cout<<"The graph is empty."<<endl;
        return 0;
    }

    if(vertex>numV)
    {
        cout<<"Invalid vertex!"<<endl;
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

void Graph::display()
{
    for (int i = 0; i < numV; i++) {
        for (int j = 0; j < numV; j++) {
            std::cout << adjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
