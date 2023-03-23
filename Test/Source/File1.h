#pragma once

namespace File1
{
    class ClassA
    {
    private:
        int _x{0};

    public:
        ClassA()  = default;
        ~ClassA() = default;

        ClassA(const ClassA& rhs) = default;
        ClassA(const int& x);

        void doSomething();

        int x() const { return _x; }
    };

}  // namespace File1
