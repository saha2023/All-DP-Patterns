class Solution {
private:
    unordered_map<int,int>mp;
    int recc(int n){
        if(n==1) return 1;
        int prod = 1;
        if(mp[n]) return mp[n];
        for(int i=1;i<=n;i++){
            prod = max(prod, i * recc(n-i));
        }
        return mp[n] = prod;
    }
public:
    int integerBreak(int n) {
        if(n<=3) return n-1;
        return recc(n);
    }
};