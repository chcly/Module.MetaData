int* LinkOrder(const float*& b)
{
    static int x;
    x = int(*b);
    return &x;
}
