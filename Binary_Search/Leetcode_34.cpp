
// Find First and Last Position of Element in Sorted Array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int Lower_Bound(vector<int> &nums, int low, int high, int val)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] < val)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;

        int first_position = Lower_Bound(nums, low, high, target);
        int last_position = Lower_Bound(nums, low, high, target + 1) - 1;

        if (first_position < nums.size() && nums[first_position] == target)
        {
            return {first_position, last_position};
        }
        else
        {
            return {-1, -1};
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Solution func;
    vector<int> ans = func.searchRange(v, m);
    cout << ans[0] << " " << ans[1] << '\n';
}