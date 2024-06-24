
#pragma once
#include <vector>
#include <string>
#include <sstream>
using std::vector;  
using std::string; 
#include <stack>

template <typename T> 
class Node{
    private:
    T data;
    vector<Node<T>*> children;

    public:

    Node(const T& d):data(d){}
    vector<Node<T>*>& get_child(){
        return children;
    }
    void add_child(Node<T>* child)
    {
        children.push_back(child);
    }
    T& get_value(){
    return this->data;
    }
    
    string string_to_string(const T& value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

};
