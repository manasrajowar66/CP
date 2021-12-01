/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head || left == right)
            return head;
        // ListNode *dummy = new ListNode(0);
        // dummy->next = head;
        ListNode *curr = head, *prev = NULL, *next = NULL;
        int temp = left;
        while (temp > 1)
        {
            prev = curr;
            curr = curr->next;
            temp--;
        }
        next = curr->next;
        ListNode *tempPrev = prev;
        prev = curr;
        for (int i = 1; i <= right - left; i++)
        {
            curr->next = next->next;
            next->next = prev;
            prev = next;
            next = curr->next;
        }
        if (tempPrev)
        {
            tempPrev->next = prev;
            return head;
        }
        else
        {
            return prev;
        }
    }
};
// @lc code=end
