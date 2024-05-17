#pragma once

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
