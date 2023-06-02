
/* 
Given an array of integers Arr of size N and a number K. 
Return the maximum sum of a subarray of size K
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long maximumSumSubarray(int K, vector<int> &Arr, int N)
    {
        int l = 0, r = 0;
        long sum = 0, mx = 0;
        while (r < N)
        {
            sum += Arr[r];
            if (r < K - 1)
            {
                r++;
            }
            else
            {
                mx = max(mx, sum);
                sum -= Arr[l];
                l++;
                r++;
            }
        }
        return mx;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Solution func;
    cout << func.maximumSumSubarray(k, v, n) << '\n';
}