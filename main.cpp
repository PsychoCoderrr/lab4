#include "Complex.h"
#include <iostream>
#include "str_switch.h"
#include "func_for_print.h"
#include "helpers_for_mapReduce.h"
#include "tests.h"
#include "UiPrint.h"

int main(int argc, const char *argv[])
{
    TestTree();
    TestMapFunc();
    testWhereFunc();
    BinaryTree<complex> testComplex;
    BinaryTree<int> testInt;
    int a;
    complex b;
    int intReduceRes;
    complex ComplexReduceRes;
    int flag = 1;
    std::string command;
    StartUiPrint();
    while (flag)
    {
        std::cout<< "Enter your command" << std::endl;
        std::cin >> command;
        SWITCH(command)
        {
            CASE("IntElem"):
            {
                std::cout<<"Enter your element" << std::endl;
                std::cin >> a;
                testInt.setRoot(testInt.insert(testInt.GetRoot(), a));
                break;
            }
            CASE("ComplElem"):
            {
                std::cout<<"Enter your element" << std::endl;
                std::cin >> b;
                testComplex.setRoot(testComplex.insert(testComplex.GetRoot(), b));
                break;
            }
            CASE("IntKLP"):
            {
                PrintKLP(testInt.GetRoot());
                break;
            }
            CASE("IntKPL"):
            {
                PrintKPL(testInt.GetRoot());
                break;
            }
            CASE("IntLPK"):
            {
                PrintLPK(testInt.GetRoot());
                break;
            }
            CASE("IntPLK"):
            {
                PrintPLK(testInt.GetRoot());
                break;
            }
            CASE("IntLKP"):
            {
                PrintLKP(testInt.GetRoot());
                break;
            }
            CASE("IntPKL"):
            {
                PrintPKL(testInt.GetRoot());
                break;
            }
            CASE("ComplKLP"):
            {
                PrintKLP(testComplex.GetRoot());
                break;
            }
            CASE("ComplKPL"):
            {
                PrintKPL(testComplex.GetRoot());
                break;
            }
            CASE("ComplLPK"):
            {
                PrintLPK(testComplex.GetRoot());
                break;
            }
            CASE("ComplPLK"):
            {
                PrintPLK(testComplex.GetRoot());
                break;
            }
            CASE("ComplLKP"):
            {
                PrintLKP(testComplex.GetRoot());
                break;
            }
            CASE("ComplPKL"):
            {
                PrintPKL(testComplex.GetRoot());
                break;
            }
            CASE("IntFull"):
            {
                printTreeNew(testInt.GetRoot());
                break;
            }
            CASE("ComplFull"):
            {
                printTreeNew((testComplex.GetRoot()));
                break;
            }
            CASE("IntMap"):
            {
                testInt.map(&testMapFunc);
                break;
            }
            CASE("ComplMap"):
            {
                testComplex.map(&testMapFunc);
                break;
            }
            CASE("IntWhere"):
            {
                testInt.where(&testWhereFunc);
                break;
            }
            CASE("IntReduce"):
            {
                intReduceRes = testInt.reduce(&testReduceFunc);
                std::cout << intReduceRes << std::endl;
                break;
            }
            CASE("ComReduce"):
            {
                ComplexReduceRes = testComplex.reduceCompl(&testReduceFunc);
                std::cout << ComplexReduceRes << std::endl;
                break;
            }
            CASE("DelIntEl"):
            {
                std::cout<< "Enter element you want to delete";
                std::cin >> a;
                testInt.deleteElem(testInt.GetRoot(), a);
                break;
            }
            CASE("DelComplEl"):
            {
                std::cout<< "Enter element you want to delete";
                std::cin >> b;
                testComplex.deleteElem(testComplex.GetRoot(), b);
                break;
            }
            CASE("SubTreeInt"):
            {
                std::cout<< "Enter element you want to use as start";
                std::cin >> a;
                printSubTree(testInt, a);
            }
            CASE("SubTreeCom"):
            {
                std::cout<< "Enter element you want to use as start";
                std::cin >> b;
                printSubTree(testComplex, b);
            }
            CASE("Stop"):
            {
                flag = 0;
                break;
            }
            DEFAULT:
            {
                std::cout << "Unknown command" << std::endl;
            }
        }
        UiPrint();
    }
    
//    BinaryTree<int> testTree;
//        int elements[] = {5, 3, 8, 2, 4, 7, 9, 6};
//        for (int value : elements)
//        {
//            testTree.setRoot(testTree.insert(testTree.GetRoot(), value));
//        }
//
//        // Печать дерева
//    printTreeNew(testTree.GetRoot());

    return 0;
}
