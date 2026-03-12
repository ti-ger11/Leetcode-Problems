/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {

        int n = nums.size();

        long long int x = n * (n + 1) / 2;

        long long int sum = 0;

        for (auto i : nums)
        {
            sum += i;
        }

        return x - sum;
    }
};
// @lc code=end
