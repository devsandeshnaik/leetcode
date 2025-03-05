#include <iostream>
#include <vector>

using namespace std;

/*
Given an integer n, return true if it is possible to represent n as the sum of distinct
powers of three. Otherwise, return false.

An integer y is a power of three if there exists an integer x such that y == 3x.
*/

bool checkPowersOfThree(int n)
{
    int power = 0;
    vector<int> vec;

    while (pow(3, power) <= n)
    {
        int res = pow(3, power);
        if (res == n)
        {
            return true;
            break;
        }
        if (res < n / 2)
        {
            vec.push_back(res);
        }
        else
        {
            for (int i = vec.size() - 1; i >= 0; i--)
            {

                if (res + vec.at(i) < n)
                {
                    res += vec.at(i);
                }
                else if (res + vec.at(i) == n)
                {
                    return true;
                    break;
                }
            }
        }
        power++;
    }
    return false;
}

int main()
{
    int ip1 = 27;
    int ip2 = 91;
    int ip3 = 21;

    cout << checkPowersOfThree(ip1) << endl;
    cout << checkPowersOfThree(ip2) << endl;
    cout << checkPowersOfThree(ip3) << endl;

    return 0;
}