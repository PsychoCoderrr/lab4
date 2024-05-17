#pragma once
#include "Tree.h"
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
