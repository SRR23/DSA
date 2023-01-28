#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int low = 1;
    int high = n;
    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid * mid <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        if (mid * mid > n)
        {
            high = mid - 1;
        }
        else if (mid * mid < n)
        {
            low = mid + 1;
        }
    }
    cout << ans << '\n';
}