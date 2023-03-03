class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.rbegin(), s.rend()); // sort descending
        int best = 0; // best result
        int prefixSum = 0; // sum of all satisfaction from biggest to s[i]
        int cur = 0; //result after each iteration
        for (int i = 0; i < s.size(); i++) {
            prefixSum += s[i]; // add this to prefixSum
            cur += prefixSum; // cur so far (we add +1 time to all previous)
            best = max(best, cur); // is cur better?
        }
        return best;
    }
};