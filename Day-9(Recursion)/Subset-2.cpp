// Given an integer array nums that may contain duplicates, return all possible subsets(the power set).
// The solution set **must not contain duplicate subsets** .Return the solution in any order.

// nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

class Solution
{
public:
    void uniqueSubsets(int ind, vector<int> nums, vector<int> &v, vector<vector<int>> &ans)
    {
        ans.push_back(v);
        for (int i = ind; i < nums.size(); i++)
        {
            if (i != ind && nums[i] == nums[i - 1])
                continue;
            v.push_back(nums[i]);
            uniqueSubsets(i + 1, nums, v, ans);
            v.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        uniqueSubsets(0, nums, v, ans);
        return ans;
    }
};