#include <iostream>

using namespace std;

class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        int firstIndex = -1;
        int swapPerformed = 0;
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
            {
                if (firstIndex == -1)
                {
                    firstIndex = i;
                }
                else if (swapPerformed == 0)
                {
                    char temp = s1[i];
                    s1[i] = s1[firstIndex];
                    s1[firstIndex] = temp;
                    swapPerformed++;
                }
                else
                {
                    return false;
                }
            }
        }
        return s1 == s1;
    }
};

int main()
{
    Solution sol = Solution();
    cout << sol.areAlmostEqual("bank", "kanb") << endl;
    cout << sol.areAlmostEqual("attack", "defend") << endl;
    cout << sol.areAlmostEqual("kelb", "kelb") << endl;
    return 0;
}
