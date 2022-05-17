// https://www.interviewbit.com/problems/distinct-numbers-in-window/
// Distinct Numbers in Window

// Medium

// 141

// 8
// Asked In:
// Amazon
// Problem Description

// You are given an array of N integers, A1, A2 ,..., AN and an integer B. Return the of count of distinct numbers in all windows of size B.

// Formally, return an array of size N-B+1 where i'th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,..., Ai+B-1.

// NOTE:  if B > N, return an empty array.

// Input Format
// First argument is an integer array A

// Second argument is an integer B.

// Output Format
// Return an integer array.

// Example Input
// Input 1:

//  A = [1, 2, 1, 3, 4, 3]
//  B = 3
// Input 2:

//  A = [1, 1, 2, 2]
//  B = 1

// Example Output
// Output 1:

//  [2, 3, 3, 2]
// Output 2:

//  [1, 1, 1, 1]

// Example Explanation
// Explanation 1:

//  A=[1, 2, 1, 3, 4, 3] and B = 3
//  All windows of size B are
//  [1, 2, 1]
//  [2, 1, 3]
//  [1, 3, 4]
//  [3, 4, 3]
//  So, we return an array [2, 3, 3, 2].
// Explanation 2:

//  Window size is 1, so the output array is [1, 1, 1, 1].

vector<int> Solution::dNums(vector<int> &a, int win)
{
    vector<int> res;
    if (a.size() < win)
        return res;
    unordered_map<int, int> m;
    for (int i = 0; i < win; i++)
    {
        m[a[i]]++;
    }
    res.push_back(m.size());
    int j = 0; // removing start element of prev window
               // increasing linearly
    for (int i = win; i < a.size(); i++)
    {
        m[a[i]]++;
        m[a[j]]--;

        if (m[a[j]] == 0)
        {
            m.erase(a[j]);
        }
        res.push_back(m.size());
        j++;
    }
    return res;
}
