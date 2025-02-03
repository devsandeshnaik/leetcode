#include <iostream>
#include <vector>

using namespace std;

// Longest Strictly Increasing or Strictly Decreasing Subarray

class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int ls = 1;
        int currentAscendingStreak = 1;
        int currentDecendingStreak = 1;

        for (int index = 1; index < nums.size(); index++)
        {
            // cout << "index => " << index << endl;
            if (nums.at(index - 1) > nums.at(index))
            {
                // decending
                currentAscendingStreak = 1;
                currentDecendingStreak++;
                ls = max(currentDecendingStreak, ls);
            }
            else if (nums.at(index - 1) < nums.at(index))
            {
                // ascending
                currentDecendingStreak = 1;
                currentAscendingStreak++;
                ls = max(currentAscendingStreak, ls);
            }
            else
            {
                currentAscendingStreak = 1;
                currentDecendingStreak = 1;
            }
        }
        return ls;
    }
};

int main()
{
    vector<int> vec1 = {1, 4, 3, 3, 2};
    vector<int> vec2 = {1, 9, 7, 1};
    vector<int> vec3 = {3, 2, 1};
    Solution sol = Solution();
    cout << "Vector 1  => " << sol.longestMonotonicSubarray(vec1) << endl;
    cout << "Vector 2  => " << sol.longestMonotonicSubarray(vec2) << endl;
    cout << "Vector 3  => " << sol.longestMonotonicSubarray(vec3) << endl;
    return 0;
}