
/*

A peak element is an element that is strictly greater than its
neighbors.

Given a 0-indexed integer array nums, find a peak element, and
return its index. If the array contains multiple peaks, return
the index to any of the peaks.

In other words, an element is always considered to be strictly
greater than a neighbor that is outside the array.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        if ((nums.size() == 1) || (nums[0] > nums[1]))
        {
            return 0;
        }
        if (nums[nums.size() - 1] > nums[nums.size() - 2])
        {
            return nums.size() - 1;
        }
        int low = 0, high = nums.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] < nums[mid + 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Solution func;
    cout << func.findPeakElement(v) << '\n';
}