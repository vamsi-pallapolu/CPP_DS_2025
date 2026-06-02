#include <iostream>

void fibonacci(int n)
{
    if (n > 0)
    {
        int first = 0;
        int second = 1;
        int current;
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
            {
                std::cout << first << " ";
                continue;
            }
            if (i == 2)
            {
                std::cout << second << " ";
                continue;
            }
            current = second + first;
            std::cout << current << " ";
            first = second;
            second = current;
        }
    }
    else
    {
        std::cout << "Enter input > 0" << std::endl;
    }
}

int main()
{
    int input;
    std::cout << "Enter no of series>";
    std::cin >> input;
    fibonacci(input);
    return 0;
}