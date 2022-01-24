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
