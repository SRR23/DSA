
// Given an array of n integers ai. Let's say that the segment of
// this array a[l..r](1≤l≤r≤n) is good if the sum of elements on this
// segment is at most s. Your task is to find the number of good
// segments.

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
    int L = 0;
    ll sum = 0, cnt = 0;
    for (int R = 0; R < n; R++)
    {
        sum += a[R];
        while (sum > s)
        {
            sum -= a[L];
            L++;
        }
        cnt += (R - L + 1);
    }
    cout << cnt << '\n';
}