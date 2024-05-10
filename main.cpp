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
};

template <typename T> class BinaryTree
{
  private:
    int size;
    Node<T> root;

  public:
    BinaryTree<T>()
    {
        root = nullptr;
        size = 0;
    }

    ~BinaryTree<T>()
    {
        deleteTree(this->GetRoot());
        delete this;
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
};

int main(int argc, const char *argv[])
{

    return 0;
}
