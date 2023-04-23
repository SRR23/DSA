
// Given an array of n integers ai. Let's say that the segment of
// this array a[l..r](1≤l≤r≤n) is good if the sum of elements on this
// segment is at least s. Your task is to find the shortest good
// segment.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ll s;
    cin >> n >> s;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int L = 0, mn = INT_MAX;
    ll sum = 0;
    for (int R = 0; R < n; R++)
    {
        sum += a[R];
        while (sum - a[L] >= s)
        {
            sum -= a[L];
            L++;
        }
        if (sum >= s)
        {
            mn = min(mn, R - L + 1);
        }
    }
    if (mn == INT_MAX)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << mn << '\n';
    }
}