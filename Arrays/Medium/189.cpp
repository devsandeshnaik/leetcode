#include <iostream>
#include <vector>

using namespace std;

/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
*/

// Works but exceeds limit and slow for longer arrays
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    for (int i = 0; i < k; i++)
    {
        int temp = nums[n - 1];
        for (int j = n - 1; j > 0; j--)
        {
            nums[j] = nums[j - 1];
        }
        nums[0] = temp;
    }
}
/*
k %= n is used to ensure that k is within the valid range [0, n-1].

Why is k %= n necessary?
If k is greater than or equal to n, then rotating the array by k steps is equivalent to rotating 
it by k % n steps.
This is because rotating an array of size n by n or any multiple of n results in the same 
array (a full cycle brings it back to the original order).
For example, if nums = [1,2,3,4,5] (size n = 5) and k = 7:

k % n = 7 % 5 = 2
Rotating by 7 is the same as rotating by 2.
*/
void rotate2(vector<int> &nums, int k)
{
    int n = nums.size();
    k %= n;
    cout << "K " << k << endl;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    for (auto i : nums)
    {
        cout << i << endl;
    }
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    rotate2(vec, 3);
    return 0;
}