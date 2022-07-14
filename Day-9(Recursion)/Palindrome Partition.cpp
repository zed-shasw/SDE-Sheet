// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return all possible palindrome partitioning of s.

//    s = "aab"
// Output: [["a","a","b"],["aa","b"]]

class Solution
{
public:
    void pal(int i, string s, vector<string> &v, vector<vector<string>> &ans)
    {
        if (i == s.size())
        {
            ans.push_back(v);
            return;
        }
        string temp;
        for (int j = i; j < s.size(); j++)
        {
            temp += s[j];
            if (isPalindrome(temp))
            {
                v.push_back(temp);
                pal(j + 1, s, v, ans);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<string> v;
        vector<vector<string>> ans;
        pal(0, s, v, ans);
        return ans;
    }

private:
    bool isPalindrome(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        while (i <= j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};