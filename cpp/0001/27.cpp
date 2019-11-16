#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP2(i, a, b) for (int i = (a); i < (int)(b); i++)
#define ALL(v) v.begin(), v.end()


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(ALL(nums));
        auto it = lower_bound(ALL(nums), val);
        // int i = distance(nums.begin(), it);
        while(true) {
            if(it == nums.end() || *it != val) break;
            nums.erase(it);
        }
        return nums.size();
    }
};

int main() {
    int N;
    cin >> N;
    VI nums(N);
    REP(i, N) cin >> nums[i];
    int val;
    cin >> val;
    int out = Solution().removeElement(nums, val);
    cout << out << endl;
    return 0;
}