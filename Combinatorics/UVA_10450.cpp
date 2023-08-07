#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll fibo[52];
    fibo[0] = 1;
    fibo[1] = 2;
    for (int i = 2; i <= 51; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;

        cout << "Scenario #" << i << ":\n";
        cout << fibo[n] << "\n\n";
    }
}