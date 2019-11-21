#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i, n) for (int i = n-1; i >= 0; i--)
#define REP2(i, a, b) for (int i = (a); i < (int)(b); i++)
#define RREP2(i, a, b) for (int i = (a); i > (int)(b); i--)
#define ALL(v) v.begin(), v.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



class Solution {
public:
    int jump(vector<int>& nums) {
        int N = nums.size();
        if(N == 1) return 0;
        VI dp(N, INT_MAX);
        dp[0] = 0;
        int i = 0;
        while(true) {
            RREP2(j, nums[i], 0) {
                if(i+j < N) {
                    chmin(dp[i+j], dp[i]+1);
                    if(dp[N-1] < INT_MAX) return dp[N-1];
                }
            }
            i++;
        }
        return dp[N-1];
    }
};

int main() {
    int N;
    cin >> N;
    VI nums(N);
    REP(i, N) cin >> nums[i];
    int out = Solution().jump(nums);
    cout << out << endl;
    return 0;
}