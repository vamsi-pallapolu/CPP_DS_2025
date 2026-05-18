#include <iostream>
#include <vector>

int main()
{

    std::vector<int> a1 = {1, 2, 3};
    std::vector<int> a2 = {1, 2, 5};

    int i = 0, j = 0;

    std::vector<int> sortedNumbers;

    while (i < a1.size() && j < a2.size())
    {
        if (a1[i] <= a2[j])
        {
            sortedNumbers.push_back(a1[i++]);
        }
        else
        {
            sortedNumbers.push_back(a2[j++]);
        }
    }

    // Add remaining elements from a1
    while (i < a1.size())
    {
        sortedNumbers.push_back(a1[i++]);
    }

    // Add remaining elements from a2
    while (j < a2.size())
    {
        sortedNumbers.push_back(a2[j++]);
    }

    a1 = sortedNumbers;

    for (int number : a1)
        std::cout << number << std::endl;
    return 0;
}