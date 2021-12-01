/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode *head)
    {
        if (!head)
            return;
        deque<ListNode *> q;
        ListNode *curr = head;
        while (curr)
        {
            q.push_back(curr);
            curr = curr->next;
        }
        curr = NULL;
        while (!q.empty())
        {
            if (!curr)
            {
                curr = q.front();
                q.pop_front();
                if (q.empty())
                    break;
                curr->next = q.back();
                q.pop_back();
                curr = curr->next;
            }
            else
            {
                curr->next = q.front();
                curr = curr->next;
                q.pop_front();
                if (q.empty())
                    break;
                curr->next = q.back();
                q.pop_back();
                curr = curr->next;
            }
        }
        curr->next = NULL;
    }
};
// @lc code=end
