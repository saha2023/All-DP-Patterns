class Solution {
private:
const static int mod = 1e9+7;
    vector<int>dp;
    int recc(int n){
        if(n==0) return 1;
        if(n<=2) return n;
        if(dp[n] != -1) return dp[n];
        int cnt = 0;
        cnt = (2*recc(n-1)%mod + recc(n-3)%mod)%mod;
        return dp[n] = cnt;
    }
public:
    int numTilings(int n) {
        dp.resize(n+1, -1);
        return recc(n);
    }
};