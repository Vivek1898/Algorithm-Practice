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
#define fr(i, a, b) for (int i = a; i < b; i++)
// Start
void solve()
{

    read(n);
    read(mean);
    vector<int> v(n);
    int mini = INT_MAX;
    int maxi = INT_MIN;
    fr(i, 0, n)
    {
        cin >> v[i];
        mini = min(mini, v[i]);
        maxi = max(maxi, v[i]);
    }
    string ans = (mean >= mini and mean <= maxi) ? "YES" : "NO";
    cout << ans << endl;
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