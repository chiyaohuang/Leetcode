/*
 * String to Integer (atoi)
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the
first non-whitespace character is found. Then, starting from this character,
takes an optional initial plus or minus sign followed by as many numerical
digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral
number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid
integral number, or if no such sequence exists because either str is empty or it
contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within
the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the numerical value is
out
of the range of representable values, INT_MAX (2^31 − 1) or INT_MIN (−2^31) is
returned.

Example 1:
Input: "42"
Output: 42

Example 2:
Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.

Example 3:
Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a
numerical digit.

Example 4:
Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical
             digit or a +/- sign. Therefore no valid conversion could be
performed.

Example 5:
Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed
integer.
             Thefore INT_MIN (−2^31) is returned.
*/

#include <iostream>
#include <string>
#include <vector>

#define INT_MIN -2147483648
#define INT_MAX 2147483647

class Solution {
  public:
    int myAtoi(std::string str) {

        __int32_t result = 0;
        std::vector<int> candidates;
        bool sign = false;
        bool flag = false;

        for (int i = 0; i < str.size(); i++) {

            if (!(str[i] >= 48 && str[i] < 59) && str[i] != '-' &&
                str[i] != '+' && str[i] != '0' && str[i] != ' ')
                break;

            if (!flag) {
                if ((str[i] >= 48 && str[i] < 59) || str[i] == '-' ||
                    str[i] == '+') {
                    flag = true;
                    if (str[i] >= 48 && str[i] < 59) {
                        candidates.push_back(str[i] - 48);
                    }

                    if (str[i] == '-')
                        sign = true;
                }
            } else {
                if (str[i] >= 48 && str[i] < 59)
                    candidates.push_back(str[i] - 48);
                else{
                    break;
                }

            }
        }

        for (int i = 0; i < candidates.size(); i++) {
            if (result > INT_MAX / 10 ||
                (result == INT_MAX / 10 && candidates[i] > 8))
                return INT_MIN;
            if (result > INT_MAX / 10 ||
                (result == INT_MAX / 10 && candidates[i] == 8)) {
                if (sign)
                    return INT_MIN;
                else
                    return INT_MAX;
            }

            result = result * 10 + candidates[i];
        }
        if (sign)
            return -result;

        return result;
    }
};
