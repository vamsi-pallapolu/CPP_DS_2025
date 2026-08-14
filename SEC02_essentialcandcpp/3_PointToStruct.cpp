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

    free(r);

    Rectangle r2[] = {{10, 20}};  // in cpp struct is not required
    for (const Rectangle &r : r2) // to avoid copying and modification
        std::cout << r.length << std::endl;


    Rectangle r3 = {10, 20};
    Rectangle *p = &r3;
    std::cout << p->length << std::endl;
    std::cout << p->breadth << std::endl;

    return 0;
}
