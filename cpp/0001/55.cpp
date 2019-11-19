#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP2(i, a, b) for (int i = (a); i < (int)(b); i++)
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
#define ALL(v) v.begin(), v.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        bool ans = false;
        if(!N) return true;
        VB dp(N, false);
        dp[0] = true;
        REP(i, N) {
            REP(j, min(N-i, nums[i]+1)) {
                dp[i+j] = true && dp[i];
            }
        }
        return dp[N-1];
    }
};

int main() {
    int N;
    cin >> N;
    VI nums(N);
    REP(i, N) cin >> nums[i];
    bool out = Solution().canJump(nums);
    cout << out << endl;
    return 0;
}