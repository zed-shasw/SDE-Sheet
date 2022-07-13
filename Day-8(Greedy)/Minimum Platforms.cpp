int calculateMinPatforms(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int platforms = 1, maxPlatforms = 1;
    int i = 1, j = 0;
    while (i < n && j < n)
    {
        if (arr[i] > dep[j])
        {
            j++;
            platforms--;
        }
        else
        {
            i++;
            platforms++;
        }
        maxPlatforms = max(platforms, maxPlatforms);
    }
    return maxPlatforms;
}