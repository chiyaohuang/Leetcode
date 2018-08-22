/*
 * 3Sum Closest
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        if(nums.size() <= 3){
            int res = 0;
            for(int i = 0; i< nums.size();i++){
                res += nums[i];
            }
            return res;
        }

        int a, b, c = 0;
        int start, end = 0;
        int min_diff = 1000000;
        int diff = 0;

        for(int i =0; i < nums.size();i++){
            a = nums[i];
            start = i + 1;
            end = nums.size() -1;

            while(start < end){
                b = nums[start];
                c = nums[end];

                diff = target - (a + b + c);


                if(abs(diff) < abs(min_diff)){
                    min_diff = diff;
                }

                if(diff == 0)
                    break;
                else if(diff > 0){
                    start = start + 1;
                }
                else
                    end = end -1;
            }
        }
        return target - min_diff;
    }
};
