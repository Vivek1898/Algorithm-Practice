class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            q.push(i);
        }
        int count = 0;
        while (q.size() > 1)
        {
            int val = q.front();
            q.pop();
            count++;
            if (count == k)
            {
                count = 0;
            }
            else
            {
                q.push(val);
            }
        }
        return q.front() + 1;
    }
};

// Indexing  Approach

class Solution
{
public:
    int helper(int n, int k)
    {
        if (n == 1)
        {
            // Return index
            return 0;
        }
        return (helper(n - 1, k) + k) % n;
    }
    int findTheWinner(int n, int k)
    {

        int ans = helper(n, k);
        return ans + 1;
    }
};