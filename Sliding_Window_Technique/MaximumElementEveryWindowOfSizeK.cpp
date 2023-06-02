
/*
You are given an array of integers nums, there is a sliding 
window of size k which is moving from the very left of the 
array to the very right. You can only see the k numbers 
in the window. Each time the sliding window moves right by one
position.

Return the max sliding window.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k)
    {
        int l = 0, r = 0;
        deque<int> dq;
        vector<int> v;
        while (r < n)
        {
            while (!dq.empty() && dq.back() < arr[r])
            {
                dq.pop_back();
            }
            dq.push_back(arr[r]);
            if (r < k - 1)
            {
                r++;
            }
            else
            {
                v.push_back(dq.front());
                if (dq.front() == arr[l])
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
    vector<int> ans = func.max_of_subarrays(v, n, k);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << '\n';
}