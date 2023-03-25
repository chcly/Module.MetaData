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
        explicit ClassA(const int& x);
        explicit ClassA(const int* x);

        void doSomething();

        int x() const { return _x; }
    };

    struct Wrapper
    {
        unsigned int y;
    };

    extern Wrapper Foo(ClassA*& ref);
}  // namespace File1
