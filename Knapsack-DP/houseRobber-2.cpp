class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if (n < 2) return n ? nums[0] : 0;
        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }
private:
    int robber(vector<int>& nums, int l, int r) {
        int pre2 = 0, pre1 = 0;
        for (int i = l; i <= r; i++) {
            int temp = max(pre2 + nums[i], pre1);
            pre2 = pre1;
            pre1 = temp;
        }
        return pre1;
    }
};