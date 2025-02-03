#include <iostream>
#include <vector>

using namespace std;

// Special Array I

class Solution
{
public:
    bool isArraySpecial(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return true;
        }
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if ((nums.at(i) % 2 == 0 && nums.at(i + 1) % 2 == 0) || (nums.at(i) % 2 == 1 && nums.at(i + 1) % 2 == 1))
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<int> vec1 = {4, 3, 1, 6};
    vector<int> vec2 = {2, 1, 4};
    Solution sol = Solution();
    bool isSpecial = sol.isArraySpecial(vec2);
    cout << isSpecial << endl;
    return 0;
}