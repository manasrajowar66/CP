/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *left = NULL, *right = NULL, *left_end = NULL, *right_end = NULL;
        ListNode *curr = head;
        while (curr)
        {
            if (curr->val < x)
            {
                if (left)
                {
                    left_end->next = curr;
                    left_end = left_end->next;
                }
                else
                {
                    left = curr;
                    left_end = curr;
                }
            }
            else
            {
                if (right)
                {
                    right_end->next = curr;
                    right_end = right_end->next;
                }
                else
                {
                    right = curr;
                    right_end = curr;
                }
            }
            curr = curr->next;
        }
        if (right)
            right_end->next = NULL;
        ListNode *newhead = left;
        if (left)
        {
            left_end->next = right;
        }
        else
        {
            newhead = right;
        }
        return newhead;
    }
};
// @lc code=end
