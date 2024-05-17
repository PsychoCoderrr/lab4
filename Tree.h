#pragma once
#include "Complex.h"
template <typename T> class Node
{
  private:
    T data;
    Node<T> *left;
    Node<T> *right;

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
    Node<T> *GetLeft()
    {
        return left;
    }
    Node<T> *GetRight()
    {
        return right;
    }

    void setLeft(Node<T> *node)
    {
        left = node;
    }
    void setRight(Node<T> *node)
    {
        right = node;
    }

    void SetData(T value)
    {
        this->data = value;
    }
};

template <typename T> class BinaryTree
{
  private:
    int size;
    Node<T> *root;

    void FuncMap(Node<T> *startRoot, T (*func)(T))
    {
        if (startRoot == nullptr)
        {
            return;
        }
        FuncMap(startRoot->GetLeft(), func);
        FuncMap(startRoot->GetRight(), func);
        startRoot->SetData(func(startRoot->Get()));
    }
    
    void FuncWhere(Node<T> *startRoot, bool (*func)(T))
    {
        if (startRoot == nullptr)
        {
            return;
        }
        FuncWhere(startRoot->GetLeft(), func);
        FuncWhere(startRoot->GetRight(), func);
        if (func(startRoot->Get()) == false)
        {
            this->deleteElem(this->root, startRoot->Get());
        }
    }
    
    void ReduceFunc(Node<T>* startRoot, T(*func)(T, T), T* base)
    {
        if (startRoot == nullptr)
        {
            return;
        }
        ReduceFunc(startRoot->GetLeft(), func, base);
        ReduceFunc(startRoot->GetRight(), func, base);
        *base = func(startRoot->Get(), *base);
    }

  public:
    BinaryTree<T>()
    {
        root = nullptr;
        size = 0;
    }

    ~BinaryTree<T>()
    {
        deleteTree(this->GetRoot());
    }

    void deleteTree(Node<T> *elem)
    {
        if (elem == nullptr)
        {
            return;
        }
        deleteTree(elem->GetLeft());
        deleteTree(elem->GetRight());
        delete elem;
    }

    Node<T> *GetRoot()
    {
        return this->root;
    }

    void setRoot(Node<T> *newRoot)
    {
        root = newRoot;
    }

    int GetSize()
    {
        return this->size;
    }

    Node<T> *maximum(Node<T> *startRoot)
    {
        if (startRoot->GetRight() == nullptr)
        {
            return startRoot;
        }
        return minimum(startRoot->GetRight());
    }

    Node<T> *minimum(Node<T> *startRoot)
    {
        if (startRoot->GetLeft() == nullptr)
        {
            return startRoot;
        }
        return minimum(startRoot->GetLeft());
    }

    Node<T> *insert(Node<T> *startRoot, T value)
    {

        if (startRoot == nullptr)
        {
            size++;
            return new Node<T>(value);
        }
        else if (value < startRoot->Get())
        {
            startRoot->setLeft(insert(startRoot->GetLeft(), value));
        }
        else if (value > startRoot->Get())
        {
            startRoot->setRight(insert(startRoot->GetRight(), value));
        }
        return startRoot;
    }

    Node<T> *search(Node<T> *startRoot, T value)
    {
        if (startRoot == nullptr || startRoot->Get() == value)
        {
            return startRoot;
        }
        if (value < startRoot->Get())
        {
            return search(startRoot->GetLeft(), value);
        }
        else
        {
            return search(startRoot->GetRight(), value);
        }
    }

    Node<T> *deleteElem(Node<T> *startRoot, T value)
    {
        if (startRoot == nullptr)
        {
            return startRoot;
        }
        if (value < startRoot->Get())
        {
            startRoot->setLeft(deleteElem(startRoot->GetLeft(), value));
        }
        else if (value > startRoot->Get())
        {
            startRoot->setRight(deleteElem(startRoot->GetRight(), value));
        }
        else if (startRoot->GetLeft() != nullptr && startRoot->GetRight() != nullptr)
        {
            startRoot->SetData((minimum(startRoot->GetRight()))->Get());
            startRoot->setRight(deleteElem(startRoot->GetRight(), startRoot->Get()));
        }
        else
        {
            if (startRoot->GetLeft() != nullptr)
            {
                startRoot = startRoot->GetLeft();
            }
            else if (startRoot->GetRight() != nullptr)
            {
                startRoot = startRoot->GetRight();
            }
            else
            {
                startRoot = nullptr;
            }
        }
        return startRoot;
    }

    void map(T (*func)(T))  //список функций map-Reduce реализован как методы класса
    {
        this->FuncMap(this->GetRoot(), func);
    }
    
    void where(bool(*func)(int))
    {
        this->FuncWhere(this->GetRoot(), func);
    }
    
    T reduce(T (*func)(T, T))
    {
        T result = 0;
        this->ReduceFunc(this->GetRoot(), func, &result);
        return result;
    }
};
