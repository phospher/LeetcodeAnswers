#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {

        vector<string> result;

        if (digits.length() == 0)
        {
            return result;
        }

        map<char, vector<string>> mapping = {
            {'2', {"a", "b", "c"}},
            {'3', {"d", "e", "f"}},
            {'4', {"g", "h", "i"}},
            {'5', {"j", "k", "l"}},
            {'6', {"m", "n", "o"}},
            {'7', {"p", "q", "r", "s"}},
            {'8', {"t", "u", "v"}},
            {'9', {"w", "x", "y", "z"}}};

        process(digits, 0, mapping, result, "");
        return result;
    }

    void process(string digits, int index, map<char, vector<string>> mapping, vector<string> &result, string temp)
    {
        for (string item : mapping[digits[index]])
        {
            string tempNew = temp + item;
            if (index < digits.length() - 1)
            {
                process(digits, index + 1, mapping, result, tempNew);
            }
            else
            {
                result.push_back(tempNew);
            }
        }
    }
};

int main()
{
    string digits = "23";
    Solution solution;
    vector<string> result = solution.letterCombinations(digits);
    for (string item : result)
    {
        cout << item << endl;
    }

    return 0;
}
