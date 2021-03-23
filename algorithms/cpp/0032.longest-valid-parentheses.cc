// Source : https://leetcode-cn.com/problems/longest-valid-parentheses/
// Author : Junjie Huang
// Date   : 2021-03-23

/******************************************************************************
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * Example 1:
 *    Input: s = "(()"
 *    Output: 2
 *    Explanation: The longest valid parentheses substring is "()".
 * Example 2:
 *    Input: s = ")()())"
 *    Output: 4
 *    Explanation: The longest valid parentheses substring is "()()".
 * Example 3:
 *    Input: s = ""
 *    Output: 0
 * Constraints:
 *    0 <= s.length <= 3 * 104
 *  s[i] is '(', or ')'.
 *****************************************************************************/

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(), 0);
        int result = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = 2;
                    if (i - 2 >= 0 && dp[i - 2] >= 0) {
                        dp[i] += dp[i - 2];
                    }
                } else if (dp[i - 1] > 0 && i - dp[i - 1] - 1 >= 0 &&
                           s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + 2;
                    if (i - dp[i] >= 0 && dp[i - dp[i]] >= 0) {
                        dp[i] += dp[i - dp[i]];
                    }
                }
                result = max(result, dp[i]);
            }
        }
        return result;
    }
};
