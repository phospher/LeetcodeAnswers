#include <iostream>

using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == 0 || (dividend > INT32_MIN && divisor == INT32_MIN))
        {
            return 0;
        }
        if (dividend == divisor)
        {
            return 1;
        }

        bool isResultPositive = (dividend > 0) == (divisor > 0);

        int dividendAbs = dividend > 0 ? -dividend : dividend;
        int divisorAbs = divisor > 0 ? -divisor : divisor;

        if (dividendAbs > divisorAbs)
        {
            return 0;
        }

        int result;
        if (divisorAbs == -1)
        {
            result = dividendAbs;
        }
        else
        {
            result = div(dividendAbs, divisorAbs);
        }

        if (result == INT32_MIN)
        {
            return isResultPositive ? INT32_MAX : INT32_MIN;
        }

        if (isResultPositive)
        {
            return -result > INT32_MAX ? INT32_MAX : -result;
        }
        else
        {
            return result < INT32_MIN ? INT32_MIN : result;
        }
    }

    int div(int dividendAbs, int divisorAbs)
    {
        if (dividendAbs > divisorAbs)
        {
            return 0;
        }
        int result = -1;
        int temp = divisorAbs;
        while (temp >= INT32_MIN - temp && temp + temp >= dividendAbs)
        {
            result += result;
            temp += temp;
        }
        return result + div(dividendAbs - temp, divisorAbs);
    }
};

int main()
{
    Solution solution;
    cout << solution.divide(10, 3) << endl;
    cout << solution.divide(7, -3) << endl;
    cout << solution.divide(-7, -3) << endl;
    cout << solution.divide(3, 7) << endl;
    cout << solution.divide(-3, -7) << endl;
    cout << solution.divide(12, 3) << endl;
    cout << solution.divide(-12, 3) << endl;
    cout << solution.divide(12, -3) << endl;
    cout << solution.divide(-12, -3) << endl;
    cout << solution.divide(INT32_MAX, 1) << endl;
    cout << solution.divide(INT32_MAX, -1) << endl;
    cout << solution.divide(INT32_MIN, 1) << endl;
    cout << solution.divide(INT32_MIN, -1) << endl;
    cout << solution.divide(INT32_MAX, 2) << endl;
    cout << solution.divide(INT32_MAX, -2) << endl;
    cout << solution.divide(INT32_MIN, 2) << endl;
    cout << solution.divide(INT32_MIN, -2) << endl;
    cout << solution.divide(INT32_MAX, 3) << endl;
    cout << solution.divide(INT32_MIN, -3) << endl;
    cout << solution.divide(INT32_MAX, -3) << endl;
    cout << solution.divide(INT32_MIN, 3) << endl;
    cout << solution.divide(1100540749, -1090366779) << endl;
    return 0;
}