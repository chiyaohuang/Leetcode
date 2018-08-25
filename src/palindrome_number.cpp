/*
 *Palindrome Number
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?
*/

#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {

        if(x < 0)
            return false;

        int quo = x;
        int pal = 0;
        while(quo != 0){
            int res = quo % 10;
            quo = quo / 10;
            pal = pal * 10 + res;
        }

        std::cout << "x: " << x <<std::endl;
        std::cout << "palindrome: " << pal <<std::endl;

        if(pal == x)
            return true;
        return false;

    }
};

int main(){
    Solution so;

    std::cout << "result: " << so.isPalindrome(12221) << std::endl;
    return 0;
}
