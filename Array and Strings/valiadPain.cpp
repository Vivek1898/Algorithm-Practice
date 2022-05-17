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
    read(y);
    cout << y;
}

bool check(string A, int s, int e)
{
    while (s <= e)
    {
        if (A[s] != A[e])
        {
            return false;
        }
        s++;
        e--;
    }
    return true;
}

bool validPalindrome(string A)
{
    int s = 0;
    int e = A.size() - 1;

    while (s <= e)
    {
        if (A[s] != A[e])
        {
            /// 2 cases
            /// delete s  check for A[s+1...e]
            /// delete e check for A[s...e-1]
            if (check(A, s + 1, e) || check(A, s, e - 1))
            {
                return true;
            }
            else
            {
                /// after deleting 1 char we are unable to obtain a palin
                return false;
            }
        }
        s++;
        e--;
    }

    /// string is already palin
    return true;
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        bool ans = validPalindrome(s);
        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}