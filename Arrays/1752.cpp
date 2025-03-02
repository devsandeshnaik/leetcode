#include <iostream>
#include <vector>

using namespace std;

/*
Given an array nums, return true if the array was originally sorted in non-decreasing order,
then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such
that B[i] == A[(i+x) % A.length] for every valid index i.
*/

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        if (nums.size() <= 2)
        {
            return true;
        }

        int index = 1;
        int lastEvaluatedValue = nums.at(0);
        int highestVal;
        int foundHighestVal = false;
        while (index < nums.size())
        {
            if (lastEvaluatedValue > nums.at(index))
            {
                if (foundHighestVal == true || (index == nums.size() - 1 && nums.at(index) > nums.at(0)))
                {
                    return false;
                }
                else
                {
                    highestVal = lastEvaluatedValue;
                    foundHighestVal = true;
                }
            }
            else if (foundHighestVal == true && ((nums.at(index) > highestVal) || nums.at(index) > nums.at(0)))
            {
                return false;
            }
            lastEvaluatedValue = nums.at(index);
            index++;
        }
        return true;
    }
};

int main()
{
    vector<int> vec1 = {3, 4, 5, 1, 2};
    vector<int> vec2 = {2, 1, 3, 4};
    vector<int> vec3 = {1, 2, 3};
    vector<int> vec4 = {2, 4, 1, 3};
    vector<int> vec5 = {3, 1, 2, 2, 4};
    Solution sol = Solution();
    bool isSpecial = sol.check(vec5);
    cout << isSpecial << endl;
    return 0;
}