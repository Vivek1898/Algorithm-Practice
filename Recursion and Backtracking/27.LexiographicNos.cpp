class Solution
{
public:
    void helper(int input, vector<int> &res, int n)
    {

        if (input > n)
            return;

        res.push_back(input);

        for (int i = 0; i < 10; i++)
        {
            helper(input * 10 + i, res, n);
        }
    }

    vector<int> lexicalOrder(int n)
    {
        vector<int> res;
        for (int i = 1; i < 10; i++)
        {
            helper(i, res, n);
        }
        return res;
    }
};