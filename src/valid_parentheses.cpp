/*
 * Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true
*/

#include <iostream>
#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stk1;

        for(int i = 0; i < s.size(); i++){
            if(stk1.size() == 0 && (s[i] == ')' || s[i] == '}' || s[i] == ']'))
                return false;

            if( s[i] == '(' || s[i] == '{' || s[i] == '[')
                stk1.push(s[i]);

            if( s[i] == ')' ){
                if(stk1.top() == '(')
                    stk1.pop();
                else
                    return false;
            }
            if( s[i] == '}' ){
                if(stk1.top() == '{')
                    stk1.pop();
                else
                    return false;
            }
            if( s[i] == ']' ){
                if(stk1.top() == '[')
                    stk1.pop();
                else
                    return false;
            }
        }
        if(stk1.empty())
            return true;
        return false;
    }
};

int main() {

    Solution s;
    std::cout << s.isValid("(])") << std::endl;
    return 0;
}
