/*
 * Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating
characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer
must be a substring, "pwke" is a subsequence and not a substring.


*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int lengthOfLongestSubstring(std::string s) {

        int pointer = 0;
        int max_length = 0;
        std::unordered_map<char, int> map;
        std::unordered_map<char, int>::iterator it;
        for (int i = 0; i < s.size(); i++) {
            it = map.find(s[i]);
            if (it != map.end()) {
                pointer = std::max(it->second, pointer);
                it->second = i + 1;
            } 
            else {
                map.insert(std::make_pair(s[i], i + 1));
            }
            max_length = std::max(max_length, i - pointer + 1);
        }

        //        for (it = map.begin(); it != map.end(); it++) {
        //            std::cout << it->first << it->second << std::endl;
        //        }
        return max_length;
    }
};

int main() {
    Solution so;
    std::cout << so.lengthOfLongestSubstring("") << std::endl;
    return 0;
}
