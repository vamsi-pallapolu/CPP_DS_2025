#include <iostream>
#include <vector>

bool check(std::vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        
    }
}

int main()
{

    // std::vector<int> nums = {3, 4, 5, 1, 2};
    std::vector<int> nums = {1, 2 , 3, 4, 5};
    bool result = check(nums);
    std::cout << "result:" << result << std::endl;
    return 0;
}