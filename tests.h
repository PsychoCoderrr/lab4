#pragma once
#include "Tree.h"
#include <assert.h>
void TestTree()
{
    BinaryTree<int> testInt;
    int a[] = {6, 3, 9, 7, 10, 4};
    for (int i = 0; i < 6; i++)
    {
        testInt.setRoot(testInt.insert(testInt.GetRoot(), a[i]));
    }
    assert(testInt.GetSize() == 6);
    assert(testInt.search(testInt.GetRoot(), 6) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 3) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 9) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 7) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 10) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 4) != nullptr);
}

void TestMapFunc()
{
    int a[] = {6, 3, 9, 7, 10, 4};
    BinaryTree<int> testInt;
    for (int i = 0; i < 6; i++)
    {
        testInt.setRoot(testInt.insert(testInt.GetRoot(), a[i]));
    }
    assert(testInt.GetSize() == 6);
    assert(testInt.search(testInt.GetRoot(), 6) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 3) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 9) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 7) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 10) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 4) != nullptr);
    testInt.map(&testMapFunc);
    assert(testInt.search(testInt.GetRoot(), 36) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 9) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 81) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 49) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 100) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 16) != nullptr);
}

void testWhereFunc()
{
    int a[] = {6, 3, 9, 7, 10, 4};
    BinaryTree<int> testInt;
    for (int i = 0; i < 6; i++)
    {
        testInt.setRoot(testInt.insert(testInt.GetRoot(), a[i]));
    }
    assert(testInt.GetSize() == 6);
    assert(testInt.search(testInt.GetRoot(), 6) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 3) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 9) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 7) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 10) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 4) != nullptr);
    testInt.where(&testWhereFunc);
    assert(testInt.GetSize() == 3);
    assert(testInt.search(testInt.GetRoot(), 6) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 10) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 4) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 3) == nullptr);
    assert(testInt.search(testInt.GetRoot(), 9) == nullptr);
    assert(testInt.search(testInt.GetRoot(), 7) == nullptr);
}

void testReduceFunc()
{
    int a[] = {6, 3, 9, 7, 10, 4};
    BinaryTree<int> testInt;
    for (int i = 0; i < 6; i++)
    {
        testInt.setRoot(testInt.insert(testInt.GetRoot(), a[i]));
    }
    assert(testInt.GetSize() == 6);
    assert(testInt.search(testInt.GetRoot(), 6) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 3) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 9) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 7) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 10) != nullptr);
    assert(testInt.search(testInt.GetRoot(), 4) != nullptr);
    int result = testInt.reduce(&testReduceFunc);
    assert(result == 39);
}
