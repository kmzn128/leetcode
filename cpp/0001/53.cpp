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
    int maxSubArray(vector<int>& nums) {
        int ans = 0;
        int N = nums.size();
        VI dp(N, 0);
        dp[0] = nums[0];
        REP2(i, 1, N) {
            dp[i] = max(dp[i-1], 0) + nums[i];
            chmax(ans, dp[i]);
        }
        return ans;
    }
};

int main() {
    int N;
    cin >> N;
    VI nums(N);
    REP(i, N) cin >> nums[i];
    int out = Solution().maxSubArray(nums);
    cout << out << endl;
    return 0;
}