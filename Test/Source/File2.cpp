using CB = float* (*)();

int* LinkOrder(const CB &Callback)
{
    static int x;
    x = int(*Callback());
    return &x;
}
