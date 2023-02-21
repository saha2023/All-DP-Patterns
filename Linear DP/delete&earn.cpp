class Solution {
private:
    unordered_map<int,int>mp;
    unordered_map<int,int>dp;
    int recc(vector<int>&nums, int idx){
        if(idx>=nums.size()) return 0;
        if(dp[idx]) return dp[idx];
        int nextIdx = upper_bound(nums.begin(), nums.end(), nums[idx]+1) - nums.begin();
        int pick = (mp[nums[idx]] * nums[idx]) + recc(nums, nextIdx);
        int notPick = recc(nums, idx+1);
        return dp[idx] = max(pick, notPick);
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        for(int it: nums) mp[it]++;
        sort(begin(nums), end(nums));
        return recc(nums, 0);
    }
};