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
        std::unordered_map<std::string, int> map;
        std::unordered_map<std::string, int>::iterator it;
        std::unordered_map<std::string, int>::iterator Max_it;
        std::pair<std::string, int> max("", 0);
        for (int i = 0; i < strs.size(); i++) {
            std::string str = strs[i].c_str();
            int length = str.size();

            for (int k = 0; k < length; k++) {
                str.resize(length - i);
                if(str.size() > 0){
                    it = map.find(str);
                    if (it != map.end()) {
                        it->second++;
                        // Longest iterate string
                        if(it->first.size() > max.first.size()){
                            max.first = it->first;
                            max.second = it->second;
                        }
                    } else {
                        map.insert(std::make_pair(str, 1));
                    }
                }
                str = strs[i].c_str();
            }
        }
        //Debug
        for(it = map.begin(); it !=map.end(); it++){
            std::cout << it->first << it->second << std::endl;
        }
        return max.first;
    }
};

int main() {

    Solution so;
    std::vector<std::string> tmp{"aa", "aa"};
    std::cout << "ans: "<< so.longestCommonPrefix(tmp) << std::endl;

    return 0;
}
