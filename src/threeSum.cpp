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
        set<string> resultSet;
        map<int, vector<int>> *numsMap = initValueMap(nums);

        vector<int> *valueMapKeys = getAllKeyFromValueMap(numsMap);
        if (valueMapKeys->size() == 0)
        {
            return result;
        }

        if (valueMapKeys->size() == 1)
        {
            if ((*valueMapKeys)[0] == 0)
            {
                vector<int> target = {0, 0, 0};
                result.push_back(target);
            }
            return result;
        }

        for (int i = 0; i < nums.size() - 2; i++)
        {
            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                int num3Index = findNum3(numsMap, nums[i], nums[j], i, j);
                if (num3Index >= 0 && !isInResult(resultSet, nums[i], nums[j], nums[num3Index]))
                {
                    vector<int> target = {nums[i], nums[j], nums[num3Index]};
                    result.push_back(target);
                    addToResultSet(resultSet, nums[i], nums[j], nums[num3Index]);
                }
            }
        }

        return result;
    }

    string getKey(int num1, int num2, int num3)
    {
        vector<int> temp = {num1, num2, num3};
        sort(temp.begin(), temp.end());
        return to_string(temp[0]) + "_" + to_string(temp[1]) + "_" + to_string(temp[2]);
    }

    bool isInResult(set<string> &resultSet, int num1, int num2, int num3)
    {
        if (resultSet.size() == 0)
        {
            return false;
        }

        return resultSet.find(getKey(num1, num2, num3)) != resultSet.end();
    }

    void addToResultSet(set<string> &resultSet, int num1, int num2, int num3)
    {
        resultSet.insert(getKey(num1, num2, num3));
    }

    map<int, vector<int>> *initValueMap(vector<int> &nums)
    {
        map<int, vector<int>> *result = new map<int, vector<int>>();
        for (int i = 0; i < nums.size(); i++)
        {
            if (result->find(nums[i]) == result->end())
            {
                (*result)[nums[i]] = *(new vector<int>());
            }
            (*result)[nums[i]].push_back(i);
        }

        return result;
    }

    vector<int> *getAllKeyFromValueMap(map<int, vector<int>> *valueMap)
    {
        vector<int> *result = new vector<int>();
        for (map<int, vector<int>>::iterator it = valueMap->begin(); it != valueMap->end(); it++)
        {
            result->push_back(it->first);
        }
        return result;
    }

    int findNum3(map<int, vector<int>> *valueMap, int num1, int num2, int num1Index, int num2Index)
    {
        int num3 = 0 - num1 - num2;
        if (valueMap->find(num3) == valueMap->end())
        {
            return -1;
        }

        for (int item : (*valueMap)[num3])
        {
            if (item != num1Index && item != num2Index)
            {
                return item;
            }
        }

        return -1;
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