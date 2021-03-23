// Source : https://leetcode.com/problems/3sum/
// Author : Junjie Huang
// Date   : 2020-03-24
/*******************************************************************************
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the sum
 * of zero.Notice that the solution set must not contain duplicate triplets.
 * Example 1:
 *    Input: nums = [-1,0,1,2,-1,-4]
 *    Output: [[-1,-1,2],[-1,0,1]]
 * Example 2:
 *    Input: nums = []
 *    Output: []
 * Example 3:
 *    Input: nums = [0]
 *    Output: []
 * Constraints:
 *    0 <= nums.length <= 3000
 *    -105 <= nums[i] <= 105
 ******************************************************************************/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int lo = i + 1, hi = nums.size() - 1; lo < hi; ) {
                if (nums[i] + nums[lo] + nums[hi] < 0) {
                    while (lo < hi && nums[lo] == nums[++lo]) {}
                } else if (nums[i] + nums[lo] + nums[hi] > 0) {
                    while (lo < hi && nums[hi] == nums[--hi]) {}
                } else {
                    result.push_back(vector<int>({nums[i], nums[lo], nums[hi]}));
                    while (lo < hi && nums[lo] == nums[++lo]) {}
                    while (lo < hi && nums[hi] == nums[--hi]) {}
                }
            }
        }
        return result;
    }
};
