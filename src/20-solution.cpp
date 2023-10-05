#include <iostream>
#include <stack>
#include <map>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stack;
        bool result = false;
        for (char item : s)
        {
            switch (item)
            {
            case '(':
            case '[':
            case '{':
                pushToStack(stack, item);
                break;
            case ')':
            case ']':
            case '}':
                result = valid(stack, item);
                if (!result)
                {
                    return result;
                }
            }
        }
        return stack.empty();
    }

    void pushToStack(stack<char> &stack, char val)
    {
        stack.push(val);
    }

    bool valid(stack<char> &stack, char checkVal)
    {
        map<char, char> valMap = {
            {')', '('},
            {']', '['},
            {'}', '{'}};

        if (stack.empty())
        {
            return false;
        }

        char val = stack.top();
        if (val == valMap[checkVal])
        {
            stack.pop();
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    string s = "(]{}";
    Solution solution;
    string result = solution.isValid(s) ? "true" : "false";
    cout << result << endl;
    return 0;
}