
// Given an array of n integers ai. Let's say that a segment of this
// array a[l..r](1≤l≤r≤n) is good if there are no more than k unique
// elements on this segment. Your task is to find the number of
// different good segments.

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
typedef long long ll;
int cnt[N] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int L = 0, x = 0;
    ll sum = 0, mx = 0;
    for (int R = 0; R < n; R++)
    {
        cnt[a[R]]++;
        if (cnt[a[R]] == 1)
        {
            x++;
        }
        while (x > k)
        {
            cnt[a[L]]--;
            if (cnt[a[L]] == 0)
            {
                x--;
            }
            L++;
        }
        mx += (R - L + 1);
    }
    cout << mx << '\n';
}