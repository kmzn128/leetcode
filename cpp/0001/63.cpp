#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP2(i, a, b) for (int i = (a); i < (int)(b); i++)
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef vector<char> VC;
#define ALL(v) v.begin(), v.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int M, N;
        N = obstacleGrid.size();
        if(!N) return 0;
        M = obstacleGrid[0].size();
        VVL dp(N, VL(M, INT_MAX));
        REP(i, N) {
            REP(j, M) {
                if(!i && !j) {
                    if(!obstacleGrid[i][j])  {
                        dp[i][j] = 1;
                    }
                    else dp[i][j] = 0;
                }
                else if(!i && j) {
                    if(!obstacleGrid[i][j] && dp[i][j-1])  {
                        dp[i][j] = dp[i][j-1];
                    }
                    else dp[i][j] = 0;
                }
                else if(i && !j) {
                    if(!obstacleGrid[i][j] && dp[i-1][j])  {
                        dp[i][j] = dp[i-1][j];
                    }
                    else dp[i][j] = 0;                    
                }
                else {
                    if(!obstacleGrid[i][j]) {
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    }
                    else dp[i][j] = 0;
                }
            }
        }
        return dp[N-1][M-1];
    }
};

int main() {
    int M, N;
    cin >> M >> N;
    VVI grid(N, VI(M, 0));
    REP(i, N) REP(j, M) cin >> grid[i][j];
    int out = Solution().uniquePathsWithObstacles(grid);
    cout << out << endl;
    return 0;
}