// Source : https://leetcode.com/problems/swap-nodes-in-pairs
// Author : Junjie Huang
// Date   : 2021-03-24
/*******************************************************************************
 * Given a linked list, swap every two adjacent nodes and return its head.
 * Example 1:
 *    Input: head = [1,2,3,4]
 *    Output: [2,1,4,3]
 * Example 2:
 *    Input: head = []
 *    Output: []
 * Example 3:
 *    Input: head = [1]
 *    Output: [1]
 * Constraints:
 *    The number of nodes in the list is in the range [0, 100].
 *    0 <= Node.val <= 100
 ******************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return nullptr;
        ListNode dummy(0, head);
        ListNode* pre = &dummy;
        ListNode* cur = pre->next;
        while (cur && cur->next) {
            pre->next = cur->next;
            cur->next = pre->next->next;
            pre->next->next = cur;
            pre = cur;
            cur = pre->next;
        }
        return dummy.next;
    }
};
