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

    void roundMatrix(int I, int J, int N, int M, VVI & matrix, VI &ans) {
        if(I > N && J > M) return;
        int i = I;
        int j = J;
        if(I == J && I == N && I == M) {
            ans.push_back(matrix[i][j]);
            return;
        }
        if(I == N) {
            while(j <= M) {
                ans.push_back(matrix[i][j]);
                j++;
            }
            return;           
        }
        if(J == M) {
            while(i <= N) {
                ans.push_back(matrix[i][j]);
                i++;            
            }
            return;          
        }
        while(j < M) {
            ans.push_back(matrix[i][j]);
            j++;
        }
        while(i < N) {
            ans.push_back(matrix[i][j]);
            i++;            
        }
        while(j > J) {
            ans.push_back(matrix[i][j]);
            j--;
        }
        while(i > I) {
            ans.push_back(matrix[i][j]);
            i--;            
        }
        roundMatrix(I+1, J+1, N-1, M-1, matrix, ans);
        return;        
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int N = matrix.size();
        VI ans = VI(0);
        if(!N) return ans;
        int M = matrix[0].size();
        roundMatrix(0, 0, N-1, M-1, matrix, ans);
        return ans; 
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    VVI matrix(N, VI(M));
    REP(i, N) REP(j, M) cin >> matrix[i][j];
    VI out = Solution().spiralOrder(matrix);
    int len = out.size();
    REP(i, len) cout << out[i] << ' ';
    cout << endl;
    return 0;
}