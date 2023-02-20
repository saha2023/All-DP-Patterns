//Buy & Sell Stock -1
class Solution {
public:
    int maxtotalMoneyIhave(vector<int>& prices) {
        int n = prices.size();
        int sell = -1e9;
        int buy = 1e9;
        int totalMoneyIhave = 0;
        for(int i=0;i<n;i++){
            sell = prices[i];
            buy = min(buy, prices[i]);
            totalMoneyIhave = max(totalMoneyIhave, sell-buy);
        }
        return totalMoneyIhave;
    }
};

//Buy & Sell Stock -2
class Solution {
private:
    enum state {buy, sell};
    int recc(vector<int>& prices, int idx, state s){
        if(idx == prices.size()) return 0;
        int totalMoney = 0;
        if(s == buy){
            totalMoney += max(recc(prices, idx+1, sell) - prices[idx], recc(prices, idx+1, buy));
        }
        if(s == sell){
            totalMoney += max(recc(prices, idx+1, buy) + prices[idx], recc(prices, idx+1, sell));
        }
        return totalMoney;
    }
public:
    int maxtotalMoneyIhave(vector<int>& prices) {
        return recc(prices, 0, buy);
    }
};

//Buy and sell stock-3
class Solution {
private:
    int getAns(vector<int>& Arr, int n, int ind, int buy, int cap, vector<vector<vector<int>>>& dp ){

        if(ind==n || cap==0) return 0; //base case
        
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
            
        int totalMoneyIhave = 0;
        
        if(buy==0){// We can buy the stock
            totalMoneyIhave = max(0 + getAns(Arr,n,ind+1,0,cap,dp),  getAns(Arr,n,ind+1,1,cap,dp)-Arr[ind]);
        }
        
        if(buy==1){// We can sell the stock
            totalMoneyIhave = max(0 + getAns(Arr,n,ind+1,1,cap,dp), Arr[ind] + getAns(Arr,n,ind+1,0,cap-1,dp));
        }
        return dp[ind][buy][cap] = totalMoneyIhave;
    }    
public:
int maxProfit(vector<int>& prices) {   
        int n = prices.size();
        // Creating a 3d - dp of size [n][2][3]
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2,vector<int>(3,-1)));
        return getAns(prices,n,0,0,2,dp);
    }
};