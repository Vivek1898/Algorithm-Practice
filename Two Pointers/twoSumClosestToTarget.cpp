class Solution
{
public:
    /**
     * @param nums: an integer array
     * @param target: An integer
     * @return: the difference between the sum and the target
     */
    int twoSumClosest(vector<int> &numbers, int target)
    {
        // write your code here

        sort(numbers.begin(), numbers.end());
        int abs = INT_MAX;
        int low = 0, high = numbers.size() - 1;
        int count = 0;
        while (low < high)
        {
            if (numbers[low] + numbers[high] == target)
            {
                return 0;
            }

            if (numbers[low] + numbers[high] < target)
            {
                abs = min(abs, target - (numbers[low] + numbers[high]));
                low++;
            }
            else if (numbers[low] + numbers[high] > target)
            {
                abs = min(abs, (numbers[low] + numbers[high]) - target);
                high--;
            }
        }
        return abs;
    }
};