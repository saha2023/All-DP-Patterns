//combination method
//2Dp ->not space optimised
class Solution {
private:
    unordered_map<int,unordered_map<int,int>>mp;
    int recc(vector<int>&coins, int tar, int idx){
        if(tar <= 0 or idx >= coins.size()) return tar==0 ? 1 : 1e9;
        int cnt = 1e9;
        if(mp[tar][idx]) return mp[tar][idx];
        for(int i=idx;i<coins.size();i++){
            if(tar-coins[i]<0) continue;
            cnt = min(cnt, recc(coins, tar-coins[i], idx)+1);
        }
        return mp[tar][idx] = cnt;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int res = recc(coins, amount, 0);
        return res == 1e9 ? -1 : res-1;
    }
};


//permutation method 
//1DP ->Optimised
class Solution {
private:
    unordered_map<int,int>mp;
    int recc(vector<int>&coins, int tar){
        if(tar <= 0) return tar==0 ? 1 : 1e9;
        int cnt = 1e9;
        if(mp[tar]) return mp[tar];
        for(int i=0;i<coins.size();i++){
            if(tar-coins[i]<0) continue;
            cnt = min(cnt, recc(coins, tar-coins[i])+1);
        }
        return mp[tar] = cnt;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int res = recc(coins, amount);
        return res == 1e9 ? -1 : res-1;
    }
};