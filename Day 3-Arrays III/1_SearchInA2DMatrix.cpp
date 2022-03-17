// https://leetcode.com/problems/search-a-2d-matrix/

// Method 1
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, h = m*n - 1;
        while(l<=h){
            int mid = (l+h)/2;
            int row = mid/m;
            int col = mid%m;
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]>target){
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return false;
    }
};


// Method 2
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int u = 0, d = n-1;
        int l = 0, r = m-1;
        int mid1, mid2;
        while(u<d) // binary search on rows
        {
            mid1 = (u+d)/2;
            if(target >= matrix[mid1][0]){
                u = mid1;
            }
            else{
                d = mid1;
            }
            if(u==d-1){
                if(matrix[d][0]<=target) u = d;
                break;
            }
        }
        
        while(l<=r) // binary search on columns
        {
            mid2 = (l+r)/2;
            if(matrix[u][mid2]>target){
                r = mid2-1;
            }
            else if(matrix[u][mid2]<target){
                l = mid2+1;
            }
            else{
                return true;
            }
        
        }
        if(matrix[0][0]!=target) return false; // edge case when number of rows = 1
        else return true;
    }
};