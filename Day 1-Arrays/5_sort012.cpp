// https://leetcode.com/problems/sort-colors/

// Method 1
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zero = 0, one = 0, two = 0;
        for(int i = 0; i < n ; i++){
            if(nums[i]==0) zero++;
            if(nums[i]==1) one++;
            if(nums[i]==2) two++;
        }
        for(int i  = 0; i < zero; i++){
            nums[i] = 0;
        }   
        for(int i  = zero; i < zero+one ; i++){
            nums[i] = 1;
        }   
        for(int i  = zero+one; i < zero+one+two; i++){
            nums[i] = 2;
        }   
    }
};

// Method 2
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        int low = 0, mid = 0, high = n-1;
        
        while(mid<=high){  // If we find mid element
                                // to be 1, leave it as it is       (bcz that's where its place is XD)
                                // to be 0, swap it with low index  (bcz that's where its place is XD)
                                // to be 2, swap it with high index (bcz that's where its place is XD)
            
            if(nums[mid]==0)
                swap(nums[low++],nums[mid++]); 
            
            else if(nums[mid]==1)
                mid++;
            
            else if(nums[mid]==2)
                swap(nums[mid],nums[high--]);
        }
    }
};