class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()>t.size()) return false;
        int i = 0;
        for(char c: t) i += s[i] == c;
        return i == s.size();
    }
};