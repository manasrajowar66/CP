/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *curr2 = NULL, *curr1 = head, *prev = NULL;
        ListNode *newhead = NULL;
        while (curr1)
        {
            if (newhead)
            {
                if (curr1->next && prev && curr1->val != curr1->next->val && curr1->val != prev->val)
                {
                    curr2->next = curr1;
                    curr2 = curr2->next;
                }
                else if (!prev && curr1->next && curr1->val != curr1->next->val)
                {
                    curr2->next = curr1;
                    curr2 = curr2->next;
                }
                else if (prev && !curr1->next && curr1->val != prev->val)
                {
                    curr2->next = curr1;
                    curr2 = curr2->next;
                }
            }
            else
            {
                if (curr1->next && prev && curr1->val != curr1->next->val && curr1->val != prev->val)
                {
                    newhead = curr1;
                    curr2 = newhead;
                }
                else if (!prev && curr1->next && curr1->val != curr1->next->val)
                {
                    newhead = curr1;
                    curr2 = newhead;
                }
                else if (prev && !curr1->next && curr1->val != prev->val)
                {
                    newhead = curr1;
                    curr2 = newhead;
                }
            }
            prev = curr1;
            curr1 = curr1->next;
        }
        if (curr2)
            curr2->next = NULL;
        return newhead;
    }
};
// @lc code=end
