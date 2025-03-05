#include <iostream>
#include <vector>

using namespace std;

/*
You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that
the following conditions are satisfied:

Every element less than pivot appears before every element greater than pivot.
Every element equal to pivot appears in between the elements less than and greater than pivot.
The relative order of the elements less than pivot and the elements greater than pivot is maintained.
More formally, consider every pi, pj where pi is the new position of the ith element and pj
is the new position of the jth element. If i < j and both elements are smaller (or larger)
than pivot, then pi < pj.
*/

vector<int> pivotArray(vector<int> &nums, int pivot)
{
    vector<int> ans(nums.size());
    int leftIndex = 0;
    int rightIndex = nums.size() - 1;
}

int main()
{
    vector<int> vec1 = {9, 12, 5, 10, 14, 3, 10};
    int pivot1 = 10;
    //[9,5,3,10,10,12,14]
    pivotArray(vec1, pivot1);

    vector<int> vec2 = {-3, 4, 3, 2};
    int pivot2 = 2;
    //[-3,2,4,3]

    return 0;
}