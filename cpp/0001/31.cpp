#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP2(i, a, b) for (int i = (a); i < (int)(b); i++)
#define RREP2(i, a, b) for (int i = (a); i > (int)(b); i--)
#define ALL(v) v.begin(), v.end()


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int N = nums.size();
        RREP2(i, N-1, 0) {
            if(nums[i] > nums[i-1]) {
                int tmp = nums[i];
                nums[i] = nums[i-1];
                nums[i-1] = tmp;
                return;
            }
        }
        sort(ALL(nums));
        return;
    }
};

int main() {
    int N;
    cin >> N;
    VI nums(N);
    REP(i, N) cin >> nums[i];
    Solution().nextPermutation(nums);
    REP(i, N) cout << nums[i];
    cout << endl;
    return 0;
}