// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
// First negative integer in every window of size k
// Easy Accuracy: 54.27% Submissions: 30247 Points: 2
// Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

// Example 1:

// Input :
// N = 5
// A[] = {-8, 2, 3, -6, 10}
// K = 2
// Output :
// -8 0 -6 -6
// Explanation :
// First negative integer for each window of size k
// {-8, 2} = -8
// {2, 3} = 0 (does not contain a negative integer)
// {3, -6} = -6
// {-6, 10} = -6

// Example 2:
// Input :
// N = 8
// A[] = {12, -1, -7, 8, -15, 30, 16, 28}
// K = 3
// Output :
// -1 -1 -7 -15 -15 0

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function printFirstNegativeInteger() which takes the array A[], its size N and an integer K as inputs and returns the first negative number in every window of size K starting from the first till the end. If a window does not contain a negative integer , then return 0 for that window.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(K)

// Constraints:
// 1 <= N <= 105
// -105 <= A[i] <= 105
// 1 <= K <= N

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{

    deque<long long int> dq;
    vector<long long> ans;

    for (int i = 0; i < K; i++)
    {
        // processing first window of size k
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }

    // storing ans of 1st k size window
    if (dq.size() > 0)
    {
        ans.push_back(A[dq.front()]);
    }
    else
        ans.push_back(0);
    // Process for remaining window
    for (int i = K; i < N; i++)
    {
        // removal shifting window
        // checking for if that element is present in current window or not
        // if present then do nothing else pop
        if ((!dq.empty() && (i - K) >= dq.front()))
        {
            dq.pop_front();
        }

        // addition
        if (A[i] < 0)
        {
            dq.push_back(i);
        }

        if (dq.size() > 0)
        {
            ans.push_back(A[dq.front()]);
        }
        else
            ans.push_back(0);
    }
    return ans;
}