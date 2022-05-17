#include <bits/stdc++.h>
#include <string>
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

// A. String Building
// time limit per test2 seconds
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output
// You are given a string s. You have to determine whether it is possible to build the string s out of strings aa, aaa, bb and/or bbb by concatenating them. You can use the strings aa, aaa, bb and/or bbb any number of times and in any order.

// For example:

// aaaabbb can be built as aa + aa + bbb;
// bbaaaaabbb can be built as bb + aaa + aa + bbb;
// aaaaaa can be built as aa + aa + aa;
// abab cannot be built from aa, aaa, bb and/or bbb.
// Input
// The first line contains one integer t (1≤t≤1000) — the number of test cases.

// Each test case consists of one line containing the string s (1≤|s|≤50), consisting of characters a and/or b.

// Output
// For each test case, print YES if it is possible to build the string s. Otherwise, print NO.

// You may print each letter in any case (for example, YES, yes, Yes will all be recognized as positive answer, NO, no and nO will all be recognized as negative answer).

// Example
// inputCopy
// 8
// aaaabbb
// bbaaaaabbb
// aaaaaa
// abab
// a
// b
// aaaab
// bbaaa
// outputCopy
// YES
// YES
// YES
// NO
// NO
// NO
// NO
// YES
// Note
// The first four test cases of the example are described in the statement.
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        bool flag = true;

        fr(i, 0, s.size())
        {
            int cnt = 0;
            while (s[i] == s[i + 1] && i + 1 < s.size())
            {
                cnt++;
                i++;
            }

            if (cnt < 1)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}