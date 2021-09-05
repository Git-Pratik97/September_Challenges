#include<bits/stdc++.h>

using namespace std;

int trap_rain(int arr[], int n)
{
    int max_left = INT_MIN;
    int max_right = INT_MIN;

    vector<int> left (n, 0);
    vector<int> right (n, 0);

    for(int i = 0; i < n; i++)
    {
        left[i] = max(max_left, arr[i]);
        if(max_left < arr[i])
        {
            max_left = arr[i];
        }
    }

    for(int i = n-1; i >= 0; i--)
    {
        right[i] = max(max_right, arr[i]);
        if(max_right < arr[i])
        {
            max_right = arr[i];
        }
    }

    int sum_rain = 0;
    for(int i = 0; i < n; i++)
    {
        sum_rain += (min(left[i], right[i]) - arr[i]);
    }

    return sum_rain;
}

int main()
{
    int arr[] = {3, 1, 2, 4, 0, 1, 3, 2};
    int n = 8;

    int rain = trap_rain(arr, n);

    cout << rain << endl;

    return 0;
}