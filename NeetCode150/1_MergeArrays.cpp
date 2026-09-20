#include <iostream>
#include <vector>

class Solution
{
public:
    // std::vector<int> getConcatenation(std::vector<int> &nums)
    // {
    //     std::vector<int> ans;
    //     int n = nums.size() * 2;
    //     int count = 0;
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (i == nums.size() && count < 2)
    //         {
    //             i = 0;
    //             count++;
    //         }
    //         if (count == 2)
    //         {
    //             break;
    //         }
    //         ans.push_back(nums[i]);
    //     }
    //     return ans;
    // }

    // Efficient solution
    std::vector<int> getConcatenation(std::vector<int> &nums)
    {
        std::vector<int> ans(nums.size() * 2);
        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = nums[i];
            ans[i + nums.size()] = nums[i];
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums = {1, 2};
    std::vector<int> result = solution.getConcatenation(nums);

    for (int num : result)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}