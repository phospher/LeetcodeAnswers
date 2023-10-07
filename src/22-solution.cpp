#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    void process(vector<string> &ans, string cur, int open, int close, int n)
    {
        if (cur.size() == n * 2)
        {
            ans.push_back(cur);
            return;
        }
        if (open < n)
        {
            process(ans, cur + "(", open + 1, close, n);
        }
        if (close < open)
        {
            process(ans, cur + ")", open, close + 1, n);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string current;
        process(result, current, 0, 0, n);
        return result;
    }
};

int main()
{
    int n = 3;
    Solution solution;
    vector<string> result = solution.generateParenthesis(n);
    for (string item : result)
    {
        cout << item << endl;
    }
    return 0;
}