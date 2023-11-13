#include "Tree.h"
#include <queue>
#include <cstdlib>
#include <ctime>

template <typename T>
Tree<T>::Tree() : root(nullptr) {}

// Destruction
template <typename T>
Tree<T>::~Tree() {
    // destroy root recursively
    destroy(root);
}

template <typename T>
void Tree<T>::destroy(Node<T>* node) {
    // Destroy children recursively before destroying node
    if (node != nullptr) for (Node<T>* child : node->children) destroy(child);
    delete node;
    
}

// some functions
template <typename T>
Node<T>* Tree<T>::getRoot() const {
    return root;
}

template <typename T>
Node<T>* Tree<T>::getParent(Node<T>* node) const {
    return node ? node->parent : nullptr;
}

template <typename T>
std::list<Node<T>*> Tree<T>::getChildren(Node<T>* node) const {
    return node ? node->children : std::list<Node<T>*>();
}


// Get size of subtree starting at node
template <typename T>
int Tree<T>::getSize(const Node<T>* node) const {
    if (node == nullptr) {
        // If tree is empty, size is 0
        return 0;
    }

    int size = 1;  // Count the current node
    for (const Node<T>* child : node->children) {
        size += getSize(child);
    }

    return size;
}
template <typename T>
int Tree<T>::getSize() const {
    return getSize(root);
}


template <typename T>
int Tree<T>::getDepth() const {
    return getDepth(root);
}
template <typename T>
int Tree<T>::getDepth(const Node<T>* node) const {
    return _getDepth(node) - 1;
}
template <typename T>
int Tree<T>::_getDepth(const Node<T>* node) const {
    int depht = 0;
    for (const Node<T>* child : node->children) {
        int _depht = _getDepth(child);
        depht = std::max(depht, _depht);
    }
    return depht + 1;
}

template <typename T>
bool Tree<T>::isEmpty() const {
    return root == nullptr;
}

template <typename T>
bool Tree<T>::isRoot(Node<T>* node) const {
    return node && (node == root);
}

template <typename T>
bool Tree<T>::isLeaf(Node<T>* node) const {
    return node && node->isLeaf();
}

template <typename T>
void Tree<T>::insertRoot(T value, const std::string& comment) {
    if (root == nullptr) {
        root = new Node<T>(value, comment);
    }
    else {
        throw std::invalid_argument("Tree already has root.");
    }
}

template <typename T>
void Tree<T>::insertRoot(T value) {
    insertRoot(value, "");
}

template <typename T>
void Tree<T>::insertChild(Node<T>* parent, T value, const std::string& comment) {
    if (parent) {
        Node<T>* newNode = new Node<T>(value, comment, parent);
        parent->children.push_back(newNode);
    }
    else {
        throw std::invalid_argument("Cannot add child to nullptr.");
    }
}

template <typename T>
void Tree<T>::insertRandom(T value, const std::string& comment) {
    if (root == nullptr) {
        // Insert as root if tree is empty
        insertRoot(value, comment);
        return;
    }

    // set rseed and generate random index in tree size
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int randomPosition = std::rand() % getSize();

    // find node at generated index and insert child
    Node<T>* targetNode = findNodeAtPosition(root, randomPosition);
    insertChild(targetNode, value, comment);
}

template <typename T>
Node<T>* Tree<T>::findNodeAtPosition(Node<T>* startNode, int& position) const {
    if (startNode == nullptr) return nullptr;

    // If the current node is the target position, return startNode
    if (position == 0) return startNode;

    // Decrement pos
    position--;

    // Recursive search in children
    for (Node<T>* child : startNode->children) {
        Node<T>* result = findNodeAtPosition(child, position);
        if (result != nullptr) return result;
    }

    return nullptr;
}

template <typename T>
void Tree<T>::deleteNode(Node<T>* node) {
    if (node == nullptr) return;

    // If node has parent, delete node from parent's child list
    if (node->parent != nullptr) {
        auto& parentChildren = node->parent->children;
        parentChildren.erase(std::remove(parentChildren.begin(), parentChildren.end(), node), parentChildren.end());
    }
    destroy(node);
}

template <typename T>
void Tree<T>::depthFirstTraversal(Node<T>* node) const {
    if (node == nullptr) return;
    std::cout << "Visited Node: " << node->data << "\n";
    for (Node<T>* child : node->children) depthFirstTraversal(child);
}
template <typename T>
void Tree<T>::depthFirstTraversal() const {
    depthFirstTraversal(root);
}

// Explicit instantiation for allowed types
template class Node<int>;
template class Node<double>;
template class Node<std::string>;
template class Node<bool>;
template class Node<float>;
template class Node<long>;

template class Tree<int>;
template class Tree<double>;
template class Tree<std::string>;
template class Tree<bool>;
template class Tree<float>;
template class Tree<long>;
