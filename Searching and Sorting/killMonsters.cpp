// Description
// There are N monsters in front of you. To defeat the i-th of them you need an army of Ai soldiers, Bi of which will be killed during the battle.
// Now you want to know the minimal number of soldiers you need to recruit in order to kill all the monsters.
// You don't care about the order of battles: the only thing that matters is that none of the monsters will be left alive.

// Input Format

// The first line contains a number T (1 ≤ T ≤ 105) - the number of test cases. Then T lines follow.
// The first line of each test cases contains single integer N (1 ≤ N ≤ 105) - the number of monsters.
// Each of the next N lines contains two space-separated integers: Ai and Bi (1 ≤ Bi ≤ Ai ≤ 109) - the number of soldiers you need to defeat the i-th monster,  and the number of soldiers that will be killed in the battle against him.
// It is guaranteed that the sum of N over all test cases doesn't exceed 5 x 105.

// Output Format

// For each test case, output a single integer on a new line — the minimal number of soldiers that is sufficient to kill all the monsters.

// Sample Input 1
//  Copy

// 2
// 2
// 7 4
// 5 1
// 3
// 4 1
// 6 4
// 5 3

// Sample Output 1
//  Copy

// 8
// 10

// Note

#include <bits/stdc++.h>
#include <string>
#include <iostream>
using namespace std;
#define vv vector
#define st set
#define ll long long int
#define pb push_back
#define eb emplace_back
#define digits(k) floor(log10(k)) + 1;
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
#define fre(i, a, b) for (int i = a; i <= b; i++)
#define debug(x) cout << x << endl;
#define cout(x) cout << x << endl;
#define all(cont) cont.begin(), cont.end()
// bool isPowerOfTwo (int x)
// {
//   return x && (!(x&(x-1)));
// }
// int ispalindrome(int n)
// {
//     int a = 0;
//     int b = n;
//     while (n > 0)
//     {
//         a = a * 10 + (n % 10);
//         n = n / 10;
//     }
//     if (a == b)
//         return 1;
//     else
//         return 0;
// }
// bool isPrime(int number)
// {
//     if (number < 2)
//         return false;
//     if (number == 2)
//         return true;
//     if (number % 2 == 0)
//         return false;
//     for (int i = 3; (i * i) <= number; i += 2)
//     {
//         if (number % i == 0)
//             return false;
//     }
//     return true;
// }
// int reverse(int n)
// {
//     int rem, rev = 0;
//     while (n > 0)
//     {
//         rem = n % 10;
//         rev = rev * 10 + rem;
//         n = n / 10;
//     }
//     return rev;
// }
// int gcdNormal(int a, int b)
// {
//     return (b == 0 ? a : gcdNormal(b, a % b));
// }
// int lcm(int a, int b)
// {
//     return a * b / gcdNormal(a, b);
// }
// Binary Exponention
// int pow(int a, int b)
//{
// int ans=1;
// if (b == 0)
// return 1;
// int x = pow(a, b / 2);
//  if (b % 2)
// {
// ans = (x * x) % mod;
// ans = (ans * a) % mod;
//  }
//  else
// ans = (x * x) % mod;
//  return ans;
//}
// Start
void solve()
{
    read(n);
    pair<int, int> monster[n];
    fr(i, 0, n)
    {
        cin >> monster[i].first >> monster[i].second;
    }
    ll res = 0;
    ll curr = 0;

    sort(monster, monster + n, [&](pair<int, int> &a, pair<int, int> &b)
         { return a.first - a.second > b.first - b.second; });

    fr(i, 0, n)
    {
        res += max(0LL, monster[i].first - curr);
        curr = max(1LL * monster[i].first, curr);
        curr -= monster[i].second;
    }
    cout << res << endl;
}
signed main()
{
    boost;
#ifndef ONLINE_JUDGE
    freopen(
        "input.txt",
        "r",
        stdin);
    freopen(
        "output.txt",
        "w",
        stdout);
#endif
    // Start Here
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}