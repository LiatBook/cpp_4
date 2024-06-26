//bookliat@gmail.com
#include "node.hpp"
#include <SFML/Graphics.hpp>
#include "iterator.hpp" 
#pragma once
#include <iostream>

template <typename T,int S=2> 
class Tree{
    private:
    Node<T>* root;


      void renderNode(Node<T>* node, sf::RenderWindow& window, float x, float y, float xOffset) {
        if (!node)
            return;

        // Draw node (example: circle)
        sf::CircleShape circle(20.f);
        circle.setFillColor(sf::Color::Blue);
        circle.setPosition(x, y);
        window.draw(circle);

        // Draw text (example: value)
        sf::Font font;
        font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf");
        sf::Text text(node->string_to_string(node->get_value()), font);
        text.setCharacterSize(12);
        text.setFillColor(sf::Color::White);
        text.setPosition(x + 10.f, y + 10.f);
        window.draw(text);
        

        // Draw edges to children
        auto children = node->get_child();
        float childX = x - xOffset;
        for (auto child : children) {
            if (child) {
                // Draw edge line (example: line)
                sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(x + 10.f, y + 10.f)),
                    sf::Vertex(sf::Vector2f(childX + 10.f, y + 50.f))
                };
                window.draw(line, 2, sf::Lines);

                // Recursively draw children
                renderNode(child, window, childX, y + 50.f, xOffset / 2.f);
                childX += xOffset;

            }
        }
    }


    public:
    Tree():root(nullptr){} // Add default constructor
        // Rest of the class definition...
    
   
    ~Tree() {
    if (root == nullptr) {
            return;
        }

        std::queue<Node<T>*> queue;
        queue.push(root);

        while (!queue.empty()) {
            Node<T>* current = queue.front();
            queue.pop();

            // Enqueue children for further deletion
            for (auto child : current->get_child()) {
                if (child != nullptr) {
                    queue.push(child);
                }
            }

            // Clear the child vector before deleting the node
            current->get_child().clear();
        }

        root = nullptr;
        }
     

    void render(sf::RenderWindow& window) {
        if (root) {
            renderNode(root, window, 400.f, 50.f, 100.f); 
        }
    }
void add_root(Node<T>* root_node){
    root=root_node;
 }

void add_sub_node(Node<T>* parent, Node<T>* child) {
    // Check if the tree has reached its maximum size S
    if (parent->get_child().size() == S) {
        throw std::runtime_error("Tree size limit reached for parent node. Cannot add more children.");
    }
    // Add child node to the parent's list of children
    parent->get_child().push_back(child);
}


TREE_DFSIterator<T> begin_pre_order(){
  
        return TREE_DFSIterator<T>(root);
    
}

TREE_DFSIterator<T> end_pre_order(){
   
        return TREE_DFSIterator<T>(nullptr);
    
}

TREE_DFSIterator<T> begin_post_order(){
  
        return TREE_DFSIterator<T>(root);
    
}

TREE_DFSIterator<T> end_post_order(){
   
        return TREE_DFSIterator<T>(nullptr);
    
}
TREE_DFSIterator<T> begin_in_order(){
  
        return TREE_DFSIterator<T>(root);
    
}

TREE_DFSIterator<T> end_in_order(){
   
        return TREE_DFSIterator<T>(nullptr);
    
}

TREE_BFSIterator<T> begin_bfs_scan(){
    return TREE_BFSIterator<T>(root);
}

TREE_BFSIterator<T> end_bfs_scan(){
    return TREE_BFSIterator<T>(nullptr);
}
TREE_BFSIterator<T> begin(){
    return begin_bfs_scan();
}

TREE_BFSIterator<T> end(){
    return end_bfs_scan();
}

MinHeapIterator<T> begin_min_heap(){
    // if(S!=2){
    //     return;
    // }
    return MinHeapIterator<T>(root);
}

MinHeapIterator<T> end_min_heap(){
    // if(S!=2){
    //     return;
    // }
    return MinHeapIterator<T>(nullptr);
}

void myHeap(Node<T>* root) {
    if (root == nullptr) {
        return;
    }
    // Recursively heapify the left and right subtrees
    for (auto child : root->get_child()) {
        myHeap(child);
    }
    // Heapify the current node
    make_heap(root);
}
 
    
};















template <typename T> 
class Tree<T,2>{
    private:
    Node<T>* root;


      void renderNode(Node<T>* node, sf::RenderWindow& window, float x, float y, float xOffset) {
        if (!node)
            return;

        // Draw node (example: circle)
        sf::CircleShape circle(20.f);
        circle.setFillColor(sf::Color::Blue);
        circle.setPosition(x, y);
        window.draw(circle);

        // Draw text (example: value)
        sf::Font font;
        font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf");
        sf::Text text(node->string_to_string(node->get_value()), font);
        text.setCharacterSize(12);
        text.setFillColor(sf::Color::White);
        text.setPosition(x + 10.f, y + 10.f);
        window.draw(text);
        

        // Draw edges to children
        auto children = node->get_child();
        float childX = x - xOffset;
        for (auto child : children) {
            if (child) {
                // Draw edge line (example: line)
                sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(x + 10.f, y + 10.f)),
                    sf::Vertex(sf::Vector2f(childX + 10.f, y + 50.f))
                };
                window.draw(line, 2, sf::Lines);

                // Recursively draw children
                renderNode(child, window, childX, y + 50.f, xOffset / 2.f);
                childX += xOffset;

            }
        }
    }

    public:
     void render(sf::RenderWindow& window) {
        if (root) {
            renderNode(root, window, 400.f, 50.f, 100.f); 
        }
    }
    Tree():root(nullptr){} // Add default constructor
        // Rest of the class definition...
     ~Tree() {
     if (root == nullptr) {
            return;
        }

        std::queue<Node<T>*> queue;
        queue.push(root);

        while (!queue.empty()) {
            Node<T>* current = queue.front();
            queue.pop();

            // Enqueue children for further deletion
            for (auto child : current->get_child()) {
                if (child != nullptr) {
                    queue.push(child);
                }
            }

            // Clear the child vector before deleting the node
            current->get_child().clear();
        }

        root = nullptr;
}
     

void add_root(Node<T>* root_node){
    root=root_node;
 }

void add_sub_node(Node<T>* parent, Node<T>* child) {
    // Check if the tree has reached its maximum size S
    if (parent->get_child().size() >= 2) {
        throw std::runtime_error("Tree size limit 2 reached for parent node. Cannot add more children.");
    }    
    // Add child node to the parent's list of children
    parent->add_child(child);
}


PreOrderIterator<T> begin_pre_order(){

     return PreOrderIterator<T>(root);
}

PreOrderIterator<T> end_pre_order(){
    
     return PreOrderIterator<T>(nullptr);
}

PostOrderIterator<T> begin_post_order(){
    
    return PostOrderIterator<T>(root);
}

PostOrderIterator<T> end_post_order(){
 
     return PostOrderIterator<T>(nullptr);
}

InOrderIterator<T> begin_in_order(){
    
    return InOrderIterator<T>(root);
}

InOrderIterator<T> end_in_order(){
    
    return InOrderIterator<T>(nullptr);
}

TREE_BFSIterator<T> begin_bfs_scan(){
    return TREE_BFSIterator<T>(root);
}

TREE_BFSIterator<T> end_bfs_scan(){
    return TREE_BFSIterator<T>(nullptr);
}
TREE_BFSIterator<T> begin(){
    return begin_bfs_scan();
}

TREE_BFSIterator<T> end(){
    return end_bfs_scan();
}

MinHeapIterator<T> begin_min_heap(){
    
    return MinHeapIterator<T>(root);
}

MinHeapIterator<T> end_min_heap(){
   
    return MinHeapIterator<T>(nullptr);
}

void myHeap(Node<T>* root) {
    if (root == nullptr) {
        return;
    }
    // Recursively heapify the left and right subtrees
    for (auto child : root->get_child()) {
        myHeap(child);
    }
    // Heapify the current node
    make_heap(root);
}
    
};
