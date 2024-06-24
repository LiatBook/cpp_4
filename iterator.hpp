
#include "node.hpp"
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;
using std::stack;
using std::set;
using std::vector;
using std::queue;   
#pragma once



template<typename T>
class PreOrderIterator {
    private:
        std::stack<Node<T>*> stack;

    public:
        PreOrderIterator(Node<T>* node) {
            if (node) {
                stack.push(node);
            }
        }

        Node<T>* operator*() const {
            return stack.top();
        }

        PreOrderIterator& operator++() {
            if (stack.empty()) {
                return *this;
            }

            Node<T>* current = stack.top();
            stack.pop();

            // Push children onto stack in reverse order (right to left)
            // This ensures left child will be on top of stack and processed first
            for (auto it = current->get_child().rbegin(); it != current->get_child().rend(); ++it) {
                stack.push(*it);
            }

            return *this;
        }

        bool operator!=(const PreOrderIterator& other) const {
            return !stack.empty() || !other.stack.empty();
        }
         Node<T>* operator->() const {
        return stack.top();
    }
    };

template<typename T>
class InOrderIterator {
private:
    Node<T>* current;
    stack<Node<T>*> nodeStack;
    stack<Node<T>*> visitStack;

    void pushLeftMostNodes(Node<T>* node) {
        while (node) {
            nodeStack.push(node);
            if (!node->get_child().empty()) {
                visitStack.push(node);
                node = node->get_child().front();
            } else {
                break;
            }
        }
    }

public:
    InOrderIterator(Node<T>* root) : current(nullptr) {
        if (root) {
            pushLeftMostNodes(root);
            if (!nodeStack.empty()) {
                current = nodeStack.top();
            }
        }
    }

    Node<T>* operator*() const {
        return current;
    }

    InOrderIterator& operator++() {
        if (nodeStack.empty()) {
            current = nullptr;
            return *this;
        }

        Node<T>* topNode = nodeStack.top();
        nodeStack.pop();

        if (!visitStack.empty() && visitStack.top() == topNode) {
            visitStack.pop();
            if (!topNode->get_child().empty()) {
                auto it = topNode->get_child().begin();
                ++it; // Skip the first child
                for (; it != topNode->get_child().end(); ++it) {
                    pushLeftMostNodes(*it);
                }
            }
        }

        current = nodeStack.empty() ? nullptr : nodeStack.top();
        return *this;
    }

    bool operator!=(const InOrderIterator& other) const {
        return current != other.current;
    }

    Node<T>* operator->() const {
        return current;
    }
};

// template<typename T>
// class MinHeapIterator {
// private:
//     std::vector<T>& heap;
//     size_t index;

// public:
//     MinHeapIterator(std::vector<T>& h, size_t idx) : heap(h), index(idx) {}

//     T& operator*() const {
//         return heap[index];
//     }

//     T* operator->() const {
//         return &heap[index];
//     }

//     MinHeapIterator& operator++() {
//         ++index;
//         return *this;
//     }

//     bool operator!=(MinHeapIterator& other) const {
//         return index != other.index;
//     }
// };


template<typename T>
class TREE_BFSIterator {
private:
    queue<Node<T>*> q;

public:
    TREE_BFSIterator(Node<T>* root) {
        if (root)
            q.push(root);
    }

    Node<T>* operator*() const {
        return q.front();
    }

    TREE_BFSIterator& operator++() {
        if (!q.empty()) {
            Node<T>* current = q.front();
            q.pop();
            for (Node<T>* child : current->get_child()) {
                q.push(child);
            }
        }
        return *this;
    }

    bool operator!=(const TREE_BFSIterator& other) const {
        return !q.empty() || !other.q.empty();
    }

    // Operator to support range-based for loop
    TREE_BFSIterator& operator++(int) {
        return operator++(); // Postfix increment calls prefix increment
    }

    // Operator -> to access the node's members
    Node<T>* operator->() const {
        return q.front();
    }
};



template<typename T>
class PostOrderIterator {
private:
    std::stack<Node<T>*> node_stack;
    Node<T>* current;

    void traverse(Node<T>* node) {
        if (!node)
            return;

        node_stack.push(node);

        // Push children to the stack in reverse order
        for (auto it = node->get_child().rbegin(); it != node->get_child().rend(); ++it) {
            traverse(*it);
        }
    }

public:
    PostOrderIterator(Node<T>* root) : current(nullptr) {
        traverse(root);

        if (!node_stack.empty()) {
            current = node_stack.top();
            node_stack.pop();
        }
    }

    bool operator!=(const PostOrderIterator& other) const {
        return current != other.current;
    }

    Node<T>& operator*() const {
        return *current;
    }

    Node<T>* operator->() const {
        return current;
    }

    PostOrderIterator& operator++() {
        if (node_stack.empty()) {
            current = nullptr;
        } else {
            current = node_stack.top();
            node_stack.pop();
        }
        return *this;
    }
};


template <typename T>
class MinHeapIterator {
private:
    std::queue<Node<T>*> nodeQueue;

public:
    MinHeapIterator(Node<T>* root = nullptr) {
        if (root != nullptr) {
            nodeQueue.push(root);
        }
    }

    bool operator!=(const MinHeapIterator& other) const {
        return !nodeQueue.empty() || !other.nodeQueue.empty();
    }

    Node<T>* operator*() const {
        return nodeQueue.front();
    }

    Node<T>* operator->() const {
        return nodeQueue.front();
    }

    MinHeapIterator& operator++() {
        if (!nodeQueue.empty()) {
            Node<T>* node = nodeQueue.front();
            nodeQueue.pop();

            // Enqueue children in the order they appear in get_son()
            for (Node<T>* child : node->get_child()) {
                if (child != nullptr) {
                    nodeQueue.push(child);
                }
            }
        }

        return *this;
    }


    
};

template<typename T>
class TREE_DFSIterator {
private:
    stack<Node<T>*> stk;

public:
    TREE_DFSIterator(Node<T>* root) {
        if (root)
            stk.push(root);
    }

    Node<T>* operator*() const {
        return stk.top();
    }

    TREE_DFSIterator& operator++() {
        if (!stk.empty()) {
            Node<T>* current = stk.top();
            stk.pop();
            // Push children in reverse order to simulate DFS (left to right)
            auto children = current->get_child();
            for (auto it = children.rbegin(); it != children.rend(); ++it) {
                stk.push(*it);
            }
        }
        return *this;
    }

    bool operator!=(const TREE_DFSIterator& other) const {
        return !stk.empty() || !other.stk.empty();
    }

    // Operator to support range-based for loop
    TREE_DFSIterator& operator++(int) {
        return operator++(); // Postfix increment calls prefix increment
    }

    // Operator -> to access the node's members
    Node<T>* operator->() const {
        return stk.top();
    }
};