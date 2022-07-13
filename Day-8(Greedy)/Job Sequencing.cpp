struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

class Solution
{
public:
    bool static comp(Job a, Job b)
    {
        return (a.profit > b.profit);
    }

    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, comp);
        int maxi = arr[0].dead;
        for (int i = 1; i < n; i++)
            maxi = max(maxi, arr[i].dead);
        vector<int> jobs(maxi + 1, -1);
        int totalJobs = 0, profit = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j >= 1; j--)
            {
                if (jobs[j] == -1)
                {
                    jobs[j] = i;
                    totalJobs++;
                    profit += arr[i].profit;
                    break;
                }
            }
        }
        return {totalJobs, profit};
    }
};