// https://leetcode.com/problems/next-permutation/

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size(), i;
        multiset<int> s;
        s.insert(nums[n - 1]);
        for (i = n - 2; i >= 0; i--){
            s.insert(nums[i]);
            if (nums[i] < nums[i + 1]) break;
        }

        if (i < 0){
            sort(nums.begin(), nums.end());
        }
        else{
            auto it = upper_bound(s.begin(), s.end(), nums[i]);
            int x = *it;
            nums[i] = x;
            s.erase(it);
            for (auto itr : s){
                nums[++i] = itr;
            }
        }
    }
};