#include <bits/stdc++.h>
#include <string>
#include <iostream>
using namespace std;
#define ll long long int
#define pb push_back
#define read(x) \
    int x;      \
    cin >> x
#define reads(x) \
    string x;    \
    cin >> x
#define boost                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define fr(i, a, b) for (int i = a; i < b; i++)

int ispalindrome(int n)
{
    int a = 0;
    int b = n;
    while (n > 0)
    {
        a = a * 10 + (n % 10);
        n = n / 10;
    }
    if (a == b)
        return 1;
    else
        return 0;
}
bool isPrime(int number)
{
    if (number < 2)
        return false;
    if (number == 2)
        return true;
    if (number % 2 == 0)
        return false;
    for (int i = 3; (i * i) <= number; i += 2)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}
int reverse(int n)
{
    int rem, rev = 0;
    while (n > 0)
    {
        rem = n % 10;
        rev = rev * 10 + rem;
        n = n / 10;
    }
    return rev;
}
// Start
// to make palindromic indices array
// frequencies
// poisition of each and every element
void solve()
{
    reads(s1);
    reads(s2);

    int ans = 0;
    // 1 base indexing
    // Ods  [pos ]  check
    for (int i = 0; i < s1.length(); i = i + 2)
    {
        if (s1[i] != s2[i])
        {
            // filling req positions
            while (i < s1.length() and s1[i] != s2[i])
            {
                i += 2;
            }
            // string ended
            ans++;
        }
    }

    for (int i = 1; i < s1.length(); i = i + 2)
    {
        if (s1[i] != s2[i])
        {
            while (i < s1.length() and s1[i] != s2[i])
            {
                i += 2;
            }
            ans++;
        }
    }
    cout << ans << endl;
}
int main()
{
    boost;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}