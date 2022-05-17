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
// Start
// to make palindromic indices array
// frequencies
// poisition of each and every element
void solve()
{
    reads(str);
    int len = str.length();
    int pal[len];
    int count[26]{0}; // Initialize all with zero

    vector<vector<int>> positions(26);
    // 2 d array

    fr(i, 0, len)
    {
        // we are storing how many times that element occurs
        //  a ato 0 idx
        //  b at 1 idx
        count[str[i] - 'a']++;

        // we are storing all positions of that element
        //  a at 0 idx ->{1,2,3,4}
        positions[str[i] - 'a'].pb(i);
    }
    int startIdx = 0;
    int oddCount = 0;
    char oddCharacter = 0;

    fr(i, 0, 26)
    {
        if (count[i] % 2 == 1)
        {
            oddCount++;
            oddCharacter = i;
        }
    }
    //>2 odd element never form palidrome
    if (oddCount >= 2)
    {
        cout << -1 << endl;
        return;
    }

    fr(i, 0, 26)
    {
        int currCount = count[i];

        if (currCount % 2 == 0)
        {

            // Building palindromic indices array

            int currLen = positions[i].size();
            for (int j = 0; j < currLen; j += 2)
            {
                pal[startIdx] = positions[i][j];
                pal[len - startIdx - 1] = positions[i][j + 1];
                startIdx++;
            }
        }
    }

    if (oddCount == 1)
    {
        for (int j = 0; j < positions[oddCharacter].size(); j++)
        {
            pal[startIdx++] = positions[oddCharacter][j];
        }
    }

    fr(j, 0, len)
    {
        cout << pal[j] + 1 << " ";
    }

    cout << endl;
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