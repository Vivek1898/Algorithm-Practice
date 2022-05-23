class Solution
{
public:
  bool canJump(vector<int> &nums)
  {
    int n = nums.size();
    int goodPos = n - 1;
    // it over 2nd last position
    for (int i = n - 2; i >= 0; i--)
    {
      // Logic
      if (i + nums[i] >= goodPos)
      {
        goodPos = i;
      }
    }

    if (goodPos == 0)
      return true;
    else
      return false;
  }
};