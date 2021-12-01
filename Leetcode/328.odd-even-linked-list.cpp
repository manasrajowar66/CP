/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *odd_list = head, *even_list = head->next, *odd_list_end = head, *even_list_end = head->next;
        while (even_list_end && even_list_end->next)
        {
            odd_list_end->next = odd_list_end->next->next;
            even_list_end->next = even_list_end->next->next;
            odd_list_end = odd_list_end->next;
            even_list_end = even_list_end->next;
        }
        odd_list_end->next = even_list;
        return head;
    }
};
// @lc code=end
