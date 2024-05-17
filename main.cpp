#include "Complex.h"
#include <iostream>
#include "str_switch.h"
#include "func_for_print.h"
#include "helpers_for_mapReduce.h"



int main(int argc, const char *argv[])
{
    BinaryTree<complex> testComplex;
    BinaryTree<int> testInt;
    int a;
    complex b;
    int intReduceRes;
    complex ComplexReduceRes;
    int countInt = 0;
    int countCompl = 0;
    int flag = 1;
    std::string command;
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
                countInt += 1;
                break;
            }
            CASE("ComplElem"):
            {
                std::cout<<"Enter your element" << std::endl;
                std::cin >> b;
                testComplex.setRoot(testComplex.insert(testComplex.GetRoot(), b));
                countCompl += 1;
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
                printTree(testInt.GetRoot(), 2, 5);
                break;
            }
            CASE("ComplFull"):
            {
                printTree((testComplex.GetRoot()), 0, 7);
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
                countInt -= 1;
                break;
            }
            CASE("DelComplEl"):
            {
                std::cout<< "Enter element you want to delete";
                std::cin >> b;
                testComplex.deleteElem(testComplex.GetRoot(), b);
                countCompl -= 1;
                break;
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
    }
    return 0;
}
