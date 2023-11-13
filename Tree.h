#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <list>
#include <string>

template <typename T>
class Node {
public:
    T data;
    std::string comment;
    Node<T>* parent;
    std::list<Node<T>*> children;

    Node(T value, const std::string& comment = "", Node<T>* parent = nullptr)
        : data(value), comment(comment), parent(parent) {}

    bool isLeaf() const {
        return children.empty();
    }
};

template <typename T>
class Tree {
private:
    Node<T>* root;

public:
    Tree();
    ~Tree();
    void destroy(Node<T>* node);

    Node<T>* getRoot() const;

    Node<T>* getParent(Node<T>* node) const;

    std::list<Node<T>*> getChildren(Node<T>* node) const;

    int getSize(const Node<T>* node) const;
    int getSize() const;

    int getDepth() const;
    int getDepth(const Node<T>* node) const;
    int _getDepth(const Node<T>* node) const;

    bool isEmpty() const;

    bool isRoot(Node<T>* node) const;

    bool isLeaf(Node<T>* node) const;

    void insertRoot(T value, const std::string& comment = "");

    void insertRoot(T value);

    void insertChild(Node<T>* parent, T value, const std::string& comment = "");

    void insertRandom(T value, const std::string& comment = "");

    Node<T>* findNodeAtPosition(Node<T>* startNode, int& position) const;

    void deleteNode(Node<T>* node);

    void depthFirstTraversal(Node<T>* node) const;
    void depthFirstTraversal() const;
};

#endif // TREE_H
