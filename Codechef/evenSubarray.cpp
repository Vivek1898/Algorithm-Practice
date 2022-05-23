#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
using namespace std;
#define ll long long int
#define pb push_back
#define read(x) \
    int x;      \
    cin >> x
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define fr(i, a, b) for (int i = a; i < b; i += 2)
#define fre(i, a, b) for (int i = a; i <= b; i += 2)
// Start
void solve()
{
    read(n);
    fr(j, 2, 2 * n + 1)
    {
        cout << j << " ";
    }
    cout << "\n";
    fre(i, 3, 2 * n + 1)
    {
        cout << i << " ";
    }
    cout << "\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}