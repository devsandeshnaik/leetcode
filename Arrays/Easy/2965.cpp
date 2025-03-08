#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
/*
You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2].
Each integer appears exactly once except a which appears twice and b which is missing.
The task is to find the repeating and missing numbers a and b.

Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.
*/

vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
{
    unordered_set<int> unique = {};
    int sqaure = grid.size() * grid.size();
    int expectedSum = (sqaure * (sqaure + 1)) / 2;
    int uniqueSum = 0;
    int duplicate = -1;
    for (vector<int> row : grid)
    {
        for (int num : row)
        {
            if (unique.find(num) == unique.end())
            {
                unique.insert(num);
                uniqueSum += num;
            }
            else
            {
                duplicate = num;
            }
        }
    }
    return {duplicate, expectedSum - uniqueSum};
}

int main()
{
    vector<vector<int>> vec = {{1, 3}, {2, 2}};
    vector<vector<int>> vec2 = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    findMissingAndRepeatedValues(vec2);
    return 0;
}