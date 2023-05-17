#include <iostream>


template <typename T>
class Node{
    Node* left;
    Node* right;
    T value

    public:

        friend class Tree;
        Node() : left(nullptr), right(nullptr), value() {}
        Node(T val): left(nullptr), right(nullptr), value(val) {}
        // Node(const Node& node) = delete;
        

};


template <typename T>
class Tree{
    
};