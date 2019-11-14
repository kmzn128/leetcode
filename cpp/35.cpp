#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP2(i, a, b) for (int i = (a); i < (int)(b); i++)
#define RREP2(i, a, b) for (int i = (a); i > (int)(b); i--)
#define ALL(v) v.begin(), v.end()


class Solution {
public:

    vector<int> searchInsert(vector<int>& nums, int target) {

     }
};

int main() {
    int N;
    cin >> N;
    VI nums(N);
    REP(i, N) cin >> nums[i];
    int T;
    cin >> T;
    VI out = Solution().searchInsert(nums, T);
    cout << out[0] << " " << out[1] << endl;
    return 0;
}