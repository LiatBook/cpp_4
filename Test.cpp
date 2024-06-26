
#include "iterator.hpp"
#include "tree.hpp" // Replace with the actual header file name
#include "node.hpp"
#include "doctest.h"
#include <vector>
#include <string>

using std::string;


TEST_CASE("PreOrderIterator") {
    // Create a tree with nodes allocated on heap
    
    Node<int> node1(1);
    Node<int> node2(2);
    Node<int> node3(3);
    Node<int> node4(4);
    Node<int> node5(5);
    Node<int> node6(6);
    Node<int> node7(7);
    Tree<int> tree;
    // Construct the tree
    tree.add_root(&node1);
    tree.add_sub_node(&node1, &node2);
    tree.add_sub_node(&node1, &node3);
    tree.add_sub_node(&node2, &node4);
    tree.add_sub_node(&node2, &node5);
    tree.add_sub_node(&node3, &node6);
    tree.add_sub_node(&node3, &node7);

    // Expected pre-order traversal result
    std::vector<int> expected = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> result;

    // Perform pre-order traversal
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        result.push_back(it->get_value());
    }

    // Compare result with expected
    CHECK(result == expected);

   
}



TEST_CASE(" Post/In/Pre Iterator when number of child>2 ->DFS")
{
    
    Node<string> node0("name");
    Node<string> node1("l");
    Node<string> node2("i");
    Node<string> node3("a");
    Node<string> node4("t");
    Node<string> node5("b");
    Node<string> node6("o");
    Node<string> node7("o");
    Node<string> node8("k");
    Tree<string,8> tree;
    // Construct the tree
    tree.add_root(&node0);
    tree.add_sub_node(&node0, &node1);
    tree.add_sub_node(&node0, &node2);
    tree.add_sub_node(&node0, &node3);
    tree.add_sub_node(&node0, &node4);
    tree.add_sub_node(&node0, &node5);
    tree.add_sub_node(&node0, &node6);
    tree.add_sub_node(&node0, &node7);
    tree.add_sub_node(&node0, &node8);
    
        std::vector<string> expected = {"name","l", "i", "a", "t", "b", "o", "o", "k"};
        std::vector<string> result;
        for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result == expected);
        std::vector<string> result2;
        for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
            result2.push_back(it->get_value());

        }
        CHECK(result == result2);
        std::vector<string> result3;
        for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
            result3.push_back(it->get_value());

        }
        CHECK(result3 == result2);
    
}


TEST_CASE(" InOrderIterator ")
{
    
    Node<string> node0("l");
    Node<string> node1("name:");
    Node<string> node2("i");
     Tree<string,2> tree;
    // Construct the tree
    tree.add_root(&node0);
    tree.add_sub_node(&node0, &node1);
    tree.add_sub_node(&node0, &node2);
    
        std::vector<string> expected = {"name","l", "i"};
        std::vector<string> result;
        for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK_FALSE(result == expected);
    
}

TEST_CASE(" BFSIterator for binary tree")
{
    
    Node<double> node0(1.1);
    Node<double> node1(1.2);
    Node<double> node2(1.3);

    Tree<double,2> tree;
    // Construct the tree
    tree.add_root(&node0);
    tree.add_sub_node(&node0, &node1);
    tree.add_sub_node(&node0, &node2);
   
        std::vector<double> expected = {1.1,1.2, 1.3};
        std::vector<double> result;
        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result == expected);
   
}

TEST_CASE(" TRY TO ADD MORE CHILD WHEN NUM OF CHILD IN MAX (1)")
{
    
    Node<double> node0(1.1);
    Node<double> node1(1.2);
    Node<double> node2(1.3);
    Tree<double,1> tree;
    tree.add_root(&node0);
    tree.add_sub_node(&node0, &node1);
    CHECK_THROWS(tree.add_sub_node(&node0, &node2));
    
}
TEST_CASE(" TRY TO ADD MORE CHILD WHEN NUM OF CHILD IN MAX (2)")
{
    
    Node<double> node0(1.1);
    Node<double> node1(1.2);
    Node<double> node2(1.3);
    Node<double> node3(1.4);
    Tree<double,2> tree;
    tree.add_root(&node0);
    tree.add_sub_node(&node0, &node1);
    tree.add_sub_node(&node0, &node2);
    CHECK_THROWS(tree.add_sub_node(&node0, &node3));
    
}

TEST_CASE(" BFSIterator for not binary tree")
{
    
    Node<double> node0(1.1);
    Node<double> node1(1.2);
    Node<double> node2(1.3);
    Node<double> node3(1.4);
    Node<double> node4(1.5);
    Tree<double,3> tree;
    // Construct the tree
    tree.add_root(&node0);
    tree.add_sub_node(&node0, &node1);
    tree.add_sub_node(&node0, &node2);
    tree.add_sub_node(&node0, &node3);
    tree.add_sub_node(&node1, &node4);
   
        std::vector<double> expected = {1.1,1.2,1.5, 1.3,1.4};
        std::vector<double> result;
        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK_FALSE(result == expected);
   
}


TEST_CASE("Node -get value")
{
    Node<int> node1(1);
    Node<int> node2(2);
    Node<int> node3(3);
    Node<int> node4(4);

    // Check initial values
    CHECK(node1.get_value() == 1);
    CHECK(node2.get_value() == 2);
    CHECK(node3.get_value() == 3);
    CHECK(node4.get_value() == 4);

}


TEST_CASE("Node -add child/get child")
{
    Node<int> node1(1);
    Node<int> node2(2);
    Node<int> node3(3);
    Node<int> node4(4);
// Add children to node1
    node1.add_child(&node2);
    node1.add_child(&node3);

    // Add child to node2
    node2.add_child(&node4);

    // Check children of node1
    std::vector<Node<int>*>& children1 = node1.get_child();
    CHECK(children1.size() == 2);
    CHECK(children1[0]->get_value() == 2);
    CHECK(children1[1]->get_value() == 3);

    // Check children of node2
    std::vector<Node<int>*>& children2 = node2.get_child();
    CHECK(children2.size() == 1);
    CHECK(children2[0]->get_value() == 4);

    // Check that node3 and node4 have no children
    std::vector<Node<int>*>& children3 = node3.get_child();
    CHECK(children3.size() == 0);
    
    std::vector<Node<int>*>& children4 = node4.get_child();
    CHECK(children4.size() == 0);
}

TEST_CASE("MinHeapIterator for heap tree") 
{
    
    Node<int> node1(1);
    Node<int> node2(2);
    Node<int> node3(3);
    Node<int> node4(4);
    Node<int> node5(5);
    Tree<int, 2> tree;
    // Construct the heap tree
    tree.add_root(&node1);
    tree.add_sub_node(&node1, &node2);
    tree.add_sub_node(&node1, &node3);
    tree.add_sub_node(&node2, &node4);
    tree.add_sub_node(&node2, &node5);

    std::vector<int> expected = {1, 2, 3, 4, 5};
    std::vector<int> result;
    for (auto it = tree.begin_min_heap(); it != tree.end_min_heap(); ++it) {
        result.push_back(it->get_value());
    }

    CHECK(result == expected);
}