class Solution {
private:
    unordered_set<string>dict;
    unordered_map<int,string> mp;
    vector<string>ans;
    void dfs(string &s, int str, string word){
        if(str == s.size()){
            word.pop_back();
            ans.push_back(word);
        }
        string curr = "";
        for(int i=str;i < s.size();i++){
            curr += s[i];
            if(dict.count(curr)){
                dfs(s, i+1, word + curr + " ");
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto &word: wordDict) dict.insert(word);
        dfs(s, 0, "");
        return ans;
    }
};

//aproach-2
class Solution {
public:
    vector<string> ans;
    
    class Trie{
    public:
        Trie* child[26];
        bool isEnd=false;
    };
    
    void insert(string& word, Trie* root){
        Trie *cur = root;
        for(auto &ch : word){
            if(cur->child[ch-'a']==NULL) cur->child[ch-'a'] = new Trie();
            cur = cur->child[ch-'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string& word, Trie* root){
        Trie *cur = root;
        for(auto &ch : word){
            if(cur->child[ch-'a']==NULL) return false;
            cur = cur->child[ch-'a'];
        }
        return cur->isEnd;
    }
    
    void dfs(string &s, int idx, Trie *root, string curStr){
        if(idx == s.size()){
            ans.push_back(curStr.substr(0,0+curStr.size()-1)); 
            return;
        }
        string str="";
        for(int i=idx; i<s.size(); ++i){
            str += s[i];
            if(search(str,root)) dfs(s,i+1,root, curStr+str+" ");
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie *root = new Trie();
        for(auto &word : wordDict){
            insert(word,root);
        }
        dfs(s,0,root,"");
        return ans;
    }
};

//appraoch-3
class Solution {
    unordered_map<string, vector<string>> memo;

    vector<string> dfs(string s, unordered_set<string>& wordDict) {
        if (memo.count(s)) return memo[s];
        vector<string> res;
        if (wordDict.count(s)) res.push_back(s);
        for (int i = s.size()-1; i >= 0; i--) {
            string word = s.substr(i);
            if (!wordDict.count(word)) continue;
            string rem = s.substr(0, i);
            vector<string> prev = dfs(rem, wordDict);
            for (string str : prev) res.push_back(str + " " + word);
        }
        memo[s] = res;
        return res;
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        return dfs(s, set);
    }
};