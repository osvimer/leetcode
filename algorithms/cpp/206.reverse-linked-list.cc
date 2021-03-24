// Source : https://leetcode.com/problems/reverse-linked-list/
// Author : Junjie Huang
// Date   : 2021-03-24
/*******************************************************************************
 * Given the head of a singly linked list, reverse the list, and return the
 * reversed list.
 * Example 1:
 *    Input: head = [1,2,3,4,5]
 *    Output: [5,4,3,2,1]
 * Example 2:
 *    Input: head = [1,2]
 *    Output: [2,1]
 * Example 3:
 *    Input: head = []
 *    Output: []
 * Constraints:
 *    The number of nodes in the list is the range [0, 5000].
 *    -5000 <= Node.val <= 5000
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
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = nullptr;
        ListNode* current;
        while (head) {
            current = head;
            head = head->next;
            current->next = new_head;
            new_head = current;
        }
        return new_head;
    }
};
