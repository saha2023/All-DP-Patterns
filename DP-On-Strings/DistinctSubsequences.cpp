// memoisation
class Solution {
private:
    unordered_map<int, unordered_map<int,int>>dp;
    int recc(string &s, string &t, int n, int m){
        if(m==0) return 1;
        if(n<m) return 0;
        if(dp[n][m]) return dp[n][m];
        int cnt = 0;
        if(s[n-1] == t[m-1]){
            cnt += recc(s, t, n-1, m-1);
            cnt += recc(s, t, n-1, m);
        }
        else cnt += recc(s, t, n-1, m);
        return dp[n][m] = cnt;
    }
public:
    int numDistinct(string s, string t) {
        return recc(s, t, s.size(), t.size());
    }
};

//dp
class Solution {
public:
    vector<vector<long long>>dp;
    int recc(string &s, string &t, int N, int M){
        for(int n=0;n<=N;n++){
            for(int m=0;m<=M;m++){
                if(n==0 or m==0){
                    if(m==0){
                        dp[n][m] = 1;
                        continue;
                    }
                    if(n==0){
                        dp[n][m] = 0;
                        continue;
                    } 
                }
                int left = 0, right = 0;
                if(s[n-1] == t[m-1]){
                    left = dp[n-1][m-1];
                }
                right = dp[n-1][m];
                dp[n][m] = (left+right)%1000000007;
            }
        }
        return dp[N][M];
    }


    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        dp.resize(n+1,vector<long long>(m+1,0));
        return recc(s, t, n, m);
    }
};

//space optimisation
class Solution {
public:
    vector<vector<long long>>dp;
    vector<int>prev, curr;
    int recc(string &s, string &t, int N, int M){
        for(int n=0;n<=N;n++){
            for(int m=0;m<=M;m++){
                if(n==0 or m==0){
                    if(m==0){
                        curr[m] = 1;
                        continue;
                    }
                    if(n==0){
                        curr[m] = 0;
                        continue;
                    } 
                }
                int left = 0, right = 0;
                if(s[n-1] == t[m-1]){
                    left = prev[m-1];
                }
                right = prev[m];
                curr[m] = (left+right)%1000000007;
            }
            prev = curr;
        }
        return curr[M];
    }


    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        dp.resize(n+1,vector<long long>(m+1,0));
        prev.resize(m+1, 0), curr.resize(m+1, 0);
        return recc(s, t, n, m);
    }
};