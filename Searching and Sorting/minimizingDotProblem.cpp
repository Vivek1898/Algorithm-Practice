// Description

// You have given two vectors in N-dimension space, let it be V and W.
// V = <V1, V2, ..., VN>
// W = <W1, W2, ..., WN>

// The dot product is defined as V.W = V1 * W1 + V2 * W2 + ... + VN * WN.

// Now you are allowed to permute numbers in vectors, in order to minimize the dot product. Find the minimum dot product that you can get.

// See sample test cases for more explanation.

// Input Format

// The first line contains a number T (1 ≤ T ≤ 105) - the number of test cases. Then T lines follow.
// The first line of each test cases contains single integer N (1 ≤ N ≤ 105) - the number of dimensions.
// The second line contains N space-separated integers V1, V2, ..., VN (0 ≤ |Vi| ≤ 105) - the vector V.
// The third line contains N space-separated integers W1, W2, ..., WN (0 ≤ |Wi| ≤ 105) - the vector W.
// It is guaranteed that the sum of N over all test cases doesn't exceed 5 x 105.

// Output Format

// For each test case, output a single integer on a new line — the minimum dot product that you can obtain.

// Sample Input 1
//  Copy

// 2
// 2
// 2 3
// -1 4
// 3
// 2 4 -2
// 5 0 -7

// Sample Output 1
//  Copy

// 5
// -38

// Note

// Explanation 1:
// Consider all possible combinations.

// V = <2, 3>, W = <-1, 4>: V.W = 10
// V = <2, 3>, W = <4, -1>: V.W = 5
// V = <3, 2>, W = <-1, 4>: V.W = 5
// V = <3, 2>, W = <4, -1>: V.W = 10
// The minimum dot product that we can get is 5.

// Explanation 2:
// We can get minimum dot product when V = <2, 4, -2> and W = <0, -7, 5>, i.e., V.W = -38.

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
    int v[n], w[n];

    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        cin >> w[i];

    sort(v, v + n);
    sort(w, w + n);

    ll ans = 0;

    for (int i = 0, j = n - 1; i < n; i++, j--)
        ans += 1LL * v[i] * w[j];

    cout << ans << "\n";
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