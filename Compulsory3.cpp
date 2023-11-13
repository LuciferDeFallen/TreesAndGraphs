// Compulsory3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Tree.h"
#include "Graph.h"
using namespace std;

// main function
int main() {

    Graph<int> graph;

    // Insert nodes
    // The insert function returns a pointer to the inserted node 
    // It can be stored in a variable or ignored
    // I wanted to do this for the trees but I forgot
    Graph<int>::Vertex* node1 = graph.insertNode(1, "Node 1");
    Graph<int>::Vertex* node2 = graph.insertNode(2, "Node 2");
    Graph<int>::Vertex* node3 = graph.insertNode(3, "Node 3");
    Graph<int>::Vertex* node4 = graph.insertNode(4, "Node 4");
    Graph<int>::Vertex* node5 = graph.insertNode(5, "Node 5");

    // cout << "Comment for node4: " << graph.getNodeComment(node4) << "\n"; // Using stored pointer

    list<Graph<int>::Vertex*> vertices = graph.getVertices();

    // Insert edges
    Graph<int>::Edge* edge1 = graph.insertEdge(node1, node2, "Edge 1-2");
    Graph<int>::Edge* edge2 = graph.insertEdge(node2, node3, "Edge 2-3");
    Graph<int>::Edge* edge3 = graph.insertEdge(node3, node4, "Edge 3-4");
    Graph<int>::Edge* edge4 = graph.insertEdge(node4, node1, "Edge 4-1");
    Graph<int>::Edge* edge5 = graph.insertEdge(node1, node3, "Edge 1-3");
    Graph<int>::Edge* edge6 = graph.insertEdge(node3, node5, "Edge 3-5");
    Graph<int>::Edge* edge7 = graph.insertEdge(node4, node4, "Edge 4-4");


    // Print graph information
    std::cout << "Number of vertices: " << graph.getVertexCount() << "\n";
    std::cout << "Number of edges: " << graph.getEdgeCount() << "\n";


    cout << "\nBreadth-first traversal:\n";
    graph.breadthFirstTraversal(node1);

    // Delete an edge
    graph.deleteEdge(node1, node4);
    cout << "\nAfter edge deletion:\n";
    cout << "Number of vertices: " << graph.getVertexCount() << "\n";
    cout << "Number of edges: " << graph.getEdgeCount() << "\n";

    // Delete a node
    graph.deleteNode(node2);
    cout << "\nAfter node deletion:\n";
    cout << "Number of vertices: " << graph.getVertexCount() << "\n";
    cout << "Number of edges: " << graph.getEdgeCount() << "\n";

    // Print updated graph information
    cout << "\nAfter deletions:\n";
    cout << "Number of vertices: " << graph.getVertexCount() << "\n";
    cout << "Number of edges: " << graph.getEdgeCount() << "\n";

    cout << "\nBreadth-first traversal:\n";
    graph.breadthFirstTraversal(node1);



    cout << "\n\n---\nTREES\n";

    Tree<string> tree;    // Node<string> root = tree.insertRoot("Text for root node", "Root node comment");
    tree.insertRoot("Text for root node", "Root node comment");
    tree.insertChild(tree.getRoot(), "Child of root", "Wow, what a cool node!");
    tree.insertChild(tree.getRoot(), "Second child of root", "Oh my, what's this, another node?");

    // Storing root's children in list
    list<Node<string>*> children = tree.getChildren(tree.getRoot());

    tree.insertChild(children.front(), "A leaf!", "Grandchild of root :O");

    // Get data & comments
    cout << "children.front()->children.front()->comment " << children.front()->children.front()->comment << "\n";
    cout << "children.front()->data " << children.front()->data << "\n";

    // Some logic stuffs
    cout << "children.front()->isLeaf() " << 
        children.front()->isLeaf() << "\n"; // This one has children
    cout << "children.back()->isLeaf() " << 
        children.back()->isLeaf() << "\n"; // This one is a leaf
    cout << "tree.getRoot()->isLeaf() " << 
        tree.getRoot()->isLeaf() << "\n"; // Root is not leaf
    cout << "tree.isRoot(tree.getRoot()) " << 
        tree.isRoot(tree.getRoot()) << "\n"; // Check if root is root
    cout << "tree.isRoot(children.back()) " << 
        tree.isRoot(children.back()) << "\n"; // Check if child is root

    cout << "tree.getParent(children.front())->data " << 
        tree.getParent(children.front())->data << "\n"; // Use tree to get parent
    cout << "children.front()->parent->data " << 
        children.front()->parent->data << "\n"; // Get parent from node data

    cout << "tree.getSize() " <<
        tree.getSize() << "\n"; // Get size
    cout << "tree.getSize(children.front()) " <<
        tree.getSize(children.front()) << "\n"; // Get size of child

    cout << "tree.getDepth() " <<
        tree.getDepth() << "\n"; // Get depht
    cout << "tree.getDepth(children.front()) " <<
        tree.getDepth(children.front()) << "\n"; // Get depht of child

    cout << "\nIncreasing tree size and depht\n";
    // This should increase depht to 5 for root
    tree.insertChild(tree.getRoot(), "Third child of root");
    tree.insertChild(tree.getRoot()->children.back(), "Child of third child");
    tree.insertChild(tree.getRoot()->children.back()->children.back(), "Child of child of third child");
    tree.insertChild(tree.getRoot()->children.back()->children.back()->children.back(), "Child of child of child of third child");
    tree.insertChild(tree.getRoot()->children.back()->children.back()->children.back()->children.back(), "Child of child of child of child of third child");
    tree.insertChild(tree.getRoot(), "Fourth child of root", "");

    cout << "tree.getDepth() " <<
        tree.getDepth() << "\n"; // Get depht
    cout << "tree.getDepth(children.front()) " <<
        tree.getDepth(children.front()) << "\n"; // Get depht of child
    cout << "tree.getDepth(*next(tree.getChildren(tree.getRoot()).begin(), 2)) " <<
        tree.getDepth(*next(tree.getChildren(tree.getRoot()).begin(), 2)) << "\n"; // Get depht of child
    cout << "tree.getSize() " <<
        tree.getSize() << "\n"; // Get size

    cout << "\nDepht-first traversal:\n";
    tree.depthFirstTraversal();

    cout << "\n\ndeleting third child of root " <<"\n";
    tree.deleteNode((*next(tree.getChildren(tree.getRoot()).begin(), 2)));
    cout << "tree.getSize() " <<
        tree.getSize() << "\n"; // Get size
    cout << "tree.getDepth() " <<
        tree.getDepth() << "\n"; // Get depht

    cout << "\nThird child should be gone now, printing children of root:\n";
    for (Node<string>* child : tree.getChildren(tree.getRoot())) cout << child->data << "\n";

    // Perform a depth-first traversal and print node values
    //cout << tree.getRoot()->parent;



    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
