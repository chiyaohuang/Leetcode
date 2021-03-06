/*
 * Next Permutation
Implement next permutation, which rearranges numbers into the lexicographically
next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible
order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding
outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
  public:
    void nextPermutation(std::vector<int> &nums) {

        if (nums.size() < 2)
            return;
        int n = nums.size(), j = n - 2;
        while (j >= 0 && nums[j] >= nums[j + 1])
            j--;

        if (j < 0) {
            //std::sort(nums.begin(), nums.end());
            std::reverse(nums.begin(), nums.end());
            return;
        }

        int i = j + 1;
        while (i < n && nums[i] > nums[j])
            i++;
        i--;

        std::swap(nums[i], nums[j]);
        std::sort(nums.begin() + j + 1, nums.end());
    }
};

/*
int main(){
    Solution so;

    std::vector<int> input = {4, 2, 0, 2, 3, 2, 0};
    for(int i = 0; i < input.size(); i++) {
        std::cout << input[i] << ' ';
    }
    std::cout << std::endl;

    so.nextPermutation(input);

    for(int i = 0; i < input.size(); i++) {
        std::cout << input[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
*/
