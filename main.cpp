#include <iostream>
#include"Complex.h"

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

    void PrintKLP(Node<T> *elem) // обход КЛП или другими словами префиксный
    {
        if (elem == nullptr)
        {
            return;
        }
        std::cout << "(" << elem->Get() << ") ";
        PrintKLP(elem->GetLeft());
        PrintKLP(elem->GetRight());
    }

    void PrintKPL(Node<T> *elem) // обход КПЛ
    {
        if (elem == nullptr)
        {
            return;
        }
        std::cout << "(" << elem->Get() << ") ";
        PrintPKL(elem->GetRight());
        PrintPKL(elem->GetLeft());
    }

    void PrintLPK(Node<T> *elem) // обход ЛПК или постфиксный обход
    {
        if (elem == nullptr)
        {
            return;
        }
        PrintLPK(elem->GetLeft());
        PrintLPK(elem->GetRight());
        std::cout << "(" << elem->Get() << ") ";
    }

    void PrintPLK(Node<T> *elem) // обход ПЛК
    {
        if (elem == nullptr)
        {
            return;
        }
        PrintPLK(elem->GetRight());
        PrintPLK(elem->GetLeft());
        std::cout << "(" << elem->Get() << ") ";
    }

    Node<T> *minimum(Node<T> *startRoot)
    {
        if (startRoot->GetLeft() == nullptr)
        {
            return startRoot;
        }
        return minimum(startRoot->GetLeft());
    }

    Node<T> *maximum(Node<T> *startRoot)
    {
        if (startRoot->GetRight() == nullptr)
        {
            return startRoot;
        }
        return minimum(startRoot->GetRight());
    }

    void PrintLKP(Node<T> *elem) // обход ЛКП  или инфиксный обход
    {
        if (elem == nullptr)
        {
            return;
        }
        PrintLKP(elem->GetLeft());
        std::cout << "(" << elem->Get() << ") ";
        PrintLKP(elem->GetRight());
    }

    void PrintPKL(Node<T> *elem) // обход ПКЛ
    {
        if (elem == nullptr)
        {
            return;
        }
        PrintPKL(elem->GetRight());
        std::cout << "(" << elem->Get() << ") ";
        PrintPKL(elem->GetLeft());
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
};

int main(int argc, const char *argv[])
{
    int a[] = {5, 4, 6, 7, 3, 8};
    BinaryTree<int> testTree;
    for (int i = 0; i < 6; i++)
    {
        testTree.setRoot(testTree.insert(testTree.GetRoot(), a[i]));
    }
    int b = (testTree.search(testTree.GetRoot(), 7))->Get();
    std::cout << b << std::endl;
    testTree.PrintPKL(testTree.GetRoot());
    std::cout << std::endl;
    testTree.setRoot(testTree.deleteElem(testTree.GetRoot(), 7));
    testTree.PrintPKL(testTree.GetRoot());
    std::cout << std::endl;
    return 0;
}
