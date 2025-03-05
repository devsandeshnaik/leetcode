#include <iostream>
#include <vector>

using namespace std;

/*
Given an integer array nums, move all 0's to
the end of it while maintaining the relative order of the non-zero elements.
*/

void moveZeroes(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0 && i < nums.size() - 1)
        {
            int j = i + 1;
            while (nums[j] == 0 && j < nums.size() - 1)
            {
                j++;
            }
            swap(nums[i], nums[j]);
        }
    }
    for (auto i : nums)
    {
        cout << i << ", ";
    }
}

// Better solution
/*
This focus on moving non zero integers to left using second pointer
which is named left in below case, left is incremented only when
non zero element is moved to its positon.
*/
void moveZeroes1(vector<int> &nums)
{
    int left = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        if (nums[right] != 0)
        {
            swap(nums[right], nums[left]);
            left++;
        }
    }
}

int main()
{
    vector<int> vec = {0, 1, 0, 3, 12};
    moveZeroes(vec);
    return 0;
}