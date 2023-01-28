#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v = {1, 2, 3, 3, 3, 4, 5, 6};
    int low = 0;
    int high = v.size() - 1;
    int target = 7;
    int lwr_bound = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] == target)
        {
            lwr_bound = mid;
            high = mid - 1;
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

    int upr_bound = -1;
    low = 0;
    high = v.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] == target)
        {
            upr_bound = mid;
            low = mid + 1;
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
    cout << lwr_bound << " " << upr_bound << '\n';
}