/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start

class Node
{
public:
    int index, val;
};
class Solution
{
private:
    vector<int> ans;
    vector<Node> arr;
    void merge_list(int low, int high)
    {
        int mid = (low + high) >> 1;
        vector<Node> temp(high - low + 1);
        int i = low, j = mid + 1, k = 0;
        while (i <= mid && j <= high)
        {
            if (arr[i].val > arr[j].val)
            {
                ans[arr[i].index] += (high - j + 1);
                temp[k].index = arr[i].index;
                temp[k].val = arr[i].val;
                k++;
                i++;
            }
            else
            {
                temp[k].index = arr[j].index;
                temp[k].val = arr[j].val;
                k++;
                j++;
            }
        }

        while (i <= mid)
        {
            temp[k].index = arr[i].index;
            temp[k].val = arr[i].val;
            k++;
            i++;
        }
        while (j <= high)
        {
            temp[k].index = arr[j].index;
            temp[k].val = arr[j].val;
            k++;
            j++;
        }
        for (i = 0; i < k; i++)
        {
            arr[low + i].index = temp[i].index;
            arr[low + i].val = temp[i].val;
        }
    }
    void merge(int low, int high)
    {
        if (low < high)
        {
            int mid = (low + high) >> 1;
            merge(low, mid);
            merge(mid + 1, high);
            merge_list(low, high);
        }
    }

public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        ans.resize(n, 0);
        arr.resize(n);
        for (int i = 0; i < n; i++)
        {
            arr[i].index = i;
            arr[i].val = nums[i];
        }
        merge(0, n - 1);
        return ans;
    }
};
// @lc code=end
