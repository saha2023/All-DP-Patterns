class Solution {
private:
    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
    int combination(string s,int idx, vector<string>sAns,vector<vector<string>>&ans){
        if(idx == s.size()){
            ans.push_back(sAns);
            return 1;
        }
        int count = 0;
        for(int wall = idx;wall<s.size();wall++){
            if(!isPalindrome(s,idx,wall)) continue;
            sAns.push_back(s.substr(idx,wall-idx+1));
            count += combination(s,wall+1,sAns,ans);
            sAns.pop_back();
        }
        return count;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        int total = combination(s,0,{},ans);
        cout<<total;
        return ans;
    }
};