class Solution {
public:
    int solveMemo(int index, int endIndex, vector<int>& slices, int n, vector<vector<int>> &dp) {
        if(n == 0 || index > endIndex)
            return 0;
        
        if(dp[index][n] != -1)return dp[index][n];
        
        int pick = slices[index] + solveMemo(index+2, endIndex, slices, n-1, dp);
        int notPick = 0 + solveMemo(index+1, endIndex, slices, n, dp);
        return dp[index][n] = max(pick , notPick);
    }
	
	int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>> dp1(k, vector<int>(k, -1));
        int case1 = solveMemo(0, k-2, slices, k/3, dp1);

        vector<vector<int>> dp2(k, vector<int>(k, -1));
        int case2 = solveMemo(1, k-1, slices, k/3, dp2);
        return max(case1, case2);
    }
};