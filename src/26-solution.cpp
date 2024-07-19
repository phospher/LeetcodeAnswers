#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() > 1)
        {
            int prevVal = nums[0];
            int currentIndex = 1;
            while (currentIndex < nums.size())
            {
                if (nums[currentIndex] == prevVal)
                {
                    nums.erase(nums.begin() + currentIndex);
                }
                else
                {
                    prevVal = nums[currentIndex];
                    currentIndex++;
                }
            }
        }
        return nums.size();
    }
};

int main()
{
    Solution soluction;
    vector<int> input = {1, 1, 2, 3, 4, 7, 9, 20, 20, 20, 25, 25};
    int result = soluction.removeDuplicates(input);
    cout << result << endl;
    for (int item : input)
    {
        cout << item << ",";
    }
    cout << endl;

    return 0;
}