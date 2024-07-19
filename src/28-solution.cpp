#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.length() > haystack.length())
        {
            return -1;
        }

        int hIndex = 0;
        while (haystack[hIndex] != needle[0] && hIndex < haystack.length())
        {
            hIndex++;
        }
        while (needle.length() <= haystack.length() - hIndex)
        {
            bool isFindBegin = false;
            int matchBeginIndex = -1;
            int matchIndex = hIndex;
            for (int nIndex = 0; nIndex < needle.length(); nIndex++)
            {
                if (!isFindBegin && matchIndex > hIndex && haystack[matchIndex] == needle[0])
                {
                    isFindBegin = true;
                    matchBeginIndex = matchIndex;
                }
                if (haystack[matchIndex] == needle[nIndex])
                {
                    matchIndex++;
                }
                else
                {
                    break;
                }
            }
            if (matchIndex - hIndex == needle.size() && haystack[matchIndex - 1] == needle[needle.length() - 1])
            {
                return hIndex;
            }
            else
            {
                if (isFindBegin)
                {
                    hIndex = matchBeginIndex;
                }
                else
                {
                    hIndex++;
                    while (haystack[hIndex] != needle[0] && hIndex < haystack.length())
                    {
                        hIndex++;
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{
    Solution solution;
    cout << solution.strStr("sadbusad", "sad") << endl;
    return 0;
}