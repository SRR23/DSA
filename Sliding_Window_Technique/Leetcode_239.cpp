#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int l = 0, r = 0;
        int n = nums.size();
        vector<int> v;
        deque<int> dq;
        while (r < n)
        {
            while (!dq.empty() && dq.back() < nums[r])
            {
                dq.pop_back();
            }
            dq.push_back(nums[r]);
            if (r < k - 1)
            {
                r++;
            }
            else
            {
                v.push_back(dq.front());
                if (dq.front() == nums[l])
                {
                    dq.pop_front();
                }
                l++;
                r++;
            }
        }
        return v;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Solution func;
    vector<int> ans = func.maxSlidingWindow(v, k);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << '\n';
}