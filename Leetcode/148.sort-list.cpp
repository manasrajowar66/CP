/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    vector<ListNode *> hash;
    // ListNode *findMid(ListNode *head, ListNode *tail)
    // {
    //     ListNode *s = head, *f = head;
    //     while (f != tail && f->next != tail)
    //     {
    //         s = s->next;
    //         f = f->next->next;
    //     }
    //     return s;
    // }
    ListNode *merge(ListNode *list1, ListNode *list2)
    {
        ListNode *newhead = NULL, *curr = NULL;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                if (!newhead)
                {
                    newhead = list1;
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
                if (!newhead)
                {
                    newhead = list2;
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
        if (list1)
        {
            if (newhead)
                curr->next = list1;
            else
                newhead = list1;
        }
        else if (list2)
        {
            if (newhead)
                curr->next = list2;
            else
                newhead = list2;
        }
        return newhead;
    }
    ListNode *merge_sort(int start, int end)
    {
        if (start == end)
        {
            ListNode *temp = hash[start];
            temp->next = NULL;
            return temp;
        }
        int mid = (start + end) >> 1;
        // ListNode *next = hash[mid]->next;
        ListNode *left = merge_sort(start, mid);
        ListNode *right = merge_sort(mid + 1, end);
        return merge(left, right);
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *curr = head, *prev = NULL;
        while (curr)
        {
            prev = curr;
            hash.push_back(curr);
            curr = curr->next;
        }
        return merge_sort(0, hash.size() - 1);
    }
};
// @lc code=end
