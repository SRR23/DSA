#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         unordered_map<int, int> mp;
//         for(int i = 0; i < nums.size(); i++) {
//             if(mp.count(nums[i])){
//                 int diff = abs(mp[nums[i]] - i);
//                 if (diff <= k)return true;
//             }
//             mp[nums[i]] = i;
//         }
//         return false;
//     }
// };

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int l = 0, r = 0;
        int n = nums.size();
        if (k < n)
        {
            k++;
        }
        else
        {
            k = n;
        }

        set<int> s;
        while (r < n)
        {
            s.insert(nums[r]);
            if (r < k - 1)
            {
                r++;
            }
            else
            {
                if (s.size() < k)
                {
                    return true;
                }
                // if (s.size() == k)
                // {
                //     s.erase(nums[l]);
                // }
                s.erase(nums[l]);
                l++;
                r++;
            }
        }
        return false;
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
    if (func.containsNearbyDuplicate(v, k))
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }
}