class Solution
{
public:
    /**
     * @param nums: an array of integer
     * @param target: An integer
     * @return: An integer
     */
    int twoSum6(vector<int> &numbers, int target)
    {
        // write your code here

        sort(numbers.begin(), numbers.end());
        vector<int> ans;
        int low = 0, high = numbers.size() - 1;
        int count = 0;
        while (low < high)
        {
            if (low > 0 and numbers[low - 1] == numbers[low])
            {
                low++;
                continue;
            }
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