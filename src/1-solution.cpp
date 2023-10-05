#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;
        for (int begin = 0; begin < nums.size() - 1; begin++)
        {
            for (int end = begin + 1; end < nums.size(); end++)
            {
                if (nums[begin] + nums[end] == target)
                {
                    result.push_back(begin);
                    result.push_back(end);
                    return result;
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {2,
                        7,
                        11,
                        15};
    int target = 9;
    Solution solution;
    vector<int> result = solution.twoSum(nums, 9);
    for (int item : result)
    {
        cout << item << endl;
    }

    return 0;
}