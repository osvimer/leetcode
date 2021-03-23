// Source : https://leetcode-cn.com/problems/container-with-most-water
// Author : Junjie Huang
// Date   : 2021-03-24
/*******************************************************************************
 * Given n non-negative integers a1, a2, ..., an , where each represents a point
 * at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
 * of the line i is at (i, ai) and (i, 0). Find two lines, which, together with
 * the x-axis forms a container, such that the container contains the most water.
 * Notice that you may not slant the container.
 *
 * Constraints:
 *    n == height.length
 *    2 <= n <= 105
 *    0 <= height[i] <= 104
 ******************************************************************************/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        for (int lo = 0, hi = height.size() - 1; lo < hi; ) {
            max_area = max(max_area, (hi - lo) * min(height[lo], height[hi]));
            height[lo] < height[hi] ? ++lo : --hi;
        }
        return max_area;
    }
};
