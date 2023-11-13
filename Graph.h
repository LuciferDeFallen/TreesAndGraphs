#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <map>
#include <stdexcept>

template <typename T>
class Graph {
public:
    struct Edge;
    struct Vertex {
        T data;
        std::string comment;
        std::map<Edge*, Vertex*> adjacentVertices;
    };

    struct Edge {
        Vertex* source;
        Vertex* destination;
        std::string comment;
    };



public:
    std::list<Vertex*> vertices;
    std::list<Edge*> edges;
    Graph();

    // Access functions
    T getNodeData(Vertex* vertex) const;
    std::string getNodeComment(Vertex* vertex) const;
    std::map<Edge*, Vertex*> getAdjacentNodes(Vertex* vertex) const;
    std::list<Vertex*> getVertices() const;
    int getVertexCount() const;
    int getEdgeCount() const;

    // Query functions
    bool isEmpty() const;

    // Insertion functions
    Vertex* insertNode(T data, const std::string& comment = "");
    Edge* insertEdge(Vertex* source, Vertex* destination, const std::string& comment = "");

    // Deletion functions
    void deleteNode(Vertex* vertex);
    void deleteEdge(Vertex* source, Vertex* destination);

    // Traversal functions
    void depthFirstTraversal(Vertex* startNode) const;
    void breadthFirstTraversal(Vertex* startNode) const;
};

#endif // GRAPH_H
