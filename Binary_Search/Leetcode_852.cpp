

/*
An array arr a mountain if the following properties hold:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array arr, return the index i such that 
arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ..
. > arr[arr.length - 1].

You must solve it in O(log(arr.length)) time complexity.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int low = 0, high = arr.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] < arr[mid + 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Solution func;
    cout << func.peakIndexInMountainArray(v) << '\n';
}