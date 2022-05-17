class Solution
{
public:
    int maxOperations(vector<int> &numbers, int target)
    {
        sort(numbers.begin(), numbers.end());
        vector<int> ans;
        int low = 0, high = numbers.size() - 1;
        int count = 0;
        while (low < high)
        {
            if (numbers[low] + numbers[high] == target)
            {
                count++;
                low++;
                high--;
            }

            if (numbers[low] + numbers[high] < target)
                low++;
            else if (numbers[low] + numbers[high] > target)
                high--;
        }
        return count;
    }
};