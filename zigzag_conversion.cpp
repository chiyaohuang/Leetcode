/*
 *ZigZag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
*/

class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1)
            return s;

        vector<int> index;
        vector<string> tmp;
        tmp.resize(numRows);
        string ans;

        int quo = 0;
        int res = 0;

        int cycle = 2 * numRows -2;

        for(int i = 0; i < s.size(); i++){
            quo = i % cycle / numRows;
            res = i % cycle % numRows;
            if(quo > 0){
                res = (numRows - 2) - res;
            }
            tmp[res].push_back(s[i]);
        }

        for(int i = 0; i < numRows;i++){
            ans.append(tmp[i]);
        }

        return ans;
    }
};
