class Solution {
public:
    int dp[102][102];
    int palindrome(string &s, int i, int j){
        int cnt = 0;
        while(i<j){
            if(s[i]!=s[j]) cnt++;
            i++, j--;
        }
        return cnt;
    }
    int solve(int i, string &s, int k){
        if(i==s.length()){
            if(k==0) return 0;
            else return 1e9;
        }
        if(k==0) return 1e9;
        if(dp[i][k]!=-1) return dp[i][k];
        int minChanges = 1e9;
        for(int cut = i+1; cut<=s.length(); cut++){
            int changes = palindrome(s, i, cut-1);
			minChanges = min(minChanges, changes + solve(cut, s, k-1));
        }
        return dp[i][k] = minChanges;
    }
    int palindromePartition(string s, int k) {
        memset(dp, -1, sizeof dp);
        return solve(0, s, k);
    }
};