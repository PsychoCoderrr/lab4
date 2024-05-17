#include "Complex.h"
#include <iostream>
#include "str_switch.h"
#include "func_for_print.h"



template <typename T>
T testMapFunc(T i)
{
    return i * i;
}

bool testWhereFunc(int i)
{
    if (i%2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
T testReduceFunc(T a, T b)
{
    return a+b;
}

int main(int argc, const char *argv[])
{
//    BinaryTree<complex> testComplex;
//    BinaryTree<int> testInt;
//    int a;
//    complex b;
//    int countInt = 0;
//    int countCompl = 0;
//    int flag = 1;
//    std::string command;
//    while (flag)
//    {
//        std::cout<< "Enter your command";
//        std::getline(std::cin, command);
//        SWITCH(command)
//        {
//            CASE("IntElem"):
//            {
//                std::cout<<"Enter your element" << std::endl;
//                std::cin >> a;
//                testInt.insert(testInt.GetRoot(), a);
//                countInt += 1;
//            }
//            CASE("ComplElem"):
//            {
//                std::cout<<"Enter your element" << std::endl;
//                std::cin >> b;
//                testComplex.insert(testComplex.GetRoot(), b);
//                countCompl += 1;
//            }
//            CASE("IntKLP"):
//            {
//                PrintKLP(testInt.GetRoot());
//            }
//            CASE("IntKPL"):
//            {
//                PrintKPL(testInt.GetRoot());
//            }
//            CASE("IntLPK"):
//            {
//                PrintLPK(testInt.GetRoot());
//            }
//            CASE("IntPLK"):
//            {
//                PrintPLK(testInt.GetRoot());
//            }
//            CASE("IntLKP"):
//            {
//                PrintLKP(testInt.GetRoot());
//            }
//            CASE("IntPKL"):
//            {
//                PrintPKL(testInt.GetRoot());
//            }
//            CASE("ComplKLP"):
//            {
//                PrintKLP(testComplex.GetRoot());
//            }
//            CASE("ComplKPL"):
//            {
//                PrintKPL(testComplex.GetRoot());
//            }
//            CASE("ComplLPK"):
//            {
//                PrintLPK(testComplex.GetRoot());
//            }
//            CASE("ComplPLK"):
//            {
//                PrintPLK(testComplex.GetRoot());
//            }
//            CASE("ComplLKP"):
//            {
//                PrintLKP(testComplex.GetRoot());
//            }
//            CASE("ComplPKL"):
//            {
//                PrintPKL(testComplex.GetRoot());
//            }
//            CASE("IntFull"):
//            {
//                printTree((testInt.GetRoot()), 0, 5);
//            }
//            CASE("ComplFull"):
//            {
//                printTree((testComplex.GetRoot()), 0, 7);
//            }
//            CASE("IntMap"):
//            {
//                testInt.map(&testMapFunc);
//            }
//            CASE("ComplMap"):
//            {
//                testComplex.map(&testMapFunc);
//            }
//            CASE("DelIntEl"):
//            {
//                std::cout<< "Enter element you want to delete";
//                std::cin >> a;
//                testInt.deleteElem(testInt.GetRoot(), a);
//            }
//            CASE("DelComplEl"):
//            {
//                std::cout<< "Enter element you want to delete";
//                std::cin >> b;
//                testComplex.deleteElem(testComplex.GetRoot(), b);
//            }
//        }
//    }
    int a[] = {50, 45, 55, 40, 35, 44, 54, 56};
    BinaryTree<int> testTree;
    for (int i = 0; i < 8; i++)
    {
        testTree.setRoot(testTree.insert(testTree.GetRoot(), a[i]));
    }
    printTree(testTree.GetRoot(), 0, 5);
//    testTree.where(&testWhereFunc);
    printTree(testTree.GetRoot(), 0, 5);
    int result = testTree.reduce(&testReduceFunc);
    std::cout << result;
    return 0;
}
