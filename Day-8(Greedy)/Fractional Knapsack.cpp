struct Item
{
    int value;
    int weight;
};

class Solution
{
public:
    // Function to get the maximum total value in the knapsack.
    bool static comp(const Item i1, const Item i2)
    {
        double r1 = (double)i1.value / (double)i1.weight;
        double r2 = (double)i2.value / (double)i2.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, comp);
        int currWeight = 0;
        double totalValue = 0.0;
        for (int i = 0; i < n; i++)
        {
            if (currWeight + arr[i].weight <= W)
            {
                currWeight += arr[i].weight;
                totalValue += arr[i].value;
            }
            else
            {
                int remainingWeight = W - currWeight;
                totalValue += (arr[i].value / (double)arr[i].weight) * (double)remainingWeight;
                break;
            }
        }
        return totalValue;
    }
};