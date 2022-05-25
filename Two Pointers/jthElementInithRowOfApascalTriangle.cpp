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
#define read(x) int x; cin >> x
#define reads(x) string x; cin >> x
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL)
#define fr(i, a, b) for (int i = a; i < b; i++)
#define fre(i, a, b) for (int i = a; i <= b; i++)
#define debug(x) cout<<x<<endl;
#define cout(x) cout<<x<<endl;
#define all(cont) cont.begin(), cont.end()
#define MOD 1000000007
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
 read(n);
   int x,y;
 fr(i,0,n){
  cin>>x>>y;

  ll  board[x+1][x+1];
 memset(board,0,sizeof(board));

board[0][0]=1;

for(ll row=1;row<=x;row++){
    board[row][0]=1;

    for(ll col=1;col<=row;col++){
        board[row][col]=((board[row-1][col]%MOD) + (board[row-1][col-1]%MOD))%MOD;

    }
}

cout<<board[x][y]<<endl;


 }


 

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
//Start Here
   int t = 1;
 cin >> t;
 while (t--)
{
solve();
}
return 0;
}