#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP2(i, a, b) for (int i = (a); i < (int)(b); i++)
#define RREP2(i, a, b) for (int i = (a); i > (int)(b); i--)
#define ALL(v) v.begin(), v.end()


class Solution {
public:

    vector<int> searchRange(vector<int>& nums, int target) {
        VI ans = {-1, -1};
        auto it_low = lower_bound(ALL(nums), target);
        auto it_up = upper_bound(ALL(nums), target);
        if(it_low != nums.end() && *it_low == target) {
            ans[0] = distance(nums.begin(), it_low);
            ans[1] = distance(nums.begin(), it_up)-1;
        }
        return ans;
    }
};

int main() {
    int N;
    cin >> N;
    VI nums(N);
    REP(i, N) cin >> nums[i];
    int T;
    cin >> T;
    VI out = Solution().searchRange(nums, T);
    cout << out[0] << " " << out[1] << endl;
    return 0;
}