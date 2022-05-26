// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int maxChars (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << maxChars (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int maxChars (string s)
{
    // your code here
    unordered_map<char,pair<int,int>>m;
    int mx=0;
    for(int i=0;i<s.length();i++){
        m[s[i]].first++;
        if(  m[s[i]].first>1){
            mx=max(mx,abs(  m[s[i]].second-i));
        }else{
             m[s[i]].second=i;
        }
    }
    return mx-1;
}