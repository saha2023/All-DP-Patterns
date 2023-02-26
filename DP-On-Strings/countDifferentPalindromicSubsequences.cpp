class Solution {
private:
    using ll = long long;
    vector<vector<int>>dp;
    ll recc(string &s, int si, int ei){
        if(si>ei) return 0;
        if(si==ei) return 1;
        if(dp[si][ei] != -1) return dp[si][ei];
        ll cnt = 0;
        if(s[si]==s[ei]){
            cnt = (2*recc(s, si+1, ei-1))%1000000007;
            int left = si+1, right = ei-1;
            while(left <= right and s[si] != s[left]) left++;
            while(left <= right and s[ei] != s[right]) right--;
            if(left>right){
                // there are no charecter in between same as the ends
                cnt = (cnt%1000000007 + 2)%1000000007;
            }
            else if(left == right){
                // there is a single character similar to the ends
                cnt = (cnt%1000000007 + 1)%1000000007;
            }
            else{
                cnt = cnt % 1000000007 - (recc(s, left+1, right-1)%1000000007)%1000000007;
            }
        }
        else cnt = recc(s, si+1, ei) + recc(s, si, ei-1) - recc(s, si+1, ei-1);
        return dp[si][ei] = cnt < 0 ? cnt + 1000000007 : cnt%1000000007;
    }
public:
    int countPalindromicSubsequences(string s) {
        dp.resize(size(s)+1, vector<int>(size(s)+1, -1));
        return recc(s, 0, size(s)-1);
    }
};