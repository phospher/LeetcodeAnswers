#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        sort(nums.begin(), nums.end());
        int currentIndex = 0;
        while (currentIndex < nums.size() && nums[currentIndex] <= val)
        {
            if (nums[currentIndex] == val)
            {
                nums.erase(nums.begin() + currentIndex);
            }
            else
            {
                currentIndex++;
            }
        }
        return nums.size();
    }
};

int main()
{
    vector<int> input = {0, 1, 2, 2, 2, 3, 0, 4, 2};
    Solution solution;
    solution.removeElement(input, 2);
    for (int item : input)
    {
        cout << item << ",";
    }
    cout << endl;
    return 0;
}