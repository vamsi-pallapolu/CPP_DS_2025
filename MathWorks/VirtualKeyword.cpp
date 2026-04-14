/*

    Without virtual Keyword example

*/

#include <iostream>
class Base
{

public:
    // void show()
    // {
    //     std::cout << "Class Base" << std::endl;
    // }

    // virtual keyword enables runtime polymorphism -> decision happens at runtime based on the object
    virtual void show()
    {
        std::cout << "Base show" << std::endl;
    }

    virtual ~Base()
    {
        std::cout << "Base destructor" << std::endl;
    }
};

class Derived : public Base
{
public:
    void show() override
    {
        std::cout << "Derived show" << std::endl;
    }

    ~Derived()
    {
        std::cout << "Derived destructor" << std::endl;
    }
};

int main()
{
    Base *b = new Derived();
    b->show();

    // without virtual destructor - only base  destructor will be called
    delete b;
    return 0;
}