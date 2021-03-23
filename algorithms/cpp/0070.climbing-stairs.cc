// Source : https://leetcode.com/problems/climbing-stairs/
// Author : Junjie Huang
// Date   : 2021-03-24
/*******************************************************************************
 * You are climbing a staircase. It takes n steps to reach the top.
 * Each time you can either climb 1 or 2 steps.
 * In how many distinct ways can you climb to the top?
 ******************************************************************************/

class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) return n;
        int f1 = 1, f2 = 2, f3;
        for (int i = 3; i <= n; ++i) {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        return f3;
    }
};
