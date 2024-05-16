#include "Complex.h"
#include <iostream>

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
            startRoot->SetData(minimum(startRoot->GetRight())->Get());
            startRoot->setRight(deleteElem(startRoot->GetRight(), value));
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

    void map(T (*func)(T))
    {
        this->FuncMap(this->GetRoot(), func);
    }
};

template <typename T>
void printTree(Node<T> *node, int space,
               int height) // все функции, которые используют cout вынесены вне класса, как отдельные функции

{
    if (node == nullptr)
    {
        return;
    }
    space += height;
    printTree(node->GetRight(), space, height);
    std::cout << std::endl;
    for (int i = height; i < space; ++i)
        std::cout << " ";
    std::cout << node->Get() << "\n";

    printTree(node->GetLeft(), space, height);
}

template <typename T> void PrintKLP(Node<T> *elem) // обход КЛП или другими словами префиксный
{
    if (elem == nullptr)
    {
        return;
    }
    std::cout << "(" << elem->Get() << ") ";
    PrintKLP(elem->GetLeft());
    PrintKLP(elem->GetRight());
}

template <typename T> void PrintKPL(Node<T> *elem) // обход КПЛ
{
    if (elem == nullptr)
    {
        return;
    }
    std::cout << "(" << elem->Get() << ") ";
    PrintPKL(elem->GetRight());
    PrintPKL(elem->GetLeft());
}

template <typename T> void PrintLPK(Node<T> *elem) // обход ЛПК или постфиксный обход
{
    if (elem == nullptr)
    {
        return;
    }
    PrintLPK(elem->GetLeft());
    PrintLPK(elem->GetRight());
    std::cout << "(" << elem->Get() << ") ";
}

template <typename T> void PrintPLK(Node<T> *elem) // обход ПЛК
{
    if (elem == nullptr)
    {
        return;
    }
    PrintPLK(elem->GetRight());
    PrintPLK(elem->GetLeft());
    std::cout << "(" << elem->Get() << ") ";
}

template <typename T> void PrintLKP(Node<T> *elem) // обход ЛКП  или инфиксный обход
{
    if (elem == nullptr)
    {
        return;
    }
    PrintLKP(elem->GetLeft());
    std::cout << "(" << elem->Get() << ") ";
    PrintLKP(elem->GetRight());
}

template <typename T> void PrintPKL(Node<T> *elem) // обход ПКЛ
{
    if (elem == nullptr)
    {
        return;
    }
    PrintPKL(elem->GetRight());
    std::cout << "(" << elem->Get() << ") ";
    PrintPKL(elem->GetLeft());
}

int testMapFunc(int i)
{
    return i * i;
}

int main(int argc, const char *argv[])
{
    int a[] = {50, 45, 55, 40, 35, 44, 54, 56};
    BinaryTree<int> testTree;
    for (int i = 0; i < 8; i++)
    {
        testTree.setRoot(testTree.insert(testTree.GetRoot(), a[i]));
    }
    //    int b = (testTree.search(testTree.GetRoot(), 7))->Get();
    //    std::cout << b << std::endl;
    PrintPKL(testTree.GetRoot());
    std::cout << std::endl;
    //    testTree.setRoot(testTree.deleteElem(testTree.GetRoot(), 7));
    //    testTree.PrintPKL(testTree.GetRoot());
    //    std::cout << std::endl;
    //    testTree.map(&testMapFunc);
    //    testTree.PrintPKL(testTree.GetRoot());
    std::cout << std::endl;
    printTree(testTree.GetRoot(), 0, 5);
    return 0;
}
