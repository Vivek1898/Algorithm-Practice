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
string delete_vowels(string a){
  string temp = "";
    int l = a.length();
    for(int i = 0 ; i < l ; i++)
    {
        //If character is consonant
        if(a[i] != 'a' && a[i] != 'e' &&
           a[i] != 'i' && a[i] != 'o' &&
           a[i] != 'u' && a[i] != 'A' &&
           a[i] != 'E' && a[i] != 'O' &&
           a[i] != 'U'&& a[i] != 'I')
            temp += a[i];
    }
     
    return temp;
}
string change_case(string a)
{
    int l = a.length();
     
    for(int i = 0 ; i < l ; i++)
    {
        // If character is lowercase
        // change to uppercase
        if(a[i] >= 'a' && a[i] <= 'z')
            a[i] = a[i] - 32;
             
        // If character is uppercase
        // change to lowercase
        else if(a[i] >= 'A' && a[i] <= 'Z')
            a[i] = a[i] + 32;
    }
     
    return a;
     
}

string insert_hash(string a)
{
    string temp = "";
    int l = a.length();
     
    for(int i = 0 ; i < l ; i++)
    {
        // If character is not special
        if((a[i] >= 'a' && a[i] <= 'z') ||
           (a[i] >= 'A' && a[i] <= 'Z'))
            temp = temp + '#' + a[i];
        else
            temp = temp + a[i];
    }
     
    return temp;
     
}

void solve()
{
   reads(a);
   string b = delete_vowels(a);
    string c = change_case(b);
    string d = insert_hash(c);
     if(d=="")
      cout<<"-1"<<endl;
    else
    cout << d<<endl;

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