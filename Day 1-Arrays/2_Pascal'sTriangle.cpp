// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i<numRows; i++){
            vector<int> currRow(i+1,1);
            for(int j = 0; j<i+1; j++){
                if(!(j==0 or j==i)){
                    currRow[j] = ans[i-1][j-1] + ans[i-1][j];
                }
            }
            ans.push_back(currRow);
        }
        return ans;
    }
};