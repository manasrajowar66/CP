/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    ListNode *prev;
    ListNode *findMid(ListNode *head, ListNode *tail)
    {
        ListNode *s = head, *f = head;
        while (f != tail && f->next != tail)
        {
            prev = s;
            s = s->next;
            f = f->next->next;
        }
        return s;
    }
    TreeNode *helper(ListNode *head, ListNode *tail)
    {
        if (head == tail)
        {
            TreeNode *root = new TreeNode(head->val);
            return root;
        }
        ListNode *mid = findMid(head, tail);
        TreeNode *root = new TreeNode(mid->val);
        if (head != mid)
        {
            root->left = helper(head, prev);
        }
        root->right = helper(mid->next, tail);
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
            return NULL;
        ListNode *curr = head;
        while (curr->next)
        {
            curr = curr->next;
        }
        return helper(head, curr);
    }
};
// @lc code=end
