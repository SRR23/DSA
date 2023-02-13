
// Each of them has a single number written on it — either 1 or 2.
// You will need to put all the tiles from the bag in a sequence, in any order
// you wish. We will then compute the sums of all prefixes in the sequence,
// and then count how many of these sums are prime numbers. If you want to keep
// the prize, you will need to maximize the number of primes you get.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v, v1;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.rbegin(), v.rend());
    if (v[0] == v[v.size() - 1])
    {
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << '\n';
    }
    else
    {
        v1.push_back(2);
        v1.push_back(1);
        for (int i = 1; i < v.size() - 1; i++)
        {
            v1.push_back(v[i]);
        }
        for (auto it : v1)
        {
            cout << it << " ";
        }
        cout << '\n';
    }
}