/*
 * 7. Reverse Integer
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1].
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/


class Solution {
public:
    int reverse(int x) {

        int input = x;

        int quo = input;
        int output = 0;
        while(quo != 0){
            int res = quo % (10);
            quo = quo / (10);

            if (output > INT_MAX/10 || (output == INT_MAX / 10 && res > 7))
                return 0;
            if (output < INT_MIN/10 || (output == INT_MIN / 10 && res < -8))
                return 0;
            output = output * 10 + res;
        }

        return output;
    }
};
