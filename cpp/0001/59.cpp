#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP2(i, a, b) for (int i = (a); i < (int)(b); i++)
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<VS> VVS;
#define ALL(v) v.begin(), v.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



class Solution {
public:

    void roundMatrix(int N, int I, int J, int index, int index_max, VVI &ans) {
        if(index > index_max) return;
        int i = 0;
        int j = 0;
        if(index == index_max) {
            ans[i+I][j+J] = index;
            return;
        }
        while(j < N-1) {
            ans[i+I][j+J] = index;
            index++;
            j++;
        }
        while(i < N-1) {
            ans[i+I][j+J] = index;
            index++;
            i++;            
        }
        while(j > 0) {
            ans[i+I][j+J] = index;
            index++;
            j--;
        }
        while(i > 0) {
            ans[i+I][j+J] = index;
            index++;
            i--;            
        }
        roundMatrix(N-2, I+1, J+1, index, index_max, ans);
        return;        
    }
    vector<vector<int>> generateMatrix(int N) {
        if(!N) return {{}};
        VVI ans(N, VI(N, 0));
        roundMatrix(N, 0, 0, 1, N*N, ans);
        return ans; 
    }
};

int main() {
    int N;
    cin >> N;
    VVI out = Solution().generateMatrix(N);
    REP(i, N) {
        REP(j, N) cout << out[i][j] << ' ';
        cout << endl;
    }        
    return 0;
}