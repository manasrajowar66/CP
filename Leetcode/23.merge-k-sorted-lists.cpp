/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
private:
    ListNode *merge(ListNode *list1, ListNode *list2)
    {
        ListNode *head = NULL, *curr = NULL;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                if (head == NULL)
                {
                    head = list1;
                    curr = list1;
                }
                else
                {
                    curr->next = list1;
                    curr = curr->next;
                }
                list1 = list1->next;
            }
            else
            {
                if (head == NULL)
                {
                    head = list2;
                    curr = list2;
                }
                else
                {
                    curr->next = list2;
                    curr = curr->next;
                }
                list2 = list2->next;
            }
        }
        if (list1 != NULL)
        {
            if (head == NULL)
                head = list1;
            else
                curr->next = list1;
        }
        else if (list2 != NULL)
        {
            if (head == NULL)
                head = list2;
            else
                curr->next = list2;
        }
        // curr = head;
        // while (curr != NULL)
        // {
        //     cout << curr->val << " ";
        //     curr = curr->next;
        // }
        // cout << endl;
        return head;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *newHead = NULL;
        int n = lists.size();
        for (int i = 0; i < n; i++)
        {
            newHead = merge(newHead, lists[i]);
        }
        return newHead;
    }
};
// @lc code=end
