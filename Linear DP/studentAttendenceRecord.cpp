class Solution {
private:
    int mem[100001][2][3] = {};
    int recc(int n, int l, int a){
        if(n<=0) return n==0;
        int cnt = 0;
        //i am present
        if(mem[n][a][l]) return mem[n][a][l];
        cnt += recc(n-1, 0, a);

        //i am late
        cnt += l<2 ? recc(n-1, l+1, a) : 0;

        //i am absent
        cnt += a<1 ? recc(n-1, 0, a+1) : 0;

        return mem[n][a][l] = cnt;
    }
public:
    int checkRecord(int n) {
        return recc(n, 0, 0);
    }
};