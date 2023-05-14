
// 0-1 knapsack

#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, sum = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = sum; j >= 1; j--)
        {
            if (j == a[i])
            {
                dp[j] = 1;
            }
            if (j - a[i] >= 0)
            {
                dp[j] |= dp[j - a[i]];
            }
        }
    }
    vector<int> v;
    for (int i = 1; i <= sum; i++)
    {
        if (dp[i])
        {
            v.push_back(i);
        }
    }
    cout << v.size() << '\n';
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << '\n';
}