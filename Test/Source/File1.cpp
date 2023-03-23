#include "File1.h"

namespace File1
{
    ClassA::ClassA(const int& x) :
        _x(x)
    {
    }

    void ClassA::doSomething()
    {
        _x = 2 * (_x - 1);
    }

}  // namespace File1
