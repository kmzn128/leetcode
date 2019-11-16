#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef vector<int> VI;
typedef vector<VI> VVI;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        REP(i, N/2) {
            REP(j, N-1-i) {
                swap(matrix[i][j+i], matrix[N-1-j-i][i]);
                swap(matrix[N-1-j-i][i], matrix[N-1-i][N-1-j-i]);
                swap(matrix[N-1-i][N-1-j-i], matrix[j+i][N-1-i]);
            }
        }
    }
};

int main() {
    int N;
    cin >> N;
    VVI matrix(N, VI(N, 0));
    REP(i, N) {
        REP(j, N) {
            cin >> matrix[i][j];
        }
    }
    Solution().rotate(matrix);
    REP(i, N) {
        REP(j, N) cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}