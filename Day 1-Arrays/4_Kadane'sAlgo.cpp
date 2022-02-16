// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0],sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            ans = max(sum,ans);
            if(sum<0) sum = 0; // if sum becomes negative, 
                               // there is no use of continuing that subarray
        }
        return ans;
    }
};