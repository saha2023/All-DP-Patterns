class Solution {
public:
//maximise the total sum of common subsequence
    unordered_map<int, unordered_map<int,int>>dp;
	int sum(int i,int j,string& s1,string& s2){
		if(i==0 or j==0) return 0;
        if (dp[i][j])return dp[i][j];
		if(s1[i-1]==s2[j-1]) return 2 * s1[i-1]+sum(i-1,j-1,s1,s2);
		return dp[i][j] = max(sum(i-1,j,s1,s2),sum(i,j-1,s1,s2));
	}

	int minimumDeleteSum(string s1, string s2) {
		int n=s1.size();
		int m=s2.size();
		int sum1=0,sum2=0;
		for(auto i:s1) sum1+=i;
		for(auto i:s2) sum2+=i;
		return (sum1+sum2) - sum(n,m,s1,s2);
	}
};