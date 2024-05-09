#include <iostream>

template <typename T> class Node
{
private:
    T data;
    Node<T>* left;
    Node<T>* right;
public:
    Node()
    {
        data = 0;
        left = nullptr;
        right = nullptr;
    }
    
    Node(T item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
    
    T Get()
    {
        return data;
    }
    Node<T>* GetLeft()
    {
        return left;
    }
    Node<T>* GetRight()
    {
        return right;
    }
};

template <typename T> class BinaryTree
{
private:
    int size;
    Node<T> root;
public:
    
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
