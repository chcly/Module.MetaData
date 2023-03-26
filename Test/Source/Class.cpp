namespace Module
{
    class Class1
    {
    private:
        int _field1{0};
        int _field2{0};

    public:
        Class1() = default;

        void setField1(const int& value)
        {
            _field1 = value;
        }

        int getField1() const
        {
            return _field1;
        }

        void doSomeWork()
        {
            _field2 += 2 * (_field1 - 1);
        }
    };

}  // namespace Module
