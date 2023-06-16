
// if array doesn't contain negative values, then this method is works.

#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int l = 0, r = 0;
    int n = a.size();
    long long sum = 0;
    int mx = 0;
    while (r < n)
    {
        sum += a[r];
        if (sum > k)
        {
            while (sum > k)
            {
                sum -= a[l];
                l++;
            }
        }
        if (sum == k)
        {
            mx = max(mx, r - l + 1);
        }
        r++;
    }
    return mx;
}

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
    cout << longestSubarrayWithSumK(v, k) << '\n';
}