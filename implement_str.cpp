/*
 * Implement strStr()
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle
is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question
to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty
string. This is consistent to C's strstr() and Java's indexOf().
*/

#include <iostream>
#include <string>

class Solution {
  public:
    int strStr(std::string haystack, std::string needle) {

        // foolproof
        if (needle.size() == 0) {
            return 0;
        }

        int needle_pointer = 0;
        for (int i = 0; i < haystack.size(); i++) {

            if (haystack[i] == needle[needle_pointer]) {
                needle_pointer = needle_pointer + 1;
            } else {
                // if matching fails
                if(needle_pointer != 0){
                    // back to the first matched index
                    i =  i - needle_pointer;
                }
                needle_pointer = 0;
            }
            //std::cout << i << '\t' << needle_pointer << std::endl;
            if (needle_pointer == needle.size())
                return i - (needle.size() - 1);
        }
        return -1;
    }
};

int main() {

    Solution so;
    std::cout << so.strStr("mississippi", "pi") << std::endl;
    std::cout << so.strStr("mississippi", "issip") << std::endl;
    //std::cout << so.strStr("aaaabab", "bab") << std::endl;

    return 0;
}
