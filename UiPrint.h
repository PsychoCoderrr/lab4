#pragma once
#include <iostream>
void StartUiPrint()
{
    std::cout << "Hello, user"<< std::endl;
    std::cout << "You alredy have two created trees: Int and Complex"<< std::endl;
    std::cout << "IntElem or ComplElem - comands to insert elements \nin int tree or in complex tree"<< std::endl;
    std::cout << "<Type><Name of travers for example KPL> - command \nto go traverses for this trees" << std::endl;
    std::cout << "DelIntEl and DelComplEl - commnds to delete elems" << std::endl;
    std::cout << "<Type><Name of func> - commands to use map and \nreduce for int and compl" << std::endl;
    std::cout << "IntWhere - command to use where for int" << std::endl;
    std::cout << "<Type>Full - command to print tree as tree" << std::endl;
    std::cout << "SubTreeInt and SubTreeCom - commands to print a \nSubTree after enetring an element you want to \nbe a root of SubTree" << std::endl;
}

void UiPrint()
{
    std::cout << "IntElem or ComplElem - comands to insert elements \nin int tree or in complex tree"<< std::endl;
    std::cout << "<Type><Name of travers for example KPL> - command \nto go traverses for this trees" << std::endl;
    std::cout << "DelIntEl and DelComplEl - commnds to delete elems" << std::endl;
    std::cout << "<Type><Name of func> - commands to use map and \nreduce for int and compl" << std::endl;
    std::cout << "IntWhere - command to use where for int" << std::endl;
    std::cout << "<Type>Full - command to print tree as tree" << std::endl;
    std::cout << "SubTreeInt and SubTreeCom - commands to print a \nSubTree after enetring an element you want to \nbe a root of SubTree" << std::endl;
}
