// Subset-Sum 2 problem with target given.

class Solution
{
public:
    void subsets(int i, int target, vector<int> arr, vector<int> &v, vector<vector<int>> &ans)
    {
        if (target == 0)
            ans.push_back(v);
        for (int j = i; j < arr.size(); j++)
        {
            if (j != i && arr[j] == arr[j - 1])
                continue;
            v.push_back(arr[j]);
            if (target >= arr[j])
                subsets(j + 1, target - arr[j], arr, v, ans);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(begin(candidates), end(candidates));
        vector<vector<int>> ans;
        vector<int> v;
        subsets(0, target, candidates, v, ans);
        return ans;
    }
};