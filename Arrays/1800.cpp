#include <iostream>
#include <vector>

// Maximum Ascending Subarray Sum

using namespace std;

class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int maxSum = 0;
        int currentSum = nums.at(0);
        for (int i = 1; i < nums.size(); i++)
        {
            cout << "Index: " << i << endl;
            if (nums.at(i - 1) < nums.at(i))
            {
                currentSum += nums.at(i);
            }
            else
            {
                cout << "CS" << currentSum << endl;
                maxSum = max(maxSum, currentSum);
                currentSum = nums.at(i);
            }
        }
        maxSum = max(maxSum, currentSum);
        return maxSum;
    }
};

int main()
{
    vector<int> vec = {10, 20, 30, 5, 10, 50};
    Solution sol = Solution();
    cout << sol.maxAscendingSum(vec);
    return 0;
}