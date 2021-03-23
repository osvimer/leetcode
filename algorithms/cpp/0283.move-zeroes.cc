// Source : https://leetcode-cn.com/problems/move-zeroes/
// Author : Junjie Huang
// Date   : 2020-03-23
/*******************************************************************************
 * Given an integer array nums, move all 0's to the end of it while maintaining
 * the relative order of the non-zero elements.
 * Note that you must do this in-place without making a copy of the array.
 ******************************************************************************/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        for (int& n : nums) {
            if (0 != n) {
                swap(nums[pos++], n);
            }
        }
    }
};
