/**
 * Demo app for Ex4
 */
#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"

using namespace std;

int main()
{

    Node<double> root_node(1.1);
    Node<double> n1 = Node<double>(1.2);
    Node<double> n2 = Node<double>(1.3);
    Node<double> n3 = Node<double>(1.4);
    Node<double> n4 = Node<double>(1.5);
    Node<double> n5 = Node<double>(1.6);
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "EX4 - Tree Visualization");
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(&root_node);
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
   
    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << "first print"<< endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout << "second print"<< endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout << "third print"<< endl;

    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << "fourth print"<< endl;

    for (auto node = tree.begin_min_heap(); node != tree.end_min_heap(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << "last print"<< endl;
     for (auto node : tree)
    {
        
        cout << node->get_value() << endl;
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

   
    // cout << tree; // Should print the graph using GUI.
}
{
     sf::RenderWindow window(sf::VideoMode(800, 600), "EX4 - Tree Visualization");
    Tree<double,3> three_ary_tree; // 3-ary tree.
    three_ary_tree.add_root(&root_node);
   
    three_ary_tree.add_sub_node(&root_node, &n1);
   
    three_ary_tree.add_sub_node(&root_node, &n2);
   
    three_ary_tree.add_sub_node(&root_node, &n3);
    
    three_ary_tree.add_sub_node(&n1, &n4);
    
    three_ary_tree.add_sub_node(&n2, &n5);
       

     // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */

     while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Red);

        // Render the tree using the Tree class method
        three_ary_tree.render(window);

        window.display();
    }
} 
}
	
