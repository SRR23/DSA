
// Given an array of n integers. Print the values of di
// (1 <= i <= 10^6) where di
// denotes the count of numbers divisible by i in the array

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int mul[N], cnt[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            mul[i] += cnt[j];
        }
    }
    for (int i = 1; i < N; i++)
    {
        cout << mul[i] << " ";
    }
    cout << '\n';
}