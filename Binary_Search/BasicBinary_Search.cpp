#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v = {2, 6, 8, 10, 12, 15, 16, 18, 21};
    int low = 0;
    int high = v.size() - 1;
    int target = 18;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] == target)
        {
            ans = mid;
            break;
        }
        if (target > v[mid])
        {
            low = mid + 1;
        }
        else if (target < v[mid])
        {
            high = mid - 1;
        }
    }
    cout << ans << '\n';
}