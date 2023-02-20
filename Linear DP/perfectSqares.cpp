class Solution {
private:
unordered_map<int,int>mp;
int solve(int n){
    if(n<=0)return n==0;
    //condition
    int cnt = 1e9;
    if(mp[n]) return mp[n];
    for(int i=1;i*i<=n;i++){
        cnt = min(cnt,1 + solve(n-i*i));
    }
    return  mp[n] = cnt;
}
public:
    int numSquares(int n) {
        return solve(n)-1;
    }
};