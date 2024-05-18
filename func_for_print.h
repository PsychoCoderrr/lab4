#pragma once
#include "Tree.h"

static std::string ch_hor = "-", ch_ver = "|", ch_ddia = "/", ch_rddia = "\\", ch_udia = "\\", ch_ver_hor = "|-", ch_udia_hor = "\\-", ch_ddia_hor = "/-", ch_ver_spa = "| ";

template <typename T>
void printTree(Node<T> *node, int space, int height) // все функции, которые используют cout вынесены вне класса, как отдельные функции
{
    if (node == nullptr)
    {
        return;
    }
    space += height;
    printTree(node->GetRight(), space, height);
    std::cout << std::endl;
    for (int i = height; i < space; ++i)
    {
        std::cout << " ";
    }
    std::cout << node->Get() << "\n";

    printTree(node->GetLeft(), space, height);
}

template <typename T>
void printTreeNew(Node<T>* node, const std::string& rpref = "", const std::string& cpref = "", const std::string& lpref = "") {
    if (!node) return;

    if (node->GetRight())
        printTreeNew(node->GetRight(), rpref + "  ", rpref + ch_ddia_hor, rpref + ch_ver_spa);

    std::cout << cpref << std::to_string(node->Get()) << std::endl;

    if (node->GetLeft())
        printTreeNew(node->GetLeft(), lpref + ch_ver_spa, lpref + ch_udia_hor, lpref + "  ");
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

template <typename T>
void printSubTree(BinaryTree<T>& mainTree, T item)
{
    Node<T>* intermediate = mainTree.search(mainTree.GetRoot(), item);
    if (intermediate == nullptr)
    {
        std::cout << "No searching element in tree" << std::endl;
    }
    else
    {
        printTree(intermediate, 0, 5);
    }
}
