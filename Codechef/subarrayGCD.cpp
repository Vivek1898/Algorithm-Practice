// Problem
// Read problems statements in English, Mandarin Chinese and Russian as well.
// Given an array A1,A2...AN, you have to print the size of the largest contiguous subarray such that GCD of all integers in that subarray is 1.
// Formally,
// For a subarray Ai,Ai+1...Aj where 1 ≤ i < j ≤ N to be valid: GCD(Ai,Ai+1...Aj) should be 1. You have to print the size of the largest valid subarray.

// If no valid subarray exists, output -1.

// Note:A single element is not considered as a subarray according to the definition of this problem.

// Note: Use scanf/print instead of cin/cout. Large input files.
// Input
// First line contains T, the number of testcases. Each testcase consists of N in one line followed by N integers in the next line.

// Output
// For each testcase, print the required answer in one line.

// Constraints
// 1 ≤ T ≤ 10
// 2 ≤ N ≤ 105
// 1 ≤ Ai ≤ 105
// Sample 1:
// Input
// Output
// 2
// 2
// 7 2
// 3
// 2 2 4
// 2
// -1
// Explanation:
// Example case 1.GCD(2,7)=1. So the subarray [A1,A2] is valid.
// Example case 2.No subarray satisfies.
#include <bits/stdc++.h>
#include <string>
#include <iostream>
using namespace std;
#define ll long long int
#define pb push_back
#define read(x) int x; cin >> x
#define reads(x) string x; cin >> x
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL)
#define fr(i, a, b) for (int i = a; i < b; i++)
#define fre(i, a, b) for (int i = a; i <= b; i++)
#define debug(x) cout<<x<<endl;
#define cout(x) cout<<x<<endl;
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
int gcdNormal(int a, int b)
{
    return (b == 0 ? a : gcdNormal(b, a % b));
}
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
//ans = (x * x) % mod;
// ans = (ans * a) % mod;
//  }
//  else
//ans = (x * x) % mod;
//  return ans;
//}
//Start
void solve()
{
    int potenialAns=0,x;
read(n);
fr(i,0,n){
    cin>>x;
    potenialAns=__gcd(potenialAns,x);
}
if(potenialAns==1){cout<<n<<endl;}
else cout(-1);

}
signed main()
{
boost;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
   int t = 1;
 cin >> t;
 while (t--)
{
solve();
}
return 0;
}