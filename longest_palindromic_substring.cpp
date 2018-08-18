/*
 * Longest Palindromic Substring
Given a string s, find the longest palindromic substring in s. You may assume
that the maximum length of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
  public:
    std::string longestPalindrome(std::string s) {

        // foolproof
        if (s.size() == 0)
            return "";

        // Two type palindromic. ans1 is odd while ans2 is even.
        int type1_length = 0;
        int type2_length = 0;

        int max_length = 0;
        int mid = 0;

        bool whichType = false;

        for (int i = 0; i < s.size(); i++) {

            type1_length = 2 * checkPalin(i, s) + 1;
            type2_length = 2 * (checkPalin2(i, s) + 1);

            if (type1_length < type2_length) {
                if (max_length < type2_length) {
                    max_length = type2_length;
                    mid = i;
                    whichType = false;
                }
            } else {
                if (max_length < type1_length) {
                    max_length = type1_length;
                    mid = i;
                    whichType = true;
                }
            }
        }
        if (whichType) {
            return s.substr(mid - (max_length - 1) / 2, max_length);
        } else {
            return s.substr(mid - (max_length / 2 - 1), max_length);
        }
    }

    int checkPalin(int &mid, std::string &s) {
        for (int i = 0; i <= mid; i++) {
            if (s[mid - i] != s[mid + i]) {
                return i - 1;
            }
        }
        return mid;
    }

    int checkPalin2(int &mid, std::string &s) {
        for (int i = 0; i <= mid; i++) {
            if (s[mid - i] != s[mid + 1 + i]) {
                return i - 1;
            }
        }
        return mid;
    }
};

int main() {

    Solution so;
    std::cout << so.longestPalindrome("adbbdaaaacccccdac") << std::endl;
    return 0;
}
