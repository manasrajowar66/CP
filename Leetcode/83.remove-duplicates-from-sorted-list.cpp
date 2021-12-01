/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
        if (!head)
        {
            return head;
        }
        ListNode *newhead = NULL, *curr1 = NULL, *curr2 = head, *prev = NULL;
        while (curr2)
        {
            if (newhead && prev->val != curr2->val)
            {
                // cout << curr2->val << " ";
                curr1->next = curr2;
                curr1 = curr1->next;
            }
            else if (!prev)
            {
                // cout << curr2->val << " ";
                newhead = curr2;
                curr1 = curr2;
            }
            prev = curr2;
            curr2 = curr2->next;
        }
        if (curr1)
            curr1->next = NULL;
        return newhead;
    }
};
// @lc code=end
