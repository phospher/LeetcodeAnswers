#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int k = nums.size() - 1;
            int target = -nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                while (j < k && nums[j] + nums[k] > target)
                {
                    k--;
                }
                if (j == k)
                {
                    break;
                }
                if (nums[j] + nums[k] == target)
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution solution;
    vector<vector<int>> result = solution.threeSum(nums);
    if (result.size() == 0)
    {
        cout << "none";
    }
    else
    {
        for (vector<int> line : result)
        {
            for (int item : line)
            {
                cout << item << ",";
            }
            cout << endl;
        }
    }
}