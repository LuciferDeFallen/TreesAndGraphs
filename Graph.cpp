#include "Graph.h"
#include <iostream>
#include <queue>
#include <set>

template <typename T>
Graph<T>::Graph() {}

template <typename T>
T Graph<T>::getNodeData(Vertex* vertex) const {
    return vertex->data;
}

template <typename T>
std::string Graph<T>::getNodeComment(Vertex* vertex) const {
    return vertex->comment;
}

template <typename T>
std::map<typename Graph<T>::Edge*, typename Graph<T>::Vertex*> Graph<T>::getAdjacentNodes(Vertex* vertex) const {
    return vertex->adjacentVertices;
}

template <typename T>
std::list<typename Graph<T>::Vertex*> Graph<T>::getVertices() const {
    std::list<Graph<T>::Vertex*> rv = vertices;
    return rv;
}

template <typename T>
int Graph<T>::getVertexCount() const {
    return vertices.size();
}

template <typename T>
int Graph<T>::getEdgeCount() const {
    return edges.size();
}

template <typename T>
bool Graph<T>::isEmpty() const {
    return vertices.empty();
}


template <typename T>
typename Graph<T>::Vertex* Graph<T>::insertNode(T data, const std::string& comment) {
    Vertex* newVertex = new Vertex{ data, comment, {} };
    vertices.push_back(newVertex);
    return newVertex;
}

template <typename T>
typename Graph<T>::Edge* Graph<T>::insertEdge(Vertex* source, Vertex* destination, const std::string& comment) {
    Edge* newEdge = new Edge{ source, destination, comment };
    edges.push_back(newEdge);
    source->adjacentVertices[newEdge] = destination;
    destination->adjacentVertices[newEdge] = source;
    return newEdge;
}

template <typename T>
void Graph<T>::deleteNode(Vertex* vertex) {
    // Remove edges containing the deleted node
    for (auto& pair : vertex->adjacentVertices) {
        edges.remove(pair.first);
        pair.second->adjacentVertices.erase(pair.first);
        delete pair.first;
    }

    // Remove the vertex
    vertices.remove(vertex);
    delete vertex;
}


// My deleteEdge function kept crashing so I had ChatGPT make a deleteEdge function
// It seems to be working so I'm just gonna leave it here
template <typename T>
void Graph<T>::deleteEdge(Vertex* source, Vertex* destination) {
    // Search for the edge in the edges list
    Edge* edgeToDelete = nullptr;
    for (Edge* edge : edges) {
        if ((edge->source == source && edge->destination == destination) ||
            (edge->source == destination && edge->destination == source)) {
            edgeToDelete = edge;
            break;
        }
    }

    // If the edge is found, remove it from the edges list
    if (edgeToDelete != nullptr) {
        edges.remove(edgeToDelete);

        // Remove the edge references from the adjacentVertices maps
        source->adjacentVertices.erase(edgeToDelete);
        destination->adjacentVertices.erase(edgeToDelete);

        // Delete the edge
        delete edgeToDelete;
    }
}

template <typename T>
void Graph<T>::depthFirstTraversal(Vertex* startNode) const {
    // Implement depth-first traversal logic
}

template <typename T>
void Graph<T>::breadthFirstTraversal(Vertex* startNode) const {
    if (startNode == nullptr) {
        std::cerr << "Error: Start node is nullptr.\n";
        return;
    }

    std::queue<Vertex*> bfsQueue;
    std::set<Vertex*> visited;

    // Enqueue the starting node
    bfsQueue.push(startNode);
    visited.insert(startNode);

    while (!bfsQueue.empty()) {
        // Dequeue a vertex and visit it
        Vertex* currentVertex = bfsQueue.front();
        bfsQueue.pop();
        std::cout << "Visited Node " << getNodeData(currentVertex) << "\n";

        // Enqueue all unvisited neighbors
        for (const auto& pair : currentVertex->adjacentVertices) {
            Vertex* neighbor = pair.second;
            if (visited.find(neighbor) == visited.end()) {
                bfsQueue.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
}

// Explicit instantiation for allowed types
template class Graph<int>;
template class Graph<double>;
template class Graph<std::string>;
template class Graph<bool>;
template class Graph<float>;
template class Graph<long>;
