#include "graph.hpp"
#include<iostream>

Graph::Graph(bool isDirected) : directed(isDirected) {}

bool Graph::isEmpty() {
    
}

bool Graph::isDirected() {
    return directed;
}