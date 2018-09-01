/*
 * Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter
combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given
below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

#include <iostream>
#include <string>
#include <vector>

class Solution {
  public:
    std::vector<std::string> letterCombinations(std::string digits) {

        std::string str(digits.size(), '\0');
        combine(digits, 0, str);
        return ans;
    }

    void combine(std::string &digits, int index, std::string str) {
        if (index == digits.size()) {
            ans.push_back(str);
            return;
        }

        std::string candidate = dictionary[digits[index] - '0'];
        for (int i = 0; i < candidate.size(); i++) {
            str[index] = candidate[i];
            combine(digits, index + 1, str);
        }
    }

    std::vector<std::string> ans;
    std::vector<std::string> dictionary = {" ",   "",    "abc", "dfg", "hij",
                                "klm", "nop", "qrs", "tuv", "wxyz"};
};
