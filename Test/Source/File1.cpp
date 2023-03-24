#include "File1.h"

namespace File1
{
    ClassA::ClassA(const int& x) :
        _x(x)
    {
    }

    ClassA::ClassA(const int* x) :
        _x(x ? *x : 0)
    {
    }

    void ClassA::doSomething()
    {
        _x = 2 * (_x - 1);
    }

}  // namespace File1
