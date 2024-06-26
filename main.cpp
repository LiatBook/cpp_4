//bookliat@gmail.com
#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"
#include "complex.hpp" // Assuming you have a Complex class implementation

using namespace std;

int main()
{
     sf::RenderWindow window(sf::VideoMode(800, 600), "EX4 - Binary-Tree Visualization");
    // Create a root node with a complex number
    Node<Complex> root_node = Node<Complex>(Complex(1.1, 2.2));

    // Create additional nodes with complex numbers
    Node<Complex> n1 = Node<Complex>(Complex(1.2, 2));
    Node<Complex> n2 = Node<Complex>(Complex(1.3, 2));
    Node<Complex> n3 = Node<Complex>(Complex(1, 2));
    Node<Complex> n4 = Node<Complex>(Complex(1, 2));
    Node<Complex> n5 = Node<Complex>(Complex(1.6, 2.7));
    Tree<Complex> tree; // Binary tree that contains Complex numbers.
    tree.add_root(&root_node);

    // Add sub-nodes to the tree
    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Red);

        // Render the tree using the Tree class method
        tree.render(window);

        window.display();
    }

    // Iterating over the tree using different traversal methods
    cout << "Pre-order traversal:" << endl;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
         cout << node->get_value() << endl;
    } 

    cout << "Post-order traversal:" << endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
         cout << node->get_value() << endl;
    } 

    cout << "In-order traversal:" << endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
         cout << node->get_value() << endl;
    } 

    cout << "BFS scan traversal:" << endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << endl;
    } 

    cout << "MIN HEAP scan traversal:" << endl;
    for (auto node = tree.begin_min_heap(); node != tree.end_min_heap(); ++node)
    {
         cout << node->get_value() << endl;
    }

    cout << "Iterating using range-based for loop (BFS):" << endl;
     for (auto node : tree)
    {
        
         cout << node->get_value() << endl;
    }






    sf::RenderWindow window2(sf::VideoMode(800, 600), "EX4 - Fournary-Tree Visualization");
    // Create a root node with a complex number
    Node<Complex> root_node2 = Node<Complex>(Complex(1, 2));

    // Create additional nodes with complex numbers
    Node<Complex> n12 = Node<Complex>(Complex(1, 3));
    Node<Complex> n22 = Node<Complex>(Complex(1, 4));
    Node<Complex> n32 = Node<Complex>(Complex(1, 5));
    Node<Complex> n42 = Node<Complex>(Complex(1, 6));
    Node<Complex> n52 = Node<Complex>(Complex(1, 7));
    Tree<Complex,4> tree2; // Binary tree that contains Complex numbers.

    tree2.add_root(&root_node2);
    // Add sub-nodes to the tree
    tree2.add_sub_node(&root_node2, &n12);
    tree2.add_sub_node(&root_node2, &n22);
    tree2.add_sub_node(&root_node2, &n32);
    tree2.add_sub_node(&root_node2, &n42);
    tree2.add_sub_node(&n22, &n52);


    while (window2.isOpen()) {
        sf::Event event;
        while (window2.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window2.close();
            }
        }

        window2.clear(sf::Color::Red);

        // Render the tree using the Tree class method
        tree2.render(window2);

        window2.display();
    }

    // Iterating over the tree using different traversal methods
    cout << "Pre-order traversal:" << endl;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
         cout << node->get_value() << endl;
    } 

    cout << "Post-order traversal:" << endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
         cout << node->get_value() << endl;
    } 

    cout << "In-order traversal:" << endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
         cout << node->get_value() << endl;
    } 

    cout << "BFS scan traversal:" << endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << endl;
    } 

    cout << "MIN HEAP scan traversal:" << endl;
    for (auto node = tree.begin_min_heap(); node != tree.end_min_heap(); ++node)
    {
         cout << node->get_value() << endl;
    }

    cout << "Iterating using range-based for loop (BFS):" << endl;
     for (auto node : tree)
    {
        
         cout << node->get_value() << endl;
    }
    
    return 0;
}