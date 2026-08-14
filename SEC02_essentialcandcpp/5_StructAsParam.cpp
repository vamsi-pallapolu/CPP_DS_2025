#include <iostream>

/*
    Passing structure as a Paramter
*/

struct Rectangle
{
    int length;
    int breadth;
};

struct Rect
{
    int A[3] = {1, 2, 3};
};

void print(struct Rect r)
{
    for (int i = 0; i < 3; i++)
    {
        // std::cout << r.A[i] << std::endl;
        std::cout << *(r.A + i) << std::endl;
    }
}

// Pass by reference
void area(struct Rectangle &r)
{
    r.length = 20;
    std::cout << r.length * r.breadth << std::endl;
}

// Pass by value
// void area(struct Rectangle r)
// {
//     std::cout << r.length * r.breadth << std::endl;
// }

int main()
{
    struct Rectangle r = {10, 20};
    area(r);
    std::cout << r.length << std::endl;
    Rect r1;
    print(r1);
    return 0;
}