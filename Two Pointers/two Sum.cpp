class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        //          - Subtract current array element from target
        //   - Check if the above difference exists in HashMap
        //     - If YES, then return the current index and the value of the difference in HashMap
        //     - If NO, then store the current element as HashMap key and current index as its value
        // - Return empty array as a result if nums array iteration is completed in the above step
        map<int, int> umap;
        int difference;

        for (int i = 0; i < nums.size(); i++)
        {
            difference = target - nums.at(i);
            if (umap.find(difference) != umap.end())
            {
                vector<int> v{umap[difference], i};

                return v;
            }
            else
            {

                umap[nums.at(i)] = i;
            }
        }

        return vector<int>{};
    }
};