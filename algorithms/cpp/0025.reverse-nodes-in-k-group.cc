// Source : https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
// Author : Junjie Huang
// Date   : 2021-03-26
/*******************************************************************************
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list. k is a positive integer and is less than or equal
 * to the length of the linked list. If the number of nodes is not a multiple of
 * k then left-out nodes, in the end, should remain as it is.
 *
 * Follow up:
 *    Could you solve the problem in O(1) extra memory space?
 *    You may not alter the values in the list's nodes, only nodes itself may be changed.
 *
 * Example 1:
 *    Input: head = [1,2,3,4,5], k = 2
 *    Output: [2,1,4,3,5]
 *
 * Example 2:
 *    Input: head = [1,2,3,4,5], k = 3
 *    Output: [3,2,1,4,5]
 *
 * Example 3:
 *    Input: head = [1,2,3,4,5], k = 1
 *    Output: [1,2,3,4,5]
 *
 * Example 4:
 *    Input: head = [1], k = 1
 *    Output: [1]
 *
 * Constraints:
 *    The number of nodes in the list is in the range sz.
 *    1 <= sz <= 5000
 *    0 <= Node.val <= 1000
 *    1 <= k <= sz
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;
        ListNode dummy(0, head);
        ListNode *pre_end = &dummy, *start = head;
        ListNode *end, *next_start;
        while (start) {
            end = start;
            for (int i = 0; i < k - 1; ++i) {
                end = end->next;
                if (!end) return dummy.next;
            }
            pre_end->next = end;
            next_start = end->next;
            end->next = nullptr;
            end = reverseList(start);
            end->next = next_start;
            start = next_start;
            pre_end = end;
        }
        return dummy.next;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* old_head = head;
        ListNode* new_head = nullptr;
        ListNode* cur;
        while (head) {
            cur = head;
            head = head->next;
            cur->next = new_head;
            new_head = cur;
        }
        return old_head;
    }
};
