/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start
// #define int long long
class NumArray
{
private:
    vector<int> arr;
    vector<int> tree;
    int n;
    void initialize(int left, int right, int treeNode)
    {
        if (left > right)
            return;
        if (left == right)
        {
            tree[treeNode] = arr[left];
            return;
        }
        int mid = (left + right) >> 1;
        initialize(left, mid, treeNode * 2);
        initialize(mid + 1, right, treeNode * 2 + 1);
        tree[treeNode] = tree[treeNode * 2] + tree[treeNode * 2 + 1];
    }
    void update(int left, int right, int treeNode, int index, int val)
    {
        if (left > right)
            return;
        if (left == right)
        {
            if (left != index)
                return;
            arr[index] = val;
            tree[treeNode] = arr[index];
            return;
        }
        int mid = (left + right) >> 1;
        if (index <= mid)
            update(left, mid, treeNode * 2, index, val);
        else
            update(mid + 1, right, treeNode * 2 + 1, index, val);
        tree[treeNode] = tree[treeNode * 2] + tree[treeNode * 2 + 1];
    }
    int sumRange(int treeNode, int left, int right, int start, int end)
    {
        if (left > right)
            return 0;
        //completely outside
        if (right < start || left > end)
        {
            return 0;
        }
        //completely inside
        if (left >= start && right <= end)
        {
            return tree[treeNode];
        }
        //partially inside
        int mid = (left + right) >> 1;
        int left_sum = sumRange(treeNode * 2, left, mid, start, end);
        int right_sum = sumRange(treeNode * 2 + 1, mid + 1, right, start, end);
        return left_sum + right_sum;
    }

public:
    NumArray(vector<int> &nums)
    {
        n = nums.size();
        arr.resize(n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = nums[i];
        }
        tree.resize(4 * n, 0);
        initialize(0, n - 1, 1);
        // for (int i = 1; i < 4 * n; i++)
        // {
        //     cout << tree[i] << " ";
        // }
        // cout << endl;
    }

    void update(int index, int val)
    {
        update(0, n - 1, 1, index, val);
    }

    int sumRange(int left, int right)
    {
        return sumRange(1, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end
