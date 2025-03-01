#include <iostream>
#include <vector>

using namespace std;

/*
You are given a 0-indexed array nums of size n consisting of non-negative integers.

You need to apply n - 1 operations to this array where, in the ith operation (0-indexed), you will apply the following on the ith element of nums:

If nums[i] == nums[i + 1], then multiply nums[i] by 2 and set nums[i + 1] to 0. Otherwise, you skip this operation.
After performing all the operations, shift all the 0's to the end of the array.

For example, the array [1,0,2,0,0,1] after shifting all its 0's to the end, is [1,2,1,0,0,0].
Return the resulting array.
*/

vector<int> applyOperations(vector<int> &nums)
{
    // running operations
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }

    // moving zero's to end of the array
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] > 0)
                {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    break;
                }
            }
        }
    }

    return nums;
}

// Single for loop approach
vector<int> applyOperations2(vector<int> &nums)
{
    // running operations
    vector<int> res(nums.size(), 0);
    int nonZeroIndex = 0;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
        if (nums[i] > 0)
        {
            res[nonZeroIndex++] = nums[i];
        }
        // Since we are iterating till n-1 we need to make sure last value is evaluated as well.
        if ((i == nums.size() - 2) && (nums[i + 1] > 0))
        {
            res[nonZeroIndex++] = nums[i + 1];
        }
    }

    return res;
}

int main()
{
    vector<int> vec1 = {1, 2, 2, 1, 1, 0};
    vector<int> vec2 = {0, 1};
    vector<int> result = applyOperations2(vec2);
    cout << "Size : " << result.size() << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}