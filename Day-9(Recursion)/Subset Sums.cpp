void subsets(int i, vector<int> nums, vector<int> &ans, int sum)
{
    if (i == 0)
    {
        ans.push_back(sum);
        return;
    }
    subsets(i - 1, nums, ans, sum + nums[i - 1]); // take
    subsets(i - 1, nums, ans, sum);               // not-take
}

vector<int> subsetSum(vector<int> &nums)
{
    vector<int> ans;
    subsets(nums.size(), nums, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
}