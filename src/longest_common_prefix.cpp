/*
 * Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of
strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.

*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::string longestCommonPrefix(std::vector<std::string> &strs) {

        // foolproof
        if(strs.size() == 0)
             return "";

        // find out shortest
        int shortest = 0;
        int shortest_index = 0;
        for(int i = 0; i < strs.size();i++){
            if(strs[i].size() < shortest){
                shortest_index = i;
            }
        }

        bool success = false;
        std::string shortest_str = strs[shortest_index];
        int length = shortest_str.size();
        for(int i = 0; i < length; i++){
            shortest_str.resize(length- i);
            for(int j = 0; j < strs.size(); j ++){
                strs[j].resize(shortest_str.size());
                if( strs[j] != shortest_str)
                    break;
                if(j == strs.size() -1 )
                    success = true;
            }
            if(success)
                break;
            shortest_str = strs[shortest_index];
        }

        if(success)
            return shortest_str;
        return "";
    }
};

int main() {

    Solution so;
    std::vector<std::string> tmp{"dog","racecar","car"};
    std::cout << "ans: "<< so.longestCommonPrefix(tmp) << std::endl;

    return 0;
}
