
// Given an integer N, you have to prime factorize N! (factorial N)

#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 1;
bool is_prime[N];
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 2; i < N; i++)
    {
        is_prime[i] = true;
    }
    for (int i = 2; i * i < N; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j < N; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i < N; i++)
    {
        if (is_prime[i])
        {
            v.push_back(i);
        }
    }

    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        int n;
        cin >> n;
        cout << "Case " << k << ": " << n << " "
             << "= ";
        for (int j = 0; j < v.size(); j++)
        {
            int prime = v[j], cnt = 0;
            for (int i = 1; i <= n; i++)
            {
                int nmbr = i;
                while (nmbr % prime == 0)
                {
                    cnt++;
                    nmbr /= prime;
                }
            }
            if (cnt > 0)
            {
                if (prime != 2)
                {
                    cout << " * ";
                }
                cout << prime << " "
                     << "(" << cnt << ")";
            }
        }
        cout << '\n';
    }
}