#include <iostream>

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    struct Rectangle *r;
    r = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    (*r).length = 10;
    r->breadth = 20;

    std::cout << r << std::endl;

    Rectangle r2[] = {{10, 20}};
    for (const Rectangle &r : r2) // to avoid copying and modification
        std::cout << r.length << std::endl;

    return 0;
}
