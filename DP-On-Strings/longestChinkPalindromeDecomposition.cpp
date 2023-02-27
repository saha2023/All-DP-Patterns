class Solution {
public:
    int longestDecomposition(string text) {
        string a,b;
        int i=0,j=text.size()-1,ans=0;

        while(i<j) {
            a+=text[i];
            b=text[j]+b;

            if(a==b) {
                ans++;
                a="";
                b="";
            }
            i++;
            j--;
        }
        ans*=2;
        if(a=="" and i>j) // even partition
            return ans;
        return ans+1;
    }
};