//#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
using namespace std;
#define ll long long int
#define pb push_back
#define read(x) \
   int x;       \
   cin >> x
#define fast_io                      \
   ios_base::sync_with_stdio(false); \
   cin.tie(NULL)
#define fr(i, a, b) for (int i = a; i < b; i++)

// Start
// How many operations needed to conver string 1 to string 2

// Given two strings s and t, return true if they are both one edit distance apart, otherwise return false.

// A string s is said to be one distance apart from a string t if you can:

// Insert exactly one character into s to get t.
// Delete exactly one character from s to get t.
// Replace exactly one character of s with a different character to get t.
// Input: s = "ab", t = "acb"
// Output: true
// Explanation: We can insert 'c' into s to get t.
// Input: s = "", t = ""
// Output: false
// Explanation: We cannot get t from s by only one step.
bool solve(string s, string t)
{
   string s1 = s.length() <= t.length() ? s : t;
   string s2 = s.length() > t.length() ? s : t;
   int k = 0;
   int count = 0;
   int i = 0;
   // BOTH STRING ARE NOT EQUAL
   if (s1.length() < s2.length())
   {
      // you will increase itr of strig s2 if elements are not equyal
      while (s1.length() && k < s2.length())
      {
         if (s1[i] == s2[k])
         {
            i++;
            k++;
            count++;
         }
         else
         {
            k++;
         }
      }
   }
   else
   {
      while (i < s1.length() and s2.length())
      {
         if (s1[i] == s2[k])
         {
            count++;
         }
         // both ptr should move on same speed
         i++;
         k++;
      }
   }

   if (s2.length() - 1 == count)
   {
      return true;
   }
   else
   {
      return false;
   }
}

int main()
{
   int t = 1;

   cin >> t;
   while (t--)
   {
      string s, t;
      cin >> s >> t;

      cout << solve(s, t);
   }

   return 0;
}