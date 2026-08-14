/*

Remove duplicate elements in a sorted array

*/

#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int> &nums)
{

    std::vector<int> result;
    int k = 0;
    result.push_back(nums.at(0));
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == result[k])
            continue;
        else
        {
            result.push_back(nums[i]);
            k++;
        }
    }
    nums = result;
    return result.size();
}

int main()
{
    std::vector<int> nums = {0, 0, 3, 3, 5, 6};
    int uniqueElementsCount = removeDuplicates(nums);
    for (int num : nums)
        std::cout << num << " ";

    return 0;
}