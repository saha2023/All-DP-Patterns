// !!!!!!!!! MEMOISATION !!!!!!!!!!!!!!!
class Solution {
private:
    int *dp;
    int recc(string &s, int n){
        if(n==0) return dp[n] = 1;
        if(dp[n] != -1) return dp[n];
        int count = 0;
        //single digit check
        if(s[n-1] != '0')
            count += recc(s, n-1);

        //double digit check
        if(n >= 2 and stoi(s.substr(n-2,2)) >= 10 and stoi(s.substr(n-2, 2)) <= 26)
            count += recc(s, n-2);
        return dp[n] = count;
    }
public:
    int numDecodings(string s) {
        int n = size(s);
        dp = new int[n+1];
        fill(dp, dp+n+1, -1);
        return recc(s, n);
    }
};


// !!!!!!!!!!!!!! TABULISATION !!!!!!!!!!!!!!!!!!!!!!!!!
class Solution {
private:
    int *dp;
    int recc(string &s, int N){
        for(int n=0;n<=N;n++){
            if(n==0){
                dp[n] = 1;
                continue;
            }
            // if(dp[n] != -1) return dp[n];
            int count = 0;
            //single digit check
            if(s[n-1] != '0')
                count += dp[n-1];

            //double digit check
            if(n >= 2 and stoi(s.substr(n-2,2)) >= 10 and stoi(s.substr(n-2, 2)) <= 26)
                count += dp[n-2];
            dp[n] = count;
        }
        return dp[N];
    }
public:
    int numDecodings(string s) {
        int n = size(s);
        dp = new int[n+1];
        fill(dp, dp+n+1, 0);
        return recc(s, n);
    }
};


// !!!!!!!!!!! SPACE OPTIMISATIOM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
class Solution {
private:
    int recc(string &s, int N){
        int dp2 = 0, dp1 = 0, dp = 0;
        for(int n=0;n<=N;n++){
            if(n==0){
                dp = 1;
                dp2 = dp1;
                dp1 = dp;
                continue;
            }
            // if(dp[n] != -1) return dp[n];
            int count = 0;
            //single digit check
            if(s[n-1] != '0')
                count += dp1;

            //double digit check
            if(n >= 2 and stoi(s.substr(n-2,2)) >= 10 and stoi(s.substr(n-2, 2)) <= 26)
                count += dp2;
            dp = count;
            dp2 = dp1;
            dp1 = dp;
        }
        return dp;
    }
public:
    int numDecodings(string s) {
        int n = size(s);
        return recc(s, n);
    }
};