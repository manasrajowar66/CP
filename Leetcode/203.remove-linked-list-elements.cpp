/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *curr = head, *prev = NULL;
        while (curr)
        {
            if (curr->val == val)
            {
                if (curr == head)
                {
                    head = head->next;
                    curr = curr->next;
                }
                else if (curr->next == NULL)
                {
                    if (prev == NULL)
                    {
                        curr = curr->next;
                    }
                    else
                    {
                        prev->next = NULL;
                        curr = curr->next;
                    }
                }
                else
                {
                    prev->next = curr->next;
                    curr = curr->next;
                }
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        if (prev)
            prev->next = NULL;
        return head;
    }
};
// @lc code=end
