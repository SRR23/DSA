
/*
Given an array A[] of size N and a positive integer K, 
find the first negative integer for each and every window
(contiguous subarray) of size K.
*/

#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{
    long long int l = 0, r = 0;
    queue<long long> q;
    vector<long long> v;
    while (r < N)
    {
        if (A[r] < 0)
        {
            q.push(A[r]);
        }
        if (r < K - 1)
        {
            r++;
        }
        else
        {
            if (q.empty())
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(q.front());
            }
            if (A[l] < 0)
            {
                q.pop();
            }
            l++;
            r++;
        }
    }
    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int n, k;
    cin >> n;
    long long int v[n];
    for (long long int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cin >> k;
    vector<long long> ans = printFirstNegativeInteger(v, n, k);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << '\n';
}