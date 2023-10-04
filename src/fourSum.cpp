#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int a = 0; a < nums.size(); a++)
        {
            if (a > 0 && nums[a] == nums[a - 1])
            {
                continue;
            }

            for (int b = a + 1; b < nums.size(); b++)
            {
                if (b > a + 1 && nums[b] == nums[b - 1])
                {
                    continue;
                }

                for (int c = b + 1; c < nums.size(); c++)
                {
                    if (c > b + 1 && nums[c] == nums[c - 1])
                    {
                        continue;
                    }

                    int d = nums.size() - 1;
                    long temp = (long)nums[a] + (long)nums[b] + (long)nums[c];
                    while (d > c && temp > target - nums[d])
                    {
                        d--;
                    }
                    if (c == d)
                    {
                        break;
                    }
                    if (temp == target - nums[d])
                    {
                        result.push_back({nums[a], nums[b], nums[c], nums[d]});
                    }
                }
            }
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {1000000000, 1000000000, 1000000000, 1000000000};
    int target = 0;
    Solution solution;
    vector<vector<int>> result = solution.fourSum(nums, target);
    for (vector<int> row : result)
    {
        for (int item : row)
        {
            cout << item << ",";
        }
        cout << endl;
    }

    return 0;
}