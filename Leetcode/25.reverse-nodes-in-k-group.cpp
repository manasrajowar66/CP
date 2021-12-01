/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */

// @lc code=start
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
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *curr = head, *prev = dummy, *next = NULL;
        int count = 0;
        while (curr)
        {
            curr = curr->next;
            count++;
        }
        while (count >= k)
        {
            curr = prev->next;
            next = curr->next;
            for (int i = 1; i < k; i++)
            {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            count -= k;
            prev = curr;
        }
        return dummy->next;
    }
};
// @lc code=end
