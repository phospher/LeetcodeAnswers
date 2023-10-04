#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    int minus = INT32_MAX;

    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());

        int result;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                if (nums[i] + nums[j] <= target)
                {
                    int k;
                    for (k = j + 1; k < nums.size(); k++)
                    {
                        int tmp = target - nums[i] - nums[j] - nums[k];
                        if (tmp <= 0)
                        {
                            if (tmp == 0)
                            {
                                return nums[i] + nums[j] + nums[k];
                            }
                            else
                            {
                                if (k > j + 1)
                                {
                                    result = check(nums[i], nums[j], nums[k - 1], target, result);
                                }
                                result = check(nums[i], nums[j], nums[k], target, result);
                            }
                            break;
                        }
                    }
                    if (k == nums.size())
                    {
                        result = check(nums[i], nums[j], nums[k - 1], target, result);
                    }
                }
                else
                {
                    int k;
                    for (k = nums.size() - 1; k > j; k--)
                    {
                        int tmp = target - nums[i] - nums[j] - nums[k];
                        if (tmp >= 0)
                        {
                            if (tmp == 0)
                            {
                                return nums[i] + nums[j] + nums[k];
                            }
                            else
                            {
                                if (k < nums.size() - 1)
                                {
                                    result = check(nums[i], nums[j], nums[k + 1], target, result);
                                }
                                result = check(nums[i], nums[j], nums[k], target, result);
                            }
                            break;
                        }
                    }
                    if (k == j)
                    {
                        result = check(nums[i], nums[j], nums[k + 1], target, result);
                    }
                }
            }
        }
        return result;
    }

    int check(int num1, int num2, int num3, int target, int result)
    {
        int minus1 = abs(target - num1 - num2 - num3);
        if (minus1 < minus)
        {
            minus = minus1;
            return num1 + num2 + num3;
        }
        else
        {
            return result;
        }
    }
};

int main()
{
    vector<int> nums = {4, 0, 5, -5, 3, 3, 0, -4, -5};
    int target = -2;
    Solution solution;
    cout << solution.threeSumClosest(nums, target) << endl;
}