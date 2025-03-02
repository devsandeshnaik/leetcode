#include <iostream>
#include <vector>

using namespace std;
/*You are given two 2D integer arrays nums1 and nums2.

nums1[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
nums2[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
Each array contains unique ids and is sorted in ascending order by id.

Merge the two arrays into one array that is sorted in ascending order by id,
respecting the following conditions:

Only ids that appear in at least one of the two arrays should be included in the resulting array.
Each id should be included only once and its value should be the sum of the values of this
id in the two arrays.
If the id does not exist in one of the two arrays, then assume its value in that array to be 0.
*/

vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
{
    int num1Size = nums1.size();
    int num2Size = nums2.size();
    // Have invidual pointers tracking index movement for each array
    int nums1Index = 0;
    int nums2Index = 0;
    vector<vector<int>> result;

    // Run first while loop until end of atleast one array is reached
    while (nums1Index < num1Size && nums2Index < num2Size)
    {
        // compare the 0th item in both internl array array
        // when both are equal generate sum and add to result
        if (nums1[nums1Index][0] == nums2[nums2Index][0])
        {

            result.push_back({nums1[nums1Index][0], nums1[nums1Index][1] + nums2[nums2Index][1]});
            nums1Index++;
            nums2Index++;
        }
        // when 0th item not equal add to result the lower 0th value item.
        else if (nums1[nums1Index][0] > nums2[nums2Index][0])
        {
            result.push_back({nums2[nums2Index][0], nums2[nums2Index][1]});
            nums2Index++;
        }
        else
        {
            result.push_back({nums1[nums1Index][0], nums1[nums1Index][1]});
            nums1Index++;
        }
    }

    // this two loops make sure if there is surplue(both array size is not equal), then add remaining
    // values to result array
    while (nums1Index < num1Size)
    {
        result.push_back({nums1[nums1Index][0], nums1[nums1Index][1]});
        nums1Index++;
    }

    while (nums2Index < num2Size)
    {
        result.push_back({nums2[nums2Index][0], nums2[nums2Index][1]});
        nums2Index++;
    }
    return result;
}

int main()
{

    vector<vector<int>> nums1 = {{1, 2},
                                 {2, 3},
                                 {4, 5}};
    vector<vector<int>> nums2 = {{1, 4},
                                 {3, 2},
                                 {4, 1}};

    vector<vector<int>> nums3 = {{2, 4},
                                 {3, 6},
                                 {5, 5}};
    vector<vector<int>> nums4 = {{1, 3},
                                 {4, 3}};
    // mergeArrays(nums1, nums2);
    mergeArrays(nums3, nums4);
    return 0;
}