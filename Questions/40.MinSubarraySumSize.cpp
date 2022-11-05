#include <iostream>
using namespace std;
int minSubarray(int arr[], int x, int n)
{
    int sum = 0, ans = INT_MAX, minLength = n + 1;
    int start = 0, end = 0;
    while (end < n)
    {
        while (sum <= x && end < n)
        {
            sum += arr[end++];
        }
        while (sum > x && start < n)
        {
            if (end - start < minLength)
            {
                minLength = end - start;
            }

            sum -= arr[start++];
        }
    }
    return minLength;
}
int main()
{
    int arr[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n = 6;
    int minLenth = minSubarray(arr, x, n);
    if (minLenth == n + 1)
        cout << "no such subarray exits" << endl;
    else
        cout << "The length of min subarray sum is: " << minLenth;
    return 0;
}