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

int main()
{
    vector<int> vec1 = {1, 2, 2, 1, 1, 0};
    vector<int> result = applyOperations(vec1);
    cout << "Size : " << result.size() << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}