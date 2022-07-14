// candidates = [ 2, 3, 6, 7 ], target = 7
// Output : [ [ 2, 2, 3 ], [7]]

// The same number may be chosen from candidates an unlimited number of times.
// return a list of all unique combinations of candidates where the chosen numbers sum to target

class Solution
{
public:
    void subsets(int ind, vector<int> nums, int target, vector<int> &v, vector<vector<int>> &ans)
    {
        int n = nums.size();
        if (target == 0)
        {
            ans.push_back(v);
            return;
        }

        for (int i = ind; i < n; i++)
        {
            if (nums[i] <= target)
            {
                v.push_back(nums[i]);
                subsets(i, nums, target - nums[i], v, ans);
                v.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> v;
        subsets(0, candidates, target, v, ans);
        return ans;
    }
};