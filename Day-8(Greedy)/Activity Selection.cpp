// 1 6 2 4
// 2 7 5 8
// A person can perform maximum of 3 activities, by performing the activities in // the given order 1 - > 3 -> 2.

typedef pair<int, int> pi;
int maximumActivities(vector<int> &start, vector<int> &finish)
{
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for (int i = 0; i < start.size(); i++)
    {
        pq.push({finish[i], start[i]});
    }
    int limit = 0, ans = 0;
    while (pq.size())
    {
        int s = pq.top().second;
        int e = pq.top().first;
        pq.pop();
        if (s >= limit)
        {
            ans++;
            limit = e;
        }
    }
    return ans;
}