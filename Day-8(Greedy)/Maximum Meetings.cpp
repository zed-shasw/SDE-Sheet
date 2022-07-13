// Function to find the maximum number of meetings that can
// be performed in a meeting room.

struct Node
{
    int start, finish, ind;
    Node(int start, int finish, int ind)
    {
        this->start = start;
        this->finish = finish;
        this->ind = ind;
    }
};

bool comp(Node n1, Node n2)
{
    if (n1.finish < n2.finish)
        return true;
    if (n1.finish > n2.finish)
        return false;
    if (n1.ind > n2.ind)
        return false;
    return true;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{
    vector<Node> meetings;
    for (int i = 0; i < start.size(); i++)
    {
        meetings.push_back(Node(start[i], end[i], i + 1));
    }
    sort(meetings.begin(), meetings.end(), comp);
    vector<int> ans;
    int limit = meetings[0].finish;
    ans.push_back(meetings[0].ind);
    for (int i = 1; i < meetings.size(); i++)
    {
        if (meetings[i].start > limit)
        {
            limit = meetings[i].finish;
            ans.push_back(meetings[i].ind);
        }
    }
    return ans;
}