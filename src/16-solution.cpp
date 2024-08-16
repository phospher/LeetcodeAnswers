#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdint>

using namespace std;

class Solution
{
public:
    int result = INT16_MAX;

    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                {
                    return sum;
                }

                check(sum, target);
                if (sum > target)
                {
                    int tempK = k - 1;
                    while (j < tempK && nums[k] == nums[tempK])
                    {
                        tempK--;
                    }
                    k = tempK;
                }
                else
                {
                    int tempJ = j + 1;
                    while (tempJ < k && nums[j] == nums[tempJ])
                    {
                        tempJ++;
                    }
                    j = tempJ;
                }
            }
        }
        return result;
    }

    void check(int current, int target)
    {
        if (abs(current - target) < abs(result - target))
        {
            result = current;
        }
    }
};

int main()
{
    vector<int> nums = {4, 0, 5, -5, 3, 3, 0, -4, -5};
    int target = -2;
    Solution solution;
    cout << solution.threeSumClosest(nums, target) << endl;

    return 0;
}