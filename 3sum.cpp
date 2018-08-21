/*
 * 3Sum
Given an array nums of n integers, are there elements a, b, c in nums such that
a + b + c = 0? Find all unique triplets in the array which gives the sum of
zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        set<vector<int>> ans;
        std::sort(nums.begin(), nums.end());
        int a, b, c = 0;
        int start, end = 0;

        for (int i = 0; i < nums.size(); i++) {
            a = nums[i];
            start = i + 1;
            end = nums.size() - 1;

            while (start < end) {
                b = nums[start];
                c = nums[end];

                if (a + b + c == 0) {
                    ans.insert(vector<int>{a, b, c});
                    end--;
                } else if (a + b + c < 0) {
                    start++;
                } else
                    end--;
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
