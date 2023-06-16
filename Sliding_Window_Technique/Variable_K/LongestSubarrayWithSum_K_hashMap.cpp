
// if array contains negative values, then this methid works.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lenOfLongSubarr(int a[], int n, int k)
    {
        int sum = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            if (sum == k)
            {
                ans = max(ans, i + 1);
            }
            if (mp.count(sum - k))
            {
                int j = mp[sum - k];
                ans = max(ans, i - j);
            }
            if (!mp.count(sum))
            {
                mp[sum] = i;
            }
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    int v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    Solution func;
    cout << func.lenOfLongSubarr(v, n, k) << '\n';
}